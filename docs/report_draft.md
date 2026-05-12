# Borrador técnico — SimulatorPIA

## Descripción del payload

SimulatorPIA es un componente educativo desarrollado en C++ orientado al aprendizaje de técnicas básicas utilizadas en análisis defensivo y simulación controlada de comportamiento tipo malware.

El proyecto fue diseñado para ejecutarse únicamente dentro de máquinas virtuales Ubuntu y no realiza acciones maliciosas reales.

Actualmente el programa implementa:

- lectura de archivos locales
- captura de tráfico ICMP mediante libpcap
- enumeración de procesos activos
- generación simulada de hashes
- arquitectura modular para futuras extensiones

El objetivo principal es permitir prácticas de análisis estático, reversing básico y monitoreo de comportamiento dentro de un entorno controlado.

---

# Diseño del sistema

El proyecto utiliza una arquitectura modular dividida en varios componentes independientes.

## Módulos implementados

### file_reader

Permite abrir y leer archivos locales del sistema para pruebas controladas de acceso a archivos.

### packet_sniffer

Utiliza la librería libpcap para capturar paquetes ICMP dentro de la máquina virtual.

### process_enum

Realiza enumeración básica de procesos activos del sistema Linux mediante acceso al directorio /proc.

### hasher

Genera un hash simulado de archivos para representar técnicas de integridad y análisis.

### main.cpp

Coordina todos los módulos y controla el flujo general del programa.

---

# Pruebas realizadas

Las pruebas fueron ejecutadas dentro de una máquina virtual Ubuntu aislada.

## Compilación

Se generaron dos binarios:

### Debug

```bash
g++ src/*.cpp -lpcap -g -o bin/SimulatorPIA_debug
```

### Release

```bash
g++ src/*.cpp -lpcap -o bin/SimulatorPIA_release
strip bin/SimulatorPIA_release
```

## Ejecución

```bash
sudo ./bin/SimulatorPIA_debug
```

## Resultados observados

Durante la ejecución el sistema mostró:

- lectura correcta de archivos
- generación de hash simulado
- enumeración de procesos activos
- captura de tráfico ICMP real

También se verificó el funcionamiento del sniffer realizando tráfico ping dentro de la máquina virtual.

---

# Hallazgos iniciales del análisis

Se realizó análisis estático preliminar usando:

- strings
- rabin2
- análisis ELF

## Hallazgos relevantes

Se identificaron referencias a:

- libpcap
- pcap_loop
- pcap_open_live
- símbolos debug
- secciones ELF (.text, .data, .bss)

La versión debug contiene información útil para reversing debido a la presencia de símbolos y secciones de depuración.

La versión release elimina parcialmente esta información usando strip.

---

# Riesgos y mitigaciones

## Riesgos identificados

Aunque el proyecto es educativo, algunas técnicas implementadas podrían parecer similares a comportamientos observados en malware real, especialmente:

- sniffing de tráfico
- análisis de procesos
- monitoreo del sistema

## Mitigaciones aplicadas

Para reducir riesgos:

- el proyecto se ejecuta únicamente en máquinas virtuales
- no existe persistencia
- no hay comunicación externa
- no se modifican archivos críticos del sistema
- no se realizan acciones ofensivas reales

El objetivo del proyecto es exclusivamente académico y defensivo.

---

# Trabajo pendiente

Para el siguiente avance se planea implementar:

- detección básica de debugging
- mejora del módulo de hashing
- captura de protocolos adicionales
- mayor documentación técnica
- pruebas adicionales de reversing y análisis dinámico

También se planea integrar más herramientas de análisis defensivo para fortalecer la capacidad educativa del proyecto.
