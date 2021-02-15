/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:09:03 by aberry            #+#    #+#             */
/*   Updated: 2021/02/15 18:20:52 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
Перевод из 10чной системы счисления в другую
Принцип такой:
1) Остаток от деления на систему счисления находим в алфавите системы счисления
(Например: в 2ой системе имеем базу = 2 и алфавит "01", остаток 0 соответствует '0' в алфавите)
2) Делим число на систему счисления
*/

static void    conversion(int number, int base, const char alpha[], char arr[33])
{
    int        i;

    memset(arr, '0', 33);
    i = 31;
    while (number)
    {
        arr[i] = alpha[number % base];
        number /= base;
        i--;
    }
    arr[32] = '\0';
}

/*
Находим по символу который пришел на вход функции индекс в алфавите
*/

static int    index(char ch, const char alpha[])
{
    int            i;

    i = 0;
    while (alpha[i])
    {
        if (ch == alpha[i])
            return (i);
        i++;
    }
    return (0);
}

/*
Складывает числа в любой системе счисления
Алгоритм следующий:

1)Создаем int массив который будет хранить сложенные индексы двух чисел
    Примерв 2ой:(8бит)
                1100
            11111111
    равно:    11112211

2)Далее по индексу находим соотвествующий символ в алфавите, при этом если индекс > base, то переносим разряд 
    Пример в 2ой:(8бит)
            11112211 -> 100001011
        на 6 индексе остаток равен нулю, нашли соответсвующий символ в алфавите
        в переменную ost записали количество переносимых разрядов, которое равно индексу массива сумм индексов деленный на base
        и т д 
3)Выводим полученное число
*/

static void    conversion_sum(char first_num[33], char second_num[33], const char alpha[], int base)
{
    int        sum[33];
    char       sum_ch[33];
    int        ost;

    memset(sum_ch, '0', 33);
    sum_ch[32] = '\0';
    ost = 0;
    for (size_t i = 0; i < 32; i++)
    {
        sum[i] = index(first_num[i], alpha) + index(second_num[i], alpha);
    }
    for (int i = 31; i > -1; i--)
    {
        sum_ch[i] = alpha[(sum[i] + ost) % base];
        ost = ((sum[i] + ost) / base);
    }
    std::cout << sum_ch << "\n\n";
}

/*
Заменяет все символы '1' на '0' и наоборот 
*/

static void    ft_inversion_bin(char inv[33])
{
    int            i;

    i = 0;
    while (inv[i])
    {
        if (inv[i] == '0')
        {
            inv[i] = '1';
        }
        else
        {
            inv[i] = '0';
        }
        i++;
    }
}

/*
Находим разность большего числа с меньшим

Для этого необходимо:
Рассмотрим числа 7 и 5 (8бит)
1)    Прямой код числа -5: 1 000 0101
    Прямой код числа 7: 0 000 0111

2)    Формирование дополнительного кода числа -5.
        Прямой код : 1 000 0101
        Инверсия : 1 111 1010
        Добавление единицы: 1 111 1011
3)
    Операция сложения.
          0 000 0111
        + 1 111 1011
        --------------
        1 0 000 0010

4)    Проверка результата путем преобразования к прямому коду.
        Дополнительный код: 0 000 0010 -> Число положительное тк старший бит равен нулю
        -> 0 000 0010 = 2
P.S.
        В данном задании считаем что дают два положительных числа и следуюет найти разность большего с меньшим ->
        Результат всегда положительный, в случае с отрицательным результатом другой алгорим:
Рассмотрим числа 7 и 5 (8бит)
1)    Прямой код числа 5: 0 000 0101
    Прямой код числа -7: 1 000 0111

2)    Формирование дополнительного кода числа -7.
        Прямой код : 1 000 0111
        Инверсия : 1 111 1000
        Добавление единицы: 1 111 1001
3)
    Операция сложения.
        0 000 0101
      + 1 111 1001
        --------------
        1 111 1110
4)
    Проверка результата путем преобразования к прямому коду.
    Дополнительный код: 1 111 1110
    Вычитание единицы : 1 111 1101
    Инверсия : 1 000 0010 (или -2)

___________________________________________________________________________________________________________________
В своем решение я решил использовать следующий алгоритм:
    Возмем опять же числа 7 и 5, требуется найти их разность
    Дополнительный код -5 = 1 111 1011
    Как находится Дополнительный код описанно выше
    В таком случае нам достаточно найти инверсию (number) - 1
    Например:
        Число 4 = 0000 0100 а его инверия = 1 111 1011, что и является дополнительным кодом 
    Однако алгоритм отрабатывает неверно если одно число равно нулю, поэтому отдельно обработаем этот случай
*/

static void    conversion_to_bin_diff(int number_1, int number_2)
{
    char    inv[33];
    char    no_inv[33];

    if (number_1 > number_2)
    {
        if(number_2 > 0)
            conversion(number_2 - 1, 2, "01", inv);
        else
            conversion(number_2, 2, "01", inv);
        conversion(number_1, 2, "01", no_inv);
    }
    else
    {
        if(number_1 != 0)
        {
            conversion(number_1 - 1, 2, "01", inv);
        }
        else
            conversion(number_1, 2, "01", inv);
        conversion(number_2, 2, "01", no_inv);
    }
    if(number_1 != 0)
        ft_inversion_bin(inv);
    conversion_sum(no_inv, inv, "01", 2);
}

/*
Нахождение и вывод на экран данных чисел в двоичной системе счисление, а также их суммы и разности 
*/

static void    conversion_to_bin(int number_1, int number_2)
{
    char    first_num[33];
    char    second_num[33];

    conversion(number_1, 2, "01", first_num);
    conversion(number_2, 2, "01", second_num);
    std::cout << "First number in bin: \n";
    std::cout << first_num << "\n\n";
    std::cout << "Second number in bin: \n";
    std::cout << second_num << "\n\n";
    std::cout << "Sum in bin: \n";
    conversion_sum(first_num, second_num, "01", 2);
    std::cout << "Diff in bin: \n";
    conversion_to_bin_diff(number_1, number_2);
}

/*
Находит разность чисел в 16ой системе счисления
Алгоритм следующий:

1)Находим разность индексов двух чисел по алфавиту

2)Если разность оказалась отрицательной то нам необходимо взять доп разряд
    Поэтому к новому индексу прибавляем 16 а переменную ost ставим в 1
    И при следующей итерации цикла мы уменьшим разницу индексов на 1, тк мы забрали разряд

3)Выводим полученное число
*/

static void    conversion_to_hex_diff(char first_num[33], char second_num[33], const char alpha[])
{
    char       diff[33];
    int        index_new;
    int        ost;

    diff[32] = '\0';
    ost = 0;
    for (int i = 31; i > -1; i--)
    {
        index_new = index(first_num[i], "0123456789ABCDEF") - index(second_num[i], "0123456789ABCDEF") - ost;
        if (index_new < 0)
        {
            ost = 1;
            index_new += 16;
        }
        else
            ost = 0;
        diff[i] = alpha[index_new];
    }
    std::cout << diff << "\n\n";
}

/*
Нахождение и вывод на экран данных чисел в 16ой системе счисление, а также их суммы и разности 
*/

static void    conversion_to_hex(int number_1, int number_2)
{
    char    first_num[33];
    char    second_num[33];

    conversion(number_1, 16, "0123456789ABCDEF", first_num);
    conversion(number_2, 16, "0123456789ABCDEF", second_num);
    std::cout << "\n\n\nFirst number in hex: \n";
    std::cout << first_num << "\n\n";
    std::cout << "Second number in hex: \n";
    std::cout << second_num << "\n\n";
    std::cout << "Sum in hex: \n";
    conversion_sum(first_num, second_num, "0123456789ABCDEF", 16);
    std::cout << "Diff in hex: \n";
    if (number_1 > number_2)
    {
        conversion_to_hex_diff(first_num, second_num, "0123456789ABCDEF");
    }
    else
    {
        conversion_to_hex_diff(second_num, first_num, "0123456789ABCDEF");
    }
}

/*
Проверяем валидность вводимых данных, их сумма или разность не могу выходить за пределы [-2147483648,2147483647]
А также числа не могут быть отрицательными 
*/

static void    error(int number_1, int number_2)
{
    if (number_2 + number_1 > INT_MAX || number_2 - number_1 < INT_MIN || number_1 - number_2 < INT_MIN || number_1 < 0 || number_2 < 0)
    {
        std::cout <<"Error\n";
        exit(1);
    }
}

/*
Ввод чисел
*/

int            main(int argc, char const *argv[])
{
    int            first_num;
    int            second_num;

    (void)argc;
    (void)argv;
    std::cout << "Input first number: ";
    std::cin >> first_num;
    std::cout << "Input second number: ";
    std::cin >> second_num;
    error(first_num, second_num);
    conversion_to_bin(first_num, second_num);
    conversion_to_hex(first_num, second_num);
    return 0;
}
