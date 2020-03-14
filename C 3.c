#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>

int check;

#define INT_MAX +32767
#define INT_MIN -32767

int  Examine(char* putout)
{
	int num;
	char temp = '\n';


	do
	{
		int check = 0;
		printf("%s\n", putout);

		if (scanf_s("%d%c", &num, &temp) == 2 && temp == '\n')
		{
			if (num > INT_MIN&& num < INT_MAX)
			{
				break;
			}
			else
			{
				printf("Error. Number is too big \n");
			}
		}
		else
		{
			printf("Error. Input a number(int) \n");
		}

		rewind(stdin);
		_getch();
		system("cls");
	} while (1);

	return num;
}

void ArrayOutput(int** Array, int sizeStr, int sizeCol) 
{
	for (int i = 0; i < sizeStr; i++) 
	{
		for (int j = 0; j < sizeCol; j++) 
		{
			Array[i][j] = rand() % 2;
			
			printf(" %d ", Array[i][j]);
		}
		printf("\n");
	}
}

void NewArrayOutput(int** Array, int sizeStr, int sizeCol) 
{
	for (int i = 0; i < sizeStr; i++) {
		if (Array[i] != NULL) {
			for (int j = 0; j < sizeCol; j++) {
				if (Array[i][j] != 5)
					printf(" %d ", Array[i][j]);
			}
			printf("\n");
		}
	}

}

void StrSort(int** Array, int sizeStr, int sizeCol)
{

	int flag = 0;

	for (int i = 0; i < sizeStr; i++)
	{
		if (Array[i] != NULL) {
			for (int j = 0; j < sizeCol; j++)
			{
				if (Array[i][j] == 1) flag++;
			}

			if (flag == 1) {
				Array[i] = NULL;
				free(Array[i]);
				check = 1;
			}

			flag = 0;

		}
	}

}

void ColSort(int** Array, int sizeStr, int sizeCol)
{
	int flagStr = 0;
	
	for (int i = 0; i < sizeCol; i++)
	{
		for (int j = 0; j < sizeStr; j++)
		{
			if (Array[j] != NULL) {
				if (Array[j][i] == 1) {

					flagStr++;

				}

			}
		}

		if (flagStr == 1) {

			for (int j = 0; j < sizeStr; j++) {
				if (Array[j] != NULL)
					Array[j][i] = 5;
				check = 1;
			}
		}
		flagStr = 0;

	}

}

int main()
{
	int sizeStr = Examine("Strings : ");
	int sizeCol = Examine("Columns : ");
	srand(time(NULL));

	int** Array = (int**)malloc(sizeStr * sizeof(int*));
	for (int i = 0; i < sizeStr; i++) {

		Array[i] = (int*)malloc(sizeof(int*) * sizeCol);

	}
	
	ArrayOutput(Array, sizeStr, sizeCol);

	printf("\n");

	do {
		check = 0;
		StrSort(Array, sizeStr, sizeCol);

		ColSort(Array, sizeStr, sizeCol);
	} while (check == 1);
	
	NewArrayOutput(Array, sizeStr, sizeCol);

	return 0;
}