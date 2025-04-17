#pragma once
#include <string>
#include <vector>
#include <filesystem>

/// @brief tree lib.
namespace tree {
	/// @brief directory's entries
	class directory_entries {
	private:
		std::filesystem::path path;
		std::vector<std::filesystem::directory_entry> entries;
	public:
		/// @brief new instance of vector dir's entries.
		/// @param path path to directory, which array is needed.
		/// @param files if true, entries will collect file.
		directory_entries(std::string, bool = false);
		/// @brief new instance of vector dir's entries.
		/// @param path path to directory, which array is needed.
		/// @param files if true, entries will collect file.
		directory_entries(std::filesystem::path, bool = false);
		/// @brief destroy this instance.
		~directory_entries() noexcept;
	public:
		inline std::vector<std::filesystem::directory_entry> get_entries() const noexcept;
		/// @brief sets new path.
		/// @param path path value.
		/// @param with_files true, if need to collect directories with files.
		inline void set_path(std::string, bool = false);
		/// @brief sets new path.
		/// @param path path value.
		/// @param with_files true, if need to collect directories with files.
		inline void set_path(std::filesystem::path, bool = false);
		/// @brief checks is directory empty.
		/// @return value that tells is directory empty (true if is empty).
		inline bool is_directory_empty() const noexcept;
		/// @brief checks is constructed path is exists.
		/// @return value that tells is path exists (true if it is).
		inline bool is_path_exist() const noexcept;
		/// @brief sorts entries.
		inline void sort();
	};
	/// @brief outputs to stdout tree.
	/// @param path path from which dir start tree.
	/// @param showFiles show files if true.
	/// @exception throws std::invalid_argument if path is not exist.
	void dirTree(std::string, bool);
}

/*

├───project
│	├───file.txt (19b)
│	└───gopher.png (70372b)
├───static
│	├───a_lorem
│	│	├───dolor.txt (empty)
│	│	├───gopher.png (70372b)
│	│	└───ipsum
│	│		└───gopher.png (70372b)
│	├───css
│	│	└───body.css (28b)
│	├───empty.txt (empty)
│	├───html
│	│	└───index.html (57b)
│	├───js
│	│	└───site.js (10b)
│	└───z_lorem
│		├───dolor.txt (empty)
│		├───gopher.png (70372b)
│		└───ipsum
│			└───gopher.png (70372b)
├───zline
│	├───empty.txt (empty)
│	└───lorem
│		├───dolor.txt (empty)
│		├───gopher.png (70372b)
│		└───ipsum
│			└───gopher.png (70372b)
└───zzfile.txt (empty)

---------------------------

├───project
├───static
│	├───a_lorem
│	│	└───ipsum
│	├───css
│	├───html
│	├───js
│	└───z_lorem
│		└───ipsum
└───zline
	└───lorem
		└───ipsum

*/