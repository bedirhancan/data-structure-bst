/**
* @file Stack.hpp
* @description Agacların tek yönlü baglı listesinde sola gitmek için kullandıgım stack baslık dosyası
* @course 2. Öğretim B grubu
* @assignment 2.Ödev
* @date 25.12.2024
* @author BEDİRHAN CAN - bedirhan.can@ogr.sakarya.edu.tr
*/
#ifndef STACK_HPP
#define STACK_HPP

#include "Dugum.hpp" // Dugum sinifi kullanildigi icin dahil edildi

class Stack {
private:
    struct Node {
        Dugum* data;     // Yiginda tutulacak veri (Dugum pointer)
        Node* next;      // Sonraki elemani gosteren pointer

        Node(Dugum* data, Node* next = nullptr);
    };

    Node* topNode;        // Yiginin en ustundeki eleman
    int stackSize;        // Yigindaki eleman sayisi

public:
    Stack();
    ~Stack();

    void push(Dugum* item); // Yigina eleman ekler
    Dugum* top() const;     // Yiginin en ustundeki elemani dondurur
    void pop();             // Yiginin en ustundeki elemani cikarir
    bool empty() const;     // Yiginin bos olup olmadigini kontrol eder
    int size() const;       // Yiginin boyutunu dondurur
};

#endif
