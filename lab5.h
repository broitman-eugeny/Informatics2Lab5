#pragma once
#include <stdio.h>//Для printf
#include <stdlib.h>//Для system
#include <Windows.h>//Для SetConsoleCP
#include <ctime>//Для clock
const int DataPointersAmount = 2;//Количество указателей на данные в вершине дерева
const int ChildPointersAmount = DataPointersAmount+1;//Количество указателей на потомков в вершине дерева
const int ValChPlacesAmount = 2;//Количество знакомест для отображения одного значения данных на экране
const int InSpaceChPlacesAmount = 1;//Количество знакомест для разделителя между значениями данных одной вершины
const int OutSpaceChPlacesAmount = 2;//Количество знакомест для разделителя между вершинами нижнего уровня
//Структура упрощенного  2-3 дерева.
//Вершина дерева содержит DataPointersAmount указателей на объекты и ChildPointersAmount  указателей на  поддеревья.
struct SimpleTree
{
	int *PData[DataPointersAmount];
	SimpleTree *PChildren[ChildPointersAmount];
};
//Функция вычисления количества ветвей дерева
//PRoot - указатель на корень дерева
int TreeBranchesAmount(SimpleTree *PRoot);
//Функция вычисления суммы длин всех ветвей дерева.
//PRoot - указатель на корень дерева
//Level - уровень корня дерева - 0
int BrunchLengthsSum(SimpleTree *PRoot, int Level);
//Функция вычисляет среднюю длину ветви дерева.
//Деление суммы длин ветвей на количество нулевых узлов дает среднюю
//длину ветви дерева.
//PRoot - указатель на корень дерева
double AverageBrunchLength(SimpleTree *PRoot);
//Функция вычисляет количество вершин дерева
//PRoot - указатель на корень дерева
int TreeNodesAmount(SimpleTree *PRoot);
//Функция вычисляет максимальную длину ветви дерева с учетом веток к нулевым вершинам
//PRoot - указатель на корень дерева
int TreeHeight(SimpleTree *PRoot);
//Функция отображает дерево
//PRoot - указатель на корень дерева
//Функция вычисляет минимальную длину ветви дерева с учетом веток к нулевым вершинам
//PRoot - указатель на корень дерева
int MinBranchLength(SimpleTree *PRoot);
void ShowTree(SimpleTree *PRoot);
//Функция отображает один уровень дерева
//PRoot - указатель на корень дерева
//ReqLevel - номер печатаемого уровня
//Height - высота дерева, включающая ветки к нулевым вершинам
//TempLevel - текущий уровень (для поиска вершин печатаемого уровня)
void ShowLevel(SimpleTree *PRoot, int ReqLevel, int Height, int TempLevel = 0);
//Функция формирования массива из дерева
//Array - указатель на буфер, куда помещается сформированный массив. Буфер резервирует вызывающая функция
//PRoot - указатель на корень дерева
//TempIndex - ссылка на текущее значение индекса в массиве Array
void Tree2Array(int *Array, SimpleTree *PRoot, int &TempIndex);
//Функция отображает массив int
//Array - указатель на нулевой элемент массива
//N - количество элементов в массиве
void ShowArray(int *Array, int N);
//Функция формирует из упорядоченного массива целых нормализованное дерево
//Array - указатель на нулевой элемент массива, в котором хранятся значения данных вершин дерева
//N - количество элементов в массиве Array
//PRoot - указатель на корень дерева. Дерево располагается в массиве типа SimpleTree, нулевой элемент которого - корень
//Index - индекс текущего заполняемого элемента в массиве PRoot
//Возвращает индекс в массиве SimpleTree сформированной вершины дерева
SimpleTree * Array2NormTree(int *Array, int N, SimpleTree *PRoot, int &Index);
//Функция выводит на экран отчет по характеристикам сбалансированности дерева и трудоемкости балансировки
//PRoot - массив корней деревьев.
//TreesAmount - количество элементов в массиве PRoot
void ShowLab5Report(SimpleTree **UnbalansedTrees, int TreesAmount);