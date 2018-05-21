#ifndef HJ_TCP_IP_H
#define HJ_TCP_IP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void server_socket_create(int &server_fd, int port, struct sockaddr_in &address);
void server_socket_new(int &new_socket, int &server_fd, struct sockaddr_in &address);
void client_socket_create(int &sock, char* server_ip, int port);

#endif // HJ_TCP_IP_H
