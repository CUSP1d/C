

#ifndef _LIST_H_
#define _LIST_H_

//#include "string_list.h"

typedef struct _ListEntry {
    struct _ListEntry* next;
    struct _ListEntry* prev;
} ListEntry;

ListEntry* SearchListMid(ListEntry*, ListEntry*);
ListEntry* GetNextEntry(ListEntry*);
void InitList(ListEntry*);
void InsertTailList(ListEntry*, ListEntry*);
ListEntry* GetNextEntry(ListEntry*);
ListEntry* GetPrevEntry(ListEntry*);
ListEntry* SwapNodes(ListEntry*, ListEntry*, ListEntry*);
ListEntry* SearchTail(ListEntry*);

#endif  // _LIST_H_
