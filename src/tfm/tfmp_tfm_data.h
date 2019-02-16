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

#ifndef TFMP_TFM_TFMP_TFM_DATA_CHARINFO_H_
#include "tfm/tfmp_tfm_data_charinfo.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_DATA_FIXWORD_ARRAY_H_
#include "tfm/tfmp_tfm_data_fixword_array.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_DATA_PARAM_H_
#include "tfm/tfmp_tfm_data_param.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_DATA_LIGKERN_H_
#include "tfm/tfmp_tfm_data_ligkern.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_DATA_EXTEN_H_
#include "tfm/tfmp_tfm_data_exten.h"
#endif

namespace tfmp{
namespace tfm {
namespace data{

class Data {
private:
public:
    /* 16 arrays */
    tfmp::tfm::data::Header *data_header_;      /* array [0 → lh −1] of stuﬀ */ 
    tfmp::tfm::data::CharInfo *char_info_;      /* array [bc → ec] of char_info word */
    tfmp::tfm::data::FixWordArray *width_;      /* array [0 → nw −1] of ﬁx word */
    tfmp::tfm::data::FixWordArray *height_;     /* array [0 → nh −1] of ﬁx word */
    tfmp::tfm::data::FixWordArray *depth_;      /* array [0 → nd −1] of ﬁx word */
    tfmp::tfm::data::FixWordArray *italic_;     /* array [0 → ni −1] of ﬁx word */
    tfmp::tfm::data::LigKern *lig_kern_;        /* array [0 → nl −1] of lig kern command */
    tfmp::tfm::data::FixWordArray *kern_;       /* array [0 → nk −1] of ﬁx word */
    tfmp::tfm::data::Exten *exten_;             /* array [0 → ne −1] of extensible recipe */
    tfmp::tfm::data::Param *param_;             /* array [1 → np] of ﬁx word*/

    Data();
    virtual ~Data();
    int Parse(tfmp::tfm::Header *header, std::ifstream* tfm_ifs);
    int Show(tfmp::DisplayBoard *display_board);
};

} // namespace data
} // namespace tfm
} // name space tfmp

#endif