#ifndef TFMP_DISPLAY_TFMP_DISPLAY_H_
#include "display/tfmp_display.h"
#endif

namespace tfmp
{

Display::Display(Tfm *tfm, DisplayBoard *display_board) {
    tfm_ = tfm;
    display_board_ = display_board;
}

int Display::Show() {
    tfm_->Show(display_board_);
    return 0;
}

} // namespace tfmp