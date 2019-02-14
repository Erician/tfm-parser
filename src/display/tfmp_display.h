#ifndef TFMP_DISPLAY_TFMP_DISPLAY_H_
#define TFMP_DISPLAY_TFMP_DISPLAY_H_

#ifndef TFMP_TFM_TFMP_TFM_H_
#include "tfm/tfmp_tfm.h"
#endif

#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#include "display/tfmp_display_board.h"
#endif

namespace tfmp
{

class Display 
{
private:

public:
    Tfm *tfm_;
    DisplayBoard *display_board_;
    Display(Tfm *tfm, DisplayBoard *display_board);
    int Show();

};

} // namespace tfmp


#endif