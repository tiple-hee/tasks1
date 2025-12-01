#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Считывает целое число с клавиатуры с проверкой корректности ввода.
 * 
 * @return int — введённое пользователем число.
 */
int Value();

/**
 * @brief Считывает размер массива (натуральное число).
 *
 * @param message Сообщение, выводимое перед вводом.
 * @return size_t — корректный размер массива > 0.
 */
size_t getSize(char* message);

/**
 * @brief Заполняет двумерный массив значениями, введёнными пользователем.
 *
 * @param arr Указатель на двумерный массив.
 * @param rows Количество строк.
 * @param columns Количество столбцов.
 */
void fillArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Печатает двумерный целочисленный массив на экран.
 *
 * @param arr Указатель на двумерный массив.
 * @param rows Количество строк.
 * @param columns Количество столбцов.
 */
void printArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Заполняет двумерный массив случайными числами из заданного диапазона.
 *
 * @param arr Указатель на двумерный массив.
 * @param rows Количество строк.
 * @param columns Количество столбцов.
 */
void fillRandom(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Выделяет память под двумерный массив размером rows × columns.
 *
 * @param rows Количество строк.
 * @param columns Количество столбцов.
 * @return int** Указатель на созданный двумерный массив.
 */
int** getArray(const size_t rows, const size_t columns);

/**
 * @brief Освобождает память, выделенную под двумерный массив.
 *
 * @param arr Указатель на двумерный массив.
 * @param rows Количество строк.
 * @return int** Всегда возвращает NULL.
 */
int** freeArray(int** arr, const size_t rows);

/**
 * @brief Проверяет корректность диапазона случайных чисел.
 *
 * @param start Начало диапазона.
 * @param end Конец диапазона.
 */
void checkRange(const int start, const int end);

/**
 * @brief Проверяет существование строки в массиве.
 *
 * @param row Номер строки.
 * @param rows Общее количество строк.
 */
void chekrow(const size_t row, const size_t rows);

/**
 * @brief Для каждой строки массива заменяет предпоследний элемент
 *        элементом с максимальным модулем в этой строке.
 *
 * @param arr Указатель на двумерный массив.
 * @param rows Количество строк.
 * @param columns Количество столбцов.
 */
void replaceabs(int** arr, size_t rows, size_t columns);

/**
 * @brief Создаёт новый массив, добавляя число K после каждого элемента,
 *        кратного 10 (но не равного 0).
 *
 * @param arr Исходный одномерный массив.
 * @param size Размер массива arr.
 * @param K Число, вставляемое после элементов, кратных 10.
 * @param newSize Указатель для записи размера нового массива.
 * @return int* Новый массив, содержащий дополнительные элементы.
 */
int* kposlech(const int* arr, int size, int K, int* newSize);

/**
 * @brief Создаёт массив M на основе массива P:
 *        M[0] = 0, M[last] = 0, остальные элементы: M[i] = P[i] * i².
 *
 * @param P Исходный массив.
 * @param size Размер массива.
 * @return int* Новый массив M.
 */
int* createArrayP(const int* P, int size);

/**
 * @brief Печатает одномерный массив.
 * @param arr Массив для печати.
 * @param size Размер массива.
 */
void printArray1D(const int* arr, int size);

enum {RANDOM = 1, MANUAL};

int main()
{
    size_t rows = getSize("Введите количество строк массива: ");
    size_t columns = getSize("Введите количество столбцов массива: ");
    int** arr = getArray(rows, columns);

    printf("Выберите способ заполнения массива:\n"
           "%d — случайными числами, %d — вручную\n", RANDOM, MANUAL);

    int choice = Value();
    switch(choice)
    {
        case RANDOM:
            fillRandom(arr, rows, columns);
            break;
        case MANUAL:
            fillArray(arr, rows, columns);
            break;
        default:
            printf("Неверный выбор!\n");
            freeArray(arr, rows);
            return 1;
    }

    printf("Исходный массив:\n");
printArray(arr, rows, columns);

replaceabs(arr, rows, columns);

printf("Массив после replaceabs:\n");
printArray(arr, rows, columns);
int flatSize = rows * columns;
int* flat = malloc(flatSize * sizeof(int));
int idx = 0;

for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < columns; j++)
        flat[idx++] = arr[i][j];
freeArray(arr, rows);

printf("Введите K: ");
int K = Value();

int newSize;
int* flat2 = kposlech(flat, flatSize, K, &newSize);

printf("\nМассив после kposlech:\n");
printArray1D(flat2, newSize);

int* M = createArrayP(flat2, newSize);

printf("Массив M (результат createArrayP):\n");
printArray1D(M, newSize);
free(flat);
free(flat2);
free(M);

return 0;
}
 
int Value()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("ERROR\n");
        exit(1);
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("ERROR\n");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Введите a[%zu,%zu] = ", i, j);
            arr[i][j] = Value();
        }
    }
}

void printArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
            printf("%5d", arr[i][j]);

        printf("\n");
    }
    printf("\n");
}

void fillRandom(int** arr, const size_t rows,const size_t columns)
{
    printf("Введите начало диапазона: ");
    int start = Value();
    printf("Введите конец диапазона: ");
    int end = Value();
    checkRange(start, end);

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            arr[i][j] = (rand() % (end - start + 1)) + start;
}

int** getArray(const size_t rows, const size_t columns)
{
    int** arr = malloc(rows * sizeof(int*));
    if (!arr)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }

    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = malloc(columns * sizeof(int));
        if (!arr[i])
        {
            printf("Ошибка выделения памяти!\n");
            exit(1);
        }
    }

    return arr;
}

int** freeArray(int** arr, const size_t rows)
{
    for (size_t i = 0; i < rows; i++)
        free(arr[i]);

    free(arr);
    return NULL;
}

void checkRange(const int start, const int end)
{
    if (start > end)
    {
        printf("Ошибка: начало больше конца!\n");
        exit(1);
    }
}

void chekrow(const size_t row, const size_t rows)
{
    if (row >= rows)
    {
        printf("Ошибка: неправильный номер строки!\n");
        exit(1);
    }
}
void replaceabs(int** arr, size_t rows, size_t columns)
{
    if (columns < 2)
    {
        printf("Ошибка: в строках меньше 2 элементов\n");
        return;
    }

    for (size_t r = 0; r < rows; r++)
    {
        int maxAbsIndex = 0;

        for (size_t j = 1; j < columns; j++)
        {
            if (abs(arr[r][j]) > abs(arr[r][maxAbsIndex]))
                maxAbsIndex = j;
        }
        arr[r][columns - 2] = arr[r][maxAbsIndex];
    }
}

int* kposlech(const int* arr, int size, int K, int* newSize)
{
    int insertCount = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 == 0 && arr[i] % 10 == 0 && arr[i] != 0)
            insertCount++;

    *newSize = size + insertCount;
    int* result = malloc((*newSize) * sizeof(int));
    if (!result)
    {
        printf("Ошибка: не удалось выделить память\n");
        *newSize = size;
        return NULL;
    }
    int w = 0;
    for (int i = 0; i < size; i++)
    {
        result[w++] = arr[i];

        if (arr[i] % 2 == 0 && arr[i] % 10 == 0 && arr[i] != 0)
            result[w++] = K;
    }

    return result;
}

int* createArrayP(const int* P, int size)
{
    if (size <= 0) return NULL;

    int* M = malloc(size * sizeof(int));
    if (!M) return NULL;

    M[0] = 0;
    if (size > 1)
        M[size - 1] = 0;

    for (int i = 1; i < size - 1; i++)
        M[i] = P[i] * i * i;

    return M;
}
void printArray1D(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%5d ", arr[i]);
    printf("\n");
}
