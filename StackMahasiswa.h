#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>

const int STACK_MAX = 6;

struct Mahasiswa {
    std::string Nama;
    std::string NIM;
    double NilaiTugas;
    double NilaiUTS;
    double NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[STACK_MAX];
    int Top; 
};

bool isEmpty(StackMahasiswa& S);
bool isFull(StackMahasiswa& S);
void createStack(StackMahasiswa& S);
bool Push(StackMahasiswa& S, const Mahasiswa& m);
bool Pop(StackMahasiswa& S, Mahasiswa& m);
bool Update(StackMahasiswa& S, int posisi, const Mahasiswa& m);
void View(StackMahasiswa& S);
void SearchNilaiAkhir(StackMahasiswa& S, double minVal, double maxVal);
double NilaiAkhirOf(const Mahasiswa& m);
void MaxNilaiAkhir(StackMahasiswa& S);

#endif 
