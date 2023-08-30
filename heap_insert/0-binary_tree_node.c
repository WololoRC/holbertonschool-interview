#include "binary_trees.h"

/**
 * binary_tree_node - Insert a node on success else NULL
 *
 *@parent: parent node
 *@value: value of new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new = malloc(sizeof(binary_tree_t));
    if (!new)
        return (NULL);

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
