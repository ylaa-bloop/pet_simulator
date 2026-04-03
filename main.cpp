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
};

struct aktivitas{
    string pesan;
    aktivitas* next;
};

void TambahAktivitas(aktivitas* &head, string keterangan){
aktivitas* baru = new aktivitas;
baru-> pesan = keterangan;
baru -> next = head;
head = baru;
}

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

int main() {
    pet myPet;
    
    cout << "====== PET SIMULATOR ======" << endl;
    cout << "Masukan jenis pet :" << endl;
    cin >> myPet.jenis;
    cout << "Masukan nama pet :" << endl;
    cin >> myPet.nama_pet;

   
 };
