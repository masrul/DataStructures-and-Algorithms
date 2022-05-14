/**
 * @author      : MasrulHuda (MasrulHuda@Masruls-MBP)
 * @file        : quick_sort
 * @created     : Saturday May 07, 2022 23:28:55 CDT
 */

#include "base.h"

class QSort: public Base {
public:
    QSort():Base(){};
    QSort(int size): Base(size){};
    void sort();

private:
    void quick_sort(int,int);
    int partition(int,int);
};

int QSort::partition(int start, int end){
    int pivot = data[end];
    int pivot_idx = start; 

    for (int i=start; i<end;++i){
        if (data[i] < pivot){
            swap(pivot_idx,i);
            ++pivot_idx;
        }
    }
    swap(pivot_idx,end);
    return pivot_idx;
}

void QSort::quick_sort(int start, int end){
    if (start < end){
        int pivot_idx = partition(start,end);
        quick_sort(start,pivot_idx-1);
        quick_sort(pivot_idx+1,end);
    }
}

void QSort::sort(){
    quick_sort(0,size-1);
}


int main(){

    QSort srt;

    std::cout << "Initial data ..\n";
    srt.print();

    srt.sort();
    srt.verify();

    std::cout << "\nAfter Quick sort ..\n";
    srt.print();
    
    return 0;
    
    return 0;
}

