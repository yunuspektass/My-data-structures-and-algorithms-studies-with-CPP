#include <iostream>
using namespace std;

struct node  {
    int data;
    struct node *next; //bir sonraki düğümü göstermesi için
};

struct node * head = NULL; //head en baştaki değer

//pointerını * unutma
//baştaki değerini nulla eşitledik

void basaEkle (int key){ //geri dönüşü olmayan void bir değer

    struct node *eleman = new node (); //struct ını oluşturdum istediğim kadar
    //nesne oluşturabilirim artık
    
    eleman->data = key;
    
    if (head == NULL) {
        head = eleman;
        head -> next = head;
        cout << head << " ilk kayıt başa eklendi." << endl;
        
        //tek yönlü dairesel olduğu için tek eleman olunca kendi kendini gösteren düğüm olması gerekiyor.
    }
    else{
        if (head->next==head) {
            eleman->next = head;
            head -> next = eleman;
            head = eleman;
            cout << head << " kayıt başa eklendi." << endl;
            
        }
        else{
            
            struct node * temp = head;
            
            while (temp->next != head) {
                temp = temp-> next;
            }
        
            eleman ->next = head;
            head = eleman;
            temp->next = head;
            cout << head << " kayıt başa eklendi." << endl;
            
        }
    }
    
    
}

void sonaEkle (int key){ //geri dönüşü olmayan void bir değer

    struct node *eleman = new node (); //struct ını oluşturdum istediğim kadar
    //nesne oluşturabilirim artık
    
    eleman->data = key;
    
    if (head == NULL) {
        head = eleman;
        head -> next = head;
        cout << eleman->data << " ilk kayıt eklendi." << endl;
        
        
        //tek yönlü dairesel olduğu için tek eleman olunca kendi kendini gösteren düğüm olması gerekiyor.
    }
    else{
        if (head->next==head) {
            
            head -> next = eleman;
            eleman -> next =head ;
            cout << eleman->data << " kayıt sona eklendi." << endl;
            
        }
        else{
            
            struct node * temp = head;
            
            while (temp->next != head) {
                temp = temp-> next;
            }
        
            temp -> next = eleman;
            eleman -> next = head;
            
            cout << eleman->data << " kayıt sona eklendi." << endl;
            
        }
    }
    
    
}

void arayaEkle (int key , int sayi){ //geri dönüşü olmayan void bir değer
    
    bool sonuc = false;

    struct node *eleman = new node (); //struct ını oluşturdum istediğim kadar
    //nesne oluşturabilirim artık
    
    eleman->data = key;
    
    if (head == NULL) {
        head = eleman;
        head -> next = head;
        cout << head << " ilk kayıt başa eklendi." << endl;
        
        //tek yönlü dairesel olduğu için tek eleman olunca kendi kendini gösteren düğüm olması gerekiyor.
    }
    else{
        if (head->next==head) {
            eleman->next = head;
            head -> next = eleman;
            head = eleman;
            cout << head << " kayıt başa eklendi." << endl;
            sonuc = true;
            
        }
        else{
           
            struct node * temp = head;
            
            while (temp-> next != head ) { // ilk düğümü gösterdiği an son düğümdedir.
                if (temp->next->data == sayi) {
                    struct node * temp2 = temp;
                    struct node * temp3 = temp->next;
                    temp2->next=eleman;
                    eleman->next=temp3;
                    
                    cout << "Araya eleman eklendi." << endl;
                    
                    sonuc = true;
                }
                temp = temp -> next;
                
            }
            
            
           
        }
        if (!sonuc) { // false yazdık normal değeri olumsuzsa içeri girer zaten
            cout << "ekleme yapılmadı." << endl;
            
        }
    }
    
    
    
}

void yazdir (){
  
    
    struct node *temp = head;
    
    if (head == NULL) {
        cout << "liste boş" << endl;
    }
    else {
        while (temp->next !=head) {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << temp->data << "  ";
        
    }
    
    
    
}

void bastanSil(){
    
    if (head == NULL) {
        cout << "liste boş silenecek eleman bulunamadı." << endl;
    }
    else{
     
        if (head->next == head) {
            delete head;
            head = NULL;
            cout << "listedeki tek düğüm silindi." << endl;
            
        }
        else{
            struct node * temp = head;
            
            while (temp -> next != head) {
             
                temp = temp -> next;
                
                
            }
            struct node * temp2 = head -> next;
            
            delete head;
            head = temp2;
            temp->next =head;
            cout << "baştaki eleman silindi." << endl;
            
        }
        
    }
    
    
}

void sondanSil(){
    
    if (head == NULL) {
        cout << "liste boş silenecek eleman bulunamadı." << endl;
    }
    else{
     
        if (head->next == head) {
            delete head;
            head = NULL;
            cout << "listedeki tek düğüm silindi." << endl;
            
        }
        else{
            struct node * temp = head;
            
            while (temp -> next->next != head) {
             
                temp = temp -> next;
                
                
            }
            delete temp ->next;
            temp -> next = head;
            cout << "Sondaki düğüm silindi.";
       
        }
        
    }
    
    
}

void aradanSil(int key){
    
    bool sonuc = false;
    
    if (head == NULL) {
        cout << "liste boş silenecek eleman bulunamadı." << endl;
        sonuc = true;
    }
    else{
     
        if (head->next == head && head->data==key) {
            delete head;
            head = NULL;
            cout << "listedeki tek düğüm silindi." << endl;
            sonuc = true;
            
        }
        else{
            struct node * temp = head;
            
            while (temp ->next != head) {
                
                if (temp ->next->data == key) {
                    
                    struct node * temp2 = temp; // düğüm oluşturuyoruz.
                    struct node * temp3 = temp->next->next;
                    
                    delete temp->next;
                    
                    temp2 -> next = temp3;
                    
                    cout << "aradaki düğüm silindi" << endl;
                    sonuc = true;
                    
                    break;
                }
                
                temp = temp -> next;
            }
            
        }
        if (!sonuc) {
            cout << key << " değerli düğüm listede yoktur.";
        }
        
    }
}





int main() {
    int sayi , secim , sayi2;
    
    while (1) {
        cout << endl;
        
        cout << "TDBL uygulaması" << endl;
        
        cout << "1- Başa ekle" << endl;
        cout << "2- Sona ekle" << endl;
        cout << "3- Araya ekle" << endl;
        cout << "4- Baştan Sİl" << endl;
        cout << "5- Sondan Sİl" << endl;
        cout << "6- Aradan Sil" << endl;
        cout << "7- Yazdır" << endl;
        cin >> secim;
        
        switch (secim) {
            case 1:
                cout << "Başa eklenecek sayı: ";
                cin >> sayi;
                basaEkle(sayi);
                break;
                
            case 2:
                cout << "Sona eklenecek sayı: ";
                cin >> sayi;
                sonaEkle(sayi);
                break;
                
            case 3:
                cout << "Araya eklenecek sayı: ";
                cin >> sayi;
                cout << "Hangi sayıdan önce eklensin?: ";
                cin >> sayi2;
               arayaEkle(sayi , sayi2);
                break;
                
            case 4:
                bastanSil();
                break;
            case 5:
                sondanSil();
                break;
                
            case 6:
                
                cout << "Aradan silenecek düğümün değeri: ";
                cin >> sayi;

                aradanSil(sayi);
                break;
                
            case 7:
                yazdir();
                break;
            
            default:
                cout << "Geçersiz bir değer girdiniz" << endl;
                break;
        }
    }
     
    return 0;
}
