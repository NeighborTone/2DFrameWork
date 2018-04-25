#pragma once
#include <array>
#include "GameObjcet.h"
#include "Scene.h"
#include "Image.h"
#include "Keyboard.h"

struct Cursur : public GameObject
{
#define CURSOR_RIGHT_MAX if (pos.x < 42 * 7)
#define CURSOR_LEFT_MAX 	if (pos.x > 90)
#define CURSOR_DOWN_MAX if(pos.y < 158)
#define CURSOR_UP_MAX  if(pos.y > 10)
	void Move(KeyBoard&);
};

struct Card : public GameObject
{
	static int cnt;
	static int quantity;	//écêî
	static int pair;

	enum class STATE
	{
		CLOSE,
		OPEN,
		CLEAR,
	};
	enum class ID
	{
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		
		NOT,
	};
	STATE state;
	ID id;
	static ID preId;
	static ID nowId;
	static bool flag;
	static bool flag2;
	void Select(Cursur&, KeyBoard);
	void Pair();

	void Init(int&, int&);
	void ShowCard();
};

class Game : public Scene
{
public:
	static const int CARDSIZE_H = 64;
	static const int CARDSIZE_W = 32;
	
	std::array<std::array<Card, 6>, 3> card;	//card[3][6]
	Cursur cursor;
	GameObject back;
	KeyBoard key;
	
	bool Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

	
};

