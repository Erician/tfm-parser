#ifndef TFMP_TFM_TFMP_TFM_H_
#include "tfm/tfmp_tfm.h"
#endif

#ifndef LOGGING_LOGGING_H_
#include "logging/logging.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_CONST_H_
#include "tfm/tfmp_tfm_const.h"
#endif

#ifndef UTILS_STRINGUTIL_H_
#include "utils/stringutil.h"
#endif

#include <fstream> 

namespace tfmp {

Tfm::Tfm(){
    tfm_file_name_ = "";
    tfm_ifs_ = new std::ifstream();
    header_ = new tfmp::tfm::Header();
    data_ = new tfmp::tfm::data::Data();
}

Tfm::Tfm(std::string tfm_file_name){
    tfm_file_name_ = tfm_file_name;
    tfm_ifs_ = new std::ifstream();
    tfm_ifs_->open(tfm_file_name_, std::ifstream::in);
    if(tfm_ifs_->fail()) {
        LOG.Error("open " + tfm_file_name_ + " failed");
        exit(-1);
    }
    header_ = new tfmp::tfm::Header();
    data_ = new tfmp::tfm::data::Data();
}

int Tfm::SetTfmFile(std::string tfm_file_name) {
    tfm_file_name_ = tfm_file_name;
    tfm_ifs_ = new std::ifstream();
    tfm_ifs_->open(tfm_file_name_, std::ifstream::in);
    if(tfm_ifs_->fail()) {
        LOG.Error("open " + tfm_file_name_ + " failed");
        exit(-1);
    }
    return 0;
}

int Tfm::Parse() {
    if(header_->Parse(tfm_ifs_) != 0) { 
        LOG.Error("failed to parse tfm header");
        exit(-1);
    }
    if(header_->Check() != 0) {
        LOG.Error("check header failed");
        exit(-1);
    }
    if(data_->Parse(header_, tfm_ifs_) != 0) {
        LOG.Error("failed to parse tfm data");
        exit(-1);
    }
    
    return 0;
}

int Tfm::Show(DisplayBoard *display_board) {
    header_->Show(display_board);
    data_->Show(display_board);
    return 0;
}

} // namespace tfmp