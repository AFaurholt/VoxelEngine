// VoxelEngine.cpp : Defines the entry point for the application.
//

#include "VoxelEngine.h"
#include "src/AddNum.h"
#include "ProjectConfig.h"
#include <string>

using namespace std;

int main()
{
	int tmp = add(1, 4);
	std::string outStr = "Hello CMake." + std::to_string(tmp);
	cout << outStr << endl;
	fprintf(stdout, "Version %d.%d.%d.%d\n",
		VoxelEngine_VERSION_MAJOR,
		VoxelEngine_VERSION_MINOR,
		VoxelEngine_VERSION_PATCH,
		VoxelEngine_VERSION_TWEAK);
	return 0;
}
