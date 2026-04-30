#include <iostream>
#include <fstream>
#include "file_reader.h"

void readFile(const char* filename)
{
    std::ifstream file(filename);

    if(!file)
    {
        std::cout << "No se pudo abrir el archivo\n";
        return;
    }

    std::string line;

    while(getline(file, line))
    {
        std::cout << line << std::endl;
    }

    file.close();
}
