#pragma once
#include <list>
#include <iostream>
#include <string>
#include "MyFloat.h"
#include "const.h"
#include "iRRAM/lib.h"
#include <sys/stat.h>
#include "generateIrram.h"
using namespace iRRAM;

unsigned char buffer[4] = { 0xff,0xff,0xff,0xff };
MyFloatPtr FLOAT_MAX = new MyFloat(true, 127, buffer, MANTISSA_SIZE);
MyFloatPtr FLOAT_MIN = new MyFloat(false, -126, buffer, MANTISSA_SIZE);

/**
**	V1.3 ʹ��ģ��������float �� double
	MiddleValue ������ʾ���м�㡿���������ڸ��������м��ֵ
**/
//template<class T>
struct MiddleValue
{
	// ���ͣ����ڱ�ʾ�����Ȼ�˫���ȸ���ֵ
	MyFloat value;
	// Ϊtrue ��ʾΪd�ұߵ����ڽ����м�㣬
	// Ϊfalse ��ʾΪd��ߵ����ڽ����м��
	bool direct;
};
/**
** �����洢Nά�ռ��У�ÿһά��Ӧ��һ��С���估��Ӧ����
**/
//template<class T>
struct Result
{
	int dimension;
	// ����ֵ = Nά�ռ��ĳС�����Ӧ�ĸ���ֵ
	// error ��ʾ���������ֵ����irramʵ������ ��ȥ �������ֵ���븡�����     // �Ĳ�ֵ
	// error = irram���򣨸���ֵ��- ������򣨸���ֵ����
	REAL error;

	/*
	Result(int n) {
		size = n;
		mid = mid[2 * dimension];
	}*/
	// Nά�ռ乲��2*N���м��ֵ������ÿһά�ռ��������м�㣬������ʾ��һά     // �����䷶Χ
	// ÿһ��ά�ȵ�����ֵ����ʾ���ά�ȵ����䣬��ô��ά�ȹ�����һ�������
	// �Խǵ㣬�ϲ���ʱ�������һ����ķ����
	struct MiddleValue *mid;
};

/*
struct ResultList
{
	int size;

	struct Result *results;
};
*/

// ����ά������
MyFloatPtr arrNLoop;

// ���������
std::list<Result> resultList;

// ����ά��
int dimension = 10;
// ����ѭ���Ƿ������־
bool loopOver = false;

void initDataStruct(int n);

void calc(std::string inputInstruction);

void init(MyFloatPtr arrNLoop);

bool fileExist(std::string filePath);

void intervalMerge(std::list<Result>& resultList);

void writeFile(std::list<Result>& resultList);

void calcError(Result& result);

void cycle(int localDim, Result& result);