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

    new = malloc(sizeof(listint_t));
    if (!new)
        return (NULL);

    new->n = number;

    if (!*head) {
        *head = new;
        return (*head);
    }

    current = *head;

    while (current)
    {
        if (current->n > new->n)
        {
           new->next = current;
           *head = new;
           return (new);

        }
        else if (new->n == current->n)
        {
            new->next = current->next;
            current->next = new;
            return (new);
        }
        else if (current->n < new->n && current->next == NULL)
        {
            current->next = new;
            return (new);
        }
        else if (current->n < new->n && current->next->n > new->n)
        {
            new->next = current->next;
            current->next = new;
            return (new);
        }

        current = current->next;

    }
    return (NULL);
}
