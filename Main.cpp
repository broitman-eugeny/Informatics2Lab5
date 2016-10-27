#include "lab5.h"
//��� ����������� �������� ������ ������������� ����� ������������� ������������������ ������(������� ����� �����)
//� ��������� ������������(������������).
//��� ���������� ������ ���������� ��������� ����������� ��������� ������� ������ ���������
//� �� ������������(���������� ������� ��������).
//������� ��� ���������� �����������(������� - ���������������, ������������).
//����������  2 - 3 ������.
//������� ������ �������� ��� ��������� �� ������� � ���  ��������� ��  ����������. ������  �  ������  �����������.
//���������� ������� �������� ��� ����, ����������� �� �������� �������� � �� �����������.
//�������� ������� ���� ������ ������ ����������� �������� � ����� ��������� � ������
//��� ����� ����������� �������� � ����������� ���������;
//����������, �������� ������� ���� ������ ������ ����������� �������� � ����������� ���������
//� ������ ��� �����, ��� ���������� �������� � ������ ���������.
//��� ���������� ������� ������������ ��� ����������� ������� ������ � ������� ��������� �,
//� �������� �����, � ������� �����.
void main()
{
	//������������������ ������
	int Keys[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};//������ �������� ��������
	//4-� ������� ������
	SimpleTree Node40 = { { &Keys[5], &Keys[6] },{ NULL,NULL,NULL } };//������� ������� Node31
	SimpleTree Node41 = { { &Keys[8], &Keys[9] },{ NULL,NULL,NULL } };// -//-
	//3-� ������� ������
	SimpleTree Node30 = { { &Keys[0], &Keys[1] },{ NULL,NULL,NULL } };//������� ������� Node20
	SimpleTree Node31 = { { &Keys[4], &Keys[7] },{ NULL,&Node40,&Node41 } };// -//-
	//2-� ������� ������
	SimpleTree Node20 = { { &Keys[2], &Keys[3] },{ &Node30,NULL,&Node31 } };//������� ������� Node010
	SimpleTree Node21 = { { &Keys[11], &Keys[12] },{ NULL,NULL,NULL } };// -//-
	SimpleTree Node22 = { { &Keys[14], &Keys[15] },{ NULL,NULL,NULL } };// -//-
	SimpleTree Node23 = { { &Keys[18], &Keys[19] },{ NULL,NULL,NULL } };//������� ������� Node011
	SimpleTree Node24 = { { &Keys[21], &Keys[22] },{ NULL,NULL,NULL } };// -//-
	//1-� ������� ������
	SimpleTree Node10 = { { &Keys[10], &Keys[13] },{ &Node20,&Node21,&Node22 } };//������� ������� Node00 (�����)
	SimpleTree Node11 = { { &Keys[17], &Keys[20] },{ NULL,&Node23,&Node24 } };// -//-
	//0-� ������� ������ (������)
	SimpleTree Node00 = { { &Keys[16], &Keys[23] },{ &Node10,&Node11,NULL } };
	SetConsoleCP(1251);//���� ������� ����
	SetConsoleOutputCP(1251);//����� ������� ����
	ShowTree(&Node00);
	printf("\n���������� ������ ������: %d", TreeBranchesAmount(&Node00));
	printf("\n����� ���� ���� ������ ������: %d", BrunchLengthsSum(&Node00,0));
	printf("\n������� ����� �����: %f", AverageBrunchLength(&Node00));
	int NodesAmount = TreeNodesAmount(&Node00);//���������� ������ � ������
	printf("\n���������� ������ ������: %d", NodesAmount);
	printf("\n������������ ����� ����� ������: %d", TreeHeight(&Node00));
	int *Array=(int *)malloc(sizeof(int)*NodesAmount*DataPointersAmount);
	int Index = 0;
	Tree2Array(Array, &Node00, Index);//������������ ������� �� ������
	ShowArray(Array, NodesAmount*DataPointersAmount);
	SimpleTree *PRoot = (SimpleTree *)malloc(sizeof(SimpleTree)*NodesAmount*DataPointersAmount);//��������� �� DataPointersAmount, �.�. � ����������� ������ � ������� ����� ��������� ����� ���� �������� ������
	Index = 0;
	Array2NormTree(Array, NodesAmount*DataPointersAmount, PRoot, Index);
	ShowTree(PRoot);
	printf("\n");
	system("pause");
	free(PRoot);
	free(Array);
}