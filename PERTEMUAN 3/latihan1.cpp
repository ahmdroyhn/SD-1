#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// Menambahkan karakter ke stack
void push(char value) {
    if (top >= MAX - 1) {
        cout << "Stack penuh!" << endl;
        return;
    }
    top++;
    stack[top] = value;
}

// Mengambil karakter paling atas
char pop() {
    if (top == -1) {
        cout << "Stack kosong!" << endl;
        return '\0';
    }
    char value = stack[top];
    top--;
    return value;
}

int main() {

    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // Memasukkan setiap karakter ke stack
    for (int i = 0; i < kata.length(); i++) {
        push(kata[i]);
    }

    // Mengeluarkan karakter dari stack
    cout << "Kata terbalik: ";
    while (top != -1) {
        cout << pop();
    }
    
    cout << endl;

    return 0;
}