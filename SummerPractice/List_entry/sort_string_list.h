
#ifndef _SORT_STRING_LIST_
#define _SORT_STRING_LIST_

#include "string_list.h"


#define OFFSET_OF(TypeName, entryName)  \
    (unsigned char*)&((TypeName*)0)->entryName

#define GET_CONTENT_RECORD(TypeName, entryName, addr)    \
    ((TypeName*)((unsigned char*)addr - OFFSET_OF(TypeName, entryName)))

typedef struct {
    ListEntry* head;
    ListEntry* pivot;
    ListEntry* tail;
}SaveHeadTail;

//ListEntry* SortStringList(StringListEntry*);

ListEntry* QSortGlav(ListEntry*);

ListEntry* myqsort(ListEntry*, ListEntry*);

ListEntry* PartList(ListEntry*, ListEntry*, SaveHeadTail*);

void SortStringList(SaveHeadTail**,ListEntry*,ListEntry*);

ListEntry* SearchListElem(StringListEntry*, int);


#endif  //_SORT_STRING_LIST_

