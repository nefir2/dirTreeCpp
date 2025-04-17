#include <string>
#include <vector>
#include <filesystem>

#include "dir_tree.h"

namespace tree {
	void treeFiles(std::filesystem::path path) {
		for (auto e : std::filesystem::recursive_directory_iterator(path)) {
		}
	}

	void treeDirectory(std::filesystem::path path) {
		for (auto e : std::filesystem::recursive_directory_iterator(path)) {
			if (std::filesystem::is_directory(path)) {
			}
		}
	}

	void dirTree(std::string path, bool showFiles) {
		if (!std::filesystem::exists(path)) throw std::invalid_argument("path not exist.");
		std::filesystem::path pPath{path};
		if (showFiles) treeFiles(pPath);
		else treeDirectory(pPath);
	}
}