#include "base.h"

class SSort: public Base{
public:
    SSort():Base(){};
    SSort(int size): Base(size){};
    void sort();
};

void SSort::sort(){
    for (int i =0;i<size-1;++i){
        int arg_min = i; 
        for (int j =i+1;j<size;++j)
            if (data[arg_min] > data[j]) arg_min = j;
        swap(i,arg_min);
    }
}

int main(){
    
    SSort srt;

    // Print initial data
    std::cout << "Initial data:\n";
    srt.print();

    // Sort, print and verify
    srt.sort();
    std::cout << "\nAfter Selection sort:\n";
    srt.print();
    srt.verify();
    
    return 0;
}

