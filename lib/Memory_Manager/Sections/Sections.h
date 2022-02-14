#include "../File_Manipulations/File_Tools.h"
class Section
{
public:
	void *memory_area;
	int section_type;
	size_t size; // Heap caps malloc uses this so we should too
	String parent_file;
	bool is_valid;
	// Methods:
	Section(String file_name, int type);
	void *get_valid_memory(size_t arg_size, int type);
	~Section();
};
