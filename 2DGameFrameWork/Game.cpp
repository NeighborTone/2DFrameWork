#include "Game.h"
void Game::Init()
{
	for (int i = 0; i < 16; ++i)
	{
		rota[i].image.Load("ƒJ[ƒ\ƒ‹.png");
		rota[i].vec2 = { 0 + (float)i * 80, 200 };
		rota[i].r = 0;
	}
}
void Game::Run()
{
	for (int i = 0; i < 16; ++i)
	{
		rota[i].r -= 1;
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
}
void Game::Fin()
{

}