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
struct Result
{
	int size;
	// 浮点值 = N维空间的某小区间对应的浮点值
	// error 表示将这个浮点值带入irram实数程序 减去 这个浮点值带入浮点程序     // 的差值
	// error = irram程序（浮点值）- 浮点程序（浮点值）；
	REAL error;

	Result(int n) {
		size = n;
		mid = mid[2 * size];
	}
	// N维空间共有2*N个中间点值，其中每一维空间有两个中间点，用来表示这一维     // 的区间范围
	// 每一个维度的两个值，表示这个维度的区间，这么多维度构成了一个方块块
	// 对角点，合并的时候必须是一个大的方块块
	struct MiddleValue<T>* mid;
};

struct ResultList
{
	int size;

	struct Result* results;
};

// 声明数组
MyFloat * arrNLoop;

// 声明结果集
//Result<MyFloat*> resList_float(10);
struct ResultList* resultList;

// 声明维度
int dimension = 10;
// 声明循环是否结束标志
bool loopOver = false;
int getInstrutionVariableNumber(std::string inputInstruction) {
	int n = 1;
	// TODO 分析指令有几个变量
	dimension = n;
	// 定义长度为n的数组，存储每个维度当前遍历的浮点值
	arrNLoop = new MyFloat[n];
	return n;
}

void initDataStruct(int n) {
	// 将数组的值初始化为浮点数最小值
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
			// 循环结束
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
// 考虑通过递归实现动态N重循环
void calc(std::string inputInstruction) {
	//int n = getInstrutionVariableNumber(inputInstruction);
	//initDataStruct(n);  
	// 如果循环数组最后一位已经为浮点数最大值，则退出递归
	if (arrNLoop[dimension-1].isFloatMax()) {
		return;
	}
	for (int currentDim = 0; currentDim < dimension; ) {
		// 遍历n维
		MyFloat begin = arrNLoop[currentDim];
		for (; !begin.isFloatMax(); begin = *begin.up()) 
		{
			Result<MyFloat*> result(dimension);
			int index = 0;
			// 将每一个维度的中间点值写入Result
			while (index < dimension)
			{
				struct MiddleValue<MyFloat*> leftMiddleVal;
				leftMiddleVal.value = &arrNLoop[index];
				leftMiddleVal.direct = false;
				// 右中间点为【下一浮点数，左】
				struct MiddleValue<MyFloat*> rightMiddleVal;
				rightMiddleVal.value = arrNLoop[index].up();
				rightMiddleVal.direct = false;
				int left = index, right = left + 1;
				result.mid[left] = leftMiddleVal;
				result.mid[right] = rightMiddleVal;
				index++;
			}
			// 调用程序算出误差
			if (fileExist("xx") && fileExist("xx")) {
				// TODO 调用float程序算出浮点结果
				// TODO 调用real程序算出实数结果
				// TODO 计算误差
				REAL error = "1";
				result.error = error;
				//resList_float.error[index++] = error;
			}
			else {
				// 生成计算程序，再计算误差
			}
			resultList->

		}

		// 优化-区间合并
		//intervalMerge(resList_float);

		// TODO 结果写入文件
		writeFile(*resultList);
		//重新初始化循环数组
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
		// 递归
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
// 合并区间，如果误差值大小一致，则可以合并
void intervalMerge(struct ResultList resultList) {
	int size = resultList.size;
	//REAL* errorList = resultList.error;
	for (int i = 0; i < size-1; i++) {
		// 误差一致，可以合并
		// TODO 怎么合并
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