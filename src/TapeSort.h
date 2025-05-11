#include <string>

#include "TurTape.h"
#pragma once

namespace sort{
class TapeSort {
    private:
    tape::TurTape input_tape_;
    tape::TurTape output_tape_;
    tape::TurTape temp_;

    void ShiftOutToRight();
    
    public:
    TapeSort(std::string input, std::string output, delay_size read_delay,
        delay_size write_delay, delay_size move_delay)
    : input_tape_(input, read_delay, write_delay, move_delay), 
      output_tape_(output, read_delay, write_delay, move_delay), 
      temp_("tmp/var.txt", read_delay, write_delay, move_delay) {
        std::ofstream to_clear;
        to_clear.open("tapes/output.txt", std::ofstream::out | std::ofstream::trunc);
        to_clear.close();
    };

    void Sort();

};
}