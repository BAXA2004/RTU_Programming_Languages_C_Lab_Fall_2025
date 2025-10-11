/*
 * week4_3_struct_database.c
 * Author: [Your Name]
 * Student ID: [Your ID]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Define struct Student with fields name, id, grade
struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int n;
  struct Student *students = NULL;

  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  // TODO: Allocate memory for n Student structs using malloc
  students = (struct Student *)malloc(n * sizeof(struct Student));
  if (students == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // TODO: Read student data in a loop
  for (int i = 0; i < n; i++) {
    printf("\nEnter info for student #%d:\n", i + 1);

    printf("Name: ");
    scanf(" %49[^\n]", students[i].name);  // Read string with spaces

    printf("ID: ");
    scanf("%d", &students[i].id);

    printf("Grade: ");
    scanf("%f", &students[i].grade);
  }

  // TODO: Display all student records in formatted output

  // Optional: Compute average grade or find top student

  // TODO: Free allocated memory

  printf("\n--- Student Records ---\n");
  for (int i = 0; i < n; i++) {
    printf("Student #%d\n", i + 1);
    printf("Name: %s\n", students[i].name);
    printf("ID: %d\n", students[i].id);
    printf("Grade: %.2f\n", students[i].grade);
    printf("----------------------\n");
  }

  // Free allocated memory
  free(students);

  return 0;
}
