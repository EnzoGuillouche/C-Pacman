import sys
from PIL import Image
import os

def image_to_hex(input_image_path, output_txt_path):
    img = Image.open(input_image_path).convert("RGB")
    width, height = img.size
    pixels = img.load()

    # Write pixel hex values to file
    with open(output_txt_path, "w") as f:
        for y in range(height):
            for x in range(width):
                r, g, b = pixels[x, y]
                hex_color = f"0x{r:02X}{g:02X}{b:02X}"
                f.write(hex_color + " ")
            f.write("\n")  # New line per row

    print(f"Done! Saved {width * height} pixels to '{output_txt_path}'.")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python imageConverter.py <input_image> <output_txt>")
        sys.exit(1)

    input_image = sys.argv[1]
    output_txt = sys.argv[2]
    image_to_hex(input_image, output_txt)
