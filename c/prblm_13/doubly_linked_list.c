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
  list->length++;

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
  list->length++;

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

    for (int i = 0; i < list->length && list->pntr->indice != indice; i++) {

      dl_list_next(list);

    }


  } else { //Else it's shorter to go backwards

    for (int i = 0; i < list->length && list->pntr->indice != indice; i++) {

      dl_list_prev(list);

    }

  }

  if (list->pntr->indice != indice) {

    printf("\nError failed to locate requested indice: %i in list\nFile: %s, Line: %i\n", indice, __FILE__, __LINE__);

  }

  return;

}

int dl_list_get_val_at_indice(struct dLinkedList * list, int indice) {

  dl_list_move_pntr_to_indice(list, indice);
  return dl_list_get_val(list); 

}

void dl_list_print(struct dLinkedList * list) {

  list->pntr = list->head;

  for (int i = 0; i < list->length; i++) {

    printf("%i:%i\t", list->pntr->indice, dl_list_get_val_at_indice(list, i));
    if ((i + 1) % 10 == 0) {

      printf("\n");

    }

  }

  printf("\n");

  return;

}

void dl_list_mov_item_to_indice(struct dLinkedList * list, int item,  int indice) {

  if (item == indice) {
    printf("Error: Item is equal to Indice\nFile: %s, Line: %i\n", __FILE__, __LINE__);
    return;
  }

  dl_list_move_pntr_to_indice(list, item);
  struct listItem * moved_item = list->pntr;
  struct listItem * moved_next_item = list->pntr->next;
  struct listItem * moved_prev_item = list->pntr->prev;
  int moved_item_indice = moved_item->indice;

  dl_list_move_pntr_to_indice(list, indice);
  struct listItem * original_item = list->pntr;
  struct listItem * original_next_item = list->pntr->next;
  struct listItem * original_prev_item = list->pntr->prev;
  int original_item_indice = original_item->indice;

  original_item->prev->next = moved_item;
  original_item->prev = moved_item->prev;
  
  moved_item->next->prev = original_item;
  moved_item->prev->next = original_item;
  moved_item->prev = original_prev_item;
  moved_item->next = original_next_item;
  moved_item->indice = original_item->indice;

  if (item == list->head->indice) {
    list->head = moved_prev_item;
  } else if (item == list->tail->indice) {
    list->tail = moved_next_item;
  }

  if (item < indice) {

    list->pntr = moved_next_item;

    for (int i = list->pntr->indice; i < indice + 2; i++) {

      list->pntr->indice--;
      dl_list_next(list);

    }

  } else {

    list->pntr = original_next_item;
    
    for (int i = list->pntr->indice; i < item; i++) {

      list->pntr->indice++;

      dl_list_next(list);

    }

  }

  return;

}



