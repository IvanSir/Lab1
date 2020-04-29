/* Task: Create a database of Workers/Vacancies like jobs.tut.by.
		 After deleting Worker/Vacancy add them to a .txt file
		 Search/Add/Remove/Help buttons.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {false , true } bool;

typedef enum  { Male, Female } Gender;

typedef enum  {None, Middle, High} Education;

typedef enum {Single, Married, Dating} FamStatus;


// Clears Console
void clrscr(void)
{
	printf("\033[2J"); /* Clear the entire screen. */
	printf("\033[0;0f"); /* Move cursor to the top left hand corner
	*/
}


// Info about workers
typedef struct
{
	char name[15];
	int age;
	char phoneNumber[14];
	Gender gender;
	char speciality[20];
	Education education;
	FamStatus famStatus;
	char city[20];
	int salary;

}WorkerInfo;


// Info about vacancies
typedef struct
{
	char company[15];
	char city[20];
	char position[15];
	Gender gender;
	char speciality[20];
	Education education;
	FamStatus famStatus;
	int age;
	int salary;

}VacancyInfo;


// Node wrk
typedef struct
{
	WorkerInfo info;
	struct Worker* prev, * next;

} Worker;


// Node vac
typedef struct 
{
	VacancyInfo info;
	struct Vacancy* prev, * next;

} Vacancy;

// LIST of Workers
typedef struct
{
	int size;
	Worker* head;
	Worker* tail;
}Workers;


// LIST of Vacancies
typedef struct
{
	int size;
	Vacancy* head;
	Vacancy* tail;

}Vacancies;



// Work with Lists//////

Vacancies* createVacList() {
	Vacancies* tmp = (Vacancies*)malloc(sizeof(Vacancies));
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;

	return tmp;
}

Workers* createWorList() {
	Workers* tmp = (Workers*)malloc(sizeof(Workers));
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;

	return tmp;
}


void deleteLists(Vacancies** listV, Workers** listW) {
	Vacancy* tmp = (*listV)->head;
	Vacancy* next = NULL;
	while (tmp) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*listV);
	(*listV) = NULL;

	Worker* temp = (*listW)->head;
	Workers* nex = NULL;
	while (temp) {
		nex = temp->next;
		free(temp);
		temp = nex;
	}
	free(*listW);
	(*listW) = NULL;
}

void pushVac( Vacancies* list, VacancyInfo info) {
	Vacancy* tmp = (Vacancy*)malloc(sizeof(Vacancy));
	if (tmp == NULL) {
		exit(1);
	}
	tmp->info = info;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head) {
		list->head->prev = tmp;
	}
	list->head = tmp;

	if (list->tail == NULL) {
		list->tail = tmp;
	}
	list->size++;
}

void pushWrk(Workers* list, WorkerInfo info) {
	Worker* tmp = (Worker*)malloc(sizeof(Worker));
	if (tmp == NULL) {
		exit(1);
	}
	tmp->info = info;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head) {
		list->head->prev = tmp;
	}
	list->head = tmp;

	if (list->tail == NULL) {
		list->tail = tmp;
	}
	list->size++;
}

WorkerInfo popFWrk(Workers* list) {
	Worker* prev;
	WorkerInfo tmp;
	if (list->head == NULL) {
		exit(2);
	}

	prev = list->head;
	list->head = list->head->next;
	if (list->head) {
		list->head->prev = NULL;
	}
	if (prev == list->tail) {
		list->tail = NULL;
	}
	tmp = prev->info;
	free(prev);

	list->size--;
	return tmp;
}

WorkerInfo popBWrk(Workers* list) {
	Worker* next;
	WorkerInfo tmp;
	if (list->tail == NULL) {
		exit(4);
	}

	next = list->tail;
	list->tail = list->tail->prev;
	if (list->tail) {
		list->tail->next = NULL;
	}
	if (next == list->head) {
		list->head = NULL;
	}
	tmp = next->info;
	free(next);

	list->size--;
	return tmp;
}

char* EducationPicker(int key)
{
	switch (key)
	{
	case 0: return "None";
	case 1: return "Middle";
	case 2: return "High";
	default: return "None";
	}
}

char* StatusPicker(int key)
{
	switch (key)
	{
	case 0: return "Single";
	case 1: return "Married";
	case 2: return "Dating";
	default: return "Single";
	}
}

char* GenderPicker(int key)
{
	switch (key)
	{
	case 0: return "Male";
	case 1: return "Female";
	default: return "Male";
	}
}

VacancyInfo popBVac(Vacancies* list) {
	Vacancy* next;
	VacancyInfo tmp;
	if (list->tail == NULL) {
		exit(4);
	}

	next = list->tail;
	list->tail = list->tail->prev;
	if (list->tail) {
		list->tail->next = NULL;
	}
	if (next == list->head) {
		list->head = NULL;
	}
	tmp = next->info;
	free(next);

	list->size--;
	return tmp;
}

VacancyInfo popFVac(Vacancies* list) {
	Vacancy* prev;
	VacancyInfo tmp;
	if (list->head == NULL) {
		exit(2);
	}

	prev = list->head;
	list->head = list->head->next;
	if (list->head) {
		list->head->prev = NULL;
	}
	if (prev == list->tail) {
		list->tail = NULL;
	}
	tmp = prev->info;
	free(prev);

	list->size--;
	return tmp;
}


Vacancy* getVac(Vacancies* list, int index) {
	Vacancy* tmp = list->head;
	int i = 0;

	while (tmp && i < index) {
		tmp = tmp->next;
		i++;
	}

	return tmp;
}

Worker* getWrk(Workers* list, int index) {
	Worker* tmp = list->head;
	int i = 0;

	while (tmp && i < index) {
		tmp = tmp->next;
		i++;
	}

	return tmp;
}

void deleteWrk(Workers* wrks,int index)
{
	FILE* fp;
	fopen_s(&fp, "C:\\Users\\asus\\Desktop\\Workers.txt", "a");
	if (!fp) exit(1);


	if (index == 0) {

		WorkerInfo info = popFWrk(wrks);
		
		char* status = StatusPicker((int)info.famStatus);
		char* educ =  EducationPicker((int)info.education);
		char* gen = GenderPicker((int)info.gender);
		fprintf_s(fp, "%s %d %s %s %s %d %s %s %s", info.name, info.age, info.city, info.phoneNumber, info.speciality, info.salary, status,educ,gen);
	}

	else if (index == wrks->size - 1 || index > wrks->size)
	{
	
		WorkerInfo info = popBWrk(wrks);

		char* status = StatusPicker((int)info.famStatus);
		char* educ = EducationPicker((int)info.education);
		char* gen = GenderPicker((int)info.gender);
		fprintf_s(fp, "%s %d %s %s %s %d %s %s %s", info.name, info.age, info.city, info.phoneNumber, info.speciality, info.salary, status, educ, gen);
	
	}

	else if (index <= wrks->size / 2)
	{
		Worker* previous = wrks->head;
		for (int i = 0; i < index - 1; i++)

		{
			previous = previous->next;
		}

		Worker* toDelete = previous->next;


		WorkerInfo info = toDelete->info;

		char* status = StatusPicker((int)info.famStatus);
		char* educ = EducationPicker((int)info.education);
		char* gen = GenderPicker((int)info.gender);
		fprintf_s(fp, "%s %d %s %s %s %d %s %s %s", info.name, info.age, info.city, info.phoneNumber, info.speciality, info.salary, status, educ, gen);

		previous->next = toDelete->next;
		Worker* next = toDelete->next;
		free(toDelete);
		next->prev = previous;

		wrks->size--;
	}

	else if (index > wrks->size / 2)
	{
		Worker* next = wrks->tail;
		for (int i = wrks->size - 1; i > index + 1; i--)
		{
			next = next->prev;
		}

		Worker* toDelete = next->prev;

		WorkerInfo info = toDelete->info;

		char* status = StatusPicker((int)info.famStatus);
		char* educ = EducationPicker((int)info.education);
		char* gen = GenderPicker((int)info.gender);
		fprintf_s(fp, "%s %d %s %s %s %d %s %s %s", info.name, info.age, info.city, info.phoneNumber, info.speciality, info.salary, status, educ, gen);

		next->prev = toDelete->prev;
		Worker* previous = toDelete->prev;
		free(toDelete);
		previous->next = next;
		wrks->size--;
	}
}

void deleteVac(Vacancies* wrks, int index)
{

	FILE* fp;
	fopen_s(&fp, "C:\\Users\\asus\\Desktop\\Vacancies.txt", "a");
	if (!fp) exit(1);


	if (index == 0)
	{
		VacancyInfo info = popFVac(wrks);

		char* status = StatusPicker((int)info.famStatus);
		char* educ = EducationPicker((int)info.education);
		char* gen = GenderPicker((int)info.gender);
		fprintf_s(fp, "%s %d %s %s %s %d %s %s %s", info.company, info.age, info.city, info.position, info.speciality, info.salary, status, educ, gen);

	}
	else if (index == wrks->size - 1 || index > wrks->size)
	{
		VacancyInfo info = popBVac(wrks);

		char* status = StatusPicker((int)info.famStatus);
		char* educ = EducationPicker((int)info.education);
		char* gen = GenderPicker((int)info.gender);
		fprintf_s(fp, "%s %d %s %s %s %d %s %s %s", info.company, info.age, info.city, info.position, info.speciality, info.salary, status, educ, gen);
	}

	else if (index <= wrks->size / 2)
	{
		Vacancy* previous = wrks->head;
		for (int i = 0; i < index - 1; i++)

		{
			previous = previous->next;
		}

		Vacancy* toDelete = previous->next;

		VacancyInfo info = toDelete->info;

		char* status = StatusPicker((int)info.famStatus);
		char* educ = EducationPicker((int)info.education);
		char* gen = GenderPicker((int)info.gender);
		fprintf_s(fp, "%s %d %s %s %s %d %s %s %s", info.company, info.age, info.city, info.position, info.speciality, info.salary, status, educ, gen);

		previous->next = toDelete->next;
		Vacancy* next = toDelete->next;
		free(toDelete);
		next->prev = previous;

		wrks->size--;
	}

	else if (index > wrks->size / 2)
	{
		Vacancy* next = wrks->tail;
		for (int i = wrks->size - 1; i > index + 1; i--)
		{
			next = next->prev;
		}

		Vacancy* toDelete = next->prev;

		VacancyInfo info = toDelete->info;

		char* status = StatusPicker((int)info.famStatus);
		char* educ = EducationPicker((int)info.education);
		char* gen = GenderPicker((int)info.gender);
		fprintf_s(fp, "%s %d %s %s %s %d %s %s %s", info.company, info.age, info.city, info.position, info.speciality, info.salary, status, educ, gen);

		next->prev = toDelete->prev;
		Worker* previous = toDelete->prev;
		free(toDelete);
		previous->next = next;
		wrks->size--;


	}

	fclose(fp);
}

/////Work with List///

//Get Index
int GetIndexWrk(Workers* wrks)
{
	printf("Choose index \n");
	int key = 0;
	scanf_s("%d", &key);
	return key;
}

int GetIndexVac(Vacancies* vcns)
{
	printf("Choose index \n");
	int key = 0;
	scanf_s("%d", &key);
	return key;
}





void AddWorker(Workers* wrks)
{
	WorkerInfo info;
	printf("Hello ! Input your information\n");

	printf("Name :\n");
	fgets(info.name, 15, stdin);
	fflush(stdin);
	info.name[strcspn(info.name, "\n")] = '\0';

	printf("Phone Number :\n");
	fgets(info.phoneNumber, 15, stdin);
	fflush(stdin);
	info.phoneNumber[strcspn(info.phoneNumber, "\n")] = '\0';


	printf("City :\n");
	fgets(info.city, 15, stdin);
	fflush(stdin);
	info.city[strcspn(info.city, "\n")] = '\0';

	printf("Speciality :\n");
	fgets(info.speciality, 20, stdin);
	fflush(stdin);
	info.speciality[strcspn(info.speciality, "\n")] = '\0';
	
	printf("Age :\n");
	scanf_s("%d", &info.age);


	printf("Gender Male(0), Female(1) :\n");
	int inter;
	scanf_s("%d", &inter);
	info.gender = (Gender)inter;

	printf("Education None(0), Middle(1), High(2) :\n");
	scanf_s("%d", &inter);
	info.education = (Education)inter;

	printf("Family status Single(0), Married(1), Dating(2) :\n");
	scanf_s("%d", &inter);
	info.famStatus = (FamStatus)inter;

	printf("Salary in $ :\n");
	scanf_s("%d", &info.salary);

	fflush(stdin);

	pushWrk(wrks, info);

}

void AddVacancy(Vacancies* vcns)
{
	VacancyInfo info;
	printf("Hello ! Input your information\n");

	printf("Company :\n");
	fgets(info.company, 15, stdin);
	fflush(stdin);
	info.company[strcspn(info.company, "\n")] = '\0';

	printf("Position :\n");
	fgets(info.position, 15, stdin);
	fflush(stdin);
	info.position[strcspn(info.position, "\n")] = '\0';

	printf("City :\n");
	fgets(info.city, 15, stdin);
	fflush(stdin);
	info.city[strcspn(info.city, "\n")] = '\0';

	printf("Speciality :\n");
	fgets(info.speciality, 20, stdin);
	fflush(stdin);
	info.speciality[strcspn(info.speciality, "\n")] = '\0';

	printf("Age :\n");
	scanf_s("%d", &info.age);


	printf("Gender Male(0), Female(1) :\n");
	int inter;
	scanf_s("%d", &inter);
	info.gender = (Gender)inter;

	printf("Education None(0), Middle(1), High(2) :\n");
	scanf_s("%d", &inter);
	info.education = (Education)inter;

	printf("Family status Single(0), Married(1), Dating(2) :\n");
	scanf_s("%d", &inter);
	info.famStatus = (FamStatus)inter;

	printf("Salary in $ :\n");
	scanf_s("%d", &info.salary);


	pushVac(vcns, info);
}

void ChooseAdd(Workers* wrks, Vacancies* vcns) 
{
	while (true)
	{
		clrscr();
		printf("1 - Add Worker\n2 - Add Vacancy\n3 - Back");
		switch (getch())
		{
		case '1': clrscr(); AddWorker(wrks); return;
		case '2': clrscr(); AddVacancy(vcns); return;
		case '3': return;
		}
	}

}




void PrintWorker(Workers* list) {
	Worker* tmp = list->head;
	int index = 0;
	while (tmp) {
		printf("\n");
		printf("num.%d\nName - %s\n",index, tmp->info.name);
		printf("Age - %d\n", tmp->info.age);
		printf("Phone Number - %s\n", tmp->info.phoneNumber);
		printf("Gender - %s\n", GenderPicker(tmp->info.gender));
		printf("Education - %s\n", EducationPicker(tmp->info.education));
		printf("City - %s\n", tmp->info.city);
		printf("Family status - %s\n", StatusPicker(tmp->info.famStatus));
		printf("Speciality - %s\n", tmp->info.speciality);
		printf("Salary - %d $\n", tmp->info.salary);
		tmp = tmp->next;
		index++;
	}
	printf("\n");
}


void PrintVacancy(Vacancies* list) {
	Vacancy* tmp = list->head;
	int index = 0;
	while (tmp) {
		printf("\n");
		printf("num.%d\nCompany - %s\n",index, tmp->info.company);
		printf("Age - %d\n", tmp->info.age);
		printf("Position - %s\n", tmp->info.position);
		printf("Gender - %s\n", GenderPicker(tmp->info.gender));
		printf("Education - %s\n", EducationPicker(tmp->info.education));
		printf("City - %s\n", tmp->info.city);
		printf("Family status - %s\n", StatusPicker(tmp->info.famStatus));
		printf("Speciality - %s\n", tmp->info.speciality);
		printf("Salary - %d $\n", tmp->info.salary);
		tmp = tmp->next;
		index++;
	}
	printf("\n");
}


void Remove(Workers* wrks, Vacancies* vcns)
{
	printf("Delete\n1 - Worker\n2 - Vacancy");
	switch (getch())
	{
	case '1': clrscr(); PrintWorker(wrks); deleteWrk(wrks, GetIndexWrk(wrks)); break;
	case '2': clrscr(); PrintVacancy(vcns); deleteVac(vcns, GetIndexVac(vcns)); break;
	}
}

void ChoosePrint(Workers* wrks, Vacancies* vcns)
{
	while (true)
	{
		clrscr();
		printf("1 - Print Workers\n2 - Print Vacancies\n3 - Back");
		switch (getch())
		{
		case '1': clrscr(); PrintWorker(wrks); return;
		case '2': clrscr(); PrintVacancy(vcns); return;
		case'3': return;
		}
	}

}

void PrintSpecificWorker(Worker* tmp)
{
	printf("\n");
	printf("\nName - %s\n", tmp->info.name);
	printf("Age - %d\n", tmp->info.age);
	printf("Phone Number - %s\n", tmp->info.phoneNumber);
	printf("Gender - %s\n", GenderPicker(tmp->info.gender));
	printf("Education - %s\n", EducationPicker(tmp->info.education));
	printf("City - %s\n", tmp->info.city);
	printf("Family status - %s\n", StatusPicker(tmp->info.famStatus));
	printf("Speciality - %s\n", tmp->info.speciality);
	printf("Salary - %d $\n", tmp->info.salary);
	tmp = tmp->next;

}

void PrintSpecificVacancy(Vacancy* tmp)
{
	printf("\n");
	printf("\nCompany - %s\n", tmp->info.company);
	printf("Age - %d\n", tmp->info.age);
	printf("Position - %s\n", tmp->info.position);
	printf("Gender - %s\n", GenderPicker(tmp->info.gender));
	printf("Education - %s\n", EducationPicker(tmp->info.education));
	printf("City - %s\n", tmp->info.city);
	printf("Family status - %s\n", StatusPicker(tmp->info.famStatus));
	printf("Speciality - %s\n", tmp->info.speciality);
	printf("Salary - %d $\n", tmp->info.salary);
	tmp = tmp->next;

}

void NameChosen(Workers* wrks) {

	clrscr();

	printf("Input name : ");
	char string[15];
	gets_s(string, 15);
	gets_s(string, 15);


	Worker* tmp= wrks->head;

	while (tmp) 
	{
		if (tmp->info.name == string)
		{
			PrintSpecificWorker(tmp);
			
		}
		tmp = tmp->next;
	}

}

void AgeChosen(Workers* wrks) {

	clrscr();

	printf("Input age : ");
	int string = 0;
	scanf_s("%d", &string);

	Worker* tmp = wrks->head;

	while (tmp)
	{
		if (tmp->info.age == string)
		{
			PrintSpecificWorker(tmp);
		
		}
		tmp = tmp->next;
	}

}

void SpecChosen(Workers* wrks) {

	clrscr();

	printf("Input speciality : ");
	char string[15];

	gets_s(string,15);
	gets_s(string, 15);

	Worker* tmp = wrks->head;

	while (tmp)
	{
		if (tmp->info.speciality == string)
		{
			PrintSpecificWorker(tmp);
			
		}
		tmp = tmp->next;
	}

}

void SalaryChosen(Workers* wrks) {

	clrscr();

	printf("Input salary : ");
	int string = 0;
	scanf_s("%d", &string);

	Worker* tmp = wrks->head;

	while (tmp)
	{
		if (tmp->info.salary == string)
		{
			PrintSpecificWorker(tmp);
			
		}
		tmp = tmp->next;
	}

}



void CompanyChosen(Vacancies* wrks) {

	clrscr();

	printf("Input company : ");
	char string[15];
	gets_s(string, 15);
	gets_s(string, 15);


	Vacancy* tmp = wrks->head;

	while (tmp)
	{
		if (tmp->info.company == string)
		{
			PrintSpecificVacancy(tmp);
			
		}
		tmp = tmp->next;
	}

}

void AgeVChosen(Vacancies* wrks) {

	clrscr();

	printf("Input age : ");
	int string = 0;
	scanf_s("%d", &string);

	Vacancy* tmp = wrks->head;

	while (tmp)
	{
		if (tmp->info.age == string)
		{
			PrintSpecificVacancy(tmp);
			
		}
		tmp = tmp->next;
	}

}

void PosChosen(Vacancies* wrks) {

	clrscr();

	printf("Input position : ");
	char string[15];


	gets_s(string, 15);
	gets_s(string, 15);

	Vacancy* tmp = wrks->head;

	while (tmp)
	{
		if (tmp->info.position == string)
		{
			PrintSpecificVacancy(tmp);

		}
		tmp = tmp->next;
	}

}

void WorkerInfoChoice(Workers* wrks) 
{
	clrscr();
	printf("Search by\n1 - Name\n2 - Age\n3 - Speciality\n4 - Salary\n5 - Back");
	switch (getch())
	{
	case '1': NameChosen(wrks); break;
	case '2': AgeChosen(wrks); break;
	case '3': SpecChosen(wrks); break;
	case '4': SalaryChosen(wrks); break;
	default: return;
		
	}
}

void VacancyInfoChoice(Vacancies* wrks)
{
	clrscr();
	printf("Search by\n1 - Company\n2 - Age\n3 - Speciality\n4 - Back");
	switch (getch())
	{
	case '1': CompanyChosen(wrks); break;
	case '2': AgeVChosen(wrks); break;
	case '3': PosChosen(wrks); break;
	default: return;

	}
}





void Help()
{
	printf("Hi there. This is my database of workers and vacancies.\n");
	printf("Add - Allows to add a worker's resume or a vacancy.\nRemove - Just removes your vacancy/resume\nView - Prints lists of workers and vacancies\n\nThanks for reading. Made by Ivan Ilyushchenka in 2020.");
}

void SearchFor(Workers* wrks, Vacancies* vcns)
{
	printf("Search for\n1 - Worker\n2 - Vacancy\n3 - Back");
	switch (getch())
	{
	case '1': WorkerInfoChoice(wrks); break;
	case '2': VacancyInfoChoice(vcns); break;
	default : return;
	}
}


void main()
{
	Workers* wrks = createWorList();
	Vacancies* vcns = createVacList();



	while (true)
	{
		clrscr();

		printf("Find your worker or job\n1 - Add\n2 - Remove\n3 - View\n4 - Help\n5 - Search\n6 - Exit");
		switch (getch()) 
		{
		case '1': clrscr(); ChooseAdd(wrks, vcns); getch(); break;
		case '2': clrscr(); Remove(wrks, vcns); break;
		case '3': clrscr(); ChoosePrint(wrks, vcns); getch(); break;
		case '4': clrscr(); Help(); getch(); break;
		case '5': clrscr(); SearchFor(wrks, vcns); getch(); break;
		case '6': return;
		}

	}
}