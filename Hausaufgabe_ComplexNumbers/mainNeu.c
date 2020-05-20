//NAME: Sophia Kovacic
//DATUM: 18.05.2020
//AUFGABE: Taschenrechner komplexe Zahlen



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fcn.h"
#pragma warning(disable:4996)
#include<complex.h>



typedef struct{

    double realprt;
    double imprt;

}complexnumber;

complexnumber num1, num2;


int main() {


    double resreal;
    double resim;
    double reslen;
    double resphi;
    char desiredaction;
    int choice;
    char zahl1[50];
    char zahl2[50];




    printf("Geben Sie die erste komplexe Zahl in kartesischer Form an: \n");
    scanf("%s", &zahl1);

    printf("Geben Sie die zweite komplexe Zahl in kartesischer Form an: \n");
    scanf("%s", &zahl2);

    


    char delimiter[] = "+-i";

    char* ptr;



    /*erste Zahl*/

    ptr = strtok(zahl1, delimiter);
    num1.realprt = atof(ptr);
    ptr = strtok(NULL, "\n\t");

    num1.imprt = atof(ptr);
    ptr = strtok(NULL, "\n\t");

    /*zweite Zahl*/

    ptr = strtok(zahl2, delimiter);
    num2.realprt = atof(ptr);
    ptr = strtok(NULL, "\n\t");

    num2.imprt = atof(ptr);
    ptr = strtok(NULL, "\n\t");


    double (*fcnptr)(double, double);
    double (*fcnptreu)(double, double);



    while (1)
    {
        printf("Folgende Möglichkeiten stehen zur Verfügung:\n");
        printf("1: Addieren zweier komplexer Zahlen.\n");
        printf("2: Subtrahieren zweier komplexer Zahlen.\n");
        printf("3: Multiplizieren zweier komplexer Zahlen.\n");
        printf("4: Dividieren zweier komplexer Zahlen\n");
        printf("5: Programm beenden\n");
        printf("Wie ist Ihre Wahl ?\n");
        scanf("%d", &choice);
        if (choice == 5)
            exit(0);
        if (choice == 1)
        {
            fcnptr = fcnadd;
            resreal = fcnptr(num1.realprt, num2.realprt);
            resim = fcnptr(num1.imprt, num2.imprt);
            printf(" Erg: %lf + (%lf)i\n", resreal, resim);
        }
        else if (choice == 2)
        {
            fcnptr = fcnsub;
            resreal = fcnptr(num1.realprt, num2.realprt);
            resim = fcnptr(num1.imprt, num2.imprt);
            printf(" Erg: %lf + (%lf)i\n", resreal, resim);
        }
        else if (choice == 3)
        {

            resreal = num1.realprt * num2.realprt - num1.imprt * num2.imprt;
            resim = num1.realprt * num2.imprt + num2.realprt * num1.imprt;

            printf("%.4lf+%.4lfi * %.4lf+%.4lfi = ", num1.realprt, num1.imprt, num2.realprt, num2.imprt);
            printf("%.4lf+%.4lfi", resreal, resim);

        }
        else if (choice == 4)
        {
            resreal = (num1.realprt * num2.realprt + num1.imprt * num2.imprt) / (num2.realprt * num2.realprt + num2.imprt * num2.imprt);
            resim = (num1.imprt * num2.realprt - num1.realprt * num2.imprt) / (num2.realprt * num2.realprt + num2.imprt * num2.imprt);

            printf("%.4lf+%.4lfi / %.4lf+%.4lfi = ", num1.realprt, num1.imprt, num2.realprt, num2.imprt);
            printf("%.4lf+%.4lfi", resreal, resim);

        }
        else {
            printf("ungültige Eingabe! Wollen Sie es nochmals versuchen, so drücken Sie eine Taste.");
            
        }

            return 0;
        
    }
}