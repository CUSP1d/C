
#ifndef _STRING_LIST_H_
#define _STRING_LIST_H_

#define COUNT_STRING 7
#define MAX_SIZE_STRING 15




#include "list.h"

typedef struct _StringListEntry {

    int index;
    char* value;
    ListEntry listEntry;

} StringListEntry;

StringListEntry* CreateAndInitNewStringListEntry(char*, int);
void GenerateRandomStringList(StringListEntry**, unsigned int);
void AddStringTailStringList(StringListEntry*, char*, int);
void PrintStringList(StringListEntry*);

#endif  // _STRING_LIST_H_
