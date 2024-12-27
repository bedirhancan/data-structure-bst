/**
* @file AgaclarListesi.cpp
* @description Agacları tek yönlü baglı listede tutan kaynak dosyası 
* @course 2. Öğretim B grubu
* @assignment 2.Ödev
* @date 25.12.2024
* @author BEDİRHAN CAN - bedirhan.can@ogr.sakarya.edu.tr
*/
#include "AgaclarListesi.hpp"
#include <iostream>
#include <iomanip>

// Constructor
AgaclarListesi::AgaclarListesi() : bas(nullptr), boyut(0), kapasite(0) {}

// isEmpty function
bool AgaclarListesi::bosMu() const {
    return bas == nullptr;
}

// count function
int AgaclarListesi::elemanSayisi() const {
    return boyut;
}

// first function
Agac* AgaclarListesi::ilk() {
    if (bosMu()) {
        cout << "Liste bos\n";
        return nullptr;
    }
     if (mevcut && mevcut->sonraki) {
            mevcut = mevcut->sonraki;  // Sonraki düğüme geç
            return mevcut->agac;
        }
}

// last function
Agac* AgaclarListesi::sonEleman() {
    if (bosMu()) {
        cout << "Liste bos\n";
        return nullptr;
    }
    return DugumPozisyonBul(boyut - 1)->agac;
}

// FindPrevByPosition helper function
Dugum* AgaclarListesi::DugumPozisyonBul(int position) {
    if (position < 0 || position >= boyut) {
        cout << "Index aralik disi\n";
        return nullptr;
    }
    int index = 0;
    Dugum* itr = bas;
    while (itr != nullptr) {
        if (index == position) return itr;
        itr = itr->sonraki;
        index++;
    }
    return nullptr;
}

// add function
void AgaclarListesi::ekle(Agac* item) {
    arayaEkle(boyut, item);
}

// insert function
void AgaclarListesi::arayaEkle(int index, Agac* item) {
    if (index < 0 || index > boyut) {
        cout << "Index aralik disi\n";
        return;
    }
    
    if (index == 0) {
        bas = new Dugum(item, bas);
    } else {
        Dugum* prev = DugumPozisyonBul(index - 1);
        prev->sonraki = new Dugum(item, prev->sonraki);
    }
    boyut++;
}

// remove function
void AgaclarListesi::sil(Agac* item) {
    int position = elemanIndeksi(item);
    pozisyondanSil(position);
}

// removeAt function
void AgaclarListesi::pozisyondanSil(int index) {
    if (bosMu()) {
        cout << "List is empty\n";
        return;
    }
    if (index < 0 || index >= boyut) {
        cout << "Index out of range\n";
        return;
    }

    Dugum* del;
    if (index == 0) {
        del = bas;
        bas = bas->sonraki;
    } else {
        Dugum* prev = DugumPozisyonBul(index - 1);
        del = prev->sonraki;
        prev->sonraki = prev->sonraki->sonraki;
    }
    delete del;
    boyut--;
}

// find function
bool AgaclarListesi::bul(Agac* item) {
    for (Dugum* itr = bas; itr != nullptr; itr = itr->sonraki) {
        if (itr->agac == item) return true;
    }
    return false;
}

// indexOf function
int AgaclarListesi::elemanIndeksi(Agac* item) {
    int index = 0;
    for (Dugum* itr = bas; itr != nullptr; itr = itr->sonraki, index++) {
        if (itr->agac == item) return index;
    }
    cout << "Item bulunamadi\n";
    return -1;
}

// Friend function to print the list
ostream& operator<<(ostream& ekran, AgaclarListesi& liste) {
    if (liste.bosMu()) {
        ekran << "Agac bos" << endl;
    } else {
        for (Dugum* itr = liste.bas; itr != nullptr; itr = itr->sonraki) {
            Agac* tree = itr->agac;  // Agac nesnesine erişim
            if (tree != nullptr) {
                tree->levelorder();  // Seviye sırasına göre yazdırma
            }
			cout << endl;
        }
    }
    return ekran;
}

// clear function
void AgaclarListesi::temizle() {
    while (!bosMu()) {
        pozisyondanSil(0);
    }
}

// Destructor
AgaclarListesi::~AgaclarListesi() {
    temizle();
}

// Baş düğümü döner
Dugum*AgaclarListesi::basDugum() {
        return bas;
    }

void AgaclarListesi::sayfadaGoster(Dugum* head, Dugum* current) {
        system("CLS"); // Konsol ekranını temizle

    const int limit = 10;
    Dugum* temp = head;
    
    // Çerçeve ve içerik satırları
    for (int i = 0; i < 7; ++i) {
        temp = head;
        for (int count = 0; count < limit && temp != nullptr; ++count, temp = temp->sonraki) {
            if (i == 0 || i == 2 || i == 4 || i == 6)
                cout << ". . . . . . . . ";
            else if (i == 1)
                cout << ". " << setw(11) << (reinterpret_cast<uintptr_t>(temp) % 10000) << " . ";
            else if (i == 3)
                cout << ". " << setw(10) << (temp->agac->KokToplam()) <<" "<< " . ";
            else if (i == 5)
                cout << ". " << setw(11) << (reinterpret_cast<uintptr_t>(temp->sonraki) % 10000) << " . ";
        }
        cout << "   "<<endl;
    }
    
    // Seçili düğüm işaretleri ve çizgileri
    temp = head;
    string isaretler;
    string cizgiler;
    for (int count = 0; count < limit && temp != nullptr; ++count, temp = temp->sonraki) {
        isaretler += (temp == current ? " ^ ^ ^ ^ ^ ^ ^ " : "                ");
        cizgiler += (temp == current ? " | | | | | | | " : "                ");
    }
    cout << isaretler << endl;
    cout << cizgiler << endl;
}

void AgaclarListesi::levelorder(Dugum* dugum) {
    // Ağacın seviyeli sıralama fonksiyonu
    if (dugum && dugum->agac) {
        dugum->agac->levelorder();  // Agac sınıfının levelorder fonksiyonu kullanılacak
    }
}

    void AgaclarListesi::sonrakiDugumeGit(Dugum*& current, Stack* history, AgaclarListesi* liste, int& currentPage, int limit) {
    if (current != nullptr && current->sonraki != nullptr) {
        history->push(current); // Mevcut düğümü yığına ekle
        current = current->sonraki;

        // Eğer sayfa sonunu geçtiyse
        if (liste->elemanIndeksi(current->agac) > (currentPage * limit + limit - 1)) {
            currentPage++;
        }
    }
}
    void AgaclarListesi::oncekiDugumeGit(Dugum*& current, Stack* history, AgaclarListesi* liste, int& currentPage, int limit) {
    if (current != nullptr) {
        if (liste->elemanIndeksi(current->agac) == currentPage * limit && currentPage > 0) {
            currentPage--;
            current = liste->DugumPozisyonBul((currentPage + 1) * limit - 1);
        } else if (!history->empty()) {
            current = history->top();   
            history->pop();
        } else {
            current = liste->basDugum();
        }
    }
}
