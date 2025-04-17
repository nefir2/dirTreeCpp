#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>

#include "dir_tree.h"

namespace tree {

	void treeFiles(const std::filesystem::path path) {
		for (std::filesystem::directory_entry de : std::filesystem::recursive_directory_iterator(path)) std::cout << de << std::endl;
	}

	void treeDirectory(const std::filesystem::path path) {
		for (std::filesystem::directory_entry de : std::filesystem::recursive_directory_iterator(path)) {
			if (de.is_directory()) {
				std::string outp {de.path().string()};
				//tree::replace(outp, std::string("\\"), std::string("/"));
				std::replace(outp.begin(), outp.end(), '\\', '/');
				std::cout << outp << std::endl;
			}
		}
	}

	void dirTree(const std::string path, bool showFiles) {
		if (!std::filesystem::exists(path)) throw std::invalid_argument("path not exist.");
		if (!std::filesystem::is_directory(path)) throw std::invalid_argument("path is not directory.");
		const std::filesystem::path pPath{path};
		if (showFiles) treeFiles(pPath);
		else treeDirectory(pPath);
	}
}