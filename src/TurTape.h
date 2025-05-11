#include <string>
#include <iostream>
#include <fstream> 
#include <iterator>
#include <chrono>

#pragma once


using delay_size = unsigned long long;


namespace tape {
class TurInterface{
    protected:
    std::string path_to_file_;
    int it_=0;

    public:
    TurInterface(std::string path) 
    : path_to_file_(path){};

    virtual void Next(int step) = 0;
    virtual void Prev(int step) = 0;
    virtual int Read() = 0;
    virtual void Write(int val) = 0;
};


class TurTape : public TurInterface{
    private:
    delay_size read_dealy_;
    delay_size write_dealy_;
    delay_size move_dealy_;
    int it_=0;

    public:
    TurTape(std::string path, delay_size read_delay,
            delay_size write_delay, delay_size move_delay) 
    : TurInterface(path), read_dealy_(read_delay),
      write_dealy_(write_delay), move_dealy_(move_delay) {};

    virtual void Next(int step=1) {
        auto start = std::chrono::system_clock::now();
        it_+=step;

        while(std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now() - start).count() < move_dealy_) {};
    };

    virtual void Prev(int step=1) {
        auto start = std::chrono::system_clock::now();
        it_ -= step;
        if (it_ < 0)
            it_ = 0;

        while(std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now() - start).count() < move_dealy_) {};
    };

    virtual int Read();

    virtual void Write(int val);

    int Iterator() {
        return it_;
    };

    bool IsEnd();
};
}