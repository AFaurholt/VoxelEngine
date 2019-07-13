// VoxelEngine.cpp : Defines the entry point for the application.
//

#include "VoxelEngine.h"
#include "src/AddNum.h"
#include <string>

using namespace std;

int main()
{
	int tmp = add(1, 4);
	std::string outStr = "Hello CMake." + std::to_string(tmp);
	cout << outStr << endl;
	return 0;
}
