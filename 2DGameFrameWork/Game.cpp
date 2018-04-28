#include "Game.h"
#include "Title.h"
#include <random>
#include <algorithm>

using namespace MyClass;


//GameLogic

int Game::revCnt = 0;
bool Game::isui = false;
bool  Card::flag = false;
bool  Card::flag2 = false;
Card::ID Card::preId = Card::ID::NOT;
Card::ID Card::nowId = Card::ID::NOT;


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
			pos.y += 94;
		}
		
	}
	if (key.Down(KeyBoard::Key::KEY_UP))
	{
		CURSOR_UP_MAX
		{
			pos.y -= 94;
		}
	}
}


void Card::Init(int& x, int& y)
{
	pos = { static_cast<float>((90 + Game::CARDSIZE_W * x) + 10 * x),
				static_cast<float>((10 + Game::CARDSIZE_H * y) + 30 * y) };
	state = Card::STATE::CLOSE;
	
	image.Load("image/cards.png");
}

bool Card::Select(Cursur& c, KeyBoard key)
{
	
	if (pos == c.pos && key.Down(KeyBoard::Key::KEY_Z))
	{
		if (state == Card::STATE::CLOSE)
		{
			state = Card::STATE::OPEN;
			++Game::revCnt;
			return true;
		}
		
	}
	if (Game::revCnt == 2 && key.Down(KeyBoard::Key::KEY_X) && state == Card::STATE::OPEN)
	{
		++Game::revCnt;
		return true;
	}
	return false;
}

bool Card::IsPair()
{
	
	if (Game::revCnt == 3)
	{
		Game::revCnt = 0;
		Game::isui = false;
	}


	if (Game::revCnt == 0 && state == Card::STATE::OPEN)
	{
		state = Card::STATE::CLOSE;
		flag = false;
		flag2 = false;
	}
	if (Game::revCnt == 1 && flag == false)
	{
		flag = true;
		preId = id;
	}
	if (Game::revCnt == 2 && flag2 == false)
	{
		flag2 = true;
		nowId = id;
	}
	if (Game::revCnt == 2 && state == Card::STATE::OPEN && preId == nowId)
	{
		state = Card::STATE::CLEAR;
		
		return true;
	}
	
	return false;
}

void Card::ShowCard()
{
	const Box CLEAR = { 448,64*2,32,64 };
	const Box CLOSE = { 448,64,32,64 };
	const Box ONE = { 0,0,32,64 };
	const Box TWO = { 32,0,32,64 };
	const Box THREE = { 64,0,32,64 };
	const Box FOUR = { 96,0,32,64 };
	const Box FIVE = { 128,0,32,64 };
	const Box SIX = { 160,0,32,64 };
	const Box SEVEN = { 192,0,32,64 };
	const Box EIGHT = { 224,0,32,64 };
	const Box NINE = { 256,0,32,64 };


			if (state == Card::STATE::OPEN)
			{
				if (id == Card::ID::ONE)
				{
					src = ONE;
					draw = ONE;
				}
				if (id == Card::ID::TWO)
				{
					src = TWO;
					draw = TWO;
				}
				if (id == Card::ID::THREE)
				{
					src = THREE;
					draw = THREE;
				}
				if (id == Card::ID::FOUR)
				{
					src = FOUR;
					draw = FOUR;
				}
				if (id == Card::ID::FIVE)
				{
					src = FIVE;
					draw = FIVE;
				}
				if (id == Card::ID::SIX)
				{
					src = SIX;
					draw = SIX;
				}
				if (id == Card::ID::SEVEN)
				{
					src = SEVEN;
					draw = SEVEN;
				}
				if (id == Card::ID::EIGHT)
				{
					src = EIGHT;
					draw = EIGHT;
				}
				if (id == Card::ID::NINE)
				{
					src = NINE;
					draw = NINE;
				}
			}
			if (state == Card::STATE::CLOSE)
			{
				src = CLOSE;
				draw = { 0,0,32,64 };

			}
			if (state == Card::STATE::CLEAR)
			{
				src = CLEAR;
				draw = { 0,0,32,64 };

			}
			image.DrawRota(pos, 0, src, draw);
			
}


//GameControl
bool Game::Initialize()
{
	cursor.image.Load("image/cursor.png");
	back.image.Load("image/back.jpg");
	nice.image.Load("image/nice.png");
	clear.image.Load("image/clear.png");
	ui.image.Load("image/zz.png");
	ui2.image.Load("image/c.png");
	openSound.Load("open.wav");
	SoundSystem::GetSystem()->AddSource(openSound);
	//‚²‚è‰Ÿ‚µ
	card[0][0].id = Card::ID::SEVEN;
	card[0][1].id = Card::ID::THREE;
	card[0][2].id = Card::ID::TWO;
	card[0][3].id = Card::ID::FOUR;
	card[0][4].id = Card::ID::THREE;
	card[0][5].id = Card::ID::ONE;
	card[1][0].id = Card::ID::TWO;
	card[1][1].id = Card::ID::FOUR;
	card[1][2].id = Card::ID::FIVE;
	card[1][3].id = Card::ID::EIGHT;
	card[1][4].id = Card::ID::SIX;
	card[1][5].id = Card::ID::NINE;
	card[2][0].id = Card::ID::SEVEN;
	card[2][1].id = Card::ID::ONE;
	card[2][2].id = Card::ID::EIGHT;
	card[2][3].id = Card::ID::FIVE;
	card[2][4].id = Card::ID::NINE;
	card[2][5].id = Card::ID::SIX;

	std::random_device get_rand_dev;
	std::mt19937 get_rand_mt(get_rand_dev());
	std::shuffle(card.begin(), card.end(), get_rand_mt);

	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 6; ++x)
		{
			card[y][x].Init(x, y);

		}
	}
	clear.pos = { 55,-40 };
	nice.pos = { 0,0 };
	cursor.pos = {90,10};
	ui.pos = {42 * 7 +35,165};
	ui2.pos = ui.pos;
	open = 0;
	a = 255;
	Isalpha = false;
	
	return true;
}

void Game::Update()
{
	key.Run();
	
	
	cursor.Move(key);
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 6; ++x)
		{

			if (card[y][x].Select(cursor, key) && Game::revCnt < 3)
			{
				openSound.PlaySE();
			}
			if (card[y][x].IsPair())
			{
				++open;
				Isalpha = true;
				isui = true;
			}
		
		}
	}
	open;
	if (open == 18)
	{
		clear.pos.y = clear.ease.QuadIn(clear.ease.Time(5), -40, 100, 5);
	}

	if (key.Down(KeyBoard::Key::KEY_E))
	{
		SceneManeger::GetInstance()->ChangeScene(new Title);
	}
}
void Game::Draw()
{
	back.image.Draw(back.pos,GetColor(255,255,200));
	
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 6; ++x)
		{
			
			card[y][x].ShowCard();
		}
	}
	cursor.src = {0,0,32,64};
	cursor.draw = { 16,32,-32,64 };
	cursor.image.DrawRota(cursor.pos,0,cursor.src,cursor.draw, GetColor(55, 225, 255));
	
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 6; ++x)
		{
			if (revCnt < 2 || revCnt == 3)
			{
				ui.image.Draw(ui.pos);
			}

			if (revCnt == 2 && card[y][x].state == Card::STATE::OPEN)
			{
				ui2.image.Draw(ui2.pos);
			}
			if (revCnt == 2  && isui && card[y][x].state != Card::STATE::OPEN)
			{
				ui.image.Draw(ui.pos);
			}
		}
	}
	if (Isalpha)
	{
		a -= 5;
		nice.image.Draw(nice.pos, GetColor(255, 225, 255, a));
	}
	if (a <= 0)
	{
		Isalpha = false;
		a = 255;
	}
	if (open == 18)
	{
		clear.image.Draw(clear.pos);
	}
}
void Game::Finalize()
{
	openSound.~SoundSource();
	cursor.image.~Image();
	back.image.~Image();
	nice.image.~Image();
	clear.image.~Image();
	ui.image.~Image();
	ui2.image.~Image();
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 6; ++x)
		{
			card[y][x].image.~Image();
		}
	}

	//‰½ŒÌ‚©‰ð•ú‚³‚ê‚È‚¢
	//openSound.Destroy();
	//cursor.image.Destroy();
	//back.image.Destroy();
	//nice.image.Destroy();
	//clear.image.Destroy();
	//ui.image.Destroy();
	//ui2.image.Destroy();
	//for (int y = 0; y < 3; ++y)
	//{
	//	for (int x = 0; x < 6; ++x)
	//	{
	//		card[y][x].image.Destroy();
	//	}
	//}

}

