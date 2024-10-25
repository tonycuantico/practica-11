
#include <stdio.h>
#include<stdio.h>
void incremento();
/* La variable enteraGlobal es vista por todas
las funciones (main e incremento) */
int enteraGlobal;
int main()
{
// La variable cont es local a la función main
int cont;
enteraGlobal = 0; // La función main accede a la variable global
for (cont=0 ; cont<5 ; cont++)
{
incremento();
}
return 999;
}
void incremento()
{
// La variable enteraLocal es local a la función incremento
int enteraLocal = 5;
enteraGlobal += 2;
printf("global(%i) + local(%i) = %d\n",enteraGlobal, enteraLocal, enteraGlobal+enteraLocal);

}
