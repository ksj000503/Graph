#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int VertexCount = 6;

int AdjacencyMatrix[VertexCount][VertexCount] =
{
	{0, 1, 0, 1, 0, 0},
	{1, 0, 1, 1, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{1, 1, 0, 0, 1, 0},
	{0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0}
};

bool Visited[VertexCount] = {};

// 시작지점으로 부터 떨어진 거리 기록
int Distance[VertexCount] = {}; 

// 해당 정점의 부모를 기록
int Parent[VertexCount] = {}; 

void PrintShortestPath(int Start, int Dest)
{
	// 0->3->4->5
	if (Visited[Dest] == false)
	{
		cout << "목적지까지 이동할 수 없습니다";
		
		return;
	}
	vector<int> FastPath = {};

	int Current = Dest;

	FastPath.push_back(Current);

	while (Current != Start)
	{
		Current = Parent[Current];
		FastPath.push_back(Current);
	}

	reverse(FastPath.begin(), FastPath.end());

	for (int i  = 0; i< FastPath.size(); i++)
	{
		cout << FastPath[i];

		if (i != FastPath.size()-1)
		{
			cout << "->";
		}
	}
}

void BFS(int Start)
{
	// 예약 목록
	queue<int> VertexQueue;

	// 시작지점 예약
	VertexQueue.push(Start);

	// 방문 도장 찍기
	Visited[Start] = true;
	
	// 처음은 자기 자신이 부모
	Parent[Start] = Start;

	Distance[Start] = 0;

	// Queue가 비어있지 않다면 반복
	while (!VertexQueue.empty())
	{
		// Queue에 가장 오래예약된 놈 한놈 엿보기
		int Current = VertexQueue.front();
		
		// 엿보기만 했기에 실제로 제거
		VertexQueue.pop();

		cout << "방문 : " << Current << endl;
		cout << "부모 : " << Parent[Current] << endl;
		cout << "거리 : " << Distance[Current] << endl << endl;

		// 연결 되어 있고 방문을 하지 않은 정점 찾기
		for (int Next = 0; Next < VertexCount; Next++)
		{
			// 연결 되어 있는지
			if (AdjacencyMatrix[Current][Next] == 0)
			{
				continue;
			}

			// 이미 방문을 했는지
			if (Visited[Next] == true)
			{
				continue;
			}

			// 예약 걸기
			VertexQueue.push(Next);

			Visited[Next] = true;

			// 예약을 걸고 나서 부모 + 거리
			// 부모는 지금 현재 연결된 정점을 뒤지고 있는 정점
			Parent[Next] = Current;

			// 부모의 거리에서 1을 더한 값이 나의 값이 된다
			Distance[Next] = Distance[Current] + 1;
		}
	}
}

int main()
{
	BFS(0);

	PrintShortestPath(0, 5);
}