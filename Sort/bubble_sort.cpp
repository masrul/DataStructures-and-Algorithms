/**
 * @author      : MasrulHuda (MasrulHuda@Masruls-MBP)
 * @file        : merge_sort
 * @created     : Monday May 09, 2022 21:53:40 CDT
 */

#include "base.h"

class BSort: public Base{
public:
    BSort():Base(){};
    BSort(int size): Base(size){};
    void sort();
};

void BSort::sort(){
    bool sorted = false;
    while (!sorted){
        sorted = true;
        for (int i =0;i<size-1;++i){
            if (data[i] > data[i+1]){
                swap(i,i+1);
                sorted = false;
            }
        }
    }
}

int main(){
    
    BSort srt(51);

    std::cout << "Initial data ..\n";
    srt.print();

    srt.sort();
    srt.verify();

    std::cout << "\nAfter Bubble sort ..\n";
    srt.print();
    
    return 0;
}

