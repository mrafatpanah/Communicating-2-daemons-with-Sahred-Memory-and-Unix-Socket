#include "baselib.h"
#include "shmem.h"

void configDaemon();

int main() {
    configDaemon();
    return 0;
}

void configDaemon() {
    pid_t process_id = 0;

    // create child process
    process_id = fork();

    // check that indication of fork() is failure
    if (process_id < 0) {
        printf("fork failed!\n");
        // Return failure in exit status
        exit(1);
    }

    // PARENT PROCESS. Need to kill it.
    if (process_id > 0) {
        printf("process_id of child process %d \n", process_id);
        // return success in exit status
        exit(0);
    }

    //set new session
    // Return failure
    if(setsid() < 0) exit(1);

    // Close stdin. stdout and stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    FILE *fp = NULL;
    //Open a log file in write mode.
    fp = fopen("./publisher.txt", "a");

    int shmId = configSharedMemorySetup();

    int c = 0;
    for(;c <= 5; c++) {
        //Dont block context switches, let the process sleep for some time
        sleep(2);
        char *str = (char*) shmat(shmId, (void*)0, 0);

        strcpy(str, "going to start daemon\n");
        fprintf(fp, "this is test from publisher!: \n");
        fflush(fp);
        sendMessage(str);
    }
    shmctl(shmId, IPC_RMID, NULL);
    fclose(fp);
    char *data;
    /* attach to the segment to get a pointer to it: */
    data = shmat(shmId, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }
    memset(data, 0, 2048);
}
