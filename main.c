// Author - Koteneva Elena
// Development Environment - QT Creator 4.11
// Algorithms. Task 7.

#include <stdio.h>
#include <stdlib.h>


// 1. Описать в коде улучшенный алгоритм быстрой сортировки
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void qs(int* arr, int first, int last){
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j){
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }while (i <= j);

    if (i < last) qs(arr, i, last);
    if (first < j) qs(arr, first, j);
}

void sortInserts(int* arr, int len){
    int temp, pos;
    for (int i = 1; i < len; ++i){
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp){
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

int findMediana(int a, int b, int c){
    if ((a > b && a < c) || (a < b && a > c))
        return a;
    else
        if ((b > a && b < c) || (b < a && b > c))
            return b;
        else
            return c;
}

void imprqs(int* arr,  int first, int last){
    int i = first;
    int j = last;

    //int x = arr[(first + last) / 2];
    int x = findMediana(arr[first], arr[(first + last) / 2], arr[last]);
    swap(&x, &arr[(first + last) / 2]);

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j){
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i <= 10) sortInserts(arr, i);
    if (j <= 10) sortInserts(arr, j);

    if (i < last) qs(arr, i, last);
    if (first < j) qs(arr, first, j);

}

// 2.Сортировать в массиве целых положительных чисел только чётные числа,
// нечётные оставив на своих местах при помощи алгоритма блочной сортировки,
// то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 4 5 9 8 8 7 3]
void bucketSort(int* arr, int len){
    const int max = len;
    const int b = 10;

    int buckets[b][max + 1];
    for (int i = 0; i < b; ++i){
        buckets[i][max] = 0;
    }

    for (int digit = 1; digit < 1000000000; digit*=10){
        for (int i = 0; i < max; ++i){

            int d = (arr[i] / digit) % b;
            //int counter = buckets[d][max];
            //buckets[d][counter] = arr[i];
            //counter++;
            //buckets[d][max] = counter;
            buckets[d][buckets[d][max]++] = arr[i];

        }
        int idx = 0;
        for (int i = 0; i < b; ++i){
            for (int j = 0; j < buckets[i][max]; ++j){
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }


}
// Дополнительные функции для работы с массивом

int* initArray(int* array, const int len){
    array = (int*)calloc(sizeof(int*), len);

    return array;
}

void printIntArray(int* array, const int len){
    for (int i = 0; i < len; ++i){
        printf("%3d", *(array + i));
    }
    printf("\n");

}

void fillRandom(int* arr, int len, int border){
    for (int i = 0; i < len; ++i){
        *(arr + i) = rand() % border;
    }
}

int main()
{
//---------1------------
    const int SZ = 50;
    int* arr = initArray(arr, SZ);
    fillRandom(arr, SZ, 100);
    printf("Исходный двумерный массив:\n");
    printIntArray(arr, SZ);
    imprqs(arr, 0, SZ - 1);
    printf("Отсортированный двумерный массив:\n");
    printIntArray(arr, SZ);
//---------2------------
//    const int SZ = 15;
//    int* arr = initArray(arr, SZ);
//    int* even = initArray(even, SZ);
//    fillRandom(arr, SZ, 100);
//    printIntArray(arr, SZ);
//    int evencounter = 0;
//    for (int i = 0; i < SZ; ++i){
//        if (*(arr +i) % 2 == 0) {
//            *(even + evencounter) = *(arr + i);
//            evencounter++;
//        }
//    }
//    printIntArray(even, evencounter);
//    bucketSort(even, evencounter);
//    printf("Отсортированный массив четных чисел:\n");
//    printIntArray(even, evencounter);
//    evencounter = 0;
//    for (int i = 0; i < SZ; ++i){
//        if (*(arr + i) % 2 == 0) {
//            *(arr + i) = *(even + evencounter);
//            evencounter++;
//        }
//    }
//    printf("Конечный массив:\n");
//    printIntArray(arr, SZ);
return 0;
}


