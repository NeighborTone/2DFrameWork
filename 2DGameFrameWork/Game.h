#pragma once
#include "GameObjcet.h"
#include "Scene.h"
#include "Image.h"
#include "Keyboard.h"
struct Card : public GameObject
{
	enum class STATE
	{
		NONE,
		OPEN,
	};
	STATE state;

};
struct Cursur : public GameObject
{
#define CURSOR_RIGHT_MAX if (pos.x < 42 * 7)
#define CURSOR_LEFT_MAX 	if (pos.x > 90)
#define CURSOR_DOWN_MAX if(pos.y < 158)
#define CURSOR_UP_MAX  if(pos.y > 10)
	void Move(KeyBoard&);
};

class Game : public Scene
{
public:
	const int CARDSIZE_H = 64;
	const int CARDSIZE_W = 32;
	
	Card card[3][6];
	Cursur cursor;
	GameObject back,field[3][6];
	KeyBoard key;
	
	bool Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

	
};

