#include "header.hpp"

void printUsage(char *[]);
int parseCmdArgs(int, char *[]);

int main(int argc, char *argv[]){
	int code;

	if(argc < 3 || argc > 6){
		printUsage(argv);
		return 0;
	}
	
	code = parseCmdArgs(argc, argv);

	return code;
}

void printUsage(char *argv[]){
	cout <<
		"single images stitcher.\n\n" << "Usage : \n" << argv[0] << " [Flages] img1 img2\n\n"
"Flags : \n"
"	-f ( cross | dist )\n"
"	-h ( hassian value )\n"
"Example usage :\n" << argv[0] << " -f cross -h 400 img1.jpg img2.jpg\n" << endl;
}

int parseCmdArgs(int argc, char *argv[]){
	for(int i = 1;i < argc;i++){
		if( string( argv[1] ) == "-f" ){
						
		}
	}
}
