#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main

double areaOfCircle(double radius) {
 return M_PI*radius*radius;
}




int main(int argc, char* argv[])
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  float start = 5.2;
  int reps = 3;
	
	char buffer[256];

  if(argc < 3) {
	  printf("Enter start:\n");
	  if(fgets(buffer, sizeof(float), stdin) && sscanf(buffer, "%f", &start)) {
		  //...
	  }
	  else {
		  printf("Invalid Input");
		  return;
	  }
	  printf("Enter reps:\n");
	  if(fgets(buffer, sizeof(int), stdin) && sscanf(buffer, "%d", &reps)) {
		  //...
	  }
	  else {
		  printf("Invalid Input");
		  return;
	  }
  }
  else if (!(sscanf(argv[1], "%f", &start) && sscanf(argv[2], "%d", &reps))) {
	  printf("Invalid Input");
	  return;
  }

  printf("calculating area of circle starting at %f, and ending at %f\n", start, start+reps-1);

  // add your code below to call areaOfCircle function with values between
  // start and end

  for(float i = 0; i < reps; ++i) {
    printf("Area of circle with radius %f: %f\n", start+i, areaOfCircle(start+i));
  }




}