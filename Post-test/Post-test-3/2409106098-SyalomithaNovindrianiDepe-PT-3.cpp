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

bool tambahData() {
    if (jumlahData >= MAX_DATA) {
        cout << "Data sudah penuh!\n";
        return false;
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
    return true;
}

string tampilkanData() {
    if (jumlahData == 0) {
        return "Belum ada data cuaca.\n";
    }
    string output = "\nDaftar Cuaca:\n";
    output += "==========================================\n";
    output += "| No | Kota            | Suhu (°C) | Kelembaban (%) |\n";
    output += "==========================================\n";
    for (int i = 0; i < jumlahData; i++) {
        output += "| " + to_string(i + 1) + "  | ";
        output += daftarCuaca[i].kota + string(15 - daftarCuaca[i].kota.length(), ' ') + "| ";
        output += to_string(daftarCuaca[i].suhu) + "       | ";
        output += to_string(daftarCuaca[i].kelembaban) + "%         |\n";
    }
    output += "==========================================\n";
    return output;
}

bool ubahData() {
    if (jumlahData == 0) {
        cout << "Belum ada data untuk diubah.\n";
        return false;
    }
    int index;
    cout << "Masukkan nomor data yang akan diubah: ";
    cin >> index;
    if (index < 1 || index > jumlahData) {
        cout << "Nomor tidak valid!\n";
        return false;
    }
    cout << "Masukkan nama kota baru: ";
    cin.ignore();
    getline(cin, daftarCuaca[index - 1].kota);
    cout << "Masukkan suhu baru (\u00B0C): ";
    cin >> daftarCuaca[index - 1].suhu;
    cout << "Masukkan kelembaban baru (%): ";
    cin >> daftarCuaca[index - 1].kelembaban;
    cout << "Data berhasil diubah!\n";
    return true;
}

bool hapusData() {
    if (jumlahData == 0) {
        cout << "Belum ada data untuk dihapus.\n";
        return false;
    }
    int index;
    cout << "Masukkan nomor data yang akan dihapus: ";
    cin >> index;
    if (index < 1 || index > jumlahData) {
        cout << "Nomor tidak valid!\n";
        return false;
    }
    for (int i = index - 1; i < jumlahData - 1; i++) {
        daftarCuaca[i] = daftarCuaca[i + 1];
    }
    jumlahData--;
    cout << "Data berhasil dihapus!\n";
    return true;
}

int main() {
    string username, password;
    int login_attempts = 0;
    while (login_attempts < 3) {
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        getline(cin, password);
        if (username == "Syalomitha Novindriani Depe" && password == "098") break;
        cout << "Login gagal. Coba lagi.\n";
        login_attempts++;
    }
    if (login_attempts == 3) {
        cout << "Terlalu banyak percobaan gagal. Program berhenti.\n";
        return 0;
    }
    int pilihan;
    do {
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
        cin >> pilihan;
        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: cout << tampilkanData(); break;
            case 3: ubahData(); break;
            case 4: hapusData(); break;
            case 5: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid!\n"; break;
        }
    } while (pilihan != 5);
    return 0;
}
