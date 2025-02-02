#include <iostream>
#include "MataKuliah.h"
#include "mahasiswa.h"
#include "relasi.h"
#include "MLL.h"

using namespace std;

int main() {
    list_Mhs LMhs;
    list_Matkul LMK;
    listRelasi LR;

    // Inisialisasi list
    createListMhs(LMhs);
    createListMk(LMK);
    createListRelasi(LR);

    int pilihan;
    do {
        cout << "\n=== Data Registrasi Mahasiswa ===\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tambah Mata Kuliah\n";
        cout << "3. Buat Relasi Mahasiswa dan Mata Kuliah\n";
        cout << "4. Hapus Mahasiswa\n";
        cout << "5. Hapus Mata Kuliah\n";
        cout << "6. Tampilkan Semua Mahasiswa dan Mata Kuliah yang Diambil\n";
        cout << "7. Tampilkan Mahasiswa yang Mengambil Mata Kuliah Tertentu\n";
        cout << "8. Tampilkan Mata Kuliah yang Diambil oleh Mahasiswa Tertentu\n";
        cout << "9. Tampilkan Mata Kuliah dengan Peminat Terbanyak dan Paling Sedikit\n";
        cout << "10. Urutkan Data Mahasiswa\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
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
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 0);

    return 0;
}
