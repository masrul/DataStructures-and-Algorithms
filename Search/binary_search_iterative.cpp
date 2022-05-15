#include<iostream>
#include<vector>

int binary_search(const std::vector<int> &data, int key, int start, int end){
    while (start <= end){
        int mid = (start+end)/2;
        if (key == data[mid]) 
            return mid;
        else if (key>data[mid]) 
            start = mid + 1;
        else 
            end = mid-1;
    }
    return -1;
}

int main()
{
    std::vector<int> data{0,1,4,7,8,9,10,14};
    for (auto key: data)
        std::cout << binary_search(data,key,0,data.size()-1)<<"\n";

    std::cout << binary_search(data,100,0,data.size()-1)<<"\n";
    return 0;
}

