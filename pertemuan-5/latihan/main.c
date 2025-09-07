// Circular Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int nilai;
    struct node *next;
}node_t;

node_t *create_node(int nilai);
void add_edge_tail(node_t **head, node_t *new_node);
void delete_edge_tail(node_t **head);
void print_node(node_t *head);

int main(void){
    node_t *head = NULL, *temp = NULL;
    
    for (int i = 0; i < 10; i++)
    {
        temp = create_node(i);
        add_edge_tail(&head, temp);
    }
    
    print_node(head);

    delete_edge_tail(&head);

    printf("\n");
    print_node(head);
}

node_t *create_node(int nilai){
    node_t *new_node = malloc(sizeof(node_t));
    new_node->nilai = nilai;
    new_node->next = NULL;

    return new_node;
}

void add_edge_tail(node_t **head, node_t *new_node){
    if (*head == NULL)
    {
        *head = new_node;
        new_node->next = *head;
        return;
    }
    
    node_t *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = *head;
    return;
}

void delete_edge_tail(node_t **head){
    node_t *temp = *head;
    if (temp->next == *head)
    {
        free(temp);
        return;
    }
    
    while (temp->next->next != *head)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = *head;
    return;
}

void print_node(node_t *head){
    node_t *temp = head;
    do
    {
        printf(" %d", temp->nilai);
        temp = temp->next;
    } while (temp != head);
    return;
}