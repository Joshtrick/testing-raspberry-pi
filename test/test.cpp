#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "hj_tcp_ip.hpp"
#include "hj_utils.hpp"

using namespace std;

int main()
{
  Proctimer a_timer;
  a_timer.get_start_time();
  a_func();
  cout << "Hello World!" << endl;
  a_timer.get_end_time("Hello");
  return 0;
}
