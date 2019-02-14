#include <iostream>
#include <elf.h>
#include <unistd.h>
#include <string.h>
#include <bitset>


int main() {
    char t1[4] = {'b', 'a', 'c', 'd'}; // must be 0 or 1
    std::string tmp = std::string(t1, 4);
    std::cout << tmp << std::endl;
    std::bitset<100> b_fix_word(std::string("ads")); 
    std::cout << b_fix_word.to_string();
}