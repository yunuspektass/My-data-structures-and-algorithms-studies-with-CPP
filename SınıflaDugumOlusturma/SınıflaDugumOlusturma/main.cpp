
#include <iostream>
using namespace std;

class node { // sınıftan klaıp oluşturduk
public:
    int data;
    
    node * next; // pointer oluşturma
    
    node (int data) {
        this->data = data;
    }
    
    
};

int main() {
    
    node *n1 = new node(11); // nesne tanımlayıp ve değeri atadık ( nesne = düğüm)
    node *n2 = new node(22); // nesneyi pointer olarak tanımlamalıyız birbirini göstermesi için pointer olarak tanımlamak için * koymalıyız.
    node *n3 = new node(33);
    
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = NULL;
    
    node * temp = n1; // temp geçici personel demek geçici anlamı var
    
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
    
    
    
    
    
    
    return 0;
}
