// # *** Map_v0.1
#include <iostream>
#include <string>
#include <map>

using namespace std;



// 100 10 10 100 50 ������⸦ �̿��Ͽ� �߶���ϴ� ���� �������� (�̱��� ������ �����)
// csb���� -> .�� ������ ������ ������ ����
// ����Ƽ������ ���� �ɷ�ġ ������ ����,���� ���� �־ �����ϴµ� �̶���
/*
#include <list>
#include <vector>
#include <map> 

struct tagInfo
{
	string Data[128];
};

 struct object
{

};

int main(void)
{
vector<int, mao<string, object>> Data;
// �̷������� ����� �� ������ �츮�� ������� ��������

// �츮�� �̷��� ����� ����
// �츮�� �����͸� �������� ���ü� ���� ������ ����ؾ���(c��� ��ü�� ������ ��������)
map<int, list<object>> Objects;

// �����̳��� ���չ���� �������� �ٲ�������� �Ѱ��� ����� ������������

return 0;
}
*/

int main(void)
{
	/*
	map<int, int> Numbers;

	// *** Key , Value : ���ڷ� ���ڸ� ã��
	// map<int , int> 

	Numbers[0] = 1;
	Numbers[1] = 2;
	Numbers[2] = 3;
	Numbers[3] = 4;
	Numbers[4] = 5;

	for (int i = 0; i < 5; ++i)
	{
		cout << Numbers[i] << endl;
	}
	// �迭�� ����Ѵ� = map�� ����Ѵ�
	*/

	// iterator�� ��� 
	/*
	map<string, int> Numbers;

	Numbers["A"] = 1;
	Numbers["B"] = 2;
	Numbers["C"] = 3;
	Numbers["D"] = 4;
	Numbers["E"] = 5;

	// begin ���� ����(ù ����) end �� ����(������)
	for (map<string, int>::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter )
	{
		cout << iter->first << endl;
		cout << iter->second << endl << endl;
	}
	for (auto iter = Numbers.begin(); iter != Numbers.end(); ++iter )
	{
		cout << iter->first << endl;
		cout << iter->second << endl << endl;
	}

	// iter->first : Ű�� 
	// iter->second : value��

	*/

	// �ɺ��� ���
	/*
	enum Key {AAA,BBB,CCC,DDD,EEE};
	const int Max = 10;

	// �迭�� �������̸鼭 ����� ������ �ִ� (int , char(�ƽ�Ű �ڵ�� �޾ƿ�))

	int Array[Max]; 

	Key _State = AAA;

	cout << Array[_State] << endl;
	*/

	// �ɺ��� ������� ������ ���°� map�̴�
	/*
	enum Key
	{
		P,
		E,
		B,
		M,
	};

	const int Max = 128;

	int Array[M][Max];
	
	for(int i = 0; i< M.end(); ++i)
	*/
	return 0;
}


// ���� ����
/*
 �ν�Ÿ�� #~~~ �� ���� ��� 
 #�� �⺻�� �˻��ؾ��� Ű�� 1�� ���� 
 �پ��� ������ �ִµ� web�ʿ��� �� ���̾�
 ����ϴ� ȯ�濡 �����ϴ� �͵鿡 ���� ������ ���� �ٸ�
	c   :  �����͸� �����ϴ� ���·� ���� ����� (�̱����� �����)
	c++ :  
 ������ �ϴٰ� ������ ����ġ�� ĳ������ ������ �������־���ϴµ�
 �¶��ΰ��ӿ����� �̰��� ������ ��������ϴµ� �̸� ��� ������?
 ������ Ŭ���̾�Ʈ�� ���� �������� ������ ������ �ϰԵ�
*/