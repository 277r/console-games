#include <iostream>
#define x 8
#define y 8

int fuckYou[2];

class winResult
{
public:
	bool won;
	char ID;
};

class Grid
{
public:
	char grid[y][x];
	void clearGrid()
	{
		for (int i = 0; i < y; i++)
		{
			for (int ii = 0; ii < x; ii++)
			{
				grid[i][ii] = '.';
			}
		}
	}
	void outputGrid()
	{
		for (int i = 0; i < y; i++)
		{
			for (int ii = 0; ii < x; ii++)
			{
				std::cout << grid[i][ii] << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
	bool setGridPoint(int xCoord, char character)
	{
		for (int i = y - 1; i >= 0; i--)
		{
			if (grid[i][xCoord] == '.')
			{
				grid[i][xCoord] = character;
				return true;
			}
		}
		return false;
	}
	winResult iswin()
	{
		for (int i = 0; i < y; i++)
		{
			for (int ii = 0; ii < x; ii++)
			{
				// horizontal
				if (grid[i][ii] == grid[i][(ii + 1) % x] && grid[i][(ii + 1) % x] == grid[i][(ii + 2) % x] && grid[i][(ii + 2) % x] == grid[i][(ii + 3) % x] && grid[i][ii] != '.')
				{
					return {true, grid[i][ii]};
				}
				// vertical
				else if (grid[i][ii] == grid[(i + 1) % y][ii] && grid[(i + 1) % y][ii] == grid[(i + 2) % y][ii] && grid[(i + 2) % y][ii] == grid[(i + 3) % y][ii] && grid[i][ii] != '.')
				{
					return {true, grid[i][ii]};
				}
				// diagonal 1
				else if (
					grid[i][ii] == grid[(i + 1) % y][(ii + 1) % x] &&
					grid[(i + 1) % y][(ii + 1) % x] == grid[(i + 2) % y][(ii + 2) % x] &&
					grid[(i + 2) % y][(ii + 2) % x] == grid[(i + 3) % y][(ii + 3) % x] &&
					grid[i][ii] != '.')
				{
					return {true, grid[i][ii]};
				}
				// diagonal 2
				else if (
					grid[i][ii] == grid[(i - 1) % y][(ii + 1) % x] &&
					grid[(i - 1) % y][(ii + 1) % x] == grid[(i - 2) % y][(ii + 2) % x] &&
					grid[(i - 2) % y][(ii + 2) % x] == grid[(i - 3) % y][(ii + 3) % x] &&
					grid[i][ii] != '.')
				{
					return {true, grid[i][ii]};
				}
				// diagonal 3
				/*else if (
					grid[i][ii] == grid[(i + 1) % y][(ii -1 ) % x] &&
					grid[(i + 1) % y][(ii - 1) % x] == grid[(i + 2) % y][(ii - 2) % x] &&
					grid[(i + 2) % y][(ii - 2) % x] == grid[(i + 3) % y][(ii - 3) % x] &&
					grid[i][ii] != '.')
				{
					return {true, grid[i][ii]};
				}
				// diagonal 4
				else if (
					grid[i][ii] == grid[(i + 1) % y][(ii + 1) % x] && 
					grid[(i + 1) % y][(ii + 1) % x] == grid[(i + 2) % y][(ii + 2) % x] &&
					grid[(i + 2) % y][(ii + 2) % x] == grid[(i + 3) % y][(ii + 3) % x] && 
					grid[i][ii] != '.')
				{
					return {true, grid[i][ii]};
				}
				*/
			}
		}

		return {false, '\x00'};
	}
};

int main()
{
	char playerChars[] = {'X', 'O'};
	bool playerSwitcher = true;
	int lineNum;
	Grid display;
	display.clearGrid();
	while (!display.iswin().won)
	{
		display.outputGrid();
		std::cout << "current player: " << playerChars[playerSwitcher] << '\n';
		std::cin >> lineNum;
		display.setGridPoint((lineNum -1), playerChars[playerSwitcher]);
		display.outputGrid();
		playerSwitcher = !playerSwitcher;
	}

	winResult haswin = display.iswin();

	std::cout << haswin.won << haswin.ID;
}
