// *** Map_v0.2
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
	// map �迭 ���
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
		Player, 
		Enemy, 
		Bullet, 
		Max,
	};

	const int MaxObject = 128;

	int Array[Max][MaxObject];

	for (int i = 0; i < Max; ++i)
	{
		for (int j = 0; j < MaxObject; ++j)
		{
			Array[i][j] = j;
		}
	}

	for (int i = 0; i < MaxObject; ++i)
		cout << Array[Enemy][i] << endl;
	*/

	// ��Ʈ��忡 2���� ���� ��带 ���������� (����Ʈ������)
	// �츮�� ����� ���� ����� Ʈ��(���� ����Ʈ��)
	// if 1 ~ 100�� �������� �ڸ��ٲ��� �������� ��ȿ�����ε� �̶� ����ϴ� ���� ����� Ʈ�� �����̴�.
	// ����� Ʈ�� ���� ����
	/*
		https://blog.naver.com/shekwl24/222244067579

		����� Ʈ�� ������ ����ϴ� ����
		������ ���������� ���� ȿ���� ���� ������ ��Ʈ ��尡 �������� �ʰ� �� ȿ�����ΰ����� �ٲ�� ������
		��忡 ���� ���� 4����Ʈ ������ ���°��� �ƴ� vector�� list�� ����������

		�츮�� �������ϰ� ����Ʈ�� �������� ����������
		���η� ���� �������� ��� �þ����ִ� ������
		link the rist?

		���� ����ϴ� ����
		1. ���ʿ��� ���������� ���� Ž�� 
		2. ������ �Ʒ��� ���� Ž��
		3. �����ʿ��� �������� ���� Ž��
		4. �Ʒ����� ���� ���� Ž��

		���� ����� ������ �������ٸ�
		���� ������ 

		800��° ���� ã������
		list 800�� ���ƾ���
		vector ã�������� ��������

		map�� �ִ� 10�� ���Ϸ� ã��������(�����͸� ã�°� �����ϱ� �����ϱⰡ ����.)

		�ؽ����̺� Ʈ������(if) �����, ����-��������)

		�ѹ� ����Ⱑ �����ʴ�.

		push_back���� �־��ָ� ��� �ȿ� ��

		���θ�ó�� ��ܿ� ���� ������ list�� ���� �տ� �־��ָ�� ������ �ٸ�
	*/

	// map ���
	map<int, int > Numbers;

	
	Numbers[0] = 0;
	Numbers[1] = 10;
	// Numbers[2] = 20;
	Numbers[3] = 30;

	// �����Է� ������� ���� ������ �ǹ���
	// ������ �����͸� ��ȣ���� ���ϱ� ������ ������ ������ ��ٷӴ�(���Ѵ�).
	// ������ �����Ͱ� ���°��� Ȯ���Ҷ� ó������ �ִµ� ������� ���α׷��� �������̰ų� �Ҷ��� �̷��� ���� ����
	// Numbers[1] = 30;

	// ��Ÿ�� �߿��� make_pair()�� ��������ν� ���������͸� �����ִ°� �߿���
	Numbers.insert( make_pair(4, 40) );
	
	// *** make_pair �� ���� �����͸� ��ȣ��
	// Numbers.insert( make_pair(2, 200) );
	
	// ** Ű ���� ã���� 
	map<int, int >::iterator iter = Numbers.find(2);

	// ** Ű ���� �������� �������� Numbers.end()�� ���� ������  if ������ �־���
	if (iter == Numbers.end())
	{
		// *** Ű���� 2�� �����Ͱ� ������ �߰�
		Numbers.insert( make_pair(2, 200) );
	}

	// *** Ű���� 2�� �����Ͱ� ������ ����
	iter->second = 200;

	// �迭�� ���
	/*
	for (int i = 0; i < 5; ++i)
	{
		cout << Numbers[i] << endl;
	}
	*/

	// �ݺ��ڷ� ���
	for (map<int, int >::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter)
	{
		cout << iter->second << endl;
	}

	// ���ȭ -> �ݺ��Ǵ� �ڵ��� ���̴°�
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

// �����ð� ���� �̻� �Ѿ�� �Ἦó��
// �ҽ����˿� ������ ������� ������ �������� -> �����ݾ��� 3�踦 ���������
// if ȭ��ǰ��� ���ϰ� ���°� ����
// ���ߵ�����