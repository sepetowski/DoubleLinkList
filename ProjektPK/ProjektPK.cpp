#include <iostream>
#include "Lista.h"

int main()
{
    DoubleLinkedList<int> list;

    // Test dodawania elementów na początek i koniec listy
    list.pushFront(2);
    list.pushFront(1);
    list.pushBack(20);

    //Wypisywanie elemntow listy
    list.printList();

    //usuwanie wszytskiego
    list.clearAll();

    list.printList();

    list.pushFront(2);
    list.pushFront(1);
    list.pushBack(20);
    // usuwane pierwszego elemtnu
    list.popFront();
    // usuwanie ostattniego elementu
    list.popBack();


    list.printList();

    // sprawdzamy czy elemnt zawiera sie w lisice
    list.contains(2);
    // sprawdzamy aktualny rozmiar listy
    list.getSize();

    // dodajemy kilka elemtnow do listy
    list.pushFront(15);
    list.pushFront(16);
    list.pushBack(22);
    list.pushFront(3);
    list.pushBack(30);
    list.pushBack(10);

    list.printList();
    list.getSize();

    // odczytywanie 1 elemtnu
    std::cout << "Pierwszy element to " << list.getFront() << std::endl;

    //odczytywanie ostatniego elemtnu
    std::cout << "Ostatni element to " << list.getBack() << std::endl;


    //odczytywanie elemntu z danej pozycji
    std::cout << "Odczytywanie elemntu z wskazanej pozycji (w tym wypadku 3 pozycji) " << list.getFromPosition(3) << std::endl;

    // wstawainie elementu na wybranej pozycji w  liscie 
    //wtsiwamy na 3 index, czyli 4 elemnt od lewa to wpisana wartosc bo indeksujemy od 0
    list.insertAt(3, 100);
    list.printList();
    std::cout << "Odczytywanie elemntu z wskazanej pozycji (w tym wypadku 3 pozycji) " << list.getFromPosition(3) << std::endl;

    std::cout<<std::endl;
    std::cout << std::endl;
 

    //przygotowanie programu do testow iteratora
    list.clearAll();
    for (int i = 0; i <= 20; i++) 
    list.pushBack(i);

    std::cout << "Aktualny stan listy:" << std::endl;
    list.printList();

    std::cout << std::endl;
    std::cout << std::endl;
    
    

    // utworzenie iteratora i przetestowanie operatora *
    DoubleLinkedList<int>::Iterator it(list.getHead());
    std::cout << "Iterator poczatku: " << *it << std::endl;

   

    // przetestowanie operatora +=
    it += 2;
    std::cout << "Przesuniecie iteratora 0 o 2 poyzcje w prawo: " << *it << std::endl;

    // przetestowanie operatora -=
    it -= 1;
    std::cout << "Przesuniecie iteratora o 1 poyzcje w lewo: " << *it << std::endl;

    // przetestowanie operatora +
    DoubleLinkedList<int>::Iterator it2 = it + 1;
    std::cout << "Utowrzenie nowego iteratora zwieskoznego o 1 pozcyje w stosunku do it0: " << *it2 << std::endl;

    // przetestowanie operatora -
    DoubleLinkedList<int>::Iterator it3 = it - 1;
    std::cout << "Utowrzenie nowego iteratora zmnijeszonego o 1 pozcyje w stosunku do it0:: " << *it3 << std::endl;

    //test inkremetacji 
    std::cout << "Test inkremetacji - wartosc poczatkowa: " << *it << std::endl;

    ++it;
    std::cout << "Po inkremetacji: " << *it << std::endl;


    //test dekrymentacja 
    std::cout << "Test dekrymaentacji - wartosc poczatkowa: " << *it << std::endl;

    --it;
    std::cout << "Po dekrymaentacji: " << *it << std::endl;

    

    // przetestowanie operatora ==
    std::string result1 = "Tak";
    DoubleLinkedList<int>::Iterator it4 = it;
    if (it != it4)
         result1 = "Nie";
    std::cout << "Czy iterator 0 i 4 wsakazuje na te same elemnty: " << result1 << std::endl;

    // przetestowanie operatora !=
    std::string result2 = "Nie";
    DoubleLinkedList<int>::Iterator it5 = it + 1;
    if (it == it5)
        result2 = "Tak";
    std::cout << "Czy iterator 0 wskazuje na ten sam element co 5: " << result2 << std::endl;

    // przetestowanie operatora <
    if (it < it5) result2 = "Tak"; else result2 = "Nie";
    std::cout << "Czy iterator 0 wsazkuje na wczesnijeszy elemnt niz iterator 5: " << result2 << std::endl;

    // przetestowanie operatora >
    if (it3 > it) result2 = "Tak"; else result2 = "Nie";
    std::cout << "Czy iterator 0 wsazkuje na poznijeszy elemnt niz iterator 3: " << result2 << std::endl;

    // przetestowanie operatora <=
    DoubleLinkedList<int>::Iterator it6 = it;
    if (it <= it6) result2 = "Tak"; else result2 = "Nie";
    std::cout << "Czy iterator 0 wsazkuje na wczesniejszy lub ten sam elemnet co iterator 6: " << result2 << std::endl;

    // przetestowanie operatora >=
    DoubleLinkedList<int>::Iterator it7 = it5;
    if (it7 >= it5) result2 = "Tak"; else result2 = "Nie";
    std::cout << "Czy iterator 7 wsazkuje na poznijeszy lub ten sam elemnet co iterator 5: " << result2 << std::endl;

    // przetestowanie metody moveToStart
    it.moveToStart();
    std::cout << "Przesun na poczatek: " << *it << std::endl;

    // przetestowanie metody moveToEnd
    it.moveToEnd();
    std::cout << "Przesun na koniec: " << *it << std::endl;

    //  przetestowanie metody moveToIndex
    it.moveToIndex(3);
	std::cout << "Przesun na pozycje 3: " << *it << std::endl;


    



    return 0;
}
