#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

typedef struct Data
{
    char str[256];
    int length;
} Data;

Data scanf_str(char* msg)
{
    unsigned int i = 0;
    bool end = false;
    Data outdata;
    memset(outdata.str, '\0', 256);
    do {
        if (msg[i] == 10 || msg[i] == '.' || msg[i] == '\0') {
          end = true;
        }
        else {
            outdata.str[i] = msg[i];
            i++;
        }
    } while (end == false);
    outdata.length = i;
    return outdata;
}

char* some_actions(Data data, int N) {
    int length = data.length;
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
    return 0;
}

int main(int argv, char* argc[])
{
    int N;
    char str[256];
    Data data;
    memset(str, '\0', 256);
    fgets(str, 256, stdin);
    data = scanf_str(str);
    scanf("%d", &N);
    some_actions(data, N);
    exit(0);
}

