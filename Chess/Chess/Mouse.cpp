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
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // �ܼ�â �Է��� �޾Ƶ���.
	if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // ���� ��ư�� Ŭ���Ǿ��� ���
	{
		int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
		int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�
		COORD Coor = { 0, 0 };
		DWORD dw;
		pos = make_pair(mouse_x, mouse_y);
		return pos;
	}
}