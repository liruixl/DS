#include "Algorithm.h"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

namespace Algorithm {
	void  backpack01(int* W, int* V, int N, int C)
	{

		using Arr2Dim = std::vector<std::vector<int>>;

		//error W is a pointer here
		/*std::cout << sizeof(W) << std::endl;
		std::cout << sizeof(W[0]) << std::endl;

		int N = sizeof(W) / sizeof(W[0]);*/

		Arr2Dim dp(N, std::vector<int>(C+1,0));

		//第0个物品,动态规划初始状态
		for (int i = 0; i <= C; ++i)
		{
			dp[0][i] = (W[0] <= i) ? V[0] : 0;
		}
		

		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j <= C; ++j)
			{
				if (j >= W[i]) //here dont forget
				{
					dp[i][j] = std::max(dp[i - 1][j],
						V[i] + dp[i - 1][j - W[i]]);
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}

		int maxvalue = dp[N - 1][C];

		std::cout << "the max value:" << maxvalue << std::endl;

	}


	std::string longestPalindrome(std::string s) {

		int len = s.size();

		int dp[10][10];
		int maxlen = 1;
		int start = 0;

		for (int i = 0; i < len; ++i)
		{
			dp[i][i] = 1;
			if (i + 1 < len && s[i] == s[i + 1])
			{
				dp[i][i + 1] = 1;
				if (maxlen < 2)
				{
					maxlen = 2;
					start = i;
				}
			}
		}


		for (int C = 2; C < len; ++C)
		{
			for (int i = 0; i < len; ++i)
			{
				if (i + C < len)
				{
					if (s[i] == s[i + C])
					{

						if (dp[i + 1][i + C - 1] == 1)
						{
							dp[i][i + C] = 1;
							if (maxlen < C + 1)
							{
								maxlen = C + 1;
								start = i;
							}
						}

					}

				}
			}
		}

		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		return s.substr(start, maxlen);
	}

	void DFS(Graph* G, int v)
	{
		//Previsit(G, v);
		std::cout << v << " ";
		G->setMark(v, 1);

		for (int w = G->first(v); w < G->n(); w = G->next(v, w))
		{
			if(G->getMark(w) == 0)
				DFS(G, w);
		}
		//Postvisit(G, v);
	}
	void BFS(Graph * G, int start, Queue<int>& Q)
	{
		int v;

		Q.push(start);
		G->setMark(start, 1);

		while (!Q.empty())
		{
			Q.front(v);
			Q.pop();

			std::cout << v << " ";

			//Postvisit(G, v);

			for (int i = G->first(v); i < G->n(); i = G->next(v, i))
			{
				if (G->getMark(i) == 0)
				{
					Q.push(i);
					G->setMark(i, 1);
				}
			
			}

			//Postvisit(G, v);

		}
	}
}

