#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

typedef struct Data {
	char *name;
	int age;
} data;

int main() {
	linkedList *list = initList();
	data *user1 = malloc(sizeof(data));
	data *user2 = malloc(sizeof(data));

	user1->name = "Liam";
	user1->age = 19;
	user2->name = "Max";
	user2->age = 15;

	addToFront(list, user1);
	addToFront(list, user2);

	printf("T: %d\n", getIndex(list, user1));

	//deleteNode(list, list->head);
	//destroyList(list);

	getchar();
	return 0;
}