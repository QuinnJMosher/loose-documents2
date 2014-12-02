#include "CFactory.h"
#include "CPlayer.h"
#include "CLevel.h"
#include "car.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Register types. 
///				Associates the Make Functions with a Type Name
/// </summary>
///	
/// <remarks>	Caswal, 3/08/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RegisterTypes()
{
	CFactory* g_Factory = CFactory::getInstance();
	(*g_Factory).AddMakeFunction("Player", MakeCPlayer);
	(*g_Factory).AddMakeFunction("Sprite", MakeCSprite);
	(*g_Factory).AddMakeFunction("Car", MakeCar);
}


int main()
{
	//Register Types
	RegisterTypes();

	//Make and Load a Level
	CLevel level;
	level.LoadLevel("test.txt");

	//Update level
	level.Update(1.0f);
	level.Draw();

	//Save Level
	level.SaveLevel("test.txt");

	system("pause");
	return 0;
}