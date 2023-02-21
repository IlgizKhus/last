/*
Научитесь пользоваться стандартной структурой данных queue для целых чисел. Напишите программу,
содержащую описание очереди и моделирующую работу очереди, реализовав все указанные здесь методы. 
Программа считывает последовательность команд и в зависимости от команды выполняет ту или иную
операцию. После выполнения каждой команды программа должна вывести одну строчку.
Перед исполнением операций front и pop программа должна проверять, содержится ли в очереди хотя
бы один элемент. Если во входных данных встречается операция front или pop, и при этом очередь
пуста, то программа должна вместо числового значения вывести строку error.
*/

/*
Функции
1) push n
Добавить в очередь число n (значение n задается после команды). Программа должна вывести ok.

2) pop
Удалить из очереди первый элемент. Программа должна вывести его значение.

3) front
Программа должна вывести значение первого элемента, не удаляя его из очереди.

4) size
Программа должна вывести количество элементов в очереди.

5) clear
Программа должна очистить очередь и вывести ok.

6) exit
Программа должна вывести bye и завершить работу.
*/

#include <iostream>
#include <stdlib.h>
#include <cstring>
#pragma warning (disable:4996)

struct dec
{
    int i;
    dec* next, * prev;
};

dec* f, * b;
int i;

void push_front(int n)
{
    dec* nf = new dec;
    nf->prev = f;
    if (f != 0)
        nf->prev->next = nf;
    nf->next = 0;
    nf->i = n;
    f = nf;
    if (i == 0)
        b = f;
    i++;
    printf("ok\n");
}

void push_back(int n)
{
    dec* nb = new dec;
    nb->prev = 0;
    nb->next = b;
    if (b != 0)
        nb->next->prev = nb;
    nb->i = n;
    b = nb;
    if (i == 0)
        f = b;
    i++;
    printf("ok\n");
}

void pop_front()
{
    if (i > 0)
    {
        printf("%d\n", f->i);
        dec* nf = f->prev;
        if (i > 1)
            nf->next = 0;
        f = nf;
        i--;
        if (i == 0)
            b = 0;
    }
    else
        printf("error\n");
}

void pop_back()
{
    if (i > 0)
    {
        printf("%d\n", b->i);
        dec* nf = b->next;
        if (i > 1)
            nf->prev = 0;
        b = nf;
        i--;
        if (i == 0)
            f = 0;
    }
    else
        printf("error\n");
}

void v()
{
    dec* n = f;
    while (n != 0)
    {
        printf("%d ", n->i);
        n = n->prev;
    }
    printf("\n");
    n = b;
    while (n != 0)
    {
        printf("%d ", n->i);
        n = n->next;
    }
    printf("\n\n");
}

void front()
{
    if (i > 0)
        printf("%d\n", f->i);
    else
        printf("error\n");
}

void back()
{
    if (i > 0)
        printf("%d\n", b->i);
    else
        printf("error\n");
}

int main()
{
    f = 0;
    b = 0;
    i = 0;
    char str[40];
    int t;
    scanf("%s", &str);
    while (str[0] != 'e')
    {
        if (str[3] == 'h')
        {
            scanf("%d", &t);
            if (str[5] == 'f')
                push_front(t);
            if (str[5] == 'b')
                push_back(t);
        }
        else if (str[3] == '_')
        {
            if (str[4] == 'f')
                pop_front();
            if (str[4] == 'b')
                pop_back();
        }
        else if (str[0] == 'f')
            front();
        else if (str[0] == 'b')
            back();
        else if (str[0] == 's')
            printf("%d\n", i);
        else if (str[0] == 'c')
        {
            f = 0;
            b = 0;
            i = 0;
            printf("ok\n");
        }
        //v();
        scanf("%s", &str);
    }
    printf("bye\n");
}