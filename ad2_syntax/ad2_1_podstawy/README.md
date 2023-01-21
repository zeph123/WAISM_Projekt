
# 2.1. Podstawy

## Plik źródłowy

Plik źródłowy (ang. source file) w języku Emojicode jest to dokument tekstowy zakodowany w UTF-8 zgodnie ze składnią określoną przez gramatykę w dokumentacji Emojicode.

Każdy plik źródłowy musi być zgodny z nazewnictwem w postaci:
* nazwa_pliku.🍇 (z rozszerzeniem .🍇) lub
* nazwa_pliku.emojic (z rozszerzeniem .emojic).

Drugie z rozszerzeń .emojic zostało stworzone z myślą, aby zapewnić zgodność z systemami, które mają problem z obsługą nazw plików emoji (najrozsądniej jest korzystać z tego rozszerzenia).

## Kompilacja i uruchomienie programu 

Aby skompilować plik źródłowy do wykonywalnego programu w języku Emojicode należy otworzyć wiersz poleceń (interpreter), następnie przejść do katalogu zawierającego plik, który chcemy skompilować, po czym uruchomić następujące polecenie:

```
$ emojicodec nazwa_pliku.emojic
```

Polecenie emojicodec służy do kompilacji pliku źródłowego zawierającego wykonywalny program do natywnego plik wykonywalnego, który można następnie uruchomić z poziomu wiersza poleceń (interpretera).

```
$ ./nazwa_pliku
```

## Kompilator

Kompilator Emojicode wykorzystuje w swoim działaniu kompilator i linker C++ - clang++ albo g++. Kompilator Emojicode wywołuje się w wierszu poleceń (interpreterze) za pomocą następującego polecenia:

```
$ emojicodec <instrukcje>
```

Służy głównie do kompilacji plików źródłowych do natywnych plików wykonywalnych (binarnych). W domyślnym ustawieniu plik wyjściowy ma nadawaną taką samą nazwę jak plik główny. Domyślną nazwę pliku wyjściowego można zmienić za pomocą opcji -o.

```
Kompilacja do pliku wykonywalnego (bez zmiany nazwy pliku wyjściowego)
Otrzymane pliki po udanej kompilacji: 
   - plik wykonywalny nazwa_pliku,
   - plik obiektowy nazwa_pliku.o

$ emojicodec nazwa_pliku.emojic
```

```
Kompilacja do pliku wykonywalnego (ze zmianą nazwy pliku wyjściowego)
Otrzymane pliki po udanej kompilacji: 
   - plik wykonywalny nowaNazwaPliku,
   - plik obiektowy nazwa_pliku.o

$ emojicodec nazwa_pliku.emojic -o nowaNazwaPliku
```

Poza podstawowym wykorzystaniem kompilatora używa się go również do kompilacji plików źródłowych do pakietów, a także do plików obiektowych. Istnieje także możliwość zastosowania kompilacji do pakietów z dodatkowymi optymalizacjami.
W celu skompilowania pliku źródłowego do pakietu (biblioteki statycznej) należy uruchomić kompilator z opcją -p nazwa_pakietu, natomiast jeśli chcemy skompilować plik źródłowy do pliku obiektowego należy uruchomić kompilator z opcją -c.

```
Kompilacja do pakietu
Otrzymane pliki po udanej kompilacji: 
   - plik interfejsu o nazwie 🏛, 
   - pakiet o nazwie libNazwaPakietu.a, z prefiksem lib- i rozszerzeniem .a,
   - plik obiektowy nazwa_pliku.o

$ emojicodec -p NazwaPakietu nazwa_pliku.emojic
```

```
Kompilacja do pliku obiektowego

Otrzymane pliki po udanej kompilacji:
   W przypadku kompilacji do pakietu:
      - plik interfejsu o nazwie 🏛, 
      - plik obiektowy nazwa_pliku.o

$ emojicodec -p NazwaPakietu nazwa_pliku.emojic -c

Otrzymane pliki po udanej kompilacji:
   W przypadku kompilacji do pliku wykonywalnego:
      - plik obiektowy nazwa_pliku.o

$ emojicodec nazwa_pliku.emojic -c
```

```
Kompilacja z dodatkowymi optymalizacjami

Otrzymane pliki po udanej kompilacji:
   W przypadku kompilacji do pakietu:
      - plik interfejsu o nazwie 🏛, 
      - pakiet o nazwie libNazwaPakietu.a, z prefiksem lib- i rozszerzeniem .a,
      - plik obiektowy nazwa_pliku.o

$ emojicodec -p nazwa_pakietu nazwa_pliku.emojic -O

Otrzymane pliki po udanej kompilacji:
   W przypadku kompilacji do pliku wykonywalnego:
      - plik wykonywalny nazwa_pliku,
      - plik obiektowy nazwa_pliku.o

$ emojicodec nazwa_pliku.emojic -O
```

## Program wykonywalny

Blok wykonywalnego programu w Emojicode składa się z kilku podstawowych części, takich jak:
* 🏁 - jest to główna część programu, która jest wykonywana zaraz po uruchomieniu pliku wykonywalnego, blok może również zwrócić liczbę całkowitą, która używana jest jako kod wyjścia programu, ale nie jest to wymagane,
* 🍇 - jest to część otwierająca program,
* 🍉 - jest to część zamykająca program.

Pomiędzy częścią otwierająca program 🍇, a częścią zamykającą program umieszcza się właściwy kod programu - instrukcje do wykonania.

```
Blok programu (bez zwracania wartości)

🏁 🍇
   💭 Właściwy kod programu, instrukcje do wykonania ...
🍉
```

```
Blok programu (ze zwracaniem wartości)

🏁 ➡️ 🔢 🍇
   💭 Właściwy kod programu, instrukcje do wykonania ...
  ↩️ 0
🍉
```

```
Przykładowy dłuższy program

🏁 🍇

    😀 🔤 Cześć, jestem programem 3. 🔤❗️

    💭 Obliczenie sumy liczb całkowitych bez użycia funkcji

    💭🔜
        Deklaracja zmiennej suma jako zmiennej modyfikowalnej
        Będzie ona przechowywać sumę dwóch argumentów
        Przypisanie zmiennej wartości 0
    🔚💭
    0 ➡️ 🖍🆕 suma

    💭 Deklaracja stałych zmiennych liczb całkowitych
    1 ➡️ a
    5 ➡️ b

    💭 Operacja sumowania argumentów 
    suma ⬅️➕ a
    suma ⬅️➕ b

    😀 🔤 Obliczenia wykonane bez użycia funkcji 🔤 ❗️
    😀 🔤 Suma wyrażenia: 🧲 a 🧲 + 🧲 b 🧲 = 🧲 suma 🧲🔤 ❗️

    
    💭🔜
        Funkcja obliczająca sumę
        Funkcja przyjmuje 2 argumenty: a, b - liczby całkowite
    🔚💭
    🍇 a 🔢 b 🔢 ➡️ 🔢

        💭🔜
        Deklaracja zmiennej suma jako zmiennej modyfikowalnej
        Będzie ona przechowywać sumę dwóch argumentów
        Przypisanie zmiennej wartości 0
        🔚💭
        0 ➡️ 🖍🆕 suma

        💭 Operacja sumowania argumentów 
        suma ⬅️➕ a
        suma ⬅️➕ b

        💭 Zwrócenie zmiennej suma
        ↩️ suma
    
    💭 Nazwanie funkcji
    🍉 ➡️ obliczSume

    😀 🔤 Obliczenia wykonane za pomocą funkcji - obliczSume(a,b) 🔤 ❗️

    😀 🔤 Suma wyrażenia: 1 + 2 = 🧲 ⁉️ obliczSume 1 2 ❗️ 🧲🔤 ❗️

    1 ➡️ a2
    3 ➡️ b2

    😀 🔤 Suma wyrażenia: 🧲 a2 🧲 + 🧲 b2 🧲 = 🧲 ⁉️ obliczSume a2 b2 ❗️ 🧲🔤 ❗️

🍉
```

## Pakiety

Pakiet w Emojicode jest to jednostka kodu, która składa się z jednego lub więcej plików źródłowych Emojicode. Każdy z tworzonych pakietów powinien mieć przypisaną nazwę (oryginalną, rozróżnialną od innych pakietów), którą podajemy w czasie kompilacji. Cały kod pliku źródłowego kompilowanego do pakietu należy do utworzonego pakietu, oznacza to, że ten plik domyślnie staje się głównym plikiem nowo utworzonego pakietu.

Celem tworzenia pakietów jest zapewnienie możliwości wielokrotnego użycia tego samego zdefiniowanego kodu oraz umożliwienie wydzielania logiki programu na pojedyncze pomniejsze jednostki logiczne. Sprawia to, że objętość kodu pisanego programu ulega zmniejszeniu, zapewnia lepszą czytelność kodu programu, natomiast podział kodu programu na bloki, segmenty odpowiadające za pojedynczą funkcjonalność pozwala na szybkie dotarcie do sedna problemu, jeśli takowy wystąpi, znacznie skraca czas naprawy błędów.

Każdy tworzony pakiet ma swój własny zestaw przestrzeni nazw. Jeśli zdefiniujesz lub zaimportujesz typy w jednym pakiecie, typy te nie będą dostępne w innych pakietach bez ich jawnego wyeksportowania i zaimportowania.

Importowanie innych plików źródłowych, pakietów odbywa się w następujący sposób:

```
Dołączanie pliku źródłowego z tego samego katalogu (bieżącego katalogu) 

📜 🔤nazwa_pliku.emojic🔤

Dołączanie pliku źródłowego z innego katalogu

📜 🔤sciezka_do_pliku/nazwa_pliku.emojic🔤
```

```
Dołączanie pakietu z domyślnej przestrzeni nazw 🏠

📦 nazwa_pakietu 🏠

Dołączanie pakietu z innej przestrzeni nazw

📦 nazwa_pakietu emoji_przestrzeni_nazw
```

Poniżej znajduje się implementacja pakietu, który eksportuje klasę 🧙‍♂️, która przyjmuje w konstruktorze 2 parametry typu całkowitego. W poniższej klasie zaimplementowane zostały dwie metody: jedna służy do obliczenia sumy dwóch liczb, natomiast druga służy do wyniku sumy dwóch liczb.

```
Przykład pakietu

💭 Przykładowy pakiet
💭🔜
   Nazwa pakietu - functions
   Importowanie pakietu za pomocą:
   📦 functions 🏠
🔚💭

🌍 🐇 🧙‍♂️ 🍇

   🖍🆕 liczba_A 🔢
   🖍🆕 liczba_B 🔢
   🖍🆕 suma 🔢 ⬅️ 0

   🆕 🍼 liczba_A 🔢 🍼 liczba_B 🔢 🍇🍉

   ❗️ 💧 🍇
      0 ➡️ 🖍🆕 temp
      temp ⬅️➕ liczba_A
      temp ⬅️➕ liczba_B
      temp ➡️ 🖍suma
   🍉

   ❗️ 🔥 🍇
      😀 🔤🧲liczba_A🧲 + 🧲liczba_B🧲 = 🧲suma🧲🔤❗️
   🍉

🍉
```

```
Przykładowy program wykorzystujący pakiet

📦 functions 🏠

🏁 🍇
    🆕🧙‍♂️ 1 5 ❗️ ➡️ suma1
    💧 suma1 ❗️
    🔥 suma1 ❗️

    🆕🧙‍♂️ 3 4 ❗️ ➡️ suma2
    💧 suma2 ❗️
    🔥 suma2 ❗️

    🆕🧙‍♂️ 2 8 ❗️ ➡️ suma3
    💧 suma3 ❗️
    🔥 suma3 ❗️
🍉
```

Kolejność wykonywania działań w wierszu poleceń (interpreterze):

```
Aby wyeksportować pakiet należy zastosować komendę:

$ emojicodec -p functions pakiet1.emojic
```

```
Następnie wygenerowane pliki umieścić w katalogach zgodnie z poniższym rozkładem:

├── packages
│   └── functions
│       ├── 🏛
│       └── libfunctions.a
└── program4.emojic
```

```
Kompilacja programu:

$ emojicodec program4.emojic

Wywołanie programu:

$ ./program4

1 + 5 = 6
3 + 4 = 7
2 + 8 = 10
```

# Porównanie do C++

...


Dokumentacja źródła: Welcome to Emojicode, Syntax, The Basics, Packages, Appendix: The Emojicode Compiler