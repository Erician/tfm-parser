#include <limits.h>
#include "gtest/gtest.h"

#ifndef TFMP_TFM_TFMP_TFM_DATA_HEADER_H_
#include "tfm/tfmp_tfm_data_header.h"
#endif

#ifndef TFMP_TFM_TFMP_TFM_HEADER_H_
#include "tfm/tfmp_tfm_header.h"
#endif

#include <fstream>

class TfmDataHeaderTest : public ::testing::Test
{
protected:
    virtual void SetUp() {
        ;
    }
    virtual void TearDown() {
        ;
    }
    tfmp::tfm::Header header;
    tfmp::tfm::data::Header data_header;
};

TEST_F(TfmDataHeaderTest, Parse_ShouldPass)
{
    std::ifstream *tfm_ifs = new std::ifstream();
    tfm_ifs->open("./cmr10.tfm", std::ifstream::in);
    ASSERT_EQ(0, header.Parse(tfm_ifs));
    ASSERT_EQ(0, data_header.Parse(header.lh_, tfm_ifs));
}

TEST_F(TfmDataHeaderTest, Show_ShouldPass)
{
    std::ifstream *tfm_ifs = new std::ifstream();
    tfm_ifs->open("./cmr10.tfm", std::ifstream::in);
    ASSERT_EQ(0, header.Parse(tfm_ifs));
    ASSERT_EQ(0, data_header.Parse(header.lh_, tfm_ifs));
    
    tfmp::DisplayBoard *db = new tfmp::DisplayBoard("aaa");
    data_header.Show(db);
    db->Close();
    remove("aaa");
}

