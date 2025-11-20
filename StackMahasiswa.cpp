#include "StackMahasiswa.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool isEmpty(StackMahasiswa& S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa& S) {
    return S.Top == STACK_MAX - 1;
}

void createStack(StackMahasiswa& S) {
    S.Top = -1;
}

bool Push(StackMahasiswa& S, const Mahasiswa& m) {
    if (isFull(S)) return false;
    S.Top++;
    S.dataMahasiswa[S.Top] = m;
    return true;
}

bool Pop(StackMahasiswa& S, Mahasiswa& m) {
    if (isEmpty(S)) return false;
    m = S.dataMahasiswa[S.Top];
    S.Top--;
    return true;
}

bool Update(StackMahasiswa& S, int posisi, const Mahasiswa& m) {
    if (posisi < 1 || posisi > S.Top + 1) return false;
    int idx = posisi - 1;
    S.dataMahasiswa[idx] = m;
    return true;
}

double NilaiAkhirOf(const Mahasiswa& m) {
    return 0.2 * m.NilaiTugas + 0.4 * m.NilaiUTS + 0.4 * m.NilaiUAS;
}

void View(StackMahasiswa& S) {
    cout << fixed << setprecision(2);
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }
    cout << "Isi stack (posisi 1 = bottom):\n";
    for (int i = 0; i <= S.Top; ++i) {
        const Mahasiswa& m = S.dataMahasiswa[i];
        cout << (i+1) << ". Nama: " << m.Nama
             << " | NIM: " << m.NIM
             << " | NilaiTugas: " << m.NilaiTugas
             << " | NilaiUTS: " << m.NilaiUTS
             << " | NilaiUAS: " << m.NilaiUAS
             << " | NilaiAkhir: " << NilaiAkhirOf(m) << '\n';
    }
}

void SearchNilaiAkhir(StackMahasiswa& S, double minVal, double maxVal) {
    cout << fixed << setprecision(2);
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }
    bool found = false;
    cout << "Hasil pencarian NilaiAkhir dalam rentang [" << minVal << ", " << maxVal << "]:\n";
    for (int i = 0; i <= S.Top; ++i) {
        double na = NilaiAkhirOf(S.dataMahasiswa[i]);
        if (na >= minVal && na <= maxVal) {
            cout << (i+1) << ". Nama: " << S.dataMahasiswa[i].Nama
                 << " | NIM: " << S.dataMahasiswa[i].NIM
                 << " | NilaiAkhir: " << na << '\n';
            found = true;
        }
    }
    if (!found) cout << "Tidak ada mahasiswa yang memenuhi kriteria.\n";
}

void MaxNilaiAkhir(StackMahasiswa& S) {
    cout << fixed << setprecision(2);
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }
    double maxVal = -1e18;
    for (int i = 0; i <= S.Top; ++i) {
        double na = NilaiAkhirOf(S.dataMahasiswa[i]);
        if (na > maxVal) maxVal = na;
    }
    cout << "Mahasiswa dengan NilaiAkhir terbesar (" << maxVal << "):\n";
    for (int i = 0; i <= S.Top; ++i) {
        double na = NilaiAkhirOf(S.dataMahasiswa[i]);
        if (abs(na - maxVal) < 1e-9) {
            cout << (i+1) << ". Nama: " << S.dataMahasiswa[i].Nama
                 << " | NIM: " << S.dataMahasiswa[i].NIM
                 << " | NilaiAkhir: " << na << '\n';
        }
    }
}
