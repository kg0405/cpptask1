#include <iostream>
#include <cstdlib>

void buildMain() {
    std::cout << "Compiling taske1.cpp to create 'Main'..." << std::endl;
    int result = system("g++ -Wall -g -o Main taske1.cpp");
    if (result == 0)
        std::cout << "Build successful." << std::endl;
    else
        std::cerr << "Build failed." << std::endl;
}

void runValgrind() {
    std::cout << "Running valgrind on 'Main'..." << std::endl;
    int result = system("valgrind --leak-check=full ./Main");
    if (result != 0)
        std::cerr << "Valgrind encountered errors." << std::endl;
}

void clean() {
    std::cout << "Cleaning up compiled files..." << std::endl;
    system("rm -f Main test");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./builder [Main|test|valgrind|clean]" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    if (command == "Main") {
        buildMain();
    }  else if (command == "valgrind") {
        runValgrind();
    } else if (command == "clean") {
        clean();
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1;
    }

    return 0;
}
