#include "hj_tcp_ip.hpp"

//Server Part-create a server socket
void server_socket_create(int &server_fd, int port, struct sockaddr_in &address)
{
  int opt = 1;
  int addrlen = sizeof(address);

  // Creating socket file descriptor
  if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
    perror("[CORERAIN] Server-socket creation");
    exit(EXIT_FAILURE);
  }

  if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
  {
    perror("[CORERAIN] Server-setsock opt");
    exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  if(bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
  {
    perror("[CORERAIN] Server-binding");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0)
  {
    perror("[CORERAIN] Server-listening");
    exit(EXIT_FAILURE);
  }
}
//Server Part-setup a new socket when a client is connecting
void server_socket_new(int &new_socket, int &server_fd, struct sockaddr_in &address)
{
  int addrlen = sizeof(address);
  if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
  {
    perror("[CORERAIN] Server-acception");
    exit(EXIT_FAILURE);
  }
}
//Client Part-create a client socket
void client_socket_create(int &sock, char* server_ip, int port)
{
  struct sockaddr_in serv_addr;
  if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    perror("[CORERAIN] Client-socket creation");
    exit(EXIT_FAILURE);
  }

  memset(&serv_addr, '0', sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if(inet_pton(AF_INET, server_ip, &serv_addr.sin_addr)<=0)
  {
    perror("[CORERAIN] Client-socket setup");
    exit(EXIT_FAILURE);
  }

  if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    perror("[CORERAIN] Client-socket connection");
    exit(EXIT_FAILURE);
  }
}
////Data Transfer
//void send_a_block(int &sock, const void *buffer)
//{
//  if(send(sock, buffer, sizeof(buffer), 0) < 0)
//  {
//    perror("[CORERAIN] TCP/IP Data Transfer-send");
//    exit(EXIT_FAILURE);
//  }
//}
//
//void recv_a_block(int &sock, (void *) &buffer, size_t length)
//{
//  if(recv(sock, buffer, length, MSG_WAITALL) < 0)
//  {
//    perror("[CORERAIN] TCP/IP Data Transfer-receive");
//    exit(EXIT_FAILURE);
//  }
//}










