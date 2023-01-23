# Funkcje, procedury

## Funkcje i procedury w Emojicode

Emojicode obsługuje typ o nazwie callables . Obiekty wywoływalne są jak metody (lub bardziej ogólnie funkcje), które można przekazywać jak każdy inny obiekt.
Każdy z typów podanych przed zwracanym typem oznacza jeden argument tego typu. Zwracany typ jest opcjonalny. Jeśli nie określono typu zwracanego, wywołanie nie zwraca wartości. Można określić typ błędu.

```
🍇🔢➡️🔡🍉  💭 Przyjmuje liczbę całkowitą i zwraca łańcuch znaków
🍇➡️🔣🍉  💭 Nie przyjmuje argumentów i zwraca symbol
🍇🍉  💭 Nie przyjmuje argumentów i nic nie zwraca
🍇🔢➡️🔡🚧🚧🍉  💭 Może wznieść 🚧
```

### Wywoływanie typu callables

Pierwsze wyrażenie musi być wywołalne.

```
💭 greet is of type 🍇🔡🍉
⁉️ greet 🔤Bob🔤❗️
```
Podatne na błędy wywoływanie musi być obsługiwane jak każde podatne na błędy wywołanie przy użyciu 🔺, 🍺 lub 🆗.

### Zamknięcie (closure)

Zamknięcia to bloki kodu, które nie są natychmiast wykonywane, ale pamiętają kontekst, w którym zostały utworzone, tj. zmienne i kontekst metody, i które można przekazywać. Typ zamknięcia to oczywiście wywołanie.

Zamknięcie jest tworzone przez blok kodu, który pojawia się, gdy oczekiwane jest wyrażenie. Oznacza to, że każdy blok kodu, który nie jest częścią instrukcji ↪️, 🙅, 🙅↪️ 🔂 lub 🔁, metody lub deklaracji inicjatora, jest zamknięciem.

W przeciwieństwie do normalnego bloku kodu, zamknięcie może definiować argumenty i zwracany typ podobny do metody.

```
🍇 name 🔡
  😀 🔤It is a pleasure to welcome the honorable 🧲name🧲🔤 ❗️
🍉 ➡️ greet

⁉️ greet 🔤Linda🔤❗️
```

### Przechwytywanie zmiennych i kontekstu

```
🐇 🍤 🍇
  🐇❗️💚 g 🍇🔡➡️🔡🍉 🍇
    😀 ⁉️g 🔤DARTH VADER🔤❗️❗️
  🍉
🍉

🏁 🍇
  🔤LUKE🔤 ➡️ 🖍🆕var

  💚🐇🍤 🍇 g🔡 ➡️🔡
    ↩️ var
  🍉❗️
🍉
```

Uruchomienie powyższego kodu spowoduje wydrukowanie pliku LUKE. W powyższym przykładzie wartość zmiennej var została zadeklarowana i przypisana poza zamknięciem. Nazywa się to przechwyconą zmienną. Podobnie, możesz uchwycić kontekst 👇 w zamknięciu.

W rzeczywistości jednak musimy rozróżnić domknięcia uciekające i nieuciekające. Domyślnie każde zamknięcie nie jest znakiem ucieczki i nie może być użyte jako wartość ucieczki. Aby zdefiniować uciekające zamknięcie, po 🍇 musi nastąpić bezpośrednio 🎍🥡

Ucieczkowe domknięcia mogą przechwytywać zmienne, podobnie jak nieucieczkowe domknięcia. Jednak w uciekających domknięciach przechwycone zmienne są stałe. W domknięciach nieuciekających przechwycone zmienne można modyfikować

```
🏁 🍇
  🔤LUKE🔤 ➡️ 🖍🆕var

  😀 var❗️

  💚🐇🍤 🍇 g🔡 ➡️🔡
    g ➡️ 🖍var
    ↩️ 🔤DEATH STAR🔤
  🍉❗️

  😀 var❗️
🍉
```

Zmienna var została zmodyfikowana wewnątrz zamknięcia i jest ustawiona na wartość g przekazaną do zamknięcia, którą w naszym przypadku było „DARTH VADER”. Nie zadziała to z uciekającym zamknięciem.

## Funkcje i procedury w C++

Funkcja to zestaw instrukcji, które pobierają dane wejściowe, wykonują określone obliczenia i generują dane wyjściowe. Chodzi o to, aby połączyć niektóre często lub wielokrotnie wykonywane zadania i utworzyć funkcję , dzięki czemu zamiast ciągle pisać ten sam kod dla różnych danych wejściowych, możemy wywołać funkcję.
Mówiąc prościej, funkcja to blok kodu, który działa tylko wtedy, gdy jest wywoływany.

### Deklaracja funkcji

Deklaracja funkcji informuje kompilator o liczbie parametrów, które funkcja przyjmuje typy danych parametrów i zwraca typ funkcji. Umieszczenie nazw parametrów w deklaracji funkcji jest opcjonalne w deklaracji funkcji, ale konieczne jest umieszczenie ich w definicji.

```
int max(int, int);
int* swap(int*, int);
char* call(char b);
int fun(char, int);
```

### Rodzaje funkcji 

- funkcja definiowana przez użytkownika 

Funkcje zdefiniowane przez użytkownika to zdefiniowane przez użytkownika/klienta bloki kodu specjalnie dostosowane w celu zmniejszenia złożoności dużych programów. Są one również powszechnie znane jako „ funkcje szyte na miarę”, które są budowane tylko w celu zaspokojenia warunków, w których użytkownik napotyka problemy, jednocześnie zmniejszając złożoność całego programu.

- funkcja biblioteki

Funkcje biblioteczne są również nazywane „funkcjami wbudowanymi ”. Funkcje te są częścią pakietu kompilatora, który jest już zdefiniowany i składa się ze specjalnej funkcji o specjalnym i innym znaczeniu. Wbudowane funkcje dają nam przewagę, ponieważ możemy ich bezpośrednio używać bez ich definiowania, podczas gdy w funkcji zdefiniowanej przez użytkownika musimy zadeklarować i zdefiniować funkcję przed ich użyciem. 

Na przykład: sqrt(), setw(), strcat() itp.

### Przekazywanie parametrów do funkcji

Parametry przekazywane do funkcji nazywane są parametrami rzeczywistymi . Na przykład 5 i 10 to rzeczywiste parametry. 
Parametry otrzymane przez funkcję nazywane są parametrami formalnymi . Na przykład x i y są parametrami formalnymi. 

Istnieją dwa najpopularniejsze sposoby przekazywania parametrów:

- Przekaż wartość - w tej metodzie przekazywania parametrów wartości rzeczywistych parametrów są kopiowane do formalnych parametrów funkcji, a dwa typy parametrów są przechowywane w różnych lokalizacjach pamięci. Tak więc wszelkie zmiany dokonane wewnątrz funkcji nie są odzwierciedlane w rzeczywistych parametrach wywołującego. 
 
- Przekaż przez referencję - zarówno parametry rzeczywiste, jak i formalne odnoszą się do tych samych lokalizacji, więc wszelkie zmiany dokonane wewnątrz funkcji są faktycznie odzwierciedlane w rzeczywistych parametrach wywołującego.

### Funkcje wykorzystujące wskaźniki

Funkcja fun() oczekuje wskaźnika ptr na liczbę całkowitą (lub adres liczby całkowitej). Modyfikuje wartość pod adresem ptr. Operator dereferencji * służy do uzyskiwania dostępu do wartości pod adresem. W instrukcji '*ptr = 30' wartość pod adresem ptr jest zmieniana na 30. Operator adresowy & służy do uzyskania adresu zmiennej dowolnego typu danych. W instrukcji wywołania funkcji „fun(&x)” przekazywany jest adres x, dzięki czemu x może być modyfikowany przy użyciu jego adresu. 

```
void fun(int* ptr) { *ptr = 30; }
 
int main()
{
    int x = 20;
    fun(&x);
    cout << "x = " << x;
 
    return 0;
}
```

### Główna funkcja 

Funkcja główna jest funkcją specjalną. Każdy program C++ musi zawierać funkcję o nazwie main. Służy jako punkt wejścia do programu. Komputer rozpocznie wykonywanie kodu od początku głównej funkcji. 

Rodzaje funkcji głównych:
- bez parametrów

```
int main() { ... return 0; }
```

- z parametrami

```
int main(int argc, char* const argv[]) { ... return 0; }
```

Powodem posiadania opcji parametru dla funkcji main jest umożliwienie wprowadzania danych z wiersza poleceń. Kiedy używasz funkcji main z parametrami, zapisuje ona każdą grupę znaków (oddzielonych spacją) po nazwie programu jako elementy w tablicy o nazwie argv . 
Ponieważ główna funkcja ma typ zwracany int , programista musi zawsze mieć w kodzie instrukcję return. Zwrócona liczba służy do poinformowania programu wywołującego, jaki był wynik wykonania programu. Zwrócenie 0 oznacza, że ​​nie było żadnych problemów.


### Rekurecja w C++

Gdy funkcja jest wywoływana w ramach tej samej funkcji, w C++ nazywa się to rekurencją. Funkcja, która wywołuje tę samą funkcję, jest znana jako funkcja rekurencyjna.
Funkcja, która wywołuje samą siebie i nie wykonuje żadnego zadania po wywołaniu funkcji, nazywana jest rekurencją ogonową. W rekurencji ogona generalnie wywołujemy tę samą funkcję za pomocą instrukcji return.

```
recursionfunction()
{
    recursionfunction(); // calling self function
}
```

### Przeciążanie funkcji w C++

Przeciążanie funkcji jest definiowane jako proces posiadania dwóch lub więcej funkcji o tej samej nazwie, ale różniących się parametrami, co jest znane jako przeciążanie funkcji w C++. W przypadku przeciążania funkcji funkcja jest ponownie definiowana przy użyciu różnych typów argumentów lub innej liczby argumentów. Tylko dzięki tym różnicom kompilator może rozróżnić funkcje.
Zaletą przeciążania funkcji jest to, że zwiększa to czytelność programu, ponieważ nie trzeba używać różnych nazw dla tej samej akcji.

```
class Cal {
public:
    static int add(int a, int b) { return a + b; }
    static int add(int a, int b, int c)
    {
        return a + b + c;
    }
};
int main(void)
{
    Cal C; // class object declaration.
    cout << C.add(10, 20) << endl;
    cout << C.add(12, 20, 23);
    return 0;
}
```
