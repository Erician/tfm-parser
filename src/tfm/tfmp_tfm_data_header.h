#ifndef TFMP_TFM_TFMP_TFM_DATA_HEADER_H_
#define TFMP_TFM_TFMP_TFM_DATA_HEADER_H_

#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#include "display/tfmp_display_board.h"
#endif

#include <fstream>
#include <string>

namespace tfmp {
namespace tfm{
namespace data{

class Header{
private:

public:
    unsigned short lh_;         /* length of the header data, in words */
    signed int checksum_;       /* header[0] */
    signed int design_size_;    /* header[1] */
    std::string coding_scheme_; /* header[2...11], if present */
    std::string font_family_;   /* header[12...16], if present */
    char sbsf_face_[4];          /* header[17], seven bit safe ﬂag and 
                                face(“weight, slope, and expansion) */
    std::string the_rest_;      /* header[18...whatever] */
    Header();
    int Parse(unsigned short lh_, std::ifstream* tfm_ifs);
    int Show(tfmp::DisplayBoard *display_board);

};

} // namespace data    
} // namespace tfm
} // namespace tfmp

#endif