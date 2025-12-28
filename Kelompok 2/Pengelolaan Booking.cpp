#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

// ============================
// Struct Booking
// ============================
struct Booking {
    int kode;
    string nama_pemesan;
    string tanggal_jam;
    int jumlah_orang;
    string kebutuhan_tambahan;
    bool pembayaran_verifikasi;
};

// ============================
// Fungsi cetak konfirmasi
// ============================
void cetakKonfirmasi(const vector<Booking>& daftar_booking) {
    cout << "\n=== KONFIRMASI BOOKING ===\n";
    for (size_t i = 0; i < daftar_booking.size(); ++i) {
        cout << "Kode: " << daftar_booking[i].kode
             << " | Nama Pemesan: " << daftar_booking[i].nama_pemesan
             << " | Tanggal & Jam: " << daftar_booking[i].tanggal_jam
             << " | Jumlah Orang: " << daftar_booking[i].jumlah_orang
             << " | Kebutuhan Tambahan: " << daftar_booking[i].kebutuhan_tambahan
             << " | Pembayaran: " << (daftar_booking[i].pembayaran_verifikasi ? "Lunas" : "Belum") 
             << endl;
    }
    cout << "Booking berhasil dan disimpan. Terima kasih!\n";
}

// ============================
// MAIN PROGRAM
// ============================
int main() {
    vector<Booking> daftar_booking;
    int kode_counter = 1;
    int pilihan;
    bool selesai = false;

    while (!selesai) {
        cout << "\n=== MENU UTAMA BOOKING ===\n";
        cout << "1. Booking Tempat Baru\n";
        cout << "2. Edit Booking\n";
        cout << "3. Lihat Booking\n";
        cout << "4. Proses Pembayaran dan Konfirmasi\n";
        cout << "Pilih opsi (1-4): ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bersihkan buffer

        switch (pilihan) {
            // ============================
            // Booking Baru
            // ============================
            case 1: {
                bool data_benar = false;
                while (!data_benar) {
                    Booking b;
                    b.kode = kode_counter++;
                    b.pembayaran_verifikasi = false;

                    cout << "\nInput Booking:\n";
                    cout << "Nama pemesan: ";
                    getline(cin, b.nama_pemesan);

                    cout << "Tanggal & Jam acara (contoh: 2023-10-15 18:00): ";
                    getline(cin, b.tanggal_jam);

                    cout << "Jumlah orang (maks. 20): ";
                    cin >> b.jumlah_orang;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (b.jumlah_orang > 20) {
                        cout << "Jumlah orang maksimal 20. Ulangi input.\n";
                        continue;
                    }

                    cout << "Kebutuhan tambahan: ";
                    getline(cin, b.kebutuhan_tambahan);

                    cout << "Data booking: " << b.nama_pemesan
                         << " | " << b.tanggal_jam
                         << " | " << b.jumlah_orang << " orang | Kebutuhan: " << b.kebutuhan_tambahan << endl;

                    string konfirmasi;
                    cout << "Apakah data benar? (ya/tidak): ";
                    getline(cin, konfirmasi);
                    transform(konfirmasi.begin(), konfirmasi.end(), konfirmasi.begin(), ::tolower);

                    if (konfirmasi == "ya") {
                        daftar_booking.push_back(b);
                        data_benar = true;
                    } else if (konfirmasi == "tidak") {
                        cout << "Silakan input ulang booking.\n";
                    } else {
                        cout << "Input tidak valid. Silakan ketik 'ya' atau 'tidak'.\n";
                    }
                }
                break;
            }

            // ============================
            // Edit Booking
            // ============================
            case 2: {
                if (daftar_booking.empty()) {
                    cout << "Tidak ada booking untuk diedit.\n";
                    break;
                }

                int kode_edit;
                cout << "Masukkan kode booking yang ingin diedit: ";
                cin >> kode_edit;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                bool ditemukan = false;
                for (size_t i = 0; i < daftar_booking.size(); ++i) {
                    if (daftar_booking[i].kode == kode_edit) {
                        cout << "Edit Booking:\n";
                        cout << "Nama pemesan baru: ";
                        getline(cin, daftar_booking[i].nama_pemesan);

                        cout << "Tanggal & Jam baru: ";
                        getline(cin, daftar_booking[i].tanggal_jam);

                        cout << "Jumlah orang baru (maks. 20): ";
                        cin >> daftar_booking[i].jumlah_orang;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (daftar_booking[i].jumlah_orang > 20) {
                            cout << "Jumlah orang maksimal 20. Edit dibatalkan.\n";
                            break;
                        }

                        cout << "Kebutuhan tambahan baru: ";
                        getline(cin, daftar_booking[i].kebutuhan_tambahan);

                        cout << "Booking berhasil diedit.\n";
                        ditemukan = true;
                        break;
                    }
                }

                if (!ditemukan) {
                    cout << "Kode booking tidak ditemukan.\n";
                }
                break;
            }

            // ============================
            // Lihat Booking
            // ============================
            case 3: {
                if (daftar_booking.empty()) {
                    cout << "Tidak ada booking.\n";
                } else {
                    cetakKonfirmasi(daftar_booking);
                }
                break;
            }

            // ============================
            // Proses Pembayaran
            // ============================
            case 4: {
                if (daftar_booking.empty()) {
                    cout << "Tidak ada booking untuk diproses.\n";
                    break;
                }

                cout << "\n=== PROSES PEMBAYARAN BOOKING ===\n";
                cout << "Admin mengirim rekening/QRIS untuk booking.\n";

                string konfirmasi_transfer;
                cout << "Apakah transfer sudah dilakukan? (ya/tidak): ";
                getline(cin, konfirmasi_transfer); // langsung baca string
                transform(konfirmasi_transfer.begin(), konfirmasi_transfer.end(), konfirmasi_transfer.begin(), ::tolower);

                if (konfirmasi_transfer == "ya") {
                    cout << "Pembayaran diverifikasi oleh admin. Pembayaran berhasil!\n";
                    for (size_t i = 0; i < daftar_booking.size(); ++i) {
                        daftar_booking[i].pembayaran_verifikasi = true;
                    }
                    cetakKonfirmasi(daftar_booking);
                    selesai = true;
                } else if (konfirmasi_transfer == "tidak") {
                    cout << "Transfer belum dilakukan. Kembali ke menu.\n";
                } else {
                    cout << "Input tidak valid. Silakan ketik 'ya' atau 'tidak'.\n";
                }
                break;
            }

            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    }

    cout << "FINISH\n";
    return 0;
}




