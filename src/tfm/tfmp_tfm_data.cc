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
    char_info_ = new tfmp::tfm::data::CharInfo();
    width_ = new tfmp::tfm::data::FixWordArray();
    height_ = new tfmp::tfm::data::FixWordArray();
    depth_ = new tfmp::tfm::data::FixWordArray();
    italic_ = new tfmp::tfm::data::FixWordArray();
    lig_kern_ = new tfmp::tfm::data::LigKern();
    kern_ = new tfmp::tfm::data::FixWordArray();
    exten_ = new tfmp::tfm::data::Exten();
    param_ = new tfmp::tfm::data::Param();
}

Data::~Data() {
    delete data_header_;
    delete char_info_;
    delete width_;
    delete height_;
    delete depth_;
    delete italic_;
    delete lig_kern_;
    delete kern_;
    delete exten_;
    delete param_;
}

int Data::Parse(tfmp::tfm::Header *header, std::ifstream* tfm_ifs) {
    data_header_->Parse(header->lh_, tfm_ifs);
    char_info_->Parse(header->bc_, header->ec_, tfm_ifs);
    width_->Parse(header->nw_, tfm_ifs);
    height_->Parse(header->nh_, tfm_ifs);
    depth_->Parse(header->nd_, tfm_ifs);
    italic_->Parse(header->ni_, tfm_ifs);
    lig_kern_->Parse(header->nl_, tfm_ifs);
    kern_->Parse(header->nk_, tfm_ifs);
    exten_->Parse(header->ne_, tfm_ifs);
    param_->Parse(header->np_, tfm_ifs);
    return 0;
}

int Data::Show(tfmp::DisplayBoard *display_board) {
    data_header_->Show(display_board);
    char_info_->Show(display_board);
    width_->Show(display_board);
    height_->Show(display_board);
    depth_->Show(display_board);
    italic_->Show(display_board);
    lig_kern_->Show(display_board);
    kern_->Show(display_board);
    exten_->Show(display_board);
    param_->Show(display_board);
    return 0;
}


} // namespace data
} // namespace tfm
} // name space tfmp