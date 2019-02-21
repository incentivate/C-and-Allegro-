#include <allegro.h>
#include "inicia.h"
#include <stdio.h>
#include <iostream>
#include "Jugador.h"
#include "Rectangulo.h"
#include "Npc.h"
#include "Espada.h"

#define PANTALLA_ANCHO 800
#define PANTALLA_ALTO 600

void inicializacion();
void inc_contador_tiempo_juego();
bool colisionan(Rectangulo rect1, Rectangulo rect2);

volatile unsigned int contador_tiempo_juego = 0;
volatile unsigned int tiempo_total = 0;
const int FRAME_RATE = 30;
BITMAP *buffer;
BITMAP *fondo;
BITMAP *personaje;
Jugador jugador;
Jugador *jug = &jugador;
Npc npc1;
Rectangulo rectPJ;
Rectangulo rectNPC;
Espada espada1;
int puntos = 0;
int vida = 9;
bool salir = false;

using namespace std;

int main()
{
    inicializacion();

    do
    {
        if (contador_tiempo_juego)
        {
            while (contador_tiempo_juego)
            {
                contador_tiempo_juego--;
            }

            clear_bitmap(buffer);
            blit(fondo, buffer, 0,0,0,0,PANTALLA_ANCHO,PANTALLA_ALTO);

            textprintf(fondo, font, 10, 10, -1, "Puntos: %d", puntos);
            textprintf(fondo, font, 650, 10, -1, "Vida: %d", vida);

            jugador.dibujarPersonaje();
            rectPJ = rectPJ.crearRectangulo(jugador.getX()+ 5, jugador.getY()+ 17, 17, 28);
            espada1.dibujarEspada(jug);

            if(colisionan(rectNPC, espada1.rectanguloEspada(jug)))
            {
                npc1.posicionarNPC(rand()%770, rand()%520);
                rectNPC = rectNPC.crearRectangulo(npc1.getX(), npc1.getY(), 32, 32);
                puntos++;
                /*Solucion temporal a problemas de choque con la ultima posicion de la espada*/
                espada1.x = -50;
                espada1.y = -50;
            }

            if(colisionan(rectNPC, rectPJ))
            {
                vida--;
            }
            if(vida <= 0)
            {
                salir = true;
                readkey();
            }
            npc1.dibujarNpc(npc1.getX(), npc1.getY());
            rectNPC = rectNPC.crearRectangulo(npc1.getX(), npc1.getY(), 32,32);

            blit(buffer, screen, 0,0,0,0,PANTALLA_ANCHO,PANTALLA_ALTO);

            npc1.moverNPC();
            jugador.moverPersonaje();
        }
        else
        {
            rest(1);
        }
        // tecla de salida
        if (key[KEY_ESC]) salir = true;
    }
    while(!salir);

    destroy_bitmap(buffer);

    return 0;
}
END_OF_MAIN ()

/*
Funcion para inicializar el juego: crea el buffer donde se van a imprimir las demás imagenes,
carga el fondo y me inicializa la posicion del NPC y la imagen de la espada.
*/
void inicializacion()
{
    inicia_allegro(PANTALLA_ANCHO,PANTALLA_ALTO);
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    inicia_audio(70,70);
    buffer = create_bitmap(PANTALLA_ANCHO,PANTALLA_ALTO);
    jugador.iniciar();
    npc1.iniciar();
    espada1.iniciar();
    fondo = load_bmp("background.bmp", NULL);
    npc1.posicionarNPC(200,500);
    srand(time(0));
    LOCK_VARIABLE(contador_tiempo_juego);
    LOCK_FUNCTION(inc_contador_tiempo_juego);
    install_int_ex(inc_contador_tiempo_juego, BPS_TO_TIMER(FRAME_RATE));
}

/*Funcion para controlar los FPS*/
void inc_contador_tiempo_juego()
{
    contador_tiempo_juego++;
    tiempo_total++;
}
END_OF_FUNCTION(inc_contador_tiempo_juego);

/*
Funcion para ver las colisiones.
Se dibuja un rectangulo invisible alrededor de los objetos y si esos rectangulos colisionan devuelve true
*/
bool colisionan(Rectangulo rect1, Rectangulo rect2)
{
    if (rect1.x < rect2.x + rect2.w &&
            rect1.x + rect1.w > rect2.x &&
            rect1.y < rect2.y + rect2.h &&
            rect1.y + rect1.h > rect2.y)
    {
        return true;
    }
    return false;
}
END_OF_FUNCTION(colisionan(Rectangulo rect1, Rectangulo rect2));
