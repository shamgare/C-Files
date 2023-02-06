#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student{
	char name[100];
	int age;
};

int main()
{
	// Student[]= {isi}, {}, {isi}, {isi}, {isi};
	// Student* [] = { NULL, NULL,* {isi}, NULL };
	
	char names[][100]= {"Ghoran", "Delvin", "Daniel"};
	int ages[]= {20, 30, 15};
	
	Student* students[3];
	
	for (int i = 0; i < 3; i++)
	{
		students[i]= (Student*)malloc(sizeof(Student));
		strcpy(students[i]->name, names[i]);
		students[i]->age = ages[i];
		
		students[0] = NULL;
		
		if (students[i] != NULL)
		{
			printf("Index %d: %s, %d years old\n", i, students[i]->name, students[i]->age);
		}
		else
		{
			printf("index %d: NULL\n", i);
		}
		
		free(students[i]);
	}
	
	
	
	for(int i = 0; i < 3; i++)
	{
	}
	
	return 0;
}