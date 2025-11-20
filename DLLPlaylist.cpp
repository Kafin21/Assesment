#include "DLLPlaylist.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool isEmpty(const ListDLL& L) {
    return L.head == nullptr;
}

void createList(ListDLL& L) {
    L.head = nullptr;
    L.tail = nullptr;
}

NodeDLL* allocate(const Song& S) {
    NodeDLL* node = new NodeDLL;
    node->info = S;
    node->prev = node->next = nullptr;
    return node;
}

void deallocate(NodeDLL* P) {
    delete P;
}

void insertFirst(ListDLL& L, const Song& S) {
    NodeDLL* node = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = node;
    } else {
        node->next = L.head;
        L.head->prev = node;
        L.head = node;
    }
}

void insertLast(ListDLL& L, const Song& S) {
    NodeDLL* node = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = node;
    } else {
        L.tail->next = node;
        node->prev = L.tail;
        L.tail = node;
    }
}

void insertAfter(ListDLL& L, NodeDLL* Q, const Song& S) {
    if (Q == nullptr) return;
    if (Q == L.tail) {
        insertLast(L, S);
        return;
    }
    NodeDLL* node = allocate(S);
    node->next = Q->next;
    node->prev = Q;
    Q->next->prev = node;
    Q->next = node;
}

void insertBefore(ListDLL& L, NodeDLL* Q, const Song& S) {
    if (Q == nullptr) return;
    if (Q == L.head) {
        insertFirst(L, S);
        return;
    }
    NodeDLL* node = allocate(S);
    node->prev = Q->prev;
    node->next = Q;
    Q->prev->next = node;
    Q->prev = node;
}

bool deleteFirst(ListDLL& L, Song& S) {
    if (isEmpty(L)) return false;
    NodeDLL* temp = L.head;
    S = temp->info;
    if (L.head == L.tail) {
        L.head = L.tail = nullptr;
    } else {
        L.head = temp->next;
        L.head->prev = nullptr;
    }
    deallocate(temp);
    return true;
}

bool deleteLast(ListDLL& L, Song& S) {
    if (isEmpty(L)) return false;
    NodeDLL* temp = L.tail;
    S = temp->info;
    if (L.head == L.tail) {
        L.head = L.tail = nullptr;
    } else {
        L.tail = temp->prev;
        L.tail->next = nullptr;
    }
    deallocate(temp);
    return true;
}

bool deleteAfter(ListDLL& L, NodeDLL* Q, Song& S) {
    if (Q == nullptr || Q->next == nullptr) return false;
    NodeDLL* target = Q->next;
    S = target->info;
    Q->next = target->next;
    if (target->next) target->next->prev = Q;
    if (target == L.tail) L.tail = Q;
    deallocate(target);
    return true;
}

bool deleteBefore(ListDLL& L, NodeDLL* Q, Song& S) {
    if (Q == nullptr || Q->prev == nullptr) return false;
    NodeDLL* target = Q->prev;
    S = target->info;
    Q->prev = target->prev;
    if (target->prev) target->prev->next = Q;
    if (target == L.head) L.head = Q;
    deallocate(target);
    return true;
}

bool updateAtPosition(ListDLL& L, int posisi, const Song& S) {
    if (posisi < 1) return false;
    NodeDLL* cur = L.head;
    int idx = 1;
    while (cur && idx < posisi) {
        cur = cur->next; idx++;
    }
    if (!cur) return false;
    cur->info = S;
    return true;
}

bool updateBefore(ListDLL& L, NodeDLL* Q, const Song& S) {
    if (Q == nullptr || Q->prev == nullptr) return false;
    Q->prev->info = S;
    return true;
}

double PopularityScoreOf(const Song& s) {
    return 0.8 * s.PlayCount + 20.0 * s.Rating;
}

void viewList(const ListDLL& L) {
    cout << fixed << setprecision(2);
    if (isEmpty(L)) {
        cout << "Playlist kosong.\n";
        return;
    }
    NodeDLL* cur = L.head;
    int idx = 1;
    cout << "Playlist:\n";
    while (cur) {
        double pop = PopularityScoreOf(cur->info);
        cout << idx << ". Title: " << cur->info.Title
             << " | Artist: " << cur->info.Artist
             << " | DurationSec: " << cur->info.DurationSec
             << " | PlayCount: " << cur->info.PlayCount
             << " | Rating: " << cur->info.Rating
             << " | PopularityScore: " << pop << '\n';
        cur = cur->next; idx++;
    }
}

void searchByPopularityRange(const ListDLL& L, double minScore, double maxScore) {
    cout << fixed << setprecision(2);
    if (isEmpty(L)) {
        cout << "Playlist kosong.\n";
        return;
    }
    NodeDLL* cur = L.head;
    int idx = 1;
    bool found = false;
    cout << "Hasil pencarian PopularityScore dalam rentang [" << minScore << ", " << maxScore << "]:\n";
    while (cur) {
        double pop = PopularityScoreOf(cur->info);
        if (pop >= minScore && pop <= maxScore) {
            cout << idx << ". Title: " << cur->info.Title
                 << " | Artist: " << cur->info.Artist
                 << " | PopularityScore: " << pop << '\n';
            found = true;
        }
        cur = cur->next; idx++;
    }
    if (!found) cout << "Tidak ada lagu yang memenuhi kriteria.\n";
}
