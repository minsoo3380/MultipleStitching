#include "H_single_stc.hpp"

void exit_program(int error_code) {
	switch (error_code) {
	case 1 :
		cout << "image load failed!!\nno search image file" << endl;
		exit(1);
		break;
	}
}