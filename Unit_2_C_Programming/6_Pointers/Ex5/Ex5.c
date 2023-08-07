#include <stdio.h>

struct employee {
  char *empName;
  int empId;
};

int main() {
  struct employee emp1 = {"Jhon", 1001};
  struct employee emp2 = {"Alex", 1002};
  struct employee emp3 = {"Taylor", 1003};

  struct employee *ptr[3] = {&emp1, &emp2, &emp3};
  
  printf("Employee Name : %s\n", ptr[0]->empName);
  printf("Employee ID : %d\n", ptr[0]->empId);

  return 0;
}
