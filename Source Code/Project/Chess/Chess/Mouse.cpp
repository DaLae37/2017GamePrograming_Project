#include "Mouse.h"

Mouse::Mouse()
{
}


Mouse::~Mouse()
{
}

pair<int, int> Mouse::CheckMouse()
{
	INPUT_RECORD rec;
	DWORD        dwNOER;
	pair<int, int> pos;
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임.
	if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // 좌측 버튼이 클릭되었을 경우
	{
		int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
		int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴
		COORD Coor = { 0, 0 };
		DWORD dw;
		pos = make_pair(mouse_x, mouse_y);
		return pos;
	}
}