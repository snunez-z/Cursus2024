#ifndef LIST_H
 #define LIST_H

#include <stddef.h>

typedef struct s_list
{
    void	*data;
    struct s_list	*next;
}	list_t;

list_t*	list_append(list_t *list, void *data, void (*free_data)(void*));
void	list_destroy(list_t *list, void (*free_data)(void*));
size_t	list_size(list_t *list);
void	*list_get(list_t *list, size_t pos);

#endif