#include <iostream>
#include "file_reader.h"
#include "packet_sniffer.h"

int main()
{
    std::cout << "[SimulatorPIA iniciado]\n";

    readFile("test.txt");

    startSniffer();

    return 0;
}
