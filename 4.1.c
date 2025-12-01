#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Считывает целое число с клавиатуры с проверкой корректности.
 * @return int Введённое пользователем число.
 */
int Value();

/**
 * @brief Считывает натуральное число — размер массива.
 * @return size_t Корректный размер массива (> 0).
 */
size_t getSize();

/**
 * @brief Заполняет массив значениями, введёнными пользователем.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Печатает одномерный массив.
 * @param arr Массив для печати.
 * @param size Размер массива.
 */
void printArray(int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами 
 * @param arr Указатель на массив.
 * @param size Размер массива.
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Создаёт копию массива того же размера.
 * @param arr Исходный массив.
 * @param size Размер массива.
 * @return int* Новый массив–копия.
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Заменяет предпоследний элемент массива элементом с максимальным абсолютным значением.
 * @param arr Массив.
 * @param size Размер массива.
 */
void Zamena(int* arr, const size_t size);

/**
 * @brief Считает количество элементов массива, делящихся на N без остатка.
 * @param arr Массив.
 * @param size Размер массива.
 * @param N Делитель (не должен быть равен нулю).
 * @return int Количество элементов, кратных N.
 */
int deln(int* arr, const size_t size, int N);

/**
 * @brief Находит первую пару соседних элементов, имеющих разные знаки.
 * @param arr Массив.
 * @param size Размер массива.
 * @return int Индекс первого элемента пары; -1, если пара не найдена.
 */
int findFirstDifferentSigns(int* arr, const size_t size);

/**
@brief Manual - заполнение массива рандомно
@brief Random - заполнение массива рандомно
*/
enum{Manual=1, Random=2};

int main(){
    printf("Введите размер массива: ");
    size_t size = getSize();
    
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("error");
        exit(1);
    }
    
    printf("Выберите способ заполнения массива %d-вручную,%d-рандомно: ", Manual, Random);
    int choice = Value();
    switch(choice)
    {
        case (Random):
            fillRandom(arr, size);
            break;
        case (Manual):
            fillArray(arr, size);
            break;
        default:
            printf("error");
            free(arr);
            exit(1);
    }
    
    printf("\nИсходный массив: ");
    printArray(arr, size);
    int* arr_copy1 = copyArray(arr, size);
    printf("\n\n1. Замена предпоследнего элемента на максимальный по модулю:");
    Zamena(arr_copy1, size);
    printf("\nРезультат: ");
    printArray(arr_copy1, size);
    free(arr_copy1);
    
    printf("\n\n2. Количество элементов, делящихся на N без остатка");
    printf("\nВведите число N: ");
    const int N = Value();
    int count = deln(arr, size, N);
    printf("Количество элементов, делящихся на %d: %d", N, count);
    
    printf("\n\n3. Поиск первой пары соседних элементов с разными знаками");
    int pairIndex = findFirstDifferentSigns(arr, size);
    if (pairIndex != -1) {
        printf("\nПервая пара с разными знаками найдена на позициях %d и %d", pairIndex, pairIndex + 1);
        printf("\nЭлементы: %d и %d", arr[pairIndex], arr[pairIndex + 1]);
    } else {
        printf("\nПар с разными знаками не найдено");
    }
    
    free(arr);
    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("ERROR\n");
        abort();
    }
    return value;
}

size_t getSize()
{
    int value = Value();
    if (value <= 0)
    {
        printf("ERROR");
        abort();
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент [%zu]: ", i);
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void fillRandom(int* arr, const size_t size)
{
    const int start = Value();
    const int end = Value();
    printf("Диапазон заполнения: [%d; %d]\n", start, end);
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int) * size);
     if (copyArr == NULL)
    {
        printf("Ошибка выделения памяти ");
        return NULL;
    }

    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

void Zamena(int* arr, const size_t size){
    if (size < 2) {
        printf("\nМассив слишком мал для замены предпоследнего элемента");
        exit(1);
    }
    
    int max_index = 0;
    for (size_t i = 1; i < size; i++){
        if (abs(arr[i]) > abs(arr[max_index])){
            max_index = i;
        }
    }
    
    arr[size - 2] = arr[max_index];
}

int deln(int* arr, const size_t size, int N){
    if (N == 0) {
        printf("Ошибка: деление на ноль!");
        return 0;
    }
    
    int count = 0;
    for (size_t i = 0; i < size; i++){
        if (arr[i] % N == 0){
            count++;
        }
    }
    return count;
}

int findFirstDifferentSigns(int* arr, const size_t size){
    for (size_t i = 0; i < size - 1; i++){
        if ((arr[i] > 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] > 0)){
            return i;
        }
    }
    return -1;
}
