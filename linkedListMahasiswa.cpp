#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
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
void deleteHead();
void deleteLast();
void cetakDaftar();

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

// Hapus node paling depan (head)
void deleteHead() {
    if (head == nullptr) {
        cout << "\n[PIHAN] List kosong, tidak ada yang dihapus.\n";
        return;
    }
    Mahasiswa* temp = head;
    head = head->next;
    cout << "\n[DIHAPUS] Mahasiswa '" << temp->nama << "' (NIM: " << temp->nim << ") dihapus dari depan.\n";
    delete temp;
}

// Hapus node paling belakang (last)
void deleteLast() {
    if (head == nullptr) {
        cout << "\n[PIHAN] List kosong, tidak ada yang dihapus.\n";
        return;
    }
    if (head->next == nullptr) {
        // Hanya satu node
        cout << "\n[DIHAPUS] Mahasiswa '" << head->nama << "' (NIM: " << head->nim << ") dihapus dari belakang.\n";
        delete head;
        head = nullptr;
        return;
    }
    Mahasiswa* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    Mahasiswa* toDelete = temp->next;
    cout << "\n[DIHAPUS] Mahasiswa '" << toDelete->nama << "' (NIM: " << toDelete->nim << ") dihapus dari belakang.\n";
    delete toDelete;
    temp->next = nullptr;
}

// Inisialisasi data awal 16 mahasiswa
void initDataAwal() {
    insertLast("103032500150", "Naufal Nafiz Fathurrahman", 92.50);
    insertLast("103032500151", "Fazli Baktiadi", 85.00);
    insertLast("103032500152", "Dare Haqu ", 78.25);
    insertLast("103032500153", "Fariz Muhtadi", 95.00);
    insertLast("103032500154", "Fathin Arib", 80.00);
    insertLast("103032500155", "Gyio Rangga", 88.50);
    insertLast("103032500156", "Matthew Glenn", 75.75);
    insertLast("103032500157", "Ida Bagus Harell", 91.00);
    insertLast("103032500158", "Dzaky Alam", 87.25);
    insertLast("103032500159", "Aqila Fathatullayya", 93.50);
    insertLast("103032500160", "Mahesa Putra", 82.00);
    insertLast("103032500161", "Fadhil Asyam", 89.75);
    insertLast("103032500162", "Rasya Iman", 79.00);
    insertLast("103032500163", "Vendra Fausta", 90.50);
    insertLast("103032500164", "Nayla Novtiera", 84.25);
    insertLast("103032500165", "Badriah Nuraini", 86.00);
}


// Cetak seluruh isi list
void cetakDaftar() {
    cout << "\n==========================================================\n";
    cout << setw(5) << left << "No"
         << setw(20) << left << "NIM"
         << setw(25) << left << "Nama"
         << setw(20) << right << "Persentase Kehadiran\n";
    cout << "----------------------------------------------------------\n";

    if (head == nullptr) {
        cout << "List kosong.\n";
    } else {
        Mahasiswa* temp = head;
        int i = 1;
        while (temp != nullptr) {
            cout << setw(5) << left << i
                 << setw(20) << left << temp->nim
                 << setw(25) << left << temp->nama
                 << setw(18) << right << fixed << setprecision(2) << temp->persentaseKehadiran << "%\n";
            temp = temp->next;
            i++;
        }
    }
    cout << "==========================================================\n";
}

int main() {
    // Masukkan data awal
    initDataAwal();

    int pilihan;
    string nim, nama;
    float persentase;

    do {
        cout << "\n========================================\n";
        cout << "   PROGRAM SINGLE LINKED LIST\n";
        cout << "   KEHADIRAN MAHASISWA\n";
        cout << "========================================\n";
        cout << "1. Insert Head (tambah di depan)\n";
        cout << "2. Insert Last (tambah di belakang)\n";
        cout << "3. Delete Head (hapus paling depan)\n";
        cout << "4. Delete Last (hapus paling belakang)\n";
        cout << "5. Cetak Daftar (lihat semua)\n";
        cout << "6. Keluar\n";
        cout << "========================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n[ERROR] Input tidak valid. Masukkan angka 1-6.\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                cout << "\n--- Insert Head ---\n";
                cout << "Masukkan NIM     : ";
                cin >> nim;
                cout << "Masukkan Nama    : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Persentase Kehadiran : ";
                cin >> persentase;
                insertHead(nim, nama, persentase);
                break;
            case 2:
                cout << "\n--- Insert Last ---\n";
                cout << "Masukkan NIM     : ";
                cin >> nim;
                cout << "Masukkan Nama    : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Persentase Kehadiran : ";
                cin >> persentase;
                insertLast(nim, nama, persentase);
                break;
            case 3:
                cout << "\n--- Delete Head ---\n";
                deleteHead();
                break;
            case 4:
                cout << "\n--- Delete Last ---\n";
                deleteLast();
                break;
            case 5:
                cetakDaftar();
                break;
            case 6:
                cout << "\nTerima kasih! Program selesai.\n";
                break;
            default:
                cout << "\n[ERROR] Pilihan tidak valid. Masukkan angka 1-6.\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}
