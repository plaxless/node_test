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




































































































































































































