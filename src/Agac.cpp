/**
* @file Agac.cpp
* @description Agaclar için kaynak dosyası  , agacı yazdırma , ascii toplamını ve aynalama fonksiyonları yer alıyor 
* @course 2. Öğretim B grubu
* @assignment 2.Ödev
* @date 25.12.2024
* @author BEDİRHAN CAN - bedirhan.can@ogr.sakarya.edu.tr
*/
#include "Agac.hpp"
#include <iostream>
#include <cmath> // pow için
#include <iomanip> // setw için

void Agac::LevelYazdir(AgacDugum *subNode, int level, int currentLevel, int maxLevel) {
    if (subNode == nullptr) {
        if (level == currentLevel) {
            int spaceCount = pow(2, maxLevel - currentLevel + 1) - 1;
            for (int i = 0; i < spaceCount; i++) cout << " ";
            cout << " ";
            for (int i = 0; i < spaceCount; i++) cout << " ";
        } else {
            LevelYazdir(nullptr, level, currentLevel + 1, maxLevel);
            LevelYazdir(nullptr, level, currentLevel + 1, maxLevel);
        }
        return;
    }

    if (level == currentLevel) {
        int spaceCount = pow(2, maxLevel - currentLevel + 1) - 1;
        for (int i = 0; i < spaceCount; i++) cout << " ";
        cout << subNode->veri;
        for (int i = 0; i < spaceCount; i++) cout << " ";
    } else {
        LevelYazdir(subNode->sol, level, currentLevel + 1, maxLevel);
        LevelYazdir(subNode->sag, level, currentLevel + 1, maxLevel);
    }
}

void Agac::LevelYazdirBaglanti(AgacDugum *subNode, int level, int currentLevel, int maxLevel) {
    if (subNode == nullptr) {
        if (level == currentLevel) {
            int spaceCount = pow(2, maxLevel - currentLevel + 1) - 1;
            for (int i = 0; i < spaceCount; i++) cout << " ";
            cout << " ";
            for (int i = 0; i < spaceCount; i++) cout << " ";
        } else {
            LevelYazdirBaglanti(nullptr, level, currentLevel + 1, maxLevel);
            LevelYazdirBaglanti(nullptr, level, currentLevel + 1, maxLevel);
        }
        return;
    }

    if (level == currentLevel) {
        int spaceCount = pow(2, maxLevel - currentLevel + 1) - 1;
        for (int i = 0; i < spaceCount-1; i++) cout << " ";
        if(subNode->sol != nullptr) cout << "/";
        else cout << " ";
        cout << " ";
        if(subNode->sag != nullptr) cout << "\\";
        else cout << " ";
        for (int i = 0; i < spaceCount-1; i++) cout << " ";
    } else {
        LevelYazdirBaglanti(subNode->sol, level, currentLevel + 1, maxLevel);
        LevelYazdirBaglanti(subNode->sag, level, currentLevel + 1, maxLevel);
    }
}

void Agac::levelorder() {
    int maxLevel = Yukseklik();
    for (int level = 0; level <= maxLevel; level++) {
        LevelYazdir(kok, level, 0, maxLevel);
        cout << endl;
        if(level < maxLevel) {
            LevelYazdirBaglanti(kok, level, 0, maxLevel);
            cout << endl;
        }
    }
}

// Constructor
Agac::Agac() {
    kok = nullptr;
}
// Liste boş mu kontrolü
bool Agac::bosMu() const {
    return kok == nullptr;
}

// Yeni eleman ekleme
void Agac::Ekle(const char& newItem) {
    AraVeEkle(kok, newItem);
}

// Eleman silme
void Agac::Sil(const char& veri) {
    if (AraVeSil(kok, veri)) 
        throw "Item bulunamadi.";
}


// Yükseklik hesaplama
int Agac::Yukseklik() {
    return Yukseklik(kok);
}

// Arama fonksiyonu
bool Agac::Ara(const char& item) {
    return Ara(kok, item);
}

// Ağacın belleğini temizleme
void Agac::Temizle() {
    while (!bosMu()) DugumSil(kok);
}

// Destructor
Agac::~Agac() {
    Temizle();
}

// --- Private Fonksiyonlar ---

// Eleman eklemek için yardımcı fonksiyon
void Agac::AraVeEkle(AgacDugum *&subNode, const char& newItem) {
    if (subNode == nullptr) {
        // Create a new AgacDugum with nullptr for both left and right children
        subNode = new AgacDugum(newItem, nullptr, nullptr);
    } else if (newItem < subNode->veri) {
        AraVeEkle(subNode->sol, newItem);
    } else if (newItem > subNode->veri) {
        AraVeEkle(subNode->sag, newItem);
    } else {
        return;  // Do nothing if the item already exists
    }
}


// Eleman silme için yardımcı fonksiyon
bool Agac::AraVeSil(AgacDugum *&subNode, const char& veri) {
    if (subNode == nullptr) return false;
    if (subNode->veri == veri) return DugumSil(subNode);
    else if (veri < subNode->veri) return AraVeSil(subNode->sol, veri);
    else return AraVeSil(subNode->sag, veri);
}

// Düğüm silme işlemi
bool Agac::DugumSil(AgacDugum *&subNode) {
    AgacDugum *DelNode = subNode;
    
    if (subNode->sag == nullptr) 
        subNode = subNode->sol;
    else if (subNode->sol == nullptr) 
        subNode = subNode->sag;
    else {
        DelNode = subNode->sol;
        AgacDugum *parent = subNode;
        while (DelNode->sag != nullptr) {
            parent = DelNode;
            DelNode = DelNode->sag;
        }
        subNode->veri = DelNode->veri;
        if (parent == subNode) subNode->sol = DelNode->sol;
        else parent->sag = DelNode->sol;
    }
    delete DelNode;
    return true;
}

// Ağacın yüksekliğini hesaplayan fonksiyon
int Agac::Yukseklik(AgacDugum *subNode) {
    if (subNode == nullptr) return -1;
    return 1 + max(Yukseklik(subNode->sol), Yukseklik(subNode->sag));
}

AgacDugum* Agac::getKok() {
        return kok;
    }

// Arama fonksiyonu
bool Agac::Ara(AgacDugum *subNode, const char& item) {
    if (subNode == nullptr) return false;
    if (subNode->veri == item) return true;
    if (item < subNode->veri) return Ara(subNode->sol, item);
    else return Ara(subNode->sag, item);
}

void Agac::aynalama() {
    aynalamaYardimci(kok);
}

void Agac::aynalamaYardimci(AgacDugum* dugum) {
    if (dugum == nullptr) return;

    // Sol ve sağ çocukları değiştir
    AgacDugum* temp = dugum->sol;
    dugum->sol = dugum->sag;
    dugum->sag = temp;

    // Alt düğümler için aynalama yap
    aynalamaYardimci(dugum->sol);
    aynalamaYardimci(dugum->sag);
}



int Agac::AsciiToplam(AgacDugum* node, bool isLeftChild = false)  {
    if (node == nullptr) return 0;

    // Düğümün değerini çarpan ile ekle
    int multiplier = isLeftChild ? 2 : 1;  // Sol alt düğümler için çarpan 2
    int totalValue = multiplier * node->veri;

    // Alt düğümleri dolaş
    totalValue += AsciiToplam(node->sol, true);   // Sol alt ağaca geçerken isLeftChild = true
    totalValue += AsciiToplam(node->sag, false); // Sağ alt ağaca geçerken isLeftChild = false

    return totalValue;
}

int Agac::KokToplam() {
    return AsciiToplam(kok);  // Kök düğümün değeri + alt ağacın toplamı
}
