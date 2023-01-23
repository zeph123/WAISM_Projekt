# 2.2 Typy i struktury danych, operatory (Literals, Variables and Assignment, Operators, Optionals, Enumerations)
</br>

## Literały w Emojicode

W Emojicode typy niektórych literałów nie są ustalone, ale zostaną wywnioskowane na podstawie oczekiwanych typów . Jeśli nie ma żadnych oczekiwań lub literał nie może spełnić oczekiwań, literał utworzy instancję typu domyślnego, który jest określony dla każdego literału.

Te domyślne typy będą pochodzić z pakietu s, który można porównać do tak zwanej biblioteki standardowej w innych językach programowania. Zapewnia niektóre z najważniejszych klas i typów wartości do pisania sensownych programów.

### Literały numeryczne:

- 🔢 - reprezentuje liczby całkowite z przedziału [ $\ -2^{63} $ , $\ 2^{63}-1$ ]
- 💯 - reprezentuje liczby rzeczywiste
- 💧 - reprezentuje bity, które są zapisywane jako liczby całkowite z przedziału [$\ -128,127 $]


Literały całkowite biorą udział w wnioskowaniu o typie i mogą tworzyć instancje dowolnego typu liczbowego. Oznacza to, że literał 130 będzie interpretowany jako 💯, gdy oczekiwane jest 💯. Literał z miejscem po przecinku oczywiście nigdy nie będzie interpretowany jako 🔢 lub 💧.

### Literał logiczny:

- 👌 - literał logiczny przyjmuje dwie wartości tj.:
    - 👍 - wartość true
    - 👎 - wartość false

### Literały tekstowe:

- 🔤 - aby wyświetlić tekst na ekranie należy umieścić go między dwoma takimi znacznikami.
- ❌ - symbol ten pozwala nam "przerwać" tekst

    ```
    🔤Typ znakowy zaczyna się od ❌🔤 symbolu.🔤
    ```

Aby wyświetlić symbol ❌, również musi on zostać "przerwany". W tym celu należy użyć tego symbolu dwuktornie (❌❌).

Symbol ❌ może być również użyty aby wykonać następujące akcje: 
- ❌n Nowa linia
- ❌t Tabulator
- ❌r Powrót karetki (klawisz enter)
- ❌e Escape

### Interpolacja w literałach tekstowych:

Aby dokonać interpolacji tekstu, należy skorzystać z dwóch symboli 🧲. Fragment, który chcemy wstawić musi znajdować się między tymi symbolami. 

```
20 ➡️ zmiennaA\
🔤 Wartością zmiennej zmiennaA jest 🧲zmiennaA🧲🔤
```

### Literały kolekcji: 

- literał listowy - to lista wyrażeń, na przykład poniższy przykład jest literałem o wartościach 14, 67, 2434. 

```
🍿 14 67 2434 🍆
```

Kompilator spróbuje wywnioskować typ literału listy. Domyślnym typem literałów listowych jest typ listy 🍨 , uporządkowane zmienne kolekcje wartości.

- literał słownikowy - W literale słownikowym klucze są powiązane z wartością.

```
🍿
  🔤Aaron Copland🔤 ➡️ 🔤Brooklyn🔤
  🔤Michael Jackson🔤 ➡️ 🔤Gary🔤
  🔤Falco🔤 ➡️ 🔤Vienna🔤
🍆
```

Powyższy przykład pokazuje literał słownikowy, który kojarzy artystów z ich miejscami urodzenia.\
Klucz musi być ciągiem znaków. Kompilator spróbuje wywnioskować typ literału. Aby przypisać wartości do kluczy można używać słowników. Domyślnym typem jest typ 🍯, prosta tablica mieszająca, przechowująca pary klucz-wartość.

## Literały w C++ 

W języku C++ istnieje pięć literałów, tj.:

### Literały całkowite:

Literały całkowite służą do reprezentowania i przechowywania tylko wartości całkowitych. Literały całkowite są wyrażane w dwóch typach:

- Przedrostki - wskazuje on na podstawę, w której ma literał ma być odczytany.
    - literał dziesięty (podstawa 10)

        Jest to niezerowa cyfra dziesiętna, po której następuje zero lub więcej cyfr dziesiętnych (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
        
        ```
        45, 89
        ```

    - literał ósemkowy (podstawa 8)

        0 (zero), po którym następuje zero lub więcej cyfr ósemkowych (0, 1, 2, 3, 4, 5, 6, 7)
        
        ```
        024, 016, 0555
        ```

    - literał szesnastkowy (podstawa 16)

        0x lub 0X, po którym następuje jedna lub więcej cyfr szesnastkowych (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, A, b, B, c, C, d, D, e, E, f, F) 
        
        ```
        0x14B, 0Xcc5, 0xFFB
        ```

    - literał binarny (podstawa 2)

        0b lub 0B, po którym następuje jedna lub więcej cyfr binarnych (0, 1)
        
        ```
        0b111, 0B10101
        ```

- Sufiksy - wskazuje typ, w jakim literał ma być odczytany.
    
    ```
    1234567890LL
    ```

    Taki zapis wskazuje na to że liczba jest typu long long int.

    - int: nie jest wymagany sufiks, ponieważ stała całkowita jest domyślnie przypisywana jako typ danych int.
    - unsigned int: znak u lub U na końcu stałej całkowitej.
    - long int: znak l lub L na końcu stałej całkowitej.
    - unsigned long int: znak ul lub UL na końcu stałej całkowitej.
    - long long int: znak ll lub LL na końcu stałej całkowitej.
    - unsigned long long int: znak ull lub ULL na końcu stałej całkowitej.

### Literały zmiennoprzecinkowe:

Służą one do reprezentowania i przechowywania liczb rzeczywistych. Liczba rzeczywista ma część całkowitą, część rzeczywistą, część ułamkową i część wykładniczą. Literały zmiennoprzecinkowe mogą być przechowywane w postaci dziesiętnej lub wykładniczej. Reprezentując ułamki dziesiętne zmiennoprzecinkowe, należy pamiętać o dwóch rzeczach, aby utworzyć poprawny literał:

- W postaci dziesiętnej należy uwzględnić kropkę dziesiętną, część wykładniczą lub obie, w przeciwnym razie doprowadzi to do błędu.
- W formie wykładniczej należy uwzględnić część całkowitą, część ułamkową lub obie, w przeciwnym razie doprowadzi to do błędu.

Poprawnych literałów zmiennoprzecinkowych:

```
7.677, 2.478-14L, 13.4E-3
```

### Literały znakowe:

Odnosi się to do literału używanego do przechowywania pojedynczego znaku w pojedynczym cudzysłowie. Aby przechowywać wiele znaków, należy użyć tablicy znaków. Przechowywanie więcej niż jednego znaku w pojedynczym cudzysłowie spowoduje wyświetlenie ostrzeżenia i wyświetlenie tylko ostatniego znaku literału. Daje to początek dwóm reprezentacjom:

- typ char - służy do przechowywania literałów o normalnych znakach lub literałów o wąskich znakach.

```
char chr = 'M'; 
```

- typ wchar_t - jeśli znak jest poprzedzony literą 'L' to literł musi być przechowywany jako typ wchar_t. Reprezentuje to literał dwubajtowy.

```
wchar_t chr = L'M';
```

### Literały łańcuchowe:

Literały łańcuchowe są podobne do literałów znakowych, z tą różnicą, że mogą przechowywać wiele znaków i używają podwójnego cudzysłowu do przechowywania tego samego. Mogą również pomieścić znaki specjalne i sekwencje specjalne. Możemy podzielić długą linię na wiele linii za pomocą literału łańcuchowego i oddzielić je za pomocą białych znaków.

```
char stringVal = "Tekstdowyswietlenia"
```

### Literały logiczne:

Służą do reprezentowania boolowskich typów danych. Mogą one mieć dwie wartości:

- true: Aby reprezentować wartość True. Nie należy tego uważać za równe int 1.
- false: Aby reprezentować wartość false. Nie należy tego uważać za równe int 0.

```
const bool isTrue = true;\
const bool isFalse = false;
```

## Zmienne i przypisania w Emojicode

Ważnym aspektem programowania są zmienne. Zmienne łączą nazwę z wartością. Nazwa zmiennej może składać się z dowolnej sekwencji znaków, ale nie może zawierać spacji ani emotikonów ani zaczynać się od cyfry.

Istnieją dwa rodzaje zmiennych: zmienne zmienne i stałe. Zmienne stałe różnią się od normalnych tym, że nie można ich zmienić po początkowym ustawieniu.

### Przypisywanie zmiennej stałej

```
31 ➡️ daysInDecember\
🔤Earth🔤 ➡️ thirdPlanet
```
Wartość, którą chcesz przypisać, znajduje się po lewej stronie symbolu ➡️ podczas gdy zmienna, której chcesz przypisać wartość, znajduje się po prawej stronie.
Kompilator automatycznie wnioskuje o typie zmiennych na podstawie podanych wartości.

Nie można zmienić wartości stałej zmiennej. Jeśli spróbujesz ponownie przypisać stałą zmienną, spowoduje to błąd kompilatora.

### Deklarowanie i przypisywanie zmiennych mutowalnych

Czasami jednak potrzebne są zmienne, których wartości można modyfikować. W tym miejscu pojawiają się mutowalne zmienne.

Zanim będziesz mógł użyć mutowalnej zmiennej, musisz ją zadeklarować. Istnieją dwa sposoby: 
- Deklaracja i przypisanie zmiennej do wartości w jednym kroku, 
- Jawna deklaracja zmiennej bez wartości początkowej.
```
50 ➡️ 🖍🆕 age\
🖍🆕 dogName 🔡
```
Pierwsza linia deklaruje zmienną age oraz przypisuje jej wartość 50. Kompilator wywnioskuje, że typem zmiennej jest 🔢. Druga linia jawnie deklaruje zmienną dogName oraz to że jest ona typu 🔡. Nie ma wartości, dopóki nie zostanie przypisana, a kompilator zgłosi błąd, jeśli spróbujesz jej użyć przed przypisaniem wartości.

### Zmiana wartości zmiennych mutowalnych

Istotą zmiennych mutowalnych jest ich niestałość, więc zobaczmy, jak można zmienić wartość zmiennej mutowalnej.
```
55 ➡️ 🖍 age\
🔤Doggo🔤 ➡️ 🖍 dogName
```
Przypisanie zmiennej mutowalnej jest bardzo podobne do przypisania zmiennej stałej, ale musimy zauważyć, że nazwa zmiennej jest poprzedzona znakiem 🖍. Otrzymasz błąd, jeśli pominiesz 🖍 i otrzymasz błąd, jeśli spróbujesz przypisać niezadeklarowanązmienną w ten sposób.

Ten mechanizm może zapobiegać błędom, które mogą się pojawić w przypadku źle wpisanej zmiennej.

### Określanie zakresu

Zmienne są dostępne tylko z zakresu , w którym zostały zadeklarowane. Każdy blok kodu (wszystko między 🍇 a 🍉) definiuje osobny zakres. Po wyjściu z bloku kodu ten zakres jest niszczony, podobnie jak wszystkie zmienne i wartości, które zostały w nim zadeklarowane. Ponadto klasy i typy wartości definiują swój własny zakres.

### Przypisanie operatora

Przypisanie operatora pozwala na zastosowanie operatora do zmiennej lub dokładniej, operator jest stosowany do wartości zmiennej i innego operandu, a wynik operacji jest następnie przechowywany w zmiennej.
```
0 ➡️ 🖍🆕i\
i ⬅️➕ 1\
i ⬅️➕ 5\
i ⬅️➗ 3\
```
Przypisanie operatora może oczywiście być używane tylko z mutowalnymi zmiennymi.


## Zmienne i przypisania w C++

Zmienne w C++ to nazwa nadana lokalizacji pamięci. Jest to podstawowa jednostka pamięci w programie. 

- Wartość zapisaną w zmiennej można zmienić w trakcie wykonywania programu.
- Zmienna to tylko nazwa nadana lokalizacji w pamięci, wszystkie operacje wykonywane na zmiennej mają wpływ na tę lokalizację w pamięci.
- W C++ wszystkie zmienne muszą być zadeklarowane przed użyciem.

### Zasady deklarowania zmiennych

- Nazwa zmiennej zawiera litery, cyfry i podkreślenia.
- W nazwie zmiennej rozróżniana jest wielkość liter na przykład "Var" i "var" są różnymi zmiennymi.
- Nazwa zmiennej nie zawiera spacji ani znaków specjalnych na przykład "#", "$", "%", "*".
- Wszystkie nazwy zmiennych muszą zaczynać się od litery alfabetu lub znaku podkreślenia "_". 
- Nie możemy użyć słowa kluczowego C++ na przykład "float", "double", "class" jako nazwy zmiennej.

### Jak deklarować zmienne

Deklaracja zmiennych w C++ wygląda następująco:

```
typ_zmiennej nazwa zmiennej;
```

Możliwa jest deklaracja wielu zmiennych tego samego typu jednocześnie

```
typ_zmiennej nazwa_zmiennej1, nazwa_zmiennej2, nazwa_zmiennej3;
```

### Różnica między deklaracją, a definicją zmiennej

Deklaracja zmiennej odnosi się do części, w której zmienna jest deklarowana lub wprowadzana po raz pierwszy przed jej pierwszym użyciem. Definicja zmiennej to część, w której zmiennej jest przypisana lokalizacja w pamięci i wartość. W większości przypadków deklaracja i definicja zmiennej są wykonywane razem.

```
// Deklaracja zmiennej
int a;

// Inicjalizacja zmiennej
a = 15;

// Definicja zmiennej (deklaracja + inicjalizacja)
int b = 25;
```

### Rodzaje zmiennych

Istnieją trzy typy zmiennych w oparciu o zakres zmiennych w C++:
- zmienne lokalne

    Zmienna zdefiniowana w bloku, metodzie lub konstruktorze jest nazywana zmienną lokalną.
    - Zmienne te tworzone są po wejściu do bloku lub wywołaniu funkcji i niszczone po wyjściu z bloku lub po powrocie wywołania z funkcji.
    - Zakres tych zmiennych istnieje tylko w bloku, w którym zmienna jest zadeklarowana. Możemy uzyskać dostęp do tej zmiennej tylko w ramach tego bloku.
    - Inicjalizacja zmiennej lokalnej jest obowiązkowa.

- zmienne instancji

    Zmienne instancji są zmiennymi niestatycznymi i są deklarowane w klasie poza jakąkolwiek metodą, konstruktorem lub blokiem. 
    - Ponieważ zmienne instancji są deklarowane w klasie, zmienne te tworzone są, gdy obiekt klasy jest tworzony i niszczone, gdy obiekt jest niszczony.
    - W przeciwieństwie do zmiennych lokalnych, możemy używać specyfikatorów dostępu dla zmiennych instancji. Jeśli nie określimy żadnego specyfikatora dostępu, zostanie użyty domyślny specyfikator dostępu.
    - Inicjalizacja zmiennej instancji nie jest obowiązkowa.
    - Dostęp do zmiennej instancji można uzyskać tylko poprzez utworzenie obiektów.

- zmienne statyczne

    Zmienne statyczne są również znane jako zmienne klasowe.
    - Zmienne te są deklarowane podobnie jak zmienne instancji, z tą różnicą, że zmienne statyczne są deklarowane przy użyciu słowa kluczowego static w obrębie klasy poza jakimkolwiek konstruktorem metody lub blokiem.
    - W przeciwieństwie do zmiennych instancji, możemy mieć tylko jedną kopię zmiennej statycznej na klasę, niezależnie od tego, ile obiektów tworzymy.
    - Zmienne statyczne są tworzone na początku wykonywania programu i automatycznie niszczone po zakończeniu wykonywania.
    - Inicjalizacja zmiennej statycznej nie jest obowiązkowa. Jego domyślna wartość to 0.
    - Jeśli uzyskamy dostęp do zmiennej statycznej, takiej jak zmienna instancji, kompilator wyświetli komunikat ostrzegawczy i nie zatrzyma programu. Kompilator automatycznie zastąpi nazwę obiektu nazwą klasy.
    - Jeśli uzyskamy dostęp do zmiennej statycznej bez nazwy klasy, kompilator automatycznie doda nazwę klasy.

### Operatory przypisania w C++

Operatory przypisania służą do przypisywania wartości zmiennej. Lewy operand operatora przypisania jest zmienną, a prawy operand operatora przypisania jest wartością. Wartość po prawej stronie musi być tego samego typu danych co zmienna po lewej stronie, w przeciwnym razie kompilator zgłosi błąd.

- = - Ten operator służy do przypisania wartości po prawej stronie do zmiennej po lewej stronie.

```
a = 15;
b = 25;
c = 'example';
```

- += - Ten operator najpierw dodaje bieżącą wartość zmiennej po lewej stronie do wartości po prawej, a następnie przypisuje wynik do zmiennej po lewej stronie.


```
a += b
```
- -= - Ten operator najpierw odejmuje bieżącą wartość zmiennej po lewej stronie od wartości po prawej stronie, a następnie przypisuje wynik zmiennej po lewej stronie.

```
a -= b
```

- *= - Ten operator najpierw mnoży bieżącą wartość zmiennej po lewej stronie przez wartość po prawej stronie, a następnie przypisuje wynik zmiennej po lewej stronie.

```
a *= b
```

- /= - Ten operator najpierw dzieli bieżącą wartość zmiennej po lewej stronie przez wartość po prawej stronie, a następnie przypisuje wynik zmiennej po lewej stronie.

```
a /= b
```

## Operatory

Operatory binarne wykonują operację na dwóch wartościach. Na przykład ➕ jest operatorem zdefiniowanym dla typu 🔢 i sumuje dwie wartości:

```
2 ➕ 14
```

### Grupowanie

Grupowanie pozwala określić, że wynik operacji ma być oceniany bez względu na operatory przed nią lub po niej.

```
🤜 3 ➕ 2 🤛 ✖️ 2
```

Wynikiem takiego kodu będzie 10.

### Priorytet operatora

Kolejność oceniania operatorów jest jasno określona. Operatorzy na górze są oceniani jako pierwsi. Operatory o równym priorytecie są oceniane od lewej do prawej.


1. 🔲, ⬛, 🔺, ⁉️, 🍺
2. 🚮, ➗, ✖️
3. ➖, ➕
4. 👈, 👉
5. ◀️, ▶️, ◀️ 🙌, ▶️ 🙌
6. 🙌, 😜
7. ⭕️
8. ❌
9. 💢
10. 🤝
11. 👐

### Short-Circuiting z 🤝 i 👐

Operator logiczny AND - 🤝 oraz logiczny OR operator - 👐 są zwarte. Oznacza to, że 🤝 oceni swoją prawą stronę tylko wtedy, gdy lewa będzie prawdziwa. 👐, przeciwnie, ocenia tylko prawą stronę, jeśli lewa była fałszywa.

Ze względu na to szczególne zachowanie 🤝 i 👐 nie można zdefiniować dla żadnego innego typu niż 👌.

### Definiowanie operacji dla typów niestandardowych

Można również zdefiniować operatory dla typów niestandardowych. Operator można zdefiniować podobnie jak metodę. To jest przykład z typu 📇 pakietu s:

```
➕ b 📇 ➡️ 📇 🍇
  count ➕ 📏b❗️ ➡️ new_count
  💭 ...
🍉
```

Różnica w stosunku do zwykłej deklaracji metody polega po prostu na tym, że zamiast nastroju (❗️ lub ❓) pojawia się operator. Ponadto nie podano nazwy.

### Kontrola tożsamości

😜 można użyć do określenia, czy dwa odniesienia do obiektów wskazują na ten sam obiekt w pamięci.

To nie jest sprawdzanie równości: dwa obiekty mogą reprezentować tę samą wartość, ale nadal są to dwa różne obiekty, które nie dzielą tej samej lokalizacji pamięci. Aby określić równość, użyj 🤝, jeśli jest dostępny.

😜 zwraca wartość true, jeśli wynikiem obu wyrażeń są odwołania do tej samej lokalizacji w pamięci. Aby uniknąć nieporozumień, nie można go zdefiniować niestandardowo.

## Operatory w C++

Operatory w C++ można podzielić na 6 typów:
- Operatory arytmetyczne
- Operatorzy relacyjni
- Operatory logiczne
- Operatory bitowe
- Operatory przypisania
- Operatory trójskładnikowe lub warunkowe

### Operatory arytmetyczne

Operatory te służą do wykonywania operacji arytmetycznych lub matematycznych na operandach.
Operatory arytmetyczne można podzielić na dwie grupy:
- operatory jednoargumentowe - te operatory operują lub pracują z jednym operandem.
    - operator przyrostu - ++
    - operator dekrementacji - --

```
    int a = 10;
    cout << "a++ is " << a++ << endl;
    cout << "++a is " << ++a << endl;
  
    int b = 15;
    cout << "b-- is " << b-- << endl;
    cout << "--b is " << --b << endl;
```

- operatory binarne - te operatory działają lub pracują z dwoma operandami.
    - dodawanie - +
    - odejmowanie - -
    - mnożenie - *
    - dzielenie - /
    - dzielenie modulo - %

```
    int a = 5, b = 7;
  
    // Dodawanie
    cout << "a + b = " << (a + b) << endl;
    
    // Odejmowanie
    cout << "a - b = " << (a - b) << endl;
    
    // Mnożenie
    cout << "a * b = " << (a * b) << endl;
    
    // Dzielenie
    cout << "a / b = " << (a / b) << endl;
    
    // Dzielenie modulo
    cout << "a % b = " << (a % b) << endl;
```

### Operatory relacyjne

Operatory te używane są do porównywania wartości dwóch operandów. Na przykład '>' sprawdza, czy jeden operand jest większy od drugiego operandu, czy nie. Wynik zwraca wartość logiczną prawda lub fałsz.

- jest równe - ==
- większy niż - >
- większy lub równy - >=
- mniejszy niż - <
- mniejszy lub równy - <=
- różny - !=

```
    int a = 8, b = 3;
  
    // Jest równe
    cout << "a == b is " << (a == b) << endl;
    
    // Większy niż
    cout << "a > b is " << (a > b) << endl;
    
    // Większy lub równy
    cout << "a >= b is " << (a >= b) << endl;
    
    //  Mniejszy niż
    cout << "a < b is " << (a < b) << endl;
    
    // Mniejszy lub równy
    cout << "a <= b is " << (a <= b) << endl;
    
    // Różny
    cout << "a != b is " << (a != b) << endl;
```

### Operatory logiczne

Operatory te używane są do łączenia dwóch lub więcej warunków lub ograniczeń lub do uzupełniania oceny rozważanego warunku pierwotnego. Wynik zwraca wartość logiczną true lub false.

- AND - && - zwraca true tylko wtedy, gdy wszystkie operandy są prawdziwe lub niezerowe
- OR - || - zwraca true, jeśli którykolwiek z operandów jest prawdziwy lub niezerowy
- NOT - ! - zwraca true, jeśli operand ma wartość false lub zero

```
    int a = 8, b = 3;
  
    // AND
    cout << "a && b is " << (a && b) << endl;
    
    // OR
    cout << "a ! b is " << (a > b) << endl;
    
    // NOT
    cout << "!b is " << (!b) << endl;
```
### Operatory bitowe

Operatory te używane są do wykonywania operacji na poziomie bitów na operandach. Operatory są najpierw konwertowane na poziom bitowy, a następnie obliczenia są wykonywane na operandach. Operacje matematyczne, takie jak dodawanie, odejmowanie, mnożenie itp., mogą być wykonywane na poziomie bitów w celu szybszego przetwarzania. 

- binarne AND - kopiuje bit do ocenianego wyniku, jeśli istnieje w obu operandach
- binarne OR - kopiuje bit do ocenianego wyniku, jeśli istnieje on w którymkolwiek z operandów
- binarne XOR - kopiuje bit do ocenianego wyniku, jeśli jest obecny w jednym z operandów, ale nie w obu
- binarne przesunięcie w lewo - przesuwa wartość w lewo o liczbę bitów określoną przez prawy operand.
- binarne przesunięcie w prawo - przesuwa wartość w prawo o liczbę bitów określoną przez prawy operand.
- komplement - zmienia cyfry binarne 1 na 0 i 0 na 1

```
    int a = 8, b = 3;
  
    // binarne AND
    cout << "a & b = " << (a & b) << endl;
    
    // binarne OR
    cout << "a | b = " << (a | b) << endl;
    
    // binarne XOR
    cout << "a ^ b = " << (a ^ b) << endl;
    
    //  binarne przesunięcie w lewo
    for (int i = 0; i < 4; i++) {
        cout << "212 << " << i << " = " << (212 << i) << endl;
    }
    
    // binarne przesunięcie w prawo
    for (int i = 0; i < 4; i++) {
        cout << "212 >> " << i << " = " << (212 >> i) << endl;
    }
    
    // komplement
    cout << "~(" << a << ") = " << (~a) << endl;
    cout << "~(" << b << ") = " << (~b) << endl;
```

### Operatory przypisania

Operatory te służą do przypisywania wartości do zmiennej. Operand po lewej stronie operatora przypisania jest zmienną, a operand po prawej stronie operatora przypisania jest wartością. Wartość po prawej stronie musi być tego samego typu danych co zmienna po lewej stronie, w przeciwnym razie kompilator zgłosi błąd. 

- operator przypisania - = - przypisuje wartość po prawej stronie zmiennej po lewej stronie 
- operator dodawania i przypisania - += - najpierw dodaje bieżącą wartość zmiennej po lewej do wartości po prawej, a następnie przypisuje wynik do zmiennej po lewej 
- operator odejmowania i przypisania - -= - najpierw odejmuje wartość po prawej stronie od aktualnej wartości zmiennej po lewej, a następnie przypisuje wynik do zmiennej po lewej
- operator mnożenia i przypisania - *= - najpierw mnoży bieżącą wartość zmiennej po lewej przez wartość po prawej, a następnie przypisuje wynik do zmiennej po lewej
- operator dzielenia i przypisania - /= - najpierw dzieli bieżącą wartość zmiennej po lewej przez wartość po prawej, a następnie przypisuje wynik do zmiennej po lewej

```
    int a = 8, b = 3;
  
    // Operator przypisania
    cout << "a = " << a << endl;
    
    //  Operator dodawania i przypisania
    cout << "a += b is " << (a += b) << endl;
    
    // Operator odejmowania i przypisania
    cout << "a -= b is " << (a -= b) << endl;
    
    //  Operator mnożenia i przypisania
    cout << "a *= b is " << (a *= b) << endl;
    
    //  Operator dzielenia i przypisania
    cout << "a /= b is " << (a /= b) << endl;
```
### Operatory trójskładnikowe lub warunkowe

```
Wyrażenie1? Wyrażenie2: Wyrażenie3
```

Operator trójskładnikowy ? określa odpowiedź na podstawie oceny Wyrażenie1. Jeśli ma wartość true, obliczane jest wyrażenie Wyrażenie2, które jest używane jako odpowiedź dla wyrażenia. Jeśli wyrażenie Wyrażenie1 ma wartość false, obliczane jest wyrażenie Wyrażenie3, które jest używane jako odpowiedź dla wyrażenia.

Ten operator przyjmuje trzy argumenty, dlatego jest znany jako operator trójskładnikowy. 

```
    int a = 3, b = 4;
  
    // Operator trójskładnikowy
    int result = (a < b) ? b : a;
    cout << "The greatest number is " << result << endl;
```

## Typ opcjonalny w Emojicode

Często podczas projektowania aplikacji programista musi radzić sobie z możliwym brakiem wartości. Aby właściwie modelować brak wartości, opracowano koncepcję opcji.
Opcjonalny to typ, który albo nie zawiera wartości, albo ją zawiera.

Można zadeklarować opcjonalny typ za pomocą 🍬, po którym następuje typ, który opcjonalny może zawierać:

```
🖍🆕 building_age 🍬🔢  💭 Wiek budynku czesto nie jest znany.
🖍🆕 pet_name 🍬🔡  💭 Niektóre zwierzęta nie mają imion.
```

W powyższym przykładzie zadeklarowane zostały dwie zmienne, z których obie są opcjonalne. W tej chwili nie zawierają wartości. Kiddy deklarujemy zmienną typu opcjonalnego, jest ona automatycznie inicjowana, ale nie zawiera wartości.

### Bez wartości

Typ opcjonalny czasami nie zawiera żadnej wartości. Oczywiście wymagany jest również sposób wyrażenia „brak wartości” w kodzie. Dokładnie to robi wyrażenie No Value. Wyrażenia No Value można użyć tylko wtedy, gdy oczekiwana jest wartość opcjonalna lub podczas porównywania wartości opcjonalnej, jak zobaczymy poniżej.

```
🤷‍♂️ ➡️ 🖍pet_name
```

### Porównanie z Bez wartości

Aby określić, czy opcja zawiera wartość, czy nie. Możemy to osiągnąć, po prostu porównując opcję opcjonalnie z 🤷‍ z operatorem porównania 🙌. Na przykład:

```
↪️ pet_name 🙌 🤷‍♀️ 🍇
  😀 🔤The pet has no name🔤❗️
🍉
```

### 🍺 Rozpakowywanie

Rozpakowanie oznacza nic innego jak wyodrębnienie wartości zawartej w opcjonalnym.
Aby wyodrębnić wartość z pet_namepowyższego przykładu i wydrukować ją, używamy 🍺:

```
😀 🍺 pet_name❗️
```

To zadziała dobrze, jeśli petName faktycznie zawiera imię zwierzaka. Jeśli jednak nie zawiera wartości, nasz program wpadnie w panikę.
Ponieważ zazwyczaj chcemy uniknąć nagłych błędów, opcjonalny znak 🍺 należy rozpakowywać tylko wtedy, gdy mamy pewność, że zawiera wartość.

### Przypisanie warunku

Rozpakowywanie opcji nie jest bezpieczne bez uprzedniego sprawdzenia. Ponieważ jest to powszechna operacja, Emojicode oferuje strukturę zwaną przypisaniem warunku.

```
↪️ pet_name ➡️ the_pet_name  🍇
  😀 the_pet_name❗️
🍉
```

Powyższy kod przypisze wartość opcji pet_name do the_pet_name pod warunkiem, że ma wartość i powiązany blok ↪️ zostanie wykonany. Jeśli opcjonalny nie ma wartości, ↪️ zachowuje się tak, jakby warunek został oceniony jako fałszywy.

## Wyliczenia

Wyliczenia to specjalny rodzaj typu wartości, który reprezentuje zestaw opcji, z których można wybrać jedną.

```
🔘 ⏰ 🍇
  🆕▶️🥓
  🆕▶️🥞
  🆕▶️🥐
🍉
```

W tym przykładzie zdefiniowano wyliczenie o nazwie ⏰, które oferuje wartości 🥓, 🥞 i 🥐.

### Tworzenie wystąpienia wyliczenia

Każde wyliczenie automatycznie zapewnia inicjatory dla wszystkich swoich opcji, nazwane na cześć opcji, którą będzie reprezentować instancja. Jak każdy typ wartości, wyliczenia są tworzone za pomocą 🆕:

```
🆕⏰▶️🥓❗
```

Wyliczenia nie mogą mieć niestandardowych inicjatorów.

### Metody

Podobnie jak inne typy wartości, wyliczenia mogą mieć metody. Poniższe przykłady pokazują wyliczenie, które zapewnia metodę zwracającą tekstowy opis wybranej wartości:

```
🔘 ⏰ 🍇
  🆕▶️🥓
  🆕▶️🥞
  🆕▶️🥐

  ❗️ 🔡 ➡️ 🔡🍇
    ↪️ 👇 🙌 🆕⏰▶️🥐❗️ 🍇
      ↩️ 🔤Croissant🔤
    🍉

    ↪️ 👇 🙌 🆕⏰▶️🥞❗️ 🍇
      ↩️ 🔤Pancakes🔤
    🍉

    ↪️ 👇 🙌 🆕⏰▶️🥓❗️ 🍇
      ↩️ 🔤Bacon🔤
    🍉

    ↩️ 🔤🔤
  🍉

🍉
```

### Porównywanie wyliczeń

Można użyć 🙌 do porównania, czy dwie instancje enum są równe:

```
🆕⏰▶️🥓❗️ ➡️ a
🆕⏰▶️🥓❗️ ➡️ b
↪️ a 🙌 b 🍇
    😀 🔤Equal🔤❗️
🍉
```

## Wyliczenia w C++

Typ wyliczeniowy to zdefiniowany przez użytkownika typ danych, któremu można przypisać pewne ograniczone wartości. Wartości te są definiowane przez programistę w momencie deklarowania typu wyliczeniowego.

Jeśli przypiszemy wartość zmiennoprzecinkową do wartości znakowej, to kompilator wygeneruje błąd. W ten sam sposób, jeśli spróbujemy przypisać jakąkolwiek inną wartość do wyliczonych typów danych, kompilator wygeneruje błąd. Typy wyliczające wartości są również znane jako wyliczacze. Jest również przypisywany przez zero, tak samo jak tablica. Może być również używany z instrukcjami switch.
Jeśli na przykład tworzona jest zmienna płci z wartością mężczyzna lub kobieta. Jeśli przypisywana jest jakakolwiek inna wartość niż mężczyzna lub kobieta, nie jest to właściwe. W takiej sytuacji można zadeklarować typ wyliczeniowy, w którym przypisane są tylko wartości męskie i żeńskie.

```
enum enumerated-type-name{value1, value2, value3…..valueN};
```

Słowo kluczowe "enum" służy do deklarowania typów wyliczeniowych po zapisaniu tej nazwy typu wyliczeniowego, a następnie w nawiasach klamrowych definiowane są możliwe wartości. Po zdefiniowaniu tworzone są zmienne typu wyliczeniowego. Można go utworzyć w dwóch typach:

- podczas deklarowania typów wyliczeniowych, wystarczy dodać nazwę zmiennej przed średnikiem. lub,
- możemy tworzyć zmienne typu wyliczeniowego tak samo, jak zwykłe zmienne.

Domyślnie początkowa wartość kodu pierwszego elementu wyliczenia to 0 (jak w przypadku tablicy). Ale można to wyraźnie zmienić.

```
enum wyliczona-nazwa-typu{wartość1=1,wartość2,wartość3};
```
