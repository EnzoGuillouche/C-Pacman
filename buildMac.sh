clear

DIR="Bin"
PROGRAM="PacSDL" 

mkdir -p $DIR

# Check if gcc is installed
if ! brew list --formula | grep -q "^gcc$"; then
    echo "gcc library not found. Installing..."
    brew install gcc
else
    echo "gcc is already installed."
fi

# Check if sdl2 is installed
if ! brew list --formula | grep -q "^sdl2$"; then
    echo "sdl2 library not found. Installing..."
    brew install sdl2
else
    echo "sdl2 is already installed."
fi

# Check if sdl2 is installed
if ! brew list --formula | grep -q "^sdl2_image$"; then
    echo "sdl2_image library not found. Installing..."
    brew install sdl2_image
else
    echo "sdl2_image is already installed."
fi

gcc -o $DIR/$PROGRAM Src/main.c `sdl2-config --cflags --libs` -std=c99 -Wall -Wextra -g -O0 -lm

if [ $? -eq 0 ]; then
    echo "Compilation complete. Executable is located at $DIR/$PROGRAM"
    sleep 1
    echo "Running $PROGRAM..."
    ./$DIR/$PROGRAM
else
    echo "Compilation failed."
    exit 1
fi