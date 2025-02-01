#include <iostream>
#include <string>
#include <random>
#include <stdexcept>

std::string generate_password(const int length) {
    const std::string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> dist(0, charset.size() - 1);

    std::string result;
    for (int i = 0; i < length; ++i) {
        result += charset[dist(generator)];
    }
    return result;
}

int main(const int argc, char* argv[]) {
    try {
        int length = 8; // Default value

        if (argc > 1) {
            size_t pos;
            length = std::stoi(argv[1], &pos);

            if (pos != strlen(argv[1])) {
                throw std::invalid_argument("contains non-numeric characters");
            }

            if (length < 1) {
                throw std::out_of_range("must be at least 1");
            }
        }

        std::cout << generate_password(length) << "\n";
        return 0;

    } catch (const std::exception& e) {
        std::cerr << "Error: Invalid argument '" << argv[1] << "' - " << e.what() << "\n";
        std::cerr << "Usage: " << argv[0] << " [password-length]\n";
        return 1;
    }
}
