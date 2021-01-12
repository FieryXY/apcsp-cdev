#include <stdio.h>



// student structure
//struct Student...
struct Student {
	char firstName[50];
	char lastName[50];
	int age;
	int studentId;
};


void printStudent(struct Student* student)
{
	printf("%s %s. Age: %d, ID: %d\n", student->firstName, student->lastName, student->age, student->studentId);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for(int i = 0; i < num; ++i) {
	  printStudent(&(students[i]));
  }
}


int main()
{

  // an array of students
  //xxx students;
  struct Student students[256];

  int numStudents = 0;
  char input[256];
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q')
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
	  struct Student newStudent;
	  printf("Enter first name: ");
	  fgets(input, 256, stdin);
	  sscanf(input, "%s", &(newStudent.firstName));
	  printf("Enter last name: ");
	  fgets(input, 256, stdin);
	  sscanf(input, "%s", &(newStudent.lastName));
	  printf("Enter age: ");
	  fgets(input, 256, stdin);
	  if(!sscanf(input, "%d", &(newStudent.age))) {
		  printf("Invalid input");
		  break;
	  }
	  printf("Enter student id: ");
	  fgets(input, 256, stdin);
	  if(!sscanf(input, "%d", &(newStudent.studentId))) {
		  printf("Invalid input");
		  break;
	  }
	  students[numStudents] = newStudent;
	        numStudents++;
    }
  }

  printf("\nGoodbye!\n");
}