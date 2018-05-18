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

  //set up a timer
  Proctimer a_timer;

  //start: open and read a dummy bin to memory

  ifstream i_file("../data/dummy_data_tcp.bin", ios::in|ios::binary|ios::ate);
  if (i_file.is_open())
  {
    //cout << size << endl;
    i_file.seekg(0, ios::beg);
    i_file.read(memblock, size);
    i_file.close();
    //cout << "finished" << endl;
  }
  //end: open and read a dummy bin to memory

  int server_fd, new_socket;
  struct sockaddr_in address;
  
  server_socket_create(server_fd, 8080, address);
  cout << "Created" << endl;
  server_socket_listen(server_fd);
  cout << "Linstening" << endl;
  server_socket_new(new_socket, server_fd, address);
  cout << "Connected" << endl;
  delete[] memblock;

  return 0;
}
