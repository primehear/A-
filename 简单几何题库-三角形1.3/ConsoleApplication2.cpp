#include <iostream>
#include <limits>
#include "TriangleItem.h"

using namespace std;

///  安全读取整数输入，失败时清空缓冲区并返回false
bool readInt(int& val)
{
    if (!(cin >> val)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "输入格式错误，请输入整数。" << endl;
        return false;
    }
    return true;
}

///  提示用户输入三边并校验
bool promptSides(int& a, int& b, int& c)
{
    cout << "请输入三角形的三边长度(正整数)：";
    if (!readInt(a) || !readInt(b) || !readInt(c))
        return false;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "边长必须为正整数，请重新输入。" << endl;
        return false;
    }
    return true;
}

int main()
{
    cout << "========== 三角形几何题库系统 ==========" << endl;

    int a, b, c;

    // 循环输入直到获得有效三角形
    while (true) {
        if (promptSides(a, b, c))
            break;
        cout << "请重新输入：" << endl;
    }

    TriangleItem triangle(a, b, c);

    // 打印三角形信息
    triangle.printTri();

    // 判题
    triangle.checkUserAnswer();

    cout << "========== 答题结束 ==========" << endl;
    return 0;
}