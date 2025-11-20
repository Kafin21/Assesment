#include "QueuePengiriman.h"
#include <iostream>

using namespace std;

bool isEmpty(QueueEkspedisi& Q) {
    return Q.Head == -1 && Q.Tail == -1;
}

bool isFull(QueueEkspedisi& Q) {
    return Q.Tail == QUEUE_MAX - 1;
}

void createQueue(QueueEkspedisi& Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

bool enQueue(QueueEkspedisi& Q, const Paket& p) {
    if (isFull(Q)) return false;
    if (isEmpty(Q)) {
        Q.Head = 0;
        Q.Tail = 0;
        Q.dataPaket[0] = p;
        return true;
    }
    Q.Tail++;
    Q.dataPaket[Q.Tail] = p;
    return true;
}

bool deQueue(QueueEkspedisi& Q, Paket& p) {
    if (isEmpty(Q)) return false;
    p = Q.dataPaket[Q.Head];
    if (Q.Head == Q.Tail) {
        
        Q.Head = Q.Tail = -1;
    } else {
        Q.Head++;
    }
    return true;
}

void viewQueue(QueueEkspedisi& Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong.\n";
        return;
    }
    cout << "Daftar paket (posisi 1 = head):\n";
    for (int i = Q.Head, pos = 1; i <= Q.Tail; ++i, ++pos) {
        const Paket& p = Q.dataPaket[i];
        cout << pos << ". Resi: " << p.KodeResi
             << " | Pengirim: " << p.NamaPengirim
             << " | Berat(kg): " << p.BeratBarang
             << " | Tujuan: " << p.Tujuan << '\n';
    }
}

long long TotalBiayaPengiriman(const QueueEkspedisi& Q) {
    if (Q.Head == -1) return 0;
    long long total = 0;
    for (int i = Q.Head; i <= Q.Tail; ++i) {
        total += (long long)Q.dataPaket[i].BeratBarang * 8250LL;
    }
    return total;
}
