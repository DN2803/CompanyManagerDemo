#pragma once
#include <iostream>
inline void getline(char*& str, std::istream& is)
{
	char* s = nullptr;
	char c;
	int sz = 0;

	is.get(c);
	while (c != '\n') {
		char* temp = new char[sz + 2];
		for (int i = 0; i < sz; i++) {
			temp[i] = s[i];
		}
		temp[sz] = c;
		temp[sz + 1] = '\0';
		delete[]s;
		s = temp;
		++sz;
		is.get(c);
	}
	str = s;
}
inline void getline(char*& str, std::istream& is, char skip)
{
	char* s = nullptr;
	char c;
	int sz = 0;

	is.get(c);
	while (c != '\n' && c != skip) {
		char* temp = new char[sz + 2];
		for (int i = 0; i < sz; i++) {
			temp[i] = s[i];
		}
		temp[sz] = c;
		temp[sz + 1] = '\0';
		delete[]s;
		s = temp;
		++sz;
		if (!is.get(c)) break;
	}
	str = s;

}
inline void strcpy(char*& dest, int size, const char* src)
{
	dest = new char[size + 1];
	for (int i = 0; i < size; i++) {
		dest[i] = src[i];
	}
	dest[size] = '\0';
}
inline bool isfivenumber(char* str)
{
	if (strlen(str) > 5) return false;
	for (int i = 0; i < 5; i++) {
		if (str[i] > '9' || str[i] < '0') return false;
	}
	return true;
}