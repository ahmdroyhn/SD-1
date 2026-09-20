#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void printList() {
    Node *temp = head;

    cout << "Isi Linked List: ";

    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

void insertFirst(int value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;

    head = newNode;

    if (tail == NULL) {
        tail = newNode;
    }
}

void insertLast(int value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter(int target, int value) {
    Node *temp = head;

    while (temp != NULL && temp->value != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Nilai " << target << " tidak ditemukan!\n";
        return;
    }

    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = temp->next;

    temp->next = newNode;

    if (temp == tail) {
        tail = newNode;
    }
}

void deleteValue(int value) {
    if (head == NULL) {
        cout << "List Kosong!\n";
        return;
    }

    if (head->value == value) {
        Node *temp = head;
        head = head->next;

        if (head == NULL) {
            tail = NULL;
        }

        delete temp;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL && temp->next->value != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Nilai " << value << " tidak ditemukan!\n";
        return;
    }

    Node *hapus = temp->next;
    temp->next = hapus->next;

    if (hapus == tail) {
        tail = temp;
    }

    delete hapus;
}

int main() {
    int pilihan;
    int nilai;
    int nilaiBaru;

    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;

                insertFirst(nilai);
                printList();
                break;

            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;

                insertLast(nilai);
                printList();
                break;

            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilaiBaru;

                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilai;

                insertAfter(nilai, nilaiBaru);
                printList();
                break;

            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;

                deleteValue(nilai);
                printList();
                break;

            case 5:
                printList();
                break;

            case 0:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}