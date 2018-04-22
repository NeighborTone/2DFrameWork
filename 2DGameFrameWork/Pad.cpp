#include "Pad.h"

void Pad::Run()
{
	DX9::pad.UpDate();
}

bool Pad::Down(const Button& key, const NO& no)
{
	return DX9::pad.Push((int)key, (int)no);
}

bool Pad::On(const Button& key, const NO& no)
{

	return DX9::pad.Press((int)key, (int)no);
}

bool Pad::Free(const Button& key, const NO& no)
{
	return DX9::pad.Free((int)key, (int)no);
}

bool Pad::Pull(const Button& key, const NO& no)
{
	return DX9::pad.Pull((int)key, (int)no);
}

bool Pad::StickOn(const Stick& key, const NO& no)
{
	if ((BYTE)key == DX9::pad.GetPovPosition((int)no))
	{
		return true;
	}

	return false;
}
