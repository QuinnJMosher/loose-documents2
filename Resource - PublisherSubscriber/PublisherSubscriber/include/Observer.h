#pragma once

#include "Vector2.h"

struct Message {
	enum {
		UPDATE,
		ON_CLICK,
		SPAWN_REQUEST
	} msg;
	bool consumed;
	Vector2 data;
};

class Observer
{
public:
	virtual void OnMessage(Message& msg) = 0;
};

