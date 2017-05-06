// thread example
#include <iostream>       // std::cout
#include <thread>
#include <pthread.h>
#include <unistd.h>
      // std::thread

using namespace std;

void foo()
{
  std::cout << "This is foo" << '\n';
}

void bar()
{
  std::cout << "This is bar" << '\n';
}

int main()
{

  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes

    //first.detach();
    //second.detach();

    if(first.joinable() && second.joinable()){
      first.join();
      second.join();
    }
    else{
      std::cout << "Threads are not joinable" << '\n';
    }

  std::cout << "foo and bar completed.\n";

  return 0;

}
