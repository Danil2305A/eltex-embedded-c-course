#include <stdio.h>
#include <stdlib.h>

/*
  1. Вывести двоичное представление целого положительного числа,
  используя битовые операции (число вводится с клавиатуры).
*/

void task_1(void) {
  int num;
  unsigned char bit;

  printf("Введите целое положительное число: ");
  scanf("%d", &num);
  if (num < 0) {
    printf("Введено отрицательное число!\n");
    return;
  }

  printf("Двоичное представление: ");
  for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
    bit = (num >> i) & 1;
    printf("%d", bit);
    if (i % 8 == 0) {
      printf(" ");
    }
  }

  printf("\n");
}

/*
  2. Вывести двоичное представление целого отрицательного числа,
  используя битовые операции (число вводится с клавиатуры).
*/

void task_2(void) {
  int num;
  unsigned char bit;

  printf("Введите целое отрицательное число: ");
  scanf("%d", &num);
  if (num >= 0) {
    printf("Введено положительное число!\n");
    return;
  }

  printf("Двоичное представление: ");
  num = ~abs(num) + 1;
  for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
    bit = (num >> i) & 1;
    printf("%d", bit);
    if (i % 8 == 0) {
      printf(" ");
    }
  }

  printf("\n");
}

/*
  3. Найти количество единиц в двоичном представлении целого
  положительного числа (число вводится с клавиатуры).
*/

void task_3(void) {
  int num;
  unsigned char bit;

  printf("Введите целое положительное число: ");
  scanf("%d", &num);
  if (num < 0) {
    printf("Введено отрицательное число!\n");
    return;
  }

  unsigned int count = 0;
  printf("Двоичное представление: ");
  for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
    bit = (num >> i) & 1;
    printf("%d", bit);
    if (i % 8 == 0) {
      printf(" ");
    }

    if (bit) {
      count++;
    }
  }
  printf("\nКоличество единиц в двоичном представлении: %d\n", count);
}

/*
  4. Поменять в целом положительном числе (типа int) значение третьего
  байта на введенное пользователем число (изначальное число также
  вводится с клавиатуры).
*/

void task_4(void) {
  int num;
  unsigned char byte, bit;

  printf("Введите целое положительное число и значение байта через пробел: ");
  scanf("%d %hhu", &num, &byte);
  if (num < 0) {
    printf("Введено отрицательное число!\n");
    return;
  }

  printf("Двоичное преставление числа: ");
  for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
    bit = (num >> i) & 1;
    printf("%d", bit);
    if (i % 8 == 0) {
      printf(" ");
    }
  }

  printf("\nДвоичное преставление байта: ");
  for (int i = 7; i >= 0; i--) {
    bit = (byte >> i) & 1;
    printf("%d", bit);
  }

  num = (num & ~0xFF0000) | (byte << 16);  // нумерация байтов с 1 справа налево
  printf("\nДвоичное преставление числа после замены третьего байта: ");
  for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
    bit = (num >> i) & 1;
    printf("%d", bit);
    if (i % 8 == 0) {
      printf(" ");
    }
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

      case 2:
        system("clear");
        task_2();
        break;

      case 3:
        system("clear");
        task_3();
        break;

      case 4:
        system("clear");
        task_4();
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
