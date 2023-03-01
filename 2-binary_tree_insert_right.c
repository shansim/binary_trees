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

binary_tree_t *new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

if (parent == NULL)
return (NULL);

if (new_node == NULL)
return (NULL);

new_node->n = value;
new_node->parent = parent;
new_node->left = NULL;

if (parent->right != NULL)
{
new_node->right = parent->right;
parent->right->parent = new_node;
}
else
{
new_node->right = NULL;
}
parent->right = new_node;

return (new_node);
}
