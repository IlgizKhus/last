/*
Научитесь пользоваться стандартной структурой данных stack для целых чисел. Напишите программу,
содержащую описание стека и моделирующую работу стека, реализовав все указанные здесь методы.
Программа считывает последовательность команд и в зависимости от команды выполняет ту или иную
операцию. После выполнения каждой команды программа должна вывести одну строчку.
Перед исполнением операций back и pop программа должна проверять, содержится ли в стеке хотя бы
один элемент. Если во входных данных встречается операция back или pop, и при этом стек пуст, то
программа должна вместо числового значения вывести строку error.
*/

/*
Функции
1) Добавить в стек число(push(int))
Программа должна вывести ok.

2) Удалить из стека последний элемент(pop())
Программа должна вывести его значение.

3) Вывод последнего элемента(back())
Программа должна вывести значение последнего элемента, не удаляя его из стека.

4) Вывод количества элементов(size())
Программа должна вывести количество элементов в стеке.

5) Очищение стека(clear())
Программа должна очистить стек и вывести ok.
*/

#include <iostream>
#include <stdlib.h>
#include <cstring>
#pragma warning (disable:4996)

struct stec
{
    int i;
    stec* next;
};

stec* first;

void push()
{
    int a;
    stec* nx = first;
    scanf("%d", &a);
    first = new stec;
    first->next = nx;
    first->i = a;
    printf("ok\n");
}

void pop()
{
    if (first != 0)
    {
        stec* nx = first->next;
        printf("%d\n", first->i);
        delete(first);
        first = nx;
    }
    else
        printf("error\n");
}

void back()
{
    if (first != 0)
    {
        printf("%d\n", first->i);
    }
    else
        printf("error\n");
}

void size()
{
    stec* cur = first;
    int i = 0;
    while (cur != 0)
    {
        i++;
        cur = cur->next;
    }
    printf("%d\n", i);
}

void cler()
{
    stec* nx;
    while (first != 0)
    {
        nx = first->next;
        delete(first);
        first = nx;
    }
}

int main()
{
    stec* nx;
    first = 0;
    int i, n, a;
    char str[10];
    do
    {
        scanf("%s", &str);
        if (str[0] == 'p')
        {
            if (str[1] == 'u')
            {
                push();
            }
            if (str[1] == 'o')
            {
                pop();
            }
        }
        if (str[0] == 'b')
            back();
        if (str[0] == 's')
            size();
        if (str[0] == 'c')
        {
            cler();
            printf("ok\n");
        }

    } while (str[0] != 'e');
    cler();
    printf("bye\n");
}