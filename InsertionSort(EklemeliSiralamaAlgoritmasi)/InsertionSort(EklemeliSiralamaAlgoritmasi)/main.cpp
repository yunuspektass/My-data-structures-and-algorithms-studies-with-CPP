/*
 insertion sort (eklemeli sıralama) algoritması = küçük sayıyı bul basa doğru taşı(geriye yürüme işlemi var)
 
 7 3 5 1 2
 
[ 7 3] 5 1 2  ->  [3 7] 5 1 2
[3 7 5] 1 2 -> [3 5 7] 1 2
 [3 5 7 1] 2 ->[1 3 5 7] 2
 [1 3 5 7 2] -> [1 2 3 5 7]
 
 
 for (4 defa dönecek) kaç sayı varsa bir eksiği kadar döner
   for(kendisinden önceki sayi adetince dönecek)
 
 */

#include <iostream>
using namespace std;

void insertionSort(int dizi[] , int n){
    
    for (int i = 1; i < n; i++) {
        for (int k=i; k>=0 ; k--) {
            if (dizi[k] < dizi[k-1]) {
                
                int gecici = dizi[k];
                dizi[k] = dizi[k-1];
                dizi[k-1] = gecici;
            }
        }
    }
    
    
}

int main(int argc, const char * argv[]) {
    int n;
    cout << "kaç adet sayı girmek istersiniz : "; cin >> n;
    int dizi[n];
    
    int i= 0;
    while (i < n) {
        cout << "sayı : "; cin >>dizi[i];
        i++;
    }
    
    insertionSort(dizi , n); //diziyi göndermek adresi göndermek demek dizi son haliyle sıralanmış oldu otomatik olarak geriye bir şey dönmeye gerek yok
    
    cout << "sıralama işlemi tamamlandı " << endl;
    
    for (int i = 0;i<n; i++) {
        cout << dizi[i]  << " ";
    }
 
    return 0;
}
