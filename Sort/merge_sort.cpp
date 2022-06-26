#include "base.h"

class MSort: public Base{
public:
    MSort():Base(){};
    MSort(int size): Base(size){};
    void sort();

private:
    void merge_sort(int,int);
    void merge(int,int,int);
};

void MSort::merge_sort(int start,int end){
    if (start < end){
        int mid = (start+end)/2;
        merge_sort(start,mid);
        merge_sort(mid+1,end);
        merge(start,mid,end);
    }
}

void MSort::merge(int start,int mid, int end){
    std::vector<int> sorted_data(end-start+1,0);
    
    // Just pointting to two halves, not creating new memory
     int* left=&data.at(start); 
     int* right=&data.at(mid+1);

     int lsize = mid-start+1;
     int rsize = end-mid;

     int nl =0;
     int nr =0;
     int n = 0;

    // Merge two halves 
     while (nl < lsize && nr<rsize){
         if (*left <  *right){
             sorted_data[n] = *left;
             ++left, ++nl, ++n;
         }else{
             sorted_data[n] = *right;
             ++right, ++nr, ++n;
         }
     }

    // Collect remaing of left, if any
     while (nl<lsize){
         sorted_data[n] = *left;
         ++left, ++nl, ++n;
     }

    // Collect remaing of right, if any
     while (nr<rsize){
         sorted_data[n] = *right;
         ++right, ++nr, ++n;
     }

     // copy to main array 
     int *sorted_ptr=&sorted_data.at(0);
     for (int i=start;i<=end;++i){
        data[i] = *sorted_ptr;
        ++sorted_ptr;
     }
}

 void MSort::sort(){
    merge_sort(0,size-1);
 }

int main(){
    
    MSort srt;

    // Print initial data
    std::cout << "Initial data:\n";
    srt.print();

    // Sort, print and verify
    srt.sort();
    std::cout << "\nAfter Merge sort:\n";
    srt.print();
    srt.verify();
    
    return 0;
}

