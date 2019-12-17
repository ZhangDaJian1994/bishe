#include "program3.h"
/*��ȡָ���Ԫ��������Ӧ��ά��ֵ*/

int getInstrutionVariableNumber(std::string inputInstruction) {
	int n = 1;
	// TODO ����ָ���м�������
	dimension = n;
	// ���峤��Ϊn�����飬�洢ÿ��ά�ȵ�ǰ�����ĸ���ֵ
	arrNLoop = new MyFloat[dimension];
	return n;
}

void initDataStruct(int n) {
	// �������ֵ��ʼ��Ϊ��������Сֵ
	init(arrNLoop);
}

/* �������ֵ��ʼ��Ϊ��������Сֵ */
void init(MyFloatPtr arrNLoop)
{
	for (int i = 0; i < dimension; i++) {
		arrNLoop[i] = *FLOAT_MIN;
	}
}

void init(MyFloatPtr arrNLoop, int index) {
	// �±�index ֮ǰ�������ʼ��Ϊ��������Сֵ
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
/* �ݹ鶯̬����N��ѭ�� */
void cycle(int localDim, Result& result)
{
	MyFloat *begin = FLOAT_MIN;
	for (; !begin->isFloatMax(); begin = begin->up())
	{
		// �������м��
		struct MiddleValue leftMiddleVal;
		leftMiddleVal.value = *begin;
		leftMiddleVal.direct = false;
		// �������м��
		struct MiddleValue rightMiddleVal;
		rightMiddleVal.value = *begin->up();
		rightMiddleVal.direct = false;

		if (dimension == 1)
		{
			result.mid[2 * (dimension - 1)] = leftMiddleVal;
			result.mid[2 * (dimension - 1) + 1] = rightMiddleVal;
			// �������
			calcError(result);

			// TODO ��κϲ���ͬά�ȵ����
			if (result.error == preResult->error)	// ���һ�£��ϲ�
			{
				// ��ֵ���£���ֵ����
				result.mid[2 * (dimension - 1)] = preResult->mid[2 * (dimension - 1)];
				// ɾ�������е�preResult
				resultList.pop_back();
			}
			// (�ϲ����result)��������
			resultList.push_back(result);
			// ��ֵ�µ�preResult
			preResult = &result;
		}
		else
		{
			int curDim = dimension - localDim;
			result.mid[2 * curDim] = leftMiddleVal;
			result.mid[2 * curDim + 1] = rightMiddleVal;
			// �ݹ�
			cycle(localDim - 1, result);
		}
	}
}
/*
// TODO ����ͨ���ݹ�ʵ�ֶ�̬N��ѭ��
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
			Result result;
			result.mid = new MiddleValue[2 * dimension];
			int index = 0;
			// ��ÿһ��ά�ȵ��м��ֵд��Result
			while (index < dimension)
			{
				struct MiddleValue leftMiddleVal;
				leftMiddleVal.value = arrNLoop[index];
				leftMiddleVal.direct = false;
				// ���м��Ϊ����һ����������
				struct MiddleValue rightMiddleVal;
				rightMiddleVal.value = *arrNLoop[index].up();
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
			}
			else {
				// ���ɼ�������ټ������
			}
			// ���뼯��
			resultList.push_back(result);
		}

		// �Ż�-����ϲ�
		//intervalMerge(resList_float);

		// TODO ���д���ļ�
		writeFile(resultList);
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
	}*/
bool isFloatMax(MyFloat f) {
	return f.isFloatMax();
}

bool fileExist(std::string filePath) {
	struct stat buffer;
	return (stat(filePath.c_str(), &buffer)) == 0;
}
// �ϲ����䣬������ֵ��Сһ�£�����Ժϲ�
void intervalMerge(std::list<Result>& resultList) {
	int size = resultList.size();
	//REAL* errorList = resultList.error;
	for (int i = 0; i < size-1; i++) {
		// ���һ�£����Ժϲ�
		// TODO ��ô�ϲ�
		
	}
}

/* ���д���ļ� */
void writeFile(std::list<Result>& resultList)
{
	FILE* fp = fopen("result.txt", "w");
	if (fp) {
		std::list<Result>::iterator iter = resultList.begin();
		for (; iter != resultList.end(); iter++) {
			// ���Nά��������
			fprintf(fp, "{");
			for (int i = 0; i < dimension; i++) {
				fprintf(fp, "[%s,", (*iter).mid[2 * i].value);
				fprintf(fp, "%s],", (*iter).mid[2 * i+1].value);
			}
			fprintf(fp, "}");
			// ��������֮���� �� �ָ�
			fprintf(fp, ":");
			// ������
			fprintf(fp, "%s\n", (*iter).error);
		}
	}
	else {
		std::cout << "result.txt ��ʧ�ܣ� �����쳣�˳�������" << std::endl;
		exit(1);
	}
	fclose(fp);
}

/* ������� */
void calcError(Result& result)
{
	if (fileExist("xx") && fileExist("xx")) {
		// TODO ����float�������������
		// TODO ����real�������ʵ�����
		// TODO �������
		REAL error = "1";
		result.error = error;
	}
	else {
		// TODO ���ɼ�������ټ������
		std::string instruction;
		generateFloatCpp(instruction);
		generateIrramCpp(instruction);
		std::string const FULL_FLOAT_CPP_PATH
			= FLOAT_CPP_PATH + FLOAT_FILE_NAME + NAME_DELIMITER + CPP_SUFFIX;
		std::string const FULL_IRRAM_CPP_PATH
			= IRRAM_CPP_PATH + IRRAM_FILE_NAME + NAME_DELIMITER + CPP_SUFFIX;
		compileCpp(FULL_FLOAT_CPP_PATH);
		compileCpp(FULL_IRRAM_CPP_PATH);
		calcError(result);
	}
}