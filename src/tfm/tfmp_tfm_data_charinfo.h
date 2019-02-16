#ifndef TFMP_TFM_TFMP_TFM_DATA_CHARINFO_H_
#define TFMP_TFM_TFMP_TFM_DATA_CHARINFO_H_

#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#include "display/tfmp_display_board.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_DATA_HEADER_H_
#include "tfm/tfmp_tfm_data_header.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_DATA_FIXWORD_ARRAY_H_
#include "tfm/tfmp_tfm_data_fixword_array.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_DATA_PARAM_H_
#include "tfm/tfmp_tfm_data_param.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_DATA_LIGKERN_H_
#include "tfm/tfmp_tfm_data_ligkern.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_DATA_EXTEN_H_
#include "tfm/tfmp_tfm_data_exten.h"
#endif

#include <fstream>

namespace tfmp {
namespace tfm{
namespace data{

/* tag explain how to interpret the remainder ﬁeld. */
enum Tag {  
    kNoTag = 0,     /* means that remainder is unused */
    kLigTag = 1,    /* means that this character has a ligature/kerning 
                       program starting at lig kern[remainder]. */ 
    kListTag = 2,   /* means that this character is part of a chain of characters of ascending sizes, 
                       and not the largest in the chain. 
                       The remainder ﬁeld gives the character code of the next larger character. */
    kExtTag = 3     /* means that this character code represents an extensible character, i.e., 
                       a character that is built up of smaller pieces so that it can be made arbitrarily large. 
                       The pieces are speciﬁed in exten[remainder]. */
}; 

class CharInfo;

struct  CharInfoWord{
    unsigned int width_index_ : 8;
    unsigned int height_index_ : 4;
    unsigned int depth_index_ : 4;
    unsigned int italic_index_ : 6;
    unsigned int tag_ : 2;
    unsigned int remainder_ : 8;
    CharInfoWord();
    CharInfoWord(char *bytes);
    virtual ~CharInfoWord();
    int Show(tfmp::DisplayBoard *display_board, \
             tfmp::tfm::data::FixWordArray *width, \
             tfmp::tfm::data::FixWordArray *height, \
             tfmp::tfm::data::FixWordArray *depth, \
             tfmp::tfm::data::FixWordArray *italic, \
             tfmp::tfm::data::LigKern      *lig_kern, \
             tfmp::tfm::data::FixWordArray *kern, \
             tfmp::tfm::data::Exten        *exten, \
             const tfmp::tfm::data::CharInfo     *char_info);
};


class CharInfo {
private:

public:
    unsigned short bc_;
    unsigned short ec_;
    struct CharInfoWord **char_info_word_array_;
    CharInfo();
    virtual ~CharInfo();
    int Parse(unsigned int bc, unsigned int ec, std::ifstream* tfm_ifs);
    int Show(tfmp::DisplayBoard *display_board, \
             tfmp::tfm::data::FixWordArray *width, \
             tfmp::tfm::data::FixWordArray *height, \
             tfmp::tfm::data::FixWordArray *depth, \
             tfmp::tfm::data::FixWordArray *italic, \
             tfmp::tfm::data::LigKern      *lig_kern, \
             tfmp::tfm::data::FixWordArray *kern, \
             tfmp::tfm::data::Exten        *exten);
};

} // namespace data    
} // namespace tfm
} // namespace tfmp

#endif