#pragma once
#include "SceneManager.h"
#include "GameObjcet.h"
#include "Game.h"
#include "Keyboard.h"
#include "DirectX9\DX9_Font.h"

class Title : public Scene
{
public:
	bool Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

	int a;
	GameObject logo_N,logo_B, back,button;
	KeyBoard key;
};