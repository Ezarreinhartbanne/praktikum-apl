#include <iostream>
#include <string>

using namespace std;

const int MAX_RESERVASI = 100;
int idList[MAX_RESERVASI];
string namaList[MAX_RESERVASI], tanggalList[MAX_RESERVASI], waktuList[MAX_RESERVASI], lapanganList[MAX_RESERVASI];
int jumlahReservasi = 0;

int main() {
    string username, password;
    int attempts = 0;
    bool loginSuccess = false;

    // Fitur Login
    while (attempts < 3) {
        cout << "=== Login Sistem ===\n";
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);

        if (username == "Ezar Reinhart Banne" && password == "2409106086") {
            loginSuccess = true;
            break;
        } else {
            cout << "Username atau password salah! Percobaan tersisa: " << (2 - attempts) << endl;
            attempts++;
        }
    }

    if (!loginSuccess) {
        cout << "Anda telah mencoba sebanyak 3 kali. Program ditutup.\n";
        return 0; // Keluar dari program jika login gagal
    }

    int idCounter = 1;
    int pilihan;
    
    do {
        cout << "\n=== Sistem Reservasi Lapangan Futsal ===\n";
        cout << "1. Tambah Reservasi\n";
        cout << "2. Tampilkan Reservasi\n";
        cout << "3. Ubah Reservasi\n";
        cout << "4. Hapus Reservasi\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            if (jumlahReservasi < MAX_RESERVASI) {
                cout << "Masukkan nama pelanggan: ";
                getline(cin, namaList[jumlahReservasi]);
                cout << "Masukkan tanggal (DD/MM/YYYY): ";
                getline(cin, tanggalList[jumlahReservasi]);
                cout << "Masukkan waktu (HH:MM): ";
                getline(cin, waktuList[jumlahReservasi]);
                cout << "Masukkan nomor lapangan: ";
                getline(cin, lapanganList[jumlahReservasi]);
                idList[jumlahReservasi] = idCounter++;
                jumlahReservasi++;
                cout << "Reservasi berhasil ditambahkan!\n";
            } else {
                cout << "Kapasitas reservasi penuh!\n";
            }
        } 
        else if (pilihan == 2) {
            if (jumlahReservasi == 0) {
                cout << "Tidak ada reservasi.\n";
            } else {
                cout << "\nDaftar Reservasi:\n";
                for (int i = 0; i < jumlahReservasi; i++) {
                    cout << "ID: " << idList[i] << " | Nama: " << namaList[i]
                         << " | Tanggal: " << tanggalList[i]
                         << " | Waktu: " << waktuList[i]
                         << " | Lapangan: " << lapanganList[i] << "\n";
                }
            }
        } 
        else if (pilihan == 3) {
            int id;
            cout << "Masukkan ID reservasi yang ingin diubah: ";
            cin >> id;
            cin.ignore();
            bool ditemukan = false;
            for (int i = 0; i < jumlahReservasi; i++) {
                if (idList[i] == id) {
                    cout << "Masukkan nama baru: ";
                    getline(cin, namaList[i]);
                    cout << "Masukkan tanggal baru (DD/MM/YYYY): ";
                    getline(cin, tanggalList[i]);
                    cout << "Masukkan waktu baru (HH:MM): ";
                    getline(cin, waktuList[i]);
                    cout << "Masukkan nomor lapangan baru: ";
                    getline(cin, lapanganList[i]);
                    cout << "Reservasi berhasil diubah!\n";
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) {
                cout << "Reservasi dengan ID tersebut tidak ditemukan.\n";
            }
        } 
        else if (pilihan == 4) {
            int id;
            cout << "Masukkan ID reservasi yang ingin dihapus: ";
            cin >> id;
            bool ditemukan = false;
            for (int i = 0; i < jumlahReservasi; i++) {
                if (idList[i] == id) {
                    for (int j = i; j < jumlahReservasi - 1; j++) {
                        idList[j] = idList[j + 1];
                        namaList[j] = namaList[j + 1];
                        tanggalList[j] = tanggalList[j + 1];
                        waktuList[j] = waktuList[j + 1];
                        lapanganList[j] = lapanganList[j + 1];
                    }
                    jumlahReservasi--;
                    cout << "Reservasi berhasil dihapus!\n";
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) {
                cout << "Reservasi dengan ID tersebut tidak ditemukan.\n";
            }
        } 
        else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan sistem ini!\n";
        } 
        else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
    
    return 0;
}