#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Безопасно считывает целое число с клавиатуры.
 *        При ошибке ввода завершает программу.
 * 
 * @return int Введенное пользователем число.
 */
int Value();

/**
 * @brief Запрашивает и возвращает положительный размер массива.
 *        Выводит указанное сообщение перед запросом ввода.
 * 
 * @param message Сообщение для пользователя.
 * @return size_t Положительный размер массива.
 */
size_t getSize(char* message);

/**
 * @brief Заполняет массив значениями, введенными пользователем с клавиатуры.
 *        Запрашивает каждый элемент по отдельности.
 * 
 * @param arr Указатель на массив для заполнения.
 * @param size Размер массива.
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Выводит массив в формате [элемент1, элемент2, ..., элементN].
 * 
 * @param arr Указатель на массив для вывода.
 * @param size Размер массива.
 */
void printArray(int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами в заданном диапазоне.
 * 
 * @param arr Указатель на массив для заполнения.
 * @param size Размер массива.
 * @param min Минимальное значение (включительно).
 * @param max Максимальное значение (включительно).
 */
void fillRandom(int* arr, const size_t size, int min, int max);

/**
 * @brief Заменяет предпоследний элемент массива на элемент с максимальным модулем.
 *        Если массив содержит менее 2 элементов, функция не выполняет действий.
 * 
 * @param arr Указатель на массив.
 * @param size Размер массива.
 */
void replaceMaxAbs(int* arr, const size_t size);

/**
 * @brief Вставляет элемент K после каждого четного элемента, который оканчивается на ноль.
 *        Изменяет размер массива и перераспределяет память.
 * 
 * @param arr Указатель на указатель массива (для изменения размера).
 * @param size Указатель на переменную размера (будет обновлен).
 * @param K Значение для вставки.
 */
void insertK(int** arr, size_t* size, int K);

/**
 * @brief Создаёт массив M на основе массива P:
 *        M[0] = 0, M[last] = 0, остальные элементы: M[i] = P[i] * i².
 * 
 * @param P Исходный массив.
 * @param M Результирующий массив (должен быть предварительно выделен).
 * @param size Размер массивов.
 */
void createArrayMP(int* P, int* M, const size_t size);

enum {RANDOM = 1, MANUAL};

int main()
{
    printf("Введите размер массива: ");
    size_t size = getSize(" ");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти\n");
        abort();
    }
    
    printf("Выберите способ заполнения массива:\n"
           "%d - случайными числами, %d - вручную: ", RANDOM, MANUAL);
    int choice = Value();
    
    switch(choice)
    {
        case RANDOM:
            fillRandom(arr, size, -30, 70);
            break;
        case MANUAL:
            fillArray(arr, size);
            break;
        default:
            printf("ERROR\n");
            free(arr);
            abort();
    }
    
    printf("\nИсходный массив: ");
    printArray(arr, size);
    printf("Задание 1: Заменить предпоследний элемент на максимальный по модулю s");
    if (size >= 2) {
        int* arr1 = malloc(size * sizeof(int));
        for (size_t i = 0; i < size; i++){ 
        arr1[i] = arr[i];
        }
        replaceMaxAbs(arr1, size);
        printf("Результат: ");
        printArray(arr1, size);
        free(arr1);
    } else {
        printf("Массив слишком мал для выполнения задания (нужно минимум 2 элемента)\n");
    }
    
    printf("Задание 2: Вставить элемент K после всех четных элементов, оканчивающихся на ноль");
    printf("Введите значение K: ");
    int K = Value();
    
    size_t newSize = size;
    int* arr2 = malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i++) {
        arr2[i] = arr[i];
    }
    insertK(&arr2, &newSize, K);
    printf("Результат (новый размер: %zu): ", newSize);
    printArray(arr2, newSize);
    
    printf("Задание 3: Сформировать массив M из массива P");
    int* M = malloc(size * sizeof(int));
    createArrayMP(arr, M, size);
    printf("Массив P: ");
    printArray(arr, size);
    printf("Массив M: ");
    printArray(M, size);
    free(M);
    free(arr2);
    free(arr);
    
    return 0;
}

int Value()
{
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Ошибка ввода\n");
        exit(1);
    }
    return value;
}

size_t getSize(char* message)
{
    int value = Value();
    if (value <= 0)
    {
        printf("Размер должен быть положительным\n");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    if (arr == NULL)
    {
        printf("Ошибка: передан NULL указатель в fillArray\n");
        abort();
    }
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент arr[%zu] = ", i);
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    if (arr == NULL)
    {
        printf("Ошибка: передан NULL указатель в printArray\n");
        abort();
    }
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void fillRandom(int* arr, const size_t size, int min, int max)
{
    if (arr == NULL)
    {
        printf("Ошибка: передан NULL указатель в fillRandom\n");
        abort();
    }
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}
void replaceMaxAbs(int* arr, const size_t size)
{
    if (arr == NULL)
    {
        printf("Ошибка: передан NULL указатель в replaceMaxAbs\n");
        abort();
    }
    
    if (size < 2){ 
    printf("Массив слишком мал для замены предпоследнего элемента");
    return;
    }
    int maxAbsIndex = 0;
    int maxAbsValue = abs(arr[0]);
    
    for (size_t i = 1; i < size; i++)
    {
        int absValue = abs(arr[i]);
        if (absValue > maxAbsValue)
        {
            maxAbsValue = absValue;
            maxAbsIndex = i;
        }
    }
    arr[size - 2] = arr[maxAbsIndex];
}

void insertK(int** arr, size_t* size, int K){
         if (arr == NULL)
    {
        printf("Ошибка: передан NULL указатель в insertK\n");
        abort();
    }
    int countToInsert = 0;
    for (size_t i = 0; i < *size; i++)
    {
        if ((*arr)[i] % 2 == 0 && (*arr)[i] % 10 == 0 )
        {
            countToInsert++;
        }
    }
    
    if (countToInsert == 0){
        printf("Ошибка");
        return;
    }
    
    size_t newSize = *size + countToInsert;
    int* newArr = malloc(newSize * sizeof(int));
    size_t newIndex = 0;
    for (size_t i = 0; i < *size; i++)
    {
        newArr[newIndex++] = (*arr)[i];
        
        if ((*arr)[i] % 2 == 0 && (*arr)[i] % 10 == 0)
        {
            newArr[newIndex++] = K;
        }
    }
    free(*arr);
    *arr = newArr;
    *size = newSize;
}
void createArrayMP(int* P, int* M, const size_t size)
{
    if (size == 0){
        printf("Ошибка");
        return;
    }
    M[0] = 0;
    if (size > 1)
    {
        M[size - 1] = 0;
        for (size_t i = 1; i < size - 1; i++)
        {
            M[i] = P[i] * (i * i);
        }
    }
}
