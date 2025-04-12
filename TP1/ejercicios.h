#ifndef EJERCICIOS_H_INCLUDED
#define EJERCICIOS_H_INCLUDED
void ej1();
void ej2();
void ej3();
void ej4();
void ej5();
void ej6();
void ej7();
void ej8();
void ej9();
void ej10();
int cont_digit(int numero);
int foundDig(int numero,int dig);
int digPar(int numero);
int digPar_recu(int numero,int pos);
int mediano(long int numero);
int mediano_rec(long int numero,int pos);
int prolijo(long int numero);
int prolijo_rec(long int numero,int ascendente,int descendente,int digito);
int hexChar2dec(char hex);
int hex2dec(char *hex);
int isPalindrome(char *word);
int isPalindrome_rec(char *inicio,char *fin);
#endif