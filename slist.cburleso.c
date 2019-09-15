//
// Created by CHBADMIN on 9/14/2019.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "slist.cburleso.h"

int insertStudent(StudentListNode **list, int id, char *name){
    // check to see if id already exists in the list
    int found = findStudent(*list, id, &name);
    if(found == 0){
        return 1;
    }
    // Create temp student to hold place
    StudentListNode* tempStudent;

    // Create currentStudent to represent data being entered into list
    StudentListNode* currentStudent;
    currentStudent = (StudentListNode *)malloc(sizeof(StudentListNode));
    currentStudent->id = id;
    strcpy(currentStudent->name,name);

    // Case for head node
    if((*list) == NULL || (*list)->id > currentStudent->id){
        currentStudent->next = (*list);
        (*list) = currentStudent;
    }else{
        tempStudent = (*list);
        // Find place where node belongs in list before inserting it (Ascending order)
        while(tempStudent->next != NULL && tempStudent->next->id < currentStudent->id){
            tempStudent = tempStudent->next;
        }
        // Insert node into list
        currentStudent->next = tempStudent->next;
        tempStudent->next = currentStudent;
    }
    // node inserted
    return 0;
}
// Find student in list
int findStudent(StudentListNode *list, int id, char *name){
    // Empty list
    if(list == NULL){
        return 1;
    }else{
        while(list != NULL && list->id != id){
            list = list->next;
        }
        if(list == NULL){
            return 1;
        }else if(list->id == id){
            strcpy(name,list->name);
            return 0;
        }
    }
}
// delete student from list
int deleteStudent(StudentListNode **list, int id){
    StudentListNode* tempStudent = *list, *previousStudent;
    // If head student is being deleted
    while(tempStudent != NULL && tempStudent->id == id){
        *list = tempStudent->next;
        tempStudent = *list;
        return 0;
    }
    // deleting other than head student
    while (tempStudent != NULL){
        // search for student that needs to be deleted
        while(tempStudent != NULL && tempStudent->id != id){
            previousStudent = tempStudent;
            tempStudent = tempStudent->next;
        }
        // If not found
        if(tempStudent == NULL){
            return 1;
        }
        // if found unlink to be deleted
        previousStudent->next = tempStudent->next;
        return 0;
    }
}
// print entire list out
int printList(StudentListNode *list) {
    StudentListNode *currentStudent = list;
    while (currentStudent != NULL) {
        printf("%d |%s|\n", currentStudent->id, currentStudent->name);
        currentStudent = currentStudent->next;
    }
    if (list == NULL) {
        printf("(empty list)\n");
    }
    return 0;
}
