/*
 çift yönlü doğrusal bağlı listede geriyi göstermeye prev denir
 en baştaki düğümün previ ve sondaki düğümün nexti NULL u gösterir.
  
 her düğüm ileriyi ve geriyi gösterir. Her düğümde iki adet gösterici vardır.

 */

//Çift yönlü doğrusal bağlı liste uygulaması

#include <iostream>
using namespace std;

struct node{
    int data;
    struct node * next; //nexti gösteren göstericimiz pointerımız
    struct node * prev; //bir önceki düğümü gösteren göstericimiz. previmi<
};

struct node * head = NULL; //en baştaki düğümümüze head diyoruz

void basaEkle(int key)
{
    struct node * eleman = new node();//new node diyerek bellekte yer ayırıyoruz
    
    eleman->data=key;
    
    if (head == NULL) {
        head = eleman;
        head->next = NULL; // tek düğüm olduğu için baş ve son düğüm oluyor.
        head -> prev = NULL; //çift yönlüde prev vardır gerideki düğümü gösterir
        cout << "ilk eleman eklendi.";
        //nexte ve preve değer vermeyi unutma yoksa hata verir.
    }
        else
        {
            
            eleman -> next = head;
            head->prev = eleman;
            head = eleman;
            
            cout << "başa eleman eklendi" << endl;
 
        }
    }

void sonaEkle(int key)
{
    struct node * eleman = new node();//new node diyerek bellekte yer ayırıyoruz
    
    eleman->data=key;
    
    if (head == NULL) {
        head = eleman;
        head->next = NULL; // tek düğüm olduğu için baş ve son düğüm oluyor.
        head -> prev = NULL; //çift yönlüde prev vardır gerideki düğümü gösterir
        cout << "ilk eleman eklendi.";
        //nexte ve preve değer vermeyi unutma yoksa hata verir.
    }
        else
        {
            struct node * temp = head; // headimiz ilk elemandır.
            
            while (temp -> next != NULL ) {
                
                temp = temp -> next;
            }
            temp -> next = eleman;
            eleman -> prev = temp;
            eleman -> next = NULL;
            
            cout << "sona eleman eklendi" << endl;
        }
    }

void arayaEkle(int key , int sayi)
{
    struct node * eleman = new node();//new node diyerek bellekte yer ayırıyoruz
    
    eleman->data=key;
    
    if (head == NULL) {
        head = eleman;
        head->next = NULL; // tek düğüm olduğu için baş ve son düğüm oluyor.
        head -> prev = NULL; //çift yönlüde prev vardır gerideki düğümü gösterir
        cout << "ilk eleman eklendi.";
        //nexte ve preve değer vermeyi unutma yoksa hata verir.
    }
        else
        {
            struct node * temp = head;
            
            while (temp->next != NULL) {
                
                if (temp->data == sayi) {
                    struct node * temp2 = temp->prev;
                    struct node * temp3 = temp;
                    
                    
                    temp2->next = eleman;
                    eleman-> prev = temp2;
                    
                    eleman->next = temp3;
                    temp3 ->prev = eleman;
                    
                    
                    
                    cout << "araya ekleme yapıldı" << endl;
                    break; // araya ekledik ve while durdurduk
                }
                
                temp = temp -> next;
            
                }
            if (temp->data == sayi) {
                struct node * temp2 = temp->prev;
                struct node * temp3 = temp;
                
                
                temp2->next = eleman;
                eleman-> prev = temp2;
                
                eleman->next = temp3;
                temp3 ->prev = eleman;
                
                
                
                cout << "araya ekleme yapıldı" << endl;
                
                
            }
        }
    }

void bastanSil()
{
    if (head == NULL) {
        cout << "Liste boştur" << endl;
    }
    else
    {
        if (head->next ==NULL) { // headin nexti null ise tek düğüm demektir
            delete head;
            head = NULL;
            
            cout << "Listedeki son düğüm silindi." << endl;
        }
        else{
            struct node * temp = head -> next;
            delete head;
            
            cout << "Baştaki düğüm silindi" << endl;
            
            head = temp; // en baştaki düğüm head dir. 1. düğüm
            head -> prev = NULL; // silip eklediğin düğümlerin previni değiştirmeyi unutma. prev öncesi
            //nexti vardı previni ekledik.
            
        }
    }
}

void sondanSil()
{
    if (head == NULL) {
        cout << "Liste boştur" << endl;
    }
    else
    {
        if (head->next ==NULL) { // headin nexti null ise tek düğüm demektir
            delete head;
            head = NULL; // baştaki düğüm olmadığı için NULLa bağladık
            
            cout << "Listedeki son düğüm silindi." << endl;
        }
        else{
            struct node * temp = head;
            
            while (temp->next != NULL) {
                
                
                temp = temp -> next;
            }
            struct node * temp2 = temp ->prev;
            delete temp;
            
            temp2->next = NULL;
            cout << "Sondan Eleman Silindi." << endl;
        }
    }
}

void aradanSil(int key)
{
    if (head == NULL) {
        cout << "liste boş" << endl;
    }
    
    else{
        if (head -> next == NULL && head -> data == key)     {
         
            delete head;
            head = NULL;
            
            cout << "listede kalan son düğüm silindi" << endl;
            
        }
        
        else {
            

            struct node * temp = head;
            
            while (temp -> next != NULL) {
                if (temp -> data == key) {
                    
                    struct node * temp2 = temp -> prev;
                    struct node * temp3 = temp -> next;
                    
                    delete temp;
                    
                    temp2 -> next = temp3;
                    temp3 -> prev = temp2;
                    
                    cout << " aradaki eleman silindi " << endl;
                    break;
                    
                }
                
                temp = temp -> next;
            }
            
        }
    }
    
}

void yazdir(){
    
    if (head == NULL) { // değeri boşsa düğüm yoktur NULL
        cout << "liste boş"  << endl;
    }
    else{
        struct node * temp = head;
        while (temp->next != NULL ) {
            
            cout << temp->data << " ";
            
            temp = temp -> next;
        }
        cout << temp->data << " "; // son düğümün değeri while girmeyeceği için

    }
    
}


    
int main(int argc, const char * argv[]) {
    
    int sayi , secim ,sayi2;
    
    while (1) {
        cout << endl;
        
        cout << "1- Başa ekle" << endl;
        cout << "2- Sona ekle" << endl;
        cout << "3- Araya ekle" << endl;
        cout << "4- Baştan sil" << endl;
        cout << "5- Sondan sil" << endl;
        cout << "6- Aradan sil" << endl;
        cout << "7- Yazdır" << endl;
        cin >> secim;
        
        switch (secim) {
            case 1:
                cout << "Başa eklenecek sayı:";
                cin >> sayi;
                basaEkle(sayi);
                break;
                
            case 2:
                cout << "Sona eklenecek sayı:";
                cin >> sayi;
                sonaEkle(sayi);
                break;
                
            case 3:
                cout << "Araya eklenecek sayı:";
                cin >> sayi;
                cout << "Hangi sayıdan önce eklenecek";
                cin >> sayi2;
                
                arayaEkle(sayi, sayi2);
                break;
                
            case 4:
                bastanSil();
                break;
                
            case 5:
                sondanSil();
                break;
               
            case 6:
                cout << "aradan silenecek sayı: ";
                cin >> sayi;
                aradanSil(sayi);
                break;
               
                
                
            case 7:
                yazdir();
                break;
                
            default:
                
                break;
        }
    }
    
    
 
    
    return 0;
}
