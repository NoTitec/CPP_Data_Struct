// QuickSorkCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void quickSort(int *data, int start, int end)
{
    if (start >= end)// ���� �迭�� ���Ұ� 1���� ��� �� ��ü�� ���ĵǾ��ִ� �迭��
    {
        return;
    }
    int pivot = start;// pivot�� �Է� �迭�� ù��° ����
    int i = start + 1;// pivot������ ���� ���� �ε���
    int j = end;// �Է� �迭�� ������ �ε���
    int temp;// swap���� �ӽ� ����

    while (i <= j)// �ε����� ������������ �ݺ�
    {
        while (data[i] <= data[pivot])// pivot���� ū�� ���������� i�� ������ �̵�
        {
            i++;
        }// pivot ���� ū ������ �ε����� i�� ������
        while (data[j] >= data[pivot]&&j>start)// pivot���� ���������������� j�� ���� �̵� && j �� pivot�ε������ٴ� Ŀ���� ������ �־�� ���� �ȹ��
        {
            j--;
        }// pivot ���� ���� ������ �ε����� j�� ������
        if (i > j)// ������ ��� pivot���� ���� j ��ġ�� ���� �ٲٸ� pivot������ ���� ������ ���ʰ� ū������ ���������� ���� ��
        {
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }
        else//������ ���°� �ƴѰ�� i�ε��� ���� j�ε��� ���� swap��
        {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }

        //�ѹ��� ������ ������ ���ҵ� 2�� �迭�� ���� �ٽ� ��ͷ� ���� ������ ������
        //���� j �ε����� ��ü�� pivot�� �̹Ƿ� ������ end �� j-1�ε����̰� �������� start�� j+1�̴�
        quickSort(data, start, j - 1);
        quickSort(data, j + 1, end);
    }
}
int main()
{
    int number = 10;
    int data[10] = { 1,10,5,8,7,6,4,3,2,9 };
    quickSort(data, 0, number - 1);
    for (int i = 0; i < number; i++)
    {
        cout << data[i]<< " ";
    }
}

