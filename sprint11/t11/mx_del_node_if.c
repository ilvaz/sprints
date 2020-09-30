#include "list.h"

void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)) {
    t_list *node = *list;
    t_list *pre_node = node;
    while (node != NULL) {
        if(cmp(del_data, node->data)) {
            if (node == *list) {
                *list = node->next; 
            } else {
                pre_node->next = node->next;  
            }
            free(node);
        }
        pre_node = node;
        node = node->next;
    }
}
