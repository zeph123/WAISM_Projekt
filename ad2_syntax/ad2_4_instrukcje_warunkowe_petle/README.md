# 2.4 Instrukcje warunkowe, pętle

## Kontrola przepływu w Emojicode

Emojicode zapewnia różne typy instrukcji przepływu sterowania, które pozwalają uporządkować przepływ programu.

### 🍇🍉 Blok kodu

Bloki kodu są używane w połączeniu ze strukturami przepływu sterowania w celu grupowania instrukcji, które będą wykonywane tylko wtedy, gdy warunek zostanie spełniony lub nie, lub który zostanie powtórzony.

### ↪️ Jeśli (if)

Oświadczenie ↪️ jest bardzo ważne. Pozwala na warunkowe wykonanie bloku kodu. Jeśli warunek ma wartość 👍, blok kodu zostanie wykonany, a jeśli ma wartość 👎, zostanie zignorowany.

W tym przykładzie zostanie wyświetlone „a jest większe niż b”, jeśli zawartość zmiennej a jest większa niż b :

```
↪️ a ▶️ b 🍇
  😀 🔤a is greater than b🔤❗️
🍉
```

### 🙅 (else)

🙅 rozszerza instrukcję ↪️, aby wykonać dodatkowy blok kodu na wypadek, gdyby wyrażenie w instrukcji if miało wartość false. Na przykład poniższy kod wyświetli „a jest większe niż b”, jeśli a jest większe niż b, a „a nie jest większe niż b” w przeciwnym razie:

```
↪️ a ▶️ b 🍇
  😀 🔤a is greater than b🔤❗️
🍉
🙅 🍇
  😀 🔤a is not greater than b🔤❗️
🍉
```

Instrukcje 🙅 są wykonywane tylko wtedy, gdy instrukcja ↪️ ma wartość fałszywą i jeśli wszystkie instrukcje 🙅↪️ również mają wartość fałszywą.

### 🙅↪️ (else if)

🙅↪️ rozszerza instrukcję ↪️, aby wykonać różne instrukcje w przypadku, gdy pierwotny warunek ↪️ ma wartość 👎. Jednak w przeciwieństwie do ↪️, wykona alternatywne wyrażenia tylko wtedy, gdy wyrażenie ↪️ to 👍. Na przykład poniższy kod wyświetli „a jest większe niż b”, „a jest równe b” lub „a jest mniejsze niż b”:

```
↪️ a ▶️ b 🍇
  😀 🔤a is greater than b🔤❗️
🍉
🙅↪️ a 🙌 b 🍇
  😀 🔤a is equal to b🔤❗️
🍉
🙅 🍇
  😀 🔤a is smaller than b🔤❗️
🍉
```

Instrukcja 🙅↪️ jest wykonywana tylko wtedy, gdy poprzedzające wyrażenie ↪️ i dowolne poprzedzające wyrażenia 🙅↪️ są oceniane na 👎, a bieżące wyrażenie 🙅↪️ oceniane na 👍.

### 🔂 (for in)

Instrukcja 🔂 umożliwia szybkie iterowanie instancji, czyli wielokrotne pobieranie z niej wartości, dopóki nie będzie już więcej wartości do podania. Na przykład możemy iterować po instancji 🍨, a otrzymamy wszystkie elementy zawarte na liście. Instrukcja 🔂 może iterować po instancjach dowolnego typu, który jest zgodny z protokołem 🔂🐚Element🍆.

```
🍡 iterable❗️ ➡️ iterator
🔁 🔽 iterator❓️ 🍇
  🔽 iterator❗️ ➡️ variable
  💭 The provided block is executed here
🍉
```

gdzie iterable to instancja do iteracji (wynik oceny wyrażenia), a variable to podana nazwa zmiennej. Najwyraźniej zmienna będzie typu, który został dostarczony do ogólnego argumentu Element , gdy typ iterowalny zadeklarował swoją zgodność z 🔂🐚Element🍆.

### Interludium: ⏩ Zasięgi

Pakiet s zawiera typ ⏩, reprezentujący zakres. Zakres jest niezmienną sekwencją liczb całkowitych i jest zdefiniowany przez trzy wartości start, stop i step. Jeśli step jest dodatnia, każda liczba f(x) = start + x * step pasująca do ograniczenia start ≤ f(x) < stopjest elementem zakresu. Jeśli stepjest ujemne, stop < f(x) ≤ startzamiast tego stosuje się ograniczenie.

Zakresy są pomocne, jeśli musimy powtórzyć coś określoną liczbę razy:

```
🔂 i 🆕⏩ 0 10 2❗️ 🍇
  😀 🔡 i❗️❗️  💭 Prints numbers 0 through 8 (including).
🍉

🔂 i 🆕⏩ 0 10❗️ 🍇
  😀 🔡 i❗️❗️  💭 Prints numbers 0 through 9 (including).
🍉

🔂 i 🆕⏩ 10 0❗️ 🍇
  😀 🔡 i❗️❗️  💭 Prints numbers 10 through 1 (including).
🍉

🔂 i 🆕⏩ 100 -10 -10❗️ 🍇
  😀 🔡 i❗️❗️  💭 Prints numbers 100 through 0 (including).
🍉
```

### 🔁 (repeat while)

🔁 powtarza dany blok kodu tak długo, jak warunkiem jest 👍. Oznacza to również, że jeśli warunek nigdy nie jest 👍, blok kodu nigdy nie zostanie wykonany.

```
🔁 👍 🍇
  😀 🔤It goes on and on and on🔤❗️
🍉
```

### 🎍🐌 🎍🏎 Szybkość gałęzi

Dekoratory 🎍🐌 (wolne) i 🎍🏎 (szybkie) pozwalają określić kompilatorowi, które gałęzie w ↪️ będą wolne lub szybkie. Może to umożliwić lepszą optymalizację kodu wrażliwego na wydajność.

Poniższy przykład pokazuje instrukcję if, której jedyna gałąź została oznaczona jako wolna

```
↪️ size 🙌 count 🎍🐌🍇
  size ⬅️✖️ 2
  ☣️ 🍇
    🏗 data size✖️⚖️Element❗️
  🍉
🍉
```

## Kontrola przepływu w C++



### Instrukcje wyboru - if oraz else

Słowo ifkluczowe jest używane do wykonania instrukcji lub bloku wtedy i tylko wtedy, gdy spełniony jest warunek. Jego składnia jest następująca:

```
if (warunek) instrukcja
```

Jeśli 'warunek' to prawda, instrukcja jest wykonywana. Jeśli jest fałszem, instrukcja nie jest wykonywana (jest po prostu ignorowana), a program kontynuuje działanie zaraz po całej instrukcji wyboru.

Instrukcje wyboru z if mogą również określać, co się stanie, gdy warunek nie zostanie spełniony, używającsłowa kluczowego 'else' do wprowadzenia instrukcji alternatywnej. Jego składnia jest następująca:

```
if (warunek) instrukcja1 else instrukcja2
```

Kilka struktur if + else można połączyć w celu sprawdzenia zakresu wartości. Na przykład:

```
if (x > 0)
  cout << "x is positive";
else if (x < 0)
  cout << "x is negative";
else
  cout << "x is 0";
```

### Instrukcje iteracyjne - pętle

- Pętla while 

Najprostszym rodzajem pętli jest pętla while. Pętla while po prostu się powtarza, dopóki jest prawdziwa. Jeśli po jakimkolwiek wykonaniu, nie jest już prawdą, pętla kończy się, a program kontynuuje zaraz po pętli.

```
  int n = 10;

  while (n>0) {
    cout << n << ", ";
    --n;
  }

  cout << "liftoff!\n";
```

- Pętla do-while

Bardzo podobną pętlą jest pętla do-while. Zachowuje się jak pętla while, z wyjątkiem tego, że jest oceniana po wykonaniu zamiast przed, co gwarantuje co najmniej jedno wykonanie, nawet jeśli nigdy nie zostanie spełnione. Na przykład poniższy przykładowy program odtwarza każdy tekst wprowadzony przez użytkownika, dopóki użytkownik się nie pożegna:

```
string str;
  do {
    cout << "Enter text: ";
    getline (cin,str);
    cout << "You entered: " << str << '\n';
  } while (str != "goodbye");
```

Pętla do-while jest zwykle preferowana w stosunku do pętli while, gdy instrukcja musi zostać wykonana co najmniej raz, na przykład gdy warunek sprawdzany do końca pętli jest określany w samej instrukcji pętli.

- Pętla for

```
for (inicjalizacja; warunek; zwiększenie) statement;
```

Pętla for jest zaprojektowana tak, aby powtarzała się wiele razy. Podobnie jak pętla while, ta pętla powtarza się, dopóki jest prawdziwa. Ale dodatkowo pętla for udostępnia określone lokalizacje zawierające inicjalizacje i zwiększenie, wykonywane odpowiednio przed rozpoczęciem pętli po raz pierwszy i po każdej iteracji. Dlatego szczególnie przydatne jest użycie zmiennych liczników, takich jak warunek.

```
  for (int n=10; n>0; n--) {
    cout << n << ", ";
  }
  cout << "liftoff!\n"
```

Trzy pola w pętli for są opcjonalne. Można je pozostawić puste, ale we wszystkich przypadkach wymagany jest średnik między nimi. Na przykład
```
for (;n<10;)
```
jest pętlą bez inicjalizacji lub zwiększenia (odpowiednik pętli while);
```
for (;n<10;++n)
```
jest pętlą ze wzrostem, ale bez inicjalizacji (być może dlatego, że zmienna została już zainicjowana przed pętlą). Pętla bez warunku jest równoważna pętli z warunkiem true (tzn. pętlą nieskończoną).

- Pętla oparta na zakresie

Pętla for ma inną składnię, która jest używana wyłącznie z zakresami: Ten rodzaj pętli for iteruje po wszystkich elementach w , gdzie deklaruje pewną zmienną, która może przyjąć wartość elementu w tym zakresie. Zakresy to sekwencje elementów, w tym tablice, kontenery i wszelkie inne typy obsługujące funkcje.

```
for ( deklaracja : zakres ) statement;

```

### Instrukcje skoku

- Oświadczenie o przerwaniu

Instrukcja 'break' pozostawia pętlę, nawet jeśli warunek jej zakończenia nie jest spełniony. Można go użyć do zakończenia nieskończonej pętli lub do wymuszenia jej zakończenia przed jej naturalnym końcem.

```
for (int n=10; n>0; n--)
  {
    cout << n << ", ";
    if (n==3)
    {
      cout << "countdown aborted!";
      break;
    }
  }
```

- Instrukcja kontynuuj

Instrukcja 'continue' powoduje, że program pomija resztę pętli w bieżącej iteracji, tak jakby został osiągnięty koniec bloku instrukcji, powodując przeskok na początek następnej iteracji. Na przykład pomińmy numer 5 w naszym odliczaniu:

```
  for (int n=10; n>0; n--) {
    if (n==5) continue;
    cout << n << ", ";
  }
  cout << "liftoff!\n";
```

- Instrukcja goto

Instrukcja 'goto' pozwala na bezwzględny skok do innego punktu w programie. Ten bezwarunkowy skok ignoruje poziomy zagnieżdżenia i nie powoduje automatycznego rozwijania stosu. Dlatego jest to funkcja, której należy używać ostrożnie i najlepiej w ramach tego samego bloku instrukcji, zwłaszcza w obecności zmiennych lokalnych.

Punkt docelowy jest identyfikowany przez etykietę , która jest następnie używana jako argument dla gotoinstrukcji. Etykieta składa się z prawidłowego identyfikatora, po którym następuje dwukropek.

```
  int n=10;
mylabel:
  cout << n << ", ";
  n--;
  if (n>0) goto mylabel;
  cout << "liftoff!\n";
```

### Instrukcje wyboru - switch

Składnia instrukcji switch jest nieco osobliwa. Jego celem jest sprawdzenie wartości spośród wielu możliwych wyrażeń stałych. Jest to coś podobnego do konkatenacji instrukcji if-else, ale ograniczone do wyrażeń stałych. Jego najbardziej typowa składnia to:

```
switch( zmienna )
{
case wartosc_1:
    grupa_instrukcji1;
    break;
   
case wartosc_2:
    grupa_instrukcji2;
    break;
   
case wartosc_n:
    grupa_instrukcjin;
    break;
   
default:
    grupa_instrukcji_default
    break;
}
```
Instruykcja 'switch' ocenia zmienną i sprawdza, czy jest równoważne z wartosc_1; jeśli tak, wykonuje się, grupa_instrukcji1 dopóki nie znajdzie instrukcji break. Po znalezieniu tej instrukcji program przeskakuje na koniec całej instrukcji switch.

Jeśli wyrażenie nie było równe wartosc_1, jest następnie sprawdzane pod kątem wartosc_2. Jeśli jest równy temu, wykonuje grupa_instrukcji2 się do momentu znalezienia break, wtedy przeskakuje na koniec intrukcji switch.

Wreszcie, jeśli wartość wyrażenia nie pasuje do żadnej z wcześniej określonych stałych, program wykonuje instrukcje zawarte po default, jeśli istnieje,ponieważ jest opcjonalna.
