#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

entry *findName(char lastname[], entry *table[])
{
    unsigned nHash = hash(lastname);
    entry *pHead = table[nHash];
    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

void append(char lastName[], entry *table[])
{
    unsigned nHash = hash(lastName);
    entry *e = (entry *) malloc(sizeof(entry));
    e -> pNext = table[nHash];
    if(!table[nHash]) {
        table[nHash] = e;
    } else {
        table[nHash] -> pNext = e;
    }
    strcpy(e -> lastName, lastName);
}

unsigned hash(char name[])
{
    unsigned sum;
    int i;
    for (sum = 1, i = 0; i < 16 && name[i] > 0; i++) {
        sum = sum * name[i] - i * name [i];
    }
    return sum % MOD;
}

void initTable(entry *table[])
{
    for(int i = 0; i < MOD; i++) {
        table[i]=NULL;
    }
}
