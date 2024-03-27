#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "string_list.h"
#include "sort_string_list.h"


// инициализация пустого списка
void InitList(ListEntry* head) {
	head->next = NULL;
	head->prev = NULL;
	return;
}


// добавление нового элемента в конец списка
void InsertTailList(ListEntry* head, ListEntry* newEntry) {
	if (head == NULL || newEntry == NULL) return;

	if (head->next == NULL) {
		newEntry->next = NULL;
		newEntry->prev = head;
		head->next = newEntry;
		return;
	}

	ListEntry* tmp = head->next;

	while (tmp->next != NULL) { 
		tmp = tmp->next; 
	}

	newEntry->next = NULL;
	newEntry->prev = tmp;
	tmp->next = newEntry;
	return;
}


// добавление нового элемента в начало списка
void InsertHead(ListEntry* head, ListEntry* newEntry) {

}



void RemoveEntry(ListEntry* entry) {

}


void FreeList(ListEntry* head) {

}


ListEntry* GetNextEntry(ListEntry* entry) {
	ListEntry* tmp = entry->next;
	return tmp;
}


ListEntry* GetPrevEntry(ListEntry* entry) {
	ListEntry* tmp = entry->prev;
	return tmp;
}


ListEntry* SwapNodes(ListEntry* L1, ListEntry* L2, ListEntry* head) {
	/*char* tmp1 = GET_CONTENT_RECORD(StringListEntry, listEntry, L1)->value;
	GET_CONTENT_RECORD(StringListEntry, listEntry, L1)->value = GET_CONTENT_RECORD(StringListEntry, listEntry, L2)->value;
	GET_CONTENT_RECORD(StringListEntry, listEntry, L2)->value = tmp1;*/
	
	
	if (L1 == L2) return head;
	int tmp1 = GET_CONTENT_RECORD(StringListEntry, listEntry, L1)->index;
	GET_CONTENT_RECORD(StringListEntry, listEntry, L1)->index = GET_CONTENT_RECORD(StringListEntry, listEntry, L2)->index;
	GET_CONTENT_RECORD(StringListEntry, listEntry, L2)->index = tmp1;
	ListEntry *prev1, *prev2, *next1, *next2;
	prev1 = L1->prev;
	prev2 = L2->prev;
	next1 = L1->next;
	next2 = L2->next;
	if (L2 == next1) {
		L2->next = L1;
		L2->prev = prev1;
		L1->next = next2;
		L1->prev = L2;
		if (next2 != NULL) next2->prev = L1;
		if (L1 != head) prev1->next = L2;
	}
	else if (L1 == next2) {
		L1->next = L2;
		L1->prev = prev2;
		L2->next = next1;
		L2->prev = L1;
		if (next1 != NULL) next1->prev = L2;
		if (L2 != head) prev2->next = L1;
	}
	else {
		if(L1 != head) prev1->next = L2;
		L2->next = next1;
		if (L2 != head) prev2->next = L1;
		L1->next = next2;
		L2->prev = prev1;
		if (next2 != NULL) next2->prev = L1;
		L1->prev = prev2;
		if (next1 != NULL) next1->prev = L2;
	}
	if (L1 == head) {
		return L2;
	}
	if (L2 == head) {
		return L1;
	}
	return head;
}
ListEntry* SearchListMid(ListEntry* l1, ListEntry* l2) {
	ListEntry* l1copy = l1;
	ListEntry* l2copy = l2;
	while (l1copy != l2copy && l1copy->next != l2copy) {
		l1copy = GetNextEntry(l1copy);
		l2copy = GetPrevEntry(l2copy);
	}
	return l1copy;
}

//void copyNodes(ListEntry* l1, ListEntry* l2) {
//	ListEntry* prev1, * prev2, * next1, * next2;
//	prev1 = l1->prev;
//	prev2 = l2->prev;
//	next1 = l1->next;
//	next2 = l2->next;
//
//}

ListEntry* SearchTail(ListEntry* head) {
	ListEntry* current = head;
	while (current->next != NULL) {
		current = GetNextEntry(current);
	}
	return current;
}