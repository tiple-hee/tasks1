#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/**
 * @brief расчитывает значение из радиан в градусы
 * @param параметры вводятся с клавиатуры
 * @return рассчитанное значение
 */
double getRadians();
/**
 * @brief рассчитывает значение из градусов в радианы
 * @param параметры вводятся с  клавиатуры
 * @return рассчитанное значение
 */
double getDegrees();
/**
 * @brief считывает значение, 
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
@brief RADIAN - переводит значение из радиан в градусы
@brief GRADUSI - переводит значение иг градусов в радиан
*/
enum{RADIAN=1,GRADUSI=2};
/**
 * brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(){
    printf("Выберите %d,если хотите перевести радианы в градусы и %d,если наоборот:",RADIAN,GRADUSI);
    int choise= (int) getValue();
    switch (choise)
    {
    case(RADIAN):
        printf("Ваше значение равно: %lf",getRadians());
        break;
    case(GRADUSI):
        printf("Ваше значение радиан:%lf",getDegrees());
        break;
    default:
        printf("Неправильный выбор");
        return(1);  
    }
    return 0;
}

double getRadians(){
    printf("Введите значение радиан:");
    double radians=getValue();
    checkValue(radians);
    return radians*180/(M_PI);
}

double getDegrees(){
    printf("Введите значенмие градусов:");
    double degrees=getValue();
    checkValue(degrees);
    return degrees*(M_PI)/180;
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
