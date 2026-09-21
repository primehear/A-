#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class TriangleItem
{
private:
	float m_usera;
	float m_area;
	int m_a, m_b, m_c;
	int m_permeter;
	int m_upermeter;
	int m_score;
	static constexpr double TOL = 1e-3;
public:
	TriangleItem();
	TriangleItem(int a, int b, int c);
	void getAnswer(float area, int permeter) {
		this->m_usera = area;
		this->m_upermeter = permeter;
	}
	void setSize(int a, int b, int c) {
		this->m_a = a;
		this->m_b = b;
		this->m_c = c;
	}
	void printTri() const {
		if (!isTriangle()) {
			std::cout << "输入的三边不能构成三角形" << std::endl;
			return;
		}
		std::cout << "三角形的三边长度为：" << m_a << ", " << m_b << ", " << m_c << std::endl;
	}
	bool isTriangle() const {
		if (m_a<=0||m_b<=0||m_c<=0) return false;
		return (m_a + m_b > m_c) && (m_a + m_c > m_b) && (m_b + m_c > m_a);
	}
	int calpermeter() const {
		if (!isTriangle()) return -1;
		return m_a + m_b + m_c;
	}
	float calarea() const {
		if (!isTriangle()) return -1.0;
		float s = calpermeter() / 2.0;
		return sqrt(s * (s - m_a) * (s - m_b) * (s - m_c));
	}
	bool checkPerimeter(double userP) const {
		if (!isTriangle()) return false;
		double correct = calpermeter();
		return fabs(userP - correct) <= TOL;
	}
	bool checkArea(double userA) const {
		if (!isTriangle()) return false;
		double correct = calarea();
		return fabs(userA - correct) <= TOL;
	}
	void chackUserAnswer() const {
		if (!isTriangle()) {
			cout << "输入的三边不能构成三角形" << endl;
			return;
		}
		double userP, userA;
		cout << "请计算并输入周长";
		cin >> userP;
		cout << "请计算并输入面积";
		cin >> userA;
		double correctP = calpermeter();
		double correctA = calarea();
		if (checkPerimeter(userP)) {
			cout << "周长计算正确" << endl;
		}
		else {
			cout << "周长计算错误，正确答案为：" << correctP << endl;
		}
		if (checkArea(userA)) {
			cout << "面积计算正确" << endl;
		}
		else {
			cout << "面积计算错误，正确答案为：" << correctA << endl;
		}
	}
	void flow();
	inline float getArea() const { return m_area; }
	inline float getPermerter() const { return m_permeter; }
	inline float getUsera() const { return m_usera; }
	inline float getUpermeter() const { return m_upermeter; }
	inline float getA() const { return m_a; }
	inline float getB() const { return m_b; }
	inline float getC() const { return m_c; }
	inline float getScore() const { return m_score; }
}
int main() {
	int a, b, c;
	cout << "请输入三角形的三边长度：";
	cin >> a >> b >> c;
	TriangleItem triangle(a, b, c);
	triangle.printTri();
	triangle.chackUserAnswer();
	return 0;
}