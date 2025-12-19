#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;

std::string flags {"None"};
std::string filepath = fs::current_path();
std::vector<fs::directory_entry> allEntries; 

std::string filePermissions(fs::perms p){
    std::string allPerms {};
    allPerms += ((p & fs::perms::owner_read) != fs::perms::none) ? 'r' : '-';
    allPerms += ((p & fs::perms::owner_write) != fs::perms::none) ? 'w' : '-';
    allPerms += ((p & fs::perms::owner_exec) != fs::perms::none) ? 'x' : '-';
    allPerms += ((p & fs::perms::group_read) != fs::perms::none) ? 'r' : '-';
    allPerms += ((p & fs::perms::group_write) != fs::perms::none) ? 'w' : '-';
    allPerms += ((p & fs::perms::group_exec) != fs::perms::none) ? 'x' : '-';
    allPerms += ((p & fs::perms::others_read) != fs::perms::none) ? 'r' : '-';
    allPerms += ((p & fs::perms::others_write) != fs::perms::none) ? 'w' : '-';
    allPerms += ((p & fs::perms::others_exec) != fs::perms::none) ? 'x' : '-';
    

    return allPerms;
}


int main(int argc, char* argv[]){

    if (argc >= 2){
        flags = argv[1];
    }

    for (auto& entry : fs::directory_iterator(filepath)){
        if (entry.is_regular_file()){
            allEntries.push_back(entry);
        }

        if (entry.is_directory()){
            allEntries.push_back(entry);
        }
    }

    std::sort(allEntries.begin(), allEntries.end());

    for (int i = 0; i < allEntries.size(); i++){
        std::string currentEntry = allEntries.at(i).path().filename();
        if ((currentEntry.at(0) != '.' ) && (flags == "None")) {
            std::cout << currentEntry << " ";
        }
        if (flags == "-a") {
            std::cout << currentEntry << " ";
        }

        if ((flags == "-l") && currentEntry.at(0) != '.'){
            std::cout << filePermissions(allEntries.at(i).status().permissions()) << " " << currentEntry << std::endl;
        }

    }

    printf("\n");


    return 0;
}