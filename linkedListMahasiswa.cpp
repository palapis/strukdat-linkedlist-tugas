#include <iostream>
#include <string>
#include <iomanip>
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

// Deklarasi fungsi
void insertHead(string nim, string nama, float persentaseKehadiran);
void insertLast(string nim, string nama, float persentaseKehadiran);

// Insert di kepala list (head)
void insertHead(string nim, string nama, float persentaseKehadiran) {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->nim = nim;
    newNode->nama = nama;
    newNode->persentaseKehadiran = persentaseKehadiran;
    newNode->next = head;
    head = newNode;
    cout << "\n[BERHASIL] Mahasiswa berhasil ditambahkan di depan (head).\n";
}

// Insert di akhir list (tail)
void insertLast(string nim, string nama, float persentaseKehadiran) {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->nim = nim;
    newNode->nama = nama;
    newNode->persentaseKehadiran = persentaseKehadiran;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Mahasiswa* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "\n[BERHASIL] Mahasiswa berhasil ditambahkan di belakang (last).\n";
}

// Inisialisasi data awal 16 mahasiswa
void initDataAwal() {
    insertLast("103032500150", "Naufal Nafiz Fathurrahman", 92.50);
    insertLast("103032500151", "Adi Wahyu Pratama", 85.00);
    insertLast("103032500152", "Budi Santoso", 78.25);
    insertLast("103032500153", "Citra Dewi", 95.00);
    insertLast("103032500154", "Doni Setiawan", 80.00);
    insertLast("103032500155", "Eka Putri", 88.50);
    insertLast("103032500156", "Fajar Mukti", 75.75);
    insertLast("103032500157", "Gita Lestari", 91.00);
    insertLast("103032500158", "Hari Surya", 87.25);
    insertLast("103032500159", "Indah Ayu", 93.50);
    insertLast("103032500160", "Jaka Taruna", 82.00);
    insertLast("103032500161", "Kartika Noor", 89.75);
    insertLast("103032500162", "Lina Marlina", 79.00);
    insertLast("103032500163", "Mochamad Rizki", 90.50);
    insertLast("103032500164", "Nurul Huda", 84.25);
    insertLast("103032500165", "Otavio Silva", 86.00);
}

int main() {
    // Masukkan data awal
    initDataAwal();

    cout << "Data awal 16 mahasiswa berhasil dimasukkan.\n";
    cout << "Fitur insertHead dan insertLast sudah tersedia.\n";
    return 0;
}
