#include <iostream>
#include <vector>

using namespace std;
static vector <int> index;
void uni(int a, int b);
int find(int a);
static int real_count;
static vector<int> real;
static vector<vector<int>> party;
bool check(int a);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int people_count, party_count;
	int count = 0;
	cin >> people_count >> party_count;
	index = vector<int>(people_count + 1);
	
	for(int i = 1; i <= people_count; i++){
		index[i] = i;
	}
	
	cin >> real_count;
	real = vector<int> (real_count + 1, 1);
	for(int i = 1; i <= real_count; i++){
		cin >> real[i];
	}
	
	party.resize(party_count,vector<int>(people_count + 1));
	
	for(int i = 0; i < party_count; i++){
		cin >> party[i][0];
		for(int j = 1; j <= party[i][0]; j++){
			cin >> party[i][j];
			if(j >= 2) uni(party[i][j-1],party[i][j]);
		}
	}
	
	for(int i = 0; i < party_count; i++){
		bool lie = true;
		for(int j = 1; j <= party[i][0]; j++){
			if(!check(party[i][j])) lie = false;
		}
		if(lie) count++;
	}
	
	cout << count << "\n";
	
	return 0;
}

bool check(int a){
	a = find(a);
	for(int i : real){
		i = find(i);
		if(a == i) return false;
	}
	index[a] = index[real[0]];
	return true;
}

void uni(int a, int b){
	a = find(a);
	b = find(b);
	if(a!=b) index[b] = a;
}

int find(int a){
	if(index[a] == a) return a;
	else{
		return index[a] = find(index[a]);
	}
}




































































































































































































/*(23.3 말쯤?)
1. 인간관계
 1) 솔직히 도움이 될만한 사람만 남기고 싶음
  <확실히 전역하고 남을 친구들> -> 챙길 사람들 (여기서 멀어지면 답 없음)
  - 김보혜
  - 강민구
  - 최민혁
  - 김형민
  - 윤준희
  
  <친해지기도, 잊기도 애매한 사람들> -> 나한테 먼저 친해지고 싶어 하는 사람만
  - 이하람
  - 김수민
  - 설가영
  - 김서희
  - 김나윤
  - 양가은
  - 이진서
  - 장능관
  - 심명서
  - 장영환
  - 이세연
  - 김수윤
  - 박지민
  
 2) 군대 내에서 인간관계
  조용히 지내고 싶음.
  그게 힘들다..
  
2. 군대 내 학습생활
 1) 토익
  - 보통 RC는 당직, LC는 개인정비시간에
 2) 학교 강의
  - 연등 때, 즉각대기땐 개인정비시간
 3) 현대 강의
  - 개인정비시간
 4) 알고리즘 코딩
  - 연등 때
 5) 쉐도잉
  - 주말, 개인정비 시간에 끌릴 때
 6) 책
  - 당직, 주말 근무

3. 휴가 계획(50일 예정)
 1) 22.11(5), 23.2(8), 23.6(8), 23.11(8), 24.1(21)
 2) 22.11(5), 23.2(8), 23.7(8), 23.11(8), 24.1(21)
 3) 22.11(5), 23.2(8), 23.6(8), 23.9(8), 23.12(8), 24.1(13)
 4) 22.11(5), 23.2(8), 23.7(8), 24.1(29)
 5) 22.11(5), 23.2(8), 23.5(8), 23.8(8), 23.11(8), 24.1(13)
 6) 22.11(5), 23.2(8), 23.5(4), 23.7(8), 23.9(4), 23.11(8), 24.1(13)
 <새로은 방안 적어주시길>
 결국 이렇게 결정됨(23.05.26) - 49일로 계산(최솟값)
 22.11(5), 23.2(8), 23.8(11), 23.11(5) <20left> - 솔직히 말출 22일 이상 필요 없음
 외박 점프 한다는 가정 하에
 6월 외박 7월 외출
 8월까지만 버티면 9월 외박 10월 외박 11월/12월 휴가 1월 말출 하면 됨 
 매달 밖에서 술 먹을 수 있다는 뜻!
 
 ?) 왜 8일 이상 안나가나?
  - 어짜피 길게 나가도 더 많은 사람들을 보기에는 한계가 있다. 8일도 충분히 길어서..
  - 일단 최대한 버티는게 이득..ㅋ
  
  
  */