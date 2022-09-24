#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "doubly_linked_list.h"

void dl_list_init(struct dLinkedList * list) {

  struct listItem * frstItem = malloc(sizeof(struct listItem));

  frstItem->val = 0;
  frstItem->indice = 0;

  list->head = frstItem;
  list->tail = frstItem;
  list->pntr = frstItem;

  return;

}

void dl_list_append(struct dLinkedList * list, int val) {

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

void dl_list_next(struct dLinkedList * list) {

  list->pntr = list->pntr->next;
    
  return;

}

void dl_list_prev(struct dLinkedList * list) {

  list->pntr = list->pntr->prev;

  return;

}

int dl_list_get_val(struct dLinkedList * list) {

  return list->pntr->val; 

}

void dl_list_set_val(struct dLinkedList * list, int val) {

  list->pntr->val = val;

}

int dl_list_get_indice(struct dLinkedList * list) {

  return list->pntr->indice;

}

void dl_list_move_pntr_to_indice(struct dLinkedList * list, int indice) {

  if (abs(indice - list->pntr->indice) < abs(list->pntr->indice + (list->tail->indice - indice))) { //If it's shorter to go forwards

    while (list->pntr->indice != indice) {

      dl_list_next(list);

    }


  } else { //Else it's shorter to go backwards

    while (list->pntr->indice != indice) {

      dl_list_prev(list);

    }

  }

}

int dl_list_get_val_at_indice(struct dLinkedList * list, int indice) {

  dl_list_move_pntr_to_indice(list, indice);
  return dl_list_get_val(list); 

}

void dl_list_print(struct dLinkedList * list) {

  for (int i = 0; i < list->tail->indice + 1; i++) {

    printf("%i\t", dl_list_get_val_at_indice(list, i));

    if (i % 10 == 0) {

      printf("\n");

    }

  }

  printf("\n");

  return;

}

void dl_list_mov_item_to_indice(struct dLinkedList * list, int item,  int indice) {

  dl_list_move_pntr_to_indice(list, item);
  struct listItem * moved_item = list->pntr;

  dl_list_move_pntr_to_indice(list, indice);
  struct listItem * original_item = list->pntr;

  original_item->prev = moved_item;
  original_item->indice += 1;

  list->pntr->prev->next = moved_item;
  moved_item->indice = indice;

  return;

}



