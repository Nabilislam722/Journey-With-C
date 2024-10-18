#include <stdio.h>


int getinput(char line[]) {
    int c, i;

    for (i = 0; i < 1000 - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n') {
        line[i] = '\n';
        i++;
    }

    line[i] = '\0';
    return i;
}

