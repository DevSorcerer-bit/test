#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 栈的最大容量

// 栈的结构定义
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// 队列的节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 队列的结构定义
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// 栈的基本操作函数
void initStack(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("栈已满！\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("栈为空！\n");
        return -1; // 返回-1表示栈为空
    }
    return s->data[s->top--];
}

void printStack(Stack* s) {
    if (isEmpty(s)) {
        printf("栈为空！\n");
        return;
    }
    printf("栈中的元素: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// 队列的基本操作函数
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) { // 队列为空
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("队列为空！\n");
        return -1; // 返回-1表示队列为空
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; // 队列为空
    }
    free(temp);
    return value;
}

void printQueue(Queue* q) {
    if (q->front == NULL) {
        printf("队列为空！\n");
        return;
    }
    Node* current = q->front;
    printf("队列中的元素: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 主函数
int main() {
    Stack stack;
    Queue queue;
    initStack(&stack);
    initQueue(&queue);

    char choice;

    while (1) {
        printf("输入 '1' 创建栈，输入 'a' 创建队列（输入 'q' 退出）：");
        scanf(" %c", &choice);  // 注意这里的空格，确保读取空格后一个字符

        switch (choice) {
        case '1': {
            initStack(&stack); // 每次选择栈时重新初始化
            int stackChoice;
            while (1) {
                printf("栈操作：\n");
                printf("1: 压栈\n");
                printf("2: 弹栈\n");
                printf("3: 打印栈\n");
                printf("4: 返回主菜单\n");
                printf("选择操作: ");
                scanf("%d", &stackChoice); // 读取整数类型的操作选择

                switch (stackChoice) {
                case 1: {
                    int value;
                    printf("输入要压栈的值: ");
                    scanf("%d", &value); // 读取栈中要压入的值
                    push(&stack, value);
                    break;
                }
                case 2:
                    printf("弹出的元素: %d\n", pop(&stack));
                    break;
                case 3:
                    printStack(&stack);
                    break;
                case 4:
                    goto mainMenu; // 返回主菜单
                default:
                    printf("无效选择，请重试。\n");
                }
            }
            break;
        }
        case 'a': {
            initQueue(&queue); // 每次选择队列时重新初始化
            int queueChoice;
            while (1) {
                printf("队列操作：\n");
                printf("1: 入队\n");
                printf("2: 出队\n");
                printf("3: 打印队列\n");
                printf("4: 返回主菜单\n");
                printf("选择操作: ");
                scanf("%d", &queueChoice); // 读取整数类型的操作选择

                switch (queueChoice) {
                case 1: {
                    int value;
                    printf("输入要入队的值: ");
                    scanf("%d", &value); // 读取队列中要入队的值
                    enqueue(&queue, value);
                    break;
                }
                case 2:
                    printf("出队的元素: %d\n", dequeue(&queue));
                    break;
                case 3:
                    printQueue(&queue);
                    break;
                case 4:
                    goto mainMenu; // 返回主菜单
                default:
                    printf("无效选择，请重试。\n");
                }
            }
            break;
        }
        case 'q':
            printf("正在退出...\n");
            exit(0);
        default:
            printf("无效选择，请重试。\n");
        }
    }

mainMenu:
    return 0;
}
