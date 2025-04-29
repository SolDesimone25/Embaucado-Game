#include <iostream>
#include "funciones.h"
#include <string>
#include "rlutil.h"

using namespace std;

//GENERALES:FUNCIONES DE UTILIDAD PARA EMPROLIJAR EL CODIGO, INICIALIZAR VARIABLES Y VECTORES,ETC.

void ubicarTexto(string texto, int columna, int fila){
    rlutil::locate(columna, fila);
    cout << texto;
}

void inicializarEnCero(int vec[], int tam){
    for (int X=0 ; X<tam ; X++){
        vec[X] = 0;
    }
}

void cargarVectorString(string vec[], string palabra, int tam){
    for (int X=0 ; X< tam ; X++){
        vec[X] = palabra;
    }
}

int acumularVector(int vec[], int tam){
    int total=0;
    for (int I=0; I< tam; I++){
        total += vec[I];
    }
    return total;
}

int buscarMayorEnVector(int vec[], int tam){
    int mayor = vec[0];
    for (int X=1 ; X<tam ; X++){
        if (vec[X] > mayor){
            mayor=vec[X];
        }
    }
    return mayor;
}

void dibujarUnaLineaVertical(int columna, int comienzoFila, int finFila){
for (int X=comienzoFila ; X< finFila ; X++){
        rlutil::locate(columna, X);
        cout << "|";
    }
}

//JUEGOS FUNCIONES QUE SE UTILIZAN EN EL TRANSCURSO DE LA PARTIDA.

void registrarNombres(string &jugador1,string &jugador2){
 ///Esta funcion se utiliza para que los jugadores ingresen sus nombres.
    bool confirmar = true;
    char confiNombres;

    while (confirmar) {
        system("cls");
        cout << "Antes de ingresar deben registrar sus nombres: " << endl;

        cout << endl << "Nombre del Jugador 1: ";
        cin >> jugador1;
        cout << endl << "Nombre del Jugador 2: ";
        cin >> jugador2;

        cout << endl << "¿Confirmar nombres? (S/s para confirmar): ";
        cin >> confiNombres;
        if (confiNombres == 'S' || confiNombres == 's') {
            confirmar = false;
        }
    }
}

int tirarUnaCarta(int tam){
    int carta;
    carta = rand() % tam;
    return carta;
}

void repartirCartas(string vecJugador1[], string vecJugador2[], int tam){
    int const CANT_CARTAS = 20;
    string vecCartas[CANT_CARTAS] = {"10 de Trebol", "J de Trebol", "Q de Trebol", "K de Trebol", "A de Trebol", "10 Pica", "J de Pica", "Q de Pica", "K de Pica", "A de Pica", "10 Corazón", "J de Corazón", "Q de Corazón", "K de Corazón", "A de Corazón", "10 Diamante", "J de Diamante", "Q de Diamante", "K de Diamante", "A de Diamante" };
    string vecAuxiliar[CANT_CARTAS];
    int carta, X, J;
    cargarVectorString(vecAuxiliar, ".", CANT_CARTAS);

    for (X=0 ; X<20 ; X++){
        bool cargado=true;
        while (cargado){
            carta=tirarUnaCarta(21);
            if (vecAuxiliar[carta] == "."){
                vecAuxiliar[carta] = vecCartas[X];
                cargado=false;
            }
        }
    }

    for (J=0 ; J<tam ; J++){
        vecJugador1[J]=vecAuxiliar[J];
        vecJugador2[J]=vecAuxiliar[J+tam];
    }

}

void mostrarVectorAcomodado(string vecNum[], int tam, int columna, int fila, string nombreJugador, int puntos[], int ronda){
    int X;
    for (X=0 ; X<=tam ; X++){
        rlutil::saveDefaultColor();
        rlutil::locate(columna,(X+fila));
        if (X==0){
            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::GREEN);
            cout << nombreJugador;
            rlutil::resetColor();
            if (ronda == 0){
                cout << ": (" << puntos[ronda] << ")";
            }else {
                cout << ": (" << puntos[ronda-1] << ")";
            }
        }else{
            cout << vecNum[X-1] << endl;
        }
    }
}

void dibujarCarta(){
    char A = 3, B = 4, C = 5, D = 6;
    ubicarTexto("*-----------------------*", 10, 7);
    dibujarUnaLineaVertical(10, 8, 28);
    rlutil::locate(19 , 18);
    cout << A << " " << B << " " << C << " " <<D;
    dibujarUnaLineaVertical(34, 8, 28);
    ubicarTexto("*-----------------------*", 10, 28);
    cout << endl << endl << endl;
}

string elegirCartaEmbaucadora(){
    const int NUM_PALOS = 4;
    string palos[NUM_PALOS] = {"Pica", "Trebol", "Corazón", "Diamante"};

    int paloIndice = tirarUnaCarta(NUM_PALOS);
    string embaucadora = palos[paloIndice];

    return embaucadora;
}

void preguntarAJugadores(string jugadorA, string jugadorB, int puntosJugadorA[], int puntosJugadorB[], int ronda, string &embaucadora){
    char respusta;
    if (puntosJugadorA[ronda-1] >= 20){
        cout << endl << jugadorA << ", ¿Desea cambiar la carta embaucadora? (S/N)" << endl;
        cin >> respusta;
        if (respusta == 'S' || respusta == 's'){
            puntosJugadorA[ronda-1] -= 20;
            embaucadora = elegirCartaEmbaucadora();
            cout << endl << "Nueva carta Embaucadora: " << embaucadora << endl;
        }else{
            cout << endl << jugadorB << ", ¿Desea cambiar la carta embaucadora? (S/N)" << endl;
            cin >> respusta;
            if (respusta == 'S' || respusta == 's'){
                puntosJugadorB[ronda-1] -= 20;
                embaucadora = elegirCartaEmbaucadora();
                cout << endl << "Nueva carta Embaucadora: " << embaucadora << endl;
            }
        }
    }else if (puntosJugadorB[ronda-1] >=20){
        cout << endl << jugadorA << " no posee los puntos suficientes para cambiar la embaucadora. " << jugadorB << ", ¿Desea cambiarla? (S/N)." << endl;
        cin >> respusta;
        if (respusta == 'S' || respusta == 's'){
            puntosJugadorB[ronda-1] -= 20;
            embaucadora = elegirCartaEmbaucadora();
            cout << endl << "Nueva carta Embaucadora: " << embaucadora << endl;
        }
    }else{
        cout << endl <<"Ambos jugadores no poseen los puntos suficientes para cambiar la carta embaucadora :(" << endl;
    }
}

//PUNTOS FUNCIONES REQUERIDAS PARA EL CONTROL DE LOS PUNTOS.

int sumarPuntos (string vec[], int tam, string embaucadora){
    int X;
    int puntos=0;
    for (X=0 ; X< tam ; X++){
        if (vec[X].find(embaucadora) == string::npos) {
            if (vec[X].find("10") != string::npos){
                puntos += 10;
            }else if(vec[X].find("J") != string::npos){
                puntos += 11;
            }else if (vec[X].find("Q") != string::npos){
                puntos += 12;
            }else if (vec[X].find("K") != string::npos){
                puntos += 15;
            }else if (vec[X].find("A") != string::npos){
                puntos += 20;
            }
        }
    }
    return puntos;
}

void mostrarPuntos(string jugador1, string jugador2, int puntosJugador1[], int puntosJugador2[], int tam){
    int totalJugador1=0, totalJugador2=0;
    int I;
    totalJugador1 = acumularVector(puntosJugador1, tam);
    totalJugador2 = acumularVector(puntosJugador2, tam);
    ubicarTexto("----------------->PUNTOS ACUMULADOS<-----------------", 1, 41);
    rlutil::locate(12, 42);
    cout << "Ronda #1    Ronda#2     Ronda#3     TOTAL" << endl;
    rlutil::locate(0, 43);
    cout <<jugador1 << ": ";
    rlutil::locate(14, 43);
    for (I=0 ; I<tam ; I++){
        cout << puntosJugador1[I] << "           ";
    }
    rlutil::locate(50, 43);
    cout << totalJugador1;
    rlutil::locate(0, 44);
    cout << endl << jugador2 << ": ";
    rlutil::locate(14, 44);
    for (I=0 ; I<tam ; I++){
        cout << puntosJugador2[I] << "           ";
    }
    rlutil::locate(50, 44);
    cout << totalJugador2;
    cout << endl;
}

//GANADORES FUNCIONES QUE SE UTILIZAN PARA MOSTRAR LOS GANADORES

void mostrarGanador(string jugador1, string jugador2, int puntosJugador1[], int puntosJugador2[], int tam, string &nombreGanador, int &puntosGanador){
    int totalPuntosJug1 = acumularVector(puntosJugador1, tam);
    int totalPuntosJug2 = acumularVector(puntosJugador2, tam);
    int maximoPuntoJug1, maximoPuntoJug2;
    if (totalPuntosJug1 > totalPuntosJug2){
        ganador(nombreGanador, jugador1, totalPuntosJug1, puntosGanador);
    }else if (totalPuntosJug1 < totalPuntosJug2){
        ganador(nombreGanador, jugador2, totalPuntosJug2, puntosGanador);
    }else{
        maximoPuntoJug1 = buscarMayorEnVector(puntosJugador1, tam);
        maximoPuntoJug2 = buscarMayorEnVector(puntosJugador2, tam);
        if(maximoPuntoJug1>maximoPuntoJug2){
            ganador(nombreGanador, jugador1, totalPuntosJug1, puntosGanador);
        }else if(maximoPuntoJug1 < maximoPuntoJug2){
            ganador(nombreGanador, jugador2, totalPuntosJug2, puntosGanador);
        }else{
            for (int X=0; X<20 ; X++){

                if (X%2 == 0){
                    rlutil::setColor(rlutil::RED);
                    rlutil::setBackgroundColor(rlutil::WHITE);
                }else{
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::setBackgroundColor(rlutil::RED);
                }
                ubicarTexto("¡¡¡ HUBO UN EMPATE !!!", 10, 5);

                rlutil::msleep(100);
            }
        }
    }
}

void ganador(string &nombreGanador, string jugador, int totalPuntos, int &puntosGanador){
    nombreGanador=jugador;
    puntosGanador=totalPuntos;
    ganadorGrafico(jugador);
}

void ganadorGrafico (string jugador){
    for (int X=0; X<20 ; X++){

        if (X%2 == 0){
            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::GREEN);
        }else{
            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
        }

        rlutil::locate(10, 5);
        cout << "¡¡¡EL/LA GANADOR/A ES " << jugador << "!!!";

        rlutil::msleep(100);
    }
}

//ESTADISTICAS FUNCIONES QUE SE UTILIZAN PARA MOSTRAR LAS ESTADISTICAS.

void cargarEnEstadistica(int vecPuntos[], string vecNombres[], int puntajeGanador, string nombreGanador){
    bool anotado= true;
    int X=0;

    while (anotado){
        if (vecNombres[X] == "\t"){
            vecNombres[X] = nombreGanador;
            anotado=false;
        }
        if (vecPuntos[X] == 0){
            vecPuntos[X] = puntajeGanador;
            anotado=false;
        }
        X++;
    }
}

void mostrarEstadistica(int vecPuntos[], string vecNombres[], int tam, int puntajeGanador, string nombreGanador){

    ubicarTexto("NOMBRE", 13, 6);
    ubicarTexto("PUNTOS", 26, 6);
    ubicarTexto("-------------------------", 10, 7);
    dibujarUnaLineaVertical(22, 6, 18);

    for (int X=0; X<tam ; X++){
        if (vecNombres[X] != "\t" && vecPuntos[X] != 0){
            rlutil::locate(12, X+8);
            cout << vecNombres[X] << ": ";
            rlutil::locate(26, X+8);
            cout << vecPuntos[X];
        }
    }

}
