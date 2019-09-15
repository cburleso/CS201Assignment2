//
// Created by CHBADMIN on 9/14/2019.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "slist.cburleso.h"

// Insert a student node into the linked list
int insertStudent(StudentListNode **list, int id, char *name){
    // Check if the record already exists before creating a new record
    if(findStudent(*list, id, &name) == 0){
        return 1;
    }
    // Temp student node to keep track of place in list
    StudentListNode* temp;

    // Create newStudent node to be entered into the list
    StudentListNode* newStudent;
    newStudent = (StudentListNode *)malloc(sizeof(StudentListNode));
    newStudent->id = id;
    strcpy(newStudent->name,name);

    // If the list is empty or the first element has a greater ID than the newStudent node
    if((*list) == NULL || (*list)->id > newStudent->id){
        newStudent->next = (*list);
        (*list) = newStudent;
    }else{
        temp = (*list);

        // Iterate until there is a node with a greater ID than the newStudent node ID
        while(temp->next != NULL && temp->next->id < newStudent->id){
            temp = temp->next;
        }

        // Place the newStudent in the correct spot within the linked list
        newStudent->next = temp->next;
        temp->next = newStudent;
    }

    return 0;
}

// Find a student record with a specified ID
int findStudent(StudentListNode *list, int id, char *name){
    // If the list is empty, return 1
    if(list == NULL){
        return 1;
    }else{
        while(list != NULL && list->id != id){
            list = list->next;
        }
        if(list == NULL){
            return 1;
        }else if(list->id == id){ // Once found, copy the given name parameter to the nodes name field
            strcpy(name,list->name);
            return 0;
        }
    }
}

// Delete a student with a specified ID within the list
int deleteStudent(StudentListNode **list, int id){
    // Create temp pointers to use
    StudentListNode* temp = *list, *prevStudent;

    // Case where head node is deleted
    while(temp != NULL && temp->id == id){
        *list = temp->next;
        temp = *list;
        return 0;
    }

    // Search and delete node with the given ID (not head)
    while (temp != NULL){
        while(temp != NULL && temp->id != id){
            prevStudent = temp;
            temp = temp->next;
        }
        // If the node was not found
        if(temp == NULL){
            return 1;
        }

        // Have previous student node point to the next node after, "deleting" the specified node
        prevStudent->next = temp->next;
        return 0;
    }
}

// Displays the names of each student node user
int printList(StudentListNode *list) {

    // Given node
    StudentListNode *theStudent = list;
    while (theStudent != NULL) {
        printf("%d |%s|\n", theStudent->id, theStudent->name); // Display the ID and name values of the nodes
        theStudent = theStudent->next; // Go to the "next" link / node in the list
    }
    if (list == NULL) { // If the list is empty, print "empty list" to the console
        printf("(empty list)\n");
    }
    return 0;
}
