#include <vector>
#include <string>
#include <filesystem>

#include "dir_tree.h"

namespace tree
{
	// directory_entries definitions

	directory_entries::directory_entries(std::string path) {
		this->set_path(path);
	}

	directory_entries::directory_entries(std::filesystem::path path) {
		this->set_path(path);
	}

	directory_entries::~directory_entries() {
		entries.~vector();
	}

	std::vector<std::filesystem::directory_entry> directory_entries::get_entries() {
		return entries;
	}

	bool directory_entries::is_directory_empty() {
		return entries.size() == 0;
	}

	bool directory_entries::is_path_exist() {
		return std::filesystem::exists(this->path);
	}

	void directory_entries::set_path(std::string path) {
		this->set_path(std::filesystem::path(path));
	}

	void directory_entries::set_path(std::filesystem::path path) {
		this->path = path;
		for (std::filesystem::directory_entry e : std::filesystem::directory_iterator(this->path)) entries.push_back(e);
	}
}
