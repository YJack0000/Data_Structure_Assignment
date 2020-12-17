#include <iostream>
#include "sorted_array.h"
#include "record_time.h"

using namespace std;

int _2kPow(int k){
    int tmp = 1;
    while(k--){
        tmp *= 2;
    }
    return tmp;
}

const int MAX = _2kPow(30);

int main(){

    srand( time( NULL ) );

    recordTime sorted_array("Sorted_Array.csv");

    for(int k=10; k<=30; k++){
        int p = _2kPow(k);
        SortedArray data;

        sorted_array.start(); cout << "start record " << k << " insertion time..." << endl;
        for(int i=0; i<p; i++){
            data.insert( rand() % MAX );
        }
        sorted_array.end(); cout << "end record " << k << " insertion time..." << endl;
        sorted_array.write( Insert, k );

        double insert_time = sorted_array.getTime();

        sorted_array.start(); cout << "start record " << k << " search time..." << endl;
        for(int i=0; i<_2kPow(20); i++){
            data.search( rand() % MAX );
        }
        sorted_array.end(); cout << "end record " << k << " search time..." << endl;
        sorted_array.write( Search, k );

        if(insert_time > 600){
            break;
        }

    }

}