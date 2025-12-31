#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>   // Incluye la clase base de Qt para ventanas principales

// Esto conecta con el archivo .ui que se diseña en Qt Designer.
// Qt genera automáticamente una clase Ui::MainWindow con todos los widgets.
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// Clase principal de la aplicación, hereda de QMainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT   // Macro necesaria para usar signals y slots en Qt

public:
    // Constructor: inicializa la ventana principal
    MainWindow(QWidget *parent = nullptr);
    // Destructor: libera memoria al cerrar la ventana
    ~MainWindow();

private:
    Ui::MainWindow *ui;   // Puntero a la interfaz gráfica (widgets del .ui)

    // Función privada que evalúa la función matemática en un punto x
    // (probablemente usando muParser para interpretar lo que escribe el usuario)
    double evaluarFuncion(double x);

private slots:
    // Slot que dibuja la función en el gráfico (usando QCustomPlot)
    void plot();
    // Slot que busca raíces de la función (valores de x donde f(x) = 0)
    void buscarRaices();
};

#endif // MAINWINDOW_H
