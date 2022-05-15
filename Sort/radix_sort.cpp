#include<queue>
#include "base.h"

class RSort: public Base{
public:
    RSort():Base(){};
    RSort(int size): Base(size){};
    void sort();
};

void RSort::sort(){
    std::vector< std::queue<int> > bins(10,std::queue<int>());

    // find max and it's number of digits 
    int max=data[0];
    for (int i=1;i<size;++i)
        if (data[i]>max) max=data[i];
    int max_digits = std::to_string(max).size();
    
    // bining max_digits times 
    for (int i =0; i<max_digits;++i){

        // bining 
        int factor =(int) std::pow(10,i);
        for (int j=0;j<size;++j){
            int bin_id = (data[j]/factor)%10;
            bins[bin_id].push(data[j]);
        }
        
        // poping from queue and save into main data  
        int idx = 0;
        for (int k=0;k<10;++k){
            while (!bins[k].empty()){
                data[idx] = bins[k].front();
                bins[k].pop();
                ++idx;
            }
        }
    }
}

int main(){
    
    RSort srt;

    // Print initial data
    std::cout << "Initial data:\n";
    srt.print();

    // Sort, print and verify
    srt.sort();
    std::cout << "\nAfter Radix sort:\n";
    srt.print();
    srt.verify();
    
    return 0;
}

