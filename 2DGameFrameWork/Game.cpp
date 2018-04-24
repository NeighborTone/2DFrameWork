#include "Game.h"

void Game::Init()
{
	for (int i = 0; i < 16; ++i)
	{
		rota[i].image.Load("カーソル.png");
		rota[i].vec2 = { 0 + (float)i * 80, 200 };
		rota[i].r = 0;
	}
	

	me.image.Load("カーソル.png");
	me.vec2 = { 0,0 };
}
void Game::Run()
{
	key.Run();
	p1.Run();
	for (int i = 0; i < 16; ++i)
	{
		rota[i].r -= 1;
	}

	if (key.On(KeyBoard::Key::KEY_RIGHT)
		|| p1.StickOn(Pad::Stick::RIGHT))
	{
		me.vec2.x += 5;
	}
	if (key.On(KeyBoard::Key::KEY_LEFT)
		|| p1.StickOn(Pad::Stick::LEFT))
	{
		me.vec2.x -= 5;
	}
	if (key.On(KeyBoard::Key::KEY_UP)
		|| p1.StickOn(Pad::Stick::UP))
	{
		me.vec2.y -= 5;
	}
	if (key.On(KeyBoard::Key::KEY_DOWN)
		|| p1.StickOn(Pad::Stick::DOWN))
	{
		me.vec2.y += 5;
	}
}
void Game::Draw()
{
	for (int i = 0; i < 16; ++i)
	{
		rota[i].src = { 0,0,80,80 };
		rota[i].draw = { 40,40,80,80 };
		rota[i].image.DrawRota(rota[i].vec2, rota[i].r, rota[i].src, rota[i].draw);
	}
	me.image.Draw(me.vec2,MyClass::GetColor(255,0,255,125));
}
void Game::Fin()
{
	
}

