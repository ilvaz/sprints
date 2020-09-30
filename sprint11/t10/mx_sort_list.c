#include "list.h"

void mx_swap(t_list *n1, t_list *n2) {
    void *tmp = n1->data;
    n1->data = n2->data;
    n2->data = tmp;
}

int mx_list_size(t_list *list) {
    int size = 0;
    while (list != NULL) {
        list = list->next;
        size++;
    }
    return size;
}

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    int size = mx_list_size(list);
    for (int i = 0; i < size; i++) {
        t_list *tmp = list;
        for (int j = 0; j < size - i - 1; j++) {
            if (cmp(tmp->data, tmp->next->data)) {
                mx_swap(tmp, tmp->next);
            }
            tmp = tmp->next;
        }
    }
    return list;
}
