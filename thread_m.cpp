// thread example
#include <iostream>       // std::cout
#include <thread>
#include <pthread.h>
#include <unistd.h>
      // std::thread

using namespace std;

void func()
{
  std::cout << "This is func" << '\n';
}


int main()
{
  std::thread t1 (func);     // created a thread

  try{
    for(int i=0;i<100;i++)
      std::cout << "from main i = " << i << '\n';
  }catch(...){
    t1.join(); // join thread
    std::cout << "/* message */" << '\n';
    throw;
  }

  std::cout << "At the end of Main" << '\n';

  return 0;

}
