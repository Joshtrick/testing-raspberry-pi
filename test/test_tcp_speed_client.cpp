#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "hj_tcp_ip.hpp"
#include "hj_utils.hpp"

using namespace std;

int main()
{
  int size = 199692;
  char * memblock = new char[size];

  int client_socket;
  char * server_ip = (char*)"192.168.123.3";

  client_socket_create(client_socket, server_ip, 8080);
  cout << "Connected" << endl;

  recv(client_socket, memblock, sizeof(memblock), MSG_WAITALL);
  cout << "Sent" << endl;
  delete[] memblock;

  return 0;
}
