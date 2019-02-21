#include "Npc.h"

void Npc::iniciar()
{
    npc = load_bmp("personaje.bmp", NULL);
    if(!npc)
    {
        allegro_message("Error al cargar la imagen");
    }

    animacion = 0;
    desplazamiento = 10;
}

void Npc::moverNPC()
{
    int ax = x;
    int ay = y;

    if (tiempo_total % 20 == 0)
    {
        direccion = rand()%4;
    }
    if (direccion == 0)
    {
        y += desplazamiento;
    }
    if (direccion == 3)
    {
        y -= desplazamiento;
    }
    if (direccion == 1)
    {
        x -= desplazamiento;
    }
    if (direccion == 2)
    {
        x += desplazamiento;
    }
    // ANIMACION DEL NPC
    if ( ax != x || ay != y )
    {
        animacion++;
        if (animacion > 2) animacion = 0;
    }

    /*
    Si choca con los limites de la pantalla, cambia de dirección
    */
    if (x < 0)
    {
        x = 0;
        direccion = rand()%4;
    }
    if (x > 770)
    {
        x = 770;
        direccion = rand()%4;
    }
    if (y < 0)
    {
        y = 0;
        direccion = rand()%4;
    }
    if (y > 520)
    {
        y = 520;
        direccion = rand()%4;
    }
}

void Npc::dibujarNpc(int x, int y)
{
    masked_blit(npc, buffer, animacion*32, direccion*32, x, y, 32, 32);
}

int Npc::getX()
{
    return this->x;
}

int Npc::getY()
{
    return this->y;
}

void Npc::posicionarNPC(int x, int y)
{

    this-> x = x;
    this-> y = y;

}
