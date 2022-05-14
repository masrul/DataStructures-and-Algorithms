/**
 * @author      : MasrulHuda (MasrulHuda@Masruls-MBP)
 * @file        : insertion_sort
 * @created     : Monday May 09, 2022 21:53:40 CDT
 */

#include "base.h"

class ISort: public Base{
public:
    ISort():Base(){};
    ISort(int size): Base(size){};
    void sort();
};

void ISort::sort(){
    for (int i =1;i<size;++i){
        int hole = i; 
        int value = data[i]; 
        while (hole > 0 & value < data[hole-1]){
            data[hole] = data[hole-1];
            --hole;
        }
        data[hole]=value;
    }
}

int main(){
    
    ISort srt;

    std::cout << "Initial data ..\n";
    srt.print();

    srt.sort();
    srt.verify();

    std::cout << "\nAfter Insertion sort ..\n";
    srt.print();
    
    return 0;
}

