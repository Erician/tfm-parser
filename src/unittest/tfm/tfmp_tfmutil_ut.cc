#include <limits.h>
#include "gtest/gtest.h"

#ifndef TFMP_TFM_TFMP_TFMPUTIL_H_
#include "tfm/tfmp_tfmutil.h"
#endif

TEST(FixWordToFloatTest, JustInteger_ShouldPass)
{
    char t1[4] = {0x00, (char)0xA0, 0x00, 0x00};
    float s_t1 = 10;
    ASSERT_EQ(tfmp::tfm::FixWordToFloat(t1), s_t1);
}

TEST(FixWordToFloatTest, JustFraction_ShouldPass)
{
    char t1[4] = {0x00, 0x02, 0x00, 0x00};
    float s_t1 = 0.125;
    ASSERT_EQ(tfmp::tfm::FixWordToFloat(t1), s_t1);
}

TEST(FixWordToFloatTest, IntegerAndFraction_ShouldPass)
{
    char t1[4] = {0x00, (char)0xA2, 0x00, 0x00};
    float s_t1 = 10.125;
    ASSERT_EQ(tfmp::tfm::FixWordToFloat(t1), s_t1);
}

TEST(FixWordToFloatTest, MinusIntegerAndFraction_ShouldPass)
{
    char t1[4] = {(char)0xff, (char)0xf2, 0x00, 0x00};
    float s_t1 = -1.125;
    ASSERT_EQ(tfmp::tfm::FixWordToFloat(t1), s_t1);
}