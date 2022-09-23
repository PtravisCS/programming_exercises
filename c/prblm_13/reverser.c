#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void initalize_dl_list(struct dLinkedList * list) {

  struct listItem * frstItem = malloc(sizeof(struct listItem));

  frstItem->val = 0;
  frstItem->indice = 0;

  list->head = frstItem;
  list->tail = frstItem;
  list->pntr = frstItem;

  return;

}

void append_list_item(struct dLinkedList * list, int val) {

  struct listItem * nxtItem = malloc(sizeof(struct listItem));

  nxtItem->val = val;
  nxtItem->indice = list->tail->indice + 1;
  nxtItem->prev = list->tail;
  nxtItem->next = list->head;

  list->tail->next = nxtItem; 
  list->head->prev = nxtItem;
  list->tail = nxtItem;

  return;

}

void advance_dl_list(struct dLinkedList * list) {

  list->pntr = list->pntr->next;
    
  return;

}

void retreat_dl_list(struct dLinkedList * list) {

  list->pntr = list->pntr->prev;

  return;

}

int get_pntr_indice_val(struct dLinkedList * list) {

  return list->pntr->val; 

}

void set_pntr_indice_val(struct dLinkedList * list, int val) {

  list->pntr->val = val;

}

int get_pntr_indice(struct dLinkedList * list) {

  return list->pntr->indice;

}

void move_dl_list_pntr_to_indice(struct dLinkedList * list, int indice) {

  if (abs(indice - list->pntr->indice) < abs(list->pntr->indice + (list->tail->indice - indice))) { //If it's shorter to go forwards

    while (list->pntr->indice != indice) {

      advance_dl_list(list);

    }


  } else { //Else it's shorter to go backwards

    while (list->pntr->indice != indice) {

      retreat_dl_list(list);

    }

  }

}

int get_val_at_dl_list_indice(struct dLinkedList * list, int indice) {

  move_dl_list_pntr_to_indice(list, indice);
  return get_pntr_indice_val(list);

}

void print_dl_linked_list(struct dLinkedList * list) {

  for (int i = 0; i < list->tail->indice + 1; i++) {

    printf("%i\t", get_val_at_dl_list_indice(list, i));

    if (i % 10 == 0) {

      printf("\n");

    }

  }

  printf("\n");

  return;

}

void mov_dl_list_item_to_indice(struct dLinkedList * list) {

  

}

int main() {

  static struct dLinkedList list;

  initalize_dl_list(&list);

  for (int i = 1; i < 101; i++) {

    append_list_item(&list, i * 10);

  }

  print_dl_linked_list(&list);

  return 0;

}
