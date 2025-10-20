#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/** @brief считывает значение, 
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkValue(const double value);
/**
 * @brief Считает значение системы
 * @param a заданное значение,равное 1.1
 * @param x значение ,которое вводит пользователь
 */
double getSystem(const double x,const double a);
/**
 * @brief начало входа
 * @return возвращает 0,если программа ввполнена корректно
 */
int main(){
    double a=1.1;
    printf("Введите значение x:");
    double x=getValue();
    checkValue(x);
    double y=getSystem(x,a);
    printf("y = %.4f\n", y);
    return 0;
}

double getSystem(const double x,const double a){
    if (x>1.2){
        return log(x)*M_PI;
    }
    else if(x<1.2){
        return (cos(x*x)/sin(x*x)) + (a*x*x)/2;
    }
    else{
        return 3;
    }
}
double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkValue(const double value)
{
    if (value <= 0 )
    {
        printf("Value have to be positive\n");
        abort();
    }
}