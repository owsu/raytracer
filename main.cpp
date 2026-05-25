#include <cstdint>
#include <fstream>

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    std::ofstream output("image.ppm", std::ios::binary);
    output << "P6\n" << image_width << " " << image_height << "\n255\n";

    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {
            auto r = double(j) / (image_width-1);
            auto g = double(i) / (image_height-1);
            auto b = 0.25 + 0.75 * (1.0 - r) * (1.0 - g);

            std::uint8_t ir = static_cast<std::uint8_t>(255.999 * r);
            std::uint8_t ig = static_cast<std::uint8_t>(255.999 * g);
            std::uint8_t ib = static_cast<std::uint8_t>(255.999 * b);

            output.write(reinterpret_cast<const char*>(&ir), 1);
            output.write(reinterpret_cast<const char*>(&ig), 1);
            output.write(reinterpret_cast<const char*>(&ib), 1);
        }
    }

    return 0;
}