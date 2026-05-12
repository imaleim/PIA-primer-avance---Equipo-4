include "process_enum.h"
#include <iostream>
#include <dirent.h>
#include <cctype>

void listProcesses() {

    DIR *dir;
    struct dirent *ent;

    dir = opendir("/proc");

    if (dir != NULL) {

        std::cout << "\n[Procesos activos]\n";

        while ((ent = readdir(dir)) != NULL) {

            // Detectar carpetas numéricas (PIDs)
            if (isdigit(ent->d_name[0])) {

                std::cout << "PID: "
                          << ent->d_name
                          << std::endl;
            }
}

        closedir(dir);

    } else {

        std::cout << "No se pudo abrir /proc"
                  << std::endl;
    }
}

