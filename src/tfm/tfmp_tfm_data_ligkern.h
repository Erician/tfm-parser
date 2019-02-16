#ifndef TFMP_TFM_TFMP_TFM_DATA_LIGKERN_H_
#define TFMP_TFM_TFMP_TFM_DATA_LIGKERN_H_

#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#include "display/tfmp_display_board.h"
#endif

#include <fstream>

namespace tfmp{
namespace tfm{
namespace data{

struct LigKernCommand {
    unsigned char skip_;
    unsigned char next_char_;
    unsigned char op_;
    unsigned char remainder_;
    LigKernCommand();
    LigKernCommand(char *bytes);
    virtual ~LigKernCommand();
    int Show(tfmp::DisplayBoard *display_board);
    /* not clear about interpreting LigKernCommand */
    int Interpret();
};

class LigKern {
private:

public:
    unsigned short nl_;     /* in word size */
    LigKernCommand **command_;
    LigKern(); 
    virtual ~LigKern();
    int Parse(unsigned int nl, std::ifstream* tfm_ifs);
    int Show(tfmp::DisplayBoard *display_board);
};

} // namespace data
} // namespace tfm    
} // namespace tfmp

#endif