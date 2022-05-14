/**
 * @author      : MasrulHuda (MasrulHuda@Masruls-MBP)
 * @file        : merge_sort
 * @created     : Monday May 09, 2022 21:53:40 CDT
 */

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
    
    SSort srt(51);

    std::cout << "Initial data ..\n";
    srt.print();

    srt.sort();
    srt.verify();

    std::cout << "\nAfter Seclection sort ..\n";
    srt.print();
    
    return 0;
}

