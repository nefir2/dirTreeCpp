#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>

#include "dir_tree.h"

namespace tree {
	std::string replace(std::string value, std::string from, std::string to) {
		for (std::string::iterator i = value.begin(); i != value.end(); i++) {
			size_t found = value.find(from);
			if (found == std::string::npos) break;
			
		}
	}

	void treeFiles(const std::filesystem::path path) {
		for (std::filesystem::directory_entry de : std::filesystem::recursive_directory_iterator(path)) std::cout << de << std::endl;
	}

	void treeDirectory(const std::filesystem::path path) {
		for (std::filesystem::directory_entry de : std::filesystem::recursive_directory_iterator(path)) {
			if (de.is_directory()) {
				std::filesystem::path p{de.path(), std::filesystem::path::generic_format};
				std::string outp(p.string());
				std::replace(outp.begin(), outp.end(), std::string("\\\\"), std::string("/"));
				std::cout << outp << std::endl;
			}
		}
	}

	void dirTree(const std::string path, bool showFiles) {
		if (!std::filesystem::exists(path)) throw std::invalid_argument("path not exist.");
		if (!std::filesystem::is_directory(path)) throw std::invalid_argument("path is not directory.");
		const std::filesystem::path pPath{path, std::filesystem::path::native_format};
		if (showFiles) treeFiles(pPath);
		else treeDirectory(pPath);
	}
}