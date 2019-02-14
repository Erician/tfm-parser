#include <limits.h>
#include "gtest/gtest.h"
#include "display/tfmp_display_board.h"

TEST(DisolayBoardTest, PutToConsole_ShouldPass)
{
    tfmp::DisplayBoard db;
    db.Put('a');
}

TEST(DisolayBoardTest, PutToFile_ShouldPass)
{
    tfmp::DisplayBoard db("aaa");
    db.Put('a');
    db.Close();

    std::ifstream ifs = std::ifstream("aaa", std::ifstream::in);
    assert(ifs);
    char c;
    ifs.get(c);
    ASSERT_EQ(c, 'a');
    
    remove("aaa");
}

TEST(DisolayBoardTest, PutsToConsole_ShouldPass)
{
    tfmp::DisplayBoard db;
    db.Puts("aa");
}


TEST(DisolayBoardTest, PutsToFile_ShouldPass)
{
    tfmp::DisplayBoard db("aaa");
    db.Puts("aa");
    db.Close();

    std::ifstream ifs = std::ifstream("aaa", std::ifstream::in);
    assert(ifs);
    char c;
    ifs.get(c);
    ASSERT_EQ(c, 'a');
    ifs.get(c);
    ASSERT_EQ(c, 'a');
    
    remove("aaa");
}



