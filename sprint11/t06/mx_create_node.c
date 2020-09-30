#include "list.h"

t_list *mx_create_node(void *data) {
    t_list *node = malloc(0);
    node->data = data;
    node->next = NULL;
    return node;
}
