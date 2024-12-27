/**
* @file Agac.hpp
* @description Agaclar için başlık dosyası  , agacı yazdırma , ascii toplamını ve aynalama fonksiyonları yer alıyor 
* @course 2. Öğretim B grubu
* @assignment 2.Ödev
* @date 25.12.2024
* @author BEDİRHAN CAN - bedirhan.can@ogr.sakarya.edu.tr
*/
#ifndef AGAC_HPP
#define AGAC_HPP

#include "AgacDugum.hpp"
#include <iostream>
#include <algorithm>

class Agac {
private:    
    AgacDugum *kok;
    
    void AraVeEkle(AgacDugum *&subNode, const char& newItem);
    bool AraVeSil(AgacDugum *&subNode, const char& veri);
    bool DugumSil(AgacDugum *&subNode);
    int  Yukseklik(AgacDugum *subNode);
    void LevelYazdir(AgacDugum *subNode, int level, int currentLevel, int maxLevel);
    bool Ara(AgacDugum *subNode, const char& item);
    void aynalamaYardimci(AgacDugum* dugum);

public:
    Agac();
    bool bosMu() const;
    void Ekle(const char& newItem);
    void Sil(const char &veri);
    void levelorder();
    int Yukseklik();
    bool Ara(const char& item);
    void Temizle();
    ~Agac();
    AgacDugum* getKok();
    int AsciiToplam(AgacDugum* dugum,bool solCocum);
    void aynalama();
    int KokToplam();
    void LevelYazdirBaglanti(AgacDugum *subNode, int level, int currentLevel, int maxLevel) ;
    
};

#endif
