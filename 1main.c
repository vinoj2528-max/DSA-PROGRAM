#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
} *front, *rear, *temp, *front1;

int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();

int count = 0;

int main()
{
    int no, ch, e;

    printf("\n1 - Enque");
    printf("\n2 - Deque");
    printf("\n3 - Front element");
    printf("\n4 - Empty");
    printf("\n5 - Exit");
    printf("\n6 - Display");
    printf("\n7 - Queue size");

    create();

    while (1)
    {
        printf("\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d", &no);
                enq(no);
                break;

            case 2:
                deq();
                break;

            case 3:
                e = frontelement();

                if (e != 0)
                    printf("Front element : %d", e);
                else
                    printf("\nNo front element in Queue as queue is empty");

                break;

            case 4:
                empty();
                break;

            case 5:
                exit(0);

            case 6:
                display();
                break;

            case 7:
                queuesize();
                break;

            default:
                printf("Wrong choice, Please enter correct choice");
                break;
        }
    }

    return 0;
}

/* Create an empty queue */
void create()
{
    front = rear = NULL;
}

/* Returns queue size */
void queuesize()
{
    printf("\nQueue size : %d", count);
}

/* Enqueuing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));

        rear->ptr = NULL;
        rear->info = data;

        front = rear;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));

        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;

        rear = temp;
    }

    count++;
}

/* Displaying the queue elements */
void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }

    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }

    if (front1 == rear)
        printf("%d", front1->info);
}

/* Dequeuing the queue */
void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("\nError: Trying to display elements from empty queue");
        return;
    }

    if (front1->ptr != NULL)
    {
        front1 = front1->ptr;

        printf("\nDequed value : %d", front->info);

        free(front);

        front = front1;
    }
    else
    {
        printf("\nDequed value : %d", front->info);

        free(front);

        front = NULL;
        rear = NULL;
    }

    count--;
}

/* Returns the front element of queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return front->info;
    else
        return 0;
}

/* Display if queue is empty or not */
void empty()
{
    if ((front == NULL) && (rear == NULL))
        printf("\nQueue empty");
    else
        printf("Queue not empty");
}





PS C:\Users\Vinodhini\OneDrive\Desktop\vinos file\DSA PROGRAM> gcc 1main.c -o main
PS C:\Users\Vinodhini\OneDrive\Desktop\vinos file\DSA PROGRAM> .\main

 1 - Push
 2 - Pop
 3 - Top
 4 - Empty
 5 - Exit
 6 - Display
 7 - Stack Count
 8 - Destroy stack
 Enter choice : 1
Enter data : 56

 Enter choice : 1
Enter data : 80

 Enter choice : 2

 Popped value : 80
 Enter choice : 3

 Top element : 56
 Enter choice : 1
Enter data : 78

 Enter choice : 1
Enter data : 90

 Enter choice : 6
90 78 56
 Enter choice : 7

 No. of elements in stack : 3
 Enter choice : 8

 All stack elements destroyed
 Enter choice : 4

 Stack is empty
 Enter choice : 5