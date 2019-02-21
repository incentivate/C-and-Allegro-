#ifndef JUGADOR_H
#define JUGADOR_H
#include "allegro.h"
#include <iostream>
#include "Rectangulo.h"

using namespace std;

extern BITMAP *buffer;
extern BITMAP *espada;

class Jugador
{
    Rectangulo rect;
    BITMAP *personaje;
    SAMPLE *pasos;
    int x, y;
    int animacion;
    int desplazamiento;

    public:
    int direccion;

    public:
        void iniciar();
        void moverPersonaje();
        void dibujarPersonaje();
        int getX();
        int getY();
};

#endif // JUGADOR_H
