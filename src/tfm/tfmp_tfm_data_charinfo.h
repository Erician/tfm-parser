#ifndef TFMP_TFM_TFMP_TFM_DATA_CHARINFO_H_
#define TFMP_TFM_TFMP_TFM_DATA_CHARINFO_H_

#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#include "display/tfmp_display_board.h"
#endif

#include <fstream>

namespace tfmp {
namespace tfm{
namespace data{

struct  CharInfoWord{
    unsigned int width_index_ : 8;
    unsigned int height_index_ : 4;
    unsigned int depth_index_ : 4;
    unsigned int italic_index_ : 6;
    unsigned int tag_ : 2;
    unsigned int remainder_ : 8;
    CharInfoWord();
    CharInfoWord(char *bytes);
    int Show(tfmp::DisplayBoard *display_board);
};


class CharInfo {
private:

public:
    unsigned short bc_;
    unsigned short ec_;
    struct CharInfoWord **char_info_word_array_;
    CharInfo();
    int Parse(unsigned int bc, unsigned int ec, std::ifstream* tfm_ifs);
    int Show(tfmp::DisplayBoard *display_board);

};

} // namespace data    
} // namespace tfm
} // namespace tfmp

#endif