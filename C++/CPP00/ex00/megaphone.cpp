#include "iostream"

int main(int argc, char **argv)
{
	int	i;
	int j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			argv[i][j] = toupper(argv[i][j]);
			std::cout << argv[i][j];
		}
	}
	std::cout << "\n";
	return (0);
}