#include <stdio.h>
#include <math.h>

void number_to_binary();
void binary_to_number();


int n_b = 0;
int b_n = 0;
int main(void) {

    int n;
    printf("Convertor binary\n");
    printf("1- Number to binary\n");
    printf("2-binary to number\n");
    printf("Enter a option  : \n");
    scanf("%d", &n);
    printf("\033[H\033[J");  // Cette ligne efface le terminal (peut ne pas fonctionner sur tous les systèmes)


    if(n == 1)
    {
    
      printf("Enter the number\n");
      scanf("%d", &n_b);
      printf("\033[H\033[J");  // Cette ligne efface le terminal (peut ne pas fonctionner sur tous les systèmes)
      number_to_binary();
    }
    if(n == 2)
    {
    
      printf("Enter the binary \n");
      scanf("%d", &b_n);
      printf("\033[H\033[J");  // Cette ligne efface le terminal (peut ne pas fonctionner sur tous les systèmes)
      binary_to_number();
    }

    return 0;
}



void number_to_binary()
{
   //log2 vient nous donner le nombre d'iteration nessecaire pour arriver au nombre le plus proche de n_b mais plus petit que lui 
   for (int i = log2(n_b); i >= 0; i--) {

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

void binary_to_number()
{
    int j = 0; // Commencez avec le bit le moins significatif (j = 0)
    int number = 0;

    while (b_n > 0) {
        int bit = b_n % 10; // Obtenez le bit de droite
        number += bit * pow(2, j); // Ajoutez le bit à la somme

        b_n /= 10; // Déplacez-vous vers le bit suivant
        j++; // Augmentez le poids du bit
    }
    printf("%d", number);

}


