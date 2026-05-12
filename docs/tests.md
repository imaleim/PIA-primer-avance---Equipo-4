# Pruebas técnicas — SimulatorPIA

## Compilación del proyecto

### Versión debug (con símbolos)

```bash
g++ src/*.cpp -lpcap -g -o bin/SimulatorPIA_debug
```

### Versión release (sin símbolos)

```bash
g++ src/*.cpp -lpcap -o bin/SimulatorPIA_release
strip bin/SimulatorPIA_release
```

---

## Ejecución del proyecto

```bash
sudo ./bin/SimulatorPIA_debug
```

---

## Salida observada

```text
[SimulatorPIA iniciado]
Proyecto PIA funcionando correctamente

[HASH SIMULADO]
Archivo: test.txt
Hash: 3c5224f2ea8e2c7e

[Procesos activos]
PID: 1
PID: 2
PID: 3
...

[Sniffer activo en interfaz: ens33]
[ICMP detectado] Tamaño: 98 bytes
```

---

## Análisis estático realizado

### Extracción de strings

```bash
strings bin/SimulatorPIA_debug > analysis/strings.txt
```

### Revisión de imports

```bash
rabin2 -i bin/SimulatorPIA_debug > analysis/imports.txt
```

### Revisión de secciones ELF

```bash
rabin2 -S bin/SimulatorPIA_debug > analysis/sections.txt
```

---

## Resultados observados

Se identificaron referencias relacionadas con:

- libpcap
- pcap_loop
- pcap_open_live
- secciones ELF (.text, .data, .bss)
- símbolos debug

---

## Referencias a evidencias

Las capturas utilizadas durante las pruebas se encuentran en:

- evidence/execution1.png
- evidence/execution2.png
- evidence/static_analysis.png
- evidence/network_activity.png
