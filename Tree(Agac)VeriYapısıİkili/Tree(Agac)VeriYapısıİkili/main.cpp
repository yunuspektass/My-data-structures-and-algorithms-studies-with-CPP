#include <iostream>
using namespace std;

struct node{ // ağaç yapımıza ekleyeceğimiz düğümün kalıbı
    int data;
    struct node * left;
    struct node * right;
};
//root ilk kök düğüm önemli

struct node * kokDugum(int key){
    //ağaç yapımızı oluşturduk kök düğümü oluşturduk
    struct node * root = new node(); // ilk düğümü eklemek için
    root->data =key;
    root->left=NULL;
    root->right=NULL;
    
    return root; // root un aderisini dönüyor
}

struct node * dugumEkle(struct node * root , int key){
    if (root == NULL) {
        root = kokDugum(key);
    }
    else{
        if (key < root->data) {
            root->left= dugumEkle(root->left, key);
        }
        else{ // büyük yada eşitse sağ eklenir
            root->right = dugumEkle(root->right, key);
        }
    }
    return  root;
}

void preOrder(struct node * root){ // önce kök
    if (root !=NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node * root){ // ortada kök
    if (root !=NULL) {
       
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    
}

void postOrder(struct node * root){ // sonda kök
    if (root !=NULL) {
        
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int dugumSayisi(struct node * root)
{
    if (root == NULL) {
        return 0;
    }
    else{
        return   dugumSayisi(root->left) + 1 + dugumSayisi(root -> right);
    }
}

int yukseklik(struct node * root){
    // derinlik , yükseklik en son dalın roota olan uzaklığı köke olan uzaklığı
    if (root == NULL) {
        return 0;
    }
    else{
        int sol,sag;
        
        sol = yukseklik(root -> left);
        sag = yukseklik(root -> right);
        
        if (sol > sag) {
            return sol+1;
        }
        else{
            return sag + 1;
        }
    }
}

void yerDegistir(struct node * root){
    struct node * temp = NULL;
    
    if (root != NULL) {
    
        yerDegistir(root->left);
        yerDegistir(root->right);
        
        temp = root->left;   // swap işlemi yapıldı
        root->left =root-> right;
        root->right = temp;
        
        
    }
    //AVL ağacı sağ dal ile sol dal arasında maksimum yükseklik 1 olacak 1 den fazla olursa avl olmaz
    // kendi içindeki dallarda önemli sağ ve solun
    
}


int main(int argc, const char * argv[]) {
    struct node * root = NULL;
    int sayi;
    int i = 0;
    
    while (i<7) {
        cout << "sayi girin: " ; cin >>sayi;
        
        root = dugumEkle(root, sayi);
        
        i++;
    }
    
    cout << "preOrder: " ; preOrder(root);
    cout << endl;
    cout << "inOrder: "; inOrder(root);
    cout << endl;
    cout <<"postOrder: ";  postOrder(root);
    cout << endl;
    cout << "eklenen düğüm sayısı: " << dugumSayisi(root);
    cout << endl;
    cout << "ağacın yüksekliği: " << yukseklik(root);
    cout << endl;
    cout << "dallar yer değiştirildi:  " << endl;
    yerDegistir(root);
    cout << "inOrder: "; inOrder(root); // dallar yer değiştirince inOrder büyükten küçüğe sıralayacak
    
    return 0;
}
