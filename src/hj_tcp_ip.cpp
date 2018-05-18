#include "hj_tcp_ip.hpp"


void server_socket_create(int &server_fd, int port, struct sockaddr_in &address)
{
  int opt = 1;
  int addrlen = sizeof(address);

  // Creating socket file descriptor
  if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
    perror("[CORERAIN] Server-socket failed");
    exit(EXIT_FAILURE);
  }

  if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
  {
    perror("[CORERAIN] Server-setsockopt");
    exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  if(bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
  {
    perror("[CORERAIN] Server-bind failed");
    exit(EXIT_FAILURE);
  }
}

void server_socket_listen(int server_fd)
{
  if (listen(server_fd, 3) < 0)
  {
    perror("[CORERAIN] Server-listen");
    exit(EXIT_FAILURE);
  }
}

void server_socket_new(int &new_socket, int &server_fd, struct sockaddr_in &address)
{
  int addrlen = sizeof(address);
  if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
  {
    perror("[CORERAIN] Server-accept");
    exit(EXIT_FAILURE);
  }
}
