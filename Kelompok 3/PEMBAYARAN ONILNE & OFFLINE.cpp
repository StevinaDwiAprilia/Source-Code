#include <iostream>
using namespace std;

struct Barang {
    string nama;
    int harga;
    int stok;
};

Barang barang[100];
int jumlahBarang = 0;

// ===== DATA AWAL =====
void dataAwal() {
    barang[0] = {"Dimsum", 12000, 50};
    barang[1] = {"Baso", 15000, 40};
    barang[2] = {"Kentang", 10000, 30};
    barang[3] = {"Seafood", 30000, 40};
    jumlahBarang = 4;
}

// Cari barang
int cariBarang(string nama) {
    for (int i = 0; i < jumlahBarang; i++) {
        if (barang[i].nama == nama)
            return i;
    }
    return -1;
}

// ===== TRANSAKSI TUNAI (OFFLINE) =====
void transaksiTunai() {
    string pembeli, namaBarang;
    int jumlah, uang, total, kembalian;

    cout << "\n=== TRANSAKSI TUNAI (OFFLINE) ===\n";
    cout << "Nama Pembeli (opsional): ";
    cin >> pembeli;

    cout << "\nDaftar Barang:\n";
    for (int i = 0; i < jumlahBarang; i++) {
        cout << "- " << barang[i].nama
             << " | Harga: " << barang[i].harga
             << " | Stok: " << barang[i].stok << endl;
    }

    cout << "\nPilih barang: ";
    cin >> namaBarang;

    int idx = cariBarang(namaBarang);
    if (idx == -1) {
        cout << "Barang tidak ditemukan!\n";
        return;
    }

    cout << "Jumlah beli: ";
    cin >> jumlah;

    if (jumlah > barang[idx].stok) {
        cout << "Stok tidak mencukupi!\n";
        return;
    }

    // P1: Hitung tunai
    total = barang[idx].harga * jumlah;
    cout << "Total harga: Rp " << total << endl;

    cout << "Uang diterima: Rp ";
    cin >> uang;

    if (uang < total) {
        cout << "Uang tidak cukup!\n";
        return;
    }

    kembalian = uang - total;
    barang[idx].stok -= jumlah;

    // S3: Output struk
    cout << "\n=== STRUK BELANJA ===\n";
    cout << "Barang    : " << barang[idx].nama << endl;
    cout << "Jumlah    : " << jumlah << endl;
    cout << "Total     : Rp " << total << endl;
    cout << "Bayar     : Rp " << uang << endl;
    cout << "Kembalian : Rp " << kembalian << endl;
    cout << "Terima kasih telah berbelanja" << endl;
}

// ===== TRANSAKSI ONLINE (KIRIM) =====
void transaksiOnline() {
    string namaBarang;
    int jumlah, ongkir, total;

    cout << "\n=== TRANSAKSI ONLINE (KIRIM) ===\n";

    cout << "\nDaftar Barang:\n";
    for (int i = 0; i < jumlahBarang; i++) {
        cout << "- " << barang[i].nama
             << " | Harga: " << barang[i].harga
             << " | Stok: " << barang[i].stok << endl;
    }

    cout << "\nPilih barang: ";
    cin >> namaBarang;

    int idx = cariBarang(namaBarang);
    if (idx == -1) {
        cout << "Barang tidak ditemukan!\n";
        return;
    }

    cout << "Jumlah beli: ";
    cin >> jumlah;

    if (jumlah > barang[idx].stok) {
        cout << "Stok tidak mencukupi!\n";
        return;
    }

    cout << "Biaya ongkir: Rp ";
    cin >> ongkir;

    // P2: Hitung online
    total = (barang[idx].harga * jumlah) + ongkir;
    barang[idx].stok -= jumlah;

    // S5: Output invoice
    cout << "\n=== INVOICE ONLINE ===\n";
    cout << "Barang : " << barang[idx].nama << endl;
    cout << "Jumlah : " << jumlah << endl;
    cout << "Ongkir : Rp " << ongkir << endl;
    cout << "Total  : Rp " << total << endl;
    cout << "Status : Lunas & Siap Kirim\n";
}

// ===== Menu Awal =====
int main() {
    dataAwal();

    int menu;
    char ulang = 'y';

    while (ulang == 'y' || ulang == 'Y') {
        cout << "\n=== MENU PENJUALAN ===\n";
        cout << "1. Transaksi Tunai (Offline di Toko)\n";
        cout << "2. Transaksi Online (Pengiriman)\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1) {
            transaksiTunai();
        }
        else if (menu == 2) {
            transaksiOnline();
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }

        cout << "\nApakah ada transaksi baru? (y/n): ";
        cin >> ulang;
    }

    cout << "\nSelesai. Pendapatan tercatat otomatis.\n";
    return 0;
}

