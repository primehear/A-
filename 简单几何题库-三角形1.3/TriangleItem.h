#pragma once
#include <limits>
#include <string>

/// 三角形题目类
/// 封装三角形的边长、合法性校验、周长/面积计算及用户答题判分逻辑
class TriangleItem {
private:
    int m_a, m_b, m_c;                  /// 三边长度
    double m_userArea;                    /// 用户输入的面积
    double m_userPerimeter;               /// 用户输入的周长
    double m_correctArea;                 /// 正确面积
    double m_correctPerimeter;            /// 正确周长
    int m_score;                          /// 得分(0~100)
    static constexpr double TOL = 1e-3;   /// 浮点比较容差

    ///  校验三边是否能构成有效三角形
    ///  当且仅当三边均为正数且满足三角不等式
    bool isValid() const;

    ///  清空输入缓冲区中的错误状态
    void clearInputError();

public:
    TriangleItem();
    TriangleItem(int a, int b, int c);

    void setSize(int a, int b, int c);

    bool isTriangle() const;

    ///  计算周长，无效三角形返回 -1
    int calPerimeter() const;

    ///  计算面积(Heron公式)，无效三角形返回 -1.0
    double calArea() const;

    ///  打印三角形基本信息
    void printTri() const;

    ///  交互式答题判分：提示用户输入周长和面积，给出得分
    void checkUserAnswer();

    // Getters
    int getA() const { return m_a; }
    int getB() const { return m_b; }
    int getC() const { return m_c; }
    double getCorrectArea() const { return m_correctArea; }
    double getCorrectPerimeter() const { return m_correctPerimeter; }
    double getUserArea() const { return m_userArea; }
    double getUserPerimeter() const { return m_userPerimeter; }
    int getScore() const { return m_score; }

    ///  获取三角形类型描述(等边/等腰/直角/普通)
    std::string getTypeDesc() const;
};