/*
 Bİnary Search (ikili arama) : dizinin sıralı olduğunu varsayılır , ortanca değer ile aranan sayı karşılaştırılır. eşitse durur , küçükse sağa bakıyoruz , büyükse sola bakıyoruz
 
 1 3 [5] 7 9    aranan sayı 3
 
 [1] 3 ortanca sayıdan aranan sayı büyük mü evet solu aldı
 
 [3] aranan sayı ortanca sayıya eşitmi evet
 

 */
#include <iostream>
using namespace std;

void quickSort(int dizi[] , int bas , int son){
    int i,j,pivot,temp;
     i = bas;
     j = son;
    pivot = dizi[(i+j)/2];
    do {
        
        while (dizi[i]<pivot)
            i++;
        while (dizi[j] > pivot)
            j--;
        if (i<=j) {
            temp =dizi[i];
            dizi[i] = dizi[j];
            dizi[j] = temp;
            i++;
            j--;
        }
    
    } while (i<j);
    if (i<son) {
        quickSort(dizi, i, son);
    }
     if (bas < j)
        quickSort(dizi, bas, j);
}


bool binarySearch(int dizi[] , int bas , int son , int aranan){
    while (son>=bas) {
        int orta = dizi[(bas + son) / 2];
        
        if (aranan == orta) {
            return true;
        }
        if (orta < aranan)
            bas++;
         if (orta > aranan)
             son--;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int n;
    cout << "dizi boyunu giriniz : " ; cin >> n;
    int dizi[n];
    
    int i = 0;
    
    while (i<n) {
        cout << "sayi :"; cin >> dizi[i];
        i++;
    }
    quickSort(dizi , 0 , n-1);
    cout << "dizideki sayılar quickSort algoritmasıyla sıralandı" << endl;
    for (i = 0; i<n; i++) {
        cout << dizi[i] << " " ;
      
    }
    cout << endl;
    
    int aranan;
    cout << "aranan sayıyı giriniz:"; cin >> aranan;
    
    bool sonuc = binarySearch(dizi , 0 , n-1 , aranan);
    
    if (sonuc) {
        cout << aranan <<  " sayısı dizide var" ;
        
    }
    else
        cout << aranan << " sayısı dizide yok" << endl;
    

    return 0;
}
