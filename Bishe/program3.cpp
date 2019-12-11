#include <iostream>
#include <string>
#include "MyFloat.h"
#include "const.h"
#include "program3.h"
#include "iRRAM/lib.h"
#include <sys/stat.h>
using namespace iRRAM;

unsigned char buffer[4] = { 0xff,0xff,0xff,0xff };
MyFloat* FLOAT_MAX = new MyFloat(true, 127, buffer, MANTISSA_SIZE);
MyFloat* FLOAT_MIN = new MyFloat(false, -126, buffer, MANTISSA_SIZE);

/**
**	V1.3 使用模板来泛化float 和 double
**/
template<class T>
struct MiddleValue
{
	// 泛型，用于表示单精度或双精度浮点值
	T value;
	// 为true 表示为d右边的最邻近的中间点，
	// 为false 表示为d左边的最邻近的中间点
	bool direct
};
/**
** 用来存储N维空间中，每一个小区间及其对应的误差。
**/
template<class T>
struct ResultList
{
	int size;
	// 浮点值 = N维空间的某小区间对应的浮点值
	// error 表示将这个浮点值带入irram实数程序 减去 这个浮点值带入浮点程序     // 的差值
	// error = irram程序（浮点值）- 浮点程序（浮点值）；
	REAL* error;

	ResultList(int n) {
		size = n;
		mid = mid[2 * size];
		error = error[size];
	}
	// N维空间共有2*N个中间点值，其中每一维空间有两个中间点，用来表示这一维     // 的区间范围
	// 每一个维度的两个值，表示这个维度的区间，这么多维度构成了一个方块块
	// 对角点，合并的时候必须是一个大的方块块
	struct MiddleValue<T>* mid;
};

// 声明数组
MyFloat * arrNLoop;

// 声明结果集
ResultList<MyFloat*> resList_float(10);

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
	int index = 0;
	for (int i = 0; i < n; i++) {
		// 遍历n维
		MyFloat* begin = FLOAT_MIN;
		for (; !begin->isFloatMax(); begin = begin->up()) {
			struct MiddleValue<MyFloat*> leftMiddleVal;
			leftMiddleVal.value = begin;
			leftMiddleVal.direct = false;
			// 右中间点为【下一浮点数，左】
			struct MiddleValue<MyFloat*> rightMiddleVal;
			rightMiddleVal.value = begin->up();
			rightMiddleVal.direct = false;
			int left = index, right = left+1;
			resList_float.mid[left] = leftMiddleVal;
			resList_float.mid[right] = rightMiddleVal;
			// 调用程序算出误差
			if (fileExist("xx") && fileExist("xx")) {
				// TODO 调用float程序算出浮点结果
				// TODO 调用real程序算出实数结果
				// TODO 计算误差
				REAL error = "1";
				resList_float.error[index++] = error;
			}
		}
		// 优化-区间合并
		intervalMerge(resList_float);

		// TODO 结果写入文件
		return;
}

	}
bool isFloatMax(MyFloat f) {
	return f.isFloatMax();
}

bool fileExist(std::string filePath) {
	struct stat buffer;
	return (stat(filePath.c_str(), &buffer)) == 0;
}

void intervalMerge(ResultList<MyFloat*> resultList) {
	int size = resultList.size;
	REAL* errorList = resultList.error;
	for (int i = 0; i < size-1; i++) {
		// 误差一致，可以合并
		// TODO 怎么合并
		if (errorList[i] == errorList[i + 1]) {

		}
	}
}