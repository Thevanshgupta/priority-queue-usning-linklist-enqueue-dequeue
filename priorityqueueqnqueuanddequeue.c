#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int data;
int priority;
struct Node* next;
} Node;
typedef struct PriorityQueue {
Node* front;
} PriorityQueue;
Node* createNode(int data, int priority) {
Node* newNode = (Node*)malloc(sizeof(Node));
if (newNode == NULL) {
printf("Memory allocation failed.\n");
exit(1);
}
newNode->data = data;
newNode->priority = priority;
newNode->next = NULL;
return newNode;
}
PriorityQueue* createPriorityQueue() {
PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
if (queue == NULL) {
printf("Memory allocation failed.\n");
exit(1);
}
queue->front = NULL;
return queue;
}
int isEmpty(PriorityQueue* queue) {
return (queue->front == NULL);
}
void enqueue(PriorityQueue* queue, int data, int priority) {
Node* newNode = createNode(data, priority);

if (isEmpty(queue) || priority < queue->front->priority) {
    newNode->next = queue->front;
    queue->front = newNode;
} else {
    Node* temp = queue->front;
    while (temp->next != NULL && temp->next->priority <= priority) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
printf("Enqueued %d with priority %d.\n", data, priority);
}
void dequeue(PriorityQueue* queue) {
if (isEmpty(queue)) {
printf("Priority Queue is empty. Cannot dequeue.\n");
return;
}
Node* temp = queue->front;
queue->front = queue->front->next;
printf("Dequeued %d with priority %d.\n", temp->data, temp->priority);
free(temp);
}
void display(PriorityQueue* queue) {
if (isEmpty(queue)) {
printf("Priority Queue is empty.\n");
return;
}

Node* temp = queue->front;
printf("Priority Queue: ");
while (temp != NULL) {
    printf("(%d, %d) ", temp->data, temp->priority);
    temp = temp->next;
}
printf("\n");
}

int main() {
PriorityQueue* queue = createPriorityQueue();

int choice, data, priority;

while (1) {
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the data to enqueue: ");
            scanf("%d", &data);
            printf("Enter the priority of the data: ");
            scanf("%d", &priority);
            enqueue(queue, data, priority);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;
case 4:
printf("Exiting the program.\n");
exit(0);
default:
printf("Invalid choice. Please try again.\n");
}
}
return 0;
}