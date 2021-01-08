#include "Player.h"

Player::Player()
{
	if (!Player_Texture.loadFromFile("images/Player.png"))
	{
		std::cout << "No texture" << std::endl;
	}

	s.setTexture(Player_Texture);
	s.setScale(0.5f, 0.5f);
	s.setPosition(BeginX,High);

}

void Player::GoRight()
{
	pos = s.getPosition().x;

	if(pos < 770)
		s.setPosition(pos+speed,High);
}

void Player::GoLeft()
{
	pos = s.getPosition().x;

	if (pos > 50)
		s.setPosition(pos-speed,High);
}