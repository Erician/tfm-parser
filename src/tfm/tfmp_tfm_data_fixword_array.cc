#ifndef TFMP_TFM_TFMP_TFM_DATA_FIXWORD_ARRAY_H_
#include "tfm/tfmp_tfm_data_fixword_array.h"
#endif

#ifndef TFMP_TFM_TFMP_TFMPUTIL_H_
#include "tfm/tfmp_tfmutil.h"
#endif

#ifndef UTILS_STRINGUTIL_H_
#include "utils/stringutil.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_CONST_H_
#include "tfm/tfmp_tfm_const.h"
#endif

#include <string>

namespace tfmp{
namespace tfm{
namespace data{

FixWordArray::FixWordArray() {
    len_ = 0;
    array_ = NULL;
}

FixWordArray::~FixWordArray() {
    if(array_ != NULL) {
        delete []array_;
    }
}

int FixWordArray::Parse(unsigned int len, std::ifstream* tfm_ifs) {
    char *buff = new char[tfmp::tfm::kSizeofFixWord];
    array_ = new float[len * tfmp::tfm::kSizeofFixWord];
    for(int i=0; i<len; i++) {
        tfm_ifs->read(buff, tfmp::tfm::kSizeofFixWord);
        array_[i] = tfmp::tfm::FixWordToFloat(buff);
    }
    delete []buff;
    return 0;
}

int FixWordArray::Show(tfmp::DisplayBoard *display_board) {
    display_board->Puts(std::to_string(len_) + "\n");
    for(int i=0; i<len_; i++) {
        display_board->Puts(std::to_string(array_[i]) + "\n");
    }
    return 0;
}

} // namespace data
} // namespace tfm    
} // namespace tfmp