#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm> // untuk transform

using namespace std;

// ============================
// Semua variabel int di atas
// ============================
int pilihan;
int kode_counter = 1;
int kode_edit;
int metode;

// ============================
// Struct Pesanan
// ============================
struct Pesanan {
    int kode;
    string nama_menu;
    int jumlah;
    string catatan;
    double harga_per_item;
};

// ============================
// Fungsi hitung total
// ============================
double hitungTotal(const vector<Pesanan>& pesanan) {
    double total = 0.0;
    for (size_t i = 0; i < pesanan.size(); ++i) {
        total += pesanan[i].harga_per_item * pesanan[i].jumlah;
    }
    return total;
}

// ============================
// Fungsi cetak struk
// ============================
void cetakStruk(const vector<Pesanan>& pesanan, double total) {
    cout << "\n=== STRUK PEMESANAN ===\n";
    for (size_t i = 0; i < pesanan.size(); ++i) {
        cout << "Kode: " << pesanan[i].kode 
             << " | Menu: " << pesanan[i].nama_menu 
             << " | Jumlah: " << pesanan[i].jumlah 
             << " | Harga: Rp" << (pesanan[i].harga_per_item * pesanan[i].jumlah) 
             << " | Catatan: " << pesanan[i].catatan << endl;
    }
    cout << "Total: Rp" << total << endl;
    cout << "Pembayaran diterima. Terima kasih!\n";
}

// ============================
// MAIN PROGRAM
// ============================
int main() {
    vector<Pesanan> daftar_pesanan;
    bool selesai = false;

    while (!selesai) {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Pesan Menu\n";
        cout << "2. Edit Pesanan\n";
        cout << "3. Lihat Pesanan\n";
        cout << "4. Proses Pembayaran dan Selesai\n";
        cout << "Pilih opsi (1-4): ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer

        switch (pilihan) {
            case 1: { 
                bool data_benar = false;
                while (!data_benar) {
                    Pesanan p;
                    p.kode = kode_counter++;

                    cout << "\nInput Pesanan:\n";
                    cout << "Nama menu (Roti/Kopi/Teh): ";
                    getline(cin, p.nama_menu);

                    cout << "Jumlah: ";
                    cin >> p.jumlah;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Catatan: ";
                    getline(cin, p.catatan);

                    if (p.nama_menu == "Roti") p.harga_per_item = 13000;
                    else if (p.nama_menu == "Kopi") p.harga_per_item = 18000;
                    else if (p.nama_menu == "Teh") p.harga_per_item = 15000;
                    else p.harga_per_item = 10000;

                    cout << "Data pesanan: " << p.nama_menu << " x" << p.jumlah 
                         << " (Rp" << (p.harga_per_item * p.jumlah) << ") Catatan: " << p.catatan << endl;

                    string konfirmasi;
                    cout << "Apakah data benar? (ya/tidak): ";
                    getline(cin, konfirmasi);

                    // Ubah input ke lowercase agar case-insensitive
                    transform(konfirmasi.begin(), konfirmasi.end(), konfirmasi.begin(), ::tolower);

                    if (konfirmasi == "ya") {
                        daftar_pesanan.push_back(p);
                        data_benar = true;
                    } else if (konfirmasi == "tidak") {
                        cout << "Silakan input ulang pesanan.\n";
                    } else {
                        cout << "Input tidak valid. Silakan ketik 'ya' atau 'tidak'.\n";
                    }
                }
                break;
            }

            case 2: {
                if (daftar_pesanan.empty()) {
                    cout << "Tidak ada pesanan untuk diedit.\n";
                    break;
                }
                cout << "Masukkan kode pesanan yang ingin diedit: ";
                cin >> kode_edit;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                bool ditemukan = false;
                for (size_t i = 0; i < daftar_pesanan.size(); ++i) {
                    if (daftar_pesanan[i].kode == kode_edit) {
                        cout << "Edit Pesanan:\n";
                        cout << "Nama menu baru (Roti/Kopi/Teh): ";
                        getline(cin, daftar_pesanan[i].nama_menu);
                        cout << "Jumlah baru: ";
                        cin >> daftar_pesanan[i].jumlah;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Catatan baru: ";
                        getline(cin, daftar_pesanan[i].catatan);

                        if (daftar_pesanan[i].nama_menu == "Roti") daftar_pesanan[i].harga_per_item = 13000;
                        else if (daftar_pesanan[i].nama_menu == "Kopi") daftar_pesanan[i].harga_per_item = 18000;
                        else if (daftar_pesanan[i].nama_menu == "Teh") daftar_pesanan[i].harga_per_item = 15000;
                        else daftar_pesanan[i].harga_per_item = 10000;

                        cout << "Pesanan berhasil diedit.\n";
                        ditemukan = true;
                        break;
                    }
                }

                if (!ditemukan) {
                    cout << "Kode pesanan tidak ditemukan.\n";
                }
                break;
            }

            case 3: {
                if (daftar_pesanan.empty()) {
                    cout << "Tidak ada pesanan.\n";
                } else {
                    double total = hitungTotal(daftar_pesanan);
                    cetakStruk(daftar_pesanan, total);
                }
                break;
            }

            case 4: {
                if (daftar_pesanan.empty()) {
                    cout << "Tidak ada pesanan untuk diproses.\n";
                    break;
                }
                double total = hitungTotal(daftar_pesanan);
                cout << "\nTotal pembayaran: Rp" << total << endl;
                cout << "Pilih metode pembayaran (1=Cash, 2=Debit, 3=QRIS): ";
                cin >> metode;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Pembayaran diterima.\n";

                cetakStruk(daftar_pesanan, total);
                selesai = true;
                break;
            }

            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    }

    cout << "FINISH\n";
}


INI YANG PERTAMA TERBARU
