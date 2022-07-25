#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char str[256];
    int length;
} Info;

int main(int argv, char* argc[])
{
    int N, length;
    char str[256];
    unsigned int i = 0;
    bool end = false;
    Info data;
    memset(str, '\0', 256);
    fgets(str, 256, stdin);
    do {
        if (str[i] == 10 || str[i] == '.' || str[i] == '\0') {
          end = true;
        }
        else {
            data.str[i] = str[i];
            i++;
        }
    } while (end == false);
    data.length = i;
    scanf("%d", &N);
    length = data.length;
    if (N >= length / 2) {
        for (int i = length - 1; i >= 0; i--) {
            printf("%c", data.str[i]);
        }
        printf("\n");
    }
    else {
        for (int i = 0; i < N; i++) {
            char temp;
            temp = data.str[i];
            data.str[i] = data.str[length-N+i];
            data.str[length-N+i] = temp;
        }
        printf("%s\n", data.str);
    }
    exit(0);
}

 
