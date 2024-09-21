#include <vector>
#include <sstream>
#include <cstdint>
#include <cstring>
#include <iostream>

#include "cmd.h"

std::string cmd::coloredText(const char *str, uint8_t r, uint8_t g, uint8_t b)
{
    std::ostringstream text;
    text << "\033[38;2;" << (int)r << ";" << (int)g << ";" << (int)b << "m" << *str << "\033[0m";
    return text.str();
}

float cmd::parseFloatFromCstring(const char *str)
{
    char *end;
    errno = 0;

    float value = std::strtof(str, &end);

    if (errno == ERANGE)
    {
        std::cerr << "error: out of range value for float\n";
        exit(EXIT_FAILURE);
    }

    if (end == str)
    {
        std::cerr << "error: no digits were found\n";
        exit(EXIT_FAILURE);
    }

    if (*end != '\0')
    {
        std::cerr << "error: invalid character found after number: '" << *end << "'\n";
        exit(EXIT_FAILURE);
    }

    return value;
}

bool cmd::parseBoolFromCstring(const char *str)
{
    if (std::strcmp(str, "true") == 0)
    {
        return true;
    }
    else if (strcmp(str, "false") == 0)
    {
        return false;
    }
    else
    {
        std::cerr << "error: invalid boolean value '" << *str << "'\n";
        exit(EXIT_FAILURE);
    }
}

void cmd::displayBanner(char *path)
{
    std::printf("Usage: %s <path> <scale> <color>\n"
                "\n"
                "path[string]: path to the image file you want to open (optional if `stdin` is provided)\n"
                "scale[float]: scale factor for the generated image (>0, optional, default=1)\n"
                "color[true/false]: shows ASCII character in ANSI-supported terminals (optional, default=false)\n"
                "\n"
                "`path` can be set to \"\", if you are providing data through `stdin`",
                path);
}

std::vector<unsigned char> cmd::readImageFromStdin()
{
    std::vector<unsigned char> buffer;
    char byte;

    while (std::cin.read(&byte, 1))
    {
        buffer.push_back(static_cast<unsigned char>(byte));
    }

    return buffer;
}
