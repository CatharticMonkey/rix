#ifndef READFAT_H
#define READFAT_H

#include "file.h"

struct bpb
{
    char OEM_ID[8];
    unsigned short sectorSize;
    unsigned char sectorsPerCluster;
    unsigned short reservedSectors;
    unsigned char numberOfFATs;
    unsigned short rootEntries;
    unsigned short totalSectors;
    unsigned char media;
    unsigned short sectorsPerFAT;
    unsigned short sectorsPerTrack;
    unsigned short headsPerCylinder;
    unsigned int hiddenSectors;
    unsigned int totalSectorsBig;
    unsigned char driveNumber;
    unsigned char unused;
    unsigned char extBootSignature;
    unsigned int serialNumber;
    char label[11];
    char filesystem[8];

} __attribute__((packed));

typedef struct fileentry
{
    char shortname[11];
    unsigned char attributes;
    char reserved[10];
    unsigned short updatedtime;
    unsigned short updateddate;
    unsigned short startcluster;
    unsigned int sizebytes;

} __attribute__ ((packed)) fileentry_t;

FILE *readfiletoFILE(char *shortname);

unsigned char *readfile(char*);

unsigned char *readFAT(struct bpb*, unsigned int);

void readcluster(unsigned int, struct bpb*, unsigned char*);

fileentry_t *getinitialentry(char*, struct bpb*);

unsigned short nextcluster(unsigned short, unsigned char*);

#endif
