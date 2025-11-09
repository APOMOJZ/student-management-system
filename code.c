#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

void input(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
}

void display(struct Student s[], int n) {
    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s %-10.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
}

int partition(struct Student s[], int low, int high) {
    int pivot = s[high].roll;
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (s[j].roll < pivot) {
            i++;
            struct Student temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
    struct Student temp = s[i + 1];
    s[i + 1] = s[high];
    s[high] = temp;
    return i + 1;
}

void quickSort(struct Student s[], int low, int high) {
    if (low < high) {
        int pi = partition(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

void binarySearch(struct Student s[], int n, int key) {
    int low = 0, high = n - 1, found = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (s[mid].roll == key) {
            printf("\nRecord Found:\nRoll No: %d\nName: %s\nMarks: %.2f\n",
                   s[mid].roll, s[mid].name, s[mid].marks);
            found = 1;
            break;
        } else if (s[mid].roll < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (!found)
        printf("\nRecord not found.\n");
}

int main() {
    struct Student s[MAX];
    int n, choice, key;

    printf("Enter number of students: ");
    scanf("%d", &n);

    input(s, n);

    while (1) {
        printf("\n---- Student Record Management System ----\n");
        printf("1. Display Records\n");
        printf("2. Sort by Roll (Quick Sort)\n");
        printf("3. Search by Roll (Binary Search)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(s, n);
                break;
            case 2:
                quickSort(s, 0, n - 1);
                printf("\nRecords sorted using Quick Sort.\n");
                break;
            case 3:
                printf("\nEnter Roll Number to search: ");
                scanf("%d", &key);
                printf("\n(Note: Make sure records are sorted before using Binary Search)\n");
                binarySearch(s, n, key);
                break;
            case 4:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
}
