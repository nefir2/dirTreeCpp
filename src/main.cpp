#include <iostream>
#include "dir_tree.h"

void usageNexit(char* programName) noexcept {
	std::cerr << "usage: " << programName << " {path} [-f]";
	exit(-1);
}

std::string checkArgs(int argc, char** argv, bool &showFiles) noexcept {
	showFiles = false;
	if (argc < 2 || argc > 3) usageNexit(argv[0]);
	else if (argc == 2) {
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

int main(int argc, char** argv) {
	std::cout << std::flush;
	bool showFiles;
	std::string path {checkArgs(argc, argv, showFiles)};
	
	try { tree::dirTree(path, showFiles); }
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return -2;
	}
	
	return 0;
}