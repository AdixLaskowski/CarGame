#include "Car.h"

Car::Car()
{
	if (!Car_Texture.loadFromFile("images/Enemy.png"))
	{
		std::cout << "Stone texture error" << std::endl;
	}

	s.setTexture(Car_Texture);
	s.setScale(0.5f, 0.5f);
	s.setPosition(20, 20);
	s.setOrigin(100, 100);
	s.setRotation(180);

	posY = 0;

	rnd = rand() % 6 + 1;
	a = 0;
	Spawn();
}

void Car::Falling()
{
	posY = s.getPosition().y;

	if (posY < 1200)
	{
		a = 0;

		s.setPosition(posX, posY + speed);
	}
	
	if (posY >= 1198)
	{
		Spawn();
		
		if (a == 0)
		{
			AddPoints();
			a = 1;
		}
	}
}

void Car::AddPoints()
{	
	points += 10;
}

void Car::Spawn()
{
	posY = 0;
	rnd = rand() % 6 + 1;

	if (rnd == 1)
		posX = 90;

	if (rnd == 2)
		posX = 250;
	
	if (rnd == 3)
		posX = 380;
	
	if (rnd == 4)
		posX = 500;
	
	if (rnd == 5)
		posX = 640;
	
	if (rnd == 6)
		posX = 800;
	

	s.setPosition(posX, posY);

}

bool Car::ChceckCollision(float x, float y)
{
	if (this->posY >= y and this->posY < y+135 and this->posX < x + 65 and this->posX > x - 65)
	{
		return true;
	}
}

