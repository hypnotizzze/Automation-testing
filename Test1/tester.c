#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define N 5

int cmp_str(char *test, char *etalon, int k)
{
  int i = 0, errors[256], size;
  bool end = false, flag = true;
  
  do {
    if (test[i] == 10 || test[i] == '.' || test[i] == '\0') {
      end = true;
    }
    else if(test[i] != etalon[i]){
      flag = false;
      errors[i] = 1;
    }
    else
      errors[i] = 0;
    i++;
  } while (end == false);
  size = i - 1;
  if(flag == true) {
    printf("Тест №%d пройден\n\n", k);
    return 0;
  }
  else {
    printf("           ");
    for(int i = 0; i < size; i++) {
      if(errors[i] == 0)
        printf(" ");
      else
        printf("^");
    }
    printf("\n");
    printf("Тест №%d не пройден\n\n", k);
    return 1;
  }
}

int main(int argc, char* argv[]) {
  int i = atoi(argv[1]), number, result, err_result;
  FILE *fp = fopen("nabor", "r"), *ep = fopen("file_err", "r");
  char test_str[256], answer[256], test_ret[256], err[256];
  for(int j = 0; j < abs(i); j ++)  {
    memset(test_str, '\0', 256);
    fgets(test_str, 256, fp);
    fscanf(fp, "%d", &number);
    getc(fp);
    memset(answer, '\0', 256);
    fgets(answer, 256, fp);
    getc(fp);
  }
  if(i > 0  && i <= N) {
    printf("%s", test_str);
    printf("%d\n", number);
    printf("%s\n", answer);
  }
  else if(abs(i) > 0 && abs(i) <= N) {
    memset(test_ret, '\0', 256);
    fgets(test_ret, 256, stdin);
    if(fscanf(ep, "%d", &err_result) == 1 && err_result > 0) {
      printf("Аварийное заверение тестируемой программы в тесте №%d\n", abs(i));
    }
    else {
        printf("  Исходное:%s", test_str);
        printf(" Ожидаемое:%s", answer);
        printf("Полученное:%s", test_ret);
        result = cmp_str(test_ret, answer, abs(i));
    }
  }
  else
    printf("Нет действия для данного параметра %d\n", abs(i));
  return result;
}

