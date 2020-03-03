// Выводит числа, меньшие number, которые в двоичном коде единицы
#include <stdio.h>
#include <math.h>
#include <conio.h>

#define INT_MAX +32767
#define INT_MIN -32767

int  Examine(char *putout)
{
	int num;
	char temp = '\n';


	do
	{   int check = 0;
		printf("%s\n", putout);

		if (scanf("%d%c", &num, &temp) == 2 && temp == '\n')
		{
		   if (num > INT_MIN && num < INT_MAX)
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
		getch();
		system("cls");
	}
	while(1);

	return num;
}

void Result (int counter)
{
	for (int i = 1; i < counter; i++)
	{
		long long result  = 0;
		int answer = (pow(2 , i) - 1);

		for (int j = 0; answer > 0; j++)
		{
			result += (answer % 2) * pow(10, j);
			answer /= 2;
		}

		printf("%d) %d - %llu\n", i, (int)(pow(2, i) - 1), result);
	}
}


int main(void)
{
int number,counter = 1;

number = Examine("Input your number\n");

	while (pow(2 , counter) <= number)
	{
		counter++;
	}

Result(counter);

getch();
return 0;
}
