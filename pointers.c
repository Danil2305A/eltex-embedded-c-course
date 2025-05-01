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

/*
  2. В приведенном ниже коде измените только одну строку (помеченную),
  чтобы напечатать “Результат: 12.0”.
*/

void task_2(void) {
  float x = 5.0;
  printf("x = %f, ", x);
  float y = 6.0;
  printf("y = %f\n", y);
  float *xp = &x + 1;  // Отредактированная строка
  float *yp = &y;
  printf("Результат: %f\n", *xp + *yp);
}  // Пояснение: в памяти x и y расположены последовательно

/*
  3. Напишите программу, в которой определите массив типа int (размер
  массива 10 элементов от 1 до 10). Используйте указатель для вывода
  элементов массива на консоль (применять можно только арифметику
  указателей, а не индексы).
*/

void task_3(void) {
  int nums[10];

  for (int i = 0; i < 10; i++) {
    *(nums + i) = i + 1;
    printf("%d ", *(nums + i));
  }

  printf("\n");
}

/*
  4. Напишите программу, которая ищет введенной строке (с клавиатуры)
  введенную подстроку (с клавиатуры) и возвращает указатель на начало
  подстроки, если подстрока не найдена, в указатель записывается NULL.
  В качестве строк использовать статические массивы.
*/

const char *find_substring(const char *str, const char *substr) {
  while (*str != '\0') {
    const char *str_p = str;
    const char *substr_p = substr;

    while (*str_p == *substr_p && *substr_p != '\0') {
      str_p++;
      substr_p++;
    }

    if (*substr_p == '\0') {
      return str;
    }
    str++;
  }

  return NULL;
}

void task_4(void) {
  char str[80];
  char substr[80];

  getchar();
  printf("Введите строку (до 80 символов): ");
  scanf("%80[^\n]", str);
  getchar();
  printf("Введите подстроку (до 80 символов): ");
  scanf("%80[^\n]", substr);

  printf("Строка: %s\n", str);
  printf("Подстрока: %s\n", substr);

  const char *result = find_substring(str, substr);
  if (!result) {
    printf("Подстрока не найдена в строке!\n");
  } else {
    printf("Подстрока найдена в строке! %s\n", result);
  }
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
