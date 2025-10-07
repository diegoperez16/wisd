# wisd
This is the official repository for 'Walter in San Digo: It's hard to be alive'

## About
A C++ videogame built using [raylib](https://www.raylib.com/).

## Building

### Prerequisites
- CMake 3.15 or higher
- C++17 compatible compiler (GCC, Clang, MSVC)
- Git

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/diegoperez16/wisd.git
cd wisd

# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
cmake --build .

# Run the game
./wisd  # On Linux/macOS
# or
wisd.exe  # On Windows
```

The project will automatically download and build raylib as a dependency if it's not found on your system.

## Controls
- ESC: Exit the game

## License
See LICENSE file for details.

