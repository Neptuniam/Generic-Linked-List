#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"

linkedList* initList() {
	linkedList *list = malloc(sizeof(linkedList));
	list->head = malloc(sizeof(node));
	list->tail = malloc(sizeof(node));

	list->length = 0;
	list->head->data = list->tail->data = NULL;

	return list;
}

int getIndex(linkedList *list, void *toFind) {
	node *temp = list->head;
	int index = 1;

	while (temp) {
		if (index > list->length)
			return -1;
		else if (temp->data == toFind)
			return index;
		else {
			temp = temp->next;
			index++;
		}
	}


	return -1;
}

node* makeNode(void *element) {
	node* newNode = malloc(sizeof(node));

	if (newNode == NULL) {
		printf("Malloc failed!\n");
		return NULL;
	}

	newNode->data = element;
	newNode->next = NULL;

	return newNode;
}

void addToFront(linkedList *list, void *element) {
	node* newNode = makeNode(element);

	if (list->length == 0)
		list->head = list->tail = newNode;
	else {
		newNode->next = list->head;
		list->head = newNode;
		list->tail->next = NULL;
	}

	list->length++;
}

void addToBack(linkedList *list, void *element) {
	node* newNode = makeNode(element);

	if (list->length == 0)
		list->head = list->tail = newNode;
	else {
		list->tail->next = newNode;
		list->tail = newNode;
	}
	
	list->length++;
}

node* deleteCur(node *toDel) {
	node *toFree = toDel;
	toDel = toDel->next;
	free(toFree->data);
	free(toFree);

	return toDel;
}

void deleteNode(linkedList *list, node *toRemove) {
	node *toDel = malloc(sizeof(node));
	toDel->data = toRemove;

	if (list->head->data == toDel->data)
		list->head = deleteCur(list->head);
	else {
		node *first = list->head;
		node *second = first->next;

		while (second) {
			if (second->data == toDel->data) {
				first->next = deleteCur(second);
				break;
			}

			first = first->next;
			second = second->next;
		}
	}

	list->length--;
}

void destroyList(linkedList *list)
{
	while (list->head != NULL) {
		list->head = deleteCur(list->head);
		list->length--;
	}
}