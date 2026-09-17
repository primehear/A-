#include<iostream>
#include<string>
class TriangleItem
{
private:
	float m_usera;
	float m_area;
	int m_a;
	int m_b;
	int m_c;
	int m_permeter;
	int m_upermeter;
	int m_score;
public:
	TriangleItem();
	TriangleItem(int a, int b, int c);
	void set(int a, int b, int c);
	void printTri();
	bool isTriangle();
	int calpermeter();
	float calarea();
	bool isRight();
	void flow();
	inline float getArea() const { return m_area; }
	inline float getPermerter() const { return m_permeter; }
	inline float getUsera() const { return m_usera; }
	inline float getUpermeter() const { return m_upermeter; }
	inline float getA() const { return m_a; }
	inline float getB() const { return m_b; }
	inline float getC() const { return m_c; }
	inline float getScore() const { return m_score; }
int main() {

}