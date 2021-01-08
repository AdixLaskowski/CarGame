#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Player : public Drawable
{
    public:
        Player();
        Texture Player_Texture;
        Sprite s;

        float speed = 16;
        float BeginX = 640;
        float High = 750;
        float pos;

        void GoRight();
        void GoLeft();
        
        

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

