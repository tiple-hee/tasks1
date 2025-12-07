#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
/**
 * @brief Считывает вещественное значение с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double Double();
/**
 * @brief Проверяет, что минимальное значение меньше максимального
 * @param min минимальное значение промежутка
 * @param max максимальное значение промежутка
 */
void checkMinandMax(const double min, const double max);
/**
 * @brief Проверяет, что шаг функции положительный
 * @param shag значение шага функции
 */
void checkShag(const double shag);
/**
 * @brief Проверяет, что число положительное
 * @param value проверяемое значение
 */
void checkPlus(const double value);
/**
 * @brief Вычисляет синус от x
 * @param x значение параментра x
 * @return рассчитанное значение
 */
double Functionsinus(const double x);
/**
 * @brief Вычисляет коэффициент рекуррентного выражения
 * @param n текущий индекс
 * @param x значение параментра x
 * @return рассчитанное значение 
 */
double Rec(const int n, const double i);
/**
 * @brief Считает сумму членов последовательности с точностью e
 * @param e заданная точность
 * @param x значение параметра x
 * @return рассчитанное значение
 */
double getSumE(const double e, const double x);
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    printf("Введите первичное значение: ");
    double min = Double();
    printf("Введите окончательное значение: ");
    double max = Double();
    checkMinandMax(min, max);
    printf("Введите шаг: ");
    double shag = Double();
    checkShag(shag);
    printf("Введите e: ");
    double e = Double();
    checkPlus(e);
    for (double x = min; x <= max + DBL_EPSILON; x += shag)
    {
        printf("x = %.4lf, sin(x) = %.6lf, S = %.6lf\n", x, Functionsinus(x), getSumE(e, x));
    }
    return 0;
}
double Double()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Ошибка в вводе значения\n");
        exit(1);
    }
    return value;
}
void checkMinandMax(const double min, const double max)
{
    if (min + DBL_EPSILON >= max)
    {
        printf("Error: должно быть (Min < max)\n");
        exit(1);
    }
}
void checkShag(const double shag)
{
    if (shag <= DBL_EPSILON)
    {
        printf("Ошибка,шаг должен быть >0 !\n");
        exit(1);
    }
}
void checkPlus(const double value)
{
    if (value <= DBL_EPSILON)
    {
        printf("Ошибка,число должно быть + \n");
        exit(1);
    }
}

double Functionsinus(const double x)
{
    return sin(x);
}
double Rec(const int n, const double i)
{
    return -pow(i,2) / ((2.0 * n + 2.0) * (2.0 * n + 3.0));
}
double getSumE(const double e, const double x)
{
    double cur = x;
    double summa = cur;
    for (int n = 0; fabs(cur) > e; n++)
    {
        cur *= Rec(n, x);
        summa += cur;
    }
    return summa;
}
