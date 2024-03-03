

#include <iostream>
using namespace std;

#define SIZE 10

struct node {
    int data;
    struct node * next;
};

struct queue{
    int adet;      // kuyruğun kapasitesini aşmamak için kullanıyoruz
    struct node * front; // kuyruğun ilk düğümü
    struct node * rear; // kuyrukaki son düğüm
    
};

void basVer(queue * q){
    q->adet=0;
    q->rear = q->front = NULL;
}

bool doluMu(queue * q){
    return (q->adet==SIZE);
}
bool bosMu(queue * q){
    return (q->adet == 0);
}

void ekle(queue * q , int key){ // enqueue ekleme işlemidir
    
    struct node * eleman = new node();
    eleman->data = key;
    
    if (doluMu(q)) {
        cout << "kuyruk dolu" << endl;
    }
    else if(bosMu(q)){ // ilk eleman ekliyorum kuyruk boş
        eleman -> next = NULL;
       q-> rear = q->front = eleman;
        q->adet++;
        
        cout << key  << " ilk düğüm oluşturuldu kuyruğa eklendi " << endl;
    }
    else{
        eleman -> next = q->rear; // kuyruğun sonuna yemi gelen elamanı ekledim
        
        q->rear = eleman;
        q->adet++;
        
        cout << key << " kuyruğa eleman eklendi." << endl;
     
    }
    
}
void sil(queue * q) {
    if (bosMu(q)) {
        cout << "kuyruk boş silenecek düğüm yok ";
    }
    else if(q->adet==1){
        
        cout << q->front->data << " eleman silindi , kuyrukta eleman kalmadı " << endl;
        
        delete q->front;
        q->front = NULL;
        q->rear = NULL;
        q->adet--;
    }
    else{
        
        cout << q->front->data << " eleman silindi" << endl;
        
        struct node * temp = q->rear;
        
        while (temp -> next != q->front) {
            temp  = temp -> next;
        }
        delete q->front; // ilk düğümü isldik
        q->front = temp; // güncelleme yapıldı.
        q->front->next=NULL; // frontun ucunu NULL a bağla yoksa sonsuz döngüye girer
        q->adet--;
    
    }
}

void yazdir(queue * q){
    if (bosMu(q)) {
        cout << "kuyruk boş" << endl;
    }
    else{
        struct node * temp = q->rear;
        
        while (temp->next != NULL) {
            
            cout << temp->data << " - > " ;
            temp = temp -> next;
        }
        cout << temp->data << "  " ;
    }
}




int main(int argc, const char * argv[]) {
    queue qu;
    basVer(&qu ); // adres üzerinde işlem yapıyor & adresi eklemeyi unutma
    
    
    int sayi , secim ;
    
    while (1) {
        cout << "KUYRUK QUEUE UYGULAMASI" << endl;
        
        cout << " 1- ekle " << endl;
        cout << " 2- sil " << endl;
        cout << " 3- yazdır " << endl;
        cout << " 0- çıkış " << endl;
        cin >> secim;
        
        switch (secim) {
            case 1:
                
                break;
                
            
        }
        
        
        
    }
    
    
    
    
    
    
    
    return 0;
}
