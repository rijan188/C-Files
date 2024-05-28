#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_elements, *ptr, i;

  // Get the number of elements to allocate
  printf("Enter the number of elements to allocate: ");
  scanf("%d", &num_elements);

  // Allocate memory dynamically using malloc
  ptr = (int*)malloc(num_elements * sizeof(int));

  // Check if memory allocation was successful
  if (ptr == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  // Access and modify elements using the allocated memory
  printf("Enter %d elements:\n", num_elements);
  for (i = 0; i < num_elements; i++) {
    scanf("%d", ptr + i);
  }

  // Print the allocated elements
  printf("The allocated elements are: ");
  for (i = 0; i < num_elements; i++) {
    printf("%d ", *(ptr + i));
  }
  printf("\n");

  // Deallocate the memory using free
  free(ptr);
  printf("Memory deallocated successfully.\n");

  return 0;
}
