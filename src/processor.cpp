#include "processor.h"
#include <linux_parser.h>

float Processor::Utilization() {
  LinuxParser::CpuUtilizationData new_data = LinuxParser::CpuUtilization();

  int sum = new_data.user + new_data.nice + new_data.system + new_data.idle +
            new_data.iowait + new_data.irq + new_data.softirq + new_data.steal +
            new_data.guest + new_data.guest_nice;

  int last_sum = cpu_data.user + cpu_data.nice + cpu_data.system +
                 cpu_data.idle + cpu_data.iowait + cpu_data.irq +
                 cpu_data.softirq + cpu_data.steal + cpu_data.guest +
                 cpu_data.guest_nice;

  int delta = sum - last_sum;
  int idle_delta = new_data.idle - cpu_data.idle;
  float cpu_usage = ((float)(delta - idle_delta)) / delta;

  cpu_data = new_data;

  return cpu_usage;
}