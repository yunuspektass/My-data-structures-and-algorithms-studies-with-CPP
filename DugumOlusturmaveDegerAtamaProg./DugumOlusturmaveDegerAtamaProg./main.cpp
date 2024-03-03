
#include <iostream>
using namespace std;

struct ogrenci { // düğüm oluşturma kalıbımımızı oluşturduk.
    string ad;
    string soyad;
    char cinsiyet;
    int yas;
    
    struct ogrenci * next; // düğüm gösteren gösterici
    
};






int main() {
    
    
    struct ogrenci *o1 = new ogrenci(); // düğüm oluşturdulk bellekte yer aldık
    struct ogrenci *o2 = new ogrenci(); // ikinci düğüm
    struct ogrenci *o3 = new ogrenci();  //üçüncü düğüm pointerı ekle referansın başına *
    o1->ad = "yunus";
    o1->soyad = "pektaş";
    o1->cinsiyet = 'e';
    o1->yas = 20;
    
    o2->ad = "sude";
    o2->soyad = "pektaş";
    o2->cinsiyet = 'k';
    o2->yas = 19;
    
    o3->ad = "zeyneb";
    o3->soyad = "pektaş";
    o3->cinsiyet = 'k';
    o3->yas = 4;
    
    o1 ->next = o2;
    o2 ->next = o3;
    o3 ->next = NULL;
    
    struct ogrenci * temp = o1;
    
    while (temp != NULL) {
        cout << temp->ad << " " << temp->soyad << " " << temp->cinsiyet << " " << temp->yas << endl;
        temp = temp->next;
    }
    
    
    
    
    
    
    
    
    return 0;
}
