#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include<string>
#include<iostream>
using namespace std;

void tambahMahasiswa(list_Mhs &LMhs);
void tambahMataKuliah(list_Matkul &LMK);
void buatRelasi(listRelasi &LR, list_Mhs &LMhs, list_Matkul &LMK);
void hapusMahasiswa(list_Mhs &LMhs, listRelasi &LR);
void hapusMataKuliah(list_Matkul &LMK, listRelasi &LR);
void tampilkanMahasiswaDanMatkul(listRelasi &LR);
void tampilkanMahasiswaByMatkul(listRelasi &LR, list_Matkul &LMK);
void tampilkanMatkulByMahasiswa(listRelasi &LR, list_Mhs &LMhs);
void matkulTerpopuler(listRelasi &LR, list_Matkul &LMK);
void urutkanMahasiswa(list_Mhs &LMhs);
void programUtama();
#endif // MLL_H
