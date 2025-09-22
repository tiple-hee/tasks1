#define USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

/** 
 * @brief Расчитывает функцию B по заданной формуле
 * @param x - значение параметра x
 * @param y -значение парметра y
 * @param z- значение параметра z
 * @return рассчитанное значение
*/
double getB (const double x,const double y, const double z);
/** 
 * @brief Расчитывает функцию A по заданной формуле
 * @param x - значение параметра x
 * @param y -значение парметра y
 * @param z- значение параметра z
 * @return рассчитанное значение
*/
double getA (const double x,const double y, const double z);

/**
 * @brief точка входа в программу
 * @return возвращает 0,если программа выполнена корректно
 */

int main(){
    const double x=1.7;
    const double y=1.08;
    const double z=0.5;
    printf("A=%lf\n",getA(x,y,z));
    printf("B=%lf\n",getB(x,y,z));
    return 0;
}

double getB(const double x,const double y , const double z)
{
    return exp(-z*x) * sqrt(x+1) + exp(-y*x);
}

double getA(const double x,const double y,const double z)
{
    return sin(x)/ (sqrt(y*y + pow(sin(x),2))) - pow(x,2)*y*z;
}