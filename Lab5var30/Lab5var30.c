#include <stdio.h>
#include <stdlib.h>

typedef struct stack 
{
    int value;              /* информативная часть */
    struct stack* next;    /* адресная часть */
} node_t, stack_t;


int is_empty(stack_t** top) 
{
    return *top == NULL;
}

// Положить элемент в стек.
void push(stack_t** top, int value) 
{
    node_t* node = (node_t*)malloc(sizeof(node_t));

    node->value = value;

    node->next = NULL;

    if (!is_empty(top))
        node->next = *top;
    
    (*top) = node;
}


 // Функция удаления элемента с вершины стека
void pop(stack_t** top) {
    
    node_t* node;

    if (!is_empty(top)) {
        node = *top;
        *top = (*top)->next;

        free(node);

        node = NULL;
    }
}


// Извлечение значения из стека
int top(stack_t** top) {
    if (!is_empty(top))
        return (*top)->value;
    else
        return 0;
}

// Очистка стека
void clear(stack_t** top) {
    while (!is_empty(top))
        pop(top);
}

// Вывод
void print(stack_t** top) {
    node_t* node;
    for (node = *top; node != NULL; node = node->next)
        printf("%d -> ", node->value);
    printf("\b\b\b   \n");
}



int main()
{
    int i;
    stack_t* s1 = NULL; 
    stack_t* s2 = NULL; 
    stack_t* s3 = NULL;
    for (i = 0; i < 10; ++i)
        push(&s1, i);

    printf("BEFORE\ncontents of the first stack: \n");
    print(&s1);


    for (i = 0; i < s1!= NULL ; ++i) {
        push(&s2, top(&s1));
        pop(&s1);
    }
    for (i = 0; i < s2 != NULL; ++i) {
        push(&s3, top(&s2));
        pop(&s2);
    }
      
    printf("AFTER\ncontents of the first stack: \n");
    print(&s1);
    printf("\ncontents of the temp stack: \n");
    print(&s2);
    printf("\ncontents of the second stack: \n");
    print(&s3);

    clear(&s3);

    return 0;
}