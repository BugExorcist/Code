#include <iostream>
using namespace std;

void processInput(int t) 
{
    int arr[5] = { 1, 2, 3, 4, 5 }; 

    if (t >= 0 && t <= 6) 
    {
        cout << "Array element: " << arr[t] << endl;
    }
    else {
        cout << "Index out of bounds." << endl;
    }
}

int main() {
    int t1 = 4; // t1ִ��fault��������t1����Ч�����������û��error
    int t2 = 5; // t2ִ��fault�����ҳ��Է���arr[5]��������error(�ڲ�����)�������ᵼ�³������(failure)
    int t3 = 6; // t3����ִ��fault�����һᵼ��failure����Ϊ���Է��ʲ����ڵ�����Ԫ��

    processInput(t1); 
    processInput(t2);
    processInput(t3);

    return 0;
}