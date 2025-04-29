///Actividad final

#include <iostream>
#include "funciones.h"
#include <cstdlib>
#include <ctime>
#include <locale>
#include "rlutil.h"

using namespace std;


int main(){

    ///MENU
    int opcion = 1;
    int Z=0;

    ///JUEGO
    //Variables del bloque donde se piden los nombres de los jugadores
    string jugador1, jugador2;
    //Variables del bloque de la ronda del juego
    int const CANT_CARTAS=5, CANT_PUNTOS=3;
    int X;
    string cartasJuador1[CANT_CARTAS], cartasJuador2[CANT_CARTAS];
    int puntosJugador1[CANT_PUNTOS], puntosJugador2[CANT_PUNTOS];
    string embaucadora;

    ///ESTADISTICA
    int const Y=10;
    int estadisticaPuntos[Y];
    string estadisticaGanadores[Y];
    int puntosGanadores=0;
    string nombreGanador;


    srand(time(0));
    setlocale(LC_ALL, "spanish");

    cargarVectorString(estadisticaGanadores, "\t", Y);
    inicializarEnCero(estadisticaPuntos, Y);

    do{
        rlutil::hidecursor();


        ubicarTexto("--------------------------", 5, 5);
        ubicarTexto("         EMBAUCADO        ", 5, 6);
        ubicarTexto("--------------------------", 5, 7);
        ubicarTexto("JUGAR", 15, 8);
        ubicarTexto("ESTADISTICA", 12, 9);
        ubicarTexto("CREDITOS", 14, 10);
        ubicarTexto("SALIR", 15, 11);
        ubicarTexto("--------------------------", 5, 12);

        rlutil::locate(10, 8 + Z);
        cout << (char)3 << endl;

        switch(rlutil::getkey()){
            case 14:
                rlutil::locate(10, 8 + Z);
                cout << " " << endl;
                Z--;
                if (Z < 0){
                    Z = 0;
                }
                break;
            case 15:
                rlutil::locate(10, 8 + Z);
                cout << " " << endl;
                Z++;
                if (Z > 3){
                    Z = 3;
                }
                break;
            case 1:
                switch (Z){
                    case 0:
                        system("cls");

                            registrarNombres(jugador1, jugador2);

                            inicializarEnCero(puntosJugador1, CANT_PUNTOS);
                            inicializarEnCero(puntosJugador2, CANT_PUNTOS);

                            for (X=0 ; X<3 ; X++){

                                system("cls");
                                ubicarTexto("EMBAUCADO", 17, 1);
                                ubicarTexto("-------------------------------------------------", 1, 2);
                                cout << endl << "\tRONDA: #" << X+1 << "\t"<< jugador1 << " Vs " << jugador2 << endl;

                                repartirCartas(cartasJuador1, cartasJuador2, CANT_CARTAS);
                                mostrarVectorAcomodado(cartasJuador1, CANT_CARTAS, 16, 10, jugador1, puntosJugador1, X);
                                cout << endl << endl;
                                mostrarVectorAcomodado(cartasJuador2, CANT_CARTAS, 16, 21, jugador2, puntosJugador2, X);
                                cout << endl << endl;
                                dibujarCarta();

                                embaucadora = elegirCartaEmbaucadora();
                                cout << "Carta Embaucadora: " << embaucadora << endl;

                                if (X == 1){
                                    preguntarAJugadores(jugador1, jugador2, puntosJugador1, puntosJugador2, X, embaucadora);
                                } else if (X == 2){
                                    preguntarAJugadores(jugador2, jugador1, puntosJugador2, puntosJugador1, X ,embaucadora);
                                }

                                puntosJugador1[X] += sumarPuntos(cartasJuador1, CANT_CARTAS, embaucadora);
                                puntosJugador2[X] += sumarPuntos(cartasJuador2, CANT_CARTAS, embaucadora);

                                mostrarPuntos(jugador1, jugador2, puntosJugador1, puntosJugador2, CANT_PUNTOS);


                                system("pause");
                            }

                            system("cls");

                            mostrarGanador(jugador1, jugador2, puntosJugador1, puntosJugador2, CANT_PUNTOS, nombreGanador, puntosGanadores);
                            cargarEnEstadistica(estadisticaPuntos, estadisticaGanadores, puntosGanadores, nombreGanador);

                            cout << endl << endl << endl;

                            system("pause");
                            system("cls");

                        break;
                    case 1:

                        system("cls");
                        ubicarTexto("EMBAUCADO", 17, 1);
                        ubicarTexto("------------------------------------------", 1, 2);
                        cout << endl << (char)3 << " " << (char)4 << " " << (char)5 << " " << (char)6 << " " << "Estadistica de Ganadores" << " " << (char)6 << " " << (char)5 << " " << (char)4 << " " << (char)3 << endl;
                        mostrarEstadistica(estadisticaPuntos, estadisticaGanadores, Y, puntosGanadores, nombreGanador);
                        cout << endl;
                        rlutil::locate(1, 19);
                        system("pause");
                        system("cls");

                        break;
                    case 2:
                        system("cls");
                        ubicarTexto("EMBAUCADO", 29, 1);
                        ubicarTexto("---------------------------------------------------------------", 1, 2);
                        cout << endl << "                    " << (char)3 << " " << (char)4 << " " << (char)5 << " " << (char)6 << " " << "CREDITOS" << " " <<(char)6 << " " << (char)5 << " " << (char)4 << " " << (char)3 << endl << endl;
                        ubicarTexto("Trabajo Practico Integrador - PROGRAMACION I - UTN (frgp)", 3, 5);
                        ubicarTexto("Juego inventado por el profesor Angel Simon", 10, 7);
                        ubicarTexto("Desarrollado por los alumnos:", 18, 9);
                        ubicarTexto("Bruno Francisco (Legajo 30249).", 16, 10);
                        ubicarTexto("Rodríguez Ignacio (Legajo 30566).", 15, 11);
                        ubicarTexto("Maria Sol Desimone (Legajo 30308).", 14, 12);
                        ubicarTexto("Tajes Albani Alejo Matías (Legajo 28074).", 12, 13);

                        rlutil::locate(1, 20);
                        system("pause");
                        system("cls");

                        break;
                    case 3:
                        opcion = 0;
                        break;
            }
        }


    }while (opcion != 0);

    system("cls");
    ubicarTexto("Gracias por jugar :)", 10, 10);
    rlutil::locate(1, 20);

    return 0;
}
