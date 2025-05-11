#include<chrono>

#include "TurTape.h"

namespace tape{
bool TurTape::IsEnd() {
    std::ifstream file(path_to_file_);
    std::string trash;

    if(it_ == 0){
        file >> trash;
        file.close();
        return trash.length() == 0;
    }

    for(int i=0; i<it_; i++)
            file >> trash;
    
    if(file.eof()){
        file.close();
        return true;
    }

    file.close();
    return false;
}
    
int TurTape::Read() {
    auto start = std::chrono::system_clock::now();
    std::ifstream file(path_to_file_);
    std::string num;

    for(int i=0; i<it_ && !file.eof(); i++)
        file >> num;
    
    if(!file.eof())
        file >> num;

    file.close();

    while(std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now() - start).count() < read_dealy_) {};

    return std::stoul(num);
}

void TurTape::Write(int val) {
    auto start = std::chrono::system_clock::now();
    std::string res="";
    
    std::ifstream file_to_read(path_to_file_);
    { // read data and rewrite the value
    int i=0;
    for(std::string num=""; !file_to_read.eof();i++) {
        file_to_read >> num;
        if(i != 0)
            res += " ";
        if(i == it_)
            num = std::to_string(val);
        
        res += num;
    }
    if(i<=it_){
        if(i != 0)
            res += " ";
        res += std::to_string(val);
    }
    }
    file_to_read.close();

    std::ofstream file_to_write(path_to_file_, std::ios::trunc);
    file_to_write << res;
    file_to_write.close();

    while(std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now() - start).count() < write_dealy_) {};
}
}