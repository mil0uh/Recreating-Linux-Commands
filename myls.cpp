#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
// #include <fstream>
// #include <typeinfo>
// Need to sort files alphabetically and display them in the order
// For base command if it starts with . then ignore it 

// For now lets put them all in a string vector

namespace fs = std::filesystem;

std::string flags {"None"};
std::string filepath = fs::current_path();
std::vector<std::string> allStrings; 

int main(int argc, char* argv[]){

    if (argc >= 2){
        flags = argv[1];
    }

    for (auto& entry : fs::directory_iterator(filepath)){
        if (entry.is_regular_file()){
            allStrings.push_back(entry.path().filename());
        }

        if (entry.is_directory()){
            allStrings.push_back(entry.path().filename());

        }

    }

    std::sort(allStrings.begin(), allStrings.end());

    for (std::string s : allStrings){
        if ((s.at(0) != '.') && (flags == "None")){
            std::cout << s << std::endl;
        }
        if (flags == "-a") {
            std::cout << s << std::endl;
        }
    }

    
    return 0;
}