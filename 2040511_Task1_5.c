#include <stdio.h>
#include <stdlib.h>


//compile with: cc 2040511_Task1_5.c -o 2040511_Task1_5

int main(){
int A, B, Btemp, C, Ctemp, D;

printf("\nEnter value for A \n");
scanf("%d", &A);
printf("\nEnter value for C \n");
scanf("%d", &Ctemp);
printf("\nEnter value for D \n");
scanf("%d", &D);

Btemp = A + Ctemp;
B = Ctemp+D;
C=Ctemp+2*D;

printf("The value for B is %d\n", B);

printf("The new value for C is %d\n", C);

return (0);

}
