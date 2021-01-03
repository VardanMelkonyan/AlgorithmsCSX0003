#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Move {
	int row, col;
};

char player = 'X', opponent = 'O';

bool isMovesLeft(char board[3][3])
{
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
			if (board[i][j]=='0')
				return true;
	return false;
}

int min(int n1, int n2) {
  if (n1 < n2) return n1;
  else return n2;
}

int max(int n1, int n2) {
  if (n1 > n2) return n1;
  else return n2;
}

int evaluate(char b[3][3])
{
	for (int col = 0; col<3; col++)
	{
		if (b[0][col]==b[1][col] &&
			b[1][col]==b[2][col])
		{
			if (b[0][col]==player)
				return +10;
	
			else if (b[0][col]==opponent)
				return -10;
		}
	}

	if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
	{
		if (b[0][0]==player)
			return +10;
		else if (b[0][0]==opponent)
			return -10;
	}

	if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
	{
		if (b[0][2]==player)
			return +10;
		else if (b[0][2]==opponent)
			return -10;
	}

	return 0;
}

int minimax(char board[3][3], int depth, bool isMax)
{
	int score = evaluate(board);

	if (score == 10)
		return score;

	if (score == -10)
		return score;

	if (isMovesLeft(board)==false)
		return 0;

	if (isMax)
	{
		int best = -1000;

		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				if (board[i][j]=='0')
				{
					board[i][j] = player;
					best = max( best,
						minimax(board, depth+1, !isMax) );
					board[i][j] = '0';
				}
			}
		}
		return best;
	}

	else
	{
		int best = 1000;
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				if (board[i][j]=='0')
				{
					board[i][j] = opponent;
					best = min(best,
						minimax(board, depth+1, !isMax));
					board[i][j] = '0';
				}
			}
		}
		return best;
	}
}

char *findBestMove(char board[3][3])
{
	int bestVal = -1000;
	char *bestMove = malloc(sizeof(char) * 3);
	bestMove[0] = -1;
	bestMove[1] = -1;

	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (board[i][j]=='0')
			{
				board[i][j] = player;
				int moveVal = minimax(board, 0, false);
				board[i][j] = '0';
				if (moveVal > bestVal)
				{
					bestMove[0] = i + '0' + 1;
					bestMove[1] = j + '0' + 1;
					bestMove[2] = '\0';
					bestVal = moveVal;
				}
			}
		}
	}
	return bestMove;
}

