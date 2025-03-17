#include <iostream>
#include <cstring>
#include <limits> 

using namespace std;

#define MAX_CUACA 100  // maks data cuaca
#define MAX_LOGIN_ATTEMPTS 3 // maks percobaan login

int main() {
    // array menyimpan data cuaca2
    string deskripsi[MAX_CUACA];
    float suhu[MAX_CUACA];
    float kelembapan[MAX_CUACA];
    int jumlahData = 0; // jumlah data saat ini

    // login
    string username, password;
    int attempts = 0;
    bool loggedIn = false;

    while (attempts < MAX_LOGIN_ATTEMPTS) {
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        // username & password
        if (username == "Mita" && password == "098") {
            cout << "Login berhasil!\n";
            loggedIn = true;
            break;
        } else {
            attempts++;
            cout << "Username atau password salah. Percobaan " << attempts << " dari " << MAX_LOGIN_ATTEMPTS << ".\n";
        }
    }

    if (!loggedIn) {
        cout << "Anda telah melebihi batas percobaan login. Program berhenti.\n";
        return 0; 
    }

    // menu utama
    int choice;
    while (true) {
        // menampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Cuaca\n";
        cout << "2. Lihat Data Cuaca\n";
        cout << "3. Ubah Data Cuaca\n";
        cout << "4. Hapus Data Cuaca\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";

        // validasi input menu
        while (!(cin >> choice) || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Pilihan tidak valid! Silakan pilih lagi (1-5): ";
        }

        // proses pilihan menu
        switch (choice) {
            case 1: // tambah data cuaca
                if (jumlahData < MAX_CUACA) {
                    cout << "Masukkan Suhu (°C): ";
                    while (!(cin >> suhu[jumlahData])) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Input tidak valid. Masukkan Suhu (°C) yang benar: ";
                    }
                    cout << "Masukkan Kelembapan (%): ";
                    while (!(cin >> kelembapan[jumlahData])) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Input tidak valid. Masukkan Kelembapan (%) yang benar: ";
                    }
                    cout << "Masukkan Deskripsi Cuaca: ";
                    cin.ignore();
                    getline(cin, deskripsi[jumlahData]);
                    jumlahData++;
                    cout << "Data cuaca berhasil ditambahkan.\n";
                } else {
                    cout << "Kapasitas data cuaca sudah penuh.\n";
                }
                break;

            case 2: // lihat data cuaca
                if (jumlahData == 0) {
                    cout << "Tidak ada data cuaca untuk ditampilkan.\n";
                } else {
                    cout << "Index\tSuhu (°C)\tKelembapan (%)\tDeskripsi\n";
                    cout << "--------------------------------------------------\n";
                    for (int i = 0; i < jumlahData; i++) {
                        cout << i << "\t" << suhu[i] << "\t\t" << kelembapan[i] << "\t\t" << deskripsi[i] << "\n";
                    }
                }
                break;

            case 3: // ubah data cuaca
                if (jumlahData == 0) {
                    cout << "Tidak ada data cuaca untuk diubah.\n";
                } else {
                    int index;
                    cout << "Masukkan index data cuaca yang ingin diubah: ";
                    while (!(cin >> index) || index < 0 || index >= jumlahData) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Index tidak valid. Masukkan index yang benar: ";
                    }
                    cout << "Masukkan Suhu baru (°C): ";
                    while (!(cin >> suhu[index])) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Input tidak valid. Masukkan Suhu (°C) yang benar: ";
                    }
                    cout << "Masukkan Kelembapan baru (%): ";
                    while (!(cin >> kelembapan[index])) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Input tidak valid. Masukkan Kelembapan (%) yang benar: ";
                    }
                    cout << "Masukkan Deskripsi Cuaca baru: ";
                    cin.ignore();
                    getline(cin, deskripsi[index]);
                    cout << "Data cuaca berhasil diperbarui.\n";
                }
                break;

            case 4: // hapus data cuaca
                if (jumlahData == 0) {
                    cout << "Tidak ada data cuaca untuk dihapus.\n";
                } else {
                    int index;
                    cout << "Masukkan index data cuaca yang ingin dihapus: ";
                    while (!(cin >> index) || index < 0 || index >= jumlahData) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Index tidak valid. Masukkan index yang benar: ";
                    }
                    for (int i = index; i < jumlahData - 1; i++) {
                        suhu[i] = suhu[i + 1];
                        kelembapan[i] = kelembapan[i + 1];
                        deskripsi[i] = deskripsi[i + 1];
                    }
                    jumlahData--;
                    cout << "Data cuaca berhasil dihapus.\n";
                }
                break;

            case 5: // keluar
                cout << "Keluar dari program.\n";
                return 0;

            default:
                cout << "Pilihan tidak valid! Silakan pilih lagi.\n";
        }
    }

    return 0;
}