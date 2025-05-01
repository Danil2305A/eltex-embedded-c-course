#include <stdio.h>
#include <stdlib.h>

/*
  1. Поменять в целом положительном числе (типа int) значение третьего
  байта на введенное пользователем число (изначальное число также
  вводится с клавиатуры) через указатель (не применяя битовые
  операции).
*/

void task_1(void) {
  int num;
  unsigned char byte;

  printf("Введите целое положительное число и значение байта через пробел: ");
  scanf("%d %hhu", &num, &byte);
  if (num < 0) {
    printf("Введено отрицательное число!\n");
    return;
  }

  printf("Исходное число (по байтам): ");
  unsigned char *ptr = (unsigned char *)&num;
  printf("%d ", *ptr);
  for (int i = 1; i < sizeof(int); i++) {
    ptr++;
    printf("%d ", *ptr);
  }
  printf("\nЗначение байта: %d\n", byte);

  ptr = (unsigned char *)&num;
  *(ptr + 2) = byte;

  printf("Число с изменённым третьим байтом (по байтам): ");
  ptr = (unsigned char *)&num;
  printf("%d ", *ptr);
  for (int i = 1; i < sizeof(int); i++) {
    ptr++;
    printf("%d ", *ptr);
  }

  printf("\n");
}

int main(void) {
  system("clear");
  unsigned int key;

  while (key != 0) {
    printf("Введите номер задания (или 0 для выхода): ");
    scanf("%d", &key);

    switch (key) {
      case 1:
        system("clear");
        task_1();
        break;

      case 0:
        system("clear");
        break;

      default:
        system("clear");
        printf("Нет такого задания!\n");
    }
  }

  return 0;
}
