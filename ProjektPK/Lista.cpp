#include "Lista.h"
#include <iostream>
#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

template <class T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {

}
//OK

template <class T>
int DoubleLinkedList<T>::getSize() const {
    std::cout << "Rozmiar listy wynosi: " << size << std::endl;
    return size;
}

template <class T>
T DoubleLinkedList<T>::getFront() {
    if (head == nullptr) {
        std::cerr << "Lista pusta!\n";
        return -1;
    }
    return head->data;
}

template <class T>
T DoubleLinkedList<T>::getBack() {
    if (tail == nullptr) {
        std::cerr << "Lista pusta!\n";
        return -1;
    }
    return tail->data;
}
template <class T>
T DoubleLinkedList<T>::getFromPosition(int pos) {
    if (pos < 0 || pos >= size) {
        std::cerr << "Invalid position!\n";
        return -1;
    }
    Node* curr = head;
    for (int i = 0; i < pos; i++) {
        curr = curr->next;
    }
    return curr->data;
}
//ok
template <class T>
bool DoubleLinkedList<T>::contains(const T value) {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == value) {
            std::cout << "Podany elemnt zawiera sie w liscie" << std::endl;
            return true;
        }
        curr = curr->next;
    }
    std::cout << "Podany elemnt nie zawiera sie w liscie" << std::endl;
    return false;
}
template <class T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::getHead() {
    if (head != nullptr) {
        return head;
    }
    else {
        std::cout << "Lista pusta!" << std::endl;
        return nullptr;
    }
}

template <class T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::getTail() {
    if (tail != nullptr) {
        return tail;
    }
    else {
        std::cout << "Lista pusta!" << std::endl;
        return nullptr;
    }
}
//ok
template <class T>
void DoubleLinkedList<T>::pushFront(T value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    size++;
}
//ok
template <class T>
void DoubleLinkedList<T>::pushBack(const T value) {
    Node* new_node = new Node(value);

    if (tail == nullptr) { // jeœli lista jest pusta
        head = tail = new_node;
    }
    else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}
//ok
template <class T>
void DoubleLinkedList<T>::popFront() {
    if (head == nullptr) {
        std::cout << "Lista jest pusta, nie mozna usunac" << std::endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete temp;
    size--;
}
//ok
template <class T>
void DoubleLinkedList<T>::popBack() {
    if (tail == nullptr) {
        // Lista jest pusta
        std::cout << "Lista jest pusta, nie mozna usunac" << std::endl;
        return;
    }
    else if (head == tail) {
        // Lista ma tylko jeden element
        delete tail;
        head = tail = nullptr;
    }
    else {
        // Lista ma wiêcej ni¿ jeden element
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    size--;
}
//ok
template <class T>
void DoubleLinkedList<T>::clearAll() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}
//ok
template <class T>
void DoubleLinkedList<T>::printList() const {
    if (head != nullptr) {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Lista pusta!" << std::endl;
    }
}










#endif