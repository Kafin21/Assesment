#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <string>

struct Paket {
    std::string KodeResi;
    std::string NamaPengirim;
    int BeratBarang; 
    std::string Tujuan;
};

const int QUEUE_MAX = 5;

struct QueueEkspedisi {
    Paket dataPaket[QUEUE_MAX];
    int Head; 
    int Tail; 
};

bool isEmpty(QueueEkspedisi& Q);
bool isFull(QueueEkspedisi& Q);
void createQueue(QueueEkspedisi& Q);
bool enQueue(QueueEkspedisi& Q, const Paket& p);
bool deQueue(QueueEkspedisi& Q, Paket& p);
void viewQueue(QueueEkspedisi& Q);

long long TotalBiayaPengiriman(const QueueEkspedisi& Q); 

#endif 
