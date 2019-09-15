//
// Created by CHBADMIN on 9/14/2019.
//

#ifndef CS201ASSIGNMENT2_SLIST_CBURLESO_H
#define CS201ASSIGNMENT2_SLIST_CBURLESO_H

// Struct to be used within the singly linked list
typedef struct StudentListNodeStruct {
    int id;
    char name[32];
    struct StudentListNodeStruct *next;
}   StudentListNode;

// Inserts a new record in the list, sorted (ascending) by student ID. If record already exists, return 1. Otherwise,
// create a new list node, put the list node in the correct place, and return 0
int insertStudent(StudentListNode **list, int id, char *name);

// Finds the record of the student with the specific ID, if there is one, it copies the name from that record
// to the name parameter and returns 0
int findStudent(StudentListNode *list, int id, char *name);

// Deletes the record from the list which has the given ID. If there isn't one, return 1. Otherwise, delete the record
// from the list and return 0.
int deleteStudent(StudentListNode **list, int id);

// Prints the records from the list, one to a line in the form "id |name|". If the list is empty, print "(empty list)"
int printList(StudentListNode *list);

#endif //CS201ASSIGNMENT2_SLIST_CBURLESO_H
