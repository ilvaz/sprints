#include "list.h"

void mx_clear_list(t_list **list) {
    t_list *node = *list;
    t_list *pre_node;
    while (node != NULL) {
        pre_node = node;
        node = node->next;
        free(pre_node);
    }
}
