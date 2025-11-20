#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <string>

struct Product {
    std::string Nama;
    std::string SKU;
    int Jumlah;
    double HargaSatuan;
    double DiskonPersen; 
};

struct NodeSLL {
    Product info;
    NodeSLL* next;
};

struct ListSLL {
    NodeSLL* head;
};

bool isEmpty(const ListSLL& L);
void createList(ListSLL& L);
NodeSLL* allocate(const Product& P);
void deallocate(NodeSLL* addr);

void insertFirst(ListSLL& L, const Product& P);
void insertLast(ListSLL& L, const Product& P);
void insertAfter(ListSLL& L, NodeSLL* Q, const Product& P);

bool deleteFirst(ListSLL& L, Product& P);
bool deleteLast(ListSLL& L, Product& P);
bool deleteAfter(ListSLL& L, NodeSLL* Q, Product& P);

bool updateAtPosition(ListSLL& L, int posisi, const Product& P);
void viewList(const ListSLL& L);
void searchByFinalPriceRange(const ListSLL& L, double minPrice, double maxPrice);

void MaxHargaAkhir(const ListSLL& L);

double HargaAkhirOf(const Product& p);

#endif 

