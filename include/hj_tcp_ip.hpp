#ifndef HJ_TCP_IP_HPP
#define HJ_TCP_IP_HPP
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

void server_socket_create(int &server_fd, int port, struct sockaddr_in &address);
void server_socket_new(int &new_socket, int &server_fd, struct sockaddr_in &address);
void client_socket_create(int &sock, string server_ip = "127.0.0.1", int port);

#endif // HJ_TCP_IP_HPP
