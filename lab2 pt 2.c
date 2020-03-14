#include <stdio.h>
#include <math.h>
#include <conio.h>

#define FLT_MAX 1000
#define FLT_MIN 0.0000004
// Факториал числа
double fact(int n){
	if(n < 0)
		return 0;
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}

float  Examine(char *putout)
{
	float num;
	char temp = '\n';


	do
	{   int check = 0;
		printf("%s\n", putout);

		if (scanf("%f%c", &num, &temp) == 2 && temp == '\n')
		{
		   if (num > FLT_MIN && num < FLT_MAX)
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
			printf("Error. Input a number(float) \n");
		}



        rewind(stdin);
		getch();
		system("cls");
	}
	while(1);

	return num;
}

int main()
{
	int  n = 1;
	float y,s,x,e;
	float sum = 0;

	x = Examine("Input argument(x)\n");
	e = fabs(Examine("Input inaccuracy(e)\n"));
	x = (x * M_PI)/180;
	y = sin(x);


	do
	{
		s = (pow( x , 2*n-1) * pow( ( -1 ) , ( n - 1 ) ) )/fact(2 * n - 1);
		sum+=s;
		n++;
	}
	while(fabs(  y - sum)  >= e );

	printf("Y = %f and S = %f and n =%d\n",y,sum,n);

	getch();
	return 0;
}
