#include "hasher.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

void generateHash(const char* filename) {

    std::ifstream file(filename);

    if (!file) {

        std::cout << "\n[HASH] No se pudo abrir el archivo\n";
        return;
    }

    unsigned long hash = 5381;
    char c;

    while (file.get(c)) {
        hash = ((hash << 5) + hash) + c;
    }
  
    std::cout << "\n[HASH SIMULADO]\n";
    std::cout << "Archivo: " << filename << std::endl;
    std::cout << "Hash: "
              << std::hex
              << hash
              << std::endl;
}



    std::cout << "\n[HASH SIMULADO]\n";
