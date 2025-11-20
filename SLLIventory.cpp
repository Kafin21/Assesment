#include "SLLIventory.h"
#include <iostream>
using namespace std;

bool isEmpty(const ListSLL& L) {
    return L.head == nullptr;
}

void createList(ListSLL& L) {
    L.head = nullptr;
}

NodeSLL* allocate(const Product& P) {
    NodeSLL* n = new NodeSLL;
    n->info = P;
    n->next = nullptr;
    return n;
}

void deallocate(NodeSLL* addr) {
    delete addr;
}

void insertFirst(ListSLL& L, const Product& P) {
    NodeSLL* n = allocate(P);
    n->next = L.head;
    L.head = n;
}

void insertLast(ListSLL& L, const Product& P) {
    NodeSLL* n = allocate(P);
    if (!L.head) {
        L.head = n;
    } else {
        NodeSLL* p = L.head;
        while (p->next) p = p->next;
        p->next = n;
    }
}

void insertAfter(ListSLL& L, NodeSLL* Q, const Product& P) {
    if (!Q) return;
    NodeSLL* n = allocate(P);
    n->next = Q->next;
    Q->next = n;
}

bool deleteFirst(ListSLL& L, Product& P) {
    if (!L.head) return false;
    NodeSLL* p = L.head;
    P = p->info;
    L.head = p->next;
    deallocate(p);
    return true;
}

bool deleteLast(ListSLL& L, Product& P) {
    if (!L.head) return false;

    NodeSLL *p = L.head, *q = nullptr;
    while (p->next) { q = p; p = p->next; }

    P = p->info;
    if (!q) L.head = nullptr;   
    else q->next = nullptr;

    deallocate(p);
    return true;
}

bool deleteAfter(ListSLL& L, NodeSLL* Q, Product& P) {
    if (!Q || !Q->next) return false;
    NodeSLL* t = Q->next;
    Q->next = t->next;
    P = t->info;
    deallocate(t);
    return true;
}

bool updateAtPosition(ListSLL& L, int posisi, const Product& P) {
    if (posisi < 1) return false;
    NodeSLL* p = L.head;
    int i = 1;

    while (p && i < posisi) {
        p = p->next;
        i++;
    }
    if (!p) return false;  

    p->info = P;
    return true;
}

double HargaAkhirOf(const Product& p) {
    return p.HargaSatuan * (1 - p.DiskonPersen / 100.0);
}

void viewList(const ListSLL& L) {
    if (!L.head) {
        cout << "List kosong.\n";
        return;
    }

    NodeSLL* p = L.head;
    int i = 1;

    while (p) {
        cout << i << ". " << p->info.Nama
             << " | SKU: " << p->info.SKU
             << " | HargaAkhir: " << HargaAkhirOf(p->info)
             << '\n';
        p = p->next;
        i++;
    }
}

void searchByFinalPriceRange(const ListSLL& L, double minPrice, double maxPrice) {
    NodeSLL* p = L.head;
    int idx = 1;
    bool ketemu = false;

    while (p) {
        double h = HargaAkhirOf(p->info);
        if (h >= minPrice && h <= maxPrice) {
            cout << idx << ". " << p->info.Nama
                 << " | HargaAkhir: " << h << '\n';
            ketemu = true;
        }
        p = p->next;
        idx++;
    }

    if (!ketemu) cout << "Tidak ada produk dalam rentang tersebut.\n";
}

void MaxHargaAkhir(const ListSLL& L) {
    if (!L.head) {
        cout << "List kosong.\n";
        return;
    }

    NodeSLL* p = L.head;
    double maks = HargaAkhirOf(p->info);

    for (; p; p = p->next) {
        double h = HargaAkhirOf(p->info);
        if (h > maks) maks = h;
    }

    cout << "Produk dengan Harga Akhir tertinggi (" << maks << "):\n";

    p = L.head;
    int idx = 1;
    while (p) {
        double h = HargaAkhirOf(p->info);
        if (h == maks) {
            cout << idx << ". " << p->info.Nama
                 << " | SKU: " << p->info.SKU
                 << '\n';
        }
        p = p->next;
        idx++;
    }
}

   
    
