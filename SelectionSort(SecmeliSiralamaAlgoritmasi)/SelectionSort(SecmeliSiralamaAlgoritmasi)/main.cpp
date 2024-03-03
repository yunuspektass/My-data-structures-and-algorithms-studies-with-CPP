/*
 selection sort (seçmeli sıralama) : en baştaki sayıyı kendisinden sonra gelen en küçük sayı ile yer değiştirir.
 
 7 3 5 1 2
 int kucuk  =
 [7] 3 5 1 2 ->  [1] 3 5 7 2
 1 [3] 5 7 2 ->  1 [2] 5 7 3
 1 2 [5] 7 3 ->  1 2 [3] 7 5
 1 2 3 [7] 5 -> 1 2 3 [5] 7
 
 for (toplam sayıdan bir eksik dönecek)
   for (kendisinden sonra gelen sayı adetince döncek)
 
 */
#include <iostream>
using namespace std;

void selectionSort(int dizi[] , int n){
    
    for (int i = 0; i<n-1; i++) {
        int kucuk = dizi[i];
        int indis = i;
        for (int k = i; k<n; k++) {
            if (kucuk > dizi[k]) { //küçük isimli değişkene en küçük sayıyı bularak atıyoruz , değişim yok
                kucuk = dizi[k];
                indis = k;
            }
        }
        dizi[indis] = dizi[i]; // dizideki küçük sayı başa alındı
        dizi[i] = kucuk;
    }
    
    
}

int main(int argc, const char * argv[]) {
    int n;
    cout << "kaç adet sayı girmek istersiniz : "; cin  >> n;
    int i = 0;
   int dizi[n];
    
    while (i<n) {
        cout << "sayi : " ; cin >>dizi[i];
        i++;
    }
    selectionSort(dizi,n);
    cout << "sıralama tamamlandı " << endl;
    for (int i = 0 ; i < n; i++) {
        cout << dizi[i] << " ";
    }
    

    return 0;
}
