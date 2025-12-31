[⬅️ Volver a "Proyectos con Qt"](https://github.com/SantiagoBaeza/proyectos-con-Qt/tree/main)

# Calculadora gráfica con muParser y QCustomPlot

Este proyecto implementa una calculadora gráfica en **Qt** que permite evaluar funciones matemáticas ingresadas por el usuario, graficarlas en un rango definido y buscar raíces mediante el método de bisección.  
Se integraron las librerías externas **muParser** y **QCustomPlot** mediante DLL, configurando el proyecto para enlazar los archivos necesarios y lograr una interfaz interactiva.

---

## Contexto

Este ejercicio corresponde a una práctica avanzada en la integración de librerías externas dentro de Qt.  
El objetivo principal fue combinar el análisis de expresiones matemáticas con **muParser** y la representación gráfica con **QCustomPlot**, reforzando conocimientos sobre:

- Manejo de DLLs en proyectos Qt.  
- Conexión de botones a funciones específicas mediante señales y slots.  
- Implementación de algoritmos numéricos (método de bisección) para encontrar raíces.  

---

## Capturas

- **Captura 01**: Interfaz principal con la función ingresada y el gráfico generado.  
  ![Interfaz](https://github.com/SantiagoBaeza/Calculadora-gr-fica-con-muParser-y-QCustomPlot/blob/main/01_captura.jpg)

---

## Funcionalidad

- Ingreso de funciones matemáticas en un campo de texto (`sin(x)`, `x^2 - 4`, etc.).  
- Graficado dinámico en el rango `[Xmin, Xmax]` con número de puntos configurable.  
- Búsqueda de hasta dos raíces en el rango mediante el método de bisección.  
- Visualización de resultados en la interfaz (gráfico y valores de raíces).  
- Ajuste automático de ejes con `rescaleAxes()` y actualización con `replot()`.  

---

## Tecnologías utilizadas

- Qt (C++), señales y slots.  
- Librería externa: **muParser** (DLL).  
- Librería externa: **QCustomPlot** (DLL).  
- Widgets: QPushButton, QLineEdit, QLabel, QCustomPlot.  
- Configuración de proyecto con `.pro` para enlazar librerías externas.  

---

## Comentarios finales

Los archivos del proyecto están incluidos en este repositorio para que cualquier persona pueda descargarlos y compilarlos localmente en **Qt** con las librerías **muParser** y **QCustomPlot**.  
De esta manera, es posible revisar el código, ejecutar la aplicación y comprobar tanto la integración de las DLL como la generación de gráficos y el cálculo de raíces. Se agrego la carpeta [QtParserPlot.zip](https://github.com/SantiagoBaeza/Calculadora-gr-fica-con-muParser-y-QCustomPlot/blob/main/QtParserPlot.zip) la cual contiene la DLL de QCustomPlot y tambien contiene las de MuParser las cuales se van a usar en el futuro, con el fin de que esta DLL sea reutilizable las coloque ambas en el mismo lugar, esa carpeta se debe colocar junto a las carpetas del disco local C: (del ordenador) para acceder desde el codigo ahi.

Este ejercicio tiene como objetivo servir de práctica en la **visualización de funciones matemáticas con Qt**, reforzar el manejo de librerías externas y dejar registro de mis avances en programación gráfica y numérica.

---

> 🧩 Estos espacios están en construcción y se actualizan de forma frecuente.
