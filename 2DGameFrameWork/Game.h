#pragma once
#include "Image.h"
#include "Keyboard.h"
#include "Pad.h"
#include "DirectX9/audio.h"
class Game
{
public:
	struct Rota
	{
		Image image;
		MyClass::Vec2 vec2;
		MyClass::Box src;
		MyClass::Box draw;
		float r;
	}rota[16], me;

	Audio* psound;
	Audio* psound2;
	KeyBoard key;
	Pad p1;
	void Init();
	void Run();
	void Draw();
	void Fin();

};

