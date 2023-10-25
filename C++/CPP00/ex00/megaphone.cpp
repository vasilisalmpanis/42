#include "iostream"

int main(int argc, char **argv)
{
	int	i;
	int j;
	std::string temp;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 0;
	while (argv[++i])
	{
		j = -1;
		temp = argv[i];
		while (argv[i][++j])
		{
			temp[j] = toupper(temp[j]);
		}
		std::cout << temp;
	}
	std::cout << "\n";
	return (0);
}
