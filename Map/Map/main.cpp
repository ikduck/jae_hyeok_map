// *** Map_v0.2
#include <iostream>
#include <string>
#include <map>

using namespace std;



// 100 10 10 100 50 띄워쓰기를 이용하여 잘라야하는 곳에 구별을줌 (싱글톤 패턴을 사용함)
// csb파일 -> .를 넣으면 깨지는 현상이 있음
// 유니티에서는 열로 능력치 행으로 직업,몬스터 등을 넣어서 구별하는데 이때는
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
// 이런식으로 사용할 수 있지만 우리는 사용하지 않을거임

// 우리는 이렇게 사용할 거임
// 우리는 데이터를 서버에서 들고올수 없음 소켓을 사용해야함(c언어 자체가 굉장히 보수적임)
map<int, list<object>> Objects;

// 컨테이너의 결합방식은 언제든지 바뀔수있으니 한가지 방법에 집착하지말것

return 0;
}
*/

int main(void)
{
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

	// 루트노드에 2개의 하위 노드를 가지고있음 (이진트리구조)
	// 우리가 사용할 것은 레드블랙 트리(완전 이진트리)
	// if 1 ~ 100을 넣을려면 자리바꿈이 심해져서 비효율적인데 이때 사용하는 것이 레드블랙 트리 구조이다.
	// 레드블랙 트리 구조 설명
	/*
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

	// map 사용
	map<int, int > Numbers;

	
	Numbers[0] = 0;
	Numbers[1] = 10;
	// Numbers[2] = 20;
	Numbers[3] = 30;

	// 강제입력 방법사용시 값이 덮어씌우기 되버림
	// 기존의 데이터를 보호하지 못하기 때문에 데이터 관리가 까다롭다(못한다).
	// 기존의 데이터가 없는것이 확실할때 처음으로 넣는데 사용하지 프로그램이 실행중이거나 할때는 이렇게 넣지 않음
	// Numbers[1] = 30;

	// 런타임 중에는 make_pair()를 사용함으로써 기존데이터를 지켜주는게 중요함
	Numbers.insert( make_pair(4, 40) );
	
	// *** make_pair 은 기존 데이터를 보호함
	// Numbers.insert( make_pair(2, 200) );
	
	// ** 키 값을 찾아줌 
	map<int, int >::iterator iter = Numbers.find(2);

	// ** 키 값이 존재하지 않을때는 Numbers.end()로 가기 때문에  if 문으로 넣어줌
	if (iter == Numbers.end())
	{
		// *** 키값이 2인 데이터가 없으면 추가
		Numbers.insert( make_pair(2, 200) );
	}

	// *** 키값이 2인 데이터가 있으면 변경
	iter->second = 200;

	// 배열로 출력
	/*
	for (int i = 0; i < 5; ++i)
	{
		cout << Numbers[i] << endl;
	}
	*/

	// 반복자로 출력
	for (map<int, int >::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter)
	{
		cout << iter->second << endl;
	}

	// 모듈화 -> 반복되는 코딩을 줄이는것
	return 0;
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

// 수업시간 절반 이상 넘어가면 결석처리
// 불시점검에 없으면 부정출결 사유에 들어갈수있음 -> 받은금액의 3배를 돌려줘야함
// if 화장실갈때 말하고 가는게 좋음
// 알잘딱하자