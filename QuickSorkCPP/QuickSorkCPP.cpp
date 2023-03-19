// QuickSorkCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void quickSort(int *data, int start, int end)
{
    if (start >= end)// 나눈 배열의 원소가 1개인 경우 그 자체가 정렬되어있는 배열임
    {
        return;
    }
    int pivot = start;// pivot은 입력 배열의 첫번째 원소
    int i = start + 1;// pivot제외한 가장 왼쪽 인덱스
    int j = end;// 입력 배열의 마지막 인덱스
    int temp;// swap위한 임시 변수

    while (i <= j)// 인덱스가 엇갈릴때까지 반복
    {
        while (data[i] <= data[pivot])// pivot보다 큰값 만날때까지 i를 오른쪽 이동
        {
            i++;
        }// pivot 보다 큰 최초의 인덱스로 i가 설정됨
        while (data[j] >= data[pivot]&&j>start)// pivot보다 작은값만날때까지 j를 왼쪽 이동 && j 는 pivot인덱스보다는 커야한 조건이 있어야 범위 안벗어남
        {
            j--;
        }// pivot 보다 작은 최초의 인덱스로 j가 설정됨
        if (i > j)// 엇갈린 경우 pivot값과 현재 j 위치의 값을 바꾸면 pivot값보다 작은 집합인 왼쪽과 큰집합인 오른쪽으로 분할 됨
        {
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }
        else//엇갈린 상태가 아닌경우 i인덱스 값과 j인덱스 값을 swap함
        {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }

        //한번의 분할이 끝나면 분할된 2개 배열에 대해 다시 재귀로 동일 동작을 수행함
        //현재 j 인덱스가 교체된 pivot값 이므로 왼쪽의 end 는 j-1인덱스이고 오른쪽의 start는 j+1이다
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

