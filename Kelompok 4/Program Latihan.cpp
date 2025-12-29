#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama;
    int pilihan;
    int ulang = 1;

    cout << "=== PROGRAM LATIHAN GYM ===\n";

    // S1: Datang ke tempat latihan
    cout << "Masukkan nama member: ";
    cin >> nama;

    // S2: Pemanasan dan mulai latihan
    cout << "\nHalo " << nama << ", lakukan pemanasan terlebih dahulu.\n";
    cout << "Latihan dimulai...\n";

    // IF + DO WHILE
    do {
        cout << "\nPilih jenis latihan:\n";
        cout << "1. Chest\n";
        cout << "2. Back\n";
        cout << "3. Shoulder\n";
        cout << "4. Leg\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            // S3 & S10
            cout << "Latihan Chest\n";
            cout << "Contoh: Dumbbell Bench Press\n";
        }
        else if (pilihan == 2) {
            // S4 & S9
            cout << "Latihan Back\n";
            cout << "Contoh: Lat Pulldown\n";
        }
        else if (pilihan == 3) {
            // S5 & S8
            cout << "Latihan Shoulder\n";
            cout << "Contoh: Lateral Raise\n";
        }
        else if (pilihan == 4) {
            // S6 & S7
            cout << "Latihan Leg\n";
            cout << "Contoh: Leg Extension\n";
        }
        else {
            cout << "Pilihan tidak valid.\n";
        }

        // S11: Rest
        cout << "\nIstirahat sejenak...\n";

        // While (ulang latihan)
        cout << "Ulang latihan? (1 = Ya, 0 = Tidak): ";
        cin >> ulang;

    } while (ulang == 1);

    // S12: Pendinginan
    cout << "\nLakukan pendinginan setelah latihan.\n";

    // Selesai
    cout << "=== LATIHAN SELESAI ===\n";

    return 0;
}
