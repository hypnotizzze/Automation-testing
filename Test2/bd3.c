 #include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

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
} Poezd;

void func1() {
  char c[100];
  do {
    printf("Нажмите д для выхода\n");
    fgets(c, 100, stdin);
  } while (strcmp(c, "д\n") != 0 && strcmp(c, "д") != 0 );
}

void func2(Poezd train) {
	printf("Номер поезда: %d\n", train.train_number);
	printf("Пункт назначения: %s\n", train.destination);
	if (train.departure_time.hour < 10)
		printf("Время отправления: 0%d:", train.departure_time.hour);
	else
		printf("Время отправления: %d:", train.departure_time.hour);
	if (train.departure_time.min < 10)
		printf("0%d\n", train.departure_time.min);
	else
		printf("%d\n", train.departure_time.min);

	printf("Целых часов в пути: %d\n", train.travel_time.hour);
	printf("Минут в пути: %d\n", train.travel_time.min);

	if (train.bilets == true)
		printf("Билеты есть в наличии\n\n");
	else
		printf("Билетов в наличии нет\n\n");
}

void func3(Poezd *train) {
	char c[100], sym;
	printf("Номер поезда: ");
	scanf("%lu", &train->train_number);
	printf("Пункт назначения: ");
	scanf("%s", &train->destination);

	do {
		printf("Часы отправления: ");
		scanf("%u", &train->departure_time.hour);
		if (train->departure_time.hour < 0 || train->departure_time.hour >= 24)
			printf("Часы отправления от 0 до 23\n");
	} while (train->departure_time.hour < 0 || train->departure_time.hour >= 24);

	do {
		printf("Минуты отправления: ");
		scanf("%u", &train->departure_time.min);
		if(train->departure_time.min < 0 || train->departure_time.min >= 60)
			printf("Минуты отправления от 0 до 59\n");
	} while (train->departure_time.min < 0 || train->departure_time.min >= 60);
  if(train->departure_time.min < 23)
    train->departure_time.min += 25;

	do {
		printf("Целых часов в пути: ");
		scanf("%u", &train->travel_time.hour);
	} while (train->travel_time.hour <= 0);
  if(train->travel_time.hour < 2)
    train->travel_time.hour += 3;

	do {
		printf("Минут в пути: ");
		scanf("%u", &train->travel_time.min);
		if (train->travel_time.min < 0 || train->travel_time.min >= 60)
			printf("Минуты в пути от 0 до 59\n");
	} while (train->travel_time.min < 0 || train->travel_time.min >= 60);
  scanf("%c", &sym);
	do {
		printf("Есть ли билеты в наличии? (да или нет)\n");
		fgets(c, 100, stdin);
	} while (strcmp(c, "да\n") != 0 && strcmp(c, "нет\n") != 0 && strcmp(c, "да") != 0 && strcmp(c, "нет") != 0);
	if (strcmp(c, "да") == 0 || strcmp(c, "да\n") == 0)
		train->bilets = true;
	else if (strcmp(c, "нет") == 0 || strcmp(c, "нет\n") == 0)
		train->bilets = false;
  return;
}

int main()
{
	FILE *fp, *tp;
	Poezd train, tmp;
	int cmd = -1, delete_train, count_find, train_for_delete[100], i, j, time_sum1, time_sum2, time_sum3;
	long int tell, cur_tell;
	bool main_menu = false;
	char filename[25], c[100], sym;
	setlocale(LC_ALL, "rus");
	strcpy(filename, "default");
	fp = fopen("default", "rb+");
	if (fp == NULL) {
		fp = fopen("default", "wb+");
		printf("Обычный файл не найден\n");
	}
	do
	{
    printf("--------------------------------------------------------------\n");
		printf("Создание(открытие) файла: 1\n");
		printf("Просмотр файла: 2\n");
		printf("Добавление данных: 3\n");
		printf("Удаление данных: 4\n");
		printf("Поиск поездов в заданный город в заданном диапазоне времени: 5\n");
		printf("Корректировка данных: 6\n");
		printf("Выход: 7\n");
		printf("Введите команду: ");
		scanf("%d", &cmd);
    scanf("%c", &sym);
    printf("\n");
		switch (cmd) {
		  case 1:
        printf("--------------------------------------------------------------\n");
				printf("Введите имя файла: ");
				scanf("%s", &filename);
				fclose(fp);
				fp = fopen(filename, "rb+");
				if (fp == NULL) {
					fp = fopen(filename, "wb+");
					printf("Файл именем %s не найден, поэтому он создан заново\n", filename);
				}
				break;

			case 2:
        printf("--------------------------------------------------------------\n");
				fseek(fp, 0, SEEK_SET);
				while (fread(&train, sizeof(Poezd), 1, fp) != 0) {
					func2(train);
				}
				func1();
				break;

			case 3:
        printf("--------------------------------------------------------------\n");
				fseek(fp, 0, SEEK_END);
				func3(&train);
				fwrite(&train, sizeof(Poezd), 1, fp);
				break;

			case 4:
        printf("--------------------------------------------------------------\n");
				fseek(fp, 0, SEEK_SET);
				delete_train = count_find = i = j = 0;
				printf("Введите номер поезда для удаления: ");
				scanf("%d", &delete_train);
				while (fread(&train, sizeof(Poezd), 1, fp) != 0) {
					if (delete_train == train.train_number) {
						count_find++;
						train_for_delete[j++] = i;
					}
					i++;
				}
				j = 0;
				if (count_find > 0) {
					printf("Найдено рейсов с введенным номером поезда: %d\n\n", count_find);
					while (j < count_find) {
						fseek(fp, sizeof(Poezd) * train_for_delete[j], SEEK_SET);
						fread(&train, sizeof(Poezd), 1, fp);
            printf("Номер записи: %d\n", j+1);
						func2(train);
						j++;
					}
					delete_train = 1;
					if (count_find > 1) {
						do {
							printf("Введите номер найденной записи для удаления: ");
							scanf("%d", &delete_train);
						} while (delete_train <= 0 && delete_train > count_find);
					}
					tp = fopen("tmp", "wb");
					fseek(fp, sizeof(Poezd) * train_for_delete[delete_train - 1], SEEK_SET);
					tell = ftell(fp);
					fseek(fp, 0, SEEK_SET);
					while (fread(&tmp, sizeof(Poezd), 1, fp) != 0) {
						cur_tell = ftell(fp);
						if (cur_tell != tell + sizeof(Poezd))
							fwrite(&tmp, sizeof(Poezd), 1, tp);
					}
					fclose(tp);
					fclose(fp);
					remove(filename);
					rename("tmp", filename);
					fp = fopen(filename, "rb+");
				}
				else
					printf("Не найдено рейсов с таким номером поезда\n");
                scanf("%c", &sym);
				func1();
				break;

			case 5:
        printf("--------------------------------------------------------------\n");
				printf("Введите станцию назначения: ");
				scanf("%s", &tmp.destination);
				do {
					printf("Введите с какого часа отправление: ");
					scanf("%u", &tmp.departure_time.hour);
				} while (tmp.departure_time.hour < 0 || tmp.departure_time.hour >= 24);

				do {
					printf("Введите с какой минуты отправление: ");
					scanf("%u", &tmp.departure_time.min);
				} while (tmp.departure_time.min < 0 || tmp.departure_time.min >= 60);
        
        time_sum2 = tmp.departure_time.hour * 60 + tmp.departure_time.min;
        
				do {
					printf("Введите до какого часа отправление: ");
					scanf("%u", &tmp.travel_time.hour);
				} while (tmp.travel_time.hour < 0 || tmp.travel_time.hour >= 24 || tmp.travel_time.hour < tmp.departure_time.hour);

				do {
					printf("Введите до какой минуты отправление: ");
					scanf("%u", &tmp.travel_time.min);
          time_sum3 = tmp.travel_time.hour * 60 + tmp.travel_time.min;
				} while (time_sum3 < time_sum2);

				fseek(fp, 0, SEEK_SET);
				while (fread(&train, sizeof(Poezd), 1, fp) != 0)
					if (strcmp(train.destination, tmp.destination) == 0) {
            time_sum1 = train.departure_time.hour * 60 + train.departure_time.min;
						if (time_sum1 >= time_sum2 && time_sum1 <= time_sum3)
              func2(train);
				}
                scanf("%c", &sym);
				func1();
				break;

			case 6:
        printf("--------------------------------------------------------------\n");
				fseek(fp, 0, SEEK_SET);
				delete_train = count_find = i = j = 0;
				printf("Введите номер поезда для редактирования: ");
				scanf("%d", &delete_train);
				while (fread(&train, sizeof(Poezd), 1, fp) != 0) {
					if (delete_train == train.train_number) {
						count_find++;
						train_for_delete[j++] = i;
					}
					i++;
				}
				if (count_find > 0) {
					printf("Найдено рейсов с введенным номером поезда: %d\n\n", count_find);
					j = 0;
					while (j < count_find) {
						fseek(fp, sizeof(Poezd) * train_for_delete[j], SEEK_SET);
						fread(&train, sizeof(Poezd), 1, fp);
                        printf("Номер записи: %d\n", j+1);
						func2(train);
						j++;
					}
					delete_train = 1;
						if (count_find > 1) {
							do {
								printf("Введите номер найденной записи для редактирования: ");
								scanf("%d", &delete_train);
							} while (delete_train <= 0 && delete_train > count_find);
						}
						func3(&train);
						fseek(fp, sizeof(Poezd) * train_for_delete[delete_train - 1], SEEK_SET);
						fwrite(&train, sizeof(Poezd), 1, fp);
				}
				else
					printf("Не найдено рейсов с таким номером поезда\n");
				break;

			case 7:
				main_menu = true;
				break;
			default:
				//
        printf("Команда %d не определена, повторите попытку\n", cmd);
				break;
		}
	} while (main_menu == false);
	fclose(fp);
	return 0;
}
 
 
