#ifndef TFMP_TFM_TFMP_TFM_DATA_HEADER_H_
#include "tfm/tfmp_tfm_data_header.h"
#endif

#ifndef UTILS_STRINGUTIL_H_
#include "utils/stringutil.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_CONST_H_
#include "tfm/tfmp_tfm_const.h"
#endif

#ifndef TFMP_TFM_TFMP_TFMPUTIL_H_
#include "tfm/tfmp_tfmutil.h"
#endif

#include <string>
#include <cstring>
#include <fstream>

namespace tfmp {
namespace tfm{
namespace data{

Header::Header() {
    lh_ = -1;
}

int Header::Parse(unsigned short lh, std::ifstream* tfm_ifs) {
    lh_ = lh;
    char *buff = new char[lh_ * kSizeofWord];
    tfm_ifs->read(buff, 4);
    checksum_ = utils::stringutil::BytesToIntWithBigEndian(buff, 0, 4);
    tfm_ifs->read(buff, 4);
    design_size_ = tfmp::tfm::FixWordToFloat(buff);
    if(lh_ >= 12) {
        tfm_ifs->read(buff, 40);
        coding_scheme_ = std::string(buff, 40);
    }
    if(lh >= 17) {
        tfm_ifs->read(buff, 20);
        font_family_ = std::string(buff, 20);
    }
    if(lh >= 18) {
        tfm_ifs->read(buff, 4);
        strncpy(sbsf_face_, buff, 4);
    }
    if(lh_-18 > 0) {
        tfm_ifs->read(buff, (lh_-18)*4);
        the_rest_ = std::string(buff, (lh_-18)*4);
    }
    delete []buff;
    return 0;
}

int Header::Show(tfmp::DisplayBoard *display_board) {
    display_board->Puts(std::to_string(lh_) + "\n");
    display_board->Puts(std::to_string(checksum_) + "\n");
    display_board->Puts(std::to_string(design_size_) + "\n");
    display_board->Puts(coding_scheme_ + "\n");
    display_board->Puts(font_family_ + "\n");
    display_board->Puts(std::string(sbsf_face_, 4) + "\n");
    if(the_rest_.size()!=0) 
        display_board->Puts(the_rest_ + "\n");
    return 0;
}

} // namespace data    
} // namespace tfm
} // namespace tfmp