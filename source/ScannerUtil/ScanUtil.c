#include <stdio.h>
#include <memory.h>
//#include <malloc.h>
#include <ctype.h>
#include <stdlib.h>
#include "ScanUtil.h"

/*
 * Function: scanInt
 * Description: takes integer input from the user, will loop until a number is entered.
 * Returns: inputted int.
 */

int scanInt(){
    char line[256];
    int i = -1;
    int loop = 1;
    while(loop) {
        if (fgets(line, sizeof(line), stdin)) {
            if (1 == sscanf(line, "%d", &i)) {
                loop = 0;
            }
            else {
                printf("Please enter an integer\n");
            }
        }
    }
    return i;
}

/*
 * Function: scanDouble
 * Description: takes double input from the user, will loop until a number is entered.
 * Returns: inputted double.
 */

double scanDouble(){
    char line[256];
    double i = -1;
    int loop = 1;
    while(loop) {
        if (fgets(line, sizeof(line), stdin)) {
            if (1 == sscanf(line, "%lf", &i)) {
                loop = 0;
            }
            else {
                printf("Please enter a double\n");
            }
        }
    }
    return i;
}


static void trim(char *str) {
    int len = strlen(str);
    char *frontp = str;
    char *endp = str + len;

    while(isspace((unsigned char) *frontp)) ++frontp;
    if(endp != frontp){
        while(isspace((unsigned char) *(--endp)) && endp != frontp);
    }

    if(str + len - 1 != endp) *(endp + 1) = '\0';
    else if(frontp != str &&  endp == frontp)*str = '\0';

    endp = str;
    if(frontp != str) {
        while(*frontp) {*endp++ = *frontp++;}
        *endp = '\0';
    }
}

/*
 * Function: scanArrayOfChar
 * Description: takes a string input from the user, ignoring trailing and leading whitespace.
 * Returns: inputted string.
 */

char* scanArrayOfChar(){
    size_t bufferSize = sizeof(char) * 256;
    char* line = malloc(bufferSize);
    while(1) {
        if (fgets(line, bufferSize, stdin)) {
            trim(line);
            if(strlen(line) != 0) {
//                toLowerCase(line);
                return line;
            }
        }
        printf("Please enter a string\n");
    }
}

void toLowerCase(char* string){
    int i = 0;

    while( string[i] )
    {
        putchar(tolower(string[i]));
        i++;
    }
}