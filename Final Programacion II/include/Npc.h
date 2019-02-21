#ifndef NPC_H
#define NPC_H
#include "allegro.h"

extern BITMAP *buffer;
extern BITMAP *fondo;
extern volatile unsigned int tiempo_total;

class Npc
{
    BITMAP *npc;
    BITMAP* mifondo;
    int x, y, w, h;
    int animacion;
    int direccion;
    int desplazamiento;

public:
    void iniciar();
    void moverNPC();
    void dibujarNpc(int x, int y);
    void posicionarNPC(int x, int y);
    int getX();
    int getY();
};

#endif // NPC_H
