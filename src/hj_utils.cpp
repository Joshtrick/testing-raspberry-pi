#include "hj_utils.hpp"

void Proctimer::get_start_time()
{
  clock_gettime(CLOCK_REALTIME, &t_start);
}

void Proctimer::get_end_time(string proc_name = "Execution")
{
  clock_gettime(CLOCK_REALTIME, &t_end);
  time_s = t_end.tv_sec-t_start.tv_sec;
  time_ms = (t_end.tv_nsec-t_start.tv_nsec)/1000000;
  time_us = ((t_end.tv_nsec-t_start.tv_nsec)-time_ms*1000000)/1000;
  time_ns = (t_end.tv_nsec-t_start.tv_nsec)-time_us*1000-time_ms*1000000;
  cout << proc_name << " time: " << time_s << " s, " << time_ms << " ms, "
    << time_us <<" us, " << time_ns << " ns." << endl;
}
