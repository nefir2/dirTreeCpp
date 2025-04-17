#include <string>
#include <filesystem>
#include <algorithm>
#include <vector>

#include "dir_tree.h"

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

// outputs to stdout tree.
//
// throws std::invalid_argument if path is not exist.
void dirTree(std::string path, bool showFiles) {
	if (!std::filesystem::exists(path)) throw std::invalid_argument("path not exist.");
	std::filesystem::path pPath{path};
	if (showFiles) treeFiles(pPath);
	else treeDirectory(pPath);
}