#pragma once
#include <XAudio2.h>
#include "wav.h"

class SoundSource
{
private:

	bool Submit(int loopNum = XAUDIO2_LOOP_INFINITE);
public:
	SoundSource();
	SoundSource(SoundSource&);
	~SoundSource();
	bool Load(const char* path);
	void PlayBGM(int loopNum = XAUDIO2_LOOP_INFINITE);
	void PlaySE();
	//�ꎞ��~
	void Stop();
	void Destroy();
	//�\�[�X���H�C�X(�����ɉ������i�[�����
	IXAudio2SourceVoice* pSource;
	//wav�f�[�^
	WAV					  wav;
};

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
	bool Create();
	bool AddSource(SoundSource& source);
	void DestroySystem(SoundSource& source);
};

