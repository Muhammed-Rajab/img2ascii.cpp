#ifndef CMD_UTLILS_4_IMG2ASCII_CPP
#define CMD_UTLILS_4_IMG2ASCII_CPP

#include <iostream>
#include <cstdint>
#include <vector>

namespace cmd
{
    void displayBanner(char *path);
    bool parseBoolFromCstring(const char *str);
    float parseFloatFromCstring(const char *str);
    std::vector<unsigned char> readImageFromStdin();
    std::string coloredText(const char *str, uint8_t r, uint8_t g, uint8_t b);

};

#endif