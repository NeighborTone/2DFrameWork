#include "Title.h"
#include "MyClass.h"
using namespace MyClass;
bool Title::Initialize()
{
	back.image.Load("image/back.jpg");
	logo_N.image.Load("image/Nervous.png");
	logo_B.image.Load("image/Breakdown.png");
	logo_N.pos = { -270,0 };
	logo_B.pos = { 500,80 };
	return true;
}
void Title::Update()
{
	key.Run();
	logo_N.pos.x = logo_N.ease.QuadIn(logo_N.ease.Time(5), -270, 0-(-270), 5);
	logo_B.pos.x = logo_B.ease.QuadIn(logo_B.ease.Time(5), 500, 0-450 , 5);
	if (key.Down(KeyBoard::Key::KEY_S))
	{
		SceneManeger::GetInstance()->ChangeScene(new Game);
	}
}

void Title::Draw()
{
	back.image.Draw(back.pos,GetColor(255, 255, 200,200));
	logo_N.image.Draw(logo_N.pos,GetColor(255,225,255));
	logo_B.image.Draw(logo_B.pos, GetColor(255, 225, 255));
}

void Title::Finalize()
{

}