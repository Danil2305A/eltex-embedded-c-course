#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT_OF_ABONENTS 100

struct abonent {
  char name[10];
  char second_name[10];
  char tel[10];
};

int current_count = 0;

void print_menu(void) {
  printf("1) Добавить абонента\n");
  printf("2) Удалить абонента\n");
  printf("3) Поиск абонентов по имени\n");
  printf("4) Вывод всех записей\n");
  printf("5) Выход\n");
  printf("Выберите действие: ");
}

void add_abonent(struct abonent *abonents) {
  if (current_count >= COUNT_OF_ABONENTS) {
    printf("Справочник переполнен!\n");
    return;
  }

  struct abonent new_abonent;

  printf("Введите имя (до 9 символов): ");
  scanf("%9s", new_abonent.name);

  printf("Введите фамилию (до 9 символов): ");
  scanf("%9s", new_abonent.second_name);

  printf("Введите номер телефона (до 9 символов): ");
  scanf("%9s", new_abonent.tel);

  abonents[current_count] = new_abonent;
  current_count++;

  printf("Абонент успешно добавлен в справочник!\n");
}

void delete_abonent(struct abonent *abonents) {
  if (current_count == 0) {
    printf("Справочник пуст!\n");
    return;
  }

  int id;
  printf("Введите порядковый номер абонента (нумерация с 1): ");
  scanf("%d", &id);

  if (id <= 0 || id > current_count) {
    printf("Абонент № %d не найден!\n", id);
    return;
  }

  strcpy(abonents[id - 1].name, "0");
  strcpy(abonents[id - 1].second_name, "0");
  strcpy(abonents[id - 1].tel, "0");

  printf("Абонент № %d успешно удалён из справочника!\n", id);
}

void search_abonents_by_name(struct abonent *abonents) {
  if (current_count == 0) {
    printf("Справочник пуст!\n");
    return;
  }

  char name[10];
  printf("Введите имя абонента: ");
  scanf("%9s", name);

  int found = 0;
  for (int i = 0; i < current_count; i++) {
    if (strcmp(abonents[i].name, name) == 0) {
      found = 1;
      printf("Найденный абонент\n");
      printf("\tИмя: %s\n", abonents[i].name);
      printf("\tФамилия: %s\n", abonents[i].second_name);
      printf("\tНомер телефона: %s\n\n", abonents[i].tel);
    }
  }

  if (!found) {
    printf("Абоненты с именем %s не найдены!\n", name);
  }
}

void print_abonents(struct abonent *abonents) {
  if (current_count == 0) {
    printf("Справочник пуст!\n");
    return;
  }

  for (int i = 0; i < current_count; i++) {
    printf("Абонент № %d\n", i + 1);
    printf("\tИмя: %s\n", abonents[i].name);
    printf("\tФамилия: %s\n", abonents[i].second_name);
    printf("\tНомер телефона: %s\n\n", abonents[i].tel);
  }
}

int main(void) {
  system("clear");

  struct abonent abonents[COUNT_OF_ABONENTS];
  unsigned int key;

  while (key != 5) {
    print_menu();
    scanf("%d", &key);

    switch (key) {
      case 1:
        system("clear");
        add_abonent(abonents);
        break;

      case 2:
        system("clear");
        delete_abonent(abonents);
        break;

      case 3:
        system("clear");
        search_abonents_by_name(abonents);
        break;

      case 4:
        system("clear");
        print_abonents(abonents);
        break;

      case 5:
        system("clear");
        break;

      default:
        system("clear");
        printf("Нажата не та клавиша!\n");
    }
  }

  return 0;
}
