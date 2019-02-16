#ifndef TFMP_TFM_TFMP_TFM_DATA_PARAM_H_
#include "tfm/tfmp_tfm_data_param.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_CONST_H_
#include "tfm/tfmp_tfm_const.h"
#endif

#ifndef TFMP_TFM_TFMP_TFMPUTIL_H_
#include "tfm/tfmp_tfmutil.h"
#endif

namespace tfmp {
namespace tfm {
namespace data {


Param::Param() {
    np_ = 0;
}
Param::~Param() {
    ;
}
int Param::Parse(unsigned int np, std::ifstream* tfm_ifs) {
    np_ = np;
    char *buff = new char[tfmp::tfm::kSizeofFixWord];
    
    tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
    slant_ = tfmp::tfm::FixWordToFloat(buff);
    tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
    space_ = tfmp::tfm::FixWordToFloat(buff);
    tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
    space_stretch_ = tfmp::tfm::FixWordToFloat(buff);
    tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
    space_shrink_ = tfmp::tfm::FixWordToFloat(buff);
    tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
    x_height_ = tfmp::tfm::FixWordToFloat(buff);
    tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
    quad_ = tfmp::tfm::FixWordToFloat(buff);
    tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
    extra_space_ = tfmp::tfm::FixWordToFloat(buff);
    if(np_ == 7 + 15) {         /* Tex math symbols */
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        num1_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        num2_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        num3_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        denom1_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        denom2_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        sup1_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        sup2_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        sup3_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        sub1_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        sub2_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        supdrop_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        subdrop_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        delim1_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        delim2_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        axis_height_ = tfmp::tfm::FixWordToFloat(buff);
    }else if(np_ == 7 + 6) {    /* Tex math extension */
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        default_rule_thickness_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        big_op_spacing1_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        big_op_spacing2_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        big_op_spacing3_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        big_op_spacing4_ = tfmp::tfm::FixWordToFloat(buff);
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        big_op_spacing5_ = tfmp::tfm::FixWordToFloat(buff);
    }
    delete []buff;
    return 0;
}

int Param::Show(tfmp::DisplayBoard *display_board) {
    display_board->Puts(std::to_string(np_) + "\n");
    display_board->Puts(std::to_string(slant_) + "\n");
    display_board->Puts(std::to_string(space_) + "\n");
    display_board->Puts(std::to_string(space_stretch_) + "\n");
    display_board->Puts(std::to_string(space_shrink_) + "\n");
    display_board->Puts(std::to_string(x_height_) + "\n");
    display_board->Puts(std::to_string(quad_) + "\n");
    display_board->Puts(std::to_string(extra_space_) + "\n");
    if(np_ == 7 + 15) {         /* Tex math symbols */
        display_board->Puts(std::to_string(num1_) + "\n");
        display_board->Puts(std::to_string(num2_) + "\n");
        display_board->Puts(std::to_string(num3_) + "\n");
        display_board->Puts(std::to_string(denom1_) + "\n");
        display_board->Puts(std::to_string(denom2_) + "\n");
        display_board->Puts(std::to_string(sup1_) + "\n");
        display_board->Puts(std::to_string(sup2_) + "\n");
        display_board->Puts(std::to_string(sup3_) + "\n");
        display_board->Puts(std::to_string(sub1_) + "\n");
        display_board->Puts(std::to_string(sub2_) + "\n");
        display_board->Puts(std::to_string(supdrop_) + "\n");
        display_board->Puts(std::to_string(subdrop_) + "\n");
        display_board->Puts(std::to_string(delim1_) + "\n");
        display_board->Puts(std::to_string(delim2_) + "\n");
        display_board->Puts(std::to_string(axis_height_) + "\n");
    }else if(np_ == 7 + 6) {       /* Tex math extension */
        display_board->Puts(std::to_string(default_rule_thickness_) + "\n");
        display_board->Puts(std::to_string(big_op_spacing1_) + "\n");
        display_board->Puts(std::to_string(big_op_spacing2_) + "\n");
        display_board->Puts(std::to_string(big_op_spacing3_) + "\n");
        display_board->Puts(std::to_string(big_op_spacing4_) + "\n");
        display_board->Puts(std::to_string(big_op_spacing5_) + "\n");
    }
    return 0;
}


} // namespace data
} // namespace tfm
} // namespace tfmp