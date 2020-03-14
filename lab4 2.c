#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
   char name[10];
   char surn[15];
};

void sortname(struct Student  *uk, int n)//struct_data - тип данных структуры,  n - количество элементов структуры
{
	struct Student tmp;//для временного хранения при сортировке
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<n-1; i++)
        {
			if(stricmp(uk[i].surn, uk[i+1].surn)>0)
            {
				tmp = uk[i];
                uk[i] = uk[i+1];
                uk[i+1] = tmp;
            }
        }
    }
}

int main()
{
	struct Student group[30];

	FILE *fp;
	fp = fopen("student.txt", "r");
	if (!fp) exit(1);

	for (int i = 0; i < 30; i++)
	{
	fscanf(fp,"%s %s",group[i].surn, group[i].name);
	}

	sortname(*&group,30);

	for (int i = 0; i < 30; i++) {
		printf("%s %s \n", group[i].surn,group[i].name);

	}





    getch();

	return 0;
}
