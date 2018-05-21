#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include "hj_utils.h"

using namespace std;

int main()
{
  int height = 256;
  int width = 256;
  int size = height*width*3;
  char memblock[size];
  for(int i = 0; i < size; i++)
  {
    memset(memblock+i, i%256, 1);
  }
  //set up a timer
  Proctimer a_timer;

  //start: open and read a dummy bin to memory

  a_timer.get_start_time();
  ofstream o_file;
  o_file.open("../data/dummy_short_data.bin", ios::out|ios::trunc);
  o_file.close();

  o_file.open("../data/dummy_short_data.bin", ios::out|ios::app|ios::binary);
  o_file.write(memblock, size);
  o_file.close();
  a_timer.get_end_time("Write");

  return 0;
}
