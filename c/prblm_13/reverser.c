#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "doubly_linked_list.h"

int main() {

  static struct dLinkedList list;

  dl_list_init(&list);

  dl_list_set_val(&list, 10);

  for (int i = 2; i < 101; i++) {

    dl_list_append(&list, i * 10);

  }

  dl_list_mov_item_to_indice(&list, 9, 5);

  dl_list_print(&list);

  dl_list_mov_item_to_indice(&list, 5, 9);

  dl_list_print(&list);

  return 0;

}
