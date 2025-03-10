#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14

void hitungLuas();
void hitungKeliling();
void hitungVolume();

int main() {
    string username, password;
    
    // sistem Login
    do {
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password (NIM): ";
        cin >> password;
        cin.ignore();

        if (username != "Syalomitha Novindriani Depe" || password != "2409106098") {
            cout << "Username atau Password salah! Coba lagi.\n";
        }
    } while (username != "Syalomitha Novindriani Depe" || password != "2409106098");

    cout << "Login Berhasil!\n";
    
    int pilihan;
    do {
        cout << "\n== SISTEM HITUNG BANGUN DATAR DAN BANGUN RUANG ==\n";
        cout << "1. Hitung Luas\n";
        cout << "2. Hitung Keliling\n";
        cout << "3. Hitung Volume\n";
        cout << "4. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: hitungLuas(); break;
            case 2: hitungKeliling(); break;
            case 3: hitungVolume(); break;
            case 4: cout << "Logout Berhasil."; break;
            default: cout << "Pilihan tidak valid.\n"; break;
        }
    } while (pilihan != 4);
    
    return 0;
}

void hitungLuas() {
    int pilihan;
    double sisi, panjang, lebar, jari, alas, tinggi;
    
    do {
        cout << "\n== HITUNG LUAS ==\n";
        cout << "1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\n";
        cout << "Pilih bentuk: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                do {
                    cout << "Masukkan sisi persegi: "; cin >> sisi;
                } while (sisi <= 0);
                cout << "Luas: " << sisi * sisi << "\n";
                break;
            case 2:
                do {
                    cout << "Masukkan panjang: "; cin >> panjang;
                    cout << "Masukkan lebar: "; cin >> lebar;
                } while (panjang <= 0 || lebar <= 0);
                cout << "Luas: " << panjang * lebar << "\n";
                break;
            case 3:
                do {
                    cout << "Masukkan jari-jari lingkaran: "; cin >> jari;
                } while (jari <= 0);
                cout << "Luas: " << PI * jari * jari << "\n";
                break;
            case 4:
                do {
                    cout << "Masukkan alas: "; cin >> alas;
                    cout << "Masukkan tinggi: "; cin >> tinggi;
                } while (alas <= 0 || tinggi <= 0);
                cout << "Luas: " << 0.5 * alas * tinggi << "\n";
                break;
        }
    } while (pilihan != 5);
}

void hitungKeliling() {
    int pilihan;
    double sisi, panjang, lebar, jari, alas, tinggi, miring;
    
    do {
        cout << "\n== HITUNG KELILING ==\n";
        cout << "1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\n";
        cout << "Pilih bentuk: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                do {
                    cout << "Masukkan sisi persegi: "; cin >> sisi;
                } while (sisi <= 0);
                cout << "Keliling: " << 4 * sisi << "\n";
                break;
            case 2:
                do {
                    cout << "Masukkan panjang: "; cin >> panjang;
                    cout << "Masukkan lebar: "; cin >> lebar;
                } while (panjang <= 0 || lebar <= 0);
                cout << "Keliling: " << 2 * (panjang + lebar) << "\n";
                break;
            case 3:
                do {
                    cout << "Masukkan jari-jari lingkaran: "; cin >> jari;
                } while (jari <= 0);
                cout << "Keliling: " << 2 * PI * jari << "\n";
                break;
            case 4:
                do {
                    cout << "Masukkan alas: "; cin >> alas;
                    cout << "Masukkan tinggi: "; cin >> tinggi;
                    cout << "Masukkan sisi miring: "; cin >> miring;
                } while (alas <= 0 || tinggi <= 0 || miring <= 0);
                cout << "Keliling: " << alas + tinggi + miring << "\n";
                break;
        }
    } while (pilihan != 5);
}

void hitungVolume() {
    int pilihan;
    double sisi, panjang, lebar, tinggi, jari;
    
    do {
        cout << "\n== HITUNG VOLUME ==\n";
        cout << "1. Kubus\n2. Balok\n3. Bola\n4. Kerucut\n5. Kembali\n";
        cout << "Pilih bentuk: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                do {
                    cout << "Masukkan sisi kubus: "; cin >> sisi;
                } while (sisi <= 0);
                cout << "Volume: " << sisi * sisi * sisi << "\n";
                break;
            case 2:
                do {
                    cout << "Masukkan panjang: "; cin >> panjang;
                    cout << "Masukkan lebar: "; cin >> lebar;
                    cout << "Masukkan tinggi: "; cin >> tinggi;
                } while (panjang <= 0 || lebar <= 0 || tinggi <= 0);
                cout << "Volume: " << panjang * lebar * tinggi << "\n";
                break;
            case 3:
                do {
                    cout << "Masukkan jari-jari bola: "; cin >> jari;
                } while (jari <= 0);
                cout << "Volume: " << (4.0/3) * PI * pow(jari, 3) << "\n";
                break;
        }
    } while (pilihan != 5);
}

case 4: cout << "Logout Berhasil."; break;