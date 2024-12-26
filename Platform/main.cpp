#include "Application.hpp"

int main() {
    try {
        Platform::Application app;
        app.Run();

    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}