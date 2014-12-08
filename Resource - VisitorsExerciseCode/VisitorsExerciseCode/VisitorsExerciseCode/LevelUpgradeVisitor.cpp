#include "StdAfx.h"
#include "LevelUpgradeVisitor.h"
#include "Modifiable.h"
#include "Player.h"
#include "Shotgun.h"
#include "MagicWand.h"
#include <iostream>

LevelUpgradeVisitor::LevelUpgradeVisitor(void)
{
}


LevelUpgradeVisitor::~LevelUpgradeVisitor(void)
{
}

void LevelUpgradeVisitor::visit(Modifiable* visitable)
{
	// determine what visitable is and then pass to the correct upgrade function
	// hint: dynamic_cast
	if (Player* cast = dynamic_cast<Player*>(visitable)) {
		upgrade((*cast));
	} else if (Shotgun* cast = dynamic_cast<Shotgun*>(visitable)) {
		upgrade((*cast));
	} else if (MagicWand* cast = dynamic_cast<MagicWand*>(visitable)) {
		upgrade((*cast));
	}
}

void LevelUpgradeVisitor::upgrade(Player& p) 
{
	p.setPoints(p.getPoints() + 5);
}

void LevelUpgradeVisitor::upgrade(Shotgun& s)
{
	if (getLevel() >= 1) {
		s.setDualShotgunEnabled(true);
	} else {
		s.setDualShotgunEnabled(false);
	}
}

void LevelUpgradeVisitor::upgrade(MagicWand& w)
{
	w.setPowerLevel(w.getPowerLevel() + 2);
}
