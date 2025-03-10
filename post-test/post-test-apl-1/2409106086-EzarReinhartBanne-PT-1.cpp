#include <iostream>
using namespace std;

bool cek_login(string username, string password) {
    return (username == "Ezar Reinhart Banne" && password == "2409106086");
}

bool login() {
    string username;
    string password;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        cin >> password;

        if (cek_login(username, password)) {
            cout << "Login Berhasil!\n\n";
            return true;
        }
        percobaan++;
        cout << "Login Gagal! Sisa percobaan: " << (3 - percobaan) << "\n\n";
    }

    cout << "Terlalu banyak percobaan gagal. Program berhenti." << endl;
    return false;
}

double konversi_mata_uang(int pilihan, double jumlah) {
    double hasil = 0;
    if (pilihan == 1) hasil = jumlah * 0.000064;  // Rupiah ke Dolar AS
    else if (pilihan == 2) hasil = jumlah * 0.000059;  // Rupiah ke Euro
    else if (pilihan == 3) hasil = jumlah * 15625;     // Dolar AS ke Rupiah
    else if (pilihan == 4) hasil = jumlah * 0.92;      // Dolar AS ke Euro
    else if (pilihan == 5) hasil = jumlah * 16800;     // Euro ke Rupiah
    else if (pilihan == 6) hasil = jumlah * 1.09;      // Euro ke Dolar AS
    else cout << "Pilihan tidak valid!\n";
    return hasil;
}

double konversi_jarak(int pilihan, double jumlah) {
    double hasil = 0;
    if (pilihan == 1) hasil = jumlah * 1000;      // Kilometer ke Meter
    else if (pilihan == 2) hasil = jumlah * 100000;    // Kilometer ke Centimeter
    else if (pilihan == 3) hasil = jumlah / 1000;      // Meter ke Kilometer
    else if (pilihan == 4) hasil = jumlah * 100;       // Meter ke Centimeter
    else if (pilihan == 5) hasil = jumlah / 100000;    // Centimeter ke Kilometer
    else if (pilihan == 6) hasil = jumlah / 100;       // Centimeter ke Meter
    else cout << "Pilihan tidak valid!\n";
    return hasil;
}

double konversi_waktu(int pilihan, double jumlah) {
    double hasil = 0;
    if (pilihan == 1) hasil = jumlah * 60;        // Jam ke Menit
    else if (pilihan == 2) hasil = jumlah * 3600;      // Jam ke Detik
    else if (pilihan == 3) hasil = jumlah / 60;        // Menit ke Jam
    else if (pilihan == 4) hasil = jumlah * 60;        // Menit ke Detik
    else if (pilihan == 5) hasil = jumlah / 3600;      // Detik ke Jam
    else if (pilihan == 6) hasil = jumlah / 60;        // Detik ke Menit
    else cout << "Pilihan tidak valid!\n";
    return hasil;
}

void menu_utama() {
    int pilihan;
    do {
        cout << "\nMenu Utama:\n1. Konversi Mata Uang\n2. Konversi Jarak\n3. Konversi Waktu\n4. Logout\nPilih menu: ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 3) {
            double jumlah;
            int sub_pilihan;

            if (pilihan == 1) {
                cout << "\nKonversi Mata Uang:\n1. Rupiah ke Dolar AS\n2. Rupiah ke Euro\n3. Dolar AS ke Rupiah\n4. Dolar AS ke Euro\n5. Euro ke Rupiah\n6. Euro ke Dolar AS\nPilih opsi: ";
            } else if (pilihan == 2) {
                cout << "\nKonversi Jarak:\n1. Kilometer ke Meter\n2. Kilometer ke Centimeter\n3. Meter ke Kilometer\n4. Meter ke Centimeter\n5. Centimeter ke Kilometer\n6. Centimeter ke Meter\nPilih opsi: ";
            } else {
                cout << "\nKonversi Waktu:\n1. Jam ke Menit\n2. Jam ke Detik\n3. Menit ke Jam\n4. Menit ke Detik\n5. Detik ke Jam\n6. Detik ke Menit\nPilih opsi: ";
            }

            cin >> sub_pilihan;
            cout << "Masukkan jumlah: ";
            cin >> jumlah;

            double hasil = (pilihan == 1) ? konversi_mata_uang(sub_pilihan, jumlah) :
                          (pilihan == 2) ? konversi_jarak(sub_pilihan, jumlah) :
                                           konversi_waktu(sub_pilihan, jumlah);

            if (hasil != -1) {
                cout << "Hasil konversi: " << hasil << "\n";
            }
        } else if (pilihan != 4) {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    cout << "Logout berhasil. Program berhenti.\n";
}

int main() {
    if (login()) menu_utama();
    return 0;
}
