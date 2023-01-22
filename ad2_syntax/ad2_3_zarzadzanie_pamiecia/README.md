# 2.3. Zarządzanie pamięcią

Zarządzanie pamięcią w języku Emojicode odbywa się za pomocą zliczania odniesień do obiektu, bądź zmiennej (referencji), oznacza to, że przechowywana i utrzymywana jest liczba referencji do utworzonego obiektu, czy zmiennej. Zgodnie z tym utworzony obiekt, bądź zmienna jest niszczona natychmiastowo w momencie, gdy nie ma do niej żadnych odniesień.

Obiekty lub zmienne, które nie zostały przypisane do żadnej zmiennej, bądź nie są w żaden sposób zwracane, nazywa się wartościami tymczasowymi. Obiekty lub zmienne tego typu są niszczone na końcu wykonywania instrukcji, bloku programu zgodnie z kolejnością, w której zostały utworzone.


W języku Emojicode obsługiwane jest pożyczanie wartości oraz unikanie używania wartości (ucieczka przed użyciem wartości). W momencie gdy wartość obiektu, bądź zmiennej (lub ich kopia) przetrwa wywołanie metody lub inicjalizatora (konstruktora) to taka sytuacja jest nazywana ucieczką przed użyciem wartości, dlatego też taką wartość uważa się za uciekającą. Obszar zastosowań powyższej koncepcji jest zawężony tylko do użycia parametrów metody, bądź konstruktora oraz użycia kontekstu (wartości zwracanej przez parametr ucieczki zastosowany za pomocą adnotacji 👇, w metodzie lub konstruktorze).

Według tej koncepcji istnieją cztery sposoby ucieczki wartości:
* Przypisywanie wartości do zmiennej instancji,
* Przekazywanie wartości do parametru ucieczki,
* Wywoływanie metody ucieczki dla wartości,
* Zwracanie wartości.

W trakcie kompilacji kompilator Emojicode analizuje wszystkie metody pod względem wszystkich możliwych sposobów ucieczki wartości w celu określenia jednoznacznie, czy wartość ucieka, czy jest pożyczana. W celu zobaczenia wszystkich uciekających parametrów oraz metod można posłużyć się dodając adnotację 🎍🥡.


Niekiedy zdarza się, że potrzebne jest uzyskanie referencji do typu wartości w tym celu jedynym możliwym sposobem aby uzyskać odwołanie jest zwrócenie go wewnątrz metody. Należy jednak pamiętać, że nie jest możliwe zwrócenie odwołania do typu wartości w zmiennej lokalnej lub do obiektu tymczasowego, jest to sprzeczne z celem odwołań.

Adnotacja ✴️ działa jak wskaźnik do typu wartości i umożliwia mutację (zmianę) typu wartości w innym obiekcie. Jak wcześniej zaznaczono odwołanie do typu wartości można uzyskać jedynie zwracając ją. Zwrócona referencja może być zmienna tylko wtedy, gdy odbiorca jest zmienny, a mutacja referencji wskazuje kompilatorowi, że odbiorca, którego metoda zwróciła referencję, został zmieniony.

Warto również zaznaczyć, że referencje nie mogą być kopiowane. Nie należy przypisywać odwołania do zmiennej, ponieważ powoduje to natychmiastowe wyłuskanie odwołania i zapisanie kopii w zmiennej, co może prowadzić do poważnych błędów pamięci.

```
Przykład uzyskiwania i przekazywania referencji do typu wartości

🕊 💳 🍇
    🖍🆕 imie 🔡
    🖍🆕 nazwisko 🔡
    🖍🆕 numer_karty 🔡
    🖍🆕 data_waznosci 🔡
    🖍🆕 kod_bezpieczenstwa 🔡

    🆕 🍼 imie 🔡 🍼 nazwisko 🔡 🍼 numer_karty 🔡 🍼 data_waznosci 🔡 🍼 kod_bezpieczenstwa 🔡 🍇🍉

    ❗️ 📙 🍇
        😀 🔤 Dane karty płatniczej 🔤❗️
        😀 🔤 Imie: 🧲imie🧲 🔤 ❗️
        😀 🔤 Nazwisko: 🧲nazwisko🧲 🔤❗️
        😀 🔤 Numer karty: 🧲numer_karty🧲 🔤❗️
        😀 🔤 Data ważności: 🧲data_waznosci🧲 🔤❗️
        😀 🔤 Kod bezpieczeństwa: 🧲kod_bezpieczenstwa🧲 🔤❗️
    🍉
🍉

🕊 🙍 🍇
    🖍🆕 imie 🔡
    🖍🆕 nazwisko 🔡
    🖍🆕 karta_platnicza 💳 

    🆕 🍼 imie 🔡 🍼 nazwisko 🔡 🍼 karta_platnicza 💳 🍇🍉

    ❗️ 🍳 ➡️ ✴️💳 🍇
        ↩️ karta_platnicza
    🍉

    ❗️ 📙 🍇
        😀 🔤 Dane klienta 🔤❗️
        😀 🔤 Imie: 🧲imie🧲 🔤 ❗️
        😀 🔤 Nazwisko: 🧲nazwisko🧲 🔤❗️
    🍉
🍉

🏁 🍇
    🆕💳 🔤Jan🔤 🔤Kowalski🔤 🔤8322978566104798🔤 🔤06/25🔤 🔤596🔤 ❗️ ➡️ karta_platnicza
    🆕🙍 🔤Jan🔤 🔤Kowalski🔤 karta_platnicza ❗️ ➡️ klient_banku
    📙 klient_banku ❗️
    😀 🔤 🔤❗️
    📙 🍳 klient_banku ❗️ ❗️
🍉
```


Czasem zdarza się, że wymagane jest zwrócenie referencji, która zostaje zwracana przez inną funkcję, mowiąc prościej jest to sytuacja, w której funkcja zwracająca odwołanie do typu wartości zostaje wywołana w innej funkcji. Nie jest to bezpieczna operacja, aczkolwiek możliwe jest aby ją wykonać w bezpieczny sposób, wtedy należy opakować wywołanie funkcji zwracającej referencję w niebezpieczny blok za pomocą adnotacji ☣️️, który pozwoli na przekazywanie mutowalnych (zmiennych) referencji. W takim przypadku należy samodzielne przydzielić pamięć za pomocą typu wartości o adnotacji 🧠.

W niektórych przypadkach przydatna jest możliwość sprawdzenia, czy odwołanie do wartości jest unikatowe. W tym celu dodaje się adnotację 🏮 przed zmienną zawierającą referencję do wartości.

Oprócz podstawowego pojęcia referencji istnieje również pojęcie referencji cyklicznej, oznacza to, że automatyczne zliczanie referencji nie może wykryć obiektów, które powinny zostać zniszczone. Odniesienie cykliczne występuje, gdy obiekty wskazują na siebie nawzajem cyklicznie, oznacza to, że jeden obiekt wskazuje na drugi i na odwrót. W takim przypadku żadnego z obiektów nie można zniszczyć, ponieważ oba mają liczbę referencji wynoszącą 1, doprowadza to do tego, że nie zostanie wywołany żaden deinicjalizator (destruktor), a pamięć zarezerwowana dla obiektów nie zostanie zwolniona.

W celu obejścia odwołań cyklicznych stosuje się słabe referencje, które nie są brane pod uwagę przy zliczaniu referencji do obiektu, co doprowadza do rozbicia referencji cyklicznej, która występuje pomiędzy obiektami. 
Słabą referencję należy zastosować w jednej z klas za pomocą adnotacji 📶.


```
Przykładowy przypadek referencji cyklicznej pomiędzy dwoma obiektami
Wraz ze sposobem jej obejścia, czyli zastosowanie słabej referencji w jednej z klas

🐇 🙍 🍇

    🖍🆕 pies 🐶

    🆕 🍼 pies 🐶 🍇
        😀 🔤 Wywołanie konstruktora - Człowieka 🔤❗️
        👇 ➡️ 🙍pies ❗️
    🍉

    ♻️ 🍇
        😀 🔤 Wywołanie destruktora - Człowieka 🔤❗️
    🍉

🍉

🐇 🐶 🍇

    💭 Komentarz: Poprzednio występowała referencja cykliczna
    💭 🖍🆕 czlowiek 🍬🙍

    🖍🆕 czlowiek 🍬📶🐚🙍🍆

    🆕 🍇
        😀 🔤 Wywołanie konstruktora - Psa 🔤❗️
    🍉

    ➡️🙍 nowy_czlowiek 🙍 🍇

        💭 Komentarz: Poprzednio występowała referencja cykliczna
        💭 nowy_czlowiek ➡️ 🖍czlowiek

        🆕📶nowy_czlowiek❗️ ➡️ 🖍czlowiek
    🍉

    ♻️ 🍇
        😀 🔤 Wywołanie destruktora - Psa 🔤❗️
    🍉

🍉

🏁🍇
    🆕🙍 🆕🐶❗️ ❗️
    💭 Komentarz: W programie odniesienie z psa z powrotem do człowieka nie liczy się przy określaniu, czy obiekt człowieka może zostać zniszczony.
🍉
```

# Porównanie do C++

Jeśli chodzi o język C++ istnieją dwa podejścia zarządzania pamięcią:
* statyczne - alokacja pamięci następuje przed rozpoczęciem wykonywania programu i istnieje aż do zakończenia wykonywania programu, pamięć jest zwalniana automatycznie po zakończeniu programu, wadą tego rozwiązania jest potrzeba wcześniejszego przewidzenia wielkości obszaru w pamięci jaki trzeba przydzielić,
* dynamiczne - alokacja pamięci następuje w trakcie wykonywania programu za pomocą deklaracji zmiennych, bądź obiektów za pomocą operatora - new, i istnieje aż do momentu jej zwolnienia za pomocą użycia operatora - delete, zaletą tego rozwiązania jest możliwość dynamicznego rozszerzania przydzielonej pamięci w zależności od potrzeb.

```
Przykład statycznej alokacji pamięci:

int tab[5];
int suma = 0;
```

```
Przykład dynamicznej alokacji pamięci i jej zwolnienia:

int *wektor = new int[10];
delete [] wektor;
```

Podobnie jak w jezyku Emojicode, w języku C++ można odwoływać się do adresu w pamięci określonej zmiennej, bądź obiektu. Jednakże język C++ wprowadza szersze możliwości operacji na adresach w pamięci.

Język C++ wprowadza dwa sposoby odwoływania sie do adresu pamięci zmiennych:
* poprzez referencje,
* poprzez wskaźnik.

Wskaźnik może wskazywać na jakąś zmienną, strukturę, tablicę a nawet funkcję. Jest niczym innym jak zmienną, która nie przechowuje wartości, tylko wskazuje na inną zmienną istniejącą w programie. 

Wyróżnia się dwa podstawowe operatory niezbędne do operowania wskaźnikami:
* operator * - wyłuskuje wartość zmiennej, na którą wskazuje wskaźnik (wyciąga wartość ze wskaźnika),
* operator & - pobiera adresu określonej zmiennej.

```
Przykład deklaracji wskaźników:

int liczba = 100;
int *wsk = &liczba; // przypisanie wskaźnikowi adresu zmiennej liczba
										         
cout << *wsk << endl; // wyświetlenie wyłuskanej wartości wskaźnika - 100
cout << wsk << endl; //wyświetlenie adresu zmiennej liczba
cout << &wsk << endl; // wyświetlenie adresu wskaźnika
```

Referencja w swym działaniu przypomina wskaźniki. Różnica polega jednak na tym, że do referencji można przypisać adres tylko raz, a jej dalsze używanie niczym się nie różni od używania zwykłej zmiennej. Operacje jakie wykona się na zmiennej referencyjnej, zostaną odzwierciedlone na zmiennej zwykłej, z której pobrano adres.
Warto zaznaczyć, że referencja zawsze musi odnosić się do określonej zmiennej, obiektu, nie jest możliwe zadeklarowanie referencji bez przypisania jej do żadnej zmiennej, bądź obiektu, oprócz tego warto wspomnieć, że raz przypisanej referencji do zmiennej nie można zmienić na inną zmienną.
Dodatkowo istnieje możliwość zadeklarowania stałych referencji do zmiennych, obiektów, których następnie nie będzie można modyfikować.

```
Przykład deklaracji referencji:

int i = 0;
int &ref_i = i;
cout << i;      // wypisze 0
ref_i = 1;
cout << i;      // wypisze 1
cout << ref_i;  // wypisze 1
```

```
Przykład błędnej deklaracj referencji:

int a, b;
int &ref_a = a, 
    &ref_b = b;
int &ref_c; // kompilator nie zezwoli na to - referencja niezainicjalizowana
ref_b = &a; // kompilator nie zezwoli na to - nie można zmieniać przypisanej referencji do innej zmiennej
```

```
Przykład deklaracji stałej referencji:

int i = 0;
const int &ref_i = i;
cout << ref_i; // wypisze 0
ref_i = 1;     // kompilator nie zezwoli na to - próba zmiany stałej referencji
```

# To bardziej odniesienie do 2.6. Programowanie obiektowe

W przypadku klas:

* inicjalizator (konstruktor)

W klasie można zdefiniować inicjalizator (konstruktor), który jest wywoływany w trakcie tworzenia instancji klasy (obiektu). W konstruktorze muszą być zainicjowane wszystkie zmienne instancji (składowe klasy).


* deinicjalizator (destruktor)

Poza możliwością zdefiniowania inicjalizatora (konstruktora) w klasie można również zdefiniować deinicjalizator (destruktor), który jest wywoływany tuż przed zniszczeniem instancji klasy (obiektu). 
Deklaruje się go za pomocą adnotacji ♻️.


```
Przykład utworzonej klasy z konstruktorem, destruktorem oraz metodą zwracają zmienne instancji (nazwę, rodzaj ryby)

🐇 🐟 🍇

    🖍🆕 nazwa 🔡
    🖍🆕 rodzaj 🔡

    🆕 🍼 nazwa 🔡 🍼 rodzaj 🔡 🍇
        😀 🔤 Wywołanie konstruktora 🔤❗️
    🍉

    ❗️ 📙 🍇
        😀 🔤 Ryba 🔤❗️
        😀 🔤 Nazwa: 🧲nazwa🧲 🔤 ❗️
        😀 🔤 Rodzaj: 🧲rodzaj🧲 🔤❗️
    🍉

    ♻️ 🍇
        😀 🔤 Wywołanie destruktora 🔤❗️
    🍉

🍉

🏁 🍇
    🆕🐟 🔤Okoń🔤 🔤Słodkowodny🔤 ❗ ➡️ fish
    📙 fish ❗️
🍉
```

Dokumentacja źródła: Memory Management, References, Safe and Unsafe Code

