#include <iostream>       // std::cout
#include <thread>
#include <pthread.h>
#include <unistd.h>
#include <mutex>
#include <fstream>

using namespace std;

class Logfile{

  mutex m_mtx;
  ofstream f;

  public:
    Logfile(){
    f.open("log.txt");
    }

    void shared_print(string id, int val){
    lock_guard<mutex> locker(m_mtx);
    f<<"from "<< id <<": "<<val<<endl;
    }
};

void func(Logfile& log){
  for(int i=0;i<100;i++){
    log.shared_print(string("from t1 :"), i);
    }
}


int main(){

  Logfile log;
  thread t1 (func, ref(log));

  for(int i=100;i<200;i++){
    log.shared_print(string("from Main :"), i);
    }

    t1.join();
  return 0;
}
