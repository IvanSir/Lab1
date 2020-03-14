#include <stdio.h>
#include <conio.h>
#include <math.h>

#define FLT_MAX 100
#define FLT_MIN -100

float a,b,c;

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

void Vvod(){
int x1 , y1 , x2 , y2 , x3 , y3, count;

	do
	{
		count = 0;

		x1 = Examine("Input x of 1 spot : \n");
		y1 = Examine("Input y of 1 spot : \n");

		x2 = Examine("Input x of 2 spot : \n");
		y2 = Examine("Input y of 2 spot : \n");

		x3 = Examine("Input x of 3 spot : \n");
		y3 = Examine("Input y of 3 spot : \n");

		a = sqrt((double)((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
		b = sqrt((double)((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3)));
		c = sqrt((double)((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)));

		double k, d;
		int checkY = y3;
		int checkX = x3;
		if (x1 != x2 && x1 != x3)
		{
			 k = (double)(y2- y1)/(x2-x1) ;
			 d = y2 - k*x2;
		}

		else if (x1 != x3)
		{
			k = (double)(y3- y1)/(x3-x1) ;
			d = y3 - k*x3;
			checkY = y2;
			checkX = x2;
		}



		if ((a + b <= c) || (a + c <= b) || (b + c <= a) || (checkY == k * checkX + d))
		{
			printf("This triangle doesn't exist ! Try again\n");
			count++;
		}


	}while (count>0);
    getch();
	system("CLS");


}

void Type(double a, double b, double c)
{
	if (a == b && b == c)
	{
		printf("Equilateral triangle\n");
	}

	else if (( a == b && a != c )||( b == c && b != a ) || ( a == c && a != b ))
	{
		printf("Isosceles triangle\n");
	}

	else
		printf("An arbitrary triangle\n");

	if ((a == sqrt(b * b + c * c)) ||(b == sqrt(a * a + c * c))
								   ||(c == sqrt(b * b + a * a)))

	  printf("Rectangular triangle\n");
      getch();
	  system("CLS");


}

float Area(float a, float b, float c)
{
	float halfP = (a+b+c)/2;

	return sqrt(halfP*(halfP - a)* (halfP - b )*( halfP - c));

}

float Perimeter()
{
	return a+b+c;
}

void Radius()
{
	printf("Radius of the circumscribed circle is %f,"
			" Radius of the inscribed circle is %f\n",
			((a*b*c)/(4*Area(a,b,c))), ((2*Area(a,b,c)/(a+b+c))));
    getch();
	system("CLS");
}

int Order(int counter)
{
	if (counter == 0)
	{
		printf("Input parameters first.");
		getch();
		return 0;
	}

	else
		return 1;
}

int main()
{
	char choice;
	int counter = 0;

	do
	{
		do
		{   	 system("CLS");
			printf(" Menu:\n 1 - Input 3 spots\n 2 - Type of Triangle\n 3 - Perimeter\n"
			" 4 - Area\n 5 - Radiuses\n 6 - Info/Version\n 7 - Exit\n ");



		}
		while ( ( choice = getch()) <'1' && choice > '7' );

		switch(choice)
		{
		case '1' :
			Vvod();
			counter++;
			break;


		case '2' :
			if (Order(counter))
				Type(a, b, c);


			break;

		case '3' :
			if (Order(counter))
			{
				printf("Perimeter is %f\n" ,Perimeter());
				getch();
				system("CLS");
			}
			break;

		case '4' :
			if (Order(counter))
			{
				printf("Area is %f\n" ,Area(a,b,c));
				getch();
				system("CLS");
			}
			break;

		case '5' :
			if (Order(counter))
				Radius();

			break;

		case '6' :
			printf("Avtory 0 let");
			getch();
			system("CLS");
			break;

		case 7 :
			return 0;
			break;
		}

	}
	while(choice!='7');



}
