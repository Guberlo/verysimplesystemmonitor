#include <iostream>
#include <fstream>
#define STAT "/proc/stat"
using namespace std;

class Cpu {
  public:
    Cpu(int);
    int get_used();
  private:
    int core_index;
    int core_usage;
    int work_jiffies_0;
    int work_jiffies_1;
    int total_jiffies_0;
    int total_jiffies_1;
};

  Cpu::Cpu(int core_index)
  {
    this->core_index=core_index;
  }

  int Cpu::get_used()
  {
    ifstream input;
    input.open(STAT);

    if(input.is_open())
    {
      for(int l=0; l<11;l++){
        string n;
        input >> n;
      }


      for(int i=0;i<n_cpus;i++)
      {
          string cpu_core;
          input >> cpu_core;

          for(int j=0;j<3;j++)
          {
            input >> this->work_jiffies_1;
            work_jiffies_1+=work_jiffies_1;
            work_jiffies_0=work_jiffies_1;
          }

          for(int k=0;k<10;k++)
          {
            input >> this->total_jiffies_1;
            total_jiffies_1+=total_jiffies_1;
            work_jiffies_0=work_jiffies_1;
          }

      }

    }

      return (int)(
    ((float)(work_jiffies_1 - work_jiffies_0) /
    (float)(total_jiffies_1 - total_jiffies_0))
    * 100);
}
