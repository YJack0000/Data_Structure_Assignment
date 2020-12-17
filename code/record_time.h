#ifndef _RECORD_TIME_H_
#define _RECORD_TIME_H_

#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

enum op { Insert=0 , Search=1};

class recordTime{

    public:

        recordTime();

        recordTime(string file_name) : fout(file_name){ 
            fout << "k, Insert, search" << endl;
            started = false;
        }

        void start(){
            started = true;
            start_time = clock();
        }

        void end(){
            if(started)
                end_time = clock();
            return;
        }

        double getTime(){
            cout << "get time " << ((double)end_time-start_time) / CLOCKS_PER_SEC << endl;
            return ((double)end_time-start_time) / CLOCKS_PER_SEC;
        }

        void write(op operation, int k){
            if(operation == 0) fout << k << ", ";
            fout << ((double)end_time-start_time) / CLOCKS_PER_SEC;
            if(operation){
                fout << endl;
            }else{
                fout << ", ";
            }
        }

    private:

        bool started;
        clock_t start_time, end_time;
        ofstream fout;

};

#endif
