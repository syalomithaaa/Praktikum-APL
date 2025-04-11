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

// prototype fungsi dan prosedur
bool loginSystem();
void displayMainMenu();
void tambahDataCuaca();
string tampilkanDataCuaca();
void ubahDataCuaca();
void hapusDataCuaca();
void keluarProgram();
float hitungRataSuhu();
float hitungRataKelembaban();

// fungsi login
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

// menambahkan data cuaca
void tambahDataCuaca() {
    if (jumlahData >= MAX_DATA) {
        cout << "Data sudah penuh!\n";
        return;
    }
    
    cout << "Masukkan nama kota: ";
    cin.ignore();
    getline(cin, daftarCuaca[jumlahData].kota);
    cout << "Masukkan suhu (\u00B0C): ";
    cin >> daftarCuaca[jumlahData].suhu;
    cout << "Masukkan kelembaban (%): ";
    cin >> daftarCuaca[jumlahData].kelembaban;
    
    jumlahData++;
    cout << "Data berhasil ditambahkan!\n";
}

// menampilkan data cuaca (tanpa rekursi)
string tampilkanDataCuaca() {
    if (jumlahData == 0) {
        return "Belum ada data cuaca.\n";
    }
    
    string output = "\nDaftar Cuaca:\n";
    output += "==========================================\n";
    output += "| No | Kota            | Suhu (°C) | Kelembaban (%) |\n";
    output += "==========================================\n";
    
    // loop biasa
    for (int i = 0; i < jumlahData; i++) {
        output += "| " + to_string(i + 1) + "  | ";
        output += daftarCuaca[i].kota + string(15 - daftarCuaca[i].kota.length(), ' ') + "| ";
        output += to_string(daftarCuaca[i].suhu) + "       | ";
        output += to_string(daftarCuaca[i].kelembaban) + "%         |\n";
    }
    
    output += "==========================================\n";
    
    // menambahkan informasi rata-rata
    output += "Rata-rata Suhu: " + to_string(hitungRataSuhu()) + "°C\n";
    output += "Rata-rata Kelembaban: " + to_string(hitungRataKelembaban()) + "%\n";
    
    return output;
}

// menghitung rata-rata suhu
float hitungRataSuhu() {
    if (jumlahData == 0) return 0;
    
    float total = 0;
    for (int i = 0; i < jumlahData; i++) {
        total += daftarCuaca[i].suhu;
    }
    return total / jumlahData;
}

// menghitung rata-rata kelembaban
float hitungRataKelembaban() {
    if (jumlahData == 0) return 0;
    
    float total = 0;
    for (int i = 0; i < jumlahData; i++) {
        total += daftarCuaca[i].kelembaban;
    }
    return total / jumlahData;
}

// mengubah data cuaca
void ubahDataCuaca() {
    if (jumlahData == 0) {
        cout << "Belum ada data untuk diubah.\n";
        return;
    }
    
    int index;
    cout << tampilkanDataCuaca();
    cout << "Masukkan nomor data yang akan diubah: ";
    cin >> index;
    
    if (index < 1 || index > jumlahData) {
        cout << "Nomor tidak valid!\n";
        return;
    }
    
    cout << "Masukkan nama kota baru: ";
    cin.ignore();
    getline(cin, daftarCuaca[index - 1].kota);
    cout << "Masukkan suhu baru (\u00B0C): ";
    cin >> daftarCuaca[index - 1].suhu;
    cout << "Masukkan kelembaban baru (%): ";
    cin >> daftarCuaca[index - 1].kelembaban;
    
    cout << "Data berhasil diubah!\n";
}

// menghapus data cuaca
void hapusDataCuaca() {
    if (jumlahData == 0) {
        cout << "Belum ada data untuk dihapus.\n";
        return;
    }
    
    int index;
    cout << tampilkanDataCuaca();
    cout << "Masukkan nomor data yang akan dihapus: ";
    cin >> index;
    
    if (index < 1 || index > jumlahData) {
        cout << "Nomor tidak valid!\n";
        return;
    }
    
    for (int i = index - 1; i < jumlahData - 1; i++) {
        daftarCuaca[i] = daftarCuaca[i + 1];
    }
    jumlahData--;
    
    cout << "Data berhasil dihapus!\n";
}

// menampilkan menu utama
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

// keluar program
void keluarProgram() {
    cout << "Keluar dari program.\n";
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
                tambahDataCuaca(); 
                break;
            case 2: 
                cout << tampilkanDataCuaca(); 
                break;
            case 3: 
                ubahDataCuaca(); 
                break;
            case 4: 
                hapusDataCuaca(); 
                break;
            case 5: 
                keluarProgram(); 
                break;
            default: 
                cout << "Pilihan tidak valid!\n"; 
                break;
        }
    } while (pilihan != 5);
    
    return 0;
}