#pragma once

#include <Windows.h>
#include <string>

class cButton
{
private: 
	const UINT buttonID;
	const std::wstring buttonName;
	const std::wstring buttonClassName;

public:
	cButton();


private:
	int buttonHigth;
	int buttonWidth;
	int buttonX;
	int buttonY;
};

