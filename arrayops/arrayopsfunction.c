#include <stdio.h>
#define MAX 100

int insert(int arr[], int n, int pos, int elem) {
    int i;
    if (n >= MAX || pos < 0 || pos > n)
        return n;
    for (i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = elem;
    return n + 1;
}

int delete(int arr[], int n, int pos) {
    int i;
    if (n == 0 || pos < 0 || pos >= n)
        return n;
    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}

void display(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX], n, choice, pos, elem;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
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
                printf("Enter element to insert: ");
                scanf("%d", &elem);
                n = insert(arr, n, pos, elem);
                printf("Element inserted.\n");
                break;

            case 2:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                n = delete(arr, n, pos);
                printf("Element deleted.\n");
                break;

            case 3:
                printf("Array elements: ");
                display(arr, n);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
