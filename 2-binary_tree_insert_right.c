#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts node as the right-child of another node
 *
 * @parent: is a pointer to the node to insert the right-child in
 * @value:  is the value to store in the new node
 *
 * Description - If parent already has a right-child, the new node must
 *				take its place, and the old right-child must be set as
 *				the left-child of the new node.
 *
 * Return: a pointer to the created node, or NULL on failure or if
 *			parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *new_node;

/* If parent is NULL, return NULL */
if (!parent)
return (NULL);

/* Allocate memory for new node */
new_node = malloc(sizeof(binary_tree_t));
if (!new_node)
return (NULL);

/* Initialize new node */
new_node->n = value;
new_node->parent = parent;
new_node->left = NULL;

if (parent->right)
{
new_node->right = parent->right;
new_node->right->parent = new_node;
}
else
{
new_node->right = NULL;
}

/* Set parent's right-child to new node */
parent->right = new_node;

/* Return new node */
return (new_node);
}
