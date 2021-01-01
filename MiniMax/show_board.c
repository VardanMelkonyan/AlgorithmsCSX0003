void ft_putstr(char *str);
void ft_putchar(char c);

void showBoard(char state[3][3]) {
	int i;
	int j;

	i = 0;
	ft_putstr("  | 1 | 2 | 3 |\n");
	ft_putstr("--------------\n");
	while (i < 3) {
		j = 0;
		ft_putchar(i + '1');
		ft_putstr(" | ");
		while (j < 3) {
			ft_putchar(state[i][j] == '0' ? ' ' : state[i][j]);
			//if (j != 2)
				ft_putstr(" | ");
			j++;
		}
		ft_putchar('\n');
		//if (i != 2) 
			ft_putstr("--------------\n");
		i++;
	}
}
