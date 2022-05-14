/**
 * @author      : MasrulHuda (MasrulHuda@Masruls-MBP)
 * @file        : singly_linked_list
 * @created     : Wednesday May 11, 2022 00:14:44 CDT
 */

#include<iostream>
#include<queue>

class  Node{
public: 
    int key;
    Node *next; 
    Node(int);
};

Node::Node(int _key){
    key = _key;
    next = nullptr;
}


class SLL{
public:
    size_t size=0;
    void push_back(int);
    void push_front(int);
    void pop_back();
    void pop_front();
    void clear();
    void print();
    bool empty();
    void sort();

private:
    Node *head = nullptr;
};

void SLL::push_back(int key){
    ++size;
    if (head == nullptr){
        head = new Node(key);
    }
    else{
        Node *current = head; 
        while (current->next !=nullptr)
            current = current->next;
        current->next = new Node(key);
    }
}

void SLL::push_front(int key){
    ++size;
    if (head == nullptr){
        head = new Node(key);
    }
    else{
        Node *front = new Node(key);
        front->next = head;
        head = front;
    }
}

void SLL::pop_back(){
    Node *prev;
    Node *current; 

    if (head == nullptr)return;  // empty 
    else if (head->next == nullptr){  // only one element 
        --size;
        delete head;
        head = nullptr;
    }
    else{
        --size;
        prev = head;
        current = prev->next; 

        while (current->next !=nullptr){
            prev = current; 
            current = prev->next;
        }
        
        delete current;
        prev->next = nullptr;
    }
}

void SLL::pop_front(){
    if (head==nullptr)return; 

    Node *front = head;
    head = head->next; 
    delete front;
    --size;
}


void SLL::print(){
    Node *current=head;

    while (current !=nullptr){
        std::cout<<current->key<<std::endl;
        current = current->next;
    }
}

void SLL::clear(){
    while (head !=nullptr){
        Node *temp = head; 
        head = head->next;
        delete temp;
    }
}

bool SLL::empty(){
    return head==nullptr ? true:false;
}

void SLL::sort(){
    Node *_head=nullptr;
    Node *_current=nullptr;
    Node *_prev=nullptr;

    while (!empty()){
        int _key = head->key;
        pop_front();

        if (_head==nullptr){
            _head = new Node(_key);
        }
        else{
            _current = _head; 
            while( _current !=nullptr & _key > _current->key){

                _current = _current->next;
                
            }
            
        }



    }
}


using std::cout;
using std::endl;

int main(){

    SLL  sll;
    /* for (int i =0; i<10;++i) */
    /*     sll.push_front(i); */
    /* sll.push_front(-1); */
    /* sll.push_front(-2); */
    
    /* sll.print(); */
    /* sll.clear(); */
    /* sll.print(); */

    sll.sort();

    return 0;
}

