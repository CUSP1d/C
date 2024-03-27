
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>


#include "string_list.h"
#include "list.h"
#include "sort_string_list.h"


StringListEntry* CreateAndInitNewStringListEntry(char* str, int index) {

    StringListEntry* entry = (StringListEntry*)malloc(sizeof(StringListEntry));

    if (entry == NULL) {
        return NULL;
    }

    int len = strlen(str) + 1;

    entry->value = (char*)malloc(len * sizeof(char));

    InitList(&entry->listEntry);

    strcpy_s(entry->value, len, str); 
    entry->index = index;

    return entry;
}



void FreeStringListEntry(StringListEntry* entry) {

    free(entry->value);
    free(entry);

    return;
}



void AddStringTailStringList(StringListEntry* stringList, char* str, int index) {
    
    StringListEntry* Tmp = CreateAndInitNewStringListEntry(str, index);

    InsertTailList(&stringList->listEntry, &Tmp->listEntry);

    return;
}



void FreeStringList(StringListEntry* stringList) {


}


void GenerateRandomStringList(StringListEntry** StringList,unsigned int size) {

    const char Alph[] = "abcdefghijklmnopqrstuvwxyz";

    StringListEntry* Tmp = (StringListEntry*)malloc(sizeof(StringListEntry));
    int CountStr = 0;

    while (CountStr < size) {
        int LenStr = rand() % MAX_SIZE_STRING + 1;
        char* Str = (char*)malloc((LenStr + 1) * sizeof(char));
        for (int i = 0; i < LenStr; ++i) {
            Str[i] = Alph[rand() % strlen(Alph)];
        }
        Str[LenStr] = '\0';
        if (CountStr == 0) Tmp = CreateAndInitNewStringListEntry(Str,CountStr, CountStr);
        else AddStringTailStringList(Tmp, Str, CountStr);
        CountStr++;
    }
    *StringList = Tmp;
    return;
}

void PrintStringList(StringListEntry* stringList) {
    StringListEntry* head = stringList;
    StringListEntry* tmp;
    ListEntry* current = &(stringList->listEntry);
    while (current->next != NULL) {
        tmp = GET_CONTENT_RECORD(StringListEntry, listEntry, current);
        printf("%s - %d\n", tmp->value, tmp->index);
        current = GetNextEntry(current);
    }
    tmp = GET_CONTENT_RECORD(StringListEntry, listEntry, current);
    printf("%s - %d\n", tmp->value, tmp->index);
}