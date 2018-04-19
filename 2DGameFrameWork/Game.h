#pragma once
#include "Image.h"
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
	}rota[16];
	
	void Init();
	void Run();
	void Draw();
	void Fin();

};
