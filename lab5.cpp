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
//PRoot - указатель на корень дерева
//Level - уровень корня дерева - 0
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
	int LeftHeight, MidHeight, RightHeight;
	LeftHeight = TreeHeight(PRoot->PChildren[0]);
	MidHeight = TreeHeight(PRoot->PChildren[1]);
	RightHeight = TreeHeight(PRoot->PChildren[2]);
	if (LeftHeight >= MidHeight && LeftHeight >= RightHeight)
	{
		return LeftHeight + 1;
	}
	if(MidHeight >= LeftHeight && MidHeight >= RightHeight)
	{
		return MidHeight + 1;
	}
	else
	{
		return RightHeight + 1;
	}
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
	if (TempLevel < ReqLevel)//Пока не достигли требуемого уровня
	{
		if (PRoot != NULL)//Не достигли конца ветви
		{
			for (int i = 0; i < ChildPointersAmount; i++)
			{
				ShowLevel(PRoot->PChildren[i], ReqLevel, Height, TempLevel + 1);//Переход к следующему уровню
			}
		}
		else//достигли конца ветви
		{
			ShowLevel(PRoot, ReqLevel, Height, TempLevel + 1);//Переход к следующему уровню со значением NULL
															//для заполнения пустых вершин звездочками
		}
	}
	else//Достигли требуемого уровня
	{
		int SpacesAmount = 1;//Количество пробелов между вершинами уровня вычисляется исходя из условия,
		//что расстояния между значениями одной вершины == InSpaceChPlacesAmount, расстояния между вершинами
		//нижнего уровня == OutSpaceChPlacesAmount. Вершины верхних уровней располагаются осесимметрично
		//относительно соответствующих вершин нижнего уровня
		for (int i = 1; i < Height - ReqLevel; i++)
		{
			SpacesAmount *= ChildPointersAmount;//Число потомков в степени (^) (высота дерева-уровень-1)
		}
		SpacesAmount = (SpacesAmount - 1)*(ValChPlacesAmount*DataPointersAmount + InSpaceChPlacesAmount*(DataPointersAmount - 1) + OutSpaceChPlacesAmount)+ OutSpaceChPlacesAmount;
		for (int i = (SpacesAmount - OutSpaceChPlacesAmount) / 2; i > 0; i--)
		{
			printf(" ");//Половина пробелов перед вершиной
		}
		char Format[5];
		Format[0] = '%';
		Format[1] = (ValChPlacesAmount>9)?'0'+ ValChPlacesAmount /10: '0' + ValChPlacesAmount;
		Format[2] = (ValChPlacesAmount>9) ? '0' + ValChPlacesAmount % 10 : 'd';
		Format[3] = (ValChPlacesAmount>9) ? 'd' : '\0';
		Format[4] = '\0';
		for (int i = 0, N= DataPointersAmount - 1; i < N; i++)//Печать значений вершины исключая последнее
		{
			if (PRoot != NULL)
			{
				printf(Format, *(PRoot->PData[i]));
			}
			else
			{
				printf("*");//Нулевая вершина (конец ветви)
			}
			for (int j = 0; j < InSpaceChPlacesAmount; j++)
			{
				printf(" ");//Пробелы между значениями одной вершины
			}
		}
		//Печать последнего значения вершины
		if (PRoot != NULL)
		{
			printf(Format, *(PRoot->PData[DataPointersAmount - 1]));
		}
		else
		{
			printf("*");//Нулевая вершина (конец ветви)
		}
		for (int i = (SpacesAmount - OutSpaceChPlacesAmount) / 2+ OutSpaceChPlacesAmount; i > 0; i--)
		{
			printf(" ");//Половина пробелов после вершины
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
			Array[TempIndex++] = *(PRoot->PData[i]);
		}
		Tree2Array(Array, PRoot->PChildren[ChildPointersAmount - 1], TempIndex);
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
//Возвращает индекс в массиве SimpleTree сформированной вершины дерева
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
			//Записываем указатель на данные в вершину
			PRoot[TempIndex].PData[i] = &(Array[NodeIndexes[i]]);
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