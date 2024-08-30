#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ej5a(int a[],int n); //Inicializar al azar los primeros N numeros
void ej5b(int a[],int n); //Ordenar ascendente primeros N numeros
int ej5c(int a[],int n); //Verificar si N numeros está ordenado en forma ascendente
int* ej5d(int a1[], int a2[], int tA,int tB); //Intercalar a1 y a2 para ordenarla en forma ascendente sin repeticion y mandarlo
                                                // a A

int main()
{
   int a[20];

   return 0;
}

void ej5a(int a[],int n)
{
    int i;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        a[i] = rand()%80;
    }
}
void ej5b(int a[],int n)
{
    int i;
    int fin = n-1;
    int aux;
    for(i=0;i<fin;i++)
    {
        if(a[i]>a[i+1])
        {
            aux = a[i+1];
            a[i] = a[i+1];
            a[i+1] = aux;
        }
    }
}
int ej5c(int a[],int n)
{
    int verdad = 1;
    int i;
    for(i=0;(i<n-1)&&verdad;i++)
    {
        if(a[i]>a[i+1])
            verdad = 0;
    }

    return verdad;
}
int* ej5d(int a1[],int a2[],int tA, int tB)
{
    int cont=0;
    int recorrer;
    int j=0;
    int i=0;
    int c;
    int* pA = (int*)malloc((tA+tB)*sizeof(int));

    if(tA<=tB)
        recorrer=tA;
    else
        recorrer=tB;

    for(i=0;i<recorrer;i++)
    {
        if(a1[i]>a2[i])
        {
            pA[j] = a2[i];
            pA[j+1]= a1[i];
            j+=2;
            cont++;
        }
        else if(a1[i]<a2[i])
        {
            pA[j] = a1[i];
            pA[j+1] = a2[i];
            j+=2;
            cont++;
        }
    }
    if(recorrer == tA)
        for(c=i;c<tB;c++)
        {
            pA[c] = a2[c];
            cont++;
        }
    else
        for(c=i;c<tA;c++)
        {
            pA[c] = a1[c];
            cont++;
        }

    return pA;
}
