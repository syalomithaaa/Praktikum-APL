#include <iostream>
#include <string>
using namespace std;

#define MAX_DATA 100

struct Cuaca {
    string kota;
    float suhu;
    int kelembaban;
};

Cuaca daftarCuaca[MAX_DATA];
int jumlahData = 0;

// prototipe fungsi pointer
bool loginSystem();
void displayMainMenu();
void tambahDataCuaca(Cuaca *data);
void tampilkanDataCuaca(const Cuaca *data, int size);
void ubahDataCuaca(Cuaca *data, int index);
void hapusDataCuaca(int *size);
float hitungRata(const Cuaca *data, int size, char jenis);

// login (ga diubah)
bool loginSystem() {
    string username, password;
    int attempts = 0;
    
    while (attempts < 3) {
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        getline(cin, password);
        
        if (username == "Syalomitha Novindriani Depe" && password == "098") {
            return true;
        }
        
        cout << "Login gagal. Coba lagi.\n";
        attempts++;
    }
    
    return false;
}

// tambah data cuaca dengan pointer ke array
void tambahDataCuaca(Cuaca *data) {
    if (jumlahData >= MAX_DATA) {
        cout << "Data sudah penuh!\n";
        return;
    }
    
    cout << "Masukkan nama kota: ";
    cin.ignore();
    getline(cin, data[jumlahData].kota);
    cout << "Masukkan suhu (\u00B0C): ";
    cin >> data[jumlahData].suhu;
    cout << "Masukkan kelembaban (%): ";
    cin >> data[jumlahData].kelembaban;
    
    jumlahData++;
    cout << "Data berhasil ditambahkan!\n";
}

// nampilkan data cuaca pointer ke array
void tampilkanDataCuaca(const Cuaca *data, int size) {
    if (size == 0) {
        cout << "Belum ada data cuaca.\n";
        return;
    }
    
    cout << "\nDaftar Cuaca:\n";
    cout << "==========================================\n";
    cout << "| No | Kota            | Suhu (°C) | Kelembaban (%) |\n";
    cout << "==========================================\n";
    
    for (int i = 0; i < size; i++) {
        cout << "| " << (i + 1) << "  | ";
        cout << data[i].kota << string(15 - data[i].kota.length(), ' ') << "| ";
        cout << data[i].suhu << "       | ";
        cout << data[i].kelembaban << "%         |\n";
    }
    
    cout << "==========================================\n";
    
    // nampilkan rata-rata menggunakan pointer
    cout << "Rata-rata Suhu: " << hitungRata(data, size, 's') << "°C\n";
    cout << "Rata-rata Kelembaban: " << hitungRata(data, size, 'k') << "%\n";
}

// ubah data cuaca dengan pointer ke elemen array
void ubahDataCuaca(Cuaca *data, int index) {
    cout << "Masukkan nama kota baru: ";
    cin.ignore();
    getline(cin, data[index].kota);
    cout << "Masukkan suhu baru (\u00B0C): ";
    cin >> data[index].suhu;
    cout << "Masukkan kelembaban baru (%): ";
    cin >> data[index].kelembaban;
    
    cout << "Data berhasil diubah!\n";
}

// hapus data cuaca dengan pointer ke jumlah data
void hapusDataCuaca(int *size) {
    if (*size == 0) {
        cout << "Belum ada data untuk dihapus.\n";
        return;
    }
    
    int index;
    tampilkanDataCuaca(daftarCuaca, *size);
    cout << "Masukkan nomor data yang akan dihapus: ";
    cin >> index;
    
    if (index < 1 || index > *size) {
        cout << "Nomor tidak valid!\n";
        return;
    }
    
    for (int i = index - 1; i < *size - 1; i++) {
        daftarCuaca[i] = daftarCuaca[i + 1];
    }
    (*size)--;
    
    cout << "Data berhasil dihapus!\n";
}

// menghitung rata-rata (suhu atau kelembaban)
float hitungRata(const Cuaca *data, int size, char jenis) {
    if (size == 0) return 0;
    
    float total = 0;
    for (int i = 0; i < size; i++) {
        if (jenis == 's') {
            total += data[i].suhu;
        } else {
            total += data[i].kelembaban;
        }
    }
    return total / size;
}

// menu utama
void displayMainMenu() {
    cout << "\n==================================\n";
    cout << "|           MENU UTAMA           |\n";
    cout << "==================================\n";
    cout << "| 1 | Tambah Data Cuaca         |\n";
    cout << "| 2 | Tampilkan Data Cuaca      |\n";
    cout << "| 3 | Ubah Data Cuaca           |\n";
    cout << "| 4 | Hapus Data Cuaca          |\n";
    cout << "| 5 | Keluar                    |\n";
    cout << "==================================\n";
    cout << "Pilih menu: ";
}

int main() {
    if (!loginSystem()) {
        cout << "Terlalu banyak percobaan gagal. Program berhenti.\n";
        return 0;
    }
    
    int pilihan;
    do {
        displayMainMenu();
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: 
                tambahDataCuaca(daftarCuaca); 
                break;
            case 2: 
                tampilkanDataCuaca(daftarCuaca, jumlahData); 
                break;
            case 3: 
                if (jumlahData == 0) {
                    cout << "Belum ada data untuk diubah.\n";
                    break;
                }
                int index;
                tampilkanDataCuaca(daftarCuaca, jumlahData);
                cout << "Masukkan nomor data yang akan diubah: ";
                cin >> index;
                if (index < 1 || index > jumlahData) {
                    cout << "Nomor tidak valid!\n";
                    break;
                }
                ubahDataCuaca(daftarCuaca, index-1); // pointer ke elemen
                break;
            case 4: 
                hapusDataCuaca(&jumlahData); // pointer ke jumlahData
                break;
            case 5: 
                cout << "Keluar dari program.\n";
                break;
            default: 
                cout << "Pilihan tidak valid!\n"; 
                break;
        }
    } while (pilihan != 5);
    
    return 0;
}