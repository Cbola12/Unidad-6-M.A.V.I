#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

int main()
{

    RenderWindow App(VideoMode(800, 600), "Space");


    Vector2f posicion(100.0f, 250.0f);
    Vector2f velocidad(0.0f, 0.0f);
    
    const float aceleracion = 0.1f;
    const float frenado = 0.05f;
   
    bool izquierda = false;
    bool derecha = false;


    while (App.isOpen())
    {
        Event event;
        while (App.pollEvent(event))
        {
            if (event.type == Event::Closed)
                App.close();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Left)
                {
                    izquierda = true;
                    derecha = false;
                }
                else if (event.key.code == Keyboard::Right)
                {
                    derecha = true;
                    izquierda = false;
                }
            }
            else if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Left || event.key.code == Keyboard::Right)
                {
                    izquierda = false;
                    derecha = false;
                }
            }
        }


        float deltaTime = 1.0f / 60.0f;

        if (izquierda)
            velocidad.x -= aceleracion * deltaTime;
        else if (derecha)
            velocidad.x += aceleracion * deltaTime;
        else
            velocidad.x -= (velocidad.x * frenado);


        posicion += velocidad * deltaTime;


        if (posicion.x > App.getSize().x)
            posicion.x = 0.0f;
        else if (posicion.x < 0.0f)
            posicion.x = App.getSize().x;

        


        App.clear();


        CircleShape object(50.0f);
        object.setPosition(posicion);
        object.setFillColor(Color::Blue);
        App.draw(object);

        App.display();
    }

    return 0;
}

