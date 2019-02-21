#include "Jugador.h"

void Jugador::iniciar()
{
    personaje = load_bmp("lee.bmp", NULL);
    if(!personaje)
    {
        allegro_message("Error al cargar la imagen");
    }
    animacion = 0;
    desplazamiento = 6;
}

void Jugador::moverPersonaje()
{
    int ax = x;
    int ay = y;

    pasos = load_wav("pasos.wav");

    // ANIMACION DEL PERSONAJE
    if (key[KEY_UP])
    {
        y -= desplazamiento;
        direccion = 1;
    }
    if (key[KEY_DOWN])
    {
        y += desplazamiento;
        direccion = 0;
    }
    if (key[KEY_LEFT])
    {
        x -= desplazamiento;
        direccion = 2;
    }
    if (key[KEY_RIGHT])
    {
        x += desplazamiento;
        direccion = 3;
    }

    if ( ax != x || ay != y )
         {
              play_sample(pasos, 100, 128, 3300, 0);
              animacion++;
              if (animacion > 2) animacion = 0;
         }

    // LIMITES DE LA PANTALLA
         if (x < 0) x = 0;
         if (x > 770) x = 770;
         if (y < 0) y = 0;
         if (y > 520) y = 520;
}

void Jugador::dibujarPersonaje()
{
    masked_blit(personaje, buffer, animacion*27, direccion*47, x, y, 27, 47);
}

int Jugador::getX()
{
    return this->x;
}

int Jugador::getY()
{
    return this->y;
}

