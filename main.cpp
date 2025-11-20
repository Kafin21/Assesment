#include <iostream>
#include <iomanip>

#include "SLLIventory.h"
#include "DLLPlaylist.h"
#include "StackMahasiswa.h"
#include "QueuePengiriman.h"

using namespace std;

int main() {
    cout << fixed << setprecision(2);

    ListSLL L1;
    createList(L1);

    Product p1 = {"Pulpen", "A001", 20, 2500.0, 0.0};
    Product p2 = {"Buku Tulis", "A002", 15, 5000.0, 10.0};
    Product p3 = {"Penghapus", "A003", 30, 1500.0, 0.0};

    insertLast(L1, p1);
    insertLast(L1, p2);
    insertLast(L1, p3);

    viewList(L1);

    Product removed;
    deleteFirst(L1, removed);
    viewList(L1);

    Product newP = {"Stabilo", "A010", 40, 9000.0, 5.0};
    updateAtPosition(L1, 2, newP);
    viewList(L1);

    searchByFinalPriceRange(L1, 2000.0, 7000.0);
    MaxHargaAkhir(L1);


    ListDLL L2;
    createList(L2);

    Song s1 = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    Song s2 = {"Langkahmu", "Delta", 185, 320, 4.8};
    Song s3 = {"Hujan Minggu", "Arka", 240, 90, 3.9};

    insertLast(L2, s1);
    insertLast(L2, s2);
    insertLast(L2, s3);

    viewList(L2);

    Song removedS;
    deleteLast(L2, removedS);
    viewList(L2);

    Song newS = {"Pelita", "Luna", 200, 260, 4.5};
    updateAtPosition(L2, 2, newS);
    viewList(L2);

    NodeDLL* cur = L2.head;
    int idx = 1;
    while (cur && idx < 2) { cur = cur->next; idx++; }

    if (cur) {
        Song sBefore = {"Senandung", "Mira", 175, 120, 4.0};
        insertBefore(L2, cur, sBefore);
        viewList(L2);

        Song sUpdateBefore = {"BaruBefore", "ArtistX", 180, 200, 4.1};
        updateBefore(L2, cur, sUpdateBefore);
        viewList(L2);

        NodeDLL* pos3 = L2.head;
        idx = 1;
        while (pos3 && idx < 3) { pos3 = pos3->next; idx++; }

        if (pos3) {
            Song tmp;
            deleteBefore(L2, pos3, tmp);
            viewList(L2);
        }
    }

    searchByPopularityRange(L2, 150.0, 300.0);


    StackMahasiswa S;
    createStack(S);

    Mahasiswa m1 = {"Venti", "11111", 75.7, 82.1, 65.5};
    Mahasiswa m2 = {"Xiao", "22222", 87.4, 88.9, 81.9};
    Mahasiswa m3 = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    Mahasiswa m4 = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    Mahasiswa m5 = {"Lynette", "55555", 77.7, 65.4, 79.9};
    Mahasiswa m6 = {"Chasca", "66666", 99.9, 93.6, 87.3};

    Push(S, m1);
    Push(S, m2);
    Push(S, m3);
    Push(S, m4);
    Push(S, m5);
    Push(S, m6);

    View(S);

    Mahasiswa popped;
    Pop(S, popped);
    View(S);

    Mahasiswa mz = {"Heizou", "77777", 99.9, 88.8, 77.7};
    Update(S, 3, mz);
    View(S);

    SearchNilaiAkhir(S, 85.5, 95.5);
    MaxNilaiAkhir(S);


    QueueEkspedisi Q;
    createQueue(Q);

    Paket pk1 = {"123456", "Hutao", 14, "Sumeru"};
    Paket pk2 = {"234567", "Ayaka", 10, "Fontaine"};
    Paket pk3 = {"345678", "Bennet", 7, "Natlan"};
    Paket pk4 = {"456789", "Furina", 16, "Liyue"};
    Paket pk5 = {"567890", "Nefer", 6, "Inazuma"};

    enQueue(Q, pk1);
    enQueue(Q, pk2);
    enQueue(Q, pk3);
    enQueue(Q, pk4);
    enQueue(Q, pk5);

    viewQueue(Q);

    Paket pktRemoved;
    deQueue(Q, pktRemoved);
    viewQueue(Q);

    long long totalBiaya = TotalBiayaPengiriman(Q);
    cout << "Total biaya: Rp " << totalBiaya << endl;

    return 0;
}

