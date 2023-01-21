# 2.7. Wielowątkowość

Język Emojicode obsługuje współbieżność, oznacza to, że możliwe jest wykonywanie wielu instrukcji kodu jednocześnie. 
Do zrównoleglania zadań w Emojicode wykorzystuje się wątki, które mogą niezależnie od siebie wykonywać określone instrukcje kodu w ramach jednego procesu, którym jest blok wykonywalny programu 🏁 🍇🍉.

Wątki w języku Emojicode są reprezentowane przez klasę 🧵.
Aby utworzyć nowy wątek należy go zadeklarować w taki sam sposób jak nowe zmienne, czy obiekty za pomocą inicjalizatora o adnotacji 🆕.

Blok wykonywalnego programu 🏁 🍇🍉 traktowany jest jako wątek główny, dlatego mimo utworzenia nowego wątku za pomocą adnotacji 🆕🧵, nie zostanie on wywołany, dzieje się tak dlatego, że nowo utworzony wątek czeka na zakończenie wątku głównego, który ostatecznie dociera do końca programu.

Aby nowo utworzony wątek został wykonany należy zaczekać na zakończenie innego wątku za pomocą metody 🛂, w chwili zakończenia wątku, 🛂 natychmiast powróci. 

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

W powyższym przykładzie wszystkie wątki są wykonywane na raz, aby temu zapobiec Emojicode wprowadza instancję 🔐 nazywaną muteksem. Muteks służy aby zapewnić kontrolę nad sekcją krytyczną wykonywanego programu, mówiąc ściślej jest to fragment kodu programu, który w danej chwili może być wykonywany tylko przez jeden wątek. Sekcja krytyczna zapewnia właściwość wzajemnego wykluczenia.

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

...

Dokumentacja źródła: Threads