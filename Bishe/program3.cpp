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
**	V1.3 ʹ��ģ��������float �� double
**/
template<class T>
struct MiddleValue
{
	// ���ͣ����ڱ�ʾ�����Ȼ�˫���ȸ���ֵ
	T value;
	// Ϊtrue ��ʾΪd�ұߵ����ڽ����м�㣬
	// Ϊfalse ��ʾΪd��ߵ����ڽ����м��
	bool direct
};
/**
** �����洢Nά�ռ��У�ÿһ��С���估���Ӧ����
**/
template<class T>
struct ResultList
{
	int size;
	// ����ֵ = Nά�ռ��ĳС�����Ӧ�ĸ���ֵ
	// error ��ʾ���������ֵ����irramʵ������ ��ȥ �������ֵ���븡�����     // �Ĳ�ֵ
	// error = irram���򣨸���ֵ��- ������򣨸���ֵ����
	REAL* error;

	ResultList(int n) {
		size = n;
		mid = mid[2 * size];
		error = error[size];
	}
	// Nά�ռ乲��2*N���м��ֵ������ÿһά�ռ��������м�㣬������ʾ��һά     // �����䷶Χ
	// ÿһ��ά�ȵ�����ֵ����ʾ���ά�ȵ����䣬��ô��ά�ȹ�����һ�������
	// �Խǵ㣬�ϲ���ʱ�������һ����ķ����
	struct MiddleValue<T>* mid;
};

// ��������
MyFloat * arrNLoop;

// ���������
ResultList<MyFloat*> resList_float(10);

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
	int index = 0;
	for (int i = 0; i < n; i++) {
		// ����nά
		MyFloat* begin = FLOAT_MIN;
		for (; !begin->isFloatMax(); begin = begin->up()) {
			struct MiddleValue<MyFloat*> leftMiddleVal;
			leftMiddleVal.value = begin;
			leftMiddleVal.direct = false;
			// ���м��Ϊ����һ����������
			struct MiddleValue<MyFloat*> rightMiddleVal;
			rightMiddleVal.value = begin->up();
			rightMiddleVal.direct = false;
			int left = index, right = left+1;
			resList_float.mid[left] = leftMiddleVal;
			resList_float.mid[right] = rightMiddleVal;
			// ���ó���������
			if (fileExist("xx") && fileExist("xx")) {
				// TODO ����float�������������
				// TODO ����real�������ʵ�����
				// TODO �������
				REAL error = "1";
				resList_float.error[index++] = error;
			}
		}
		// �Ż�-����ϲ�
		intervalMerge(resList_float);

		// TODO ���д���ļ�
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
		// ���һ�£����Ժϲ�
		// TODO ��ô�ϲ�
		if (errorList[i] == errorList[i + 1]) {

		}
	}
}