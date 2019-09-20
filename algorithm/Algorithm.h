#pragma once

#include <string>

#include <ds/Graph.h>
#include <ds/Queue.h>

using namespace std;

namespace Algorithm {
	void  backpack01(int* W, int* V, int N, int C);
	string longestPalindrome(string s);
	void DFS(Graph* G, int v);
	void BFS(Graph* G, int v, Queue<int>& Q);
}

