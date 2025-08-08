/**
 * swap_nodes - swap node with the next node in the list
 * @list: pointer to pointer of the head
 * @node1: node to swap with the next node
 *
 * Return: nothing
 */
void swap_nodes(listint_t **list, listint_t *node1) 
{
    listint_t *node2 = node1->next;
    listint_t *node1_prev = node1->prev;
    listint_t *node2_next = node2->next;

    /* Adjust pointers of surrounding nodes */
    if (node1_prev != NULL) {
        node1_prev->next = node2;
    } else {
        /* node1 was the head, so node2 becomes the new head */
        *list = node2;
    }

    if (node2_next != NULL) {
        node2_next->prev = node1;
    }

    /* Adjust pointers of node1 and node2 */
    node2->prev = node1_prev;
    node2->next = node1;
    node1->prev = node2;
    node1->next = node2_next;

}
