#ifndef TFMP_TFM_TFMP_TFM_DATA_PARAM_H_
#define TFMP_TFM_TFMP_TFM_DATA_PARAM_H_

#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#include "display/tfmp_display_board.h"
#endif

#include <fstream>

namespace tfmp {
namespace tfm {
namespace data {

class Param {
private:

public:
    unsigned short np_;
    /* slant_ is param[0], maybe the dvistd0 is wrong */
    float slant_, space_, space_stretch_, \
          space_shrink_, x_height_, quad_, extra_space_;
    /* Tex math symbols */
    float num1_, num2_, num3_, denom1_, denom2_, \
          sup1_, sup2_, sup3_, sub1_, sub2_, \
          supdrop_, subdrop_, delim1_, delim2_, axis_height_;
    /* Tex math extension */
    float default_rule_thickness_, \
          big_op_spacing1_, big_op_spacing2_,
          big_op_spacing3_, big_op_spacing4_,
          big_op_spacing5_;
    Param();
    virtual ~Param();
    int Parse(unsigned int np, std::ifstream* tfm_ifs);
    int Show(tfmp::DisplayBoard *display_board);
};

} // namespace data
} // namespace tfm
} // namespace tfmp


#endif