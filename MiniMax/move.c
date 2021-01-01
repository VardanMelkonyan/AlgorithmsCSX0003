void updateWinTable(int i, int j, int winTable[3][3], int turn);

int move(char move[3], int turn, char state[3][3], int winTable[3][3]) {
	char player;
	int i;
	int j;

	player = turn ? 'O' : 'X';
	i = move[0] - '0' - 1;
	j = move[1] - '0' - 1;
	updateWinTable(i, j, winTable, turn);
	if (state[i][j] == '0') {
		state[i][j] = player;
		return (1);
	} else { 
		return (0);
	}
}

void updateWinTable(int i, int j, int winTable[3][3], int turn) {
	if (i == 0 && j == 0) {
		turn ? winTable[0][0]++ : winTable[0][0]--;
		turn ? winTable[1][0]++ : winTable[1][0]--;
		turn ? winTable[2][0]++ : winTable[2][0]--;
	}
	else if (i == 0 && j == 1) {
		turn ? winTable[0][0]++ : winTable[0][0]--;
		turn ? winTable[1][1]++ : winTable[1][1]--;
	}
	else if (i == 0 && j == 2) {
		turn ? winTable[0][0]++ : winTable[0][0]--;
		turn ? winTable[1][2]++ : winTable[1][2]--;
		turn ? winTable[2][1]++ : winTable[2][1]--;
	}
	else if (i == 1 && j == 0) {
		turn ? winTable[0][1]++ : winTable[0][1]--;
		turn ? winTable[1][0]++ : winTable[1][0]--;
	}
	else if (i == 1 && j == 1) {
		turn ? winTable[0][1]++ : winTable[0][1]--;
		turn ? winTable[1][1]++ : winTable[1][1]--;
		turn ? winTable[2][0]++ : winTable[2][0]--;
		turn ? winTable[2][1]++ : winTable[2][1]--;
	}
	else if (i == 1 && j == 2) {
		turn ? winTable[0][2]++ : winTable[0][2]--;
		turn ? winTable[1][2]++ : winTable[1][2]--;
	}
	else if (i == 2 && j == 0) {
		turn ? winTable[0][2]++ : winTable[0][2]--;
		turn ? winTable[1][0]++ : winTable[1][0]--;
		turn ? winTable[2][1]++ : winTable[2][1]--;
	}
	else if (i == 2 && j == 1) {
		turn ? winTable[0][2]++ : winTable[0][2]--;
		turn ? winTable[1][1]++ : winTable[1][1]--;
	}
	else if (i == 2 && j == 2) {
		turn ? winTable[0][2]++ : winTable[0][2]--;
		turn ? winTable[1][2]++ : winTable[1][2]--;
		turn ? winTable[2][0]++ : winTable[2][0]--;
	}

}
