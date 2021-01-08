// GreatGame21.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Car.h"

using namespace sf;

int main()
{
    //Rendering game window

    RenderWindow window(VideoMode(900, 1300), "Car Game", Style::Titlebar | sf::Style::Close);

    //Creating player and cars objects

    Player player;

    Car car1;
    Car car2;
    Car car3;
    Car car4;
    Car car5;

    // Making texts

    Font font;

    int points=0;

    String p = std::to_string(points);

    font.loadFromFile("GoodTimes.ttf");
    Text ScoreText1, PointsText, GameOverText, RestartText;

    ScoreText1.setFont(font);
    ScoreText1.setCharacterSize(60);
    ScoreText1.setString("Score: ");
    ScoreText1.setPosition(100, 1220);

    PointsText.setFont(font);
    PointsText.setCharacterSize(60);
    PointsText.setString(p);
    PointsText.setPosition(500, 1220);

    GameOverText.setFont(font);
    GameOverText.setFillColor(Color::Red);
    GameOverText.setCharacterSize(100);
    GameOverText.setString("Game over");
    GameOverText.setPosition(80, 150);

    RestartText.setFont(font);
    RestartText.setFillColor(Color::Yellow);
    RestartText.setCharacterSize(35);
    RestartText.setString("Press space to play again");
    RestartText.setPosition(80, 650);

    //Music Controller

    Music soundtrack;
    soundtrack.openFromFile("Race.wav");
    soundtrack.setVolume(30);
    soundtrack.play();
    soundtrack.setLoop(1);

    bool gameover = false;

    while (window.isOpen())
    {

        //Basic events 

        Event basics;
        while (window.pollEvent(basics))
        {
            if (basics.type == Event::Closed)
                window.close();
        }
        
        window.setFramerateLimit(60);

        //Background and point counter bar

        Texture Background_Texture, Bar_Texture;
        

        if (!Background_Texture.loadFromFile("Images/Road.jpg"))
        {
            std::cout << "Loadning texture error" << std::endl;
        }


        if (!Bar_Texture.loadFromFile("Images/Bar.jpg"))
        {
            std::cout << "Loadning texture error" << std::endl;
        }

        Sprite Background, Bar;
        Background.setTexture(Background_Texture);
        Bar.setTexture(Bar_Texture);

        Bar.setPosition(0,1200);

        
        //Player Controller

        if (Keyboard::isKeyPressed(Keyboard::D))
            player.GoRight();

        if (Keyboard::isKeyPressed(Keyboard::A))
            player.GoLeft();

        // Cars
        if (gameover == false)
        {
            car1.Falling();
            car1.speed = 19;

            car2.Falling();
            car2.speed = 18.5;

            car3.Falling();
            car3.speed = 18.2;

            car4.Falling();
            car4.speed = 17.5;

            car5.Falling();
        }

        //Restarting game

        if (gameover == true)
        {
            if (Keyboard::isKeyPressed(Keyboard::Space))
            {
                car1.points = 0;
                car2.points = 0;
                car3.points = 0;
                car4.points = 0;
                car5.points = 0;

                car1.Spawn();
                car2.Spawn();
                car3.Spawn();
                car4.Spawn();
                car5.Spawn();

                gameover = false;
                soundtrack.play();

                ScoreText1.setCharacterSize(60);
                ScoreText1.setString("Score: ");
                ScoreText1.setPosition(100, 1220);

                PointsText.setCharacterSize(60);
                PointsText.setString(p);
                PointsText.setPosition(500, 1220);

                GameOverText.setFillColor(Color::Red);
                GameOverText.setCharacterSize(100);
                GameOverText.setString("Game over");
                GameOverText.setPosition(80, 150);

            }

        }
       
        

        //Chcecking collisions

        if (gameover == false)
        {
            if (car1.ChceckCollision(player.pos, player.High) == true)
            {
                gameover = true;
            }

            if (car2.ChceckCollision(player.pos, player.High) == true)
            {
                gameover = true;
            }

            if (car3.ChceckCollision(player.pos, player.High) == true)
            {
                gameover = true;
            }

            if (car4.ChceckCollision(player.pos, player.High) == true)
            {
                gameover = true;
            }

            if (car5.ChceckCollision(player.pos, player.High) == true)
            {
                gameover = true;
            }
        }

        //Counting points

        points = car1.points + car2.points + car3.points + car4.points;

        p = std::to_string(points);
            PointsText.setString(p);

        //Game Over

            if (gameover == true)
            {
                ScoreText1.setCharacterSize(65);
                ScoreText1.setString("Score: ");
                ScoreText1.setPosition(100, 400);
;
                PointsText.setCharacterSize(65);
                PointsText.setString(p);
                PointsText.setPosition(500, 400);

                soundtrack.pause();

                window.clear(Color::Black);
                window.draw(GameOverText);
                window.draw(ScoreText1);
                window.draw(PointsText);
                window.draw(RestartText);
            }


        //Drawing objects

        
        if (gameover == false)
        {
            window.clear(Color::White);

            window.draw(Background);
            window.draw(player.s);

            window.draw(car1.s);
            window.draw(car2.s);
            window.draw(car3.s);
            window.draw(car4.s);
            window.draw(car5.s);

            window.draw(Bar);
            window.draw(ScoreText1);
            window.draw(PointsText);
        }

        window.display();

    
    }


    std::cout << "Hello World!\n";
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
