// # *** Map_v0.1
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