#include "Keyboard.h"

void KeyBoard::Run()
{
	DX9::in.UpDate();
}
//�����Ă���
bool KeyBoard::On(const Key& key)
{
	return DX9::in.Push((int)key);
}
//������
bool KeyBoard::Down(const Key& key)
{
	return DX9::in.Press((int)key);
}
//���͂��Ȃ�
bool KeyBoard::Free(const Key& key)
{
	return DX9::in.Free((int)key);
}
//�����ꂽ
bool KeyBoard::Pull(const Key& key)
{
	return DX9::in.Pull((int)key);
}