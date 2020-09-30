#include "list.h"

/*int mx_list_size(t_list **list) {
    int size = 0;
    t_list *node = *list;
    while (node != NULL) {
        node = node->next;
        size++;
    }
    return size;
}*/

void mx_pop_index(t_list **list, int index) {
    if (index < 0) {
        mx_pop_front(list);
        return;
    } else if (index > mx_list_size(*list)) {
        mx_pop_back(list);
    } else {
        t_list *node = *list;
        for (int i = 0; i < index - 1; i++) {
            node = node->next;
        }
        mx_pop_front(&(node->next));
    }
}
