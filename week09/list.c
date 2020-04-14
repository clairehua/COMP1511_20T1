// implements functions in list.h
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

// ======= W10 Tut Problems ========

// appends list1 to list 2 and returns the new list (head of it)
struct node *list_append(struct node *list1, struct node *list2) {
    // check base cases
    
    // both empty lists
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }
    // list 1 empty
    if (list1 == NULL) {
        return list2;
    }
    
    // general case!!!!!
    // NOTE: make a copy!!
    struct node *curr = list1;
    
    // traverse to the end of list1
    while (curr->next != NULL) {
        curr = curr->next;
    }   
    // now at the end of list1 (at the last node)
    // join it up with list2
    curr->next = list2;
    return list1;
}


// use: struct node *create_node(int dat);

// returns a copy of the linked list
struct node *copy(struct node *head) {
    struct node *copiedList = NULL;
    
    struct node *curr = head;
    while (curr != NULL) {
        // copy the node
        struct node *newNode = create_node(curr->data);
        // adding the node to our list
        copiedList = list_append(copiedList, newNode);
        curr = curr->next;
    }
    return copiedList;
}

// returns 1 if the two lists are identical, otherwise returns 0
int identical(struct node *head1, struct node *head2) {
    // make copies of pointers
    struct node *curr1 = head1;
    struct node *curr2 = head2;
    
    while (curr1 != NULL && curr2 != NULL) {
        // check data is the same (check if it is non identical)
        if (curr1->data != curr2->data) {
            return 0;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    // either one or both are NULL
    // if both are NULL - GOOD (identical)
    if (curr1 == NULL && curr2 == NULL) {
        return 1;
    } else {
        // this means there are different lengths
        return 0;
    }

}

// returns 1 if list is in strictly increasing order, otherwise returns 0
int ordered(struct node *head) {
    return 0;   // replace this
}

// given two lists in strictly increasing order,
// return a new linked list (in strictly increasing order) of the elements in both set1 and set2
struct node *set_intersection(struct node *set1, struct node *set2) {
    struct node *curr1 = set1;
    struct node *curr2 = set2;
    
    // base cases
    
    if (curr1 == NULL || curr2 == NULL) {
        return NULL;
    } else if (curr1 == NULL) {
        return NULL;    
    } else if (curr2 == NULL) {
        return curr1;
    }
    
    
    
    // return list
    struct node *intersectList = NULL;
    
    
    
    while (curr1 != NULL && curr2 != NULL) {
    
        if (curr1 < curr2) {
            struct node *newNode = create_node(curr1->data);
            // adding the node to our list
            intersectList = list_append(intersectList, newNode);
            // make curr1 catch up to curr2
            curr1 = curr1->next;
        } else if (curr2 < curr1) { 
            struct node *newNode = create_node(curr2->data);
            // adding the node to our list
            intersectList = list_append(intersectList, newNode);

            curr2 = curr2->next;
        } else {
            // curr1 == curr2    
            struct node *newNode = create_node(curr1->data);
            // adding the node to our list
            intersectList = list_append(intersectList, newNode);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }              
        
    }
    
    if (curr1 == NULL && curr2 == NULL) {
        return intersectList;        
    } else if (curr1 != NULL) {
        intersectList = list_append(intersectList, curr1);
    } else {
        intersectList = list_append(intersectList, curr2);
    }
    
    return intersectList;
}

// given two linked lists in strictly increasing order,
// return a new linked list (in strictly increasing order) of the elements in either set1 or set2
// no duplicates (only include them once)
struct node *set_union(struct node *set1, struct node *set2) {
    return NULL;    // replace this
}

// =================================

// given an array of integer values for data items
// returns the head of a linked list with these values
// in the order as they appear in the array
// size gives the size of the array
struct node *create_list(int values[], int size) {
    int i = 0;

    if (size <= 0) {
        // empty linked list (or invalid size)
        return NULL;
    }

    struct node *head = NULL;   // head of the linked list
    struct node *tmp = NULL;    // temporary item we're working with
    struct node *curr = NULL;   // current node we're looking at in the linked list

    while (i < size) {
        tmp = create_node(values[i]);

        // link this node onto our list
        if (head == NULL) {
            // this is the first node in the list
            head = tmp;
            curr = head;
        } else {
            // this is not the first node in the list
            // add it to the end, i.e. after curr
            curr->next = tmp;

            // reset curr to point at the new last node
            curr = tmp;
        }
        i = i + 1;
    }

    return head;
}

// creates a struct node with the given data value
// returns a pointer to this node
struct node *create_node(int dat) {
    struct node *new = malloc(sizeof(struct node));
    assert(new != NULL);
    new->data = dat;
    new->next = NULL;

    return new;
}

// prints out the list given the head of a list
void print_list(struct node *head) {
    struct node *curr;
    curr = head;

    while (curr != NULL) {
        printf("[ %d ]-->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");

}

// frees all the elements in a linked list
void free_list(struct node *head) {
    if (head == NULL) {
        return;
    }
    free_list(head->next);
    free(head);
}

// return the number of items in the linked list
int num_items(struct node *head) {
    struct node *curr = head;
    int count = 0;

    while (curr != NULL) {
        count = count + 1;
        curr = curr->next;
    }

    return count;
}
