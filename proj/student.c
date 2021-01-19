//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


int createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
   if(numStudents >= 100) {
      //In case array is full
      return 0;
   }

   Student* newStudent = (Student*) malloc(sizeof(Student));
  newStudent->firstName = (char*) malloc(strlen(fname)*sizeof(char));
  newStudent->lastName = (char*) malloc(strlen(lname)*sizeof(char));
  strcpy(newStudent->firstName, fname);
  strcpy(newStudent->lastName, lname);
  //Implicit Conversion between int and unsigned int
  newStudent->age = age;

  newStudent->id = (long) id;
 students[numStudents] = newStudent;
 ++numStudents;
return 1;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
   for(int i = 0; i < numStudents; ++i) {
      deleteStudent(students[i]);
   }
   numStudents = 0;
}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532
  FILE* data;
   data = fopen(STUFILE, "w+");
   char buf[700];
   for(int i = 0; i < numStudents; ++i) {
     Student* current = students[i];
     sprintf(buf, "%s %s %u %ld\n", current->firstName, current->lastName, current->age, current->id);
     caesarEncrypt(buf, key);
     printf("saving: %s\n", buf);
     fprintf(data, buf);
   } 
   fclose(data);
}


void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
 deleteStudents();
  FILE* data;
  data = fopen(STUFILE, "r");
  char fname[256];
  char lname[256];
  char buf[710];
  unsigned int age;
  long id;
  fgets(buf, 700, data);
  caesarDecrypt(buf, key);
  int counter = 0;
  while(sscanf(buf, "%s %s %u %ld\n", fname, lname, &age, &id) == 4) {
    if(createStudent(fname, lname, age, id)) {
        ++counter;
        fgets(buf, 700, data);
        caesarDecrypt(buf, key);
     }
     else {break;}
  }
  printf("Loaded %d students", counter);

}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




