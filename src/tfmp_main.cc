#ifndef TFMP_DISPLAY_TFMP_DISPLAY_H_
#include "display/tfmp_display.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_H_
#include "tfm/tfmp_tfm.h"
#endif

#ifndef LOGGING_LOGGING_H_
#include "logging/logging.h"
#endif


int main(int argc,char *argv[]) {
    if(argc < 2) {
        std::cout << "Usage Error: gfp <input file> [output file]" << std::endl;
        return -1;
    }

    tfmp::Tfm *tfm = new tfmp::Tfm(argv[1]);
    if(tfm->Parse() != 0){
        std::cout<<"Parse Error: some error(s) happen when parsing the tfm file"<<std::endl;
        return -1;
    }

    tfmp::DisplayBoard *display_board;
    if(argc < 3) {
        display_board = new tfmp::DisplayBoard();
    }else {
        display_board = new tfmp::DisplayBoard(argv[2]);
    }
    tfmp::Display display(tfm, display_board);
    display.Show();
    return 0;
}
