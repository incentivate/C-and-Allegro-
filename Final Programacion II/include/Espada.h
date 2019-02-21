#pragma once
#define ESPADA_H
#include "allegro.h"
#include "Jugador.h"
#include "Rectangulo.h"

extern BITMAP* buffer;

class Espada{

    public:
    int x, y, w, h;
    private:
    BITMAP *espada;
    SAMPLE *ruidoEspada;
    Rectangulo rectEspada;

    public:
    void iniciar();
    void dibujarEspada(Jugador *jug);
    Rectangulo rectanguloEspada(Jugador *jug);
    Rectangulo borrarRectEspada();
};
