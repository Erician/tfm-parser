#ifndef TFMP_TFM_TFMP_TFM_DATA_LIGKERN_H_
#include "tfm/tfmp_tfm_data_ligkern.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_CONST_H_
#include "tfm/tfmp_tfm_const.h"
#endif

namespace tfmp{
namespace tfm{
namespace data{

LigKernCommand::LigKernCommand() {
    skip_ = 0;
    next_char_ = 0;
    op_ = 0;
    remainder_ = 0;
}   
LigKernCommand::LigKernCommand(char *bytes) {
    skip_ = (unsigned char)bytes[0];
    next_char_ = (unsigned char)bytes[1];
    op_ = (unsigned char)bytes[2];
    remainder_ = (unsigned char)bytes[3];
}
LigKernCommand::~LigKernCommand() {
    ;
}

int LigKernCommand::Show(tfmp::DisplayBoard *display_board) {
    display_board->Puts(std::to_string(skip_) + "\n");
    display_board->Puts(std::to_string(next_char_) + "\n");
    display_board->Puts(std::to_string(op_) + "\n");
    display_board->Puts(std::to_string(remainder_) + "\n");
    return 0;
}

int LigKernCommand::Interpret() {
    return 0;
}

LigKern::LigKern() {
    nl_ = 0;
    command_ = NULL;
}

LigKern::~LigKern() {
    for(int i=0; i<nl_; i++) {
        delete command_[i];
    }
    delete []command_;
}

int LigKern::Parse(unsigned int nl, std::ifstream* tfm_ifs) {
    nl_ = nl;
    command_ = new struct LigKernCommand*[nl_];
    char *buff = new char [tfmp::tfm::kSizeofLigKernCommand];
    for(int i=0; i<nl_; i++) {
        tfm_ifs->read(buff, tfmp::tfm::kSizeofLigKernCommand);
        command_[i] = new struct LigKernCommand(buff);
    }
    delete []buff;
    return 0;
}

int LigKern::Show(tfmp::DisplayBoard *display_board) {
    display_board->Puts(std::to_string(nl_) + "\n");
    for(int i=0; i<nl_; i++) {
        display_board->Puts(std::to_string(i) + "\n");
        command_[i]->Show(display_board);
    }
    return 0;
}

} // namespace data
} // namespace tfm    
} // namespace tfmp