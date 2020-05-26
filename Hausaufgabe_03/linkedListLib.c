/*

NAME:           Sophia Kovacic
DATUM:          26.05.2020
AUFGABE         Ergänzen .c file

*/








#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "HA03_linkedListLib.h"

void delay(int milliseconds){

    long pause;
    clock_t now, then;
    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now - then) < pause)
        now = clock();
}//Bei andere Gruppe gefragt



void addListElem(listElement* start) {

    listElement* new;
    new = (listElement*)malloc(sizeof(listElement));
    if (new == NULL) {
        printf("can't reserve storage.\n");
        return;
    }

    listElement* currElem = start;
    while (currElem->nextElem != NULL) currElem = currElem->nextElem;// get last elem in list
    currElem->nextElem = new; // add new to the end of list
    new->nextElem = NULL;

    /* fill data in new element */

    printf("Please enter last name: \n");
    scanf("%s", new->lastName);

    printf("Please enter first name: \n");
    scanf("%s", new->firstName);

    printf("Please enter age: \n");
    scanf("%d", &(new->age));

    printf("end of function\n");
}



void printList(listElement* start) {

    if (start->nextElem == NULL) printf("\n>> list is empty\n\n");

    else {

        int i = 0;
        listElement* currElem = start;
        printf("\n>> current list:\n\n");

            do {

            currElem = currElem->nextElem;

            printf("%d.)", i); i++;
            printf("\tlast Name: %s\n", currElem->lastName);
            printf("\tfirst Name: %s\n", currElem->firstName);
            printf("\tage : %d\n", currElem->age);
            } while (currElem->nextElem != NULL);

        printf("\n");
    }
}



void delListElem(listElement* start) {


printf("\n>> delListElem fcn is tbd.\n\n");

}



void delList(listElement* start) {


printf("\n>> getLenOfList fcn is tbd.\n\n");

}



int getLenOfList(listElement* start) { // we use this for save list fcn

    int counter = 0;
    listElement* currElem = start;
    while (currElem->nextElem != NULL) {// get last elem in list

    currElem = currElem->nextElem; counter++;

    }

    return counter;

}



void saveList(listElement* start) {



    char filename[50];
    printf("\n >> saving data...\n\n");
    printf("filename without extension: ");
    scanf("%s", filename);
    strcat(filename, ".txt"); // adding .txt to file name



    FILE* fPtr;
    fPtr = fopen(filename, "w");









    /*  1.) Check if fopen() was successful.

            Otherwise exit function with return and inform the user about the canceled task. */



    if (fPtr == NULL) {

        printf("\nCould not open file.\n");

    }

    else {

        printf("Opening file was successful.\n");

    }

    /*

            2.) Use fprintf() to write length of list as first value to the text file.

                This will be the first information needed by the loadList function. */



    int length = getLenOfList(start);
    printf("The length is: %d\n", length);
    fprintf(fPtr, "%d\n", length);


    if (start->nextElem == NULL) printf("list ist empty\n\n");
    else {
        int i = 0;
        listElement* currElem = start;

        do {

            currElem = currElem->nextElem;
            fprintf(fPtr, "%d.)", i); i++;
            fprintf(fPtr, "\tlast Name: %s\n", currElem->lastName);
            fprintf(fPtr, "\tfirst Name: %s\n", currElem->firstName);
            fprintf(fPtr, "\tage : %d\n", currElem->age);

        } while (currElem->nextElem != NULL);

        if (currElem->nextElem == NULL){
            printf("Saving successfull!\n\n");

        }
    }
    fclose(fPtr);

}

   




void loadList(listElement* start) {

    int i = 0;
    int length = 0;
    char filename[50];

    printf("\nloading data...\n\n");
    printf("availible data: \n----------------\n");
    system("ls *.txt"); // dir /b *.txt for windows | print availible *.txt files in current location
    printf("\nfilname without extension: ");
    scanf("%s", filename);
    strcat(filename, ".txt"); // adding .txt to file name



    FILE* fPtr;
    fPtr = fopen(filename, "r");



    if (fPtr == NULL) {

    printf("\nCould not open file.\n");

    }

    else printf("\nOpening file was successful.\n");


    fscanf(fPtr, "%d", &length);
    printf("length of list amounted to:%d\n", length);

        

    listElement* currElem = start;

           


     do {

      currElem = currElem->nextElem;
      fscanf(fPtr, "%d.)", &i); i++;
      fscanf(fPtr, "\tlast Name: %s\n", currElem->lastName);
      fscanf(fPtr, "\tfirst Name: %s\n", currElem->firstName);
      fscanf(fPtr, "\tage : %d\n", &currElem->age);
      printf("\n(%d)\n\t Last name: %s\\First name: %s\n\t Age: %d\n\n", i, currElem->lastName, currElem-> age);

      } while (currElem->nextElem != NULL);


       


            fclose(fPtr);
            printf("loading data will be append to current list...\n");
            printList(start); // show loaded list

        
}



void exitFcn(listElement* start) {

    printf("\n>> exitFcn fcn is tbd.\n\n");

}



void sortList(listElement* start) {

    printf("\n>>sortList fcn is tbd.\n\n");

}



void stringToLower(char* string) {

    printf("\n>>stringToLower fcn is tbd.\n\n");
}
