#include <iostream>
#include <thread>
#include <sstream>

using namespace std;

void wykonaj_watek_w_tle(string thread_id, int liczba_petli) {
    
    cout << "Wątek w tle działający, aż do zakończenia wątku głównego o id: " << thread_id << endl;
    
    int liczba_sekund = liczba_petli;

    for( int i = 0; i < liczba_petli; i++ ){  
        
        int j = i;
        j++;

        // instrukcja wątku w tle wykonuje się co 1 sekundę
        cout << "Instrukcja nr: " << j << ", Bip biiip biiiiip ..." << endl;
        cout << "Szacunkowy pozostały czas trwania wątku w tle: " << liczba_sekund << " sekund." << endl;
        this_thread::sleep_for(chrono::seconds(1));

        liczba_sekund--;

    }
};

void wykonaj_watek_glowny() {

    int x = 3;
    thread::id this_id = this_thread::get_id();
    cout << "Watek główny o id: " << this_id << endl;
    cout << "Watek główny trwa "<< x << " sekund." << endl;
    cout << endl;

    ostringstream ss;
    ss << this_id;
    string thread_id = ss.str();
    int liczba_petli = 5;

    thread watek_w_tle{wykonaj_watek_w_tle, thread_id, liczba_petli};
    watek_w_tle.detach();

    // wątek główny trwa x sekund
    this_thread::sleep_for(chrono::seconds(x));
};

int main()
{   
    thread watek_glowny(wykonaj_watek_glowny);
    watek_glowny.join();

    return 0;
}
