#ifndef __TCP_CONNECTION_H__
#define __TCP_CONNECTION_H__

#include <sys/errno.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <cstdio>

#include "log.h"

class TcpConnection {
   private:
    int _sock_fd;

   public:
    TcpConnection() {
        _sock_fd = socket(PF_INET, SOCK_STREAM, 0);
        if (_sock_fd == -1) {
            perror("SOCKET CREATE");
        }
        Log::info("Socket created successful.");
    }
};

#endif