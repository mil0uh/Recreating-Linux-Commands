#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    
    const char* file;
    
    if (argc >= 2) {
        file = argv[1];
    }
    else{
        std::cout << "Usage: cat <fileName> " << std::endl;
    }

    std::ifstream myRead(file);
    std::string myText;
    
    if (!myRead){
        printf("The file %s does not exist\n", file);
    }

    while(getline(myRead, myText)){
        std::cout << myText <<std::endl;
    }

    return 0;

}