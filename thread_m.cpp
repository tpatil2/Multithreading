// thread example
#include <iostream>       // std::cout
#include <thread>
#include <pthread.h>
#include <unistd.h>
      // std::thread

using namespace std;

void func()
{
  std::cout << "This is func " << '\n';
}

class Factor{
public:
  void operator()(){
    for(int i=100;i>1;i--)
      std::cout << "In functor i "<< i << '\n';
  }

};


int main()
{
  Factor f1;
  std::thread t1 (f1);     // created a thread

    for(int i=0;i<100;i++)
      std::cout << "from main i = " << i << '\n';

      t1.join(); // join thread


  std::cout << "At the end of Main" << '\n';


  return 0;

}
