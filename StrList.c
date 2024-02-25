#include <stdio.h>
#include "StrList.h"
#include <string.h>
#include <stdlib.h>

// Function to allocate memory for a Node with data and next pointer
Node* node_alloc(const char* data, Node* next) {
    // Allocate memory for the new Node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    } 
    // Allocate memory for the string data and copy the provided data
    newNode-> _data = strdup(data);
    if (newNode-> _data == NULL) {
        printf("Memory allocation failed\n");
        free(newNode);
        exit(EXIT_FAILURE);
    }
    // Set the next pointer
    newNode-> _next = next;
    return newNode;
}

StrList* StrList_alloc(){
    StrList* list = (StrList*)malloc(sizeof(StrList));
    if(list == NULL){
        printf("Error: Could not allocate memory for StrList\n");
        return NULL;
    }
    list-> _head = NULL;
    list-> _size = 0;
    return list;
}

void StrList_free(StrList* StrList){
    if(StrList == NULL){
        return;
    }
    Node* current = StrList-> _head;
    Node* next;
    while(current != NULL){
        next = current-> _next;
        free(current-> _data); // Free memory allocated for data
        free(current); // Free memory allocated for the node
        current = next;
    }
    free(StrList); // Free memory allocated for the list
}

void StrList_free11(StrList* StrList){
    if(StrList == NULL){
        return;
    }
    Node* current = StrList-> _head;
    Node* next;
    while(current != NULL){
        next = current-> _next;
        free(current-> _data); // Free memory allocated for data
        free(current); // Free memory allocated for the node
        current = next;
    }
    StrList->_head = NULL;
    StrList->_size = 0;

}

size_t StrList_size(const StrList* StrList){
    return StrList-> _size;
}

void StrList_insertLast(StrList* StrList, const char* data){
    // Create a new node
    Node* newNode = node_alloc(data, NULL);
    if(newNode == NULL){
        return;
    }
    if (StrList-> _head == NULL) {
        StrList-> _head = newNode;
    } else {
        // Otherwise, find the last node and append the new node after it
        Node* current = StrList-> _head;
        while (current-> _next != NULL) {
            current = current-> _next;
        }
        current-> _next = newNode;
    }
    StrList-> _size++;
}


void StrList_insertAt(StrList* StrList, const char* data, int index){
    if(index < 0){
        printf("index is too low!");
        return;
    }
    if(index > StrList-> _size){
        printf("index is yoo high!");
        return;
    }
    // Create a new node
    Node* newNode = node_alloc(data, NULL);
    if(newNode == NULL){
        return;
    }
    if(index == 0 || StrList-> _head == NULL){
        // Inserting at the beginning of the list
        newNode-> _next = StrList-> _head;
        StrList-> _head = newNode;
    }
    else{
        Node* current = StrList-> _head;
        // Traverse the list to find the node just before the insertion point
        while(index > 1){
            current = current-> _next;
            index--;
        }
        // Insert the new node between current and current->next
        newNode-> _next = current-> _next;
        current-> _next = newNode; 
    }
    StrList-> _size++;
}


char* StrList_firstData(const StrList* StrList){
    if(StrList == NULL){
        printf("List is empty!");
        return "";
    }
    return StrList-> _head-> _data;
}

void StrList_print(const StrList* StrList){
    if(StrList == NULL){
        printf("The list is empty!");
        return;
    }
    Node* current = StrList-> _head;
    while(current != NULL){
        printf("%s ", current-> _data); // Print each word
        current = current-> _next;
    }
    printf("\n"); // Add a newline after printing each sentence
}



void StrList_printAt(const StrList* Strlist, int index){
    if(Strlist == NULL){
        printf("List is too short!");
        return;
    }
    if(index < 0){
        printf("index is too low!");
        return;
    }
    if(index > Strlist-> _size){
        printf("index is yoo high!");
        return;
    }

    Node* current = Strlist-> _head;
    while(index != 0){
        current = current-> _next;
        index--;
    }
    printf("%s\n", current-> _data);
}

int StrList_printLen(const StrList* Strlist){
    int totalChars = 0;
    Node* current = Strlist-> _head;
    while(current != NULL){
        totalChars += strlen(current-> _data);
        current = current-> _next;
    }
    return totalChars;
}

int StrList_count(StrList* StrList, const char* data){
    int count = 0;
    Node* current = StrList-> _head;
    while (current != NULL){
        if(strcmp(current-> _data, data) == 0){
            count++;
        }
        current = current-> _next;
    }
    return count;
}

void StrList_remove(StrList* StrList, const char* data){
    Node* current = StrList-> _head;
    Node* prev = NULL;
    while(current != NULL){
        if(strcmp(current-> _data, data) == 0){
            Node* temp = current;
            if(prev == NULL){
                StrList-> _head = current-> _next;
            }
            else{
                prev-> _next = current-> _next;
            }
            current = current -> _next;
            free(temp-> _data);
            free(temp);
            StrList-> _size--; // Decrease the size of the list
            return; // Exit the function after removing the node
        }
        else{
            prev = current;
            current = current-> _next;
        }
    }
}



void StrList_removeAt(StrList* StrList, int index){
    if(index < 0){
        printf("index is too low!");
        return;
    }
    if(index > StrList-> _size){
        printf("index is yoo high!");
        return;
    }
    Node* current = StrList-> _head;
    Node* prev = NULL;
    while(index != 0){
        prev = current;
        current = current-> _next;
        index--;
    }
    if(prev == NULL){
        StrList-> _head = current-> _next;
    }
    else{
        Node* temp = current;
        prev-> _next = current-> _next;
        current = current-> _next;
        free(temp-> _data);
        free(temp);
    }
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if(StrList1-> _size != StrList2-> _size){
        return 0;
    }
    int n = StrList1-> _size;
    Node* current1 = StrList1-> _head;
    Node* current2 = StrList2-> _head;
    for(int i = 0; i < n; i++){
        if(strcmp(current1-> _data, current2-> _data) != 0){
            return 0;
        }
        current1 =  current1-> _next;
        current2 =  current2-> _next;
    }
    return 1;
}

StrList* StrList_clone(const StrList* StrList){
    if(StrList == NULL){
        return NULL;
    }
    StrListPtr CloneList = StrList_alloc();
    if(CloneList == NULL){

        return NULL;
    }
    Node* current = StrList-> _head;
    Node* cloneTemp = NULL;
    while(current != NULL){
        Node* newNode = node_alloc(current-> _data, NULL);
        if(newNode == NULL){
            StrList_free(CloneList);
            return NULL;
        }
        if(CloneList-> _head == NULL){
            CloneList-> _head = newNode;
            cloneTemp = newNode;
        } else {
            cloneTemp-> _next = newNode;
            cloneTemp = cloneTemp-> _next;
        }
        CloneList->_size++;
        current = current-> _next;
    }
    return CloneList;
}

void StrList_reverse( StrList* StrList){
    Node* prev = NULL;
    Node* current = StrList-> _head;
    Node* next = NULL;

    // Traverse the list and reverse the pointers
    while (current != NULL) {
        next = current-> _next; // Store next node
        current-> _next = prev; // Reverse current node's pointer
        prev = current; // Move pointers one position ahead
        current = next;
    }
    
    // Update the head pointer to point to the last node (which is now the first)
    StrList-> _head = prev;
}

void StrList_sort(StrList *strList) {
    Node* current = strList-> _head;
    Node* index = NULL;
    char* temp;

    // If the list is empty or contains only one element, it is already sorted
    if (current == NULL || current-> _next == NULL) {
        return;
    }

    while (current != NULL) {
        index = current-> _next;
        while (index != NULL) {
            // Compare adjacent strings and swap if necessary to ensure lexicographical order
            if (strcmp(current-> _data, index-> _data) > 0) {
                temp = current-> _data;
                current-> _data = index-> _data;
                index-> _data = temp;
            }
            index = index-> _next;
        }
        current = current-> _next;
    }
}

int StrList_isSorted(StrList* strList) {
    Node *current = strList-> _head;
    while (current != NULL && current-> _next != NULL) {
        // Compare the current string with the next one
        if (strcmp(current-> _data, current-> _next-> _data) > 0) {
            // If the current string is greater than the next one, the list is not sorted
            return 0;
        }
        current = current-> _next;
    }
    // If all comparisons passed without finding any unsorted pair, the list is sorted
    return 1;
}
