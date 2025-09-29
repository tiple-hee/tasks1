#include <stdio.h>
#include <stdlib.h>
/**
 * @brief считает силу тока во второй лампе
 * @param x пользователь вводит с клавиатуры
 * @param y пользователь вводить с клаввиатуры
 */
int getTok(const int x,const int y);
/**
 * @brief считает сопротивление во второй лампе
 * @param x берется из 1 функции
 * @param y берется из 1 функции
 */
int getSopr(const int x,const int y);
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
 * @brief точка входа в программу
 * @return возвращает 0,если программа выполнена корренктно
 */
int main(){
    printf("Введите значение силы тока в цепи (1): ");
    int x=getValue();
    checkValue(x);
    printf("Введите значение силы тока в первой лампе (2): ");
    int y=getValue();
    checkValue(y);
    printf("Ток во второй лампер равен: %d\n",getTok(x,y));
    printf("Сопротивление равно: %d\n",getSopr(x,y));
    return 0;
}

int getTok(const int x,const int y){
    return x-y;
}

int getSopr(const int x,const int y){
    int u=220;
    return u/getTok(x,y);
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
