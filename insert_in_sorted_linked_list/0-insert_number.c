#include "lists.h"
/**
 * insert_node - insert a node inside a sorted linked list
 *
 * @head: ptr to head list
 * @number: n fot new node
 * Return: new inserted node on success, NULL if fails.
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (!new)
        return (NULL);

    new->n = number;

    while (current)
    {
        if (current->n < new->n && current->next->n > new->n) {
            new->next = current->next;
            current->next = new;
            return (new);
        } else {
            current = current->next;
        }

    }

    return (NULL);
}
