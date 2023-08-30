#include "binary_trees.h"

/**
 * binary_tree_node - Insert a on a binary tree.
 *
 *@parent: parent node
 *@value: value of new node
 * Return: new node on succes, else NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new = malloc(sizeof(binary_tree_t));
    if (!new)
        return (NULL);

    new->parent = NULL;
    new->left = NULL;
    new->right = NULL;

    new->n = value;

    if (!parent)
    {
        return (new);
    }

    if (!parent->left)
    {
        parent->left = new;
        new->parent = parent;
        return (new);
    }

    parent->right = new;
    new->parent = parent;

    return (new);
}
