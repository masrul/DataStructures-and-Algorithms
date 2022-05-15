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
    size_t size;
    SLL();
    void push_back(int);
    void push_front(int);
    void pop_back();
    void pop_front();
    void clear();
    void print();
    bool empty();
    void sort();
    void reverse();
private:
    Node *head;
};

SLL::SLL(){
    size = 0;
    head = nullptr;
}

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
    std::cout << "Yet to be implemented!!!\n";
}

void SLL::reverse(){
    Node* current = head; 
    Node* prev = nullptr; 
    Node* next = nullptr; 

    while(current !=nullptr){
        next = current->next;
        current->next = prev; 
        prev = current; 
        current = next;
    }
    head = prev;
}

int main(){

    SLL  sll;
    for (int i =0; i<10;++i)
        sll.push_front(i);
    sll.push_front(-1);
    sll.push_front(-2);
    
    sll.print();
    sll.reverse(); 
    sll.print();
    sll.clear();
    sll.print();

    return 0;
}

