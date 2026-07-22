#include <iostream>

struct dynamicArr {
  int size;
  int cap;
  int *arr;
};

void initArr(dynamicArr *&arr, int size) {
  arr = new dynamicArr;
  arr->size = size;
  arr->cap = size > 8 ? size * 2 : 8;
  arr->arr = new int[arr->cap];
}

void expandArr(dynamicArr *&arr, int newCap) {
  arr->cap *= 2;

  int *tempArr = new int[arr->cap];
  for (int i = 0; i < arr->size; i++)
    tempArr[i] = arr->arr[i];

  delete arr->arr;
  arr->arr = tempArr;
}

void insertIntoArr(dynamicArr *&arr, int num) {
  while (arr->size + 1 >= arr->cap)
    expandArr(arr, arr->cap * 2);

  arr->arr[arr->size] = num;
  arr->size++;
}

void printArr(const dynamicArr *arr) {
  for (int i = 0; i < arr->size; i++)
    printf("%d ", arr->arr[i]);

  printf("\n");
}

void deleteArr(dynamicArr *&arr) {
  delete arr->arr;
  delete arr;
}

int main() {
  dynamicArr *myArr;
  initArr(myArr, 8);
  for (int i = 0; i < myArr->size; i++)
    myArr->arr[i] = i * 10;

  printArr(myArr);
  insertIntoArr(myArr, 12);
  insertIntoArr(myArr, 13);
  insertIntoArr(myArr, 14);
  printArr(myArr);

  deleteArr(myArr);

  return 0;
}
