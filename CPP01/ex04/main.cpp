#include "main.hpp"

std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.erase(start_pos, from.length());
        str.insert(start_pos, to);
        start_pos += to.length();
    }
    return str;
}

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string File = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];
        std::string content;

        std::ifstream inFile(File.c_str());
        if(inFile.is_open()){
            
            std::stringstream buffer;
            buffer << inFile.rdbuf();
            content = buffer.str();
            inFile.close();
        }

        content = replaceAll(content, s1, s2);
        
        std::string FileToCreate = File + ".replace";
        std::ofstream MyFile(FileToCreate.c_str());
        MyFile << content;
        MyFile.close();
    }
    else
    {
        std::cout << "Pa-pa-pa, no way you dont listen on how it is supposed to be done 3 parameters" << std::endl;
        std::cout << " Try again\n dont forget to start a program )" << std::endl;
    }
    return 0;
}