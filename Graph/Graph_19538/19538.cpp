#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> list[200000 + 1];		// Adjacent list
vector<int> first;					// Fist diffusers
vector<int> visited;				// visited vector including times.

void BFS(int diff)
{
	queue<int> my_que;
	my_que.push(diff);
	while (!my_que.empty())
	{
		int tmp = my_que.front();
		my_que.pop();

		if (!list[tmp].empty())
		{
			for (auto &e : list[tmp])
			{
				if (visited[e] < 0)
				{
						my_que.push(e);
						visited[e] = visited[tmp] + 1;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		while (1)
		{
			int a;	cin >> a;
			if (a == 0)	break;
			list[i].push_back(a);
		}
	}

	visited.resize(N + 1, -1);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a;	cin >> a;
		first.push_back(a);
		visited[a] = 0;
	}

	for (auto &diff : first)
		BFS(diff);

	for (int i = 1; i <= N; i++)
		cout << visited[i] << ' ';

	/***************input test**************
	cout << "visited\n";
	for (auto &e : visited)
		cout << e << ' ';
	cout << '\n';
	cout << "adjacent list\n";
	for (int i = 1; i <= N; i++)
	{
		for (auto &e : list[i])
			cout << e << ' ';
		cout << '\n';
	}
	cout << "fisrt\n";
	for (auto &e : first)
		cout << e << ' ';
	*/
}