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
  int size = 399384;
  int half_size = size/2;
  char * memblock = new char[size];

  //set up a timer
  Proctimer a_timer;

  //start: open and read a dummy bin to memory

  a_timer.get_start_time();
  ifstream i_file("../data/dummy_data.bin", ios::in|ios::binary|ios::ate);
  if (i_file.is_open())
  {
    //cout << size << endl;
    //size = i_file.tellg();
    i_file.seekg(0, ios::beg);
    i_file.read(memblock, size);
    i_file.close();
    //cout << "finished" << endl;
  }
  //end: open and read a dummy bin to memory
  a_timer.get_end_time("Read");

  a_timer.get_start_time();
  ofstream o_file;
  o_file.open("../data/dummy_short_data.bin", ios::out | ios::app | ios::binary);
  o_file.write(memblock, half_size);
  o_file.close();
  delete[] memblock;
  a_timer.get_end_time("Write");

  return 0;
}
