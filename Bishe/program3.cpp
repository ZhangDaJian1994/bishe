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
struct Result
{
	int size;
	// ����ֵ = Nά�ռ��ĳС�����Ӧ�ĸ���ֵ
	// error ��ʾ���������ֵ����irramʵ������ ��ȥ �������ֵ���븡�����     // �Ĳ�ֵ
	// error = irram���򣨸���ֵ��- ������򣨸���ֵ����
	REAL error;

	Result(int n) {
		size = n;
		mid = mid[2 * size];
	}
	// Nά�ռ乲��2*N���м��ֵ������ÿһά�ռ��������м�㣬������ʾ��һά     // �����䷶Χ
	// ÿһ��ά�ȵ�����ֵ����ʾ���ά�ȵ����䣬��ô��ά�ȹ�����һ�������
	// �Խǵ㣬�ϲ���ʱ�������һ����ķ����
	struct MiddleValue<T>* mid;
};

struct ResultList
{
	int size;

	struct Result* results;
};

// ��������
MyFloat * arrNLoop;

// ���������
//Result<MyFloat*> resList_float(10);
struct ResultList* resultList;

// ����ά��
int dimension = 10;
// ����ѭ���Ƿ������־
bool loopOver = false;
int getInstrutionVariableNumber(std::string inputInstruction) {
	int n = 1;
	// TODO ����ָ���м�������
	dimension = n;
	// ���峤��Ϊn�����飬�洢ÿ��ά�ȵ�ǰ�����ĸ���ֵ
	arrNLoop = new MyFloat[n];
	return n;
}

void initDataStruct(int n) {
	// �������ֵ��ʼ��Ϊ��������Сֵ
	init(arrNLoop);
}

void init(MyFloat * arrNLoop)
{
	for (int i = 0; i < dimension; i++) {
		arrNLoop[i] = *FLOAT_MIN;
	}
}

void init(MyFloat* arrNLoop, int index) {
	for (int i = 0; i <= index; i++) {
		arrNLoop[i] = *FLOAT_MIN;
	}
	int newIndex = index+1;
	while (newIndex < dimension) {
		if (newIndex == dimension - 1 && arrNLoop[newIndex].isFloatMax()) {
			// ѭ������
			loopOver = true;
		}
		else if(arrNLoop[newIndex].isFloatMax()){
			arrNLoop[newIndex] = *FLOAT_MIN;
		}
		else {
			arrNLoop[newIndex] = *arrNLoop[newIndex].up();
			break;
		}
		newIndex++;
	}
}
// ����ͨ���ݹ�ʵ�ֶ�̬N��ѭ��
void calc(std::string inputInstruction) {
	//int n = getInstrutionVariableNumber(inputInstruction);
	//initDataStruct(n);  
	// ���ѭ���������һλ�Ѿ�Ϊ���������ֵ�����˳��ݹ�
	if (arrNLoop[dimension-1].isFloatMax()) {
		return;
	}
	for (int currentDim = 0; currentDim < dimension; ) {
		// ����nά
		MyFloat begin = arrNLoop[currentDim];
		for (; !begin.isFloatMax(); begin = *begin.up()) 
		{
			Result<MyFloat*> result(dimension);
			int index = 0;
			// ��ÿһ��ά�ȵ��м��ֵд��Result
			while (index < dimension)
			{
				struct MiddleValue<MyFloat*> leftMiddleVal;
				leftMiddleVal.value = &arrNLoop[index];
				leftMiddleVal.direct = false;
				// ���м��Ϊ����һ����������
				struct MiddleValue<MyFloat*> rightMiddleVal;
				rightMiddleVal.value = arrNLoop[index].up();
				rightMiddleVal.direct = false;
				int left = index, right = left + 1;
				result.mid[left] = leftMiddleVal;
				result.mid[right] = rightMiddleVal;
				index++;
			}
			// ���ó���������
			if (fileExist("xx") && fileExist("xx")) {
				// TODO ����float�������������
				// TODO ����real�������ʵ�����
				// TODO �������
				REAL error = "1";
				result.error = error;
				//resList_float.error[index++] = error;
			}
			else {
				// ���ɼ�������ټ������
			}
			resultList->

		}

		// �Ż�-����ϲ�
		//intervalMerge(resList_float);

		// TODO ���д���ļ�
		writeFile(*resultList);
		//���³�ʼ��ѭ������
		if (arrNLoop[currentDim + 1].isFloatMax()) {
			//arrNLoop[currentDim + 1] = *FLOAT_MIN;
			init(arrNLoop, currentDim + 1);
			if (loopOver) break;
		}
		else {
			arrNLoop[currentDim] = *FLOAT_MIN;
			arrNLoop[currentDim+1] = *arrNLoop[currentDim + 1].up();
		}
		//init(arrNLoop, currentDim + 1, arrNLoop[currentDim + 1].up());
		// �ݹ�
		//return calc(inputInstruction);
}

	}
bool isFloatMax(MyFloat f) {
	return f.isFloatMax();
}

bool fileExist(std::string filePath) {
	struct stat buffer;
	return (stat(filePath.c_str(), &buffer)) == 0;
}
// �ϲ����䣬������ֵ��Сһ�£�����Ժϲ�
void intervalMerge(struct ResultList resultList) {
	int size = resultList.size;
	//REAL* errorList = resultList.error;
	for (int i = 0; i < size-1; i++) {
		// ���һ�£����Ժϲ�
		// TODO ��ô�ϲ�
		if (errorList[i] == errorList[i + 1]) {

		}
	}
}

void writeFile(struct ResultList resultList)
{
	FILE* fp = fopen("result.txt", "w");
	
	if (fp) {
		for (int i = 0; i < resultList.size; i++) {
			
			//fprintf(fp,"%s\n", resultList.results[i].)
		}
	}
}