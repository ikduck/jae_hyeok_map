// *** Map_v0.4
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

// 100 10 10 100 50 띄워쓰기를 이용하여 잘라야하는 곳에 구별을줌 (싱글톤 패턴을 사용함)
// csb파일 -> .를 넣으면 깨지는 현상이 있음
// 유니티에서는 열로 능력치 행으로 직업,몬스터 등을 넣어서 구별하는데 이때는
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
// 이런식으로 사용할 수 있지만 우리는 사용하지 않을거임

// 우리는 이렇게 사용할 거임
map<int, list<object>> Objects;
// 우리는 데이터를 서버에서 들고올수 없음 소켓을 사용해야함(c언어 자체가 굉장히 보수적임)

// 컨테이너의 결합방식은 언제든지 바뀔수있으니 한가지 방법에 집착하지말것

return 0;
}
*/

#pragma region 프로토타입 패턴의 일부분 ver.1
// 생성자 복사생성자를 사용한 프로토타입 패턴의 일부분
/*
	프로토타입 패턴의 일부분
	원본을 만들고 복사 생성하기로 사용함
	복사 생성하여 사용할수 있게 만들어주는 것이 가장 중요함
	우리가 셀수없을 정도로 많이 생성해야할때 사용함

	양식을 만들어놓는 거라고 생각하면됨
	복사생성자 = 프린터기 new 할당 = 손 정도의 속도차이가 난다고 생각하면됨
	빈번하게 사용되는 경우에 사용함 if. 몬스터 , 총알 ,아이템
*/

/*
	struct Vector3
	{
		float x, y, z;
	
		// 생성자 초기화 안하면 에러걸림
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
		// 복사 생성자(Object)를 호출 -> 호출한 복사 생성자에서 초기화해줌
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

	// 생성자 초기화 안하면 에러걸림
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
	#pragma region 2022_06_17 Map ~ AddData까지
	// map 배열 사용
	/*
	map<int, int> Numbers;
	
	// *** Key , Value : 숫자로 숫자를 찾음
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
	// 배열을 사용한다 = map를 사용한다
	*/
	
	// iterator을 사용 
	/*
	map<string, int> Numbers;
	
	Numbers["A"] = 1;
	Numbers["B"] = 2;
	Numbers["C"] = 3;
	Numbers["D"] = 4;
	Numbers["E"] = 5;
	
	// begin 시작 지점(첫 원소) end 끝 지점(마지막)
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
	
	// iter->first : 키값
	// iter->second : value값
	
	*/
	
	// 심볼릭 상수
	/*
	enum Key {AAA,BBB,CCC,DDD,EEE};
	const int Max = 10;
	
	// 배열이 정수형이면서 상수만 받을수 있다 (int , char(아스키 코드로 받아옴))
	
	int Array[Max];
	
	Key _State = AAA;
	
	cout << Array[_State] << endl;
	*/
	
	// 심볼릭 상수에서 개선된 형태가 map이다
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
	
	// map 사용
	// map<int, int > Numbers;
	
	// 데이터 관리
	/*
	Numbers[0] = 0;
	Numbers[1] = 10;
	// Numbers[2] = 20;
	Numbers[3] = 30;
	
	
	// 강제입력 방법사용시 값이 덮어씌우기 되버림
	// 기존의 데이터를 보호하지 못하기 때문에 데이터 관리가 까다롭다(못한다).
	// 기존의 데이터가 없는것이 확실할때 처음으로 넣는데 사용하지 프로그램이 실행중이거나 할때는 이렇게 넣지 않음
	// Numbers[1] = 30;
	
	// *** make_pair 은 기존 데이터를 보호함
	// Numbers.insert( make_pair(2, 200) );
	
	// 런타임 중에는 make_pair()를 사용함으로써 기존데이터를 지켜주는게 중요함
	Numbers.insert( make_pair(4, 40) );
	
	AddData(2,200);
	*/
	
	// 배열로 출력
	/*
	for (int i = 0; i < 5; ++i)
	{
		cout << Numbers[i] << endl;
	}
	*/
	
	// ** 키 값을 찾아줌 
	/*
	map<int, int >::iterator iter = Numbers.find(2);
	
	// ** 키 값이 존재하지 않을때는 Numbers.end()로 가기 때문에  if 문으로 넣어줌
	if (iter == Numbers.end())
	{
		// *** 키값이 2인 데이터가 없으면 추가
		Numbers.insert( make_pair(2, 200) );
	}
	
	// *** 키값이 2인 데이터가 있으면 변경
	iter->second = 200;
	
	// 모듈화 -> 반복되는 코딩을 줄이는것
	*/
	
	// 반복자로 출력
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

	// 출력 1
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

	// 키 값이 없을때는 키값을 생성하고 Temp에 value값을 복사해서 넣어줌
	if (iter == Objects.end())
	{
		list<Object*> Temp;
		Temp.push_back(_Object);
		Objects.insert(make_pair(_Key, Temp));
	}
	// 키 값이 있다면 value값만 넣음 
	else
		iter->second.push_back(_Object);
}


// 들어가기 전에
/*
 인스타에 #~~~ 와 같은 기능 
 #의 기본형 검색해야할 키값 1개 정보 
 다양한 사용법이 있는데 web쪽에서 더 많이씀
 사용하는 환경에 지원하는 것들에 따라서 사용법이 많이 다름
	c   :  데이터를 보관하는 형태로 많이 사용함 (싱글톤을 사용함)
	c++ :  
 게임을 하다가 껏을때 그위치와 캐릭터의 정보를 가지고있어야하는데
 온라인게임에서는 이것을 서버에 보내줘야하는데 이를 어떻게 보낼까?
 요즘은 클라이언트를 배우기 쉬워져서 개발자 개인이 하게됨
*/

// 이진트리에 대하여(완성형 이진트리, 레드블랙 트리 구조)
/*
	루트노드에 2개의 하위 노드를 가지고있음 (이진트리구조)
	우리가 사용할 것은 레드블랙 트리(완전 이진트리)
	if 1 ~ 100을 넣을려면 자리바꿈이 심해져서 비효율적인데 이때 사용하는 것이 레드블랙 트리 구조이다.
	레드블랙 트리 구조 설명

	https://blog.naver.com/shekwl24/222244067579

	레드블랙 트리 구조를 사용하는 이유
	굉장히 복잡하지만 가장 효율이 좋은 이유는 루트 노드가 고정되지 않고 더 효율적인것으로 바뀌기 때문임
	노드에 들어가는 것이 4바이트 변수만 들어가는것이 아닌 vector나 list가 들어갈수도있음

	우리가 보기편하게 이진트리 형식으로 설명하지만
	내부로 들어가면 직선으로 길게 늘어져있는 형태임
	link the rist?

	많이 사용하는 순서
	1. 왼쪽에서 오른쪽으로 가는 탐색
	2. 위에서 아래로 가는 탐색
	3. 오른쪽에서 왼쪽으로 가는 탐색
	4. 아래에서 위로 가는 탐색

	세기 어려울 정도로 많아진다면
	층을 나누고

	800번째 값을 찾을려면
	list 800번 돌아야함
	vector 찾을때까지 돌려야함

	map은 최대 10번 이하로 찾을수있음(데이터를 찾는게 빠르니까 관리하기가 쉽다.)

	해쉬테이블 트리구조(if) 경매장, 피파-이적시장)

	한번 만들기가 쉽지않다.

	push_back으로 넣어주면 노드 안에 들어감

	쇼핑몰처럼 상단에 띄우고 싶으면 list로 제일 앞에 넣어주면됨 구조상 다름
*/ 

// 수업 전달상황 2022/06/17
/*
	수업시간 절반 이상 넘어가면 결석처리
	불시점검에 없으면 부정출결 사유에 들어갈수있음 -> 받은금액의 3배를 돌려줘야함
	if 화장실갈때 말하고 가는게 좋음
	알잘딱하자
	6월 20일 1시 ~ 6시 A반
	7월 25일 이후로 3시 ~ 6시 교육으로 바뀜
	
	C++로 진행 // 아스키 아트로 만드는 포트폴리오
*/ 

// 수업 내용 2022/06/20
/*
	구인구직 실력이없으면 못함, 자신만의 방법을 고집하면안됨 
	코딩테스트? 지금도 느껴지긴해
	
	포트폴리오 -> 학원 홍보용으로 사용할수 있음.
	결석 조퇴 지각 사유 꼭 말해줘야함
	쳐내질수도있음 조심해야함 전략적으로 가야함
	자료구조
	
	c++ 의 개념 깨부하자! 
	API는 하지않음 -> 다이렉트(이미 끝물), mfc(안씀)를 하겟다 -> 의미없다!
	다이렉트 -> 기본 3D

	C++ stl c#을 이용한 유니티 2d + 3d 

	선생님이 주신 함수 그대로 사용하자
	함수 생성하는게 아니라 사용이라도 잘하자

	함수를 잘 만드는게 아니라 함수를 얼마나 잘 쓰는지가 더 중요함

	공간의 활용 -> 테트리스 

	횡스크롤 2d, 종스크롤 2d ,3d 에셋구매 돈 모아놓기 (환률)

	이력서 코딩테스트 

	2023 3월 이후로 끝날수도 있음 9개월 or 10개월 
	기초 초반 교육이 굉장히 중요함

	책 추천 할게 별로없음
	영어공부 꾸준하게 하기
*/ 