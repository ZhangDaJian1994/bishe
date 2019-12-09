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
**	V1.3 使用模板来泛化float 和 double
**/
struct MiddleValue
{
	// 泛型，用于表示单精度或双精度浮点值
	T value;
	// 为true 表示为d右边的最邻近的中间点，
	// 为false 表示为d左边的最邻近的中间点
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
** 用来存储N维空间中，每一个小区间及其对应的误差。
**/
template<class T>

struct ResultList
{
private:
	int n = 0;
	// 浮点值 = N维空间的某小区间对应的浮点值
	// error 表示将这个浮点值带入irram实数程序 减去 这个浮点值带入浮点程序     // 的差值
	// error = irram程序（浮点值）- 浮点程序（浮点值）；
	REAL error;

public:
	ResultList(int n) {
		n = n;
	}
	// N维空间共有2*N个中间点值，其中每一维空间有两个中间点，用来表示这一维     // 的区间范围
	// 每一个维度的两个值，表示这个维度的区间，这么多维度构成了一个方块块
	// 对角点，合并的时候必须是一个大的方块块
	struct MiddleValue<T> mid[2*n];
	
};

// 声明数组
MyFloat * arrNLoop;

// 声明结果集
ResultList<float> resList_float(10);
test<float> tes(1.0, 2.0);

int getInstrutionVariableNumber(std::string inputInstruction) {
	// TODO 分析指令有几个变量
	int n = 1;
	return n;
}

void initDataStruct(int n) {
	// 定义长度为n的数组，存储每个维度当前遍历的浮点值
	arrNLoop = new MyFloat[n];
	// 将数组的值初始化为浮点数最小值
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