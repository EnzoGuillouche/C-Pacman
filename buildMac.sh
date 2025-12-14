clear

DIR="Bin"
PROGRAM="PacSDL" 

# Check if gcc is installed
if ! brew list --formula | grep -q "^gcc$"; then
    echo "gcc library not found. Installing..."
    brew install gcc
else
    echo "gcc is already installed."
fi

# Check if sdl2 is installed
if ! brew list --formula | grep -q "^sdl2$"; then
    echo "SDL2 library not found. Installing..."
    brew install sdl2
else
    echo "sdl2 is already installed."
fi

gcc -o $DIR/$PROGRAM Src/main.c
echo "Build complete. Executable is located at $DIR/$PROGRAM"
./$DIR/$PROGRAM