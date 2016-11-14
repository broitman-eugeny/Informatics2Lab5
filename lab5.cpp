#include "lab5.h"
//������� ���������� ���������� ������ ������
//PRoot - ��������� �� ������ ������
int TreeBranchesAmount(SimpleTree *PRoot)
{
	if (PRoot == NULL)//����� �� ����� �����
	{
		return 1;//�������� ���� ����� 
	}
	int BranchesAmount = 0;
	for (int i = 0; i < ChildPointersAmount; i++)//�� ���� �������� �����
	{
		BranchesAmount += TreeBranchesAmount(PRoot->PChildren[i]);
	}
	return BranchesAmount;
}
//������� ���������� ����� ���� ���� ������ ������.
//PRoot - ��������� �� ������ (�������) ������
//Level - ������� ����� (�������) ������ - 0
int BrunchLengthsSum(SimpleTree *PRoot, int Level)
{
	if (PRoot == NULL)//����� �� ����� �����
	{
		return Level ;//��������� ����� � ������� ��������
	}
	int LengthsSum = 0;
	for (int i = 0; i < ChildPointersAmount; i++)//�� ���� �������� �����
	{
		LengthsSum += BrunchLengthsSum(PRoot->PChildren[i], Level + 1);
	}
		return LengthsSum;
}
//������� ��������� ������� ����� ����� ������.
//������� ����� ���� ������ �� ���������� ������� ����� ���� �������
//����� ����� ������.
//PRoot - ��������� �� ������ ������
double AverageBrunchLength(SimpleTree *PRoot)
{
	int LengthsSum = BrunchLengthsSum(PRoot, 0);//��������� ����� ���� ������
	int BranchesAmount = TreeBranchesAmount(PRoot);//���������� ������
	return (double)LengthsSum/ (double)BranchesAmount;
}
//������� ��������� ���������� ������ ������
//PRoot - ��������� �� ������ ������
int TreeNodesAmount(SimpleTree *PRoot)
{
	if (PRoot == NULL)//����� �� ����� �����
	{
		return 0;
	}
	int NodesAmount = 1;
	for (int i = 0; i < ChildPointersAmount; i++)//�� ���� �������� �����
	{
		NodesAmount += TreeNodesAmount(PRoot->PChildren[i]);
	}
	return NodesAmount;
}
//������� ��������� ������������ ����� ����� ������ � ������ ����� � ������� ��������
//PRoot - ��������� �� ������ ������
int TreeHeight(SimpleTree *PRoot)
{
	if (PRoot == NULL)//����� �� ����� �����
	{
		return 0;
	}
	int Heights[ChildPointersAmount];
	for (int i = 0; i < ChildPointersAmount; i++)//�� ���� �������� �����
	{
		Heights[i] = TreeHeight(PRoot->PChildren[i]);
	}
	return Heights[MaxInt(Heights, ChildPointersAmount)]+1;
}
//������� ���������� ������ ������������� �������������� �������� � �������
//Dim - ������ ����� �����
//N - ������ �������
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
//������� ��������� ����������� ����� ����� ������ � ������ ����� � ������� ��������
//PRoot - ��������� �� ������ ������
int MinBranchLength(SimpleTree *PRoot)
{
	if (PRoot == NULL)//����� �� ����� �����
	{
		return 0;
	}
	int Heights[ChildPointersAmount];
	for (int i = 0; i < ChildPointersAmount; i++)//�� ���� �������� �����
	{
		Heights[i] = TreeHeight(PRoot->PChildren[i]);
	}
	return Heights[MinInt(Heights, ChildPointersAmount)] + 1;
}
//������� ���������� ������ ������������ �������������� �������� � �������
//Dim - ������ ����� �����
//N - ������ �������
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
//������� ���������� ������
//PRoot - ��������� �� ������ ������
void ShowTree(SimpleTree *PRoot)
{
	int Height = TreeHeight(PRoot);//������ ������ � ������ ������� �����
	printf("\n");
	for (int i = 0; i < Height; i++)
	{
		ShowLevel(PRoot,i, Height);//���������� ���� ������� ������
		printf("\n");
	}
}
//������� ���������� ���� ������� ������
//PRoot - ��������� �� ������ ������
//ReqLevel - ����� ����������� ������
//Height - ������ ������, ���������� ����� � ������� ��������
//TempLevel - ������� ������� (��� ������ ������ ����������� ������)
void ShowLevel(SimpleTree *PRoot, int ReqLevel, int Height, int TempLevel)
{
	char FormatS[5];
	FormatS[0] = '%';
	FormatS[1] = (ValChPlacesAmount>9) ? '0' + ValChPlacesAmount / 10 : '0' + ValChPlacesAmount;
	FormatS[2] = (ValChPlacesAmount>9) ? '0' + ValChPlacesAmount % 10 : 's';
	FormatS[3] = (ValChPlacesAmount>9) ? 's' : '\0';
	FormatS[4] = '\0';
	int Temp1 = OutSpaceChPlacesAmount / 2,//��������� ���������� 1
		Temp2 = OutSpaceChPlacesAmount - Temp1,//��������� ���������� 2
		SpacesBeforeNode = Temp1,//���������� ��������, ������� ����� ���������� ����� �������� �������� ������
		SpacesAfterNode = Temp2,//���������� ��������, ������� ����� ���������� ����� ������� �������� ������
		W = ValChPlacesAmount*DataPointersAmount + (DataPointersAmount - 1)*InSpaceChPlacesAmount;//���������� ���������, ���������� ����� �������� ������
	if (TempLevel < ReqLevel)//���� �� �������� ���������� ������
	{
		if (PRoot != NULL)//�� �������� ����� �����
		{
			for (int i = 0; i < ChildPointersAmount; i++)
			{
				ShowLevel(PRoot->PChildren[i], ReqLevel, Height, TempLevel + 1);//������� � ���������� ������
			}
		}
		else//�������� ����� �����. ���������� ���������� ������� � ������������� ������ (��������� ������ ��������� � ������������� ������), ����� ���������� ������������� �������� ��-�� ������� ������ � ������� ������ � ��������� ��������� ������
		{
			if (ChildPointersAmount % 2 == 0)//���� ���������� �������� ������
			{
				for (int i = Height - 2; i >= TempLevel; i--)
				{
					Temp1 = SpacesBeforeNode;//�������� �� ���������� ������
					Temp2 = SpacesAfterNode;//�������� �� ���������� ������
					//���������� ��������, ������� ����� ���������� ����� ��������
					SpacesBeforeNode = ChildPointersAmount*(W + Temp1 + Temp2) / 2 - W / 2;
					//���������� ��������, ������� ����� ���������� ����� �������
					SpacesAfterNode= SpacesBeforeNode+ W / 2-(W-W/2);//�.�. W �.�. �������� � W/2 < �������� W
				}
			}
			else//���� ���������� �������� ��������
			{
				for (int i = Height - 2; i >= TempLevel; i--)
				{
					Temp1 = SpacesBeforeNode;//�������� �� ���������� ������
					Temp2 = SpacesAfterNode;//�������� �� ���������� ������
					//���������� ��������, ������� ����� ���������� ����� ��������
					SpacesBeforeNode = (ChildPointersAmount-1)*(W + Temp1 + Temp2) / 2 + Temp1;
					//���������� ��������, ������� ����� ���������� ����� �������
					SpacesAfterNode = SpacesBeforeNode- Temp1+ Temp2;
				}
			}
			//������ �������� ����� ��������
			for (int i = 0; i < SpacesBeforeNode; i++)
			{
				printf(" ");
			}
			for (int i = 0; i < DataPointersAmount; i++)//������ �������� ����� ��������� ���������
			{
				printf(FormatS, " ");
				if (i < DataPointersAmount - 1)//�� ��������� �������� �������
				{
					for (int j = 0; j < InSpaceChPlacesAmount; j++)
					{
						printf(" ");//������� ����� ���������� ����� �������
					}
				}
			}
			//������ �������� ����� �������
			for (int i = 0; i < SpacesAfterNode; i++)
			{
				printf(" ");
			}
		}
	}
	else//�������� ���������� ������
	{
		if (ChildPointersAmount % 2 == 0)//���� ���������� �������� ������
		{
			for (int i = Height - 2; i >= TempLevel; i--)
			{
				Temp1 = SpacesBeforeNode;
				Temp2 = SpacesAfterNode;
				//���������� ��������, ������� ����� ���������� ����� ��������
				SpacesBeforeNode = ChildPointersAmount*(W + Temp1 + Temp2) / 2 - W / 2;
				//���������� ��������, ������� ����� ���������� ����� �������
				SpacesAfterNode = SpacesBeforeNode + W / 2 - (W - W / 2);//�.�. W �.�. �������� � W/2 < �������� W
			}
		}
		else//���� ���������� �������� ��������
		{
			for (int i = Height - 2; i >= TempLevel; i--)
			{
				Temp1 = SpacesBeforeNode;
				Temp2 = SpacesAfterNode;
				//���������� ��������, ������� ����� ���������� ����� ��������
				SpacesBeforeNode = (ChildPointersAmount - 1)*(W + Temp1 + Temp2) / 2 + Temp1;
				//���������� ��������, ������� ����� ���������� ����� �������
				SpacesAfterNode = SpacesBeforeNode - Temp1 + Temp2;
			}
		}
		//������ �������� ����� ��������
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
		for (int i = 0; i < DataPointersAmount; i++)//������ �������� �������
		{
			if (PRoot != NULL)//������� ������� (�� ����� �����)
			{
				if (PRoot->PData[i] != NULL)//���� �������� � ������� �������
				{
					printf(Format, *(PRoot->PData[i]));
				}
				else
				{
					printf(FormatS, "*");//��� �������� � �������
				}
			}
			else//������� ������� (����� �����)
			{
				printf(FormatS, "*");
			}
			if (i < DataPointersAmount - 1)//�� ��������� �������� �������
			{
				for (int j = 0; j < InSpaceChPlacesAmount; j++)
				{
					printf(" ");//������� ����� ���������� ����� �������
				}
			}
		}
		//������ �������� ����� �������
		for (int i = 0; i < SpacesAfterNode; i++)
		{
			printf(" ");
		}
	}
}
//������� ������������ ������� �� ������
//Array - ��������� �� �����, ���� ���������� �������������� ������. ����� ����������� ���������� �������
//PRoot - ��������� �� ������ ������
//TempIndex - ������ �� ������� �������� ������� � ������� Array
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
		Tree2Array(Array, PRoot->PChildren[ChildPointersAmount - 1], TempIndex);//�.�. �� ��������� �������� � ������� ��� ������
	}
}
//������� ���������� ������ int
//Array - ��������� �� ������� ������� �������
//N - ���������� ��������� � �������
void ShowArray(int *Array, int N)
{
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", Array[i]);
	}
}
//������� ��������� �� �������������� ������� ����� ��������������� ������
//Array - ��������� �� ������� ������� �������, � ������� �������� �������� ������ ������ ������
//N - ���������� ��������� � ������� Array
//PRoot - ��������� �� ������ ������. ������ ������������� � ������� ���� SimpleTree, ������� ������� �������� - ������
//Index - ������ �������� ������������ �������� � ������� PRoot
//���������� ��������� �� �������������� ������� ������ � ������� PRoot
SimpleTree * Array2NormTree(int *Array, int N, SimpleTree *PRoot, int &Index)
{
	if (N > 0)//�������� �� ������� ��������� ����
	{
		int NodeIndexes[DataPointersAmount];//������� � ������� Array �������� �������
		NodeIndexes[0] = (N - 1) / ChildPointersAmount;//��������� ������� �� ChildPointersAmount �����������
		int TempIndex = Index;//��� �������� � Index, ������� �������� �� ����� ����������� �������
		PRoot[TempIndex].PData[0] = &(Array[NodeIndexes[0]]);
		for (int i = 1; i < DataPointersAmount; i++)//��� ������� �������� ������ ������� ������
		{
			//��������� ������ �������� ������ � ������� Array
			NodeIndexes[i] = NodeIndexes[i - 1] + 1 + NodeIndexes[0];
			if (i <= N - 1)//���� ������ �� ����������� ����������� ��������� �������� �� ���������� (���� �������� ��� ������)
			{
				//���������� ��������� �� ������ � �������
				PRoot[TempIndex].PData[i] = &(Array[NodeIndexes[i]]);
			}
			else//�������� �� ���������� �����������
			{
				PRoot[TempIndex].PData[i] = NULL;
			}
		}
		int MaxChIndex = ChildPointersAmount - 1;//������������ ������ ������� ����� ������� ������
		for (int i = 0; i < MaxChIndex; i++)//��� ���� ��������, ����� ����������, �.�. � ��� ��������� ����� ��������� ������ ���������� ������
		{
			//���������� ��������� ������� ������� � �������� ��������� �� ���
			PRoot[TempIndex].PChildren[i] = Array2NormTree(&(Array[i*(NodeIndexes[0]+1)]), NodeIndexes[0], PRoot, ++Index);
			if (PRoot[TempIndex].PChildren[i] == NULL)
			{
				Index--;//�.�. ������� ������� �� ����������� � �������
			}
		}
		//���������� ��������� ������� ���������� ������� � �������� ��������� �� ���
		PRoot[TempIndex].PChildren[MaxChIndex] = Array2NormTree(&(Array[MaxChIndex*(NodeIndexes[0] + 1)]), N-1-NodeIndexes[DataPointersAmount-1], PRoot, ++Index);		
		if (PRoot[TempIndex].PChildren[MaxChIndex] == NULL)
		{
			Index--;//�.�. ������� ������� �� ����������� � �������
		}
		//���������� ��������� �� �������������� ������� ������������ �������
		return &(PRoot[TempIndex]);
	}
	//�������� �� ������� ��������� ������� Array �����������
	return NULL;
}
//������� ������� �� ����� ����� �� ��������������� ������������������ ������ � ������������ ������������
//UnbalancedTrees - ������ ������ ��������.
//TreesAmount - ���������� ��������� � ������� UnbalancedTrees
void ShowLab5Report(SimpleTree **UnbalancedTrees, int TreesAmount)
{
	int *NodesAmount;
	int *Time;
	NodesAmount = (int*)malloc(sizeof(int)*TreesAmount);
	Time = (int*)malloc(sizeof(int)*TreesAmount);
	SetConsoleCP(1251);//���� ������� ����
	SetConsoleOutputCP(1251);//����� ������� ����
	for (int i = 0; i < TreesAmount; i++)
	{
		printf("\n������������������ ������ %d",i);
		ShowTree(UnbalancedTrees[i]);
		printf("\n���������� ������ ������: %d", TreeBranchesAmount(UnbalancedTrees[i]));
		printf("\n����� ���� ���� ������ ������: %d", BrunchLengthsSum(UnbalancedTrees[i], 0));
		printf("\n������� ����� �����: %f", AverageBrunchLength(UnbalancedTrees[i]));
		NodesAmount[i] = TreeNodesAmount(UnbalancedTrees[i]);//���������� ������ � ������
		printf("\n���������� ������ ������: %d", NodesAmount[i]);
		printf("\n������������ ����� ����� ������: %d", TreeHeight(UnbalancedTrees[i]));
		printf("\n����������� ����� ����� ������: %d", MinBranchLength(UnbalancedTrees[i]));
		int *Array = (int *)malloc(sizeof(int)*NodesAmount[i]*DataPointersAmount);
		int Index = 0;
		Tree2Array(Array, UnbalancedTrees[i], Index);//������������ ������� �� ������
		printf("\n�������� ������������������� ������ %d � ������������ �������:", i);
		ShowArray(Array, NodesAmount[i]*DataPointersAmount);
		SimpleTree *PRoot = (SimpleTree *)malloc(sizeof(SimpleTree)*NodesAmount[i]*DataPointersAmount);//��������� �� DataPointersAmount, �.�. � ����������� ������ � ������� ����� ��������� ����� ���� �������� ������
		Time[i] = clock();//��, ����� � ������ ���������� ���������
		for (int j = 0; j < 1000000; j++)
		{
			Index = 0;
			Tree2Array(Array, UnbalancedTrees[i], Index);//������������ ������� �� ������
			//printf("\n�������� ������������������� ������ %d � ������������ �������:", i);
			//ShowArray(Array, NodesAmount*DataPointersAmount);
			Index = 0;
			Array2NormTree(Array, NodesAmount[i]*DataPointersAmount, PRoot, Index);
		}
		Time[i] = clock() - Time[i];
		printf("\n���������������� ������ %d", i);
		ShowTree(PRoot);
		printf("\n����� ������������: %d ��", Time[i]);
		printf("\n");
		system("pause");
		free(PRoot);
		free(Array);
	}
	printf("������� ���������:\n");
	printf("���������� ��������� ������\t����� ������������, ��\n");
	for (int i = 0; i < TreesAmount; i++)
	{
		printf("%d\t\t\t\t%d\n",NodesAmount[i], Time[i]);
	}
	free(NodesAmount);
	free(Time);
	system("pause");
}