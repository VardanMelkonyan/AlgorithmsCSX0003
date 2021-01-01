#include <unistd.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_putstr(char *str) {
	int i;

	i = 0;
	while(str[i] != '\0'){
		ft_putchar(str[i]);
		i++;
	}
}

void fillBoard(char state[3][3]) {
	int i;
	int j;

	i = 0;
	while (i < 3) {
		j = 0;
		while (j < 3) {
			state[i][j] = '0';
			j++;
		}
		i++;
	}
}

void fill(int mat[3][3]) {
	int i;
	int j;
	
	i = 0;
	while (i <  3) {
		j = 0;
		while (j < 3) {
			mat[i][j] = 0;
			j++;
		}
		i++;
	}
}

int isValidMove(char move[3]) {
	short int validity;

	validity = 0;
	switch (move[0]) {
		case '1':
		case '2':
		case '3':
			validity++;
			break;
		default:
			break;
	}
	switch (move[1]) {
		case '1':
		case '2':
		case '3':
			validity++;
			break;
		default:
			break;
	}
	if (validity == 2) return (1);
	else return (0);
}

void clearScreen() {
	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

int checkWinner(int winTable[3][3]) {
	int i;
	int j;

	i = 0;
	while (i < 3) {
		j = 0;
		while (j < 3) {
			if (winTable[i][j] == 3) return (1);
			else if (winTable[i][j] == -3) return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
