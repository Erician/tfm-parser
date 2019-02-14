#ifndef TFMP_TFM_TFMP_TFM_HEADER_H_
#include "tfm/tfmp_tfm_header.h"
#endif

#ifndef UTILS_STRINGUTIL_H_
#include "utils/stringutil.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_CONST_H_
#include "tfm/tfmp_tfm_const.h"
#endif

#ifndef LOGGING_LOGGING_H_
#include "logging/logging.h"
#endif

namespace tfmp{
namespace tfm{

Header::Header() {
    lf_ = 0;
    lh_ = 0;
    bc_ = 0;
    ec_ = 0;
    nw_ = 0;
    nh_ = 0;
    nd_ = 0;
    ni_ = 0;
    nl_ = 0;
    nk_ = 0;
    ne_ = 0;
    np_ = 0;
}

int Header::Parse(std::ifstream* tfm_ifs) {
    char * header_buffer = new char [tfmp::tfm::kTfmHeaderLength];
    tfm_ifs->read(header_buffer, tfmp::tfm::kTfmHeaderLength);
    lf_ = utils::stringutil::BytesToIntWithBigEndian(header_buffer, 0, 2);
    lh_ = utils::stringutil::BytesToIntWithBigEndian(header_buffer, 2, 4);
    bc_ = utils::stringutil::BytesToIntWithBigEndian(header_buffer, 4, 6);
    ec_ = utils::stringutil::BytesToIntWithBigEndian(header_buffer, 6, 8);
    nw_ = utils::stringutil::BytesToIntWithBigEndian(header_buffer, 8, 10);
    nh_ = utils::stringutil::BytesToIntWithBigEndian(header_buffer, 10, 12);
    nd_ = utils::stringutil::BytesToIntWithBigEndian(header_buffer, 12, 14);
    ni_ = utils::stringutil::BytesToIntWithBigEndian(header_buffer, 14, 16);
    nl_ = utils::stringutil::BytesToIntWithBigEndian(header_buffer, 16, 18);
    nk_ = utils::stringutil::BytesToIntWithBigEndian(header_buffer, 18, 20);
    ne_ = utils::stringutil::BytesToIntWithBigEndian(header_buffer, 20, 22);
    np_ = utils::stringutil::BytesToIntWithBigEndian(header_buffer, 22, 24);
    delete[] header_buffer;
    return 0;
}

int Header::Check() {
    if(!(bc_-1<=ec_ && ec_<=255 && ne_<=256)) {
        LOG.Error("check bc, ec, ne failed");
        return -1;
    }
    if(!(lf_==6+lh_+(ec_-bc_+1)+nw_+nh_\
        +nd_+ni_+nl_+nk_+ne_+np_)) {
        LOG.Error("check lf failed");
        return -1;
    }
    return 0;
}

int Header::Show(tfmp::DisplayBoard *display_board) {
    display_board->Puts(std::to_string(lf_) + "\n");
    display_board->Puts(std::to_string(lh_) + "\n");
    display_board->Puts(std::to_string(bc_) + "\n");
    display_board->Puts(std::to_string(ec_) + "\n");
    display_board->Puts(std::to_string(nw_) + "\n");
    display_board->Puts(std::to_string(nh_) + "\n");
    display_board->Puts(std::to_string(nd_) + "\n");
    display_board->Puts(std::to_string(ni_) + "\n");
    display_board->Puts(std::to_string(nl_) + "\n");
    display_board->Puts(std::to_string(nk_) + "\n");
    display_board->Puts(std::to_string(ne_) + "\n");
    display_board->Puts(std::to_string(np_) + "\n");
    return 0;
}




} // namespace tfm
} // namespace tfmp
