#include <iostream>
using namespace std;

#define MAX 5 // berarti slotnya maksimal 5, berarti nanti slotnya ada 4
int stack[MAX]; 
int top = -1; // inisialisasi stack kosong

// TODO : Operasi Push
void push (int value) {
    if(top == MAX - 1){
        cout << "Stack Penuh! \n"; 
    } else {
        top++;
        stack[top] = value;
        cout << value << " ditambahkan ke dalam stack\n";
    }
}

// TODO : Operasi Pop
void pop (){
    if(top == -1){
        cout << "Stack Kosong! \n";
    } else {
        cout << "\n" << stack[top] << " dihapus dari stack\n";
        top--; 
    }
}

// TODO : Nampilin Stack
void display() {
    if(top == -1){
        cout << "Stack Kosong! \n";
    } else {
        cout << "\nIsi dari stack:\n";
        for(int i = top; i >= 0; i--){
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main (){
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    display();
    pop();
    display;

    return 0;
}