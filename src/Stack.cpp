/**
* @file Stack.cpp
* @description Agacların tek yönlü baglı listesinde sola gitmek için kullandıgım stack kaynak dosyası
* @course 2. Öğretim B grubu
* @assignment 2.Ödev
* @date 25.12.2024
* @author BEDİRHAN CAN - bedirhan.can@ogr.sakarya.edu.tr
*/
#include "Stack.hpp"
#include <stdexcept>

// Node yapıcısı
Stack::Node::Node(Dugum* data, Node* next) : data(data), next(next) {}

// Stack sınıfı yapıcısı
Stack::Stack() : topNode(nullptr), stackSize(0) {}

// Stack sınıfı yıkıcısı
Stack::~Stack() {
    while (!empty()) {
        pop();
    }
}

// Yigina eleman ekler
void Stack::push(Dugum* item) {
    topNode = new Node(item, topNode);
    ++stackSize;
}

// Yiginin en ustundeki elemani dondurur
Dugum* Stack::top() const {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return topNode->data;
}

// Yiginin en ustundeki elemani cikarir
void Stack::pop() {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
    --stackSize;
}

// Yiginin bos olup olmadigini kontrol eder
bool Stack::empty() const {
    return topNode == nullptr;
}

// Yiginin boyutunu dondurur
int Stack::size() const {
    return stackSize;
}
