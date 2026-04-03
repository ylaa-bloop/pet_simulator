#include <iostream>
#include <string>
using namespace std;

struct pet{
    string jenis;
    string nama_pet;
    int lapar;
    int bahagia;
    int energi;
    int koin;
    int makanan;
    int apel;
    int daging;
    int roti;
};

struct aktivitas{
    string pesan;
    aktivitas* next;
};

// Create
void TambahAktivitas(aktivitas* &head, string keterangan){
aktivitas* baru = new aktivitas;
baru-> pesan = keterangan;
baru -> next = head;
head = baru;
}

void BeliMakanan(pet &p, aktivitas* &head){
    int pilih;

    cout << "=== TOKO MAKANAN ===";
    cout << "1. Apel (Harga: 5, Lapar -5)";
    cout << "2. Daging (Harga: 15, Lapar -15)";
    cout << "3. Roti (Harga: 7, Lapar: -10)";
    cout << "Pilih makanan yang ingin dibeli(masukkan angka): ";
    cin >> pilih;

    if (pilih == 1){
        if (p.koin >= 5){
            p.koin -= 5;
            p.apel++;
            TambahAktivitas(head, "Membeli apel");
        } 
        else cout << "Koin tidak cukup!";
    }
    else if (pilih == 2){
        if (p.koin >= 15){
            p.koin -= 15;
            p.daging++;
            TambahAktivitas(head, "Membeli daging");
        } else cout << "Koin tidak cukup!\n";
    }
    else if (pilih == 3){
        if (p.koin >= 7){
            p.koin -= 7;
            p.roti++;
            TambahAktivitas(head, "Membeli roti");
        } else cout << "Koin tidak cukup!\n";
    }
    else {
        cout << "Makanan tidak tersedia!\n";
    }
}

// Read
void LihatAktivitas(aktivitas* &head){
    cout << "\n ====RIWAYAT AKTIVITAS PET====" << endl;
    aktivitas* temp = head;
    if (!temp) cout << "Belum ada aktivitas yang dilakukan" << endl;
    while (temp) {
        cout << "- " << temp->pesan << endl;
        temp = temp-> next;
    }
    cout << "==============================" << endl;
}

// update
void Makan(pet &p, aktivitas* &head){
    int pilih;
    cout << "=== PILIH MAKANAN ===";
    cout << "1. Apel (stok: " << p.apel << ")";
    cout << "2. Daging (stok: " << p.daging << ")";
    cout << "3. Roti (stok: " << p.roti<< ")";
    cout << "Pilih makanan: ";
    cin >> pilih;

    if (pilih == 1){
        if (p.apel > 0){
            p.apel--;
            p.lapar -= 5;
            TambahAktivitas(head, "Memberi apel");
        }
        else{
            cout << "Apel habis!";
        }
    }
    else if (pilih == 2){
        if (p.daging > 0){
            p.daging--;
            p.lapar -= 15;
            TambahAktivitas(head, "Memberi daging");
        }
        else {
            cout << "Daging habis!";
        }
    }
    else if (pilih == 3){
        if (p.roti > 0){
            p.roti--;
            p.lapar -= 7;
            TambahAktivitas(head, "Memberi roti");
        }
        else {
            cout << "Roti habis!";
        }
    }
    else {
        cout << "Pilihan tidak valid!";
    }

    if (p.lapar < 0) p.lapar = 0;
}

int main() {
    pet myPet;
    
    cout << "====== PET SIMULATOR ======" << endl;
    cout << "Masukan jenis pet :" << endl;
    cin >> myPet.jenis;
    cout << "Masukan nama pet :" << endl;
    cin >> myPet.nama_pet;

   
 };
