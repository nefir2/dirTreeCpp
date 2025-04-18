#include <iostream>
#include <cstring>
#include <string>

#include "dir_tree.h"

inline const void usageNexit(const char* const programName) noexcept {
	std::cerr << "usage: " << programName << " {path} [-f]";
	exit(-1);
}

inline const std::string checkArgs(const int argc, const char** const argv, bool &showFiles) noexcept {
	showFiles = false;
	if (argc == 2) {
		if (std::string(argv[1]).find("-h") == std::string::npos) return std::string(argv[1]);
		else {
			std::cout << "usage: " << argv[0] << " {path} [-f]\n\tpath - path to dir start;\n\tf - show files." << std::endl;
			exit(0);
		}
	}
	else if (argc == 3) {
		if (std::string(argv[2]).find("-f") == std::string::npos) usageNexit(argv[0]);
		else {
			showFiles = true;
			return std::string(argv[1]);
		}
	} 
	usageNexit(argv[0]);
}

int main(const int& argc, const char** const argv) {
	bool showFiles;
	const std::string path {checkArgs(argc, argv, showFiles)};

	try { tree::dirTree(path, showFiles); }
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return -2;
	}
	
	return 0;
}