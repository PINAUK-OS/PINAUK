#include <stdint.h>

// Root System Description Pointer (ACPI 2.0+)
typedef struct {
    char Signature[8];
    uint8_t Checksum;
    char OEMID[6];
    uint8_t Revision;
    uint32_t RsdtAddress;        // Only for ACPI 1.0
    uint64_t XsdtAddress;        // ACPI 2.0
    uint8_t ExtendedChecksum;
    uint8_t Reserved[3];
} __attribute__((packed)) RSDPDescriptor20;

// System Descriptor Header
typedef struct {
    char Signature[4];
    uint32_t Length;
    uint8_t Revision;
    uint8_t Checksum;
    char OEMID[6];
    char OEMTableID[8];
    uint32_t OEMRevision;
    uint32_t CreatorID;
    uint32_t CreatorRevision;
} __attribute__((packed)) ACPISDTHeader;

// XSDT Table
typedef struct {
    ACPISDTHeader Header;
    uint64_t Entries[];  // Pointers to other tables
} __attribute__((packed)) XSDT;

// FADT (Fixed ACPI Description Table)
typedef struct {
    ACPISDTHeader Header;
    uint8_t Reserved1[76 - sizeof(ACPISDTHeader)];
    uint32_t PM1a_CNT_BLK;
    uint8_t Reserved2[256 - 80];  // Skip rest
} __attribute__((packed)) FADT;
