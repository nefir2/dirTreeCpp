#include <iostream>
#include <string>
#include <algorithm>
#include <filesystem>

#include "dir_tree.h"

namespace tree {
	inline void dirTree(const std::string path, bool showFiles) {
		if (!std::filesystem::exists(path)) throw std::invalid_argument("path not exist.");
		if (!std::filesystem::is_directory(path)) throw std::invalid_argument("path is not directory.");
		const std::filesystem::path pPath{path};
		tree::directory_entries des{path};

		for (auto e : des.get_entries()) {
			
		}

		for (std::filesystem::directory_entry de : std::filesystem::recursive_directory_iterator(path)) {
			std::string outp {de.path().string()};
			std::replace(outp.begin(), outp.end(), '\\', '/');
			if (de.is_directory()) std::cout << outp << std::endl;
			else if (showFiles) std::cout << outp << " (" << de.file_size() << "b)" << std::endl;
		}
	}
}