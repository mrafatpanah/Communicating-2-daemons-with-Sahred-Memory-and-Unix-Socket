#ifndef __BASELIB_H__

int initializeSocket() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = SOCKET_OPT;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) exit(EXIT_FAILURE);

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) exit(EXIT_FAILURE);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) exit(EXIT_FAILURE);

    if (listen(server_fd, 3) < 0) exit(EXIT_FAILURE);

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) exit(EXIT_FAILURE);

    return new_socket;
}

void sendMessage(int socketId, char *message) {
    send(socketId, message, strlen(message), 0); 
}

void startServer() {

    int new_socket = initializeSocket();
    char buffer[BUFFER_SIZE] = {0};
    int valread;

    FILE *fp = NULL;
    //Open a log file in write mode.
    fp = fopen("./ServerLog.txt", "a");

    fprintf(fp, "socket initialize was successful !!!\n");

    while (1) {
        valread = read(new_socket, buffer, BUFFER_SIZE);
        fprintf(fp, "message received from client: %s\n", buffer);
        fflush(fp);
        sendMessage(new_socket, "I got message from you !!!");
    }
    fclose(fp);
}

#endif
