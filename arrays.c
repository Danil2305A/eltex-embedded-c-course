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
