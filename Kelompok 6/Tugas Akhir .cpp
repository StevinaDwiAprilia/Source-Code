#include <iostream> 
using namespace std; 
 
class KasirAngkringan { private:     int harga, jumlah;     int subtotal;     int total;     float diskon;     int uangPembeli;     int kembalian; 
 
public: 
    KasirAngkringan() { 
        total = 0;         diskon = 0; 
    } 
 
    void inputBarang() {         cout << "\nInput harga barang : ";         cin >> harga; 
        cout << "Input jumlah barang : ";         cin >> jumlah; 
 
        subtotal = harga * jumlah;         total += subtotal; 
    } 
 
    bool tambahPesanan() { 
        char pilih; 
        cout << "Tambah pesanan lagi? (y/n): "; 
        cin >> pilih; 
        return (pilih == 'y' || pilih == 'Y'); 
    } 
 
    void tampilSubtotal() { 
        cout << "\nSubtotal sementara : Rp " << total << endl; 
    } 
 
 
    void prosesDiskon() {         char pilih; 
        cout << "Apakah ada diskon? (y/n): "; 
        cin >> pilih; 
 
        if (pilih == 'y' || pilih == 'Y') {             cout << "Masukkan diskon (%) : ";             cin >> diskon; 
            total = total - (total * diskon / 100); 
        } 
    } 
 
 
    void inputPembayaran() {    
	     cout << "Masukkan uang pembeli : Rp ";      
		    cin >> uangPembeli; 
    } 
 
 
    void hitungKembalian() { 
        kembalian = uangPembeli - total; 
    } 
 
    void tampilkanStruk() { 
        cout << "\n===== STRUK ANGKRINGAN =====\n"; 
        cout << "Total Belanja   : Rp " << total << endl;         cout << "Uang Pembeli   : Rp " << uangPembeli << endl;         cout << "Kembalian      : Rp " << kembalian << endl; 
        cout << "===========================\n"; 
    } 
}; 
 
int main() {     KasirAngkringan kasir; 
    char ulang; 
 
    cout << "===== APLIKASI KASIR ANGKRINGAN =====\n"; 
 
    do { 
        kasir.inputBarang();    
		} while (kasir.tambahPesanan()); 
 
    kasir.tampilSubtotal();  
	kasir.prosesDiskon();
	kasir.inputPembayaran();  
	kasir.hitungKembalian(); 
    kasir.tampilkanStruk(); 
 
    return 0; 
} 

