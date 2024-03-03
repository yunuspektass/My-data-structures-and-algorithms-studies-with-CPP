/*
 ARAMA ALGORİTMALARI
 
 Linear Search (doğrusal arama) = Baştan başlayarak sona doğru aranan değeri kıyaslayarak arıyor
 Binary Search (ikili arama)

 */

#include <iostream>
using namespace std;

int linearSearch(int dizi[] , int n , int aranan)
{
    int i;
    for (i=0; i<n; i++) {
        if (aranan == dizi[i]) {
            return i;
        }
    }
    return -1; // aranan bulunmazsa
    
}
int main(int argc, const char * argv[]) {
    int n;
    cout << "dizi boyunu giriniz : "; cin >> n;
    int  dizi[n];
    
    int i=0;
    while (i<n) {
        cout << "sayi : "; cin >> dizi[i];
        i++;
    }
    int aranan;
    cout << "aranan sayıyı  giriniz :"; cin>>aranan;
    
    int sonuc = linearSearch(dizi,n,aranan);
    
    if (sonuc == -1)
        cout << "aranan sayı dizide yok" << endl;
    
    else
        cout << " aranan sayı dizinin " << sonuc << ". indisinci sırada..." << endl;
    
    
    return 0;
}
