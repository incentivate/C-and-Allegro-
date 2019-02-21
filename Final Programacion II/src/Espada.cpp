#include "Espada.h"

void Espada::iniciar()
{
   espada = load_bmp("espadas.bmp", NULL);
}

void Espada::dibujarEspada(Jugador *jug)
{
    //ruidoEspada = load_wav("blade.wav");

     if(key[KEY_X])
    {
       // play_sample(ruidoEspada, 100, 128, 1000, 0);

        if(jug->direccion == 1) // arriba
        {
            w = 8;
            h = 21;
            x = jug->getX()+ 8;
            y = jug->getY()-15;
            masked_blit(espada, buffer, 0, 0, jug->getX()+8, jug->getY()-15, w, h);
        }
        if(jug->direccion == 2) // izquierda
        {
            w = 21;
            h = 8;
            x = jug->getX()-15;
            y = jug->getY()+20;
            masked_blit(espada, buffer, 16, 0, jug->getX()-15, jug->getY()+20, w, h);
        }
        if(jug->direccion == 3) // derecha
        {
            w = 21;
            h = 8;
            x = jug->getX()+20;
            y = jug->getY()+20;
            masked_blit(espada, buffer, 16, 9, jug->getX()+20, jug->getY()+20, w, h);
        }
        if(jug->direccion == 0) // abajo
        {
            w = 8;
            h = 21;
            x = jug->getX()+8;
            y = jug->getY()+30;
            masked_blit(espada, buffer, 8, 0, jug->getX()+8, jug->getY()+30, w, h);
        }
    }
}

Rectangulo Espada::rectanguloEspada(Jugador *jug)
{
    if(jug->direccion == 1) // arriba
    {
        rectEspada = rectEspada.crearRectangulo(x, y, w, h);
        return rectEspada;
    }
    if(jug->direccion == 2) // izquierda
    {
        rectEspada = rectEspada.crearRectangulo(x, y, w, h);
        return rectEspada;
    }
    if(jug->direccion == 3) // derecha
    {
        rectEspada = rectEspada.crearRectangulo(x, y, w, h);
        return rectEspada;
    }
    if(jug->direccion == 0) // abajo
    {
        rectEspada = rectEspada.crearRectangulo(x, y, w, h);
        return rectEspada;
    }
}

Rectangulo Espada::borrarRectEspada()
{
    rectEspada = rectEspada.crearRectangulo(-10,-10,0,0);

}
