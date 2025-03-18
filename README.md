# Stallion

## About
Stallion is a custom open-source, modular game engine written in C++ for high performance and great stability. It targets Vulkan, Direct3D 12, and Metal 3 as its graphics backends and offers a novel GPGPU-based approach for physics calculations. The engine serves as a middleware layer, abstracting the complexities of modern rendering APIs while still allowing low-level control where needed.  

## Features
- **Cross-Platform Native Application** - Uses Native APIs for GUI, ensuring the editor fits in with each OS's interface guidelines.
- **Multi-Backend Graphics API** – Supports Vulkan, Direct3D 12, and Metal 3.  
- **GPGPU Physics Acceleration** – Compute shader-based physics for high-performance simulations.   
- **Modular Architecture** – Designed for flexibility, allowing developers to use specific engine components independently.

## Prerequisites
- [CMake](https://cmake.org) (for project configuration)  
- A compatible C++ compiler supporting C++20 or later  

### Vulkan Specific  
- [Vulkan SDK](https://www.lunarg.com/vulkan-sdk/)  

### DirectX 12 Specific  
- Windows SDK (installed via Visual Studio)  

### Metal Specific  
- Xcode with Metal support (for macOS and iOS development)  

## Getting Started
To build Stallion, follow these steps:

```sh
git clone --recurse-submodules https://github.com/yourrepo/stallion.git
cd stallion
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

## Contributions
We welcome contributions! If you’d like to contribute, please follow these steps:

1. Fork the repository
2. Create a new branch for your feature/bugfix
3. Submit a pull request with a clear description of your changes
For detailed contribution guidelines, see [CONTRIBUTING.md](CONTRIBUTING.md).

## License
Stallion is licensed under the GNU General Public License v3.0.
See [LICENSE](LICENSE) for details.