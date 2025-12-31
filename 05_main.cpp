#include "mainwindow.h"   // Incluye la definición de la clase MainWindow
#include <QApplication>   // Incluye la clase QApplication, necesaria para cualquier app Qt

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Crea el objeto QApplication, que maneja el ciclo de vida de la aplicación,
    // eventos de la interfaz gráfica, teclado, mouse, etc.
    // argc y argv permiten pasar argumentos desde la consola.

    MainWindow w;
    // Crea una instancia de tu ventana principal (la clase que se define en mainwindow.h).

    w.show();
    // Muestra la ventana en pantalla.

    return a.exec();
    // Inicia el "event loop" de Qt: un bucle que espera y procesa eventos (meeedio parecido a lo que pasa en arduino con void loop, pero no es lo mismo)
    // (clics, teclas, redibujos, señales, etc.). La aplicación corre hasta que se cierre.
}
