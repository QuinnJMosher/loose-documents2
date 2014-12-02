#include "car.h"
#include "string_Util.h"

Car::Car() {
}
Car::~Car(){

}
void Car::Load(FILE* file) {
	CSprite::Load(file);
	fscanf(file, "%i\n", enginePower);
	fscanf(file, "%f, %f\n", velocity.x, velocity.y);
	fgets(occupent, 256, file);
	trimWhiteSpace(occupent);
}

void Car::Save(FILE* file) {
	CSprite::Save(file);
	fprintf(file, "%i\n", enginePower);
	fprintf(file, "%f %f\n", velocity.x, velocity.y);
	fprintf(file, "%s\n", occupent);
}

void Car::Draw() {
	if (strcmp(occupent, "") == 0) {
		printf("a car with no occupent draws\n");
	} else {
		printf("a car driven by %s draws\n", occupent);
	}

}