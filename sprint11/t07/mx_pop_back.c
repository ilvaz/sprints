#include "list.h"

void mx_pop_back(t_list **list) {
    t_list *node = *list;
    t_list *pre_node;
    while (node->next != NULL) {
        pre_node = node;
        node = node->next;
    }
    free(node);
    pre_node->next = NULL;
}
