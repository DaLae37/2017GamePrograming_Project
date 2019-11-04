﻿//#include <stdio.h> 
//#include <Windows.h>
//
//
//HANDLE COUT = 0;    // 콘솔 출력 장치
//HANDLE CIN = 0;        // 콘솔 입력 장치
//
//int be_input()
//{
//	INPUT_RECORD input_record;
//	DWORD input_count;
//
//	PeekConsoleInput(CIN, &input_record, 1, &input_count);
//	return input_count;
//}
//
//int get_input(WORD *vkey, COORD *pos)
//{
//	INPUT_RECORD input_record;
//	DWORD input_count;
//
//	ReadConsoleInput(CIN, &input_record, 1, &input_count);
//	switch (input_record.EventType) {
//	case MOUSE_EVENT:
//		if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
//			CONSOLE_SCREEN_BUFFER_INFO csbi;
//
//			GetConsoleScreenBufferInfo(COUT, &csbi);
//
//			*pos = input_record.Event.MouseEvent.dwMousePosition;
//			pos->X -= csbi.srWindow.Left;
//			pos->Y -= csbi.srWindow.Top;
//
//			return MOUSE_EVENT;
//		}
//		break;
//
//	}
//
//	//    FlushConsoleInputBuffer(CIN);
//	return 0;
//}
//
//void gotoxy(int x, int y)      // 좌표 보내기 gotoxy
//{
//	COORD Cur;
//	Cur.X = x;
//	Cur.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
//}
//
//void reset(int x, int y) {
//
//}
//void main()
//{
//	DWORD mode;
//	WORD key;
//	COORD pos;
//
//	int event;        // 마우스 이벤트에 이용
//	int x;            // 마우스의 x좌표 저장소
//	int y;            // 마우스의 y좌표 저장소
//
//	CIN = GetStdHandle(STD_INPUT_HANDLE);
//	COUT = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	// 마우스 활성화
//	GetConsoleMode(CIN, &mode);
//	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
//
//	while (1)
//	{
//		if (be_input())
//		{
//			if (get_input(&key, &pos) != 0)
//			{
//				MOUSE_EVENT;
//				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
//				y = pos.Y;
//				gotoxy(x, y);
//				printf("*");
//			}
//		}
//	}
//}

#include<Windows.h>
#include<stdio.h>
 
INPUT_RECORD rec;
DWORD        dwNOER;
 
void CheckMouse()
{
    while (true)
    {
        ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임.
        if (rec.EventType == MOUSE_EVENT) // 마우스 이벤트일 경우
        {
            if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // 좌측 버튼이 클릭되었을 경우
            {
                int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
                int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴
                COORD Coor = { 0, 0 };
                DWORD dw;
                FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 80 * 25, Coor, &dw); // 콘솔창 화면을 지운다.
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor); // 커서를 0, 0으로 이동시킨다.
                printf("%d, %d", mouse_x, mouse_y); // 좌표를 출력한다.
                return;
            }
        }
    }
}
 
void main()
{
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
    while (true)
    {
        CheckMouse();
    }
}