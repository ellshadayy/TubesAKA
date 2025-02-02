#include <iostream>
#include "MataKuliah.h"
#include "mahasiswa.h"
#include "relasi.h"
#include "MLL.h"

using namespace std;

void tambahMahasiswa(list_Mhs &LMhs) {
     mahasiswa mhs;
    cout << "Masukkan NIM: ";
    cin >> mhs.nim;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, mhs.nama);
    cout << "Masukkan Jurusan: ";
    getline(cin, mhs.jurusan);
    cout << "Masukkan Kelas: ";
    cin >> mhs.kelas;
    cout << "Masukkan Semester: ";
    cin >> mhs.semester;
    adr_mhs p = newElmListMhs(mhs);
    insertLastMhs(LMhs, p);
    cout << "Mahasiswa berhasil ditambahkan.\n";

    // Panggil fungsi printMahasiswa untuk menampilkan data
    cout << "\nData Mahasiswa Saat Ini:\n";
    printMhs(LMhs);
}

void tambahMataKuliah(list_Matkul &LMK) {
    mataKuliah mk;
    cout << "Masukkan Kode Mata Kuliah: ";
    cin >> mk.kodeMatkul;
    cout << "Masukkan Nama Mata Kuliah: ";
    cin.ignore();
    getline(cin, mk.namaMatkul);
    cout << "Masukkan SKS: ";
    cin >> mk.sks;
    adr_matkul p = newElmListMK(mk);
    insertLastMK(LMK, p);
    cout << "Mata Kuliah berhasil ditambahkan.\n";

    cout <<"\nData Mata Kuliah Saat Ini:\n";
    printListMatkul(LMK);
}

void buatRelasi(listRelasi &LR, list_Mhs &LMhs, list_Matkul &LMK) {
    string namaMhs, namaMK;
    cout << "Masukkan Nama Mahasiswa: ";
    cin.ignore();
    getline(cin, namaMhs);
    cout << "Masukkan Nama Mata Kuliah: ";
    getline(cin, namaMK);
    adr_mhs mhs = findMhs(LMhs, namaMhs);
    adr_matkul mk = findMatkul(LMK, namaMK);

    if (mhs != NULL && mk != NULL) {
        // Hitung total SKS yang sudah diambil mahasiswa
        int totalSKS = 0;
        adr_relasi rl = LR.first;
        while (rl != NULL) {
            if (rl->relasiMhs == mhs) {
                totalSKS += rl->relasiMK->info.sks;
            }
            rl = rl->next;
        }

        // Periksa apakah penambahan mata kuliah baru akan melebihi 24 SKS
        if (totalSKS + mk->info.sks <= 24) {
            adr_relasi newRelasi = newElmListRelasi(mhs, mk);
            insertLastRelasi(LR, newRelasi);
            cout << "Relasi berhasil dibuat.\n";
        } else {
            cout << "Gagal: Mahasiswa ini sudah mengambil total SKS sebesar " << totalSKS
                 << ". Penambahan mata kuliah ini akan melebihi batas 24 SKS.\n";
        }
    } else {
        cout << "Mahasiswa atau Mata Kuliah tidak ditemukan.\n";
    }
}


void hapusMahasiswa(list_Mhs &LMhs, listRelasi &LR) {
    string namaMhs;
    cout << "Masukkan Nama Mahasiswa yang akan dihapus: ";
    cin.ignore();
    getline(cin, namaMhs);
    adr_mhs mhs = findMhs(LMhs, namaMhs);
    if (mhs != NULL) {
        adr_relasi rl = LR.first;
        while (rl != NULL) {
            if (rl->relasiMhs == mhs) {
                deleteFirstRelasi(LR, rl);
            }
            rl = rl->next;
        }
        deleteFirstMhs(LMhs, mhs);
        cout << "Mahasiswa berhasil dihapus.\n";
    } else {
        cout << "Mahasiswa tidak ditemukan.\n";
    }
}

void hapusMataKuliah(list_Matkul &LMK, listRelasi &LR) {
    string namaMK;
    cout << "Masukkan Nama Mata Kuliah yang akan dihapus: ";
    cin.ignore();
    getline(cin, namaMK);
    adr_matkul mk = findMatkul(LMK, namaMK);
    if (mk != NULL) {
        adr_relasi rl = LR.first;
        while (rl != NULL) {
            if (rl->relasiMK == mk) {
                deleteFirstRelasi(LR, rl);
            }
            rl = rl->next;
        }
        deleteFirstMK(LMK, mk);
        cout << "Mata Kuliah berhasil dihapus.\n";
    } else {
        cout << "Mata Kuliah tidak ditemukan.\n";
    }
}

void tampilkanMahasiswaDanMatkul(listRelasi &LR) {
    printRelasi(LR);
}

void tampilkanMahasiswaByMatkul(listRelasi &LR, list_Matkul &LMK) {
    string namaMK;
    cout << "Masukkan Nama Mata Kuliah: ";
    cin.ignore();
    getline(cin, namaMK);
    adr_matkul mk = findMatkul(LMK, namaMK);
    if (mk != NULL) {
        adr_relasi rl = LR.first;
        while (rl != NULL) {
            if (rl->relasiMK == mk) {
                cout << "Mahasiswa: " << rl->relasiMhs->info.nama << endl;
            }
            rl = rl->next;
        }
    } else {
        cout << "Mata Kuliah tidak ditemukan.\n";
    }
}

void tampilkanMatkulByMahasiswa(listRelasi &LR, list_Mhs &LMhs) {
    string namaMhs;
    cout << "Masukkan Nama Mahasiswa: ";
    cin.ignore();
    getline(cin, namaMhs);
    adr_mhs mhs = findMhs(LMhs, namaMhs);
    if (mhs != NULL) {
        adr_relasi rl = LR.first;
        while (rl != NULL) {
            if (rl->relasiMhs == mhs) {
                cout << "Mata Kuliah yang diambil: " << rl->relasiMK->info.namaMatkul << endl;
            }
            rl = rl->next;
        }
    } else {
        cout << "Mahasiswa tidak ditemukan.\n";
    }
}

void matkulTerpopuler(listRelasi &LR, list_Matkul &LMK) {
    adr_matkul mk = LMK.first;
    int maxPeminat = 0, minPeminat = INT_MAX;
    string populer, tidakPopuler;
    while (mk != NULL) {
        int count = 0;
        adr_relasi rl = LR.first;
        while (rl != NULL) {
            if (rl->relasiMK == mk) {
                count++;
            }
            rl = rl->next;
        }
        if (count > maxPeminat) {
            maxPeminat = count;
            populer = mk->info.namaMatkul;
        }
        if (count < minPeminat) {
            minPeminat = count;
            tidakPopuler = mk->info.namaMatkul;
        }
        mk = mk->next;
    }
    cout << "Mata Kuliah Terpopuler: " << populer << " dengan " << maxPeminat << " peminat.\n";
    cout << "Mata Kuliah Paling Sedikit Peminat: " << tidakPopuler << " dengan " << minPeminat << " peminat.\n";
}

void urutkanMahasiswa(list_Mhs &LMhs) {
    // Algoritma pengurutan sederhana berbasis atribut tertentu (contoh NIM)
    if (LMhs.first != NULL) {
        for (adr_mhs i = LMhs.first; i->next != NULL; i = i->next) {
            for (adr_mhs j = i->next; j != NULL; j = j->next) {
                if (i->info.nim > j->info.nim) {
                    swap(i->info, j->info);
                }
            }
        }
    }
    cout << "Nama Mahasiswa berdasarkan NIM.\n";
    cout << "\nDaftar Mahasiswa Terurut:\n";
    adr_mhs p = LMhs.first;
    while (p != NULL) {
        cout << "NIM       : " << p->info.nim << endl;
        cout << "-------------------------\n";
        p = p->next;
    }
}

void programUtama() {
    list_Mhs LMhs;
    list_Matkul LMK;
    listRelasi LR;
    createListMhs(LMhs);
    createListMk(LMK);
    createListRelasi(LR);

    int pilihan;
    do {
        cout << "--- Program Manajemen Mahasiswa dan Mata Kuliah ---\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tambah Mata Kuliah\n";
        cout << "3. Buat Relasi\n";
        cout << "4. Hapus Mahasiswa\n";
        cout << "5. Hapus Mata Kuliah\n";
        cout << "6. Tampilkan Mahasiswa dan Mata Kuliah\n";
        cout << "7. Tampilkan Mahasiswa berdasarkan Mata Kuliah\n";
        cout << "8. Tampilkan Mata Kuliah berdasarkan Mahasiswa\n";
        cout << "9. Mata Kuliah Terpopuler\n";
        cout << "10. Urutkan Mahasiswa\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahMahasiswa(LMhs);
                break;
            case 2:
                tambahMataKuliah(LMK);
                break;
            case 3:
                buatRelasi(LR, LMhs, LMK);
                break;
            case 4:
                hapusMahasiswa(LMhs, LR);
                break;
            case 5:
                hapusMataKuliah(LMK, LR);
                break;
            case 6:
                tampilkanMahasiswaDanMatkul(LR);
                break;
            case 7:
                tampilkanMahasiswaByMatkul(LR, LMK);
                break;
            case 8:
                tampilkanMatkulByMahasiswa(LR, LMhs);
                break;
            case 9:
                matkulTerpopuler(LR, LMK);
                break;
            case 10:
                urutkanMahasiswa(LMhs);
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
}


