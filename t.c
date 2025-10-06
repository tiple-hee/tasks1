#include <stdio.h>
#include <math.h>

/**
 * @brief Расчитывает Параметр а из радиан в градусы
 * @param a - значение параметра вводить пользователь
 * @return расчитанное значение
 */
double getG(const double a);
/**
 * @brief Расчитывает Параметр а из радиан в секунды
 * @param a - значение параметра вводить пользователь
 * @return расчитанное значение
 */
double getS(const double a );
/**
 * @brief Расчитывает Параметр а из радиан в минуты
 * @param a - значение параметра вводить пользователь
 * @return расчитанное значение
 */
double getMin(const double a);

/**
 * @brief Точка входа в программу
 * @return возвращает 0,если программа выполнена корректно
 */
int main(void){
    double a=0;
    printf("Введите значение A");
    scanf("%lf",&a);
    printf("в градусах %lf\n",getG(a));
    printf("В минутах %lf\n",getS(a));
    printf("В секундах  %lf\n",getMin(a));
    return 0;
}

double getG(const double a)
{
    return a*180/(M_PI);
}

double getS(const double a)
{
    return getG(a)*60;
}

double getMin(const double a)
{
    return getS(a)*60;
}
