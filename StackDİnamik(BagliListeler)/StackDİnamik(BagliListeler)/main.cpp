#include <iostream>
#define SIZE 10 // STACK İN DEPOSUNU BELİRLİYOR
using namespace std;

struct node{ // stacke eklenecek düğümün kalıbı
    int data;
    
    struct node * next;
};


struct stack {
    struct node * top = NULL; // bağlı liste yapısını kullanarak düğüm oluşturduk ilk düğümün ismi top , ilk düğümü oluşturduk
    
    int cnt =  0;
};

bool isFull(stack * stk){
    return ( stk->cnt == SIZE);
}

bool isEmpty ( stack * stk){
    return (stk->cnt == 0);
}


void push(stack * stk  , int key){ // düğüm ekler
    
    struct node * eleman = new node();
    eleman -> data = key;
    
    if (isFull(stk)) {
        cout << "stack doludur" << endl;
    }
    else if(isEmpty(stk)){
        
        stk -> top = eleman;
        
        eleman -> next = NULL; // en son düğüm hep null u gösterecek
        
        cout << "Stack oluşturuldu ve ilk düğüm eklendi" << endl;
    }
    else{
        eleman -> next = stk -> top;
        
        stk->top = eleman;
        
        cout << "stack e düğüm eklendi" << endl;
        
        stk->cnt++;
        
        
    }
    
}

void pop(stack * stk){ // çıkartır
    if (stk->cnt == 0) {
        cout << "stack boş çıkartılacak düğüm yoktur" << endl;
    }
    else {
        cout <<  stk->top->data << " değerini içeren düğüm silindi" << endl;
        struct node * temp = stk->top->next;
        delete stk->top; // düğüm silindi
         
        stk->top = temp;
        
        stk->cnt--;
        
        
    }
    
}

void top(){
    
    
    
    
}
    
}

void print(){
    
    
    
}


int main() {
   
    
    
    return 0;
}
