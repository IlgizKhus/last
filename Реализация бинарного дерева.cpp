/*
Реализуйте бинарное дерево поиска для целых чисел. Программа получает на вход последовательность
целых чисел и строит из них дерево. Элементы в деревья добавляются в соответствии с результатом
поиска их места. Если элемент уже существует в дереве, добавлять его не надо. Балансировка дерева
не производится.
*/

/*
Функции
1) Создание дерева(scan(tree*))
*/

#include <iostream>
#include <stdlib.h>
#pragma warning (disable:4996)

struct tree
{
	int num;
	tree* r;
	tree* l;
};



void scan(tree* first)
{
	int max = 0, q;
	first = new tree;
	first->num = 0;
	first->l = 0;
	first->r = 0;
	tree* c;
	scanf("%d", &q);
	first->num = q;
	while (q)
	{
		c = first;
		scanf("%d", &q);
		if (!q)
			break;
		while (c->num)
		{
			if (c->num < q)
			{
				if (c->l == 0)
				{
					c->l = new tree;
					c->l->l = 0;
					c->l->r = 0;
					c->l->num = 0;
				}
				c = c->l;
			}
			else if (c->num > q)
			{
				if (c->r == 0)
				{
					c->r = new tree;
					c->r->l = 0;
					c->r->r = 0;
					c->r->num = 0;
				}
				c = c->r;
			}
			else
			{
				break;
			}
		}
		c->num = q;
	}
}

int main()
{
	tree* derevo = 0;
	scan(derevo);
}