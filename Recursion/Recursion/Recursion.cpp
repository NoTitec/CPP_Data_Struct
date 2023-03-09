// Recursion.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int factorial(int n)
{
    cout << "factorial"<<n<< "\n";
    if (n == 1) return 1;
    else return (n * factorial(n - 1));
}
int factorialIter(int n)
{
    int result = 1;
    for (int k = n; k > 0; k--) {
        result *= k;

    }
    return result;
}

int fibIter(int n)
{
    //n이 2보다 작은경우
    if (n < 2) return n;
    
    else {
        int temp, current = 1, last = 0;// 구조로는 last,current순으로 저장됨
        //n 이 2일경우
        for (int i = 2; i <= n; i++) {
            //[0,current=1] 인상태
            temp = current;//temp에 current 복사
            current += last; // 현재값은 현재값+이전값으로 갱신
            last = temp;//last 이전값을 복사했던 이전 current값으로 갱신
        }
        return current;
    }
}
int main()
{
    cout<<factorial(3)<<"\n";
    cout << factorialIter(3);
    cout << fibIter(2);
}//순환은 표현이 간단하지만 반복에 비해 호출을 많이하여 수행속도가 느려진다
//따라서 설명은 순환으하고 실제는 반복으로 바꾸어 코딩하는 경우도있다 ,물론 순환이 더 빠른경우도 있다


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
