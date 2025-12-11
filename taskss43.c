#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/**
 * @brief считывает целое число с клавиатуры с проверкой ввода
 * @return считанное значение
 */
int getValue();

/**
 * @brief считывает размер массива (натуральное число)
 * @param message сообщение, выводимое перед вводом
 * @return size_t — корректный размер массива > 0
 */
size_t getSize(char* message);

/**
 * @brief выделяет память под двумерный массив размером rows × columns
 * @param rows количество строк
 * @param columns количество столбцов
 * @return int** указатель на созданный двумерный массив
 */
int** allocateArray(const size_t rows, const size_t columns);

/**
 * @brief освобождает память, выделенную под двумерный массив
 * @param arr указатель на двумерный массив
 * @param rows количество строк
 */
void freeArray(int** arr, const size_t rows);

/**
 * @brief заполняет двумерный массив значениями, введёнными пользователем
 * @param arr указатель на двумерный массив
 * @param rows количество строк
 * @param columns количество столбцов
 */
void fillArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief заполняет двумерный массив случайными числами из заданного диапазона
 * @param arr указатель на двумерный массив
 * @param rows количество строк
 * @param columns количество столбцов
 */
void fillRandom(int** arr, const size_t rows, const size_t columns);

/**
 * @brief печатает двумерный целочисленный массив на экран
 * @param arr указатель на двумерный массив
 * @param rows количество строк
 * @param columns количество столбцов
 */
void printArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief заменяет четные элементы (с индексами 2, 4, 6...) каждой строки нулями
 *        (индексация с 1, как в условии)
 * @param arr указатель на двумерный массив
 * @param rows количество строк
 * @param columns количество столбцов
 */
void replaceEvenElementsWithZero(int** arr, const size_t rows, const size_t columns);

/**
 * @brief находит минимальное значение во всем массиве
 * @param arr указатель на двумерный массив
 * @param rows количество строк
 * @param columns количество столбцов
 * @return int минимальное значение в массиве
 */
int findMinValue(int** arr, const size_t rows, const size_t columns);

/**
 * @brief подсчитывает количество строк, содержащих заданное значение
 * @param arr указатель на двумерный массив
 * @param rows количество строк
 * @param columns количество столбцов
 * @param value искомое значение
 * @return int количество строк, содержащих value
 */
int countRowsWithValue(int** arr, const size_t rows, const size_t columns, int value);

/**
 * @brief создает новый массив с вставленными строками после строк с минимальным значением
 * @param arr исходный массив
 * @param rows количество строк в исходном массиве
 * @param columns количество столбцов
 * @param newRows указатель для сохранения нового количества строк
 * @return int** новый массив с вставленными строками
 */
int** insertRowsAfterMin(int** arr, const size_t rows, const size_t columns, size_t* newRows);

/**
 * @brief генерирует строку с числами 1, 2, 3... для вставки
 * @param row строка для заполнения
 * @param columns количество столбцов
 */
void generateSequenceRow(int* row, const size_t columns);

/**
 * @brief копирует строку из одного массива в другой
 * @param dest строка назначения
 * @param src исходная строка
 * @param columns количество столбцов
 */
void copyRow(int* dest, int* src, const size_t columns);

/**
@brief MANUAL - заполнение массива вручную
@brief RANDOM - заполнение массива рандомно
*/
enum { RANDOM = 1, MANUAL };

int main()
{
    printf("=== Создание и обработка многомерного массива ===\n\n");
    size_t rows = getSize("Введите количество строк массива: ");
    size_t columns = getSize("Введите количество столбцов массива: ");
    int** arr = allocateArray(rows, columns);
    printf("\nВыберите способ заполнения массива:\n");
    printf("%d — случайными числами\n", RANDOM);
    printf("%d — вручную с клавиатуры\n", MANUAL);
    printf("Ваш выбор: ");
    
    int choice = getValue();
    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, rows, columns);
        break;
    case MANUAL:
        fillArray(arr, rows, columns);
        break;
    default:
        printf("Ошибка: неверный выбор!\n");
        freeArray(arr, rows);
        return 1;
    }
    printf("\nИсходный массив:\n");
    printArray(arr, rows, columns);
    replaceEvenElementsWithZero(arr, rows, columns);
    printf("\nМассив после замены четных элементов нулями:\n");
    printArray(arr, rows, columns);
    size_t newRows;
    int** newArr = insertRowsAfterMin(arr, rows, columns, &newRows);
    
    printf("\nМассив после вставки строк после строк с минимальным значением:\n");
    printArray(newArr, newRows, columns);
    freeArray(arr, rows);
    freeArray(newArr, newRows);
    
    printf("\nПрограмма завершена успешно.\n");
    return 0;
}

int getValue()
{
    int value;
    if (scanf("%d", &value) != 1)
    {
        printf("Ошибка ввода! Программа завершена.\n");
        exit(1);
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = getValue();
    if (value <= 0)
    {
        printf("Ошибка: размер должен быть положительным числом!\n");
        exit(1);
    }
    return (size_t)value;
}

int** allocateArray(const size_t rows, const size_t columns)
{
    int** arr = (int**)malloc(rows * sizeof(int*));
    if (!arr)
    {
        printf("Ошибка выделения памяти для строк!\n");
        exit(1);
    }
    
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = (int*)malloc(columns * sizeof(int));
        if (!arr[i])
        {
            printf("Ошибка выделения памяти для столбцов!\n");
            for (size_t j = 0; j < i; j++)
                free(arr[j]);
            free(arr);
            exit(1);
        }
    }
    
    return arr;
}

void freeArray(int** arr, const size_t rows)
{
    for (size_t i = 0; i < rows; i++)
        free(arr[i]);
    free(arr);
}

void fillArray(int** arr, const size_t rows, const size_t columns)
{
    printf("\nЗаполнение массива вручную:\n");
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Введите элемент [%zu][%zu]: ", i, j);
            arr[i][j] = getValue();
        }
    }
}

void fillRandom(int** arr, const size_t rows, const size_t columns)
{
    printf("\nЗаполнение массива случайными числами:\n");
    printf("Введите начало диапазона: ");
    int start = getValue();
    printf("Введите конец диапазона: ");
    int end = getValue();
    
    if (start > end)
    {
        printf("Ошибка: начало диапазона больше конца! Исправление...\n");
        int temp = start;
        start = end;
        end = temp;
    }
    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = rand() % (end - start + 1) + start;
        }
    }
}

void printArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        printf("Строка %zu: ", i);
        for (size_t j = 0; j < columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

void replaceEvenElementsWithZero(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 1; j < columns; j += 2)
        {
            arr[i][j] = 0;
        }
    }
}

int findMinValue(int** arr, const size_t rows, const size_t columns)
{
    int minValue = INT_MAX;
    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (arr[i][j] < minValue)
            {
                minValue = arr[i][j];
            }
        }
    }
    
    return minValue;
}

int countRowsWithValue(int** arr, const size_t rows, const size_t columns, int value)
{
    int count = 0;
    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (arr[i][j] == value)
            {
                count++;
                break;
            }
        }
    }
    
    return count;
}

int** insertRowsAfterMin(int** arr, const size_t rows, const size_t columns, size_t* newRows)
{
    int minValue = findMinValue(arr, rows, columns);
    int rowsWithMin = countRowsWithValue(arr, rows, columns, minValue);
    *newRows = rows + rowsWithMin;
    int** newArr = allocateArray(*newRows, columns);
    size_t newIndex = 0;
    
    for (size_t i = 0; i < rows; i++)
    {
        copyRow(newArr[newIndex], arr[i], columns);
        newIndex++;
        int containsMin = 0;
        for (size_t j = 0; j < columns; j++)
        {
            if (arr[i][j] == minValue)
            {
                containsMin = 1;
                break;
            }
        }
        if (containsMin)
        {
            generateSequenceRow(newArr[newIndex], columns);
            newIndex++;
        }
    }
    
    return newArr;
}

void generateSequenceRow(int* row, const size_t columns)
{
    for (size_t j = 0; j < columns; j++)
    {
        row[j] = (int)(j + 1);  // 1, 2, 3, ...
    }
}

void copyRow(int* dest, int* src, const size_t columns)
{
    for (size_t j = 0; j < columns; j++)
    {
        dest[j] = src[j];
    }
}
