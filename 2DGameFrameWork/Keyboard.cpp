#include "Keyboard.h"

void KeyBoard::Run()
{
	DX9::in.UpDate();
}
//‰Ÿ‚µ‚Ä‚¢‚é
bool KeyBoard::On(const Key& key)
{
	return DX9::in.Push((int)key);
}
//‰Ÿ‚µ‚½
bool KeyBoard::Down(const Key& key)
{
	return DX9::in.Press((int)key);
}
//“ü—Í‚ª‚È‚¢
bool KeyBoard::Free(const Key& key)
{
	return DX9::in.Free((int)key);
}
//—£‚³‚ê‚½
bool KeyBoard::Pull(const Key& key)
{
	return DX9::in.Pull((int)key);
}