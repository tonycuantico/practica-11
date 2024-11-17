/* Rdoriguez Arreguin Luis Antonio
Practica 11 - ejercicio examen*/

#include <stdio.h>
#include <stdlib.h>
#define a 10
#define b 100

void read_comp(int arr[a][b])
{
    int i,j;
    int total, comp;

    //Inicializacion de la matriz
    for(i = 0; i < a; i++)
        for(j = 0; j < b; j++)
            arr[i][j] = 0;
    printf("La matriz se inicializo\n");

    //Lectura de datos
    printf("Introducir el numero de componentes por aparato.\n");
    for(i = 0; i < a; i++)
    {
        printf("Total de componentes del aparato %d: ", i+1);
        scanf("%d", &total);
        for(j = 0; j < total; j++)
        {
            printf("Posición del componente %d: ", j+1);
            scanf("%d", &comp);
            arr[i][comp] = 1;
        }
    }
}

void read_month(int arr[a][b], int arr2[])
{
    int i, j, temp;

    printf("Introducir el numero de aparatos fabricados mensualmente.\n");
    //Lectura de datos mensuales
    for(i = 0; i < a; i++)
    {
        temp  = 0;
        for(j = 0; j < b; j++)
        {
            temp = temp + arr[i][j];
        }
        if (temp != 0)
        {
            printf("Aparato %d: ", i+1);
            scanf("%d", &arr2[i]);
        }
    }
}

void total_month(int arr[a][b], int month[], int total[])
{
    int i, j;
    //Inicializacion del arreglo
    for(i = 0; i < b; i++)
    {
        total[i] = 0;
    }

    //Calculo de los componentes mensuales
    printf("Numero de unidades de cada componente utilizados mensualmente.\n");
    for(i = 0; i < b; i++)
    {
        for(j = 0; j < a; j++)
        {
            total[i] = total[i] + (arr[j][i] * month[j]);
        }
        if(total[i] != 0)
        {
            printf("Componente %d: %d\n", i, total[i]);
        }
        
    }
}

void max_comp(int total[])
{
    int i, comp, max = 0;
    for(i = 0; i < 100; i++)
    {
        if(max < total[i])
        {
            max = total[i];
            comp = i;
        }
    }
    printf("El componente electronico %d es el mas utilizado, se necesitan %d unidades.", comp, max);
}   

int main (int argc, char *argv )
{
    int arr[a][b];
    int month[a], total[b];

    read_comp(arr);
    printf("\n\n");
    read_month(arr, month);
    printf("\n\n");
    total_month(arr, month, total);
    printf("\n\n");
    max_comp(total);
    return 0;
}
