# 2.7. Wielowątkowość

Język Emojicode obsługuje współbieżność, oznacza to, że możliwe jest wykonywanie wielu instrukcji kodu jednocześnie. 
Do zrównoleglania zadań w Emojicode wykorzystuje się wątki, które mogą niezależnie od siebie wykonywać określone instrukcje kodu w ramach jednego procesu, którym jest blok wykonywalny programu 🏁 🍇🍉.

Wątki w języku Emojicode są reprezentowane przez klasę 🧵.
Aby utworzyć nowy wątek należy go zadeklarować w taki sam sposób jak nowe zmienne, czy obiekty za pomocą inicjalizatora o adnotacji 🆕.

Blok wykonywalnego programu 🏁 🍇🍉 traktowany jest jako wątek główny, dlatego mimo utworzenia nowego wątku za pomocą adnotacji 🆕🧵, nie zostanie on wywołany, dzieje się tak dlatego, że nowo utworzony wątek czeka na zakończenie wątku głównego, który nie jest zatrzymany i ostatecznie dociera do końca programu.

Aby nowo utworzony wątek został wykonany należy zaczekać na zakończenie wątku głównego za pomocą metody 🛂, która wstrzymuje wykonywanie bieżącego wątku w tym przypadku (wątku głównego) aż do zakończenia wykonywania nowo utworzonego wątku, metoda w chwili zakończenia wątku 🛂 natychmiast powróci. 

```
Przykład utworzenia 3 wątków - wszystkie wątki próbują wykonać się jednocześnie

🏁 🍇
    🆕🍨🐚🧵🍆❗️ ➡️ 🖍🆕watki

    🔂 i 🆕⏩ 0 3❗️ 🍇
        🐻 watki 🆕🧵 🍇 🎍🥡
            😀 🔤Wątek 🧲i🧲: Instrukcja 1🔤❗️
            😀 🔤Wątek 🧲i🧲: Instrukcja 2🔤❗️
            😀 🔤Wątek 🧲i🧲: Instrukcja 3🔤❗️
        🍉❗️❗️
    🍉

    🔂 watek watki 🍇
        🛂 watek❗️
    🍉
🍉

Wynik powyższego przykładu jest zmienny, ale widoczne jest to, że wątki wykonują się jednocześnie i nie ma tu żadnej kontroli nad wykonywanym programem. Wątki wykonują instrukcje w różnej kolejności.

Wątek 0: Instrukcja 1
Wątek 2: Instrukcja 1
Wątek 2: Instrukcja 2
Wątek 2: Instrukcja 3
Wątek 0: Instrukcja 2
Wątek 0: Instrukcja 3
Wątek 1: Instrukcja 1
Wątek 1: Instrukcja 2
Wątek 1: Instrukcja 3
```

W powyższym przykładzie wszystkie wątki są wykonywane na raz, aby temu zapobiec Emojicode wprowadza mechanizm synchronizacji wątków, instancję 🔐 nazywaną muteksem. Muteks służy aby zapewnić kontrolę nad sekcją krytyczną wykonywanego programu, mówiąc ściślej jest to fragment kodu programu, który w danej chwili może być wykonywany tylko przez jeden wątek. Sekcja krytyczna zapewnia właściwość wzajemnego wykluczenia.

Standardową realizacją wzajemnego wykluczenia jest wykorzystanie muteksu (obiektu blokady), który zawiera operację:
* blokowania muteksu - 🔒 mutex❗️,
* odblokowania muteksu - 🔓 mutex❗️.

Działa to w ten sposób, że wątek próbując wejść do sekcji krytycznej wykonywanego programu wywołuje na początku operację blokowania muteksu - 🔒 mutex❗️, oznacza to, że wątek spróbuje zablokować muteks, jeśli nie został wcześniej zablokowany. W tym momencie wątek przechwytuje muteks, następnie wchodzi do sekcji krytycznej i wykonuje instrukcje, które zostały zdefiniowane w jej środku. Inne wątki natomiast będą oczekiwać, aż wątek zakończy wykonywanie instrukcji w środku sekcji krytycznej i wyjdzie z niej, po czym wywoła operację odblokowania muteksu - 🔓 mutex❗️, dzięki czemu kolejny wątek będzie mógł przechwycić muteks, następnie go zablokować, wykonać instrukcje zadeklarowane w sekcji krytycznej, po czym wychodząc odblokować muteks i tak cyklicznie.
Taka operacja, która jest chroniona przed zakłóceniami ze strony innych wątków, nazywana jest atomową.

```
Przykład kontroli sekcji krytycznej wykonywanego programu z zastosowaniem muteksu

🏁 🍇
    🆕🍨🐚🧵🍆❗️ ➡️ 🖍🆕watki

    🆕🔐❗️ ➡️ mutex

    🔂 i 🆕⏩ 0 3❗️ 🍇
        🐻 watki 🆕🧵 🍇 🎍🥡
            🔒 mutex❗️
            😀 🔤Instrukcja 1🔤❗️
            😀 🔤Instrukcja 2🔤❗️
            😀 🔤Instrukcja 3🔤❗️
            😀 🔤Instrukcja 4🔤❗️
            😀 🔤Instrukcja 5🔤❗️
            🔓 mutex❗️
        🍉❗️❗️
    🍉

    🔂 watek watki 🍇
        🛂 watek❗️
    🍉
🍉

Wynik powyższego przykładu jest jak najbardziej oczekiwany, widoczne jest to, że wątki wykonują instrukcje w odpowiednej kolejności.

Wątek 0: Instrukcja 1
Wątek 0: Instrukcja 2
Wątek 0: Instrukcja 3
Wątek 1: Instrukcja 1
Wątek 1: Instrukcja 2
Wątek 1: Instrukcja 3
Wątek 2: Instrukcja 1
Wątek 2: Instrukcja 2
Wątek 2: Instrukcja 3
```

# Porównanie do C++

Aby móc używać wątków w języku C++ należy zainstalować kompilator g++ w wersji 11.
W języku C++ wątek reprezentuje klasa std::thread. Każdy obiekt utworzony za pomocą klasy std::thread reprezentuje pojedynczy wątek (utworzony przez system operacyjny), bądź tak zwany pusty wątek (Not-A-Thread), który jest instancją klasy std::thread utworzonej za pomocą konstruktora domyślnego, bądź obiektem wątku po wykonaniu na nim operacji std::move(). Warto zaznaczyć, że obiektów wątków nie można kopiować. Mimo braku możliwości kopiowania, wątki mogą być przenoszone pomiędzy obiektami za pomocą funkcji std::move().

Wątek jest uruchamiany przez przekazanie w konstruktorze obiektu std::thread. Tak jak w przypadku języka Emojicode, główna funkcja programu main() traktowana jest jako wątek główny i aby nowo utworzony wątek został wykonany należy wstrzymać wykonywanie funkcji main() aż do zakończenia wykonywania nowo utworzonego wątku za pomocą metody join(). Metoda join() wstrzymuje wykonanie bieżącego wątku, aż do czasu zakończenia pracy przez wskazany wywołaniem wątek.

W przypadku kompilacji pliku źródłowego, w którym były tworzone i wykorzystywane wątki w języku Emojicode, nie było zasadniczej różnicy w składni komendy i nie było potrzeby zastosowaywać dodatkowych opcji, aby skompilować go do pliku wykonywalnego programu stosuje się komendę z tą samą składnią: emojicodec nazwa_pliku.emojic.
Jednakże aby skompilować plik źródłowy, wykorzystujący wielowątkowość w języku C++ do pliku wykonywalnego programu należy zastosować dodatkową opcję podczas kompilacji, w tym celu stosuje się komendę z następującą składnią: g++ -o nazwa_programu nazwa_pliku.cpp -pthread.

```
Przykład deklaracji wątku w języku C++

#include <iostream>
#include <thread>

using namespace std;

int main()
{   
    // deklaracja wątku za pomocą funkcji Lambda
    thread t([] { cout << "Mój pierwszy wątek." << endl; });
    t.join();
}

Wynik powyższego przykładu:

Mój pierwszy wątek.
```

Oprócz możliwości tworzenia wątków wykonywanych w określonym momencie (w określonym porzadku, hierarchii) w programie istnieje możliwość utworzenia wątku, który będzie mógł być wykonywany w tle aż do zakończenia działania programu. Wątek utworzony w ten sposób określany jest najczęściej jako wątek tła lub demon.
Wątek taki deklaruje się w ten sam sposób co normalny wątek, jednakże zamiast metody join(), używa się metody detach(), która wskazuje, że wątek ma być wykonywany w tle.

```
Przykład utworzenia wątku w tle, w wątku głównym

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

Wynik powyższego przykładu znajduje się poniżej. Widoczne jest to, że wątek główny ma ustawione działanie na 3 sekundy, podczas gdy instrukcje wykonywane w wątku w tle powinny być wykonywane przez 5 sekund. Jako, że wątek w tle jest zależny od wątku głównego, to w chwili zakończenia wątku głównego, zostaje również przerwana praca wątku w tle i zostaje on zakończony. Wątek w tle będzie trwał dokładnie tyle czasu co wątek główny, tym samym zostaną wykonane jedynie 3 instrukcje z 5 zadeklarowanych w wątku w tle.

Watek główny o id: 139754277426944
Watek główny trwa 3 sekund.

Wątek w tle działający, aż do zakończenia wątku głównego o id: 139754277426944
Instrukcja nr: 1, Bip biiip biiiiip ...
Szacunkowy pozostały czas trwania wątku w tle: 5 sekund.
Instrukcja nr: 2, Bip biiip biiiiip ...
Szacunkowy pozostały czas trwania wątku w tle: 4 sekund.
Instrukcja nr: 3, Bip biiip biiiiip ...
Szacunkowy pozostały czas trwania wątku w tle: 3 sekund.
```

Podobnie jak w języku Emojicode, w jęzku C++ również istnieją mechanizmy synchronizacji wątków, lecz jest ich znacznie więcej, są szerzej rozbudowane (istnieje więcej rodzaji), co więcej są one bardziej szczegółowo opisane, dzięki czemu nie ma problemu znalezienia ich sposobu implementacji i użycia, jak i również zasad działania.
W jezyku C++ wyróżniamy podstawowe obiekty blokad takie jak:
* muteks - inaczej zamek, jest to obiekt, który umożliwia osiągnięcie efektu wzajemnego wykluczenia,
* semafor - wyróżniamy 4 rodzaje semaforów - binarny, ogólny (zliczający), uogólniony oraz dwustronnie ograniczony,
* strażnicy (obiekty klas lock_guard, unique_lock oraz shared_lock), zmienne warunkowe (obiekty klas condition_variable oraz condition_variable_any) oraz bariery.

```
Przykład użycia wielowątkowości w języku C++ wraz z kontrolą sekcji krytycznej wykonywanego programu z zastosowaniem muteksu

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

Wynik powyższego przykładu:

Watek o id: 139719387535104 wykonuje instrukcje nr: 1
Watek o id: 139719387535104 wykonuje instrukcje nr: 2
Watek o id: 139719387535104 wykonuje instrukcje nr: 3
Watek o id: 139719387535104 wykonuje instrukcje nr: 4
Watek o id: 139719387535104 wykonuje instrukcje nr: 5

Watek o id: 139719379142400 wykonuje instrukcje nr: 1
Watek o id: 139719379142400 wykonuje instrukcje nr: 2
Watek o id: 139719379142400 wykonuje instrukcje nr: 3
Watek o id: 139719379142400 wykonuje instrukcje nr: 4
Watek o id: 139719379142400 wykonuje instrukcje nr: 5

Watek o id: 139719370749696 wykonuje instrukcje nr: 1
Watek o id: 139719370749696 wykonuje instrukcje nr: 2
Watek o id: 139719370749696 wykonuje instrukcje nr: 3
Watek o id: 139719370749696 wykonuje instrukcje nr: 4
Watek o id: 139719370749696 wykonuje instrukcje nr: 5
```


Dokumentacja źródła: Threads