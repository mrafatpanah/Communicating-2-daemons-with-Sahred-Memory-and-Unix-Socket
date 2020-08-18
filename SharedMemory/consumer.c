#include "baselib.h"
#include "shmem.h"

int main()
{
  int shmid = configSharedMemorySetup();
    char *data;
    /* attach to the segment to get a pointer to it: */
    data = shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }
    memset(data, 0, SHM_BUFFER_SIZE);

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
    fp = fopen("./consumer.txt", "a");

    int counter = 0;

    while (1) {
        // shmat to attach to shared memory
        char *str = (char*) shmat(shmid,(void*)0,0);
        if (strlen(str) > 0) {
            fprintf(fp, "data read from memory: %s\n", str);
            fflush(fp);
            shmdt(str);
        }
        else if(counter > 15)
            break;
        sleep(2);
        counter ++;
    }

    return 0;
}
