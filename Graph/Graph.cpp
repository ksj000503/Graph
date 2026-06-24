#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int Width, Height, CabbageCount;

const int MaxFarmSize = 11;

int Farm[MaxFarmSize][MaxFarmSize];

bool Visited[MaxFarmSize][MaxFarmSize];

int Count = 0;

void MakeMap()
{
	scanf("%d %d %d", &Width, &Height, &CabbageCount);

	for (int i = 0; i < CabbageCount; i++)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		Farm[y + 1][x + 1] = 1;
	}
}

void DFS(int X, int Y)
{
	const int DirectionY[4] = { -1, 1, 0, 0 };

	const int DirectionX[4] = { 0, 0, -1, 1 };

	Visited[Y][X] = true;

	for (int dir = 0; dir < 4; ++dir)
	{
		int NextY = Y + DirectionY[dir];

		int NextX = X + DirectionX[dir];

		if (NextY < 1 || NextY > Height || NextX < 1 || NextX > Width)
			continue;

		if (Farm[NextY][NextX] == 0)
			continue;

		if (Visited[NextY][NextX] == true)
			continue;

		DFS(NextX, NextY);
	}
}

void FindDFS()
{
	for (int FarmY = 0; FarmY < Height; FarmY++)
	{
		for (int FarmX = 0; FarmX < Width; FarmX++)
		{
			if (Farm[FarmY][FarmX] == 1 && Visited[FarmY][FarmX] == false)
			{
				DFS(FarmX, FarmY);

				Count++;
			}
		}
	}
}

int main()
{
	MakeMap();

	FindDFS();

	cout << Count << endl;;
}
