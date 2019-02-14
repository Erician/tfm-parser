#ifndef TFMP_TFM_TFMP_TFM_DATA_H_
#include "tfm/tfmp_tfm_data.h"
#endif

#ifndef UTILS_STRINGUTIL_H_
#include "utils/stringutil.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_CONST_H_
#include "tfm/tfmp_tfm_const.h"
#endif

#include <math.h>

namespace tfmp{
namespace tfm {
namespace data{

Data::Data() {
    data_header_ = new tfmp::tfm::data::Header();
    char_info_ = NULL;
    width_ = NULL;
    height_ = NULL;
    depth_ = NULL;
    italic_ = NULL;
    lig_kern_ = NULL;
    kern_ = NULL;
    exten_ = NULL;
    param_ = NULL;
}

int Data::Parse(tfmp::tfm::Header *header, std::ifstream* tfm_ifs) {
    data_header_->Parse(header->lh_, tfm_ifs);
    return 0;
}

int Data::Show(tfmp::DisplayBoard *display_board) {
    data_header_->Show(display_board);
    return 0;
}


} // namespace data
} // namespace tfm
} // name space tfmp