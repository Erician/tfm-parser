#ifndef TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_
#define TFMP_DISPLAY_TFMP_DISPLAY_BOARD_H_

#include <fstream>

namespace tfmp
{

class DisplayBoard 
{
private:
    std::string output_file_name_;
    std::ofstream * output_file_stream_;
    std::ostream *board_;
public:
    DisplayBoard();
    DisplayBoard(std::string output_file_name);
    void SetBoard();
    void SetBoard(std::string out_file_name);
    void Puts(std::string str);
    void Put(char c);

    void Close();
};

} // namespace tfmp


#endif