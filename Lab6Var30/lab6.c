
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum bool{ false,true };

typedef struct item {
    char* data;
    struct item* left;
    struct item* right;
} Item;

void AddNode(char* data, Item** node);
void LeftOrder(Item* node);

void AddNode(char* data, Item** node)
{
    if (*node == NULL) {
        *node = (Item*)calloc(1, sizeof(Item));
        (*node)->data = data;
        (*node)->left = (*node)->right = NULL;
    }
    else {
        if (stricmp(data, (*node)->data) < 0)
            AddNode(data, &(*node)->left);

        else if (stricmp(data, (*node)->data) > 0)
            AddNode(data, &(*node)->right);
        else
            puts("There is such element in the tree");
    }
}
/* Обход дерева Слева  */
void LeftOrder(Item* node)
{
    if (node->left)
        LeftOrder(node->left);
    printf("%s\n", node->data);
    if (node->right)
        LeftOrder(node->right);
}

/* Обход дерева Справа */
void RightOrder(Item* node)
{
    if (node->right)
        RightOrder(node->right);
    
    printf("%s\n", node->data);
    if (node->left)
        RightOrder(node->left);
}



int main()
{
    srand(time(NULL));
    int counter = 0;
    char str[30];

    Item *node = NULL;


    printf("Input words\n");

    fgets(&str, 30, stdin);

    char* pch = strtok(str, " ,.-\\n"); // во втором параметре указаны разделитель (пробел, запятая, точка, тире)
    
    while (pch != NULL)
    {

        AddNode(pch, &node);
        counter++;

        printf("Key %d - %s\n",counter,  pch);

        pch = strtok(NULL, " ,.-");
    }

    printf("LEFT Order:\n");
    LeftOrder(node);

    printf("RIGHT Order:\n");
    RightOrder(node);


}

