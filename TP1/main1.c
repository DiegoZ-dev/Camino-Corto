#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void ej1()
{
    /* Diseñar un programa que dados tres numeros enteros "dia", "mes", "año":
     *  Analice si la fecha que representan es válida, e indique el resultado por pantalla.
     */
    system("cls");
    int dia,mes,anio;
    int valido;

    printf("Ingrese el dia: ");
    scanf("%d",&dia);
    printf("Ingrese el mes: ");
    scanf("%d",&mes);
    printf("Ingrese el anio: ");
    scanf("%d",&anio);

    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
    {
        valido = 0<dia && dia<=31;
    }
    else if(mes==2)
    {
        valido = ((anio%4==0 && anio%100!=0) || anio%400==0)? 0<dia && dia<=29 : 0<dia && dia<=28;
    }
    else
    {
        valido = 0<dia && dia<=30;
    }
    printf("\nEl dia es ");
    printf(valido?"VALIDO":"INVALIDO");
}
void ej2()
{
    /* Diseñar un programa que, dado un entero largo (long) que representa una candidad de segundos,
    convierta y muestre dicha cantidad de segundos en el siguiente formato de tiempo:
     hh:mm:ss
    */
    system("cls");
    long int segundos;
    long int hora,minuto,segundo;
    printf("Ingrese los segundos a convertir: ");
    scanf("%ld",&segundos);

    hora = (segundos/60)/60;
    minuto = segundos/60 - hora*60;
    segundo = segundos - minuto*60 - hora*3600;

    printf("%.2ld:%.2ld:%.2ld",hora,minuto,segundo);
}
void ej3()
{
    /* Escribir un programa que permita llevar adelante las siguientes conversiones:
     Celsius a Fahrenheit (1 C° = 33,8 Fahrenheit)
     Millas por hora a Kilometros por minuto (1 milla = 1,609344 kilometros).
     Litros cada 100 km a millas por galón (1 litro = 0,264172052 galones).
    */
    system("cls");
    double celsius,fahrenheit,millas,kilometros,litros,galones;
    printf("Ingrese Celsius para pasar a Fahrenheit: ");
    scanf("%lf",&celsius);
    printf("Ingrese millas/h para pasar a Km/min: ");
    scanf("%lf",&millas);
    printf("Ingrese litros cada 100km para pasar a millas por galon: ");
    scanf("%lf",&litros);

    fahrenheit = (celsius * 9/5)+32;
    kilometros = (millas * 1.609344)/60;
    galones = (100*(1/1.609344))/(litros*0.264172052);

    printf("\n%.2lf Celsius = %.2lf Fahrenheit\n",celsius,fahrenheit);
    printf("%.2lf millas/h = %.2lf Km/min\n",millas,kilometros);
    printf("%.2lf litros/100km = %.2lf millas/galon\n",litros,galones);
}
void ej4()
{
    int serie;
    long int numero,mayor,menor,promedio;

    printf("Cuantos numeros enteros ingresara? ");
    scanf("%d",&serie);

    promedio=0;

    printf("Ingrese la serie de numeros: ");
    for(int i=0;i<serie;i++)
    {
        scanf("%ld",&numero);
        if(i==0)
        {
            mayor=numero;
            menor=numero;
        }

        if(numero>mayor)
            mayor=numero;
        if(numero<menor)
            menor=numero;

        promedio+=numero;
    }
    promedio/=(float) serie;

    printf("El menor de la serie de %d numeros es: %ld\nEl mayor: %ld\nPromedio: %ld",serie,menor,mayor,promedio);
}
void ej5()
{
    int binario,decimal,digito,pos;
    printf("Ingrese numero binario a convertir en decimal: ");
    scanf("%d",&binario);

    pos = 0;
    decimal = 0;

    while(binario!=0)
    {
        digito = binario%10;

        decimal+=digito*pow(2,pos);
        pos++;
        binario/=10;
    }

    printf("El binario en base 10 es: %d",decimal);
}

int cont_digit(int numero)
{
    int cont;

    if(numero == 0)
        cont = 0;
    else
        cont = 1 + cont_digit(numero/10);

    return cont;
}
int foundDig(int numero,int dig)
{
    int cont;
    int ult_digito = numero%10;

    if(numero==0)
        cont = 0;
    else if(ult_digito == dig)
        cont = 1 + foundDig(numero/10,dig);
    else
        cont = foundDig(numero/10,dig);

    return cont;
}
int digPar_recu(int numero,int pos)
{
    int cont;
    int digito = numero%10;
    if(numero==0)
        cont=0;
    else if(pos%2!=0 && digito%2==0)
        cont = 1+digPar_recu(numero/10,++pos);
    else
        cont = digPar_recu(numero/10,++pos);

    return cont;
}
int digPar(int numero)
{
    return digPar_recu(numero,1);
}
void ej6()
{
    int numero,cant_dig,digito;
    printf("a) Ingrese un numero: ");
    scanf("%d",&numero);

    cant_dig = cont_digit(numero);
    printf("Tiene %d digitos.",cant_dig);

    printf("\n\nb) Ingrese un numero: ");
    scanf("%d",&numero);

    printf("Ingrese un digito a contar: ");
    scanf("%d",&digito);
    cant_dig = foundDig(numero,digito);

    printf("El digito %d aparece %d veces.",digito,cant_dig);

    printf("\n\nc) Ingrese un numero: ");
    scanf("%d",&numero);
    cant_dig = digPar(numero);

    printf("Aparecen %d digitos pares en posiciones impares. ",cant_dig);
}
int mediano_rec(long int numero,int pos)
{
    int cont;
    int digito = numero%10;

    if(numero==0)
        cont=0;
    else if(pos%2!=0)
        cont = mediano_rec(numero/10,++pos) + digito;
    else
        cont = mediano_rec(numero/10,++pos) - digito;

    return cont;
}
int mediano(long int numero)
{
    return mediano_rec(numero,1);
}
void ej7()
{
    long int numero;
    printf("Ingrese un numero: ");
    scanf("%ld",&numero);

    printf("El numero mediano de %ld es %d",numero,mediano(numero));
}
int prolijo_rec(long int numero,int ascendente,int descendente,int digito)
{
    int esProlijo;
    int digitoN;

    if((descendente==1 && numero==0) || numero==0)
        esProlijo=1;
    else if(ascendente==0 && descendente==0)
    {
       digitoN = numero%10;

       if(digito>digitoN)
            esProlijo= prolijo_rec(numero/10,1,descendente,digitoN);
       else if(digito<digitoN)
            esProlijo = prolijo_rec(numero/10,ascendente,1,digitoN);
       else if(digito==digitoN)
            esProlijo=0;
    }
    else if(ascendente==1)
    {
        digitoN = numero%10;
        if(digito>digitoN)
            esProlijo= prolijo_rec(numero/10,ascendente,descendente,digitoN);
        else
            esProlijo=0;
    }
    else if(descendente==1)
    {
        digitoN = numero%10;
        if(digito<digitoN)
            esProlijo= prolijo_rec(numero/10,ascendente,descendente,digitoN);
        else
            esProlijo=0;
    }

    return esProlijo;
}
int prolijo(long int numero)
{
    return prolijo_rec(numero/10,0,0,numero%10);
}
void ej8()
{
    long int numero;
    printf("Ingrese un numero: ");
    scanf("%ld",&numero);

    printf("%ld es ",numero);
    printf(prolijo(numero)? "prolijo":"no prolijo");
}
int hex2dec(char *hex,int length)
{
    int valor;
    int exponente = length-1;
    int numero = 0;
    while(*hex != '\0')
    {
        switch(*hex)
        {
        case '0':
            valor = 0;
            break;
        case '1':
            valor = 1;
            break;
        case '2':
            valor = 2;
            break;
        case '3':
            valor = 3;
            break;
        case '4':
            valor = 4;
            break;
        case '5':
            valor = 5;
            break;
        case '6':
            valor = 6;
            break;
        case '7':
            valor = 7;
            break;
        case '8':
            valor = 8;
            break;
        case '9':
            valor = 9;
            break;
        case 'A':
            valor = 10;
            break;
        case 'B':
            valor = 11;
            break;
        case 'C':
            valor = 12;
            break;
        case 'D':
            valor = 13;
            break;
        case 'E':
            valor = 14;
            break;
        case 'F':
            valor = 15;
            break;
        }
        numero += valor * pow(16,exponente);
        hex++;
        exponente--;
    }
    return numero;
}
void ej9()
{
    char hex[120];

    printf("Ingrese el numero hexadecimal: ");
    scanf("%s",hex);

    printf("%s en decimal es: %d",hex,hex2dec(hex,strlen(hex)));
}
int isPalindrome_rec(char *inicio, char *fin)
{
    int palindromo = 0;
    char *anterior = (inicio-1);

    if(inicio == fin)
        palindromo = 1;
    else if(anterior == fin)
        palindromo = 1;
    else
    {
        if(*inicio == *fin)
            palindromo = isPalindrome_rec(++inicio,--fin);
    }

    return palindromo;
}
int isPalindrome(char *word)
{
    char *ultima = word;
    char *primera = word;

    while(*word != '\0')
    {
        ultima = word;
        word++;
    }
    return isPalindrome_rec(primera,ultima);
}
void ej10()
{
    char palindrome[200];

    printf("Ingrese una palabra: ");
    scanf("%s",palindrome);

    printf("La palabra %s es ",palindrome);
    printf(isPalindrome(palindrome)?"PALINDROME.":"NO PALINDROME.");
}
int main()
{
    ej10();

    return 0;
}
