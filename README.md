# SimulatorPIA – Componente educativo de ciberseguridad en C++

## Objetivo del proyecto

Desarrollar un simulador educativo en C++ que implemente técnicas básicas de análisis de comportamiento tipo malware en un entorno controlado mediante máquinas virtuales.

El proyecto permite observar acceso a archivos locales y captura de tráfico ICMP como base para análisis estático y dinámico en ciberseguridad.

## Descripción técnica

SimulatorPIA es una herramienta modular desarrollada en C++ que implementa:

- lectura controlada de archivos locales
- captura de tráfico de red ICMP usando libpcap
- ejecución en entorno aislado (Ubuntu VM)

El diseño permite integrar módulos adicionales como enumeración de procesos, generación de hashes y detección de debugging en fases posteriores del proyecto.

## Alcance y límites

Incluye:

- simulación educativa de acceso a archivos
- captura de paquetes ICMP en red virtual
- arquitectura modular en C++
- ejecución controlada dentro de máquina virtual

No incluye:

- persistencia en el sistema
- comunicación con servidores externos
- exfiltración de información
- modificaciones al sistema anfitrión

## Compilación

Ejecutar dentro de la carpeta principal del proyecto:

```bash
g++ src/*.cpp -lpcap -o SimulatorPIA

## Integrantes y responsabilidades técnicas

Joustin Martinez

Diseño de la arquitectura inicial del proyecto, implementación del módulo file_reader e integración del sistema de compilación en entorno virtual Linux.

Alendra

Implementación del módulo packet_sniffer mediante libpcap y validación experimental de la captura de tráfico ICMP dentro de la red virtual.

Santiago

Organización de la estructura modular del repositorio, preparación de los módulos process_enum y hasher y apoyo en pruebas de ejecución del simulador dentro de la máquina virtual.
