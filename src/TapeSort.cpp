#include "TapeSort.h"

namespace sort{
void TapeSort::ShiftOutToRight(){
    for(; !output_tape_.IsEnd(); output_tape_.Next()){
        int curr = output_tape_.Read();
        output_tape_.Write(temp_.Read());
        temp_.Write(curr);
    }
    output_tape_.Write(temp_.Read());
};


void TapeSort::Sort() {
    for(;!input_tape_.IsEnd(); input_tape_.Next()){
        int num_to_merge = input_tape_.Read();
        output_tape_.Prev(output_tape_.Iterator());
        
        for (;!output_tape_.IsEnd(); output_tape_.Next()) {
            int curr_num = output_tape_.Read();
            if (curr_num > num_to_merge)
            break;
        }
        
        temp_.Write(num_to_merge);
        ShiftOutToRight();
    }
};


}