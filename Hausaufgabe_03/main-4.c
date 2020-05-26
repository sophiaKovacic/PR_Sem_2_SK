#include <stdio.h>
#pragma warning(define:4996)
#include <stdlib.h>
#include <string.h>
#include "HA03_linkedListLib.h"

int main() {



    listElement* start;

    start = (listElement*)malloc(sizeof(listElement));

    if (start == NULL) {

        printf("can't reserve storage.\n");

        return -1;

    }

    start->nextElem = NULL;



    int FLAGG = 1;

    while (FLAGG) {



        printf("1... print list\n");

        printf("2... add element\n");

        printf("3... delete element\n");

        printf("4... delete list\n");

        printf("5... save list\n");

        printf("6... load list\n");

        printf("7... sort list\n");

        printf("0... quit\n");

        scanf("%d", &FLAGG);

        system("clear"); // cls for windows





        switch (FLAGG) {

        case 1: printList(start); break;

        case 2: addListElem(start); break;

        case 3: delListElem(start); break;

        case 4: delList(start); break;

        case 5: saveList(start); break;

        case 6: loadList(start); break;

        case 7: sortList(start); break;

        case 0: FLAGG = 0; exitFcn(start); break;

        default: printf("invalid choice\n"); break;

        }

    }

    return 0;

}