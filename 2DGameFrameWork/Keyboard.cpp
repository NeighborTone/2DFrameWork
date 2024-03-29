#include "Keyboard.h"

void KeyBoard::Run()
{
	DX9::in.UpDate();
}
//押している
bool KeyBoard::On(const Key& key)
{
	return DX9::in.Push((int)key);
}
//押した
bool KeyBoard::Down(const Key& key)
{
	return DX9::in.Press((int)key);
}
//入力がない
bool KeyBoard::Free(const Key& key)
{
	return DX9::in.Free((int)key);
}
//離された
bool KeyBoard::Pull(const Key& key)
{
	return DX9::in.Pull((int)key);
}