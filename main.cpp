#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
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

// Fungsi Tidur
void Tidur(pet &p, aktivitas* &head) {
    int pilih;

    while (true) {
        cout << "\n=== PILIH WAKTU TIDUR ===\n";
        cout << "1. 5 detik (15 energi)\n";
        cout << "2. 10 detik (35 energi)\n";
        cout << "3. 15 detik (50 energi)\n";
        cout << "4. Kembali\n";
        cout << "Pilihan: ";
        cin >> pilih;

        int durasi = 0, energi_dapat = 0;

        if (pilih == 4) return; // Balik ke menu utama

        if (pilih == 1) { durasi = 5; energi_dapat = 15; }
        else if (pilih == 2) { durasi = 10; energi_dapat = 35; }
        else if (pilih == 3) { durasi = 15; energi_dapat = 50; }
        else {
            cout << "Pilihan tidak valid!\n";
            continue;
        }

        cout << p.nama_pet << " sedang tidur...\n";

        for (int i = durasi; i > 0; i--) {
            cout << "Sisa waktu: " << i << " detik\r";
            cout.flush();
            this_thread::sleep_for(chrono::seconds(1));
        }

        p.energi += energi_dapat;
        if (p.energi > 100) p.energi = 100;

        p.lapar += 5;
        if (p.lapar > 100) p.lapar = 100;

        TambahAktivitas(head, "Tidur " + to_string(durasi) + " detik");

        cout << "\nSelesai tidur!\n";
        return; // Balik ke menu utama juga
    }
}

int main() {
    pet myPet;
    aktivitas* head = NULL;

    srand(time(0)); // Random poin awal pet

    cout << "====== PET SIMULATOR ======\n";
    cout << "Masukan jenis pet: ";
    cin >> myPet.jenis;
    cout << "Masukan nama pet: ";
    cin >> myPet.nama_pet;

    // Random poin awal pet (rentang 40–60)
    myPet.lapar = rand() % 21 + 40;
    myPet.bahagia = rand() % 21 + 40;
    myPet.energi = rand() % 21 + 40;

    myPet.koin = 50;

    myPet.apel = 0;
    myPet.daging = 0;
    myPet.roti = 0;

    cout << "\nPet memiliki kondisi awal acak!\n";

    int pilihan;
    bool jalan = true;

    while (jalan) {
        cout << "\n=== MENU ===\n";
        cout << "1. Lihat Status\n";
        cout << "2. Makan\n";
        cout << "3. Beli Makanan\n";
        cout << "4. Tidur\n";
        cout << "5. Lihat Aktivitas\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n=== STATUS ===\n";
                cout << "Lapar   : " << myPet.lapar << endl;
                cout << "Bahagia : " << myPet.bahagia << endl;
                cout << "Energi  : " << myPet.energi << endl;
                cout << "Koin    : " << myPet.koin << endl;
                break;

            case 2:
                Makan(myPet, head);
                break;

            case 3:
                BeliMakanan(myPet, head);
                break;

            case 4:
                Tidur(myPet, head);
                break;

            case 5:
                LihatAktivitas(head);
                break;

            case 6:
                jalan = false;
                cout << "Anda telah keluar dari game. Terima kasih telah memainkan Pet Simulator ^-^\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}
