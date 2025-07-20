#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX], n, choice, pos, elem, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element at a given position\n");
        printf("2. Delete element from a given position\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position to insert (0 to %d): ", n);
                scanf("%d", &pos);
                
                if (pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }
                
                printf("Enter element to insert: ");
                scanf("%d", &elem);
                
                for (i = n; i > pos; i--)
                    arr[i] = arr[i - 1];
                    
                arr[pos] = elem;
                n++;
                
                printf("Element inserted.\n");
                break;

            case 2:
                if (n == 0) {
                    printf("Array is empty. Cannot delete.\n");
                    break;
                }
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                    break;
                }
                for (i = pos; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;
                printf("Element deleted.\n");
                break;

            case 3:
                printf("Array elements: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
