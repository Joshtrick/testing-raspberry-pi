#ifndef HJ_UTILS_HPP
#define HJ_UTILS_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>
using namespace std;

class Proctimer
{
public:
  void get_start_time();
  void get_end_time(string proc_name);
private:
  long time_ms, time_us, time_ns;
  time_t time_s;
  timespec t_start, t_end;
};


#endif //HJ_UTILS_HPP
