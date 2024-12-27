/**
* @file Main.cpp
* @description Menu islemlerinin , dosya işlemlerinin yapıldıgı main sınıfımız 
* @course 2. Öğretim B grubu
* @assignment 2.Ödev
* @date 25.12.2024
* @author BEDİRHAN CAN - bedirhan.can@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include "Stack.hpp"
#include <string>
#include "AgaclarListesi.hpp"

using namespace std;

// Menü seçeneklerini ekrana yazdıran fonksiyon
void menu() {
    cout << endl;
    cout << "secim...:";
}

void menuSecimiUygula(char choice, Dugum*& current, Stack* history, AgaclarListesi* liste, int& currentPage, int limit) {
    
    if (liste->bosMu()) {
        cout << "Liste bos! Program sonlandiriliyor..." << endl;
        exit(0); // Programı sonlandır
    }
    switch (toupper(choice)) {
        case 'D':
            liste->sonrakiDugumeGit(current, history, liste, currentPage, limit);
            break;

        case 'A':
            liste->oncekiDugumeGit(current, history, liste, currentPage, limit);
            break;

        case 'S':
            if (current != nullptr) {
                Dugum* silinecek = current;
                current = (current->sonraki != nullptr) ? current->sonraki : liste->basDugum();
                liste->sil(silinecek->agac);
            }
            if(liste->elemanSayisi() == 0) {
                
                system("CLS");
            }
            break;

        case 'W':
            if (current != nullptr && current->agac != nullptr) {
                current->agac->aynalama();
                current->agac->levelorder();
            }
            break;

        case 'Q':
            cout << "Program sonlandiriliyor..." << endl;
            exit(0);

        default:
            cout << "Gecersiz secim!" << endl;
            break;
    }
}

int main() {
    AgaclarListesi* liste = new AgaclarListesi();
    ifstream dosya("agaclar.txt");
    if (!dosya.is_open()) {
        cerr << "Dosya acilamadi!" << endl;
        return 1;
    }

    string satir;
    while (getline(dosya, satir)) {
        Agac* yeniAgac = new Agac();
        for (char ch : satir) {
            yeniAgac->Ekle(ch);
        }
        liste->ekle(yeniAgac);
    }
    dosya.close();

    Dugum* current = liste->basDugum();
    Stack* history = new Stack();

    int currentPage = 0;
    const int limit = 10;

    char choice;
    while (true) {
        if (liste->bosMu()) {
        cout << "Liste bos! Program sonlandiriliyor..." << endl;
        break; // Döngüden çık
    }
        system("cls");
        Dugum* startDugum = liste->DugumPozisyonBul(currentPage * limit);
        liste->sayfadaGoster(startDugum, current);
        if (current && current->agac) {
            current->agac->levelorder();
        }
        menu();
        cin >> choice;
        menuSecimiUygula(choice, current, history, liste, currentPage, limit);
    }

    delete history;
    delete liste;
    return 0;
}
