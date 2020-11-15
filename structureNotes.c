#include <stdio.h>

struct newStructure
{
	int x;
	double y;
};

typedef struct Student
{
	char *name;
	int age;
}  STUD;

void printInfo(STUD s);
void printInfoPtr(STUD*);

int main()
{

	struct newStructure geronimo;
	geronimo.x = 47;
	geronimo.y = 0;
	int z = geronimo.x + geronimo.y;

	struct newStructure tarzan;
	tarzan.x = 4;
	
	
	STUD student1;  // same as "struct student"
	student1.age = 20;
	student1.name = "Charlie";

	printf("%d %s\n", student1.age, student1.name);

	printInfo(student1);  // makes a copy - does not change original

	printInfoPtr(&student1); // changes original

	return 0;
}


void printInfo(STUD s)
{
	printf("%d %s\n", s.age, s.name);
	return;
}


void printInfoPtr(STUD *s)
{
	printf("%d %s\n", s->age, s->name);
	return;
}
