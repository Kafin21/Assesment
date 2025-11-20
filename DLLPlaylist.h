#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <string>

struct Song {
    std::string Title;
    std::string Artist;
    int DurationSec;
    int PlayCount;
    double Rating; 
};

struct NodeDLL {
    Song info;
    NodeDLL* prev;
    NodeDLL* next;
};

struct ListDLL {
    NodeDLL* head;
    NodeDLL* tail;
};

bool isEmpty(const ListDLL& L);
void createList(ListDLL& L);
NodeDLL* allocate(const Song& S);
void deallocate(NodeDLL* P);

void insertFirst(ListDLL& L, const Song& S);
void insertLast(ListDLL& L, const Song& S);
void insertAfter(ListDLL& L, NodeDLL* Q, const Song& S);
void insertBefore(ListDLL& L, NodeDLL* Q, const Song& S);

bool deleteFirst(ListDLL& L, Song& S);
bool deleteLast(ListDLL& L, Song& S);
bool deleteAfter(ListDLL& L, NodeDLL* Q, Song& S);
bool deleteBefore(ListDLL& L, NodeDLL* Q, Song& S);

bool updateAtPosition(ListDLL& L, int posisi, const Song& S);
bool updateBefore(ListDLL& L, NodeDLL* Q, const Song& S);

void viewList(const ListDLL& L);
void searchByPopularityRange(const ListDLL& L, double minScore, double maxScore);

double PopularityScoreOf(const Song& s);

#endif 
