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
	//������ �������� ��������
	int Keys[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
	//������������������ �������
	//������ 0
	//2-� ������� ������ 0
	SimpleTree Node020 = { { &Keys[0], &Keys[1] },{ NULL,NULL,NULL } };//������� ������� Node010
	SimpleTree Node021 = { { &Keys[3], &Keys[4] },{ NULL,NULL,NULL } };// -//-
	//1-� ������� ������ 0
	SimpleTree Node010 = { { &Keys[2], &Keys[5] },{ &Node020,&Node021,NULL } };//������� ������� Node000
	//0-� ������� ������ 0
	SimpleTree Node000 = { { &Keys[6], &Keys[7] },{ &Node010,NULL,NULL } };//������
	//������ 1
	//3-� ������� ������ 1
	SimpleTree Node130 = { { &Keys[0], &Keys[1] },{ NULL,NULL,NULL } };//������� ������� Node120
	SimpleTree Node131 = { { &Keys[5], &Keys[6] },{ NULL,NULL,NULL } };//������� ������� Node121
	SimpleTree Node132 = { { &Keys[9], &Keys[10] },{ NULL,NULL,NULL } };// -//-
	//2-� ������� ������ 1
	SimpleTree Node120 = { { &Keys[2], &Keys[3] },{ &Node130,NULL,NULL } };//������� ������� Node110
	SimpleTree Node121 = { { &Keys[7], &Keys[8] },{ &Node131,NULL,&Node132 } };// -//-
	//1-� ������� ������ 1
	SimpleTree Node110 = { { &Keys[4], &Keys[11] },{ &Node120,&Node121,NULL } };//������� ������� Node100
	SimpleTree Node111 = { { &Keys[13], &Keys[14] },{ NULL,NULL,NULL } };// -//-
	//0-� ������� ������ 1
	SimpleTree Node100 = { { &Keys[12], &Keys[15] },{ &Node110,&Node111,NULL } };//������
	//4-� ������� ������ 2
	SimpleTree Node240 = { { &Keys[5], &Keys[6] },{ NULL,NULL,NULL } };//������� ������� Node231
	SimpleTree Node241 = { { &Keys[8], &Keys[9] },{ NULL,NULL,NULL } };// -//-
	//3-� ������� ������ 2
	SimpleTree Node230 = { { &Keys[0], &Keys[1] },{ NULL,NULL,NULL } };//������� ������� Node220
	SimpleTree Node231 = { { &Keys[4], &Keys[7] },{ NULL,&Node240,&Node241 } };// -//-
	//2-� ������� ������ 2
	SimpleTree Node220 = { { &Keys[2], &Keys[3] },{ &Node230,NULL,&Node231 } };//������� ������� Node210
	SimpleTree Node221 = { { &Keys[11], &Keys[12] },{ NULL,NULL,NULL } };// -//-
	SimpleTree Node222 = { { &Keys[14], &Keys[15] },{ NULL,NULL,NULL } };// -//-
	SimpleTree Node223 = { { &Keys[18], &Keys[19] },{ NULL,NULL,NULL } };//������� ������� Node011
	SimpleTree Node224 = { { &Keys[21], &Keys[22] },{ NULL,NULL,NULL } };// -//-
	SimpleTree Node225 = { { &Keys[24], &Keys[25] },{ NULL,NULL,NULL } };//������� ������� Node012
	SimpleTree Node226 = { { &Keys[27], &Keys[28] },{ NULL,NULL,NULL } };// -//-
	SimpleTree Node227 = { { &Keys[30], &Keys[31] },{ NULL,NULL,NULL } };// -//-
	//1-� ������� ������ 2
	SimpleTree Node210 = { { &Keys[10], &Keys[13] },{ &Node220,&Node221,&Node222 } };//������� ������� Node200 (�����)
	SimpleTree Node211 = { { &Keys[17], &Keys[20] },{ NULL,&Node223,&Node224 } };// -//-
	SimpleTree Node212 = { { &Keys[26], &Keys[29] },{ &Node225,&Node226,&Node227 } };// -//-
	//0-� ������� ������ 2 (������)
	SimpleTree Node200 = { { &Keys[16], &Keys[23] },{ &Node210,&Node211,&Node212 } };
	SimpleTree *PRoots[] = { &Node000,&Node100,&Node200 };
	ShowLab5Report(PRoots, 3);
}