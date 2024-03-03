#include <iostream>
using namespace std;

struct node { // düğüm oluşturma kalıbı node düğüm demek
    
    int data;
    struct node * next; // gösterici pointer oluşturduk
    
    
};

int main() {
    
    struct node * n1 = new node(); // ilk düğümü oluşturduk ve bellekte yer ayırdık
    struct node * n2 = new node(); // ikinci düğümü oluşturduk ve bellekte yer ayırdık
    struct node * n3 = new node(); // üçüncü düğümü oluşturduk ve bellekte yer ayırdık
    
    n1 -> data = 11; // düğümler bellekte oluştu
    n2 -> data = 12;  // düğümlerin verilerini girdik
    n3 -> data = 13;
    
    n1 -> next = n2; // bellekte n1 n2'yi gösteriyor artık * pointer kullanıyoruz. Next pointer demek
    n2 -> next = n3;
    n3 -> next = NULL;
    
    
    struct node * temp = n1; //birinci düğümü gösteren geçici düğüm oluşturduk
    
    while (temp != NULL) //temp nulla eşit olmayana kadar true döner
    {
        cout << temp -> data << " ";
        
        temp = temp -> next;
        
        }

    
    
    
    
    
                            

 
    return 0;
}
