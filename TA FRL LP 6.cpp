#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

enum SlotState { EMPTY, OCCUPIED, DELETED };

struct Entry {
    int key;
    string value;
    SlotState state = EMPTY;
};

int hashFunc(int key) { return (key % SIZE + SIZE) % SIZE; }

void insertData(Entry table[], int key, string value) {
    int idx = hashFunc(key), start = idx;
    do {
        if (table[idx].state != OCCUPIED) {
            table[idx] = {key, value, OCCUPIED};
            cout << "Data berhasil ditambahkan!\n";
            return;
        }
        if (table[idx].key == key) {
            table[idx].value = value;
            cout << "Data diperbarui!\n";
            return;
        }
        idx = (idx + 1) % SIZE;
    } while (idx != start);
    cout << "Hash table penuh!\n";
}

void searchData(Entry table[], int key) {
    int idx = hashFunc(key), start = idx;
    do {
        if (table[idx].state == EMPTY) break;
        if (table[idx].state == OCCUPIED && table[idx].key == key) {
            cout << "Data ditemukan: " << table[idx].value << endl;
            return;
        }
        idx = (idx + 1) % SIZE;
    } while (idx != start);
    cout << "Data tidak ditemukan.\n";
}

void deleteData(Entry table[], int key) {
    int idx = hashFunc(key), start = idx;
    do {
        if (table[idx].state == EMPTY) break;
        if (table[idx].state == OCCUPIED && table[idx].key == key) {
            table[idx].state = DELETED;
            cout << "Data berhasil dihapus!\n";
            return;
        }
        idx = (idx + 1) % SIZE;
    } while (idx != start);
    cout << "Data tidak ditemukan.\n";
}

void displayData(Entry table[]) {
    cout << "\nIsi Hash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " -> ";
        if (table[i].state == OCCUPIED)
            cout << "(" << table[i].key << ", " << table[i].value << ")";
        else if (table[i].state == DELETED)
            cout << "DELETED";
        else
            cout << "EMPTY";
        cout << endl;
    }
}

int main() {
    Entry table[SIZE];
    bool jalan = true;
    int pilih;

    while (jalan) {
        cout << "\n=== Menu HashMap Pelanggan ===\n"
             << "1. Tambah Data\n2. Cari Data\n3. Hapus Data\n4. Lihat Semua Data\n5. Keluar\nPilih: ";
        cin >> pilih;

        if (pilih == 1) {
            int id; string nama;
            cout << "Masukkan ID: "; cin >> id;
            cout << "Masukkan Nama: "; cin >> nama;
            insertData(table, id, nama);
        } else if (pilih == 2) {
            int id; cout << "Masukkan ID: "; cin >> id; searchData(table, id);
        } else if (pilih == 3) {
            int id; cout << "Masukkan ID: "; cin >> id; deleteData(table, id);
        } else if (pilih == 4)
            displayData(table);
        else if (pilih == 5) {
            cout << "Keluar.\n"; jalan = false;
        } else
            cout << "Pilihan tidak valid!\n";
    }
    return 0;
}
