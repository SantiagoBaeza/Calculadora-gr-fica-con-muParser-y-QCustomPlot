#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <cmath>
#include "muParser.h"

// Constructor de la ventana principal
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this); // Inicializa la interfaz gráfica definida en el archivo .ui

    // Conecta los botones de la interfaz con las funciones (slots)
    connect(ui->Plotboton, &QPushButton::clicked, this, &MainWindow::plot);
    connect(ui->RaicesBoton, &QPushButton::clicked, this, &MainWindow::buscarRaices);
}

// Destructor: libera la memoria reservada para la interfaz
MainWindow::~MainWindow() {
    delete ui;
}

// Función que evalúa la expresión matemática escrita por el usuario en el campo "Funcion"
double MainWindow::evaluarFuncion(double x) {
    mu::Parser parser; // Crea un parser de muParser (parser es uan especie de "analizador" que transforma el texto en operaciones matematicas)
    parser.DefineVar(L"x", &x); // Define la variable 'x' para que pueda usarse en la expresión
    parser.SetExpr(ui->Funcion->text().toStdWString()); // Toma la función escrita en el campo de texto
    return parser.Eval(); // Evalúa la función en el valor x
}

// Slot que grafica la función en el rango [xmin, xmax]
void MainWindow::plot() {
    int N = ui->N->text().toInt();              // Número de puntos
    double xmin = ui->Xmin->text().toDouble();  // Límite inferior
    double xmax = ui->Xmax->text().toDouble();  // Límite superior
    double dx = (xmax - xmin) / (double)N;      // Paso entre puntos

    QVector<double> x(N), y(N); // Vectores para guardar los puntos
    for (int i = 0; i < N; ++i) {
        x[i] = xmin + i * dx;            // Calcula cada punto en X
        y[i] = evaluarFuncion(x[i]);     // Evalúa la función en ese punto
    }

    // Configura el gráfico en QCustomPlot
    ui->plot->clearGraphs();             // Limpia gráficos anteriores
    ui->plot->addGraph();                // Agrega un nuevo gráfico
    ui->plot->graph(0)->setPen(QPen(Qt::blue)); // Color azul para la curva
    ui->plot->graph(0)->setData(x, y);   // Asigna los datos calculados
    ui->plot->rescaleAxes();             // Ajusta los ejes al rango de datos
    ui->plot->replot();                  // Redibuja el gráfico
}

// Slot que busca raíces de la función en el rango [xmin, xmax]
void MainWindow::buscarRaices() {
    double xmin = ui->Xmin->text().toDouble();  // Límite inferior
    double xmax = ui->Xmax->text().toDouble();  // Límite superior
    int N = ui->N->text().toInt();              // Número de intervalos
    double dx = (xmax - xmin) / N;              // Paso entre intervalos
    double tol = 1e-6;                          // Tolerancia para el método de bisección

    QVector<double> raices; // Vector para guardar las raíces encontradas
    for (int i = 0; i < N - 1 && raices.size() < 2; ++i) {
        double xi = xmin + i * dx;   // Extremo izquierdo del intervalo
        double xd = xi + dx;         // Extremo derecho del intervalo
        double fxi = evaluarFuncion(xi);
        double fxd = evaluarFuncion(xd);

        // Si hay cambio de signo, hay raíz en el intervalo
        if (fxi * fxd < 0) {
            // Método de bisección para aproximar la raíz
            while (fabs(xd - xi) > tol) {
                double xm = (xi + xd) / 2.0; // Punto medio
                double fxm = evaluarFuncion(xm);
                if (fxi * fxm < 0)
                    xd = xm; // La raíz está en [xi, xm]
                else
                    xi = xm; // La raíz está en [xm, xd]
            }
            double raiz = (xi + xd) / 2.0; // Aproximación final de la raíz
            raices.append(raiz);           // Guarda la raíz encontrada
        }
    }

    // Muestra las raíces encontradas en la interfaz (hasta 2 raíces)
    if (raices.size() > 0)
        ui->raiz1->setText(QString::number(raices[0], 'g', 10));
    else
        ui->raiz1->setText("No encontrada");

    if (raices.size() > 1)
        ui->raiz2->setText(QString::number(raices[1], 'g', 10));
    else
        ui->raiz2->setText("No encontrada");
}
