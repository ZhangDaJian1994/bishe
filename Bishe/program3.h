#pragma once
#include <list>
#include <iostream>
#include <string>
#include "MyFloat.h"
#include "const.h"
#include "iRRAM/lib.h"
#include <sys/stat.h>
#include "generateIrram.h"
//using namespace iRRAM;

unsigned char buffer[4] = { 0xff,0xff,0xff,0xff };
MyFloatPtr FLOAT_MAX = new MyFloat(true, 127, buffer, MANTISSA_SIZE);
MyFloatPtr FLOAT_MIN = new MyFloat(false, -126, buffer, MANTISSA_SIZE);

/**
**	V1.3 使用模板来泛化float 和 double
	MiddleValue 用来表示【中间点】：两个相邻浮点数最中间的值
**/
//template<class T>
struct MiddleValue
{
	// 泛型，用于表示单精度或双精度浮点值
	MyFloat value;
	// 为true 表示为d右边的最邻近的中间点，
	// 为false 表示为d左边的最邻近的中间点
	bool direct;
};
/**
** 用来存储N维空间中，每一维对应的一个小区间及对应的误差。
**/
//template<class T>
struct Result
{
	int dimension;
	// 浮点值 = N维空间的某小区间对应的浮点值
	// error 表示将这个浮点值带入irram实数程序 减去 这个浮点值带入浮点程序     // 的差值
	// error = irram程序（浮点值）- 浮点程序（浮点值）；
	iRRAM::REAL error;

	/*
	Result(int n) {
		size = n;
		mid = mid[2 * dimension];
	}*/
	// N维空间共有2*N个中间点值，其中每一维空间有两个中间点，用来表示这一维     // 的区间范围
	// 每一个维度的两个值，表示这个维度的区间，这么多维度构成了一个方块块
	// 对角点，合并的时候必须是一个大的方块块
	struct MiddleValue *mid;
};

/*
struct ResultList
{
	int size;

	struct Result *results;
};
*/

// 声明维度数组
MyFloatPtr arrNLoop;

// 声明结果集
std::list<Result> resultList;

// 声明上一个Result，用于区间合并
Result *preResult;

// 声明维度
int dimension = 10;
// 声明循环是否结束标志
bool loopOver = false;

void initDataStruct(int n);

void calc(std::string inputInstruction);

void init(MyFloatPtr arrNLoop);

bool fileExist(std::string filePath);

void intervalMerge(std::list<Result>& resultList);

void writeFile(std::list<Result>& resultList);

void calcError(Result& result);

void cycle(int localDim, Result& result);