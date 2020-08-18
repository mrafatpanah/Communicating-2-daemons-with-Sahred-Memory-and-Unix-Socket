#ifndef __SHMEM_H__

#include <sys/shm.h>

#define     PATH_NAME             "shmem_daemon"
#define     PROJECT_NUMBER_IDENTIFIER   60
#define     SHM_BUFFER_SIZE             2048

int configSharedMemorySetup() {
    // ftok to generate unique key 
    key_t key = ftok(PATH_NAME, PROJECT_NUMBER_IDENTIFIER);
    // shmget returns an identifier in shmid 
    int shmId = shmget(key, SHM_BUFFER_SIZE, 0666|IPC_CREAT);
    return shmId;
}

void sendMessage(char *str) {    
    // detach from shared memory  
    shmdt(str);
}

void destorySharedMemory(int shmId) {
    // destroy the shared memory 
    shmctl(shmId, IPC_RMID, NULL); 
}

#endif // __SHMEM_H__
