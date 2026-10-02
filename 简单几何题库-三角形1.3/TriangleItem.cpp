#include "TriangleItem.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <utility>    
#include <algorithm>  // VS兼容: 安装了Fix File Encoding后，解决了34个报错。

using namespace std;

// ==================== 构造函数 ====================

TriangleItem::TriangleItem()
    : m_a(0), m_b(0), m_c(0),
    m_userArea(0), m_userPerimeter(0),
    m_correctArea(0), m_correctPerimeter(0),
    m_score(0) {
}

TriangleItem::TriangleItem(int a, int b, int c)
    : m_a(a), m_b(b), m_c(c),
    m_userArea(0), m_userPerimeter(0),
    m_correctArea(0), m_correctPerimeter(0),
    m_score(0) {
}

// ==================== 核心方法 ====================

void TriangleItem::setSize(int a, int b, int c)
{
    m_a = a;
    m_b = b;
    m_c = c;
}

bool TriangleItem::isValid() const
{
    if (m_a <= 0 || m_b <= 0 || m_c <= 0) return false;
    return (m_a + m_b > m_c) &&
        (m_a + m_c > m_b) &&
        (m_b + m_c > m_a);
}

bool TriangleItem::isTriangle() const
{
    return isValid();
}

int TriangleItem::calPerimeter() const
{
    if (!isValid()) return -1;
    return m_a + m_b + m_c;
}

double TriangleItem::calArea() const
{
    if (!isValid()) return -1.0;
    // Heron公式: S = sqrt(p*(p-a)*(p-b)*(p-c)), p = 周长/2
    double p = static_cast<double>(calPerimeter()) / 2.0;
    return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
}

// ==================== 输出与交互 ====================

void TriangleItem::printTri() const
{
    if (!isValid()) {
        cout << "输入的三边不能构成三角形，请检查输入值。" << endl;
        return;
    }
    cout << "三角形的三边长度为：" << m_a << ", "
        << m_b << ", " << m_c << "。" << endl;
    cout << "三角形类型：" << getTypeDesc() << endl;
}

void TriangleItem::clearInputError()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void TriangleItem::checkUserAnswer()
{
    if (!isValid()) {
        cout << "输入的三边不能构成三角形，无法计算。" << endl;
        return;
    }

    m_correctPerimeter = calPerimeter();
    m_correctArea = calArea();
    m_score = 0;

    // --- 周长输入 ---
    cout << "请计算并输入周长：";
    if (!(cin >> m_userPerimeter)) {
        clearInputError();
        cout << "输入格式错误，请输入数字。" << endl;
        return;
    }

    // --- 面积输入 ---
    cout << "请计算并输入面积(保留两位小数)：" << fixed << setprecision(2);
    if (!(cin >> m_userArea)) {
        clearInputError();
        cout << "输入格式错误，请输入数字。" << endl;
        return;
    }

    // --- 判分 ---
    bool perimeterOk = fabs(m_userPerimeter - m_correctPerimeter) <= TOL;
    bool areaOk = fabs(m_userArea - m_correctArea) <= TOL;

    if (perimeterOk) {
        cout << "周长计算正确！" << endl;
        m_score += 50;
    }
    else {
        cout << "周长计算错误，正确答案为："
            << static_cast<int>(m_correctPerimeter) << "。" << endl;
    }

    if (areaOk) {
        cout << "面积计算正确！" << endl;
        m_score += 50;
    }
    else {
        cout << "面积计算错误，正确答案为："
            << fixed << setprecision(2) << m_correctArea << "。" << endl;
    }

    cout << "本题得分：" << m_score << " 分" << endl;
}

// ==================== 辅助方法 ====================

string TriangleItem::getTypeDesc() const
{
    if (!isValid()) return "非三角形";

    // 等边三角形
    if (m_a == m_b && m_b == m_c)
        return "等边三角形";

    // 等腰三角形
    if (m_a == m_b || m_b == m_c || m_a == m_c)
        return "等腰三角形";

    // 直角三角形 (勾股定理)
    int sides[3] = { m_a, m_b, m_c };
    // 简单排序
    for (int i = 0; i < 2; ++i)
        for (int j = i + 1; j < 3; ++j)
            if (sides[i] > sides[j])
                swap(sides[i], sides[j]);
    // sides[0] <= sides[1] <= sides[2]
    if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2])
        return "直角三角形";

    return "普通三角形";
}