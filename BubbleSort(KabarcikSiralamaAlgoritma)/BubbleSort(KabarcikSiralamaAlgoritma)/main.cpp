//bubble sort (kabarcık sıralama) algoritması ; en büyük sayıyı bul , en sona taşı
/*
 7 2 5 3 1    en büyük sayıyı bul en sona taşı
 
 2 5 3 1 7   // 1. iç döngü tamamlandı en büyük sayı sonda
 
 2 3 1 5 7   // 2. iç döngü tamamlandı en büyük ikinci sayı sondan bir öne taşındı
 
 2 1 3 5 7   // 3. iç döngü tamamlandı en büyük üçüncü sayı sondan iki öne taşındı
 
 1 2 3 5 7   // 4. iç döngü tamamlandı en büyük üçüncü sayı sondan iki öne taşındı
 
 for
    for
 
 */

#include <iostream>
using namespace std;


void bubbleSort(int dizi[] , int n){
    
    for(int i = 0 ; i<n-1 ; i++)
    {
        for (int k = 0 ; k<n-i-1 ; k++) {
            if (dizi[k] > dizi[k+1]) {
                int gecici = dizi[k];
                dizi[k] = dizi[k+1];
                dizi[k+1] = gecici;
            }
        }
        
    }

}

int main(int argc, const char * argv[]) {
    int n;
    cout << "kaç adet sayı girmek istersiniz : " ; cin >> n;
    int dizi[n];
    
    int i = 0;
    
    while (i<n) {
        cout << "sayı: " ; cin >> dizi[i];
        
        i++;
    }
    bubbleSort(dizi,n);
    cout << "sıralama işlemi tamamlandı" << endl;
    for (int i =0;i<n ;i++ ) {
        cout << dizi[i] << " ";
        
    }
  
    return 0;
}
