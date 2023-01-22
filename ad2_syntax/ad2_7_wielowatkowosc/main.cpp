#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
 
mutex my_mutex;

void kodDoWykonania() {

  thread::id this_id = this_thread::get_id();
  
  my_mutex.lock();

  for( int i = 0; i < 5; i++ ){  
    int j = i;
    j++;
    cout << "Watek o id: " << this_id << " wykonuje instrukcje nr: " << j << endl;
    this_thread::sleep_for(chrono::milliseconds(10));
  }

  cout << endl;

  my_mutex.unlock();

  this_thread::sleep_for(chrono::milliseconds(100));
}

int main()
{
    thread watek1(kodDoWykonania);
    thread watek2(kodDoWykonania);
    thread watek3(kodDoWykonania);

    watek1.join();
    watek2.join();
    watek3.join();

    return 0;
}