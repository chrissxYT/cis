#include <stdio.h>
#include <unistd.h>
#include "util.h"
#include "sock.h"
#include "commands.h"

#include "config.h"

void serve(int fd, struct sockaddr_storage *sa);

int main()
{
        int sock = sock_get_ips(HOST, PORT);
        struct sockaddr_storage sa;
        socklen_t sa_len;
        int fd;

        while(1)
        {
                sa_len = sizeof(sa);
                fd = accept(sock, (struct sockaddr *) &sa, &sa_len);
                if(fork()) close(fd);
                else serve(fd, &sa);
        }
}

#define process_request(in, out) run_command(*in, in + 1, out)

void serve(int fd, struct sockaddr_storage *sa)
{
        sock_set_timeout(fd, 30);
        char in[CIS_MAX];
        char out[CIS_MAX];
        
        in[read(fd, in, CIS_MAX)] = '\0';
        process_request(in, out);
        write(fd, out, CIS_MAX);

	shutdown(fd, SHUT_RD);
	shutdown(fd, SHUT_WR);
	close(fd);
}
