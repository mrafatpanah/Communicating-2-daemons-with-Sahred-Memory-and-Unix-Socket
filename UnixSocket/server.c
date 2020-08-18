#include "baselib.h"
#include "daemon.h"
#include "server_socket.h"

int main(int argc, char const *argv[]) 
{ 
    createDaemon();
    startServer();
    return 0; 
} 
