#include "lab5.h"
//Для древовидных структур данных предусмотреть вывод характеристик сбалансированности дерева(средняя длина ветви)
//и процедуру выравнивания(балансировки).
//При выполнении работы произвести измерение зависимости «грязного» времени работы программы
//и ее трудоемкости(количества базовых операций).
//Оценить вид полученной зависимости(линейно - логарифмическая, квадратичная).
//Упрощенное  2 - 3 дерево.
//Вершина дерева содержит два указателя на объекты и три  указателя на  поддеревья. Данные  в  дереве  упорядочены.
//Нелистовые вершины содержат два поля, указывающие на диапазон значений в их поддеревьях.
//Значение первого поля строго больше наибольшего значения в левом поддереве и меньше
//или равно наименьшему значению в центральном поддереве;
//аналогично, значение второго поля строго больше наибольшего значения в центральном поддереве
//и меньше или равно, чем наименьшее значение в правом поддереве.
//Эти нелистовые вершины используются для направления функции поиска к нужному поддереву и,
//в конечном итоге, к нужному листу.
void main()
{
	//Несбалансированное дерево
	int Keys[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};//Массив ключевых значений
	//4-й уровень дерева
	SimpleTree Node40 = { { &Keys[5], &Keys[6] },{ NULL,NULL,NULL } };//Потомок вершины Node31
	SimpleTree Node41 = { { &Keys[8], &Keys[9] },{ NULL,NULL,NULL } };// -//-
	//3-й уровень дерева
	SimpleTree Node30 = { { &Keys[0], &Keys[1] },{ NULL,NULL,NULL } };//Потомок вершины Node20
	SimpleTree Node31 = { { &Keys[4], &Keys[7] },{ NULL,&Node40,&Node41 } };// -//-
	//2-й уровень дерева
	SimpleTree Node20 = { { &Keys[2], &Keys[3] },{ &Node30,NULL,&Node31 } };//Потомок вершины Node010
	SimpleTree Node21 = { { &Keys[11], &Keys[12] },{ NULL,NULL,NULL } };// -//-
	SimpleTree Node22 = { { &Keys[14], &Keys[15] },{ NULL,NULL,NULL } };// -//-
	SimpleTree Node23 = { { &Keys[18], &Keys[19] },{ NULL,NULL,NULL } };//Потомок вершины Node011
	SimpleTree Node24 = { { &Keys[21], &Keys[22] },{ NULL,NULL,NULL } };// -//-
	//1-й уровень дерева
	SimpleTree Node10 = { { &Keys[10], &Keys[13] },{ &Node20,&Node21,&Node22 } };//Потомок вершины Node00 (корня)
	SimpleTree Node11 = { { &Keys[17], &Keys[20] },{ NULL,&Node23,&Node24 } };// -//-
	//0-й уровень дерева (корень)
	SimpleTree Node00 = { { &Keys[16], &Keys[23] },{ &Node10,&Node11,NULL } };
	SetConsoleCP(1251);//Ввод русских букв
	SetConsoleOutputCP(1251);//Вывод русских букв
	ShowTree(&Node00);
	printf("\nКоличество ветвей дерева: %d", TreeBranchesAmount(&Node00));
	printf("\nСумма длин всех ветвей дерева: %d", BrunchLengthsSum(&Node00,0));
	printf("\nСредняя длина ветви: %f", AverageBrunchLength(&Node00));
	int NodesAmount = TreeNodesAmount(&Node00);//Количество вершин в дереве
	printf("\nКоличество вершин дерева: %d", NodesAmount);
	printf("\nМаксимальная длина ветви дерева: %d", TreeHeight(&Node00));
	int *Array=(int *)malloc(sizeof(int)*NodesAmount*DataPointersAmount);
	int Index = 0;
	Tree2Array(Array, &Node00, Index);//формирование массива из дерева
	ShowArray(Array, NodesAmount*DataPointersAmount);
	SimpleTree *PRoot = (SimpleTree *)malloc(sizeof(SimpleTree)*NodesAmount*DataPointersAmount);//Домножаем на DataPointersAmount, т.к. в вырожденном случае в вершине может оказаться всего одно значение данных
	Index = 0;
	Array2NormTree(Array, NodesAmount*DataPointersAmount, PRoot, Index);
	ShowTree(PRoot);
	printf("\n");
	system("pause");
	free(PRoot);
	free(Array);
}