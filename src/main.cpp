#include<mutex>
#include<thread>
#include<iostream>
#include<vector>
#include<chrono>
#include<string>

#include"TurTape.h"
#include"TapeSort.h"


using ll = long long int;


int main(int argc, char* argv[]) {
    //---------DATA PREPARE--------------
    if (argc != 6) {
        std::cout << "Expected 5 arguments: "
        << "[input file], [output file], [write delay], [read delay], [move delay]\n"
        << "Received: " << argc - 1 << " arguments" << std::endl;
        return 1;
    }
    
    std::string input_file=argv[1], output_file=argv[2];
    int read_delay=std::stoi(argv[3]), write_delay=std::stoi(argv[4]);
    int move_delay=std::stoi(argv[5]);
    //-----------------------------------
    
    //--------------ALGO-----------------
    sort::TapeSort sorting(input_file, output_file, read_delay, write_delay, move_delay);
    sorting.Sort();
    //-----------------------------------

    //-----------RESULT PRINT------------
    std::cout << "all good" << std::endl;
    //-----------------------------------

    return 0;
}