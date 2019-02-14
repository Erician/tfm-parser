#ifndef TFMP_TFM_TFMP_TFM_DATA_H_
#define TFMP_TFM_TFMP_TFM_DATA_H_

#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#include "display/tfmp_display_board.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_DATA_HEADER_H_
#include "tfm/tfmp_tfm_data_header.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_HEADER_H_
#include "tfm/tfmp_tfm_header.h"
#endif

namespace tfmp{
namespace tfm {
namespace data{

class Data {
private:
public:
    /* 16 arrays */
    tfmp::tfm::data::Header *data_header_;           /* array [0 → lh −1] of stuﬀ */ 
    char *char_info_;        /* array [bc → ec] of char_info word */
    char *width_;            /* array [0 → nw −1] of ﬁx word */
    char *height_;           /* array [0 → nh −1] of ﬁx word */
    char *depth_;            /* array [0 → nd −1] of ﬁx word */
    char *italic_;           /* array [0 → ni −1] of ﬁx word */
    char *lig_kern_;         /* array [0 → nl −1] of lig kern command */
    char *kern_;             /* array [0 → nk −1] of ﬁx word */
    char *exten_;            /* array [0 → ne −1] of extensible recipe */
    char *param_;            /* array [1 → np] of ﬁx word*/

    Data();
    int Parse(tfmp::tfm::Header *header, std::ifstream* tfm_ifs);
    int Show(tfmp::DisplayBoard *display_board);
};

} // namespace data
} // namespace tfm
} // name space tfmp

#endif