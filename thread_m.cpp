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
  void operator()(string msg){
    std::cout << "Inside join : "<< msg << '\n';
    std::cout << "Factoe ID: "<<std::this_thread::get_id() << '\n';
    msg="changed";
  }

};


int main()
{
  string s = "This is multi-threading";
      std::cout << "Main ID: "<<std::this_thread::get_id() << '\n';
  std::thread t1 ((Factor()),std::move(s));     // created a thread
      std::cout << "Before Join : "<< s << '\n';
      std::cout << "Main ID t1: "<<t1.get_id() << '\n';
      t1.join(); // join thread

      std::cout << "After Join : "<< s << '\n';
      std::cout << "At the end of Main" << '\n';


  return 0;

}
