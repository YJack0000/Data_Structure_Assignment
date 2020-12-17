#include <iostream>
#include <unordered_set>
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

    recordTime bbst("bbst.csv");

    for(int k=10; k<=30; k++){
        int p = _2kPow(k);
        unordered_set<int> data;

        bbst.start(); cout << "start record " << k << " insertion time..." << endl;
        for(int i=0; i<p; i++){
            data.insert( rand() % MAX );
        }
        bbst.end(); cout << "end record " << k << " insertion time..." << endl;
        bbst.write( Insert, k );

        double insert_time = bbst.getTime();

        bbst.start(); cout << "start record " << k << " search time..." << endl;
        for(int i=0; i<_2kPow(20); i++){
            data.count( rand() % MAX );
        }
        bbst.end(); cout << "end record " << k << " search time..." << endl;
        bbst.write( Search, k );

        if(insert_time > 600){
            break;
        }

    }

}