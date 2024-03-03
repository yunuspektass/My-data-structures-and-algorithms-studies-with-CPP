#include <iostream>
using namespace std;

struct node {
    
    int data;
    
    struct node * next; // ileri
    struct node * prev; // geri
};

struct node * head = NULL; // en baştaki düğüm

void basaEkle(int key){
    struct node * eleman = new node();
    eleman -> data = key;
    
    if (head == NULL) {
        
        head = eleman;
        
        head->next=head;
        head->prev=head;
        
        cout << "liste oluşturuldu ilk düğüm eklendi." << endl;
        
    }
    else {
        
        struct node * temp = head;
        
        while (temp -> next != head) { // en son düğüm başı gösterir.
            
            
            temp = temp -> next;
        }
        eleman -> next = head;
        head -> prev = eleman;
        head = eleman;
        
        temp -> next = head;
        head -> prev = temp;
        
        
        cout << "başa düğüm eklendi." << endl;
    }
    
    
}

void sonaEkle(int key){
    struct node * eleman = new node();
    eleman -> data = key;
    
    if (head == NULL) {
        
        head = eleman;
        
        head->next=head;
        head->prev=head;
        
        cout << "liste oluşturuldu ilk düğüm eklendi." << endl;
        
    }
    else {
        
        struct node * temp = head;
        
        while (temp -> next != head) { // en son düğüm başı gösterir.
            
            
            temp = temp -> next;
        }
        temp -> next = eleman;
        eleman -> prev = temp;
        
        eleman -> next = head;
        head -> prev = eleman;
        
        cout << "Sona eleman eklendi" << endl;
    }
}

void bastanSil(){
    
    if (head == NULL) {
        cout << "liste boş silenecek düğüm yok." << endl;
    }
    
    else{
        
        if (head->next == head) {
            delete head;
            head = NULL;
            cout << "listedeki son düğüm silindi" << endl;
        }
        else{
            
            struct node * temp = head;
            
            while (temp -> next != head) {
                
                temp = temp->next;
            }
            struct node * temp2 = head -> next;
            delete head;
            head = temp2;
            head->prev = temp;
            temp -> next = head;
            cout << "baştan eleman silindi." << endl;
            
        }
        
    }

}

void sondanSil(){
    
    if (head == NULL) {
        cout << "liste boş silenecek düğüm yok." << endl;
    }
    
    else{
        
        if (head->next == head) {
            delete head;
            head = NULL;
            cout << "listedeki son düğüm silindi" << endl;
        }
        else{
            
            struct node * temp = head;
            
            while (temp -> next != head) {
                
                temp = temp->next;
            }
            struct node * temp2 = temp->prev;
            delete temp;
          
            temp2 -> next = head;
            head -> prev = temp2;
            
        
            cout << "sondan eleman silindi." << endl;
            
        }
        
    }

}

void aradanSil(int key){
  
    
    if (head == NULL) {
        cout << "liste boş silenecek düğüm yok." << endl;
    }
    
    else{
        
        if (head->next == head && head -> data == key) {
            delete head;
            head = NULL;
            cout << "listedeki tek düğüm silindi" << endl;
        }
        else if(head->next != head && head->data==key){
            //baştaki düğümü sileceğiz ama birden fazla düğüm var.
            // eğer baştakiyse istenen
            
            struct node * temp = head;
            
            while (temp -> next != head) {
                
                
                
                temp=temp->next;
            }
            struct node * temp2 = head->next;
            delete head;
            
            head=temp2;
            
            head->prev=temp;
            temp->next=head;
            
        }
        else {
            
            struct node * temp = head;
            
            while (temp->next != head) {
                
                if (temp->data==key) {
                    
                    struct node * temp2 = temp->prev;
                    struct node * temp3 = temp->next;
                    
                    delete temp;
                    
                    temp2->next=temp3;
                    temp3->prev=temp2;
                    
                    cout << "aradaki düğüm silindi" << endl;
                    break;
                }
                
                
                temp = temp->next;
            }
            if (temp->data==key) {
                
                struct node * temp2 = temp->prev;
              
                
                delete temp;
                
                temp2->next=head;
                head -> prev = temp2;
                
                cout << "son düğüm düğüm silindi" << endl;
            }
            
        }
        
    }

}



    void yazdir () {
        
        if(head == NULL) {
            
            cout << "Liste boştur" << endl;
        }
        else {
            struct node * temp = head;
            
            while (temp -> next != head) {
                
                cout << temp->data  << " ";
                
                
                
                temp = temp -> next;
            }
            cout << temp->data  << " ";
        }
    }
    
void adet(){
 
    if (head == NULL) {
        cout << "liste boş" << endl;
    }
    
    
    
}
    


int main() {
    
    int sayi,secim;
    
    while (1) {
        cout << endl;
        
        cout << "1- Başa ekle" << endl;
        cout << "2- Sona ekle" << endl;
        cout << "3- Yazdır" << endl;
        cout << "4- Baştan sil " << endl;
        cout << "5- Sondan sil " << endl;
        cout << "6- Aradan sil" << endl;
        cout << "0- Çıkış" << endl;
        cin >> secim;
        
        
        
        switch (secim) {
            case 1:
                cout << "listinin başına eklenecek değer :" ; cin >> sayi;
                basaEkle(sayi);
                break;
            case 2:
                cout << "listenin sonuna eklenecek değer :" ; cin >> sayi;
                sonaEkle(sayi);
                break;
            case 3:
                yazdir();
                break;
            case 4:
                bastanSil();
                break;
            case 5:
                sondanSil();
                break;
            case 6:
                cout << "aradan silenecek düğüm değeri: " ; cin >> sayi;
                aradanSil(sayi);
                break;
            case 0:
                cout << "Programdan çıkılıyor." << endl;
                return 0;
                break;
                
                
                
            default:
                break;
        }
    }
   
    return 0;
}
