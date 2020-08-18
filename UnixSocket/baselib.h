#ifndef __BASELIB_H__

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

// socket libs
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
//

//deamon
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
//

#define     PORT            8080 
#define     BUFFER_SIZE     2048
#define     SOCKET_OPT      1


#endif // __BASELIB_H__
