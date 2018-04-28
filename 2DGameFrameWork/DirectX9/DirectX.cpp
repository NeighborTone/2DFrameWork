#include "DirectX.h"
#include "../MyClass.h"

using namespace MyClass;

namespace DX9
{
	bool DirectX::Init(System& win)
	{
		if (direct3d.Create(win))
		{
			in.CreateInput(win.GetWindow());
			pad.CreatePadInput(win.GetWindow());
			scene = SceneManeger::GetInstance();
			//���̉�����
			system->GetSystem()->Create();
			sound.Load("Grass.wav");
			system->GetSystem()->AddSource(sound);
			sound.Play();
			scene->InsertScene(new Title);
			return true;
		}
		return false;
	}

	void DirectX::Update()
	{
	
		scene->GetCurrentScene()->Update();
	}

	void DirectX::Draw()
	{
		//�`��J�n
		if (SUCCEEDED(direct3d.p_d3dDevice->BeginScene()))
		{
			//�w�i�N���A
			direct3d.p_d3dDevice->Clear(
				0,
				NULL,
				D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER,
				GetColor(0, 0, 0),
				1.0f,
				0
			);

			scene->GetCurrentScene()->Draw();

			//�`��I��
			direct3d.p_d3dDevice->EndScene();
		}
		else
		{
			MessageBox(NULL, "�`��Ɏ��s���܂���", "Error", MB_OK);
		}
		//�`�攽�f
		direct3d.p_d3dDevice->Present(NULL, NULL, NULL, NULL);
	}

	void DirectX::End()
	{
		scene->GetCurrentScene()->Finalize();
		system->GetSystem()->DeleteSystem(sound);
	}
	
}