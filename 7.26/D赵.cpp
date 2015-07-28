#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

map<vector<pair<int, int> >, bool> hsh;
queue<vector<pair<int, int> > > que; 
int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0, 1,-1};
char buf[20][20];
inline pair<int, int> find(char ch) {
	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < 8; ++j) {
			if(buf[i][j] == ch)
				return make_pair(i, j);
		}
	}
}
inline void init() {
	hsh.clear();
	while(!que.empty())
		que.pop();
}
int dir;
inline bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return dx[dir] * a.first + dy[dir] * a.second > dx[dir] * b.first + dy[dir] * b.second;
}
inline bool check(pair<int, int> sta, int num, const vector<pair<int, int> > lst) {
	if(sta.first < 0 || sta.first >= 8 || sta.second < 0 || sta.second >= 8)
		return false;
	if(buf[sta.first][sta.second] == '#')
		return false;
	for(int i = 0; i < 4; ++i) {
		if(i != num) {
			if(sta.first >= lst[i].first && sta.first < lst[i].first + 2 
			   && sta.second >= lst[i].second && sta.second < lst[i].second + 2)
				return false;
		}
	}
	return true;
}
inline bool judge(pair<int, int> sta, int num, const vector<pair<int, int> > lst) {
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			if(!check(make_pair(sta.first + i, sta.second + j), num, lst))
				return false;
		}
	}
	return true;
}
inline vector<pair<int, int> >move(vector<pair<int, int> > sta, int cur) {
	vector<pair<int, int> > tmp = sta;
	dir = cur;
	sort(tmp.begin(), tmp.end(), cmp);
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			if(tmp[i] == sta[j]) {
				while(judge(make_pair(sta[j].first + dx[cur], sta[j].second + dy[cur]), j,sta))
					sta[j] = make_pair(sta[j].first + dx[cur], sta[j].second + dy[cur]);
			}
		}
	}
	return sta;
}
int main() {
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		init();
		for(int i = 0; i < 8; ++i) {
			scanf("%s", buf[i]);
		}
		vector<pair<int, int> > sta;
		for(int i = 0; i < 4; ++i) {
			sta.push_back(find('A' + i));
		}
		que.push(sta);
		while(!que.empty()) {
			vector<pair<int, int> > sta = que.front();
			que.pop();
			for(int i = 0; i < 4; ++i) {
				vector<pair<int, int> > to = move(sta, i);
				if(hsh.find(to) == hsh.end()) {
					hsh[to] = true;
					que.push(to);
				}
			}	
		}
		printf("Case %d: %d\n",cas, (int)hsh.size());
	}
	return 0;
}
