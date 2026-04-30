# Diseño técnico – SimulatorPIA

## Arquitectura general

SimulatorPIA es un componente educativo de ciberseguridad desarrollado en C++ con arquitectura modular. Cada técnica simulada se implementa como un módulo independiente dentro del directorio /src.

El archivo main.cpp coordina la ejecución de los módulos.

## Módulos implementados

file_reader

Simula el acceso a archivos locales mediante lectura controlada de contenido desde test.txt.

packet_sniffer

Captura tráfico de red local utilizando la librería libpcap y detecta paquetes ICMP dentro de la red virtual.

## Módulos planeados

process_enum

Permitirá enumerar procesos activos del sistema para análisis de comportamiento.

hasher

Permitirá generar hashes de archivos usando algoritmos seguros (SHA-256).

anti_debug (fase posterior)

Detectará la presencia de herramientas de depuración durante la ejecución.

## Flujo general del programa

Inicio del programa

↓

Lectura de archivo local (file_reader)

↓

Captura de tráfico ICMP (packet_sniffer)

↓

Finalización controlada del programa

## Dependencias técnicas

Compilador g++

Librería libpcap (captura de paquetes de red)

Sistema operativo Linux (Ubuntu en máquina virtual aislada)
