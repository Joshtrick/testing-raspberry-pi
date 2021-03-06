#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include "hj_tcp_ip.h"
#include "hj_utils.h"

using namespace std;

int main()
{
  int size = 199692;
  int large_size = 514*514*3;
  char memblock[large_size];
  memset(memblock, 0, sizeof(memblock));
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

  //for(int i = 0; i < size; i++)
  //{
  //  printf("%x", memblock[i]);
  //}
  //printf("\n");

  //end: open and read a dummy bin to memory

  int server_fd, new_socket;
  struct sockaddr_in address;

  server_socket_create(server_fd, 8080, address);
  cout << "Created" << endl;
  cout << "Linstening" << endl;
  server_socket_new(new_socket, server_fd, address);
  cout << "Connected" << endl;
  int cycle = 1e4;

  cout << "Start sending " << large_size << " Bytes data for " << cycle << " times." << endl;
  a_timer.get_start_time();
  for(int i = 0; i < cycle; i++)
  {
    send(new_socket, memblock, large_size, 0);
  }
  a_timer.get_end_time("Total send");

  cout << "Sent" << endl;

  return 0;
}
