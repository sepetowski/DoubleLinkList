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
        Node(T d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;   //  pole przechowujące aktualną liczbę obiektów

public:
    DoubleLinkedList(); //  konstruktor domyślny
    DoubleLinkedList(T value);  //  konstruktor parametryczny
    DoubleLinkedList(const DoubleLinkedList<T>& other); //konstruktor kopiujący
    ~DoubleLinkedList();    //  destruktor

    int getSize() const; // zwraca liczbê reprezentuj¹c¹ iloœæ elementów w liœcie
    T getFront(); // zwraca pierwszy element listy
    T getBack(); // zwraca ostatni element listy
    T getFromPosition(int pos); // zwraca element z danej pozycji

    bool contains(const T value); // sprawdza, czy element nale¿y do listy

    Node* getHead(); // odczytywanie wskaŸnika pierwszej pozycji
    Node* getTail(); // odczytywanie wskaŸnika ostatniej pozycji

    void pushFront(const T value); // dodawanie do listy na pocz¹tek
    void pushBack(const T value); // dodawanie do listy na koniec
    void popFront(); // usuwa pierwszy element
    void popBack(); // usuwa ostatni element
    void clearAll(); // usuwa wszystkie elementy
    void printList() const; // wypisuje wszystkie elementy
    void insertAt(int pos, T value); // wstawianie na konkretnej pozycji

    // klasa iteratorów
	class Iterator {
	private:
		Node* current;
	public:
		Iterator(Node* node = nullptr) : current(node) {}   //  konstruktor iteratora
		Iterator& operator++();     //  przesuwa iterator o 1 do przodu
		Iterator& operator--();     //  przesuwa iterator o 1 wstecz
		T& operator*() const;       //  zwraca wartosc elementu
		bool operator==(const Iterator& other) const;      //  sprawdza czy elementy są równe
		bool operator!=(const Iterator& other) const;       //  sprawdza czy elementy są różne
		Iterator operator+(int n) const;    // tworzy nowy iterator -  przechodzi o n elementów w przód
		Iterator operator-(int n) const;    //  tworzy nowy iterator - przechodzi o n elementów wstecz
		Iterator& operator+=(int n);    //  przesuwa iterator o n elementów do przodu
		Iterator& operator-=(int n);    //  przesuwa iterator o n elementów wstecz
		bool operator>(const Iterator& other) const;    //  sprawdza czy porównywany iterator jest późniejszy
		bool operator<(const Iterator& other) const;    //  sprawdza czy porównywany iterator jest wcześniejszy
		bool operator>=(const Iterator& other) const;   //  sprawdza czy porównywany iterator jest późniejszy bądź wskazuje tą samą pozycje
		bool operator<=(const Iterator& other) const;   //  sprawdza czy porównywany iterator jest wcześniejszy bądź wskazuje tą samą pozycje
		Iterator& moveToStart();    //  przesuwa iterator na początek listy
		Iterator& moveToEnd();      //  przesuwa iterator na koniec listy
		Iterator& moveToIndex(int index);   //  przesuwa iterator na element listy o podanym indeksie
	};
};



#endif