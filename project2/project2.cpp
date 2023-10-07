#include <iostream>
#include <vector>
#include<stack>

using namespace std;

vector< vector<int>> graph;
vector<bool> visitedTomPath;
vector<bool> visitedJerryPath;
vector<bool> visitedTom;
vector<bool> visitedJerry;
vector<bool> visitedPath;
vector<int> path;
int tom = 0;
int jerry = 0;

void tomRecDFS(int start) {
	visitedTomPath[start] = true;
	tom++;
	for (int i = 0; i < graph[start].size(); i++) {
		if (visitedTomPath[graph[start][i]] != true and visitedJerry[graph[start][i]] != true) {
			tomRecDFS(graph[start][i]);
			
		}
	}
}

void jerryRecDFS(int start) {
	visitedJerryPath[start] = true;
	jerry++;
	for (int i = 0; i < graph[start].size(); i++) {
		if (visitedJerryPath[graph[start][i]] != true and visitedTom[graph[start][i]] != true) {
			jerryRecDFS(graph[start][i]);
		}
	}
}

void pathDFS(int start, int end) {
	visitedPath[start] = true;
	if (!path.empty()) {
		return;
	}
	for (int i = 0; i < graph[start].size(); i++) {
		if (path.empty()) {
			if (start == end) {
				path.push_back(start);
			}
			else if (visitedPath[graph[start][i]] != true) {
				pathDFS(graph[start][i], end);
			}
		}
	}
	if (!path.empty() and start!= end) {
		path.push_back(start);
	}

}

void clear() {
	tom = 0;
	jerry = 0;
	visitedTomPath.resize(0);
	visitedJerryPath.resize(0);
	visitedTom.resize(0);
	visitedJerry.resize(0);
	visitedPath.resize(0);
	path.resize(0);
}

void init() {
	int count, questions;
	cin >> count>>questions;
	graph.resize(count+1);
	
	for (int i = 0; i < count - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < questions ; i++) {
		int a, b;
		cin >> a >> b;
		visitedPath.resize(count + 1);
		pathDFS(a, b);
		visitedJerry.resize(count + 1,false);
		visitedTom.resize(count + 1, false);
		visitedJerryPath.resize(count+1, false);
		visitedTomPath.resize(count+1, false);
		for (int i = 0, ii = path.size()-1; i <= ii; i++, ii--) {
			visitedJerry[path[i]]=true;
			if (i < ii) {
				visitedTom[path[ii]] = true;
			}
		}
		jerryRecDFS(b);
		tomRecDFS(a);
		if (tom < jerry) {
			cout << "NIE";
		}
		else {
			cout << "TAK";
		}
		cout << endl;
		clear();
	}
	
}



int main() {
	ios_base::sync_with_stdio(0);
 	init();
	
	
}