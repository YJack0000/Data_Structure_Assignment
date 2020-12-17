#ifndef _SORTED_ARRAY_
#define _SORTED_ARRAY_

#include <vector>
#include <algorithm>

class SortedArray{

    public:

        SortedArray(){}
        SortedArray(int size);

        void insert(int k);

        int search(int t);

        void print();

    private:
        
        std::vector<int> v;

};

#endif