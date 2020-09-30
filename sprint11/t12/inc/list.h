#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>


typedef struct s_list
{
    void *data;
    struct s_list *next;
}              t_list;

int mx_strlen(const char *s);
void mx_printstr(char *s);
int mx_strcmp(const char *s1, const char *s2);

char *mx_file_to_str(const char *filename);

t_list *mx_create_node(void *data);
void mx_clear_list(t_list **list);
void mx_foreach_list(t_list *list, void (*f)(t_list *node));
int mx_list_size(t_list *list);
void mx_pop_back(t_list **list);
void mx_pop_front(t_list **list);
void mx_pop_index(t_list **list, int index);
void mx_push_back(t_list **list, void *data);
void mx_push_front(t_list **list, void *data);
void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b));
