#include <pcap.h>
#include <iostream>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include "packet_sniffer.h"

void packetHandler(u_char *args,
                   const struct pcap_pkthdr *header,
                   const u_char *packet)
{
    struct ip *ipHeader = (struct ip*)(packet + 14);

    if(ipHeader->ip_p == IPPROTO_ICMP)
    {
        std::cout << "[ICMP detectado] Tamaño: "
                  << header->len
                  << " bytes\n";
    }
}

void startSniffer()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *interfaces;

    if(pcap_findalldevs(&interfaces, errbuf) == -1)
    {
        std::cerr << "Error encontrando interfaces: "
                  << errbuf << std::endl;
        return;
    }

    pcap_t *handle = pcap_open_live(
        interfaces->name,
        BUFSIZ,
        1,
        1000,
        errbuf
    );

    if(handle == nullptr)
    {
        std::cerr << "No se pudo abrir interfaz\n";
        return;
    }

    std::cout << "[Sniffer activo en interfaz: "
              << interfaces->name
              << "]\n";

    pcap_loop(handle, 10, packetHandler, nullptr);

    pcap_close(handle);
}
