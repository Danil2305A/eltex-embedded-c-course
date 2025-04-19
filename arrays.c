#include <stdio.h>
#include <stdlib.h>

#define N 3

// 1. Вывести квадратную матрицу по заданному N.

void task_1(void) {
  int matrix[N][N];

  int value = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      matrix[i][j] = value++;
      printf("%-2d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// 2. Вывести заданный массив размером N в обратном порядке.

void task_2(void) {
  int nums[N];

  printf("Прямой порядок: ");
  for (int i = 0; i < N; i++) {
    nums[i] = i + 1;
    printf("%d ", nums[i]);
  }

  for (int i = 0; i < N / 2; i++) {
    int temp = nums[i];
    nums[i] = nums[N - i - 1];
    nums[N - i - 1] = temp;
  }

  printf("\nОбратный порядок: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", nums[i]);
  }

  printf("\n");
}

// Заполнить верхний треугольник матрицы 0, а нижний 1.

void task_3(void) {
  int matrix[N][N];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i + j < N - 1) {
        matrix[i][j] = 0;
      } else {
        matrix[i][j] = 1;
      }

      printf("%d ", matrix[i][j]);
    }
    printf("\n");
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
