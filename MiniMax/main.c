#include <stdio.h>
#include <stdlib.h>

void	fillBoard(char state[3][3]);
void 	fill(int mat[3][3]);
void	showBoard(char state[3][3]);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		isValidMove(char move[3]);
void	clearScreen();
int		move(char move[3], int turn, char state[3][3], int winTable[3][3]);
int		checkWinner(int winTable[3][3]);
char	*findBestMove(char board[3][3]);


int 	main(int ac, char **av) {
	char	state[3][3];
	int		turn;
	char	mv[3];
	char	*mvai;
	int		steps;
	int		winner;

	int		winTable[3][3];

	fillBoard(state);
	fill(winTable);
	turn = 0;
	steps = 0;
	
	if (ac == 2 && av[1][0] == 'm') {
		while (steps < 9) {
			clearScreen();
			showBoard(state);
			if (steps > 4) {
				winner = checkWinner(winTable);
				if (winner == 1) {
					ft_putstr("O Won!!!\n");
					return (0);
				}
				if (winner == -1) {		
					ft_putstr("X Won!!!\n");
					return (0);
				}
			}
			ft_putchar(turn ? 'O' : 'X');
			ft_putstr(" Player: ");
			scanf("%s", mv);
			if (!isValidMove(mv)) {
				ft_putstr("The inputes can only be numbers 1-3,\n");
				continue;
			}
			if (move(mv, turn, state, winTable)){
				turn = !turn;
				steps++;
			}
		}
		ft_putstr("It's a Tie!");
	} else {
		while (steps < 9) {
			clearScreen();
			mvai = findBestMove(state);
			mv[0] = mvai[0];
			mv[1] = mvai[1];
			if (move(mv, 0, state, winTable)) steps++;
			showBoard(state);
			if (steps > 4) {
				winner = checkWinner(winTable);
				if (winner == 1) {
					ft_putstr("O Won!!!\n");
					return (0);
				}
				if (winner == -1) {		
					ft_putstr("X Won!!!\n");
					return (0);
				}
			}
			
			ft_putstr("Your turn: ");
			scanf("%s", mv);
			if (!isValidMove(mv)) {
				ft_putstr("The inputes can only be numbers 1-3,\n");
				continue;
			}
			if (move(mv, 1, state, winTable)) steps++;
				
		}
	}
}
