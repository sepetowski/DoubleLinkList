#pragma once
#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

template <class T>
class DoubleLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node( T d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoubleLinkedList();

    int getSize() const; // zwraca liczbê reprezentuj¹c¹ iloœæ elementów w liœcie
    T getFront(); // zwraca pierwszy element listy
    T getBack(); // zwraca ostatni element listy
    T getFromPosition(int pos); // zwraca element z danej pozycji

    bool contains(const T value); // sprawdza, czy element nale¿y do listy

    Node* getHead(); // odczytywanie wskaŸnika pierwszej pozycji
    Node* getTail(); // odczytywanie wskaŸnika ostatniej pozycji

    void pushFront(const T value); // dodawanie do listy na pocz¹tek
    void pushBack(const T value); // dodawanie do listy na koniec
    //void insertAt(int pos, const T value); // wstawianie na konkretnej pozycji
    void popFront(); // usuwa pierwszy element
    void popBack(); // usuwa ostatni element
    void clearAll(); // usuwa wszystkie elementy
    void printList() const; // wypisuje wszystkie elementy

    
};

#endif