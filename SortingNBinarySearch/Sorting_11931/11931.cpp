#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000
int arr[MAX], N;

bool compare(int x, int y)
{
	return x > y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N, compare);

	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';
}