#include "sort.h"

/**
 * _swap - swaps two nodes of doubly linked list
 *
 * @node: node base to change
 * @list: double link list head
 *
 * Return: No return
 */

 void _swap(listint_t **node, listint_t **list)
 {
     listint_t *temp = *node, *temp2, *temp3;

     if (!(*node)->prev)
         *list = (*node)->next;

     temp = temp3 = *node;
     temp2 = temp->next;

     temp->next = temp2->next;
     temp3 = temp->prev;
     temp->prev = temp2;
     temp2->next = temp;
     temp2->prev = temp3;

     if (temp2->prev)
         temp2->prev->next = temp2;

     if (temp->next)
         temp->next->prev = temp;

     *node = temp2;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 *
 * @list: doubly linked list
 *
 * Return: No return
 */

 void insertion_sort_list(listint_t **list)
 {
     listint_t *head, *tback, *aux;

     if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
         return;

     head = *list;
     while (head && head->next)
     {
         if (head->n > head->next->n)
         {
             aux = head;

             _swap(&aux, list);
             print_list(*list);
             head = aux;
             tback = aux;

             while (tback && tback->prev)
             {
                 if (tback->n < tback->prev->n)
                 {
                     aux = tback->prev;

                     _swap(&(aux), list);

                     print_list(*list);
                     tback = aux->next;
                 }

                 tback = tback->prev;
             }
         }
         head = head->next;
     }
 }
