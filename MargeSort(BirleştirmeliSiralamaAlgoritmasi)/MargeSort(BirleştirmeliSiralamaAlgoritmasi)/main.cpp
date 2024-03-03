/*
 Merge Sort (birleştirmeli sıralama) algoritması
 
       7 3 1 5 2 0 4 6    divide(bölme işlemi) yarıya bölücez
 
    7 3 1 5        2 0 4 6
 7 3      1 5    2 0    4 6
 
 son iki rakam kalana kadar böldük sonra sıralayarak birleştiricez
 
 7 3      1 5    2 0    4 6
 
 3 7      1 5    0 2    4 6   küçükleri başa alarak sıraladık   , son üç adımda merge() birleştirme                                                                                     işlemi yaptık
 
 kendi için de 4 rakamı birleştirip sıralıycaz
 
 1 3 5 7        0 2 4 6
 
 en son toplam 8 rakamı birleştirip küçükten büyüğe sıralıycaz
 
 0 1 2 3 4 5 6 7
 
 
 */

#include <iostream>
using namespace std;

int a[]={7 ,3, 1, 5, 2, 0, 4, 6 , 9 ,8};
int b[10]; // geçici dizi

void birlestir(int bas , int orta , int son){
    int i,j,k;
    for (i=bas;i<=son; i++) // a dizimizi b dizimize kopyalıyoruz
        b[i]=a[i];
   
    i = bas;
    j = orta+1;
    k = bas;
    
    while (i<=orta && j<=son) {
        if (b[i] <= b[j]) {
            a[k++] = b[i++];
        }
        else{
            a[k++] = b[j++];
        }
    }
    while (i<=orta) {
        a[k++] = b[i++];
    }
    
}

void bol(int bas , int son)
{
    if (bas < son) {
        int orta = (bas + son) / 2;
        bol(bas, orta);
        bol(orta+1, son);
        birlestir(bas , orta ,son);
    }
}



int main(int argc, const char * argv[]) {
    bol(0, 9);
    for (int i = 0; i<=9; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}
