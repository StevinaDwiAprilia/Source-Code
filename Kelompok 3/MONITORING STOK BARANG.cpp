#include <iostream>
using namespace std;

struct Barang {
    string nama;
    int harga;
    int stok;
};	

Barang barang[100];
int jumlahBarang = 0;

// Cari barang berdasarkan nama
int cariBarang(string nama) {
    for (int i = 0; i < jumlahBarang; i++) {
        if (barang[i].nama == nama)
            return i;
    }
    return -1;
}

// S2: Tambah Barang Baru
void tambahBarang() {
    cout << "\n=== Tambah Barang Baru ===\n";
    cout << "Masukan Jumlah Produk :";
    cin >> jumlahBarang;
    
    Barang Barang [jumlahBarang];
    
    for (int i = 0; i < jumlahBarang; i++) {
    	cout << "\nBarang ke-" << i + 1 << endl;
        cout << "Nama barang  : ";
        cin >> barang[i].nama;
        cout << "Harga        : ";
        cin >> barang[i].harga	;
        cout << "Stok         : ";
        cin >> barang[i].stok;
        cout << "barang berhasil ditambahkan" << endl;
	}
	}

// S3: Update Data / Stok Barang
void updateBarang() {
    string nama;
    cout << "\nMasukkan nama barang yang ingin diupdate: ";
    cin >> nama;

    int idx = cariBarang(nama);
    if (idx == -1) {
        cout << "Barang tidak ditemukan!\n";
        return;
    }

    string namaBaru;
    int hargaBaru, perubahanStok;

    cout << "Nama baru (jika tidak dirubah maka klik 'tidak'): ";
    cin >> namaBaru;
    if (namaBaru != "tidak")
        barang[idx].nama = namaBaru;

    cout << "Harga baru (0 jika tidak diubah): ";
    cin >> hargaBaru;
    if (hargaBaru > 0)
        barang[idx].harga = hargaBaru;

    // ===== TAMBAH / KURANG STOK =====
    int pilihan, jumlah;
    cout << "\nPilih perubahan stok:\n";
    cout << "1. Tambah Stok\n";
    cout << "2. Kurangi Stok\n";
    cout << "Pilihan: ";
    cin >> pilihan;

    if (pilihan == 1) {
        cout << "Jumlah stok yang ditambahkan: ";
        cin >> jumlah;
        barang[idx].stok += jumlah;
    }
    else if (pilihan == 2) {
        cout << "Jumlah stok yang dikurangi: ";
        cin >> jumlah;
        if (jumlah > barang[idx].stok) {
            cout << "Stok tidak mencukupi!\n";
            return;
        }
        barang[idx].stok -= jumlah;
    }
    else {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    cout << "Data barang berhasil diupdate.\n";
}

// S4: Lihat Data Barang
void tampilkanBarang() {
    cout << "\n=== Data Stok Barang ===\n";
    if (jumlahBarang == 0) {
        cout << "Belum ada data barang.\n";
        return;
    }

    for (int i = 0; i < jumlahBarang; i++) {
        cout << "------------------------\n";
        cout << "Nama  : " << barang[i].nama << endl;
        cout << "Harga : " << barang[i].harga << endl;
        cout << "Stok  : " << barang[i].stok << endl;
    }
}

// MAIN (S1, S5, S6)
int main() {
    int menu;
    char ulang = 'y';

    while (ulang == 'y' || ulang == 'Y') {
    	cout << "SELAMAT DATANG DI ROMDA FROZEN";
        cout << "\n=== MENU KELOLA STOK ===\n";
        cout << "1. Tambah Barang Baru\n";
        cout << "2. Update Data / Stok Barang	\n";
        cout << "3. Lihat Data Stok\n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1:
                tambahBarang();
                break;            
			case 2:
                updateBarang();
                break;
            case 3:
                tampilkanBarang();
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

        cout << "\nKembali ke menu kelola stok? (y/n): ";
        cin >> ulang;
    }

    cout << "\nSelesai. Data stok tersimpan.\n";
    return 0;
}

