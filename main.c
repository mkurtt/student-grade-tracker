#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{

    char name [50];
    int id;
    float grade;
    struct Node *next;
} Node;

Node *newNode(char *name, int id, float grade){

    Node *node = malloc(sizeof(Node));
    strcpy(node->name, name);
    node->id = id;
    node->grade = grade;
    node->next = NULL;
    return node;
}

void addStudent(Node **head, char *name, int id, float grade);
void deleteStudent(Node **head, int id);
void listStudents(Node *head);
void averageGrade(Node *head);
void highestGrade(Node *head);
void lowestGrade(Node *head);

int main(){

    Node *head= NULL;

    addStudent(&head, "Name1", 10, 50);
    addStudent(&head, "Name2", 3, 30);
    addStudent(&head, "Name3", 6, 40);
    listStudents(head);
    averageGrade(head);
    highestGrade(head);
    lowestGrade(head);
    deleteStudent(&head,0);
    listStudents(head);
    deleteStudent(&head,10);
    listStudents(head);

    return 0;
}

void addStudent(Node **head, char* name, int id, float grade){

    Node *new =newNode(name,id,grade);
    new->next = *head;
    *head = new;
}
void deleteStudent(Node **head, int id){

    Node *temp = *head;
    Node *temp2 = *head;  
    while(temp != NULL && temp->id != id){
        temp2 = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Student not found\n"); 
    } else if(temp == *head){
        *head = temp->next;
        free(temp);
    } else {
        temp2->next = temp->next;
        free(temp);
    }
}

void listStudents(Node *head){

    Node *temp = head;
    while(temp!=NULL){
        printf(" Name: %s | Id: %d | Grade: %.1f\n" , temp->name,temp->id,temp->grade);
        temp = temp->next;
    }
    printf("NULL\n");
}

void averageGrade(Node *head){

    Node *temp =head;
    float sum= 0;
    int i= 0;
    while(temp!= NULL){
        sum+=temp->grade;
        i++;
        temp = temp->next;
    }
    if(i == 0){
        printf("No students\n");
        return;
    }
    printf("Average: %.1f\n" , sum/ i);        
}


void highestGrade(Node *head){

    Node *temp = head;
    float highest = temp->grade; // 10 20 30 40 50
    while(temp != NULL){
        if(temp->grade > highest ){
            highest = temp->grade;
        }
        temp = temp->next;
    }
    printf("Highest Grade: %.1f\n", highest);
}

void lowestGrade(Node *head){

    Node *temp = head;
    float lowest = temp->grade;
    while(temp!= NULL){
        if(temp->grade < lowest){
            lowest = temp->grade;
        }
        temp = temp->next;
    }
    printf("Lowest Grade: %.1f\n", lowest);
}