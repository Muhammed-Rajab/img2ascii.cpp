
# img2ascii.cpp

Convert your images🖼️ to ASCII art🎨 instantly with `img2ascii.cpp`!

## Description

`img2ascii.cpp` allows users to easily scale down images while converting them to ASCII art. Choose between classic monochrome output or vibrant ANSI color-coded text for a dynamic visual experience. Perfect for adding a creative touch to your projects!
## Features

- **Image Scaling**: Easily scale down images for - better ASCII representation.
- **Color Options**: Choose between colorless ASCII art or ANSI color-coded text.
- **Minimal CLI**: Simple command-line interface for easy use.
## Build

To build img2ascii.cpp, you need a C++ compiler. Use the following command:

```
g++ img2ascii.cpp cmd.cpp -o img2ascii
```

I developed this project using `g++ 13.2.0`.
## Usage

To use img2ascii.cpp, run the following command:

```
./img2ascii <image_path> <scaling_factor> <use_color>
```

### Parameters
-  `<image_path>`: Path to the image you want to convert. If no path is provided, the program will attempt to read from standard input.

- `<scaling_factor>`: (Optional) A float value to scale the image. Default is 1.

- `<use_color>`: (Optional) A boolean value (true or false) to specify if you want color in the output. Default is false.
## Examples


```bash
./img2ascii examples/1.jpeg .5 true
```

```bash
./img2ascii examples/2.png .2 true
```

## Results

- 1
    - [Original](/examples/1.jpeg)
    - [ASCII](https://youtube.com/shorts/3T8QE3FaFUk)

- 2
    - [Original](/examples/2.png)
    - [ASCII](https://youtube.com/shorts/ExTeKufisk0?feature=share)

- 3
    - [Original](/examples/3.png)
    - [ASCII](https://youtu.be/cqHEAjxs-Rc)

- 4
    - [Original](/examples/4.png)
    - [ASCII](https://youtu.be/aiVsx3GAszc)



Feel free to experiment with the CLI using the sample images located in the examples/ directory. You can adjust your terminal's zoom level or modify the scaling factor to achieve your desired resolution. Note that high-quality images cannot be provided due to file sizes being 100MB or larger.

## Dependencies

- `stb_image.h`: Used for loading images.
## License

This project is licensed under the MIT License. See the [LICENSE](/LICENSE) file for details.