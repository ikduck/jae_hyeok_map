// *** Map_v0.4
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

// 100 10 10 100 50 ������⸦ �̿��Ͽ� �߶���ϴ� ���� �������� (�̱��� ������ �����)
// csb���� -> .�� ������ ������ ������ ����
// ����Ƽ������ ���� �ɷ�ġ ������ ����,���� ���� �־ �����ϴµ� �̶���
/*
#include <iostream>
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
vector<int, map<string, object>> Data;
// �̷������� ����� �� ������ �츮�� ������� ��������

// �츮�� �̷��� ����� ����
map<int, list<object>> Objects;
// �츮�� �����͸� �������� ���ü� ���� ������ ����ؾ���(c��� ��ü�� ������ ��������)

// �����̳��� ���չ���� �������� �ٲ�������� �Ѱ��� ����� ������������

return 0;
}
*/

#pragma region ������Ÿ�� ������ �Ϻκ� ver.1
// ������ ��������ڸ� ����� ������Ÿ�� ������ �Ϻκ�
/*
	������Ÿ�� ������ �Ϻκ�
	������ ����� ���� �����ϱ�� �����
	���� �����Ͽ� ����Ҽ� �ְ� ������ִ� ���� ���� �߿���
	�츮�� �������� ������ ���� �����ؾ��Ҷ� �����

	����� �������� �Ŷ�� �����ϸ��
	��������� = �����ͱ� new �Ҵ� = �� ������ �ӵ����̰� ���ٰ� �����ϸ��
	����ϰ� ���Ǵ� ��쿡 ����� if. ���� , �Ѿ� ,������
*/

/*
	struct Vector3
	{
		float x, y, z;
	
		// ������ �ʱ�ȭ ���ϸ� �����ɸ�
		Vector3() : x(0.0f), y(0.0f), z(0.0f) {};
		Vector3(const float& _x, const float& _y) : x(_x), y(_y), z(0.0f) {};
		Vector3(const float& _x, const float& _y, const float& _z) : x(_x), y(_y) , z(_z) {};
	};
	
	struct Trasnform
	{
		Vector3 Position;
		Vector3 Rotation;
		Vector3 Scale;
	};
	
	struct Object
	{
		Trasnform Info;
		Object() {};
		Object(const Trasnform& _Info) : Info(_Info) {};
	};
	
	struct Player : public Object
	{
	
		Player() {};
		// ���� ������(Object)�� ȣ�� -> ȣ���� ���� �����ڿ��� �ʱ�ȭ����
		Player(const Trasnform& _Info) : Object(_Info) {};
	};
	
	
	
	map<string, Object*> Objects;
	
	void Initialize();
	
	// void AddData(int _Key, int _Value);
	void AddObject(string _Key, Object* _Object);
	
	
	int main(void)
	{
			Initialize();
	
		cout << Objects["Player"]->Info.Position.x << endl;
		cout << Objects["Player"]->Info.Position.y << endl;
		cout << Objects["Player"]->Info.Position.z << endl;


		return 0;
		}
		
		void Initialize()
		{
			Trasnform Info;
		
			Info.Position.x = 10;
			Info.Position.y = 20;
			Info.Position.z = 30;
		
		
			Objects["Player"] = new Player(Info);
		}
		
		void AddObject(string _Key, Object* _Object)
		{
			map<string , Object* >::iterator iter = Objects.find(_Key);
		
			if (iter == Objects.end())
				Objects.insert(make_pair(_Key, _Object));
			else
				iter->second = _Object;
	}
*/

#pragma endregion

struct Vector3
{
	float x, y, z;

	// ������ �ʱ�ȭ ���ϸ� �����ɸ�
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {};
	Vector3(const float& _x, const float& _y) : x(_x), y(_y), z(0.0f) {};
	Vector3(const float& _x, const float& _y, const float& _z) : x(_x), y(_y) , z(_z) {};
};

struct Trasnform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};

struct Object
{
	Trasnform Info;
	Object() {};
	Object(const Trasnform& _Info) : Info(_Info) {};
};

struct Player : public Object
{
	Player() {};
	Player(const Trasnform& _Info) : Object(_Info) {};
};

struct Boss : public Object
{
	Boss() {};
	Boss(const Trasnform& _Info) : Object(_Info) {};
};

struct Enemy : public Object
{
	Enemy() {};
	Enemy(const Trasnform& _Info) : Object(_Info) {};
};


struct Bullet : public Object
{
	Bullet() {};
	Bullet(const Trasnform& _Info) : Object(_Info) {};
};

map<string, list<Object*>> Objects;

void Initialize();

// void AddData(int _Key, int _Value);
void AddObject(string _Key, Object* _Object);

int main(void)
{
	#pragma region 2022_06_17 Map ~ AddData����
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
	
	// map ���
	// map<int, int > Numbers;
	
	// ������ ����
	/*
	Numbers[0] = 0;
	Numbers[1] = 10;
	// Numbers[2] = 20;
	Numbers[3] = 30;
	
	
	// �����Է� ������� ���� ������ �ǹ���
	// ������ �����͸� ��ȣ���� ���ϱ� ������ ������ ������ ��ٷӴ�(���Ѵ�).
	// ������ �����Ͱ� ���°��� Ȯ���Ҷ� ó������ �ִµ� ������� ���α׷��� �������̰ų� �Ҷ��� �̷��� ���� ����
	// Numbers[1] = 30;
	
	// *** make_pair �� ���� �����͸� ��ȣ��
	// Numbers.insert( make_pair(2, 200) );
	
	// ��Ÿ�� �߿��� make_pair()�� ��������ν� ���������͸� �����ִ°� �߿���
	Numbers.insert( make_pair(4, 40) );
	
	AddData(2,200);
	*/
	
	// �迭�� ���
	/*
	for (int i = 0; i < 5; ++i)
	{
		cout << Numbers[i] << endl;
	}
	*/
	
	// ** Ű ���� ã���� 
	/*
	map<int, int >::iterator iter = Numbers.find(2);
	
	// ** Ű ���� �������� �������� Numbers.end()�� ���� ������  if ������ �־���
	if (iter == Numbers.end())
	{
		// *** Ű���� 2�� �����Ͱ� ������ �߰�
		Numbers.insert( make_pair(2, 200) );
	}
	
	// *** Ű���� 2�� �����Ͱ� ������ ����
	iter->second = 200;
	
	// ���ȭ -> �ݺ��Ǵ� �ڵ��� ���̴°�
	*/
	
	// �ݺ��ڷ� ���
	/*
	for (map<int, int >::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter)
	{
		cout << iter->second << endl;
	}
*/

#pragma endregion

	// Initialize();
	Trasnform Info;
	
	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;
	
	AddObject("Player", new Player(Info));
	AddObject("Player", new Player(Info));
	AddObject("Player", new Player(Info));
	
	Info.Position.x = 100;
	Info.Position.y = 200;
	Info.Position.z = 300;
	
	AddObject("Enemy", new Enemy(Info));
	AddObject("Enemy", new Enemy(Info));
	
	Info.Position.x = 1000;
	Info.Position.y = 2000;
	Info.Position.z = 3000;
	
	AddObject("Bullet", new Bullet(Info));
	AddObject("Bullet", new Bullet(Info));
	AddObject("Bullet", new Bullet(Info));
	
	Info.Position.x = 10000;
	Info.Position.y = 20000;
	Info.Position.z = 30000;
	
	AddObject("Boss", new Boss(Info));
	AddObject("Boss", new Boss(Info));
	AddObject("Boss", new Boss(Info));

	// ��� 1
	/*
	cout << Objects["Player"]->Info.Position.x << endl;
	cout << Objects["Player"]->Info.Position.y << endl;
	cout << Objects["Player"]->Info.Position.z << endl;

	for (list < Object*>::iterator iter = Objects.begin()->second.begin() ; iter != Objects.begin()->second.end(); ++iter)
	{
			cout << (*iter)->Info.Position.x << endl;
			cout << (*iter)->Info.Position.y << endl;
			cout << (*iter)->Info.Position.z << endl;
	}
	*/

	for (map<string, list<Object*>>::iterator iter = Objects.begin(); iter != Objects.end(); ++iter)
	{
		cout << "[" << iter->first << "]" << endl;
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			cout << (*iter2)->Info.Position.x << ", " << (*iter2)->Info.Position.y << ", "
				<< (*iter2)->Info.Position.z << endl;
		}
		cout << endl;
	}

	return 0;
}

void Initialize()
{
	Trasnform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;

	// Objects["Player"] = new Player(Info);
}

void AddObject(string _Key, Object* _Object)
{
	map<string , list<Object*>>::iterator iter = Objects.find(_Key);

	// Ű ���� �������� Ű���� �����ϰ� Temp�� value���� �����ؼ� �־���
	if (iter == Objects.end())
	{
		list<Object*> Temp;
		Temp.push_back(_Object);
		Objects.insert(make_pair(_Key, Temp));
	}
	// Ű ���� �ִٸ� value���� ���� 
	else
		iter->second.push_back(_Object);
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

// ����Ʈ���� ���Ͽ�(�ϼ��� ����Ʈ��, ����� Ʈ�� ����)
/*
	��Ʈ��忡 2���� ���� ��带 ���������� (����Ʈ������)
	�츮�� ����� ���� ����� Ʈ��(���� ����Ʈ��)
	if 1 ~ 100�� �������� �ڸ��ٲ��� �������� ��ȿ�����ε� �̶� ����ϴ� ���� ����� Ʈ�� �����̴�.
	����� Ʈ�� ���� ����

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

// ���� ���޻�Ȳ 2022/06/17
/*
	�����ð� ���� �̻� �Ѿ�� �Ἦó��
	�ҽ����˿� ������ ������� ������ �������� -> �����ݾ��� 3�踦 ���������
	if ȭ��ǰ��� ���ϰ� ���°� ����
	���ߵ�����
	6�� 20�� 1�� ~ 6�� A��
	7�� 25�� ���ķ� 3�� ~ 6�� �������� �ٲ�
	
	C++�� ���� // �ƽ�Ű ��Ʈ�� ����� ��Ʈ������
*/ 

// ���� ���� 2022/06/20
/*
	���α��� �Ƿ��̾����� ����, �ڽŸ��� ����� �����ϸ�ȵ� 
	�ڵ��׽�Ʈ? ���ݵ� ����������
	
	��Ʈ������ -> �п� ȫ�������� ����Ҽ� ����.
	�Ἦ ���� ���� ���� �� ���������
	�ĳ����������� �����ؾ��� ���������� ������
	�ڷᱸ��
	
	c++ �� ���� ��������! 
	API�� �������� -> ���̷�Ʈ(�̹� ����), mfc(�Ⱦ�)�� �ϰٴ� -> �ǹ̾���!
	���̷�Ʈ -> �⺻ 3D

	C++ stl c#�� �̿��� ����Ƽ 2d + 3d 

	�������� �ֽ� �Լ� �״�� �������
	�Լ� �����ϴ°� �ƴ϶� ����̶� ������

	�Լ��� �� ����°� �ƴ϶� �Լ��� �󸶳� �� �������� �� �߿���

	������ Ȱ�� -> ��Ʈ���� 

	Ⱦ��ũ�� 2d, ����ũ�� 2d ,3d ���±��� �� ��Ƴ��� (ȯ��)

	�̷¼� �ڵ��׽�Ʈ 

	2023 3�� ���ķ� �������� ���� 9���� or 10���� 
	���� �ʹ� ������ ������ �߿���

	å ��õ �Ұ� ���ξ���
	������� �����ϰ� �ϱ�
*/ 