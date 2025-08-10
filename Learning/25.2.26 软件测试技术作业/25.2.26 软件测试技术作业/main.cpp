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
    int t1 = 4; // t1执行fault，但由于t1是有效的索引，因此没有error
    int t2 = 5; // t2执行fault，并且尝试访问arr[5]，这会产生error(内部错误)，但不会导致程序崩溃(failure)
    int t3 = 6; // t3不仅执行fault，而且会导致failure，因为尝试访问不存在的数组元素

    processInput(t1); 
    processInput(t2);
    processInput(t3);

    return 0;
}