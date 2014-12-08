#include "AIE.h"
#include "Cat.h"
#include "GameDefs.h"
#include <iostream>

Cat::Cat(void)
{
	m_sprite = -1;
	m_isAlive = false;
	m_position.x = iScreenWidth>>1;
	m_position.y = iScreenHeight>>1;
}


Cat::~Cat(void)
{
}

void Cat::initWithFile(const char* szFilename)
{
	m_sprite = CreateSprite(szFilename, 128, 128, true);
}

void Cat::destroy() 
{
	DestroySprite(m_sprite);
}

void Cat::OnMessage(Message& msg)
{
	// Implement how your cats respond to your messages here
	switch (msg.msg)
	{
	case 0:
		draw();
		msg.consumed = true;
		break;

	case 1:
		if (msg.data.x > m_position.x - 64 && msg.data.x < m_position.x + 64) {
			if (msg.data.y > m_position.y - 64 && msg.data.y < m_position.y + 64) {
				destroy();
				this->m_isAlive = false;
				msg.consumed = true;
			}
		}
		break;

	case 2:
		if (this->m_isAlive == false) {
			initWithFile("images/cat1.png");
			m_position = msg.data;
			m_isAlive = true;
			msg.consumed = true;
		}
		break;

	default:
		throw("mesage value error");
		break;
	}
}

void Cat::draw()
{
	if (m_isAlive == false || m_sprite < 0) {
		return;
	}

	DrawSprite(m_sprite);
}