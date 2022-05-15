/**
 * @author      : Masrul Huda (mail2masrul@gmail.com)
 * @file        : base
 * @created     : Monday May 09, 2022 16:14:00 CDT
 */

#ifndef BASE_H

#define BASE_H

#include<iostream>
#include<vector>
#include<string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include<cassert>
#include<cmath>
#define RANDMAX 100

class Base{
public:
    std::vector<int> data;
    int size;
    Base();
    Base(int);
    void print();
    void verify();

protected:
    void swap(int,int);
};

Base::Base(){
    std::srand( ( unsigned int )std::time( nullptr ) );
    size=100;
    for (int i=0;i<size;++i)
        data.push_back(rand()%RANDMAX);
}

Base::Base(int n){
    std::srand( ( unsigned int )std::time( nullptr ) );
    size = n;
    for (int i=0;i<n;++i)
        data.push_back(rand()%RANDMAX);
}

void Base::swap(int index0, int index1){
    int temp = data[index0];
    data[index0] =  data[index1];
    data[index1] = temp;
}

void Base::print(){
    for (int i=0; i<size;++i){
        std::cout <<std::setw(5)<< data[i] <<" ";
        if ((i+1)%10 ==0)
            std::cout<<std::endl;
    }
    if (data.size()%10 !=0)
        std::cout<<std::endl;
}

void Base::verify(){
    for (int i=0; i<size-1;++i)
        assert(data[i+1]-data[i]>=0);
    std::cout<<"\nPassed verification .. :)\n\n";
}

#endif /* end of include guard BASE_H */

