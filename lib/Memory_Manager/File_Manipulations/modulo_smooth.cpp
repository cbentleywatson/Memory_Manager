#include "../Memory_Manager.h"
int Memory_Manager::modulo_smooth(int n)
{
	// Integer math to make every piece of memory come in a 4 byte chunk
	int four = 4;
	return ((n + four) / four) * four;
}
