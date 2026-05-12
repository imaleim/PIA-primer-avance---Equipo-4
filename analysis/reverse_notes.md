# Notas de reversing

## Strings identificados

Durante el análisis estático se identificaron referencias a:

- libpcap
- pcap_loop
- pcap_open_live
- funciones de C++
- mensajes internos del programa

## Funciones detectadas

El binario contiene funciones relacionadas con:

- captura de tráfico ICMP
- lectura de archivos
- generación de hash
- enumeración de procesos

## Observaciones técnicas

La versión debug contiene símbolos visibles y secciones .debug_* que facilitan el análisis estático y reversing.

También se identificaron secciones ELF como:

- .text
- .data
- .bss
- .rodata

## Hallazgos

El programa realiza correctamente captura de tráfico mediante libpcap y puede ejecutarse dentro de una máquina virtual Ubuntu.

La versión release fue procesada usando strip para remover símbolos y dificultar parcialmente el análisis.
