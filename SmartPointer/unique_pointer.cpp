#include <iostream>
#define DEBUG 1 
#if DEBUG
    #define LOG(x) std::cout<<"Calling "<<x<<"\n"
#else 
    #define LOG(x) 
#endif 


namespace SMART_PTR {

template <typename T>
class unique_ptr {
public:
    
    T* raw_ptr; 

    // Empty constructor 
    unique_ptr(){};
    
    // Constructor from raw pointer 
    explicit unique_ptr(T* resource): raw_ptr(resource){};

    // copy constructor 
    unique_ptr(const unique_ptr<T>&) = delete;

    // move constructor 
    unique_ptr(unique_ptr<T>&& other){  
        LOG("move constructor");

        raw_ptr = other.raw_ptr;
        other.raw_ptr = nullptr;
    }

    // Copy  assignment operator 
    unique_ptr& operator=(const unique_ptr&) = delete;

    // Move assignment operator 
    unique_ptr& operator=(unique_ptr&& other){
        LOG("move assignment operator");

        raw_ptr = other.raw_ptr;
        other.raw_ptr = nullptr;
        return (*this); 
    }

    // destructor 
    ~unique_ptr(){
        LOG("destructor");

        if (raw_ptr != nullptr)
            delete raw_ptr;
        raw_ptr=nullptr;
    }

    // Overloading *
    T& operator*(){
        return *raw_ptr;
    }

    // Overloading ->
    T* operator->(){
        return raw_ptr;
    }

    // releasing managed resource 
    T* release(){
        T* temp = raw_ptr; 
        raw_ptr = nullptr;
        return temp;
    }

    // swap managed resources 
    void swap(unique_ptr<T>& other){
        T* temp = other.raw_ptr;
        other.raw_ptr = raw_ptr; 
        raw_ptr = temp; 
    }
};

template <typename T>
unique_ptr<T> make_unique(){
}

}


int main()
{
    SMART_PTR::unique_ptr<int> ptr1(new int(5));    
    *ptr1 = 7; 

    SMART_PTR::unique_ptr<int> ptr2(std::move(ptr1));
    *ptr2 = 9; 

    SMART_PTR::unique_ptr<int> ptr3(SMART_PTR::unique_ptr<int>{new int(5)});

    return 0;
}

