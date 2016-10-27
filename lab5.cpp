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
//PRoot - ��������� �� ������ ������
//Level - ������� ����� ������ - 0
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
	int SpacesBeforeNextNode = OutSpaceChPlacesAmount / 2,//���������� ��������, ������� ����� ���������� ����� �������� ���������� ������
		SpacesAfterNextNode = OutSpaceChPlacesAmount - SpacesBeforeNextNode,//���������� ��������, ������� ����� ���������� ����� ������� ���������� ������
		SpacesBeforeNode = SpacesBeforeNextNode,//���������� ��������, ������� ����� ���������� ����� �������� �������� ������
		SpacesAfterNode = SpacesAfterNextNode,//���������� ��������, ������� ����� ���������� ����� ������� �������� ������
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
		else//�������� ����� �����
		{
			if (ChildPointersAmount % 2 == 0)//���� ���������� �������� ������
			{
				for (int i = Height - 2; i >= TempLevel; i--)
				{
					SpacesBeforeNextNode = SpacesBeforeNode;
					SpacesAfterNextNode = SpacesAfterNode;
					//���������� ��������, ������� ����� ���������� ����� ��������
					SpacesBeforeNode = ChildPointersAmount*(W + SpacesBeforeNextNode + SpacesAfterNextNode) / 2 - W / 2;
					//���������� ��������, ������� ����� ���������� ����� �������
					SpacesAfterNode= SpacesBeforeNode+ W / 2-(W-W/2);//�.�. W �.�. �������� � W/2 < �������� W
				}
			}
			else//���� ���������� �������� ��������
			{
				for (int i = Height - 2; i >= TempLevel; i--)
				{
					SpacesBeforeNextNode = SpacesBeforeNode;
					SpacesAfterNextNode = SpacesAfterNode;
					//���������� ��������, ������� ����� ���������� ����� ��������
					SpacesBeforeNode = (ChildPointersAmount-1)*(W + SpacesBeforeNextNode + SpacesAfterNextNode) / 2 + SpacesBeforeNode;
					//���������� ��������, ������� ����� ���������� ����� �������
					SpacesAfterNode = SpacesBeforeNode- SpacesBeforeNextNode+ SpacesAfterNextNode;
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
				SpacesBeforeNextNode = SpacesBeforeNode;
				SpacesAfterNextNode = SpacesAfterNode;
				//���������� ��������, ������� ����� ���������� ����� ��������
				SpacesBeforeNode = ChildPointersAmount*(W + SpacesBeforeNextNode + SpacesAfterNextNode) / 2 - W / 2;
				//���������� ��������, ������� ����� ���������� ����� �������
				SpacesAfterNode = SpacesBeforeNode + W / 2 - (W - W / 2);//�.�. W �.�. �������� � W/2 < �������� W
			}
		}
		else//���� ���������� �������� ��������
		{
			for (int i = Height - 2; i >= TempLevel; i--)
			{
				SpacesBeforeNextNode = SpacesBeforeNode;
				SpacesAfterNextNode = SpacesAfterNode;
				//���������� ��������, ������� ����� ���������� ����� ��������
				SpacesBeforeNode = (ChildPointersAmount - 1)*(W + SpacesBeforeNextNode + SpacesAfterNextNode) / 2 + SpacesBeforeNode;
				//���������� ��������, ������� ����� ���������� ����� �������
				SpacesAfterNode = SpacesBeforeNode - SpacesBeforeNextNode + SpacesAfterNextNode;
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
			Array[TempIndex++] = *(PRoot->PData[i]);
		}
		Tree2Array(Array, PRoot->PChildren[ChildPointersAmount - 1], TempIndex);
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
//���������� ������ � ������� SimpleTree �������������� ������� ������
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