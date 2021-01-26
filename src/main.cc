#include "test.h"
#include <thread>
#include <string>
#include <iostream>

std::thread threads[N_THREAD];
std::string logger[N_THREAD];

int main(int argc, char* argv[]){
  for (int i = 0 ; i < N_THREAD; i++)
  {
    auto a = &logger[i];
    threads[i] = std::thread([a,i] { *a = calls<double>(i + .5,i + 1.5); });
  }
  for (int i = 0 ; i < N_THREAD; i++)
  {
    std::cout << "Thread " << i << ":" << std::endl;
    threads[i].join();
    std::cout << logger[i] << std::endl;
    std::cout << std::endl;
  }
}
