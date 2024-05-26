#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int size;
    int i;

    // Prompt user for the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Allocate memory for the array
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Exit the program if memory allocation fails
    }

    // Take input for the array elements
    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Print the array elements
    printf("The elements in the array are:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}
