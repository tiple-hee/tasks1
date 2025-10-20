#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
 * @brief рассчитывает значение функции Y
 * @return значение
 */
double getY(const double x);
/**
 * @brief проверяет ход на положительность
 * @param step проверяемая переменная
 */
void checkStep(const double step);
/**
 * @brief проверяет, принадлежит ли значение аргумента функции
 * её области определения
 * @param x - аргумент функции
 * @return true, если аргумент принадлежит ООФ, иначе false
 */
bool defineOOF(const double x);
/**
 * brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(){
	printf("Введите начальное значение: ");
	double start = getValue();
	printf("Введите конечное значение: ");
	double end = getValue();
	printf("Введите шаг: ");
	double step = getValue();
	checkStep(step);
    for (double x = start; x < end + DBL_EPSILON; x = x + step)
        {
            if (defineOOF(x))
            {
                printf("x = %.2lf, y = %.4lf\n", x, getY(x));
            }
            else
            {
                printf("x = %.2lf, не принадлежит ООФ\n", x);
            }
        }
        return 0;
    }


    
    void checkStep(const double step)
    {
        if (step <= DBL_EPSILON)
        {
            printf("Ошибка, шаг должен быть положительным\n");
            abort();
        }
    }
    
    bool defineOOF(const double x)
    {
        return 1+2*x+pow(x,2)>0 ;
    }
    
    
    double getY(const double x){
        return log(1/(1+2*x+pow(x,2)));
    }
    
    double getValue()
    {
        double value = 0;
        if (!scanf("%lf", &value))
        {
            printf("Error\n");
            abort();
        }
        return value;
    }
