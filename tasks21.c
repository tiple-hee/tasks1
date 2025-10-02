#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief рассчитывает площадь прямоугольника
 * @param a первая сторона прямоугольника
 * @param b вторая сторона прямоугольника
 * @return возвращает рассчитанный Периметр
 */
double getPR(const double a, const double b);
/**
 * @brief считывает значение, 
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
 * @brief считает площадь через синус
 * @param a первая сторона
 * @param b вторая сторона
 * @param d альфа угол
 * @return считает плошадь
 */
double getTRsin(const double a,const double b);
/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkValue(const double value);
/**
 * @return считает площадь через высоту
 * @param a сторона
 * @return значение площади
 */
double getTRh(const double a);
/**
 * @return считает площадь через радиус
 * @param a сторона
 * @param b 2 сторона
 * @return значение площади
 */
double getTRRadius(const double a,const double b);

enum {SQUAREPR=1,SQUARETR1=2,SQUARETR2=3,SQUARETR3=4};
/**
 * brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */

int main(void){
    printf("Введите а: ");
    double a=getValue();
    checkValue(a);
    printf("Введите значение B: ");
    double b=getValue();
    checkValue(b);
    printf("Введите что хотите посчитать: %d-периметр прямоугольника,\n%d-площаль треугольна через синус,\n%d-площадь треугольника через высоту,\n%d-площадь треугольнка через радус\n",SQUAREPR,SQUARETR1,SQUARETR2,SQUARETR3);
    int choise=(int) getValue();
    switch (choise)
    {
    case SQUAREPR:
        printf("Периметр прямоугольнка равен: %.2lf",getPR(a,b));
        break;
    case SQUARETR1:
        printf("Площадь треугольнка равна: %.2lf",getTRsin(a,b));
        break;
    case SQUARETR2:
        printf("Площадь треугольнка равна: %.2lf",getTRh(a));
        break;
    case SQUARETR3:
        printf("Площадь треугольнка равна: %2.lf",getTRRadius(a,b));
        break;
    default:
        printf("Неправильный выбор");
    }
    return 0;
}

double getPR(const double a,const double b)
{
    return a*b;
}


double getTRsin(const double a,const double b)
{
    printf("Введите значение синуса:");
    int d=getValue();
    return (a*b*sin(d))/2;
}

double getTRh(const double a){
    printf("Введите значение высоты:");
    int h=getValue();
    return (a*h)/2; 
}

double getTRRadius(const double a,const double b){
    printf("Введите значение радиуса:");
    int r=getValue();
    printf("Введите значение 3 стороны:");
    int c=getValue();
    return (a*b*c)/(4*r);
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