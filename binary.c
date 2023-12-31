#include <stdio.h>
#include <math.h>

void number_to_binary();
void binary_to_number();

int n_b = 0;
int b_n = 0;

int main(void) {
    int choice;

    do {
        printf("Converter binary\n");
        printf("1- Number to binary\n");
        printf("2- Binary to number\n");
        printf("0- Exit\n");
        printf("Enter an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &n_b);
                number_to_binary();
                break;
            case 2:
                printf("Enter the binary: ");
                scanf("%d", &b_n);
                binary_to_number();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please enter a valid option.\n");
        }

        if (choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); // Consume the newline character
            getchar(); // Wait for Enter key
            printf("\033[H\033[J"); // Clear the terminal
        }

    } while (choice != 0);

    return 0;
}

void number_to_binary() {
    int j = 0;
    int i_b_t = 0;


    for (int j = 0; pow(2, j) <= n_b; j++) {
        i_b_t = j;
    }
    for (int i = i_b_t; i >= 0; i--) {
        int binary_basic_two = pow(2, i);

        if (n_b >= binary_basic_two) {
            n_b -= binary_basic_two;
            printf("%d", 1);
        } else {
            printf("%d", 0);
        }
    }
    printf("\n");
}

void binary_to_number() {
    int j = 0;
    int number = 0;

    while (b_n > 0) {
        int bit = b_n % 10;
        number += bit * pow(2, j);
        b_n /= 10;
        j++;
    }
    printf("%d\n", number);
}
