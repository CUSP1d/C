// Шаблон для задания 4.1.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "string_list.h"
#include "sort_string_list.h"






int main() {
    srand((unsigned)time(NULL));
    SaveHeadTail* save = (SaveHeadTail*)malloc(sizeof(SaveHeadTail));
    StringListEntry* stringList;

    GenerateRandomStringList(&stringList, COUNT_STRING);
    PrintStringList(stringList);
    save->head = &(stringList->listEntry);
    save->tail = SearchTail(&(stringList->listEntry));
    ListEntry* head = &(stringList->listEntry);
    ListEntry* tail = SearchTail(head);
    SortStringList(save,head,tail);
    printf("--------------------------------------------------------\n");
    PrintStringList(GET_CONTENT_RECORD(StringListEntry, listEntry, save->head));

  
    //FreeList





   /* StringListEntry tmpStringListEntry;
    ListEntry* entry = &tmpStringListEntry.listEntry;
    printf("entry: %p\n", entry);
    printf("start string list: %p\n", GET_CONTENT_RECORD(StringListEntry, listEntry, entry));
    return 0;*/
    

    return 0;
}
