#include <stdio.h>
#include "Header_Files/IED.h"

#define MAXLINES 1000
#define MAXLEN 1000

char line[MAXLEN];
char enLine[MAXLEN];
char deLine[MAXLEN];
char entabbedLines[MAXLINES][MAXLEN];
char detabbedLines[MAXLINES][MAXLEN];

int main() {
    int length = 0;
    int lineCount = 0;

    while ((length = getinput(line)) > 0) {
        Entab(line, enLine, length);
        deTab(line, deLine, length);

        // Store the results for multiple lines
        snprintf(entabbedLines[lineCount], MAXLEN, "%s", enLine);
        snprintf(detabbedLines[lineCount], MAXLEN, "%s", deLine);
        lineCount++;
    }

    printf("\nEnTabs: \n");
    for (int i = 0; i < lineCount; i++) {
        printf("%s", entabbedLines[i]);
    }

    printf("\nDeTabs: \n");
    for (int i = 0; i < lineCount; i++) {
        printf("%s", detabbedLines[i]);
    }

    return 0;
}

