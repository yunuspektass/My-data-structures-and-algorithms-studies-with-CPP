/*
 statik
 dinamik
 
 LİFO last in first out
 
 son giren ilk çıkar
 
 push metodu = yığına veri ekler
 pop metodu = veri çıkartır yığından
 top metodu = en üst değeri veir bize
 
 
 
 */

#define SIZE 10 // dizinin kapasitesini belirledik
// 10 adet veri alabilir
#include <iostream>
using namespace std;

struct stack {
    int data[SIZE]; // her bir değerim 4 byte ediyor
    //4*10 40 byte lık yerim var
    
    int top = -1; // -1 değeri stackte hiç bişi yok demek
    // bununla birlikte 44 byte eder
    // indis değerini tutuyor en süt değeri
    
};

stack  * stk; // boş bir konteynır tnaımladık.

void push(int key){ // push metodu stacke ekleme yapar
    
    if (stk->top == SIZE -1 ) { // diziler sıfırdan başlıyor
        
        cout << "stack doludur" << endl;
    }
    else{
        stk->top++; // her artmada 0. cı oldu 1. odlu atıyorum bu şekilde
        stk->data[stk->top] = key;
        
        cout << "stacke veri girişi yapıldı " << endl;
        
    }
    
}

void pop(){ // stackden veri çıkartır
    
    if (stk->top==-1) { // stk ın topu -1 eşitse stack boştur demek
        cout << "stack boştur" << endl;
    }
    else{
        cout <<stk->data[stk->top] << "değeri stack'den çıkartıldı." << endl;
        stk->top--; // en üst değerimizi top tutar. dizinin boyutu sabittir
    }
}

void reset(){ // stack'e boşaltıyor
    stk->top = -1; //stacğin yani stk nın topunu -1 yapmam dizim sıfırlandı anlamına gelir
    cout << "stack resetlendi" << endl;
    
}

void print(){ // stackdeki verileri yazdırır
    
    if (stk->top == -1) { // stk ın topu -1 ise boş demektşr
        cout << "stack boş" << endl;
    }
    else{
        int i;
        
        for (i = stk->top; i>-1; i--) {
            cout << stk->data[i] << endl;
        }
    }
}

int main() {
    
    int sayi , secim;
    cout << "stack in toplam kapisetesi " << sizeof(stk) << " byte" << endl;
    
    while (1) {
        cout << "1- push (ekle)" << endl;
        cout << "2- pop(çıkar)" << endl;
        cout << "3- reset (boşalt)" << endl;
        cout << "4- print(yazdır)" << endl;
        
        switch (1) {
            case 1:
                cout << "sayı giriniz:" ; cin >> sayi;
                push(sayi);
                break;
            case 2:
                pop();
                break;
            case 3:
                reset();
                break;
            case 4:
                print();
                break;
                
            default:
                break;
        }

    }
    return 0;
}
