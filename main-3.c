// NAME: Sophia Kovacic
//AUFGABE: Newton-Raphson-Verfahren
//Datum: 13.05.2020




#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Koennen auch in .h Datei bis Zeile 33 (Global)



double func(double x) {                                                     //double gewählt zwecks Genauigkeit
                                                                            //Werte in Funktion eingesetzt
    int a = 2;
    int b = -6;
    int c = 9;

    return (pow(x, a) + b * x + c);
}

double der(double x) {                                                      //double gewählt zwecks genauigkeit
                                                                            //Werte in Ableitung eingesetzt

    int a = 2;
    int b = -6;
    int c = 9;

    return (a * x) + b;
}


int main() {

    int a = 2;
    int b = -6;
    int c = 9;

    //printf("Geben Sie a,b und c ein (x^a + bx + c ) : \n");
    //scanf("%d.%d.%d",&a,&b,&c);
   // printf("Ihre Eingabe war: %d, %d, %d, \n",a,b,c);



    float tol = 0.00000001;
    double x0 = 5, x1 = 0, epsilon = 1.0E-10;                              //x0 = 5 ist der Anfangswert
    int max_wiederholungen;

    double* values = malloc(20 * sizeof(*values));                            //zugeordneter Speicher
    if (values == NULL) {
        printf("Platz im Speicher reicht nicht aus.\n Das Programm wird beendet...\n");
        return 0;
    }

    printf("Geben Sie die Anzahl der Wiederholungen an ( < 20) \n");
    scanf("%d", &max_wiederholungen);
    if (max_wiederholungen >= 20) {
        printf("Eingabe war höher als 20.\nErneute Eingabe (unter 20): ");
        scanf("%d", &max_wiederholungen);
        if (max_wiederholungen >= 20);
        printf("Eingabe war wieder >= 20. Wird nun beendet.\n");
        return 0;
    }

    printf("Wiederholung\t x0\t\t x1\t\t func\t\t der\n");
    printf("---------\t -\t\t -\t\t -----\t\t --------\n");

    //Newton-Raphson-Verfahren
    for (int i = 0;i <= max_wiederholungen;i++) {
        x1 = x0 - func(x0) / der(x0);                                         //Rechnung des Verfahrens
        printf("%d\t\t %.8f\t %.8f\t %.8f\t %.8f\n", i, x0, x1, func(x0), der(x0));  // Ausgabe
        if (fabs(der(x0)) < epsilon) {
            printf("Die Zahl ist zum dividieren zu klein");             //durch 0 ist nicht teilbar
            return 0;
        }
        else {
            x0 = x1;
            values[i] = x0;                                             //Gibt das entwickelte ergebnis zu dem array zur Kontrolle der Genauigkeit
        }
    }

    if (fabs(values[max_wiederholungen] - values[max_wiederholungen - 1]) <= tol) { //wie präzise arbeitet das Programm
        printf("Das Ergebnis nach der %d - ten Wiederholung, ist: %.10f.\n", max_wiederholungen, x1);
        printf("%d -te Wiederholung ist: %.8f\n", max_wiederholungen, values[max_wiederholungen]);
        printf("%d -te Wiederholung ist: %.8f\n", max_wiederholungen - 1, values[max_wiederholungen - 1]);
        printf("Der mögliche Fehler in der Schätzung liegt bei %.8f\n", fabs(values[max_wiederholungen] - values[max_wiederholungen - 1]));
        printf("wo unsere Toleranz bei %.8f liegt", tol);
    }
    else {

        printf("%d -te Wiederholung ist: %.8f\n", max_wiederholungen, values[max_wiederholungen]);
        printf("%d -te Wiederholung ist: %.8f\n", max_wiederholungen - 1, values[max_wiederholungen - 1]);
        printf("Der mögliche Fehler in der Schätzung beträgt:  %.8f\n", fabs(values[max_wiederholungen] - values[max_wiederholungen - 1]));
        printf("unsere Toleranz liegt bei %.8f ", tol);
    }

    free(values); //leert den freien Speicherplatz


    return (0);
}
