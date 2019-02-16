#ifndef TFMP_TFM_TFMP_TFM_DATA_FIXWORD_ARRAY_H_
#define TFMP_TFM_TFMP_TFM_DATA_FIXWORD_ARRAY_H_

#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#include "display/tfmp_display_board.h"
#endif

#include <fstream>

namespace tfmp{
namespace tfm{
namespace data{

class FixWordArray {
private:

public:
    unsigned short len_;     /* in word size */
    float *array_;
    FixWordArray();
    virtual ~FixWordArray();
    int Parse(unsigned int len, std::ifstream* tfm_ifs);
    int Show(tfmp::DisplayBoard *display_board);

};

} // namespace data
} // namespace tfm    
} // namespace tfmp


#endif