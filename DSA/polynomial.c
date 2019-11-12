  #include <stdio.h>
  #include <stdlib.h>

  struct polynomial {
        int power;
        float coeff;
  };

  int main() {
        struct polynomial *p1, *p2, *p3;
        int i, pow1, pow2, max, flag = 0;

        /* get the max powers of first and second polynomial */
        printf("Maximum power in first polynomial:");
        scanf("%d", &pow1);

        printf("Maximum power in second polynomial:");
        scanf("%d", &pow2);

        /* dynamic memory allocation for input polynomials */
        p1 = (struct polynomial *)calloc(sizeof(struct polynomial), pow1 + 1);
        p2 = (struct polynomial *)calloc(sizeof(struct polynomial), pow2 + 1);

        /* get the first polynomial input from the user */
        printf("Enter your input for first polynomial:\n");
        for (i = 0; i <= pow1; i++) {
                printf("%dX^%d => ", i , i);
                (p1 + i)->power = i;
                printf("Coefficient:");
                scanf("%f", &((p1 + i)->coeff));
        }

        /* get the second polynomial input from the user */
        printf("Enter your input for second polynomial:\n");
        for (i = 0; i <= pow2; i++) {
                printf("%dX^%d => ", i , i);
                (p2 + i)->power = i;
                printf("Coefficient:");
                scanf("%f", &((p2 + i)->coeff));
        }

        max = pow1 > pow2 ? pow1 : pow2;

        /* dynamically allocate memory for output polynomial */
        p3 = (struct polynomial *)calloc(sizeof(struct polynomial), max + 1);

        /* add given two polynomials and store the result in output polynomial */
        for (i = 0; i <= max; i++) {
                if (i <= pow1 && i <= pow2) {
                        (p3 + i)->power = (p1 + i)->power;
                        (p3 + i)->coeff = (p1 + i)->coeff + (p2 + i)->coeff;
                } else if (i <= pow1) {
                        (p3 + i)->power = (p1 + i)->power;
                        (p3 + i)->coeff = (p1 + i)->coeff;
                } else {
                        (p3 + i)->power = (p2 + i)->power;
                        (p3 + i)->coeff = (p2 + i)->coeff;
                }
        }

        /* print the results */
        printf("Sum of the given two polynomials:\n");
        for (i = max; i >= 0; i--) {
                if (flag)
                        printf(" + ");
                printf("%.1fX^%d", (p3 + i)->coeff, (p3 + i)->power);
                flag = 1;
        }
        printf("\n");
        return 0;
  }

