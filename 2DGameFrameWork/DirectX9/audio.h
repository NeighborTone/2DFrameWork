#pragma once
#include <XAudio2.h>
#include "wav.h"

class SoundSource
{
private:


public:
	SoundSource();
	SoundSource(SoundSource&);
	~SoundSource();
	bool Load(const char* path);
	void PlayBGM(int loopNum = XAUDIO2_LOOP_INFINITE, float gain = 1.0f, float pitch = 1.0f);
	void PlaySE(float gain = 1.0f, float pitch = 1.0f);
	//�ꎞ��~
	void Stop();
	void Destroy();
	//�\�[�X���H�C�X(�����ɉ������i�[�����
	IXAudio2SourceVoice* pSource;
	//wav�f�[�^�i�[�p
	WAV					  wav;
};

//�T�E���h�Ǘ����B�V���O���g���E
class SoundSystem 
{
private:
		//�C���^�[�t�F�[�X
		static IXAudio2* pXAudio2;
		//�}�X�^�[���H�C�X
		static IXAudio2MasteringVoice* pMaster;

		SoundSystem();
		SoundSystem(const SoundSystem&) = delete;	//�R�s�[�֎~
public:
	~SoundSystem();
	
	static SoundSystem* GetSystem();
	//�T�E���h�V�X�e���̏������A��x�������΂悢
	bool Create();
	//�\�[�X�{�C�X�̓o�^
	//�\�[�X�{�C�X�͖����I�ɊJ�����Ȃ�����A�v���P�[�V�����I�����܂Ŏc�葱����
	bool AddSource(SoundSource& source);
	void DestroySystem(SoundSource& source);
};

