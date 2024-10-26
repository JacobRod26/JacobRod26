#include <stdio.h>
#include <stdlib.h>
struct node
{
    float value;
    struct node *next;
};
struct node* head = NULL;

void insert_end(float num)
{
	struct node *newNode;
	struct node *nodeptr;

	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = num;
	newNode->next = NULL;

	if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        nodeptr = head;

        while(nodeptr->next != NULL)
        {
            nodeptr = nodeptr->next;
        }

        nodeptr->next = newNode;

    }

}


void print_list()
{
    struct node *nodeptr = head;
    printf("\nList of Exam Grades: ");
    while(nodeptr != NULL)
    {
        printf("%.2f  ",nodeptr->value);
        nodeptr = nodeptr->next;
    }
}

void class_average()
{
    float ave = 0;
    int count = 0;
    struct node *nodeptr = head;
    printf("\nClass average: ");
    while (nodeptr != NULL)
        {
            ave += nodeptr->value;
            nodeptr = nodeptr->next;
            count++;
        }
    ave /= count;
    printf("%.2f", ave);

}

void high_low()
{
    struct node *nodeptr = head;
    struct node *highest_node = head;
    struct node *lowest_node = head;
    float highest = nodeptr->value;
    float lowest = nodeptr->value;

    printf("\n1) Highest and the Lowest exam scores among the linked-list:\n");
    while(nodeptr != NULL)
    {
        if(nodeptr->value > highest)
        {
            highest = nodeptr->value;
            highest_node = nodeptr;
        }
        if(nodeptr->value < lowest)
        {
            lowest = nodeptr->value;
            lowest_node = nodeptr;
        }
        nodeptr = nodeptr->next;
    }

    printf("    Highest value: %.2f Highest address: %p\n", highest, (void*)highest_node);
    printf("    Lowest value: %.2f Lowest address: %p", lowest, (void*)lowest_node);

}

void replace_val()
{
    struct node *current = head;
    struct node *lowest_node = head;
    struct node *previous = NULL;
    struct node *lowest_previous = NULL;


    while (current != NULL) {
        if (current->value < lowest_node->value) {
            lowest_node = current;
            lowest_previous = previous;
        }
        previous = current;
        current = current->next;
    }


    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = 70;
    new_node->next = lowest_node->next;


    if (lowest_previous != NULL) {
        lowest_previous->next = new_node;
    } else {
        head = new_node;
    }


    free(lowest_node);

    printf("\n\n2) Replaced the lowest exam score with a new node that has the value 70.\n");
    printf("Address of the new node: %p", (void*)new_node);

}



void del_val() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node* nodePtr = head;
    struct node* previousNode = NULL;
    struct node* highest_node = head;
    struct node* highest_previous = NULL;
    float highest = nodePtr->value;


    while (nodePtr != NULL) {
        if (nodePtr->value > highest) {
            highest = nodePtr->value;
            highest_node = nodePtr;
            highest_previous = previousNode;
        }
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }


    if (highest_node == head) {
        head = head->next;
        free(highest_node);
    } else {
        highest_previous->next = highest_node->next;
        free(highest_node);
    }



}

int main()
{
    float num;
    printf("Enter seven exam scores for your class: \n");

    for(int i = 0; i<7; i++)
    {
        printf("Enter grade for Exam %d : ", i+1);
        scanf("%f", &num);
        insert_end(num);
    }

    high_low();//1st section
    print_list();
    class_average();


    replace_val();
    print_list();

    del_val();
    printf("\n\n3) Delete the highest exam score from the list and display the list:");
    print_list();

    printf("\n\n4) Calculate and display the class average:");
    class_average();


    return 0;
}
