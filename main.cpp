#define STB_IMAGE_IMPLEMENTATION
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>

#include "cmd.h"
#include "stb_image.h"
#include "character_map.h"

int main(int argc, char *argv[])
{
    /*
    The CLI part is kept minimalistic, hence the user is expected to provide even the default value.
    */

    if (argc < 2)
    {
        cmd::displayBanner(argv[0]);
        return 1;
    }

    // GET IMAGE PATH
    char *filePath = argv[1];

    // GET THE SCALE FACTOR, DEFAULT 1
    float scalingFactor = 1;
    if (argc >= 3)
    {
        scalingFactor = cmd::parseFloatFromCstring(argv[2]);
    }

    // GET WHETHER USER WANTS TO USE COLOR
    bool putColor = false;
    if (argc >= 4)
    {
        putColor = cmd::parseBoolFromCstring(argv[3]);
    }

    // OPEN THE IMAGE OR USE DATA FROM STDIN
    int imageWidth, imageHeight, channelCount;
    unsigned char *image = nullptr;

    if (std::strcmp(filePath, "") == 0)
    {
        std::vector<unsigned char> imageData = cmd::readImageFromStdin();
        if (imageData.size() == 0)
        {
            std::cerr << "error: no input provided. either provide a file path or data through `stdin`\n";
            return 1;
        }

        image = stbi_load_from_memory(imageData.data(), imageData.size(), &imageWidth, &imageHeight, &channelCount, 3);
    }
    else
    {
        image = stbi_load(filePath, &imageWidth, &imageHeight, &channelCount, 3);
    }

    if (!image)
    {
        std::cerr << "error: failed to load image: " << filePath << "\n";
        return 1;
    }

    int scaledWidth = static_cast<int>(imageWidth * scalingFactor);
    int scaledHeight = static_cast<int>(imageHeight * scalingFactor);

    std::ostringstream oss;

    // SCALING + PIXEL GENERATION
    for (int yN = 0; yN < scaledHeight; ++yN)
    {

        int yO = static_cast<int>(yN / scalingFactor);

        for (int xN = 0; xN < scaledWidth; ++xN)
        {
            int xO = static_cast<int>(xN / scalingFactor);
            int index = (yO * imageWidth + xO) * 3;

            unsigned char r = image[index];
            unsigned char g = image[index + 1];
            unsigned char b = image[index + 2];

            int brightness = static_cast<int>((0.299f * r + 0.587 * g + 0.114f * b));
            char pixel = CHARACTER_MAP[brightness];

            if (putColor)
                oss << cmd::coloredText(&pixel, r, g, b);
            else
                oss << pixel;
        }
        oss << "\n";
    }

    std::cout << oss.str();

    stbi_image_free(image);
    return 0;
}