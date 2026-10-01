#include <iostream>
#include <string>
using namespace std;

// Struktur Node Mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    float persentaseKehadiran;
    Mahasiswa* next;
};

// Head global untuk linked list
Mahasiswa* head = nullptr;

int main() {
    cout << "Program Single Linked List - Kehadiran Mahasiswa\n";
    cout << "Struktur node (struct Mahasiswa) berhasil didefinisikan.\n";
    cout << "Field: nim, nama, persentaseKehadiran, next\n";
    return 0;
}
