#include <unistd.h>
void	print_board(int *board);

int	is_valid_pos(int *board, int col)
{
	int	i;

	i = 0;
	while (col - i > 0)
	{
		i++;
		if (board[col] == board[col - i])
			return (0);
		if (board[col] == board[col - i] - i)
			return (0);
		if (board[col] == board[col - i] + i)
			return (0);
	}
	return (1);
}

void	solver(int *board, int col, int *counter)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		board[col] = i;
		if (is_valid_pos(board, col) && col == 9)
		{
			print_board(board);
			*counter += 1;
		}
		else if (is_valid_pos(board, col))
			solver(board, col + 1, counter);
		i++;
	}
}

void	print_board(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	col;
	int	i;
	int	counter[1];

	i = -1;
	while (++i < 10)
		board[i] = 0;
	col = 0;
	counter[0] = 0;
	solver(board, col, counter);
	return (*counter);
}
