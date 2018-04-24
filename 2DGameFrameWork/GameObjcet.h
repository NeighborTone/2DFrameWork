#pragma once
#include "Image.h"
#include "MyClass.h"
class GameObject
{
public:
	Image image;
	MyClass::Box src;
	MyClass::Box draw;
	MyClass::Vec2 pos;

	GameObject() {
		src = { 0,0,0,0 };
		draw = { 0,0,0,0 };
		pos = { 0,0 };
	};
	~GameObject() {};
 };