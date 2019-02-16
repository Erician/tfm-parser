#ifndef TFMP_TFM_TFMP_TFM_DATA_EXTEN_H_
#include "tfm/tfmp_tfm_data_exten.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_CONST_H_
#include "tfm/tfmp_tfm_const.h"
#endif

namespace tfmp{
namespace tfm{
namespace data{


ExtenCommand::ExtenCommand(char *bytes) {
    top_ = (unsigned char)bytes[0];
    mid_ = (unsigned char)bytes[1];
    bot_ = (unsigned char)bytes[2];
    rep_ = (unsigned char)bytes[3];
}
ExtenCommand::~ExtenCommand() {
    ;
}
int ExtenCommand::Show(tfmp::DisplayBoard *display_board) {
    display_board->Puts(std::to_string(top_) + "\n");
    display_board->Puts(std::to_string(mid_) + "\n");
    display_board->Puts(std::to_string(bot_) + "\n");
    display_board->Puts(std::to_string(rep_) + "\n");
    return 0;
}

Exten::Exten() {
    ne_ = 0;
    commands_ = NULL;
}
Exten::~Exten() {
    for(int i=0; i<ne_; i++) {
        delete commands_[i];
    }
    delete []commands_;
}
int Exten::Parse(unsigned int ne, std::ifstream* tfm_ifs) {
    ne_ = ne;
    commands_ = new struct ExtenCommand*[ne_];
    char *buff = new char [tfmp::tfm::kSizeofExtenCommand];
    for(int i=0; i<ne_; i++) {
        tfm_ifs->read(buff, tfmp::tfm::kSizeofExtenCommand);
        commands_[i] = new struct ExtenCommand(buff);
    }
    delete []buff;
    return 0;
}
int Exten::Show(tfmp::DisplayBoard *display_board) {
    display_board->Puts(std::to_string(ne_) + "\n");
    for(int i=0; i<ne_; i++) {
        display_board->Puts(std::to_string(i) + "\n");
        commands_[i]->Show(display_board);
    }
    return 0;
}

} // namespace data
} // namespace tfm    
} // namespace tfmp