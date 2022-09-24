#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct listItem listItem;

struct listItem {
  int val;
  int indice;
  listItem * next;
  listItem * prev;
};

struct dLinkedList {
  listItem * head;
  listItem * tail;
  listItem * pntr;
};

void dl_list_init(struct dLinkedList * list);

void dl_list_append(struct dLinkedList * list, int val);

void dl_list_next(struct dLinkedList * list);

void dl_list_prev(struct dLinkedList * list);

int dl_list_get_val(struct dLinkedList * list);

void dl_list_set_val(struct dLinkedList * list, int val);

int dl_list_get_indice(struct dLinkedList * list);

void dl_list_move_pntr_to_indice(struct dLinkedList * list, int indice);

int dl_list_get_val_at_indice(struct dLinkedList * list, int indice);

void dl_list_print(struct dLinkedList * list);

void dl_list_mov_item_to_indice(struct dLinkedList * list, int item, int indice);

#endif
