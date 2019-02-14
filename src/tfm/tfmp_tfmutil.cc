#ifndef TFMP_TFM_TFMP_TFMPUTIL_H_
#include "tfm/tfmp_tfmutil.h"
#endif

#ifndef UTILS_STRINGUTIL_H_
#include "utils/stringutil.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_CONST_H_
#include "tfm/tfmp_tfm_const.h"
#endif

#include <math.h>

namespace tfmp{
namespace tfm{
    
float FixWordToFloat(char* fix_word) {
    int i_integer;
    char c_integer[2];
    c_integer[0] = (fix_word[0]&0xf0)>>4;
    c_integer[1] = ((fix_word[0]&0x0f)<<4)|((fix_word[1]&0xf0)>>4);

    bool is_minus = false;
    if(fix_word[0]>>7&0x01) {
        is_minus = true;
        /* 取反, 加一 */
        unsigned int tmp = ((((unsigned char)fix_word[0]^0xff)<<4) | \
        (((unsigned char)fix_word[1]^0xff)>>4)) + 1;
        c_integer[0] = (tmp&0xf00)>>4;
        c_integer[1] = (tmp&0xff);
    }
    i_integer = utils::stringutil::BytesToIntWithBigEndian(c_integer, 0, 2);
    
    float fraction = 0;
    for(int i=12; i<kBitLenFixWord; i++) {
        int bit = (fix_word[i/8]>>(7-i%8))&0x01;
        fraction += pow(2, 12-1-i) * bit;
    }
    return is_minus ? -i_integer-fraction : i_integer+fraction;
}

} // namespace tfm    
} // namespace tfmp