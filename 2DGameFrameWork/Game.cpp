#include "Game.h"
using namespace MyClass;

//GameLogic
void Cursur::Move(KeyBoard& key)
{
	
	if (key.Down(KeyBoard::Key::KEY_RIGHT))
	{
		CURSOR_RIGHT_MAX
		{
			pos.x += 42;
		}
		
	}
	if (key.Down(KeyBoard::Key::KEY_LEFT))
	{
		CURSOR_LEFT_MAX
		{
			pos.x -= 42;
		}
		
	}
	if (key.Down(KeyBoard::Key::KEY_DOWN))
	{
		CURSOR_DOWN_MAX
		{
			pos.y += 74;
		}
		
	}
	if (key.Down(KeyBoard::Key::KEY_UP))
	{
		CURSOR_UP_MAX
		pos.y -= 74;
	}
}






//GameControl
bool Game::Initialize()
{
	cursor.image.Load("image/cursor.png");
	back.image.Load("image/back.jpg");
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 6; ++x)
		{
			field[y][x].pos = { static_cast<float>((90 + CARDSIZE_W * x) +10 *x), 
									   static_cast<float>((10 + CARDSIZE_H * y)    +10 *y) };
			field[y][x].image.Load("image/cursor.png");

			card[y][x].pos = { static_cast<float>((90 + CARDSIZE_W * x) + 10 * x),
										static_cast<float>((10 + CARDSIZE_H * y) + 10 * y) };
			card[y][x].state = Card::STATE::NONE;
		}
	}
	
	cursor.pos = {90,10};
	return true;
}
void Game::Update()
{
	key.Run();
	cursor.Move(key);


}
void Game::Draw()
{
	
	back.image.Draw(back.pos,GetColor(255,0,255));
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 6; ++x)
		{
			field[y][x].image.Draw(field[y][x].pos);
		}
	}

	cursor.image.Draw(cursor.pos, GetColor(55, 225, 255));
}
void Game::Finalize()
{
	
}

