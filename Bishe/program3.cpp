#include <iostream>
#include <string>
#include "MyFloat.h"
#include "const.h"
#include "program3.h"

unsigned char buffer[4] = { 0xff,0xff,0xff,0xff };
MyFloat* FLOAT_MAX = new MyFloat(true, 127, buffer, MANTISSA_SIZE);
MyFloat* FLOAT_MIN = new MyFloat(false, -126, buffer, MANTISSA_SIZE);


template<class T>
/**
**	V1.3 ʹ��ģ��������float �� double
**/
struct MiddleValue
{
	// ���ͣ����ڱ�ʾ�����Ȼ�˫���ȸ���ֵ
	T value;
	// Ϊtrue ��ʾΪd�ұߵ����ڽ����м�㣬
	// Ϊfalse ��ʾΪd��ߵ����ڽ����м��
	bool direct
};


template<class T>

struct test {
	T x;
	T y;
	test(T x, T y) {
		x = x;
		y = y;
	}

	T add() {
		return x + y;
	}

	struct test2
	{
		T z;
		void display() {
			std::cout << "hello" << std::endl;
		}
	};
};
/**
** �����洢Nά�ռ��У�ÿһ��С���估���Ӧ����
**/
template<class T>

struct ResultList
{
private:
	int n = 0;
	// ����ֵ = Nά�ռ��ĳС�����Ӧ�ĸ���ֵ
	// error ��ʾ���������ֵ����irramʵ������ ��ȥ �������ֵ���븡�����     // �Ĳ�ֵ
	// error = irram���򣨸���ֵ��- ������򣨸���ֵ����
	REAL error;

public:
	ResultList(int n) {
		n = n;
	}
	// Nά�ռ乲��2*N���м��ֵ������ÿһά�ռ��������м�㣬������ʾ��һά     // �����䷶Χ
	// ÿһ��ά�ȵ�����ֵ����ʾ���ά�ȵ����䣬��ô��ά�ȹ�����һ�������
	// �Խǵ㣬�ϲ���ʱ�������һ����ķ����
	struct MiddleValue<T> mid[2*n];
	
};

// ��������
MyFloat * arrNLoop;

// ���������
ResultList<float> resList_float(10);
test<float> tes(1.0, 2.0);

int getInstrutionVariableNumber(std::string inputInstruction) {
	// TODO ����ָ���м�������
	int n = 1;
	return n;
}

void initDataStruct(int n) {
	// ���峤��Ϊn�����飬�洢ÿ��ά�ȵ�ǰ�����ĸ���ֵ
	arrNLoop = new MyFloat[n];
	// �������ֵ��ʼ��Ϊ��������Сֵ
	init(arrNLoop, n);
}

void init(MyFloat * arrNLoop, int n)
{
	for (int i = 0; i < n; i++) {
		arrNLoop[i] = *FLOAT_MIN;
	}
}

void calc(std::string inputInstruction) {
	int n = getInstrutionVariableNumber(inputInstruction);
	initDataStruct(n);

	for (int i = 0; i < n; i++) {
		//
		tes.add();
		tes.
		

}

	}
bool isFloatMax(MyFloat f) {
	return f.isFloatMax();
}