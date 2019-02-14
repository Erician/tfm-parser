#ifndef TFMP_TFM_TFMP_TFM_H_
#define TFMP_TFM_TFMP_TFM_H_

#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#include "display/tfmp_display_board.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_DATA_HEADER_H_
#include "tfm/tfmp_tfm_data_header.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_HEADER_H_
#include "tfm/tfmp_tfm_header.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_DATA_H_
#include "tfm/tfmp_tfm_data.h"
#endif

#include <map>
#include <vector>
#include <fstream>

namespace tfmp {

/* the length of one word is 32 bits */
class Tfm {
private:
    
public:
    std::string tfm_file_name_;
    std::ifstream *tfm_ifs_;

    /* header */
    tfmp::tfm::Header *header_;
    /* data */
    tfmp::tfm::data::Data *data_;
    
    Tfm();
    Tfm(std::string tfm_file_name);
    int SetTfmFile(std::string tfm_file_name);
    int Parse();
    int Show(DisplayBoard *display_board);
};

} // namespace tfmp

#endif