#pragma once
#include <stdio.h>//��� printf
#include <stdlib.h>//��� system
#include <Windows.h>//��� SetConsoleCP
#include <ctime>//��� clock
const int DataPointersAmount = 2;//���������� ���������� �� ������ � ������� ������
const int ChildPointersAmount = DataPointersAmount+1;//���������� ���������� �� �������� � ������� ������
const int ValChPlacesAmount = 2;//���������� ��������� ��� ����������� ������ �������� ������ �� ������
const int InSpaceChPlacesAmount = 1;//���������� ��������� ��� ����������� ����� ���������� ������ ����� �������
const int OutSpaceChPlacesAmount = 2;//���������� ��������� ��� ����������� ����� ��������� ������� ������
//��������� �����������  2-3 ������.
//������� ������ �������� DataPointersAmount ���������� �� ������� � ChildPointersAmount  ���������� ��  ����������.
struct SimpleTree
{
	int *PData[DataPointersAmount];
	SimpleTree *PChildren[ChildPointersAmount];
};
//������� ���������� ���������� ������ ������
//PRoot - ��������� �� ������ ������
int TreeBranchesAmount(SimpleTree *PRoot);
//������� ���������� ����� ���� ���� ������ ������.
//PRoot - ��������� �� ������ ������
//Level - ������� ����� ������ - 0
int BrunchLengthsSum(SimpleTree *PRoot, int Level);
//������� ��������� ������� ����� ����� ������.
//������� ����� ���� ������ �� ���������� ������� ����� ���� �������
//����� ����� ������.
//PRoot - ��������� �� ������ ������
double AverageBrunchLength(SimpleTree *PRoot);
//������� ��������� ���������� ������ ������
//PRoot - ��������� �� ������ ������
int TreeNodesAmount(SimpleTree *PRoot);
//������� ��������� ������������ ����� ����� ������ � ������ ����� � ������� ��������
//PRoot - ��������� �� ������ ������
int TreeHeight(SimpleTree *PRoot);
//������� ���������� ������
//PRoot - ��������� �� ������ ������
//������� ��������� ����������� ����� ����� ������ � ������ ����� � ������� ��������
//PRoot - ��������� �� ������ ������
int MinBranchLength(SimpleTree *PRoot);
void ShowTree(SimpleTree *PRoot);
//������� ���������� ���� ������� ������
//PRoot - ��������� �� ������ ������
//ReqLevel - ����� ����������� ������
//Height - ������ ������, ���������� ����� � ������� ��������
//TempLevel - ������� ������� (��� ������ ������ ����������� ������)
void ShowLevel(SimpleTree *PRoot, int ReqLevel, int Height, int TempLevel = 0);
//������� ������������ ������� �� ������
//Array - ��������� �� �����, ���� ���������� �������������� ������. ����� ����������� ���������� �������
//PRoot - ��������� �� ������ ������
//TempIndex - ������ �� ������� �������� ������� � ������� Array
void Tree2Array(int *Array, SimpleTree *PRoot, int &TempIndex);
//������� ���������� ������ int
//Array - ��������� �� ������� ������� �������
//N - ���������� ��������� � �������
void ShowArray(int *Array, int N);
//������� ��������� �� �������������� ������� ����� ��������������� ������
//Array - ��������� �� ������� ������� �������, � ������� �������� �������� ������ ������ ������
//N - ���������� ��������� � ������� Array
//PRoot - ��������� �� ������ ������. ������ ������������� � ������� ���� SimpleTree, ������� ������� �������� - ������
//Index - ������ �������� ������������ �������� � ������� PRoot
//���������� ������ � ������� SimpleTree �������������� ������� ������
SimpleTree * Array2NormTree(int *Array, int N, SimpleTree *PRoot, int &Index);
//������� ������� �� ����� ����� �� ��������������� ������������������ ������ � ������������ ������������
//PRoot - ������ ������ ��������.
//TreesAmount - ���������� ��������� � ������� PRoot
void ShowLab5Report(SimpleTree **UnbalansedTrees, int TreesAmount);