#pragma once
#include <array>
#include "GameObjcet.h"
#include "Image.h"
#include "Keyboard.h"
#include "SceneManager.h"
#include "DirectX9/audio.h"

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

	

	bool Select(Cursur&, KeyBoard);
	bool IsPair();

	void Init(int&, int&);
	void ShowCard();
};

class Game : public Scene
{
public:
	bool Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

	static const int CARDSIZE_H = 64;
	static const int CARDSIZE_W = 32;
	static int revCnt;

	std::array<std::array<Card, 6>, 3> card;	//card[3][6]
	Cursur cursor;
	GameObject back,nice,clear,ui,ui2;
	SoundSource openSound;
	KeyBoard key;
	
	//alpha’l
	bool Isalpha;
	static bool isui;
	int a;
	int open;
	
};

