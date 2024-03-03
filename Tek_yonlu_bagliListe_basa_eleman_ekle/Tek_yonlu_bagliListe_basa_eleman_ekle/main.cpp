
#include <iostream>
using namespace std;

struct node { // yapımızı oluşturduk.
    int data;
    struct node * next;

};

struct node * basaEkle(struct node * head , int key) {//metod oluşturduk
    
    
    if (head == NULL) { // head ilk düğüm demek null ise oluşturulmamış
        struct node * temp = new node();
        temp->data = key;
        temp -> next =NULL;
        
        head = temp; // ilk düğüm olarak atadık.
        
        cout << "ilk düğüm oluşturuldu." << endl;
    }
        
        else {
            struct node * temp = new node();
            temp->data = key;
            temp -> next = head;//başa ekliyoruz yani
            
            head = temp; // headi güncelledik basa eleman ekledikç
            
            cout << "listenin başına düğüm eklendi" << endl;
            
        }
        return  head;
}

struct node * sonaEkle(struct node * head , int key) {//metod oluşturduk
    
    
    if (head == NULL) { // head ilk düğüm demek null ise oluşturulmamış
        struct node * temp = new node();
        temp->data = key;
        temp -> next =NULL;
        
        head = temp; // ilk düğüm olarak atadık.
        
        cout << "ilk düğüm oluşturuldu." << endl;
    }
        
        else {
            struct node * temp = new node();
            temp->data = key;
            temp -> next = NULL;//son düğüm null u gösteriyor
            
    
            struct node  * temp2 = head;
            
            while (temp2->next != NULL)
                temp2 = temp2 -> next;
                
                temp2 -> next = temp;
                cout << "listenin sonuna eleman eklendi" << endl;
            
            
            
        }
        return  head;
}

void verileriYazdır (struct node * head){
    
    system("cls"); // ekranı temizler
    
    if (head == NULL) {
        cout << "listeniz boş" << endl;
    }
    else{
        
        
        struct node * temp = head;
        
        while (temp != NULL)
            
        {
            cout << temp->data << "  " ;
            temp = temp -> next;
            
            
        }
    }
        
    
}

void tümBİlgileriYazdir (struct node * head){
    
    system("cls"); // ekranı temizler
    
    if (head == NULL) {
        cout << "listeniz boş" << endl;
    }
    else{
        
        
        struct node * temp = head;
        int i = 1;
        
        while (temp != NULL)
            
        {
            cout << i << ". düğümün datası:" << temp->data << "adresi: " << temp << "bir sonraki düğümün adresi: " << temp -> next << endl;
            temp = temp -> next;
            i++;
            //sadece temp yazarsak pointerı yazarsak sadece adresi döner
            
        }
    }
        
    
}

int dugumAdeti(struct node * head){
    
    int adet = 0;
    
    if (head==NULL) {
        cout << "liste boş" << endl;
        return 0;
    }
    else{
        struct node * temp = head;
        
        while (temp != NULL) {
            
            adet++;
            
            temp = temp -> next;
            
            
        }
        return adet;
    }
    
}
int verilerinToplamı(struct node * head){
    
    int toplam = 0;
    
    if (head==NULL) {
        cout << "liste boş" << endl;
        return 0;
    }
    else{
        struct node * temp = head;
        
        while (temp != NULL) {
            
            toplam += temp -> data; // dataları topluyoruz
            
            temp = temp -> next; //bir sonraki düğüme geçiyoruz
            
            
        }
        return toplam;
    }
    
}
void veriAra ( struct node * head , int arananSayi) {
    bool sonuc = false;
    if (head == NULL) {
        cout << "liste boştur" << endl;
    }
    else{
        
        int index = 0 ;
        struct node * temp = head;
        
        while (temp != NULL) {
            index++;
            if (temp->data == arananSayi) {
                sonuc  = true;
                
                break;
            }
            temp = temp->next;
        }
            if (sonuc == true) {
                cout << arananSayi << " sayısı listede vardır ve düğüm sırası:" << index << endl;
            
            }
            else
                cout << "aranan sayı listede yoktur" << endl;
        
    }
}
struct node * bastanSil(struct node* head){
    if (head == NULL) {
        cout << "liste boştur. Silenecek duğüm yoktur.";
    }
    else{
        if (head -> next == NULL) {
            delete head;
            head = NULL;
        }
        else{
            struct node * temp = head -> next;
            
            delete head; // ilk düğüm silindi
            
            head = temp;
        }
        
    }
    return head;
    
}

struct node * sondanSil(struct node* head){
    if (head == NULL) {
        cout << "liste boştur. Silenecek duğüm yoktur.";
    }
    else{
        if (head -> next == NULL) {
            delete head;
            head = NULL;
        }
        else{
            struct node * temp = head;
            while (temp ->next->next != NULL) {
                temp = temp -> next;
                
                struct node * temp2 = temp;
                
                delete temp -> next;
                
                temp2 -> next = NULL;
                
            }
            
        }
        
    }
    return head;
    
}




int main() {
    
    struct node * head = NULL;
    
    int sayi , secim , n;
    
    while (1) { // 1 sonsuz döngü true
        cout << endl;
        cout << " tek yönlü doğrusal bağlı liste uygulaması" << endl;
        cout << "1- başa eleman ekle" << endl;
        cout << "2- sona eleman ekle" << endl;
        cout << "3- verileri yazdır." << endl;
        cout << "4- listedeki tüm bilgileri yazdır." << endl;
        cout << "5- düğüm adeti" << endl;
        cout << "6- verilerin toplamı" << endl;
        cout << "7- arama yap" << endl;
        cout << "8- baştan eleman sil" << endl;
        cout << "9- sondan eleman sil" << endl;
        cout << "10- ÇIKIŞ" << endl;
        cout << "Seçiminiz:" ;
        cin >> secim;
        switch (secim) {
            case 1:
                cout << "başa eklenecek sayı:" ;
                cin >> sayi;
                
                head = basaEkle(head, sayi);
                break;
            case 2:
                cout << "sona eklenecek sayı:" ;
                cin >> sayi;
                
                head = sonaEkle(head, sayi);
                break;
                
            case 3:
               
                verileriYazdır(head);
                break;
                
            case 4:
                tümBİlgileriYazdir(head);
                break;
                
            case 5:
                n = dugumAdeti(head);
                cout << "listedeki düğüm adeti:" << n << endl;
                
                break;
                
            case 6:
                n = verilerinToplamı(head);
                cout << "listedeki verilerin toplamı:" << n << endl;
                
                break;
            case 7:
                cout << "aranan sayıyı giriniz:" ;
                cin >> sayi ;
                veriAra(head, sayi  );
                
                break;
            case 8:
                head = bastanSil(head);
                break;
            case 9:
                head = sondanSil(head);
                break;
            case 10:
                cout << "çıkış yapıldı... " << endl;
                return 0;
                
            default:
                cout << "hatalı seçim yaptınız" << endl;
                break;
              
        }
    }
 
    return 0;
}
