#pragma once
#include "Image.h"
#include "MyClass.h"
#include "easing.hpp"
class GameObject
{
public:
	Image image;
	MyClass::Box src;
	MyClass::Box draw;
	MyClass::Vec2 pos;
	Easing ease;
	GameObject() {
		src = { 0,0,0,0 };
		draw = { 0,0,0,0 };
		pos = { 0,0 };
	};
	virtual ~GameObject() {};
 };