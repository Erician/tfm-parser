#include <limits.h>
#include "gtest/gtest.h"

#ifndef TFMP_TFM_TFMP_TFM_HEADER_H_
#include "tfm/tfmp_tfm_header.h"
#endif

#include <fstream>

class TfmHeaderTest : public ::testing::Test
{
protected:
    virtual void SetUp() {
        ;
    }
    virtual void TearDown() {
        ;
    }
    tfmp::tfm::Header header;
};


TEST_F(TfmHeaderTest, Parse_ShouldPass)
{
    std::ifstream *tfm_ifs = new std::ifstream();
    tfm_ifs->open("./cmr10.tfm", std::ifstream::in);
    ASSERT_EQ(0, header.Parse(tfm_ifs));
}

TEST_F(TfmHeaderTest, Check_ShouldPass)
{
    std::ifstream *tfm_ifs = new std::ifstream();
    tfm_ifs->open("./cmr10.tfm", std::ifstream::in);
    ASSERT_EQ(0, header.Parse(tfm_ifs));
    ASSERT_EQ(0, header.Check());
}

TEST_F(TfmHeaderTest, Show_ShouldPass)
{
    std::ifstream *tfm_ifs = new std::ifstream();
    tfm_ifs->open("./cmr10.tfm", std::ifstream::in);
    ASSERT_EQ(0, header.Parse(tfm_ifs));
    ASSERT_EQ(0, header.Check());
    tfmp::DisplayBoard *db = new tfmp::DisplayBoard("aaa");
    header.Show(db);
    db->Close();

    unsigned short lf_ = 324;       /* length of the entire ﬁle, in words */
    unsigned short lh_ = 18;        /* length of the header data, in words */
    unsigned short bc_ = 0;         /* smallest character code in the font */
    unsigned short ec_ = 127;       /* largest character code in the font */
    unsigned short nw_ = 36;        /* number of words in the width table */
    unsigned short nh_ = 16;        /* number of words in the height table */
    unsigned short nd_ = 10;        /* number of words in the depth table */
    unsigned short ni_ = 5;         /* number of words in the italic correction table */
    unsigned short nl_ = 88;        /* number of words in the lig/kern table */
    unsigned short nk_ = 10;        /* number of words in the kern table */
    unsigned short ne_ = 0;         /* number of words in the extensible character table */
    unsigned short np_ = 7;         /* number of font parameter words */

    std::ifstream ifs = std::ifstream("aaa", std::ifstream::in);
    assert(ifs);
    const int len = 10;
    char *buffer = new char[len];
    ifs.getline(buffer, len);
    ASSERT_EQ(lf_, atoi(buffer));

    ifs.getline(buffer, len);
    ASSERT_EQ(lh_, atoi(buffer));

    ifs.getline(buffer, len);
    ASSERT_EQ(bc_, atoi(buffer));

    ifs.getline(buffer, len);
    ASSERT_EQ(ec_, atoi(buffer));

    ifs.getline(buffer, len);
    ASSERT_EQ(nw_, atoi(buffer));

    ifs.getline(buffer, len);
    ASSERT_EQ(nh_, atoi(buffer));

    ifs.getline(buffer, len);
    ASSERT_EQ(nd_, atoi(buffer));

    ifs.getline(buffer, len);
    ASSERT_EQ(ni_, atoi(buffer));

    ifs.getline(buffer, len);
    ASSERT_EQ(nl_, atoi(buffer));

    ifs.getline(buffer, len);
    ASSERT_EQ(nk_, atoi(buffer));

    ifs.getline(buffer, len);
    ASSERT_EQ(ne_, atoi(buffer));

    ifs.getline(buffer, len);
    ASSERT_EQ(np_, atoi(buffer));

    remove("aaa");
    delete[] buffer;

}
