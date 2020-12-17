#include <iostream>
#include "sorted_array.h"

using namespace std;

SortedArray::SortedArray(int size){
    v.resize(size);
}

void SortedArray::insert(int k){
    //int pos = upper_bound(v.begin(), v.end(), k) - v.begin();
    v.insert(upper_bound(v.begin(), v.end(), k), k);
}

int SortedArray::search(int k){
    return upper_bound(v.begin(), v.end(), k) - v.begin();
}

void SortedArray::print(){
    for(int val: v){
        cout << val << " ";
    }cout << endl;
}
