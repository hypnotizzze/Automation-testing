#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define N 3

typedef struct {
	unsigned short int hour;
	unsigned short int min;
} Time;

typedef struct {
	unsigned long train_number;
	char destination[100];
	Time departure_time;
	Time travel_time;
	bool bilets;
} Train;

int cmp_str(char *test, char *etalon)
{
  int i = 0, errors[256], size;
  bool end = false, flag = true;
  
  do {
    if (test[i] == 10 || test[i] == '\0') {
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
  if(flag == false) {
    printf("            ");
    for(int i = 0; i < size; i++) {
      if(errors[i] == 0)
        printf(" ");
      else
        printf("↓");
    }
    printf("\n");
    return 1;
  }
  else
    return 0;
}

int main(int argc, char* argv[]) {
  int i = atoi(argv[1]), int_cmd, k = 0, err_result;
  unsigned long int int_otv;
  FILE *fp, *bp, *ep = fopen("file_err", "r");;
  bool test_no_error, tmp_bool;
  Train train;
  char tmp_str[100], char_cmd, sym;
  if(i > 0 && i <= N) {
    // Ввод данных
    fp = fopen(argv[2], "r+");
    while(fscanf(fp, "%c", &char_cmd) != EOF) {
      if(char_cmd == 'd') {
        fscanf(fp, "%d", &int_cmd);
        fscanf(fp, "%c", &sym);
        printf("%d\n", int_cmd);
      }
      else if(char_cmd == 's') {
        fscanf(fp, "%c", &sym);
        fgets(tmp_str, 100, fp);
        printf("%s", tmp_str);
      } 
    }
  fclose(fp);
  }
  else if(abs(i) > 0 && abs(i) <= N) {
    // Проверка
    fp = fopen(argv[2], "r");
    bp = fopen(argv[3], "rb");
    test_no_error = true;
    if(fscanf(ep, "%d", &err_result) == 1 && err_result > 0) {
      printf("Аварийное заверение тестируемой программы в тесте №%d\n", abs(i));
    }
    else {
    while (fread(&train, sizeof(Train), 1, bp) != 0) {
      fscanf(fp, "%lu", &int_otv);
      fscanf(fp, "%c", &sym);
      if(int_otv != train.train_number) {
        printf("\n");
        printf("Ошибка в записи №%d\n", k+1);
        printf("Номер поезда не совпадает\n");
        printf("Ожидаемый результат: %lu\n", int_otv);
        printf("Полученный результат: %lu\n", train.train_number);
        test_no_error = false;
      }
      
      fgets(tmp_str, 100, fp);      
      if(cmp_str(train.destination, tmp_str) != 0) {
        printf("\n");
        printf("Ошибка в записи №%d\n", k+1);
        printf("Полученное: %s\n", train.destination);
        printf(" Ожидаемое: %s\n", tmp_str);
        test_no_error = false;
      }
      
      fscanf(fp, "%lu", &int_otv);
      if(int_otv != train.departure_time.hour) {
        printf("\n");
        printf("Ошибка в записи №%d\n", k+1);
        printf("Часы отправления поезда не совпадают\n");
        printf("Ожидаемый результат: %lu\n", int_otv);
        printf("Полученный результат: %lu\n", train.departure_time.hour);
        test_no_error = false;
      }
      
      fscanf(fp, "%lu", &int_otv);
      if(int_otv != train.departure_time.min) {
        printf("\n");
        printf("Ошибка в записи №%d\n", k+1);
        printf("Минуты отправления поезда не совпадают\n");
        printf("Ожидаемый результат: %lu\n", int_otv);
        printf("Полученный результат: %lu\n", train.departure_time.min);
        test_no_error = false;
      }
      
      fscanf(fp, "%lu", &int_otv);
      if(int_otv != train.travel_time.hour) {
        printf("\n");
        printf("Ошибка в записи №%d\n", k+1);
        printf("Количество часов в пути не совпадает\n");
        printf("Ожидаемый результат: %lu\n", int_otv);
        printf("Полученный результат: %lu\n", train.travel_time.hour);
        test_no_error = false;
      }
      
      fscanf(fp, "%lu", &int_otv);
      if(int_otv != train.travel_time.min) {
        printf("\n");
        printf("Ошибка в записи №%d\n", k+1);
        printf("Количество минут в пути не совпадает\n");
        printf("Ожидаемый результат: %lu\n", int_otv);
        printf("Полученный результат: %lu\n", train.travel_time.min);
        test_no_error = false;
      }
      
      fscanf(fp, "%lu", &int_otv);
      if(int_otv == 0)
        tmp_bool = false;
      else if(int_otv == 1)
        tmp_bool = true;
      
      if(tmp_bool != train.bilets) {
        printf("\n");
        printf("Ошибка в записи №%d\n", k+1);
        printf("Информация о наличии билетов не совпадает\n");
        printf("Ожидается, что билеты ");
        if(tmp_bool == true)
          printf("в наличии\n");
        else
          printf("не в наличии\n");
        printf("Получено, что билеты ");
        if(train.bilets == true)
          printf(" в наличии\n");
        else
          printf("не в наличии\n");
        test_no_error = false;
        k++;
      }
    }
    fclose(bp);
    fclose(fp);
    if(test_no_error == false)
        printf("Тест %d не пройден\n\n", abs(i));
      else
        printf("Тест %d пройден\n\n", abs(i));
  }
  }
  else
    printf("Нет действия для данного параметра %d\n", abs(i));
  return 0;
}

