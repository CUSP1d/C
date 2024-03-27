#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "sort_string_list.h"
#include "string_list.h"

static ListEntry* Head = 0;

void SortStringList(SaveHeadTail* Save, ListEntry* head, ListEntry* end){
    ListEntry* pivot = head;
    SaveHeadTail save_tmp = { 0,0,0 };
    save_tmp.tail = end;
    int index1 = GET_CONTENT_RECORD(StringListEntry, listEntry, head)->index;
    int index2 = GET_CONTENT_RECORD(StringListEntry, listEntry, end)->index;
    char* tmp10 = GET_CONTENT_RECORD(StringListEntry, listEntry, Save->head)->value;
    char* tmp1 = GET_CONTENT_RECORD(StringListEntry, listEntry, pivot)->value;
    char* tmp5 = GET_CONTENT_RECORD(StringListEntry, listEntry, Save->head)->value;
    ListEntry* i = head->next;
    char* tmp2 = GET_CONTENT_RECORD(StringListEntry, listEntry, i)->value;
    ListEntry* j = end;
    char* tmp3 = GET_CONTENT_RECORD(StringListEntry, listEntry, j)->value;
    while (GET_CONTENT_RECORD(StringListEntry, listEntry, i)->index < GET_CONTENT_RECORD(StringListEntry, listEntry, j)->index) 
    {
        while((strlen(GET_CONTENT_RECORD(StringListEntry, listEntry, i)->value) < strlen(GET_CONTENT_RECORD(StringListEntry, listEntry, pivot)->value)) && GET_CONTENT_RECORD(StringListEntry, listEntry, i)->index < GET_CONTENT_RECORD(StringListEntry, listEntry, j)->index)
        {
            i = GetNextEntry(i);
            tmp2 = GET_CONTENT_RECORD(StringListEntry, listEntry, i)->value;
        }
        while ((strlen(GET_CONTENT_RECORD(StringListEntry, listEntry, j)->value) >= strlen(GET_CONTENT_RECORD(StringListEntry, listEntry, pivot)->value)) && GET_CONTENT_RECORD(StringListEntry, listEntry, i)->index <= GET_CONTENT_RECORD(StringListEntry, listEntry, j)->index)
        {
            j = GetPrevEntry(j);
            tmp3 = GET_CONTENT_RECORD(StringListEntry, listEntry, j)->value;
        }
        if (GET_CONTENT_RECORD(StringListEntry, listEntry, i)->index < GET_CONTENT_RECORD(StringListEntry, listEntry, j)->index) 
        {
            ListEntry* next = i->next;
            ListEntry* prev = j->prev;
            Save->head = SwapNodes(i, j, Save->head);
            if (save_tmp.tail == j) {
                save_tmp.tail = i;
            }
            i = next;
            j = prev;
            printf("-------------------------------------------------------------------\n");
            PrintStringList(GET_CONTENT_RECORD(StringListEntry, listEntry, Save->head));
            printf("-------------------------------------------------------------------\n");
        }
    }
    if (strlen(GET_CONTENT_RECORD(StringListEntry, listEntry, j)->value) > strlen(GET_CONTENT_RECORD(StringListEntry, listEntry, pivot)->value)) {
    }
    else {
        Save->head = SwapNodes(pivot, j, Save->head);
        if (save_tmp.tail == j) {
            save_tmp.tail = pivot;
        }
    }
    PrintStringList(GET_CONTENT_RECORD(StringListEntry, listEntry, Save->head));
    if (index1 < GET_CONTENT_RECORD(StringListEntry, listEntry, pivot)->index) {
        SortStringList(Save, j, GetPrevEntry(pivot));
    }
    if (index2 > GET_CONTENT_RECORD(StringListEntry, listEntry, pivot)->index) {
        SortStringList(Save, GetNextEntry(pivot), save_tmp.tail);
    }
}