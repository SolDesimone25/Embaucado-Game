#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

using namespace std;

///GENERALES
void ubicarTexto(string texto, int columna, int fila);
void inicializarEnCero(int vec[], int tam);
void cargarVectorString(string vec[], string palabra, int tam);
int acumularVector(int vec[], int tam);
int buscarMayorEnVector(int vec[], int tam);
void dibujarUnaLineaVertical(int columna, int comienzoFila, int finFila);
///JUEGO
void registrarNombres(string &jugador1, string &jugador2);
int tirarUnaCarta(int tam);
void repartirCartas(string vecJugador1[], string vecJugador2[], int tam);
void mostrarVectorAcomodado(string vecNum[], int tam, int columna, int fila, string nombreJugador, int puntos[], int ronda);
void dibujarCarta();
string elegirCartaEmbaucadora();
void preguntarAJugadores(string jugadorA, string jugadorB, int puntosJugadorA[], int puntosJugadorB[], int ronda, string &embaucadora);
///PUNTOS
int sumarPuntos (string vec[], int tam, string embaucadora);
void mostrarPuntos(string jugador1, string jugador2, int puntosJugador1[], int puntosJugador2[], int tam);
///GANADORES
void mostrarGanador(string jugador1, string jugador2, int puntosJugador1[], int puntosJugador2[], int tam, string &nombreGanador, int &puntosGanador);
void ganador(string &nombreGanador, string jugador, int totalPuntos, int &puntosGanador);
void ganadorGrafico (string jugador);
///ESTADISTICA
void cargarEnEstadistica(int vecPuntos[], string vecNombres[], int puntajeGanador, string nombreGanador);
void mostrarEstadistica(int vecPuntos[], string vecNombres[], int tam, int puntajeGanador, string nombreGanador);

#endif // FUNCION_H_INCLUDED
