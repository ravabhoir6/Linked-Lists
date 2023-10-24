#include <stdio.h>
#include <stdlib.h>

// Structure for a Doubly linked list 
struct Node {
    int data;
    struct Node *next, *prev;
};

// Functions declarations
void forward_traversal(struct Node *);
void backward_traversal(struct Node *);
void insert_at_begin(struct Node **, int);
void insert_at_end(struct Node **, int);
void add_after_value(struct Node **, int, int);
void add_before_value(struct Node **, int, int);
void insert_at_index(struct Node **, int, int);
void delete_at_begin(struct Node **);
void delete_at_end(struct Node **);
void delete_by_val(struct Node **, int);


// Main 
int main(){
    struct Node *head;
    head = NULL;
    int choice,x,v,i;
    char ch;

    do{
        printf("\nOperations\n");
        printf("1. insert at begin\n");
        printf("2. insert at end\n");
        printf("3. insert after value\n");
        printf("4. insert before value\n");
        printf("5. insert at index\n");
        printf("6. delete at begin\n");
        printf("7. delete at end\n");
        printf("8. delete node by value\n");
        printf("9. forward traversal\n");
        printf("10. backward traversal\n");
        printf("11. exit\n");

        printf("Enter your choice :: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: printf("Enter element to insert :: ");
                    scanf("%d",&x);
                    insert_at_begin(&head,x);
                    break;

            case 2: printf("Enter element to insert :: ");
                    scanf("%d",&x);
                    insert_at_end(&head,x);
                    break;

            case 3: printf("Enter value :: ");
                    scanf("%d",&v);
                    printf("Enter element to insert :: ");
                    scanf("%d",&x);
                    add_after_value(&head,v,x);
                    break;

            case 4: printf("Enter value :: ");
                    scanf("%d",&v);
                    printf("Enter element to insert :: ");
                    scanf("%d",&x);
                    add_before_value(&head,v,x);
                    break;

            case 5: printf("Enter index :: ");
                    scanf("%d",&i);
                    printf("Enter element to insert :: ");
                    scanf("%d",&x);
                    insert_at_index(&head,i,x);
                    break;

            case 6: delete_at_begin(&head);
                    break;

            case 7: delete_at_end(&head);
                    break;

            case 8: 
                    printf("Enter element to delete :: ");
                    scanf("%d",&x);
                    delete_by_val(&head,x);
                    break;

            case 9: forward_traversal(head);
                    break;

            case 10: backward_traversal(head);
                    break;

            case 11: exit(0);
                    break;

            default: printf("Invalid Choice!\n");
                    break;

        }

        printf("Do you wish to continue?(y/n) :: ");
        getchar();
        scanf("%c",&ch);
        
    }while(ch == 'y');
}


// Function to traverse the doubly linked list in the forward direction
void forward_traversal(struct Node *head){
    if(!head){
        printf("DLL is empty\n");
        return;
    }

    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
    return;
}


// Function to traverse the doubly linked list in the backward direction
void backward_traversal(struct Node *head){
    if(!head){
        printf("DLL is empty\n");
        return;
    }

    while(head->next != NULL){
        head = head->next;
    }

    while(head != NULL){
        printf("%d ",head->data);
        head = head->prev;
    }
    printf("\n");

    return;
}


// Function to insert a new node at the beginning of the doubly linked list
void insert_at_begin(struct Node **head, int val){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = (*head);
    if((*head) != NULL){
        (*head)->prev=newnode;
    }
    *head = newnode;
    return;
}


// Function to insert a new node at the end of the doubly linked list
void insert_at_end(struct Node **head, int val){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    if((*head) == NULL){
        *head = newnode;
        return;
    }

    struct Node *current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newnode;
    newnode->prev = current;
    return;
}


// Function to insert a new node after a specific value in the doubly linked list
void add_after_value(struct Node **head, int val, int element){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = element;
    newnode->next = NULL;
    newnode->prev = NULL;

    if((*head) == NULL){
        *head = newnode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL){
        if(temp->data == val){
            newnode->next = temp->next;
            newnode->prev = temp;
            newnode->next->prev = newnode;
            temp->next = newnode;
            return;
        }
    }
    temp->next = newnode;
    newnode->prev = temp;
    return;
}


// Function to insert a new node before a specific value in the doubly linked list
void add_before_value(struct Node **head, int val, int element){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = element;
    newnode->next = NULL;
    newnode->prev = NULL;

    if ((*head)==NULL){
        *head = newnode;
        return;
    }

    if((*head)->data == val){
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
        return;
    }

    struct Node *current = *head;

    while(current->next != NULL){
        if((current->next)->data == val ){
            newnode->next = current->next;
            newnode->prev = current;
            current->next = newnode;
            newnode->next->prev = newnode;
            return;
        }
    }

    newnode->next = (*head);
    (*head)->prev = newnode;
    *head  = newnode;
    return; 
}


// Function to insert a new node at a specified index in the doubly linked list
void insert_at_index(struct Node **head, int index, int element) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = element;

    if (index == 0) {
        newnode->prev = NULL;
        newnode->next = *head;

        if (*head != NULL) {
            (*head)->prev = newnode;
        }

        *head = newnode; // Update the head to point to the new node
        return;
    }

    int i = 0; // Initialize i to 0
    struct Node *current = *head;

    while (current != NULL) {
        if (i == index) {
            newnode->next = current;
            newnode->prev = current->prev;
            
            if (current->prev != NULL) {
                current->prev->next = newnode;
            }
            
            current->prev = newnode;
            return;
        }
        current = current->next;
        i++;
    }

    // If index is greater than the length of the list, you can append it to the end
    if (current == NULL && i == index) {
        struct Node *tail = *head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = NULL;
    }
}


// Function to delete the node at the beginning of the doubly linked list
void delete_at_begin(struct Node **head){
    if ((*head)==NULL){
        return ;
    }
    struct Node *temp = *head;
    (*head) = (*head)->next;
    if((*head) != NULL){
        (*head)->prev = NULL;
    }
    free(temp);
    return;
}


// Function to delete the node at the end of the doubly linked list
void delete_at_end(struct Node **head){
    if((*head) == NULL){
        return;
    }

    struct Node *temp = *head;

    if((*head)->next == NULL){
        *head = NULL;
        free(temp);
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    return;
}


// Function to delete a node with a specific value from the doubly linked list
void delete_by_val(struct Node **head, int val){
    if(*head == NULL){
        return;
    }

    if((*head)->data = val){
        struct Node *temp = *head;
        *head = (*head)->next;
        if((*head) != NULL){
            (*head)->prev = NULL;
        }
        return;
    }

    struct Node *current = *head;
    while(current->next != NULL){
        if(current->data == val){
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return;
        }
    }

    if(current->data == val){
        current->prev->next = NULL;
        free(current);
        return;
    }
    return;
}


