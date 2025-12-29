#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama, membership, metode;
    int pilihMembership, pilihMetode;
    int verifikasi;
    int berhasil = 0;

    cout << "=== SISTEM PEMBAYARAN GYM ===\n";

    // S1: Mulai
    cout << "Masukkan nama pengguna: ";
    cin >> nama;   

    // S2: Pilih membership
    cout << "\nPilih Jenis Membership:\n";
    cout << "1. Harian\n";
    cout << "2. Bulanan\n";
    cout << "3. Tahunan\n";
    cout << "Pilihan: ";
    cin >> pilihMembership;

    if (pilihMembership == 1) {
        membership = "Harian";
    } else if (pilihMembership == 2) {
        membership = "Bulanan";
    } else if (pilihMembership == 3) {
        membership = "Tahunan";
    } else {
        membership = "Tidak Valid";
    }

    cout << "Membership dipilih: " << membership << endl;

    // S3, S4, P1: Pembayaran & Verifikasi
    do {
        cout << "\nPilih Metode Pembayaran:\n";
        cout << "1. Tunai\n";
        cout << "2. Transfer\n";
        cout << "3. E-Wallet\n";
        cout << "Pilihan: ";
        cin >> pilihMetode;

        if (pilihMetode == 1) {
            metode = "Tunai";
        } else if (pilihMetode == 2) {
            metode = "Transfer";
        } else if (pilihMetode == 3) {
            metode = "E-Wallet";
        } else {
            metode = "Tidak Valid";
        }

        cout << "Metode pembayaran: " << metode << endl;

        // P1: Verifikasi pembayaran
        cout << "Verifikasi pembayaran (1 = berhasil, 0 = gagal): ";
        cin >> verifikasi;

        if (verifikasi == 1) {
            berhasil = 1;
        } else {
            cout << "Pembayaran gagal, silakan ulangi.\n";
        }

    } while (berhasil == 0);

    // S5: Bukti Pembayaran
    cout << "\nBukti pembayaran berhasil dicetak/dikirim.\n";

    // S6: Nama Member GYM
    cout << "Member gym atas nama " << nama << " telah diaktifkan.\n";

    // S7: Selesai
    cout << "=== PROSES SELESAI ===\n";

    return 0;
}
