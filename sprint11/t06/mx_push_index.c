#include "list.h"

int mx_list_size(t_list **list) {
    int size = 0;
    t_list *node = *list;
    while (node != NULL) {
        node = node->next;
        size++;
    }
    return size;
}

void mx_push_index(t_list **list, void *data, int index) {
    if (index < 0) {
        mx_push_front(list, data);
        return;
    } else if (index > mx_list_size(list)) {
        mx_push_back(list, data);
    } else {
        t_list *node = *list;
        for (int i = 0; i < index - 1; i++) {
            node = node->next;
        }
        mx_push_front(&(node->next), data);
    }
}
