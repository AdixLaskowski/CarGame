#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Car : public Drawable
{
public:
	Car();
    Texture Car_Texture;
    Sprite s;
    float posX;
    float posY;
    float speed = 18;
    int points = 0;
    float rnd;
    bool a = 0;


    void Falling();
    void Spawn();
    void AddPoints();
    bool ChceckCollision(float x, float y);

private:
    Sprite m_sprite;
    Texture m_texture;
    VertexArray m_vertices;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(m_sprite, states);
        states.texture = &m_texture;
        target.draw(m_vertices, states);
    }

};

