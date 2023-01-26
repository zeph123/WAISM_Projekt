#include<iostream>

using namespace std;

// Fibonacci (iteracyjnie)
int fib_iteratively(int n) {
    int a = 0, b = 1, c;
    if( n == 0) {
        return a;
    }

    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

// Fibonacci (rekurencyjnie) 
int fib_recursively(int n) {

    if (n <= 1) {
        return n;
    }

    return fib_recursively(n - 1) + fib_recursively(n - 2);
}

int main ()
{
    int n = 10;

    cout << "Fibonacci (iteracyjnie)" << endl;
    for (int i = 0; i <= n ; i++) {
        cout << "Fib (" << i << ") = " << fib_iteratively(i) << endl;
    }

    cout << "Fibonacci (rekurencyjnie)" << endl;
    for (int i = 0; i <= n ; i++) {
        cout << "Fib (" << i << ") = " << fib_recursively(i) << endl;
    }

    return 0;
}