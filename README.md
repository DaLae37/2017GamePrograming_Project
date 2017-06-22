# Amazing Checks

A simple console-based chess game on C++

### Main screen ascii art
```
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

void print(string str) {
	cout << str << endl;
}

int main(){
	system("mode con:cols=120 lines=32");
	// this reads "amazing checks"                                                   
	print("                                                 _/                      ");
	print("    _/_/_/  _/_/_/  _/_/      _/_/_/  _/_/_/_/      _/_/_/      _/_/_/   ");
	print(" _/    _/  _/    _/    _/  _/    _/      _/    _/  _/    _/  _/    _/    ");
	print("_/    _/  _/    _/    _/  _/    _/    _/      _/  _/    _/  _/    _/     ");
	print(" _/_/_/  _/    _/    _/    _/_/_/  _/_/_/_/  _/  _/    _/    _/_/_/      ");
	print("             _/                            _/                   _/       ");
	print("    _/_/_/  _/_/_/      _/_/      _/_/_/  _/  _/      _/_/_//_/          ");
	print(" _/        _/    _/  _/_/_/_/  _/        _/_/      _/_/                  ");
	print("_/        _/    _/  _/        _/        _/  _/        _/_/               ");
	print(" _/_/_/  _/    _/    _/_/_/    _/_/_/  _/    _/  _/_/_/                  ");

	return 0;
}
```
