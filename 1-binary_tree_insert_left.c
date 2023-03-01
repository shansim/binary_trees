#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 *
 * @parent: is a pointer to the node to insert the left-child in
 * @value:  is the value to store in the new node
 *
 * Description - If parent already has a left-child, the new node must
 *				take its place, and the old left-child must be set as
 *				the left-child of the new node.
 *
 * Return: a pointer to the created node, or NULL on failure or if
 *			parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{

binary_tree_t *new_node = NULL;

if (parent == NULL)
return (NULL);

new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

if (new_node == NULL)
return (NULL);

new_node->n = value;
new_node->parent = parent;
new_node->right = NULL;

if (parent->left != NULL)
{
new_node->left = parent->left;
parent->left->parent = new_node;
}
else
{
new_node->left = NULL;
}
parent->left = new_node;
return (new_node);
}
