#pragma once
#include "CSprite.h"

#define MAKEFUNCTION(Type) inline IObject* Make##Type() { return new Type(); }

class Car : public CSprite {
public:
	Car();
	~Car();

	virtual void Load(FILE* file);
	virtual void Save(FILE* file);

	virtual void Update(float dt) { printf("Car update!\n"); }
	virtual void Draw();

private:
	int enginePower;
	sVector2D velocity;
	char occupent[256];
};

MAKEFUNCTION(Car)