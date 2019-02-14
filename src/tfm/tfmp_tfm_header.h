#ifndef TFMP_TFM_TFMP_TFM_HEADER_H_
#define TFMP_TFM_TFMP_TFM_HEADER_H_

#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#include "display/tfmp_display_board.h"
#endif

#include <fstream>

namespace tfmp{
namespace tfm{

class Header{
private:

public:
    /* the headers: 12 16-bit intergers */
    unsigned short lf_;      /* length of the entire ﬁle, in words */
    unsigned short lh_;      /* length of the header data, in words */
    unsigned short bc_;      /* smallest character code in the font */
    unsigned short ec_;      /* largest character code in the font */
    unsigned short nw_;      /* number of words in the width table */
    unsigned short nh_;      /* number of words in the height table */
    unsigned short nd_;      /* number of words in the depth table */
    unsigned short ni_;      /* number of words in the italic correction table */
    unsigned short nl_;      /* number of words in the lig/kern table */
    unsigned short nk_;      /* number of words in the kern table */
    unsigned short ne_;      /* number of words in the extensible character table */
    unsigned short np_;      /* number of font parameter words */

    Header();
    int Parse(std::ifstream* tfm_ifs);
    int Check();
    int Show(tfmp::DisplayBoard *display_board);
    
};

} // namespace tfm
} // namespace tfmp


#endif