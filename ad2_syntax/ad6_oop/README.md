# Programowanie obiektowe
Programowanie obkietowe jest jednym z najważniejszych, a także najczęściej wykorzystywanych paradygamtów programowania. Z tego też powodu nie mogło go również zabraknąć w Emojicode. W języku tym obiektowoć przejawia się w trzech głównych elementach: 
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

### Pola klas
Jak wiemy, klasa sama w sobie nie jest nam zbyt przydatna. To co czyni ją przydatną, to pola i metody dla niej zdefiniowane. W przypadku pól inicjalizację dokonujemy z wykorzystaniem operatora "🖍" w połączeniu z operatorem "🆕". Dokładna składnia definicji pola to:
```
🖍🆕 nazwa_pola <typ_pola>
```
Przykładowo chcąc do naszej klasy Astronauta dodać pole liczbowe dni_w_kosmosie możemy to zrobić następująco:
```
🐇 👩‍🚀 👩‍💼 🍇
  🖍🆕 dni_w_kosmosie 🔢
🍉
```
Pola klas nie ograniczają się oczywiście do wyłącznie typów prostych. Mogą one również np. być typem wartościowym. Dodatkowo należy zapamiętać, że domyśnie pola klas są prywatne, czyli dostępne są wyłącznie wewnątrz instancji danej klasy i nie można z nich skorzystać nawet w klasach pochodnych. Więcej o dostępności pól i metod zostanie wspomniane w dlaszej części tego rozdziału.

Pola mogą mieć także wartość domyśną, którą definiujemy z użyciem operatora "⬅️".
```
🐇 👩‍💼 🍇
  🖍🆕 imie 🔡 ⬅️ 🔤Jan🔤
  🖍🆕 naziwsko 🔡 ⬅️ 🔤Kowalski🔤
🍉
```
### Konstruktor
Konstruktor to specjalna metoda, wywoływana podczas tworzenia jej instancji. Podstawowym zadaniem konstruktora jest zainicjowanie obiektu.
Do utworzenia konstruktora w Emojicode korzysta się z operatora "🆕". Należy pamiętać, że konstruktor musi inicjalizować wszystkie pola nieopcjonalne pola klasy.
```
🕊 💳 🍇
  🖍🆕 number 🔡
  🖍🆕 expiration_date 🔡
  🖍🆕 security_code 🔡

  🆕 a_number 🔡 an_expiration_date 🔡 a_security_code 🔡 🍇
    a_number ➡️🖍number
    an_expiration_date ➡️🖍expiration_date
    a_security_code ➡️🖍security_code
  🍉
🍉
```

Ponieważ taka inicjalizacja każdej zmiennej jest żmudna, w Emojicode mamy dostęp do operatora "🍼", który pozwala na znaczne uproszczenie tej operacji:
```
🐇 👩‍💼 🍇
  🖍🆕 firstname 🔡
  🖍🆕 lastname 🔡

  🆕 🍼 firstname 🔡 🍼 lastname 🔡 🍇🍉
🍉
```

Definiując konstruktor klasy, która dziedziczy po innej, musimy pamiętać, aby wywołać także konstruktor klasy nadrzędnej poprzez operator "⤴️".

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