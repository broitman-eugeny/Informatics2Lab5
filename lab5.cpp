#include "lab5.h"
//Функция вычисления количества ветвей дерева
//PRoot - указатель на корень дерева
int TreeBranchesAmount(SimpleTree *PRoot)
{
	if (PRoot == NULL)//Дошли до конца ветви
	{
		return 1;//Добавить одну ветку 
	}
	int BranchesAmount = 0;
	for (int i = 0; i < ChildPointersAmount; i++)//По всем потомкам корня
	{
		BranchesAmount += TreeBranchesAmount(PRoot->PChildren[i]);
	}
	return BranchesAmount;
}
//Функция вычисления суммы длин всех ветвей дерева.
//PRoot - указатель на корень (вершину) дерева
//Level - уровень корня (вершины) дерева - 0
int BrunchLengthsSum(SimpleTree *PRoot, int Level)
{
	if (PRoot == NULL)//Дошли до конца ветви
	{
		return Level ;//Учитываем ветки к нулевым вершинам
	}
	int LengthsSum = 0;
	for (int i = 0; i < ChildPointersAmount; i++)//По всем потомкам корня
	{
		LengthsSum += BrunchLengthsSum(PRoot->PChildren[i], Level + 1);
	}
		return LengthsSum;
}
//Функция вычисляет среднюю длину ветви дерева.
//Деление суммы длин ветвей на количество нулевых узлов дает среднюю
//длину ветви дерева.
//PRoot - указатель на корень дерева
double AverageBrunchLength(SimpleTree *PRoot)
{
	int LengthsSum = BrunchLengthsSum(PRoot, 0);//Суммарная длина всех ветвей
	int BranchesAmount = TreeBranchesAmount(PRoot);//Количество ветвей
	return (double)LengthsSum/ (double)BranchesAmount;
}
//Функция вычисляет количество вершин дерева
//PRoot - указатель на корень дерева
int TreeNodesAmount(SimpleTree *PRoot)
{
	if (PRoot == NULL)//Дошли до конца ветви
	{
		return 0;
	}
	int NodesAmount = 1;
	for (int i = 0; i < ChildPointersAmount; i++)//По всем потомкам корня
	{
		NodesAmount += TreeNodesAmount(PRoot->PChildren[i]);
	}
	return NodesAmount;
}
//Функция вычисляет максимальную длину ветви дерева с учетом веток к нулевым вершинам
//PRoot - указатель на корень дерева
int TreeHeight(SimpleTree *PRoot)
{
	if (PRoot == NULL)//Дошли до конца ветви
	{
		return 0;
	}
	int Heights[ChildPointersAmount];
	for (int i = 0; i < ChildPointersAmount; i++)//По всем потомкам корня
	{
		Heights[i] = TreeHeight(PRoot->PChildren[i]);
	}
	return Heights[MaxInt(Heights, ChildPointersAmount)]+1;
}
//Функция возвращает индекс максимального целочисленного значения в массиве
//Dim - массив целых чисел
//N - размер массива
int MaxInt(int *Dim, int N)
{
	int MaxInd = 0;
	for (int i = 1; i < N; i++)
	{
		if (Dim[i] > Dim[MaxInd])
		{
			MaxInd = i;
		}
	}
	return MaxInd;
}
//Функция вычисляет минимальную длину ветви дерева с учетом веток к нулевым вершинам
//PRoot - указатель на корень дерева
int MinBranchLength(SimpleTree *PRoot)
{
	if (PRoot == NULL)//Дошли до конца ветви
	{
		return 0;
	}
	int Heights[ChildPointersAmount];
	for (int i = 0; i < ChildPointersAmount; i++)//По всем потомкам корня
	{
		Heights[i] = TreeHeight(PRoot->PChildren[i]);
	}
	return Heights[MinInt(Heights, ChildPointersAmount)] + 1;
}
//Функция возвращает индекс минимального целочисленного значения в массиве
//Dim - массив целых чисел
//N - размер массива
int MinInt(int *Dim, int N)
{
	int MinInd = 0;
	for (int i = 1; i < N; i++)
	{
		if (Dim[i] < Dim[MinInd])
		{
			MinInd = i;
		}
	}
	return MinInd;
}
//Функция отображает дерево
//PRoot - указатель на корень дерева
void ShowTree(SimpleTree *PRoot)
{
	int Height = TreeHeight(PRoot);//Высота дерева с учетом нулевых веток
	printf("\n");
	for (int i = 0; i < Height; i++)
	{
		ShowLevel(PRoot,i, Height);//Отображает один уровень дерева
		printf("\n");
	}
}
//Функция отображает один уровень дерева
//PRoot - указатель на корень дерева
//ReqLevel - номер печатаемого уровня
//Height - высота дерева, включающая ветки к нулевым вершинам
//TempLevel - текущий уровень (для поиска вершин печатаемого уровня)
void ShowLevel(SimpleTree *PRoot, int ReqLevel, int Height, int TempLevel)
{
	char FormatS[5];
	FormatS[0] = '%';
	FormatS[1] = (ValChPlacesAmount>9) ? '0' + ValChPlacesAmount / 10 : '0' + ValChPlacesAmount;
	FormatS[2] = (ValChPlacesAmount>9) ? '0' + ValChPlacesAmount % 10 : 's';
	FormatS[3] = (ValChPlacesAmount>9) ? 's' : '\0';
	FormatS[4] = '\0';
	int Temp1 = OutSpaceChPlacesAmount / 2,//Временная переменная 1
		Temp2 = OutSpaceChPlacesAmount - Temp1,//Временная переменная 2
		SpacesBeforeNode = Temp1,//Количество пробелов, которые нужно напечатать перед вершиной текущего уровня
		SpacesAfterNode = Temp2,//Количество пробелов, которые нужно напечатать после вершины текущего уровня
		W = ValChPlacesAmount*DataPointersAmount + (DataPointersAmount - 1)*InSpaceChPlacesAmount;//Количество знакомест, занимаемых одной вершиной дерева
	if (TempLevel < ReqLevel)//Пока не достигли требуемого уровня
	{
		if (PRoot != NULL)//Не достигли конца ветви
		{
			for (int i = 0; i < ChildPointersAmount; i++)
			{
				ShowLevel(PRoot->PChildren[i], ReqLevel, Height, TempLevel + 1);//Переход к следующему уровню
			}
		}
		else//достигли конца ветви. Необходимо напечатать пробелы в запрашиваемом уровне (текстовый курсор находится в запрашиваемом уровне), чтобы восполнить отсутствующие элементы из-за нулевых вершин в текущем уровне и сохранить симметрию дерева
		{
			if (ChildPointersAmount % 2 == 0)//Если количество потомков четное
			{
				for (int i = Height - 2; i >= TempLevel; i--)
				{
					Temp1 = SpacesBeforeNode;//Значение со следующего уровня
					Temp2 = SpacesAfterNode;//Значение со следующего уровня
					//Количество пробелов, которые нужно напечатать перед вершиной
					SpacesBeforeNode = ChildPointersAmount*(W + Temp1 + Temp2) / 2 - W / 2;
					//Количество пробелов, которые нужно напечатать после вершины
					SpacesAfterNode= SpacesBeforeNode+ W / 2-(W-W/2);//Т.к. W м.б. нечетным и W/2 < половины W
				}
			}
			else//Если количество потомков нечетное
			{
				for (int i = Height - 2; i >= TempLevel; i--)
				{
					Temp1 = SpacesBeforeNode;//Значение со следующего уровня
					Temp2 = SpacesAfterNode;//Значение со следующего уровня
					//Количество пробелов, которые нужно напечатать перед вершиной
					SpacesBeforeNode = (ChildPointersAmount-1)*(W + Temp1 + Temp2) / 2 + Temp1;
					//Количество пробелов, которые нужно напечатать после вершины
					SpacesAfterNode = SpacesBeforeNode- Temp1+ Temp2;
				}
			}
			//Печать пробелов перед вершиной
			for (int i = 0; i < SpacesBeforeNode; i++)
			{
				printf(" ");
			}
			for (int i = 0; i < DataPointersAmount; i++)//Печать пробелов чтобы сохранить симметрию
			{
				printf(FormatS, " ");
				if (i < DataPointersAmount - 1)//Не последнее значение вершины
				{
					for (int j = 0; j < InSpaceChPlacesAmount; j++)
					{
						printf(" ");//Пробелы между значениями одной вершины
					}
				}
			}
			//Печать пробелов после вершины
			for (int i = 0; i < SpacesAfterNode; i++)
			{
				printf(" ");
			}
		}
	}
	else//Достигли требуемого уровня
	{
		if (ChildPointersAmount % 2 == 0)//Если количество потомков четное
		{
			for (int i = Height - 2; i >= TempLevel; i--)
			{
				Temp1 = SpacesBeforeNode;
				Temp2 = SpacesAfterNode;
				//Количество пробелов, которые нужно напечатать перед вершиной
				SpacesBeforeNode = ChildPointersAmount*(W + Temp1 + Temp2) / 2 - W / 2;
				//Количество пробелов, которые нужно напечатать после вершины
				SpacesAfterNode = SpacesBeforeNode + W / 2 - (W - W / 2);//Т.к. W м.б. нечетным и W/2 < половины W
			}
		}
		else//Если количество потомков нечетное
		{
			for (int i = Height - 2; i >= TempLevel; i--)
			{
				Temp1 = SpacesBeforeNode;
				Temp2 = SpacesAfterNode;
				//Количество пробелов, которые нужно напечатать перед вершиной
				SpacesBeforeNode = (ChildPointersAmount - 1)*(W + Temp1 + Temp2) / 2 + Temp1;
				//Количество пробелов, которые нужно напечатать после вершины
				SpacesAfterNode = SpacesBeforeNode - Temp1 + Temp2;
			}
		}
		//Печать пробелов перед вершиной
		for (int i = 0; i < SpacesBeforeNode; i++)
		{
			printf(" ");
		}
		char Format[5];
		Format[0] = '%';
		Format[1] = (ValChPlacesAmount>9)?'0'+ ValChPlacesAmount /10: '0' + ValChPlacesAmount;
		Format[2] = (ValChPlacesAmount>9) ? '0' + ValChPlacesAmount % 10 : 'd';
		Format[3] = (ValChPlacesAmount>9) ? 'd' : '\0';
		Format[4] = '\0';
		for (int i = 0; i < DataPointersAmount; i++)//Печать значений вершины
		{
			if (PRoot != NULL)//Вершина имеется (не конец ветви)
			{
				if (PRoot->PData[i] != NULL)//Если значение в вершине имеется
				{
					printf(Format, *(PRoot->PData[i]));
				}
				else
				{
					printf(FormatS, "*");//Нет значения в вершине
				}
			}
			else//Нулевая вершина (конец ветви)
			{
				printf(FormatS, "*");
			}
			if (i < DataPointersAmount - 1)//Не последнее значение вершины
			{
				for (int j = 0; j < InSpaceChPlacesAmount; j++)
				{
					printf(" ");//Пробелы между значениями одной вершины
				}
			}
		}
		//Печать пробелов после вершины
		for (int i = 0; i < SpacesAfterNode; i++)
		{
			printf(" ");
		}
	}
}
//Функция формирования массива из дерева
//Array - указатель на буфер, куда помещается сформированный массив. Буфер резервирует вызывающая функция
//PRoot - указатель на корень дерева
//TempIndex - ссылка на текущее значение индекса в массиве Array
void Tree2Array(int *Array, SimpleTree *PRoot, int &TempIndex)
{
	if (PRoot != NULL)
	{
		for (int i = 0, N= ChildPointersAmount-1; i < N; i++)
		{
			Tree2Array(Array, PRoot->PChildren[i], TempIndex);
			if (PRoot->PData[i] != NULL)
			{
				Array[TempIndex++] = *(PRoot->PData[i]);
			}
		}
		Tree2Array(Array, PRoot->PChildren[ChildPointersAmount - 1], TempIndex);//Т.к. за последним потомком в вершине нет данных
	}
}
//Функция отображает массив int
//Array - указатель на нулевой элемент массива
//N - количество элементов в массиве
void ShowArray(int *Array, int N)
{
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", Array[i]);
	}
}
//Функция формирует из упорядоченного массива целых нормализованное дерево
//Array - указатель на нулевой элемент массива, в котором хранятся значения данных вершин дерева
//N - количество элементов в массиве Array
//PRoot - указатель на корень дерева. Дерево располагается в массиве типа SimpleTree, нулевой элемент которого - корень
//Index - индекс текущего заполняемого элемента в массиве PRoot
//Возвращает указатель на сформированную вершину дерева в массиве PRoot
SimpleTree * Array2NormTree(int *Array, int N, SimpleTree *PRoot, int &Index)
{
	if (N > 0)//Элементы на участке разбиения есть
	{
		int NodeIndexes[DataPointersAmount];//Индексы в массиве Array значений вершины
		NodeIndexes[0] = (N - 1) / ChildPointersAmount;//Разбиваем участок на ChildPointersAmount подучастков
		int TempIndex = Index;//Для развязки с Index, который меняется во время рекурсивных вызовов
		PRoot[TempIndex].PData[0] = &(Array[NodeIndexes[0]]);
		for (int i = 1; i < DataPointersAmount; i++)//Для каждого значения данных вершины дерева
		{
			//Вычисляем индекс значения данных в массиве Array
			NodeIndexes[i] = NodeIndexes[i - 1] + 1 + NodeIndexes[0];
			if (i <= N - 1)//Если индекс не превосходит максимально возможное значение на подучастке (есть элементы для записи)
			{
				//Записываем указатель на данные в вершину
				PRoot[TempIndex].PData[i] = &(Array[NodeIndexes[i]]);
			}
			else//Элементы на подучастке закончились
			{
				PRoot[TempIndex].PData[i] = NULL;
			}
		}
		int MaxChIndex = ChildPointersAmount - 1;//Максимальный индекс потомка одной вершины дерева
		for (int i = 0; i < MaxChIndex; i++)//Для всех потомков, кроме последнего, т.к. в его поддереве может оказаться другое количество вершин
		{
			//Рекурсивно формируем вершину потомка и получаем указатель на нее
			PRoot[TempIndex].PChildren[i] = Array2NormTree(&(Array[i*(NodeIndexes[0]+1)]), NodeIndexes[0], PRoot, ++Index);
			if (PRoot[TempIndex].PChildren[i] == NULL)
			{
				Index--;//Т.к. нулевая вершина не формируется в массиве
			}
		}
		//Рекурсивно формируем вершину последнего потомка и получаем указатель на нее
		PRoot[TempIndex].PChildren[MaxChIndex] = Array2NormTree(&(Array[MaxChIndex*(NodeIndexes[0] + 1)]), N-1-NodeIndexes[DataPointersAmount-1], PRoot, ++Index);		
		if (PRoot[TempIndex].PChildren[MaxChIndex] == NULL)
		{
			Index--;//Т.к. нулевая вершина не формируется в массиве
		}
		//Возвращаем указатель на сформированную вершину родительской вершине
		return &(PRoot[TempIndex]);
	}
	//Элементы на участке разбиения массива Array закончились
	return NULL;
}
//Функция выводит на экран отчет по характеристикам сбалансированности дерева и трудоемкости балансировки
//UnbalancedTrees - массив корней деревьев.
//TreesAmount - количество элементов в массиве UnbalancedTrees
void ShowLab5Report(SimpleTree **UnbalancedTrees, int TreesAmount)
{
	int *NodesAmount;
	int *Time;
	NodesAmount = (int*)malloc(sizeof(int)*TreesAmount);
	Time = (int*)malloc(sizeof(int)*TreesAmount);
	SetConsoleCP(1251);//Ввод русских букв
	SetConsoleOutputCP(1251);//Вывод русских букв
	for (int i = 0; i < TreesAmount; i++)
	{
		printf("\nНесбалансированное дерево %d",i);
		ShowTree(UnbalancedTrees[i]);
		printf("\nКоличество ветвей дерева: %d", TreeBranchesAmount(UnbalancedTrees[i]));
		printf("\nСумма длин всех ветвей дерева: %d", BrunchLengthsSum(UnbalancedTrees[i], 0));
		printf("\nСредняя длина ветви: %f", AverageBrunchLength(UnbalancedTrees[i]));
		NodesAmount[i] = TreeNodesAmount(UnbalancedTrees[i]);//Количество вершин в дереве
		printf("\nКоличество вершин дерева: %d", NodesAmount[i]);
		printf("\nМаксимальная длина ветви дерева: %d", TreeHeight(UnbalancedTrees[i]));
		printf("\nМинимальная длина ветви дерева: %d", MinBranchLength(UnbalancedTrees[i]));
		int *Array = (int *)malloc(sizeof(int)*NodesAmount[i]*DataPointersAmount);
		int Index = 0;
		Tree2Array(Array, UnbalancedTrees[i], Index);//формирование массива из дерева
		printf("\nЭлементы несбалансированного дерева %d в возрастающем порядке:", i);
		ShowArray(Array, NodesAmount[i]*DataPointersAmount);
		SimpleTree *PRoot = (SimpleTree *)malloc(sizeof(SimpleTree)*NodesAmount[i]*DataPointersAmount);//Домножаем на DataPointersAmount, т.к. в вырожденном случае в вершине может оказаться всего одно значение данных
		Time[i] = clock();//мс, время с начала выполнения программы
		for (int j = 0; j < 1000000; j++)
		{
			Index = 0;
			Tree2Array(Array, UnbalancedTrees[i], Index);//формирование массива из дерева
			//printf("\nЭлементы несбалансированного дерева %d в возрастающем порядке:", i);
			//ShowArray(Array, NodesAmount*DataPointersAmount);
			Index = 0;
			Array2NormTree(Array, NodesAmount[i]*DataPointersAmount, PRoot, Index);
		}
		Time[i] = clock() - Time[i];
		printf("\nСбалансированное дерево %d", i);
		ShowTree(PRoot);
		printf("\nВремя балансировки: %d нс", Time[i]);
		printf("\n");
		system("pause");
		free(PRoot);
		free(Array);
	}
	printf("Сводный результат:\n");
	printf("Количество элементов дерева\tВремя балансировки, нс\n");
	for (int i = 0; i < TreesAmount; i++)
	{
		printf("%d\t\t\t\t%d\n",NodesAmount[i], Time[i]);
	}
	free(NodesAmount);
	free(Time);
	system("pause");
}