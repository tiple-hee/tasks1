#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
 * @brief Считывает вещественное значение с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getDouble();

/*
 * @brief Проверяет, что минимальное значение меньше максимального
 * @param min минимальное значение промежутка
 * @param max максимальное значение промежутка
 */
void checkMM(const double min, const double max);

/*
 * @brief Проверяет, что шаг функции положительный
 * @param step значение шага функции
 */
void checkStep(const double step);

/*
 * @brief Проверяет, что число положительное
 * @param value проверяемое значение
 */
void checkPositive(const double value);

/*
 * @brief Вычисляет значение заданной функции
 * @param x значение параметра x
 * @param variant номер варианта (1 или 2)
 * @return рассчитанное значение
 */
double func(const double x, const int variant);

/*
 * @brief Вычисляет коэффициент рекуррентного выражения
 * @param n текущий индекс
 * @param x значение параметра x
 * @param variant номер варианта (1 или 2)
 * @return рассчитанное значение
 */
double getRecurrent(const int n, const double x, const int variant);

/*
 * @brief Считает сумму членов ряда с точностью e
 * @param e заданная точность
 * @param x значение параметра x
 * @param variant номер варианта (1 или 2)
 * @return рассчитанное значение
 */
double getSumE(const double e, const double x, const int variant);

/*
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    int variant;
    printf("Выберите вариант функции (1 или 2):\n");
    printf("1: y = 3**x \n");
    printf("2: y = sin(x)\n");
    printf("Ваш выбор: ");
    
  if (scanf("%d", &variant) != 1)
{
    printf("Ошибка ввода: введите целое число\n");
    exit(1);
}

if (variant != 1 && variant != 2)
{
    printf("Ошибка: выберите 1 или 2\n");
    exit(1);
}

    printf("Введите начальное значение: ");
    double min = getDouble();
    printf("Введите конечное значение: ");
    double max = getDouble();
    checkMM(min, max);
    printf("Введите шаг: ");
    double step = getDouble();
    checkStep(step);
    printf("Введите точность e: ");
    double e = getDouble();
    checkPositive(e);
    for (double x = min; x <= max + DBL_EPSILON; x += step)
    {
        printf("x = %.4lf, y(x) = %.6lf, S(x) = %.6lf\n",
               x, func(x, variant), getSumE(e, x, variant));
    }
    return 0;
}

double getDouble()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Ошибка, введено неверное значение!\n");
        exit(1);
    }
    return value;
}

void checkMM(const double min, const double max)
{
    if (min + DBL_EPSILON >= max)
    {
        printf("Ошибка, минимальное значение должно быть меньше максимального!\n");
        exit(1);
    }
}

void checkStep(const double step)
{
    if (step <= DBL_EPSILON)
    {
        printf("Ошибка, шаг должен быть положительным!\n");
        exit(1);
    }
}

void checkPositive(const double value)
{
    if (value <= DBL_EPSILON)
    {
        printf("Ошибка, число должно быть положительным!\n");
        exit(1);
    }
}

double func(const double x, const int variant)
{
    if (variant == 1)
    {
        return pow(3.0, x);
    }
    else 
    {
        return sin(x);
    }
}

double getRecurrent(const int n, const double x, const int variant)
{
    if (variant == 1)
    {
        return (log(3.0) * x) / n;
    }
    else 
    {
        return -x * x / ((2.0 * n + 1.0) * (2.0 * n + 2.0));
    }
}

double getSumE(const double e, const double x, const int variant)
{
    double current, sum;
    
    if (variant == 1)
    {
        current = 1.0;
        sum = current;
        
        for (int n = 1; fabs(current) > e; n++)
        {
            current *= getRecurrent(n, x, variant);
            sum += current;
        }
    }
    else
    {
        current = x;
        sum = current;
        
        for (int n = 0; fabs(current) > e; n++)
        {
            current *= getRecurrent(n, x, variant);
            sum += current;
        }
    }
    return sum;
}