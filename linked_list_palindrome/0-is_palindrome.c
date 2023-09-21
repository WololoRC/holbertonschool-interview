#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to a pointer to the head of the list
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow_ptr = *head, *fast_ptr = *head;
    listint_t *prev_slow_ptr = NULL;
    listint_t *second_half = NULL;
    int is_palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        prev_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    if (fast_ptr != NULL)
    {
        // Odd number of elements, skip the middle element.
        slow_ptr = slow_ptr->next;
    }

    second_half = slow_ptr;
    prev_slow_ptr->next = NULL;

    // Reverse the second half of the list.
    second_half = reverse_listint(&second_half);

    while (*head != NULL && second_half != NULL)
    {
        if ((*head)->n != second_half->n)
        {
            is_palindrome = 0;
            break;
        }
        *head = (*head)->next;
        second_half = second_half->next;
    }

    // Restore the original list.
    second_half = reverse_listint(&second_half);
    prev_slow_ptr->next = second_half;

    return (is_palindrome);
}

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to a pointer to the head of the list
 *
 * Return: pointer to the new head of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return (*head);
}

