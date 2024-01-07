#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_HD_D_SIZE 100

void number_to_binary();
void binary_to_number();
void decimal_to_hexa_decimal();
void hexa_decimal_to_decimal();
int hex_digit_to_decimal(char hex_digit);
void octal_to_decimal();
void decimal_to_octal();

int n_b = 0; // number  to binary
int b_n = 0; // binary to number
int d_hd = 0; // decimal to hexa decimal 
int o_d = 0; // octal to decimal
int d_0 = 0; // deicmal to octal
char hd_d[MAX_HD_D_SIZE]; // Déclarez avec une taille fixe  hexa decimal to decimal 

int main(void) {
    int choice;

    do {
        printf("Converter binary\n");
        printf("1- Number to binary\n");
        printf("2- Binary to number\n");
        printf("3- Decimal to Hexadecimal\n");
        printf("4- Hexadecimal to decimal\n");
        printf("5- decimal to octal\n");
        printf("6- octal to decimal\n");

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
            case 3:
                printf("Enter the decimal number: ");
                scanf("%d", &d_hd);
                decimal_to_hexa_decimal();
                break;
            case 4:
                printf("Enter the hexadecimal number: ");
                scanf("%s", hd_d);
                hexa_decimal_to_decimal();
                break;
            case 5:
                printf("Enter the decimal number: ");
                scanf("%d", &d_0);
                decimal_to_octal();
                break;
            case 6:
                printf("Enter the hexadecimal number: ");
                scanf("%d", &o_d);
                octal_to_decimal();
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
        i_b_t = j;// la fonction s'arretera une fois que le pow(i, j) sera plus grand que le nombre ducoup la puissance j sera la plus proche de n_b.
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

void decimal_to_hexa_decimal(){
     int quotient;
    int remainder;
    int i = 1;
    char hexadecimalNumber[100];

    quotient = d_hd;

    while (quotient != 0) {
        remainder = quotient % 16;

        // si le reste est plus petit que 10 alors il reste le chiffre en question on ajoute le reste plus 'O' qui 48 en ascii et le resultat de l'addition donnera le reste en question en valeur ascii qu'on transformera en chiffre decimal.
        if (remainder < 10)
            hexadecimalNumber[i++] = remainder + '0';
        // si le reste est plus grand que 10 il appartient a la 2 eme partit d'un nombre de base 16 les lettre de A a F le remainder plus la valeur ascii de 'A' - 10 donnera la valeur ascii de la lettre corespondante qu'on transformera en lettre.
        else
            hexadecimalNumber[i++] = remainder + 'A' - 10;

        quotient = quotient / 16;
    }

    // Afficher le résultat en ordre inverse
    printf("La représentation hexadécimale est : ");
    for (int j = i - 1; j > 0; j--)
        printf("%c", hexadecimalNumber[j]);

    printf("\n");
    
}
int hex_digit_to_decimal(char hex_digit) {
    if (hex_digit >= '0' && hex_digit <= '9') {
        return hex_digit - '0';
    } else if (hex_digit >= 'A' && hex_digit <= 'F') {
        return hex_digit - 'A' + 10; // par c c'est sont assci c'est 67 - 65 = 2 + 12 et et la valeur de la lettre c dans le systeme de base 16
    } else if (hex_digit >= 'a' && hex_digit <= 'f') {
        return hex_digit - 'a' + 10;
    } else {
        // Gérer le cas d'un caractère hexadécimal invalide
        printf("Caractère hexadécimal invalide: %c\n", hex_digit);
        return 0;
    }
}
void hexa_decimal_to_decimal() {
    int lenght_dh_d = strlen(hd_d);
    int i = 0;
    int number = 0;

    for (i = lenght_dh_d - 1; i >= 0; --i) {
        number += hex_digit_to_decimal(hd_d[i]) * pow(16, lenght_dh_d - 1 - i);
    }

    printf("%d\n", number);
}
void octal_to_decimal() {
    const char *o_d;
    int decimal = 0;
    int length = strlen(o_d);

    for (int i = length - 1, position = 0; i >= 0; i--, position++) {
        if (o_d[i] < '0' || o_d[i] > '7') {
            printf("Caractère octal invalide: %c\n", o_d[i]);
            return;
        }

        int digit = o_d[i] - '0';
        decimal += digit * pow(8, position);
    }

    printf("Le nombre décimal correspondant est : %d\n", decimal);
}
void decimal_to_octal()
{
    while (d_0 != 0) {
        int remainder = d_0 % 8;
        printf("%d", remainder);
        d_0 = d_0 / 8;
    }
    
}

