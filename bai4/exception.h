#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <string>
using namespace std;
class Exception {
private:
	string message;
public:
	Exception() {
		message = "";
	}
	Exception(string msg) {
		message = msg;
	}
	string getMessage() {
		return message;
	}
};
#endif