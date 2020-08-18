
// Client side C/C++ program to demonstrate Socket programming
#include "baselib.h"
#include "daemon.h"

int main(int argc, char const *argv[])
{

    createDaemon();

    FILE *fp = NULL;
    //Open a log file in write mode.
    fp = fopen("./ClientLog.txt", "a");

    int sock = 0, valread;
    struct sockaddr_in serv_addr;


    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(fp, "server socket initialize failed\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        fprintf(fp, "Invalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(fp, "Connection Failed \n");
        return -1;
    }

    int counter = 0;
    char *message = "Hello this is client from daemon";
    for (; counter < 10; counter ++) {
        send(sock, message, strlen(message), 0);
        char buffer[BUFFER_SIZE] = {0};
        valread = read(sock, buffer, BUFFER_SIZE);
        fprintf(fp, "message came from server as: %s\n", buffer);
        fflush(fp);
        sleep(1);
    }
    fclose(fp);

    return 0;
}
