#include <vector>
#include <string>
#include <algorithm>
#include <filesystem>

#include "dir_tree.h"

namespace tree
{
	// directory_entries definitions

	directory_entries::directory_entries(std::string path, bool with_files = false) {
		this->set_path(path, with_files);
	}

	directory_entries::directory_entries(std::filesystem::path path, bool with_files = false) {
		this->set_path(path, with_files);
	}

	directory_entries::~directory_entries() noexcept {
		entries.~vector();
		delete this;
	}

	std::vector<std::filesystem::directory_entry> directory_entries::get_entries() const noexcept {
		return entries;
	}

	bool directory_entries::is_directory_empty() const noexcept {
		return entries.size() == 0;
	}

	bool directory_entries::is_path_exist() const noexcept {
		return std::filesystem::exists(this->path);
	}

	void directory_entries::set_path(std::string path, bool with_files = false) {
		this->set_path(std::filesystem::path(path), with_files);
	}

	void directory_entries::set_path(std::filesystem::path path, bool with_files = false) { // noexcept(std::filesystem::exists(path))
		this->path = path;
		for (std::filesystem::directory_entry e : std::filesystem::directory_iterator(this->path)) if (!e.is_directory() && with_files) entries.push_back(e);
		this->sort();
	}

	void directory_entries::sort() {
		std::sort(
			entries.begin(),
			entries.end(),
			[](std::filesystem::directory_entry left, std::filesystem::directory_entry right) {
				return left < right;
			}
		); //std::filesystem::path::compare
	}
}
