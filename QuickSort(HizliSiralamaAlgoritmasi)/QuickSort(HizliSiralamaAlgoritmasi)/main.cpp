/*
 quick sort (hızlı sıralama) algoritması : pivot olarak belirlenen sayının sağ ve sol kısımları pivot ile kıyaslanır: Bu işlem requrcive (özyineli) olarak tekrarlanır.

 
 7 3 [5] 1 2 -> pivot olarak ortanca sayı belirlendi (5)
 
 7 3 [5] 1 2 -> 2 3 [5] 1  7 // sağdakiler büyük soldaki sayılar kendinden küçük pivotumuz 5 sabitlendi
 
 2 3 [5] 1  7 -> 2 3 1 [5] 7
  // geriye kalan 3 sayı kendi içinde  requrcive olarak devam ediyor. pivotu ortadaki belirledik
 2 [3] 1 -> 2 1 [3] solundaki sayılar küçük pivot sabitlendi
 
 [2] 1 çift sayı varsa soldakini pivot alıcaz  , pivotun sağındaki sayı pivottan büyük solundaki sayı ise küçük olmalı ona göre yer değiştirir
 
 1 [2]
 
 1 [2] [3] [5] 7
 */
#include <iostream>
using namespace std;

void quickSort(int dizi[] , int bas , int son){
    int i,j,pivot,temp;
    
    i = bas;
    j = son;
    pivot = dizi[(i+j) / 2 ];
    
    do {
        while (dizi[i] < pivot)
            i++;
        
        
        while (dizi[j] > pivot)
            j--;
        
        if (i<=j) { //karşılıklı yer değişim işlemi yapıldı
            temp = dizi[i];
            dizi[i] = dizi[j];
            dizi[j] = temp;
            i++;
            j--;
        }
        
        
        
    } while (i<j);
    
    if (i<son)
        quickSort(dizi,i,son);
     if (bas < j)
         quickSort(dizi,bas,j);
    
    
    
    
}
int main(int argc, const char * argv[]) {

    int n;
    
    cout << "dizi boyunu giriniz : "; cin>>n;
    int dizi[n];
    int i = 0 ;
    
    while (i < n) {
        cout << " sayı :" ; cin >> dizi[i];
        i++;
    }
    
    quickSort(dizi , 0 , n-1);
    
    cout << "hızlı sıralama işlemi tamamlandı " << endl;
    
    for (i = 0; i<n ; i++) {
        cout << dizi[i] << " ";
    }
    
    
    return 0;
}
