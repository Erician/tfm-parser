#ifndef TFMP_TFM_TFMP_TFM_DATA_EXTEN_H_
#define TFMP_TFM_TFMP_TFM_DATA_EXTEN_H_

#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#include "display/tfmp_display_board.h"
#endif

#include <fstream>

namespace tfmp{
namespace tfm{
namespace data{

struct ExtenCommand {
    unsigned char top_;
    unsigned char mid_;
    unsigned char bot_;
    unsigned char rep_;
    ExtenCommand(char *bytes);
    virtual ~ExtenCommand();
    int Show(tfmp::DisplayBoard *display_board);
};

class Exten {
private:

public:
    unsigned short ne_;     /* in word size */
    struct ExtenCommand **commands_;
    Exten();
    virtual ~Exten();
    int Parse(unsigned int ne, std::ifstream* tfm_ifs);
    int Show(tfmp::DisplayBoard *display_board);

};

} // namespace data
} // namespace tfm    
} // namespace tfmp

#endif