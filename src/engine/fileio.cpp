#include "fileio.hpp"
#include <fstream>
#include <sstream>


namespace FileIO {
    std::string ReadFile(std::string filename){
        std::ifstream file(filename);
        if(!file){
            std::printf("Failed to Open %s", filename.c_str());
            return NULL;
        }
        std::stringstream buffer;
        buffer << file.rdbuf(); 
        file.close();
        return buffer.str();
    }
}