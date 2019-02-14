#ifndef TFMP_TFM_TFMP_TFM_DATA_CHARINFO_H_
#include "tfm/tfmp_tfm_data_charinfo.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_CONST_H_
#include "tfm/tfmp_tfm_const.h"
#endif

#include <iostream>

namespace tfmp {
namespace tfm{
namespace data{

CharInfoWord::CharInfoWord() {
    width_index_ = 0;
    height_index_ = 0;
    depth_index_ = 0;
    italic_index_ = 0;
    tag_ = 0;
    remainder_ = 0;
}
CharInfoWord::CharInfoWord(char *bytes) {
    width_index_ = bytes[0];
    height_index_ = ((unsigned char)bytes[1])>>4;
    depth_index_ = ((unsigned char)bytes[1])&0x0f;
    italic_index_ = ((unsigned char)bytes[2])>>2;
    tag_ = ((unsigned char)bytes[2])&0x03;
    remainder_ = bytes[3];
}

int CharInfoWord::Show(tfmp::DisplayBoard *display_board) {
    display_board->Puts(std::to_string(width_index_) + "\n");
    display_board->Puts(std::to_string(height_index_) + "\n");
    display_board->Puts(std::to_string(depth_index_) + "\n");
    display_board->Puts(std::to_string(italic_index_) + "\n");
    display_board->Puts(std::to_string(tag_) + "\n");
    display_board->Puts(std::to_string(remainder_) + "\n");
    return 0;
}

CharInfo::CharInfo() {
    bc_ = -1;
    ec_ = -1; 
    char_info_word_array_ = NULL;
}

int CharInfo::Parse(unsigned int bc, unsigned int ec, std::ifstream* tfm_ifs) {
    bc_ = bc;
    ec_ = ec;
    char_info_word_array_ = new struct CharInfoWord*[ec-bc+1];
    char *buff = new char [tfmp::tfm::kSizeofCharInfoWord];
    for(int i=bc_; i<ec_; i++) {
        tfm_ifs->read(buff, tfmp::tfm::kSizeofCharInfoWord);
        char_info_word_array_[i-bc_] = new struct CharInfoWord(buff);
    }
    delete []buff;
    return 0;
}

int CharInfo::Show(tfmp::DisplayBoard *display_board) {
    display_board->Puts(std::to_string(bc_) + "\n");
    display_board->Puts(std::to_string(ec_) + "\n");
    for(int i=bc_; i<ec_; i++) {
        display_board->Puts(std::to_string(i) + "\n");
        char_info_word_array_[i-bc_]->Show(display_board);
    }
    return 0;
}

} // namespace data    
} // namespace tfm
} // namespace tfmp