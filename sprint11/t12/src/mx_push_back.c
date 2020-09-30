#include "list.h"

void mx_push_back(t_list **list, void *data) {
    t_list *new_node = mx_create_node(data);
    t_list *node = *list; 
    if (node == NULL) {
        *list = new_node;
    } else {
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = new_node;
    }
    
}
