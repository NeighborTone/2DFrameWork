#pragma once
#include <XAudio2.h>
#include "wav.h"

class SoundSource
{
private:
	//�����i�[�p�̃o�b�t�@�[
	XAUDIO2_BUFFER buf;

public:
	//�\�[�X���H�C�X(�����ɉ������i�[�����
	IXAudio2SourceVoice * pSource;
	//wav�f�[�^�i�[�p
	WAV					  wav;

	SoundSource();
	SoundSource(SoundSource&);
	~SoundSource();
	bool Load(const char* path);
	void PlayBGM(int loopNum = XAUDIO2_LOOP_INFINITE, float gain = 1.0f, float pitch = 1.0f);
	void PlaySE(float gain = 1.0f, float pitch = 1.0f);
	//�ꎞ��~
	void Pause();
	//��~
	void Stop();
	//�\�[�X�j��
	void Destroy();
	
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
	//�o�^�����T�E���h�S�̂̉��ʒ���
	void SetMasterGain(float gain);
	void DestroySystem(SoundSource& source);
};

