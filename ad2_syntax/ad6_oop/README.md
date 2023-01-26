# Programowanie obiektowe
Programowanie obiektowe jest jednym z najważniejszych, a także najczęściej wykorzystywanych paradygamtów programowania. Z tego też powodu nie mogło go również zabraknąć w Emojicode. W języku tym obiektowość przejawia się w trzech głównych elementach: 
- klasach (Classes),
- typach wartościowych (Value types),
- wyliczeniach (Enumerations).

Rozdział ten skupiał się będzie na dwóch pierwszych elementach, zaś wyliczenia zostaną przybliżone w kolejnym.

Klasy są znane każdemu, kto miał styczność z programowaniem obiektowym, natomiast typy wartościowe nie są aż tak szeroko rozpowszechnione. Czym właściwie one są i jakie są różnice między nimi oraz klasami?

Dwie podstawowe różnice między klasami oraz typami wartościowymi to:
1. instancje klas są zawsze alokowane na stosie i przekazywane są przez referencję, natomiast instancje typów wartościowych są przekazywane - zgodnie z ich nazwą - poprzez wartość.
2. klasy umożliwiają dziedziczenie, podczas gdy typy wartościowe nie pozwalają na korzystanie z tego mechanizmu.

Oznacza to, że typy wartościowe są przydatne w sytuacjach, gdy ważna jest dla nas rzeczywista wartość przechowywanych danych, a nie ich identyfikacja jako obiekt danej klasy. Innymi słowy w przypadku typów wartościowych skupiamy się na danej konkretnej wartości, a nie na pewnej instancji danego obiektu.

Aby to sobie lepiej zobrazować wyobraźmy sobie, że przechowujemy dane dotyczące daty zakupu oraz klienta. Data zakupu, niezależnie od kontekstu, będzie zawsze tym samym. Interesuje nas po prostu na jaki dzień, miesiąc i rok wskazuje, czyli dokładnie mówiąc jej wartość - i nic poza tym. W przypadku danych klienta zależy nam, żeby wiedzieć z jakim konkretnie klientem mamy do czynienia. Może być wielu klientów nazwanych "Jan Kowalski", ale każdy z nich to inna osoba i przez to jest reprezentowany przez inny obiekt.
W tym przykładzie data zakupu byłaby reprezentowana przez typ wartościowy, natomiast klient przez klasę.

W C++ obiekty danej klasy domyślnie traktowane są w pewien sposób jako połączenie klas i typów wartościowych z Emocjicode. Tworząc nowy obiekt będący instancją danej klasy zyskujemy domyślnie dostęp jedynie do wartości tego obiektu i jest on alokowany na stosie. Chcąc uzyskać referencję do konkretnego obiektu (miejsca pamięci, w którym obiekt jest przechowywany) musimy wykorzystać mechanizmy wskaźników lub refencji. Przykładowo, jeżeli zdefiniowalibyśmy klasę MojaKlasa, to dostęp do jej instancji wyglądałby następująco:

```cpp
  MojaKlasa  a;      // typ wartościowy (przechouje jedynie wartość)
  MojaKlasa  b;      // typ wartościowy (przechouje jedynie wartość)
  MojaKlasa &c =  a; // typ referncyjny (referencja w C++), przypisana do obiektu a
  MojaKlasa *d = &b; // typ referncyjny (wksaźnik w C++)

  a = b; // skopiuj wartość b do a
  c = b; // skopiuj wartośc b do c
  d = &a; // ustaw d aby wskazywał na obiekt a (referncja do instancji; konkretnego miejsca w pamięci)
  *d = b; // skopiuj wartośc b do a (d wskazuje na a)
```
Sprawa wygląda jeszcze inaczej, gdy do utworzenia instancji zostanie wykorzystany operator `new`, jednak więcej na ten temat zostanie wspomniane w dalszej części tego rozdziału. 
## Definiowanie klas
Aby zdefiniować klasę korzystamy z operatora "🐇". Przykładowa klasa Klient (👩‍💼) wygląda następująco:
```
🐇 👩‍💼 🍇

🍉
```
Jak już zostało wspomniane, klasy mogą dziedziczyć po innych. Aby zdefiniować klasę nadrzędną podajemy jej nazwę (symbol) po nazwie (symbolu) definiowanej klasy. Przykładowo, jeżeli chcilibyśmy stworzyć klasę Astronauta (👩‍🚀) dziedziczącą po klasie klient, napisalibyśmy to w ten sposób:
```
🐇 👩‍🚀 👩‍💼 🍇

🍉
```

Można zauważyć, że mechanizm definiowania klas w Emojicode nie różn i się specjalnie względem tego dostępnego w C++. Tak, jak w Emojicode mamy specjalne oznaczenie "🐇", tak w C++ dostępne mamy słowo kluczowe class. Różnice występują w przypadku dziedziczenia, gdyż w C++ musimy dodatkowo użyć operatora `:` oraz wskazać specyfikator dostępu odziedziczonych pól, przykładowo:

```cpp
class Klient {}
class Astronauta : public Klient {}
```

### Pola klas
Jak wiemy, klasa sama w sobie nie jest nam zbyt przydatna. To co czyni ją przydatną, to pola i metody dla niej zdefiniowane. W przypadku pól inicjalizacji dokonujemy z wykorzystaniem operatora "🖍" w połączeniu z operatorem "🆕". Dokładna składnia definicji pola to:
```
🖍🆕 nazwa_pola <typ_pola>
```
Przykładowo chcąc do naszej klasy Astronauta dodać pole liczbowe dni_w_kosmosie możemy to zrobić następująco:
```
🐇 👩‍🚀 👩‍💼 🍇
  🖍🆕 dni_w_kosmosie 🔢
🍉
```
Pola klas nie ograniczają się oczywiście do wyłącznie typów prostych. Mogą one również np. być typem wartościowym. Dodatkowo należy zapamiętać, że domyśnie pola klas są prywatne, czyli dostępne są wyłącznie wewnątrz danej klasy i nie można z nich skorzystać nawet w klasach pochodnych. Więcej o dostępności pól i metod zostanie wspomniane w dalszej części tego rozdziału.

Pola mogą mieć także wartość domyśną, którą definiujemy z użyciem operatora "⬅️".
```
🐇 👩‍💼 🍇
  🖍🆕 imie 🔡 ⬅️ 🔤Jan🔤
  🖍🆕 naziwsko 🔡 ⬅️ 🔤Kowalski🔤
🍉
```

Porównując definiowanie pól z tym dostępnym w C++ pierwsza rzecz, na którą możemy zwrócić uwagę jest fakt, że w C++ nie musimy konkretnie precyzować, że pola te mogą być modyfikowane (poprzez operator "🖍" w Emojicode) oraz nie potrzebujemy wykorzystywać dodatkowego operatora "🆕". Tak samo natomiast jest z dostępnością pól - pola domyślnie traktowane są jako prywatne i dostępne są tylko i wyłącznie w ramach danej klasy. Przepisując powyższy przykład na język C++ otrzymamy:

```cpp
class Klient {
  string imię = "Jan";
  string nazwisko = "Kowalski";
}
class Astronauta : public Klient {
  int dni_w_kosmosie;
}
```

### Konstruktor
Konstruktor to specjalna metoda, wywoływana podczas tworzenia jej instancji. Podstawowym zadaniem konstruktora jest zainicjowanie obiektu.
Do utworzenia konstruktora w Emojicode korzysta się z operatora "🆕". Należy pamiętać, że konstruktor musi inicjalizować wszystkie nieopcjonalne pola klasy.
```
🐇 👩‍💼 🍇
  🖍🆕 imie 🔡
  🖍🆕 naziwsko 🔡

  🆕 p_imie 🔡 p_naziwsko 🔡 🍇
    p_imie ➡️🖍imie
    p_naziwsko ➡️🖍naziwsko
  🍉
🍉
```

Ponieważ taka inicjalizacja każdej zmiennej jest żmudna, w Emojicode mamy dostęp do operatora "🍼", który pozwala na znaczne uproszczenie tej operacji:
```
🐇 👩‍💼 🍇
  🖍🆕 imie 🔡
  🖍🆕 naziwsko 🔡

  🆕 🍼 imie 🔡 🍼 nazwisko 🔡 🍇🍉
🍉
```

Definiując konstruktor klasy, która dziedziczy po innej, musimy pamiętać, aby wywołać także konstruktor klasy nadrzędnej poprzez operator "⤴️".

Mając zdefiniowaną klasę, możemy utworzyć jej instnację. Robimy to z użyciem operatora "🆕", podając wszystkie argumenty konstruktora oraz kończąc wprowadzenie argumentów poprzez symbol "❗️".
```
🆕👩‍💼 🔤Jan🔤 🔤Kowalski🔤❗️ ➡️ klient_kowalski
```
W C++ konstruktor wymaga, aby jego nazwa była identyczna jak nazwa klasy, musi on być publiczny oraz nie może zwracać żadnej wartości. Nie mamy też dostępu do uproszczenia składni, dlatego musimy ręcznie przypisać wartości dla każdego z nieopcjonalnych pól. Należy także pamiętać, że musimy konkretnie wskazać, iż konstuktor jest publiczny, gdyże w przeciwieństwie do Emojicode, wszystkie elementy klasy są traktowane jako prywatne, a nie tylko jej pola.

```cpp
class Klient {
  string imię;
  string nazwisko;
  public:
    Klient(string p_imie, string p_naziwsko){
      imie = p_imie;
      naziwsko - p_naziwsko;
    }
}
```
Odnośnie inicjalizacji obiektów danej klasy było już wspomniane na samym początku tego rozdziału i wiemy już, że mamy na to różne sposoby, pozwalające na uzyskanie różnego sposobu dostępu do obiektu. Chcąc jednak uzyskać efekt identyczny, do Emojicode możemy zrobić to bez użycia operatora `new` w następujący sposób:

```cpp
Klient klient_jan("Jan", "Kowalski");
``` 

### Metody
Klasy i typy wartościowe, podobnie jak w przypadku innych języków programowania, mogą posiadać metody. Metody deklarujemy w następujący sposób:
```
❗️ 💸 wartosc 💯 🍇
  😀 🔤Faktura🔤❗️
  😀 🔤Dla: 🧲imie🧲 🧲nazwisko🧲🔤 ❗️
  😀 🔤Wartość: 🧲🔡wartosc 2❗️🧲🔤❗️
  😀 🔤Środki zostaną pobrane z Twojego konta. 🔤❗️
🍉
```
Metody mogą również zwracać wartość, z użyciem operatora "↩️". 
```
❗️ 🔖 ➡️ 🔡 🍇
  ↩️ tresc
🍉
```
Operator ten może zostać także użyty, aby w dowolnym momencie wrócić z wykonywanej metody bez zwracania wartości. W przykładzie poniżej tekst "Mnie nie widać" nigdy nie zostanie wyświetlony.
```
❗️ 🛎 🍇
  ↩️↩️
  😀 🔤Mnie nie widać!🔤❗️
🍉
```
Przyjrzyjmy się teraz definiowaniu metod w C++. Mechanizm ten wygląda bardzo podobnie, ponieważ również musimy nadać metodzie nazwę, zwracany typ oraz listę argumentów wraz z ich typami. Symbol "↩️" występuje tutaj pod postacią słowa kluczowego `return`. Różnicą, o której musimy pamiętać jest natomiast fakt, iż metoda zawsze musi wskazywać zwracaną wartość, a jeżeli takiej nie ma, to należy oznaczyć ją poprzez słowo kluczowe `void`. Tak więc powyższe przykłady wyglądałyby w C++ następująco:

```cpp
void rachunek(int wartosc){
  cout << "Faktura\n";
  cout << "Dla: " << imie <<"  " << nazwisko << "\n";
  cout << "Wartość: " << wartosc << "\n";
  cout << "Środki zostaną pobrane z Twojego konta.\n";
}

string zakladka(){
  return tresc;
}

void dzwonek(){
  return;
  cout << "Mnie nie widać!";
}
```

### Nastroje metod (Moods)
W Emojicode przedstawiony został koncept nastrojów metod, którego nie znajdziemy w C++. Metoda może być w nastroju imperatywnym lub irrogatywnym. Metody imperatywne, to metody, które pozwalają na mutację (zmianę) wartości pól danej klasy. Metody interrogatywne (pytające) nie modyfikują obiektu klasy, a jedynie służą do zwracania pewnej wartości dotyczącej danego obiektu. Metody imperatywne oznaczane są symbolem "❗️", zaś metody interrogatywne symbolem "❓". W ramach danej klasy mogą może istnieć zarówno metoda impeartywna, jak i interrogatywna o tej samej nazwie.
Przykład:
1. metoda interrogatywna - zwraca wartość typu logicznego (prawda/fałsz) mówiącą o tym, czy astronauta spędził przynajmniej jeden dzień w kosmosie
```
❓ 🚀 ➡️ 👌 🍇
  ↩️ dni_w_kosmosie ▶️ 0
🍉
```
2. metoda imperatywna - przypisuje podaną wartość do pola dni_w_kosmosie
```
❗️ 🚀 dni_w_kosmosie_parametr 🔢 🍇
  dni_w_kosmosie_parametr ➡️ dni_w_kosmosie
🍉
```

Tak jak już wspomniano, mechanizm ten nie występuje w C++, gdyż zmian w polach klasy można dokonywać wewnątrz jej metod bez potrzeby dodatkowych działań. Powyższe metody w języku C++ wyglądałyby następująco:

```cpp
class Astronauta : public Klient{
  int dni_w_kosmosie;

  public: 
    bool rakieta(){
      return dni_w_kosmosie > 0;
    }
    void rakieta(int dni_w_kosmosie_parametr){
      dni_w_kosmosie = dni_w_kosmosie_parametr;
    }
}
```
### Wywoływanie metod
Wywoływanie metod jest bardzo proste. Podajemy najpierw nazwę (symbol) metody, następnie instancję klasy, na której metoda ma zostać wykonana oraz wymagane argumenty. Wprowadzanie argumentów kończone jest odpowiednim oznaczeniem nastroju wywoływanej metody. 
Przykład:
```
🚀 astronauta_maciek❓ 💭 Czy Maciek był kiedykolwiek w kosmosie?
🚀 astronauta_maciek 6390❗️ 💭 Zmień liczbę dni spędzonych w kosmosie przez Maćka na 6390
```
W C++ wygląda to następująco:

```cpp
Astronauta astronauta_maciek;
astronauta_maciek.rakieta();
astronauta_maciek.rakieta(6390);
```

### Słowo kluczowe `this`
Dobrze znane słowo kluczowe this z innych języków programowania, pozwalające na dostęp do kontekstu instancji klasy, dla której wywołana została metoda ma również reprezentację w Emojicode. Kontekst ten oznaczony jest symbolem "👇"
Przykładowo jeżeli chcielibyśmy napisać metodę, która pozwala na pobranie opłaty od astronauty (z użyciem wcześniej zdefiniowanej metody 💸), jeżeli był on chociaż jeden dzień w kosmosie możemy wykonać to w następujący sposób:
```
❗️ 🛸 🍇
  ↪️ 🚀 👇❓ 🍇
    💸👇 100❗️
  🍉
🍉
```
Dodatkowo, jeżeli wywoływana metoda nie przyjmuje żadnych argumentów, symbol 👇 można pominąć z jej wywołania.

W C++ nie ma obowiązku stosowania wskaźnika this, nawet jeżeli metoda przyjmuje parametry. Powyższa metoda wyglądałąby następująco:

```cpp
void ufo(){
  if(rakieta()){
    rachunek(100);
  }
}
```
## Metody statyczne (Type Methods)
W Emojicode możliwe jest także utworzenie metod statycznych, które wykonywane są na typie klasy bądź typu wartościowego, a nie na instancji. Metody te są dziedziczone przez podklasy i zachowują się tak samo jak zwykłe metody. Do zdefiniowania takiej metody używamy tego samego oznaczenia, które wykorzystywane jest w przypadku klas "🐇".
Przykładowa klasa z metodą statyczną wygląda następująco:
```
🐇 🍕 🍇
  📗 Zwróć dostępne rodzaje pizzy. 📗
  🐇❗️ 📜 ➡️ 🍨🐚🔡🍆 🍇
    ↩️ 🍿 🔤Margherita🔤 🔤Tonno🔤 🔤Quattro Formaggi🔤 🍆
  🍉
🍉

📜🐇🍕❗️
```

Statyczne metody w C++ działają w ten sam sposób. Mogą one uzyskiwać dostęp tylko do statycznych składowych danej klay, innych statycznych metod składowych i wszelkich innych funkcji spoza klasy oraz nie mają dostępu do wskaźnika this. Do wywowałania metody statycznej używamy nazwy klasy oraz operatora `::`. Przykład powyższej klasy z metodą statyczną oraz jej wywołania przedstawiony został poniżej:

```cpp
class Pizza{
  /* Zwróć dostępne rodzaje pizzy. */
  static string* lista(){
    string* rodzaje_pizzy = new string[3]{ "Margherita", "Tonno", "Quattro Formaggi" };
    return rodzaje_pizzy;
  }
}
```
### Rodzaje metod
Tak samo jak i w innych językach, metody klas w emojicode mogą mieć różną dostępność. Emojicode pozwala na definiowanie metod według klasycznego schematu ich dostępności, wedle którego metody i konstruktory klas mogą być:
- 🔓 - publiczne (metoda/konstruktor dostępna jest wszędzie)
- 🔒 - prywatne (metoda/konstruktor dostępna jest tylko wewnątrz pakietu/klasy, w której została zdefiniowana)
- 🔐 - chronione (metoda/konstruktor dostępne są w klasie/pakiecie, w której została zdefiniowana oraz w klasach pochodnych)

Identycznie można definiować dostępność w języku C++ za pomocą słów kluczowych public, private i protected. Nie są one jednak dostępne dla konstruktorów klas, które muszą być publiczne. Dodatkowo, tych specyfikatorów dostępu używa się w formie bloków, które pozwalają uniknąć powtarzania pisania ich przy nazwie każdej metody i pola. Należy także pamiętać, że w C++ wszystkie elementy składowe klasy są domyślnie prywatne, dlatego należy konkretnie wskazać, które metody mają być dostępne publicznie.

Największa różnica jeżeli chodzi o specyfikatory dostępu pojawia się w przypadku dziedziczenia połączonego z nadpisywaniem metod.
W C++ dziedzicząc po klasie mamy możliwość zdefiniowania za pomocą specyfikatorów dostępu, jak traktowane będą odziedziczone elementy klasy nadrzędnej. W przypadku Emojicode odziedziczone metody domyślnie posiadają taką samą dostępność jak te z klasy nadrzędnej, ale można to również nadpisać poprzez nadpisywanie samej metody. Należy jednak pamiętać, że metoda nadpisywana musi mieć dostępność co najmniej identyczną, jak w klasie nadrzędnej, co oznacza, że nadpisana metoda nie może stać się prywatna (🔒), a metoda oznaczona jako publiczna (🔓) nie może zostać zmieniona na chornioną (🔐) 

## Definiowanie typu wartościowego
Typ wartościowy definiujemy bardzo podobnie do klasy, z tym że wykorzystujemy operator "🕊". Tak więc chcąc zdefiniować typ wartościowy DaneKartyPlatniczej (💳) możemy napisać:
```
🕊 💳 🍇

🍉
```
Typy wartościowe możemy wykorzystywać wewnątrz klas do zdefiniowania ich pól, przykładowo rozwijając wcześniej rozważaną klasę Klient (👩‍💼) możemy ją rozwinąc o informację o karcie kredytowej poprzez:
```
🐇 👩‍💼 🍇
  🖍🆕 imie 🔡 ⬅️ 🔤Jan🔤
  🖍🆕 naziwsko 🔡 ⬅️ 🔤Kowalski🔤
  🖍🆕 karta_kredytowa 💳 ⬅️ 🆕💳 🔤48829284848291🔤 🔤12/22🔤 🔤513🔤❗️
🍉
```

Typy wartościowe zapewniają identyczne funkcjonalności jak klasy, jednak należy zwrócic uwagę na jedną szczególną różnicę - instancje typów wartościowych nie mogą być dowolnie modyfikowane. Metody mające mieć dostęp do operacji modyfikacji pól typów wartościowych muszą być oznaczone symbolem "🖍". Przykładowo metoda pozwalająca na zaktualizowanie informacji o kodzie bezpieczeństwa karty płatniczej wyglądałaby następująco:
```
🖍❗️🗝 code 🔡 🍇
  code ➡️🖍security_code
🍉
```
Należy także pamiętać, że tego typu metod nie można wywoływać w metodach nie będących oznaczonymi symbolem "🖍" jako mutujące.

Dodatkowo mutacja zmiennej będącej danego typu wartościowego może zajść, gdy zmienna ta sama jest wskazana jako mutująca, np. poniższy przykład jest poprawny:
```
🆕💳 🔤48829284848291🔤 🔤12/22🔤 🔤513🔤❗️ ➡️ 🖍🆕credit_card
🗝credit_card 🔤126🔤❗️
```
Jednakże poniższy jest błedny - zmienna nie została oznaczona poprzez "🖍".
```
🆕💳 🔤48829284848291🔤 🔤12/22🔤 🔤513🔤❗️ ➡️ credit_card
🗝credit_card 🔤789🔤❗️
```

## Podsumowanie
Jak widać programowanie obiektowe w Emojicode jest bardzo zbliżone do programowania w C++, jednak ma pewne cechy, których nie znajdziemy w języku z rodziny C. Nastroje metod są jednym z konceptów, który jest zupełnie obcy dla języka C++ oraz ma on zupełnie inne podejście do możliowści mutacji instancji klas. W C++ granice między typami wartościowymi i klasami są zatarte i występowanie cech tych struktur przejawia się w różnym sposobie inicjalizacji obiektów danej klasy. Gdy obiekt utworzymy po prostu podając nazwę klasy otrzymamy twór zbliżony do klas w Emojicode, który zostanie zapisany na stosie i dostępny będzie w postaci tylko jego wartości. Tworząc obiekt z użyciem operatora new lub wykorzystując wskaźniki/refernecje otrzymujemy dostęp do konkretego miejsca w pamięci, gdzie dana instancja została zapisana, przez co mamy prawdziwy dostęp do konkretnej instancji danej klasy. 

Najważniejsze różnice pomiędzy Emojicode i C++ w kwestii programowania obiektowego zostały zebrane poniżej:
- w C++ wszystkie elementy składowe klas są domyślnie prywatne, a nie tylko metody, tak jak w przypadku Emojicode,
- w przypadku dziedziczenia w C++ musimy wskazać, jak traktowane będą odziedziczone pola i metody z klasy nadrzędnej. Używamy do tego typowych specyfikatorów dostępu public, private i protected. W Emojicode dziedziczone pola i metody dziedziczą również dostępność, która można nadpisać, jednak tylko w stronę bardziej łagodnej,
- w C++ pola klasy można modyfikować bez potrzeby specjalnego oznaczania ich, jako mutujące, tak jak w przypadku Emojicode,
- w C++ nie ma mechanizmu nastrojów metod, jednak nadpisywanie metod jest w pełni możliwe.