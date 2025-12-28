#include <iostream>
#include <vector>
#include <string>
#include <limits> 
#include <algorithm> // untuk transform
using namespace std;

struct Pesanan {
    int kode;
    string nama_menu;
    int jumlah;
    string catatan;
    double harga_per_item;
    bool pembayaran_verifikasi; 
    string metode_pengiriman;
};

double hitungTotal(const vector<Pesanan>& pesanan) {
    double total = 0.0;
    for (size_t i = 0; i < pesanan.size(); ++i) {
        total += pesanan[i].harga_per_item * pesanan[i].jumlah;
    }
    return total; // sebelumnya lupa return
}

void cetakStrukAkhir(const vector<Pesanan>& pesanan, double total) {
    cout << "\n=== STRUK PEMESANAN ONLINE ===\n";
    for (size_t i = 0; i < pesanan.size(); ++i) {
        cout << "Kode: " << pesanan[i].kode << " | Menu: " << pesanan[i].nama_menu 
             << " | Jumlah: " << pesanan[i].jumlah << " | Harga: Rp" 
             << (pesanan[i].harga_per_item * pesanan[i].jumlah) << " | Catatan: " << pesanan[i].catatan << endl;
    }
    cout << "Total: Rp" << total << endl;
    cout << "Metode Pengiriman: " << pesanan[0].metode_pengiriman << endl; 
    cout << "Pesanan diproses. Terima kasih!\n";
}

int main() {
    vector<Pesanan> daftar_pesanan;
    int kode_counter = 1;
    int pilihan;
    bool selesai = false;

    while (!selesai) {
        cout << "\n=== MENU UTAMA ONLINE (WHATSAPP) ===\n";
        cout << "1. Terima Pesanan Baru\n";
        cout << "2. Edit Pesanan Online\n";
        cout << "3. Lihat Pesanan\n";
        cout << "4. Proses Pembayaran dan Selesai\n";
        cout << "Pilih opsi (1-4): ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        switch (pilihan) {
            case 1: { // Terima Pesanan Baru
                bool data_benar = false;
                while (!data_benar) {
                    Pesanan p;
                    p.kode = kode_counter++;
                    p.pembayaran_verifikasi = false; 
                    cout << "\nInput Pesanan Online:\n";
                    cout << "Nama menu: ";
                    getline(cin, p.nama_menu);
                    cout << "Jumlah: ";
                    cin >> p.jumlah;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Catatan: ";
                    getline(cin, p.catatan);

                    if (p.nama_menu == "Rye Bread") p.harga_per_item = 15000;
                    else if (p.nama_menu == "Croissant") p.harga_per_item = 20000;
                    else if (p.nama_menu == "Danish Pastry") p.harga_per_item = 5000;
                    else p.harga_per_item = 10000;

                    cout << "Data pesanan: " << p.nama_menu << " x" << p.jumlah 
                         << " (Rp" << (p.harga_per_item * p.jumlah) << ") Catatan: " << p.catatan << endl;

                    string konfirmasi;
                    cout << "Apakah data benar? (ya/tidak): ";
                    getline(cin, konfirmasi);
                    // ubah menjadi huruf kecil agar tidak case-sensitive
                    transform(konfirmasi.begin(), konfirmasi.end(), konfirmasi.begin(), ::tolower);

                    if (konfirmasi == "ya") {
                        daftar_pesanan.push_back(p);
                        data_benar = true;
                    } else if (konfirmasi == "tidak") {
                        cout << "Silakan input ulang data pesanan.\n";
                    } else {
                        cout << "Input tidak valid. Ketik 'ya' atau 'tidak'.\n";
                    }
                }
                break;
            }

            case 2: { // Edit Pesanan Online
                if (daftar_pesanan.empty()) {
                    cout << "Tidak ada pesanan untuk diedit.\n";
                    break;
                }
                cout << "Masukkan kode pesanan yang ingin diedit: ";
                int kode_edit;
                cin >> kode_edit;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                bool ditemukan = false;
                for (size_t i = 0; i < daftar_pesanan.size(); ++i) {
                    if (daftar_pesanan[i].kode == kode_edit) {
                        cout << "Edit Pesanan Online:\n";
                        cout << "Nama menu baru: ";
                        getline(cin, daftar_pesanan[i].nama_menu);
                        cout << "Jumlah baru: ";
                        cin >> daftar_pesanan[i].jumlah;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Catatan baru: ";
                        getline(cin, daftar_pesanan[i].catatan);
                        if (daftar_pesanan[i].nama_menu == "Rye Bread") daftar_pesanan[i].harga_per_item = 15000;
                        else if (daftar_pesanan[i].nama_menu == "Croissant") daftar_pesanan[i].harga_per_item = 20000;
                        else if (daftar_pesanan[i].nama_menu == "Danish Pastry") daftar_pesanan[i].harga_per_item = 5000;
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

            case 3: { // Lihat Pesanan
                if (daftar_pesanan.empty()) {
                    cout << "Tidak ada pesanan.\n";
                } else {
                    cout << "\n=== DAFTAR PESANAN ===\n";
                    for (size_t i = 0; i < daftar_pesanan.size(); ++i) {
                        cout << "Kode: " << daftar_pesanan[i].kode << " | Menu: " << daftar_pesanan[i].nama_menu 
                             << " | Jumlah: " << daftar_pesanan[i].jumlah << " | Harga: Rp" 
                             << (daftar_pesanan[i].harga_per_item * daftar_pesanan[i].jumlah) << " | Catatan: " << daftar_pesanan[i].catatan << endl;
                    }
                }
                break;
            }

            case 4: { // Proses Pembayaran dan Selesai
                if (daftar_pesanan.empty()) {
                    cout << "Tidak ada pesanan untuk diproses.\n";
                    break;
                }
                double total = hitungTotal(daftar_pesanan);
                cout << "\n=== PROSES PEMBAYARAN ===\n";
                cout << "Admin mengirim rekening/QRIS untuk total Rp" << total << endl;
                string transfer;
                cout << "Simulasi: Customer melakukan transfer (ya/tidak): ";
                getline(cin, transfer);
                transform(transfer.begin(), transfer.end(), transfer.begin(), ::tolower);

                if (transfer == "ya") {
                    cout << "Pembayaran diverifikasi oleh admin. Pembayaran berhasil!\n";
                    for (size_t i = 0; i < daftar_pesanan.size(); ++i) {
                        daftar_pesanan[i].pembayaran_verifikasi = true;
                    }
                    
                    int metode;
                    cout << "Pilih metode pengiriman (1=Pickup, 2=GoFood): ";
                    cin >> metode;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (metode == 1) {
                        for (size_t i = 0; i < daftar_pesanan.size(); ++i) {
                            daftar_pesanan[i].metode_pengiriman = "Pickup";
                        }
                    } else if (metode == 2) {
                        for (size_t i = 0; i < daftar_pesanan.size(); ++i) {
                            daftar_pesanan[i].metode_pengiriman = "GoFood";
                        }
                    } else {
                        cout << "Pilihan tidak valid, default ke Pickup.\n";
                        for (size_t i = 0; i < daftar_pesanan.size(); ++i) {
                            daftar_pesanan[i].metode_pengiriman = "Pickup";
                        }
                    }
                    
                    cout << "Pesanan diproses.\n";
                    cetakStrukAkhir(daftar_pesanan, total);
                    selesai = true;
                } else {
                    cout << "Transfer belum dilakukan. Kembali ke menu.\n";
                }
                break;
            }

            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    }

    cout << "FINISH\n";
}



