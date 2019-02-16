#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#include "display/tfmp_display_board.h"
#endif

#include <iostream>

namespace tfmp {

DisplayBoard::DisplayBoard(){
    output_file_name_ = std::string();
    board_ = &(std::cout);
    output_file_stream_ = NULL;
}

DisplayBoard::DisplayBoard(std::string output_file_name){
    output_file_name_ = output_file_name;
    output_file_stream_ =  new std::ofstream(output_file_name_, std::ofstream::out);
    board_ = output_file_stream_;
}

void DisplayBoard::SetBoard(){
    board_ = &(std::cout);
}

void DisplayBoard::SetBoard(std::string output_file_name){
    if(output_file_stream_ != NULL){
        output_file_stream_->close();
    }
    output_file_stream_ =  new std::ofstream(output_file_name_, std::ofstream::out | std::ofstream::app);
    board_ = output_file_stream_;
}

void DisplayBoard::Puts(std::string str) {
    (*board_)<<str;
}

void DisplayBoard::Put(char c) {
    (*board_)<<c;
}

void DisplayBoard::Close(){
    output_file_stream_->close();
}


} // namespace tfmp