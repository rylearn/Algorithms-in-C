//
// Created by Stanley Jacob on 9/10/18.
//
#include <stdlib.h>
#include <stdio.h>

struct node {
    int val;
    struct node* next;
    struct node* prev;
};

struct node* make_new_node(int val, struct node* next) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = next;
    return new_node;
}

void insert_begin(struct node* head, int val) {
    struct node* prev_head = head;
    struct node* new_node = make_new_node(val, prev_head);
    head = new_node;
}

void insert_end(struct node** head, int val) {
    if (*head == NULL) {
        *head = make_new_node(val, NULL);
        return;
    }
    struct node* curr_node = *head;
    while (curr_node->next != NULL) {
        curr_node = curr_node->next;
    }
    struct node* new_node = make_new_node(val, NULL);
    curr_node->next = new_node;
}

void insert_sorted_end(struct node** head, int val) {
    if (*head == NULL) {
        *head = make_new_node(val, NULL);
        return;
    }
    struct node** curr_node = head;

    while ((*curr_node)->next != NULL && (*curr_node)->val < val) {
        curr_node = &(*curr_node)->next;
    }

    if ((*curr_node)->next != NULL) {
        struct node* curr_node_cpy = *curr_node;
        struct node* new_node = make_new_node(val, curr_node_cpy);
        *curr_node = new_node;
    }
    else {
        struct node* new_node = make_new_node(val, NULL);
        (*curr_node)->next = new_node;
    }

}

int main() {
    struct node* linked_list = NULL;
    int n;
    scanf("%d", &n);

    int i = 0;
    while(i != n) {
        int x;
        scanf("%d", &x);
        insert_end(&linked_list, x);
        i += 1;
    }

    printf("%p\n", linked_list);
    for (int i = 0; i < n; ++i) {
        printf("%d\t", linked_list->val);
        linked_list = linked_list->next;
    }

    return 0;
}
