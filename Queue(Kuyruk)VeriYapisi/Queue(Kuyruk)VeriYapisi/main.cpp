
#include <iostream>
using namespace std;
#define SIZE 10

struct queue{
    int data [SIZE ];
    int cnt;
    int front;
    int rear;
    
    
};

void initialize (  queue * q ){
    
    q->cnt = 0;
    q->front=0;
    q->rear=-1;
    
}
bool isFull(queue * q){
    
    return (q -> cnt == SIZE);
}

bool isEmpty(queue * q){
    return (q->cnt == 0); // cnt kuyruk eleman sayısını verir
    //cnt ekleme yaptıkça artar sildikçe azalır
    
}

void enqueue(queue * q , int key) // kuyruğa eleman ekler , sondan ekler
{
    if (isFull(q)) {
        cout << "kuyruk doldu" << endl;
    }
    else{
        q->rear++; // rear sadece indis değer tutmaz son değeri
        
        if (q-> rear == SIZE) {
            q->rear = 0;
            //dizinin son indisini gösteriyorsa taşma hatası olmaması için rear set edildi
        }
        q->data[q->rear] = key;
        cout  <<  "kuyruğa eleman eklendi" << endl;
        q->cnt++;
    }

}
void dequeue(queue * q){ // kuyruktan eleman çıkartır
    if (isEmpty(q)) {
        cout << "kuyruk boş silenecek eleman yok" << endl;
        
    }
    else{
        int x = q->data[q->front];
        q->front++;
        if (q->front == SIZE) {
            q->front = 0;
            //dizinin ilk indisi dizinin boyutuna ulaşmışsa set ediyoruz
        }
        cout << x << " kuyruktan silindi" << endl;
        q->cnt--;
    }
 
}

void print(queue * q){
    if (isEmpty(q)) {
        cout << "kuyruk boş yazdırılacak değer yoktur." << endl;
    }
    else{
        for (int i = q->rear ;i>=q->front; i--) {
            cout << q->data[i] << " -> ";
            
        }
    }
    
}



int main(int argc, const char * argv[]) {

    queue qu ;
    
    initialize(&qu );
    
    int sayi , secim ;
    
    while (1) {
        cout << "KUYRUK UYGULAMASI" << endl;
        cout << "1 - enqueue" << endl;
        cout << "2 - dequeue" << endl;
        cout << "3 - print " << endl;
        
        cin >> secim;
        
        switch (secim) {
            case 1:
                cout << "sayı giriniz :" ; cin >> sayi;
                enqueue(&qu , sayi);
                break;
                
            case 2:
                dequeue(&qu);
                break;
            case 3:
                print(&qu);
                break;
                
                
        }
    }
    
    
    
    return 0;
}
