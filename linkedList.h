#ifndef LinkedList
#define LinkedList

typedef struct nodeType {
	void *data;
	struct nodeType *next;
}node;

typedef struct linkedListType {
	int length;
	node *head;
	node *tail;
}linkedList;

linkedList* initList();
node* makeNode(void *element);
int getIndex(linkedList *list, void *toFind);
void addToFront(linkedList *list, void *element);
void addToBack(linkedList *list, void *element);
node* deleteCur(node *toDel);
void deleteNode(linkedList *list, node *toRemove);
void destroyList(linkedList *list);

#endif 