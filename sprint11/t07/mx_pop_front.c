#include "list.h"

void mx_pop_front(t_list **list) {
    t_list *node = *list;
    t_list *next_node = node->next;
    *list = next_node;
    free(node);
}
