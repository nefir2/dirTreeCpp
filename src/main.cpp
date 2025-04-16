#include <iostream>

void usageNexit(char* programName) {
	std::cerr << "usage: " << programName << " {path} [-f]";
	exit(-1);
}

std::string checkArgs(int argc, char** argv, bool &showFiles) {
	showFiles = false;
	if (argc < 2 || argc > 3) usageNexit(argv[0]);
	else if (argc == 2) {
		if (std::string(argv[1]).find("-h")) {
			std::cout << "usage: " << argv[0] << " {path} [-f]\n\tpath - path to dir start;\n\tf - show files." << std::endl;
			exit(0);
		}
		else return std::string(argv[1]);
	}
	else if (argc == 3) {
		if (std::string(argv[2]).find("-f")) {
			showFiles = true;
			return std::string(argv[1]);
		}
		else usageNexit(argv[0]);
	} 
}

int main(int argc, char** argv) {
	bool showFiles;
	std::string path {checkArgs(argc, argv, showFiles)};
	dirTree(path, showFiles);
	return 0;
}