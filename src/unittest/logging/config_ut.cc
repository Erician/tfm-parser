#include <limits.h>
#include "gtest/gtest.h"
#include "logging/config.h"
#include "logging/const.h"

class ConfigTest : public ::testing::Test
{
protected:
    virtual void SetUp() {
        config.Init("logging/logging.ini");
    }
    virtual void TearDown() {
        ;
    }
    Config config;
};

TEST_F(ConfigTest, IsHave_ShouldPass)
{
    ASSERT_EQ(true, config.IsHave(config::kLogFilePath));
}

TEST_F(ConfigTest, GetValue_ShouldPass)
{
    ASSERT_EQ("../logs/log.txt", config.GetValue(config::kLogFilePath));
}


