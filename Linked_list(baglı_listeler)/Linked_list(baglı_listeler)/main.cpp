
#include <iostream>
using namespace std;
//tek yönlü doğrusal bağlı listew

struct node { // kalıp tanımladık düğüm oluşturacağız
    int data;
    struct node * next; // ileri gitmesini gösteren pointer
    
};

int main() {
    
    struct node * n1 = new node(); // bellekte yer aldık ilk düğümdür
  n1->data=11;
    
    struct node * n2 = new node(); // bellekte yer aldık ikinci düğümdür
   n2->data=12;
    
    
    struct node * n3 = new node(); // bellekte yer aldık üçüncü düğümdür
   n3->data=13;
    
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = NULL; //tek yönlü doğrusal bağlı listenin özelliği son düğüm null'u gösterir
    
    struct node * temp = n1;
    
    while (temp != NULL) {
        cout << temp->data << " " ;
        temp = temp->next;
    }
    
    
    
    
   
    return 0;
}
