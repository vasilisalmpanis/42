#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <database file>" << std::endl;
		return 1;
	}
	
	Database db(argv[1]);

	return 0;
}
