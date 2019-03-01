---
title: "Conceptos"
author: "Dan Yael Sajarópulos Verdugo"
lang: es
---

# Sistema de control

Un sistema de control es un conjunto de dispositivos encargados de administrar, ordenar, dirigir o regular el comportamiento de otro sistema, con el fin de reducir las probabilidades de fallo y obtener los resultados deseados. Por lo general, se usan sistemas de control industriales en procesos de producción industriales para controlar equipos o máquinas.

El control automático de procesos es una de las disciplinas que se ha desarrollado a una velocidad vertiginosa, dando las bases a lo que hoy algunos autores llaman la segunda revolución industrial. El uso intensivo de las técnicas del control automático de procesos tiene como origen la evolución y tecnificación de las tecnologías de medición y control aplicadas al ambiente industrial. Su estudio y aplicación ha contribuido al reconocimiento universal de sus ventajas y beneficios asociados al ámbito industrial, que es donde tiene una de sus mayores aplicaciones debido a la necesidad de controlar un gran número de variables, sumado esto a la creciente complejidad de los sistemas. El control automático de procesos se usa fundamentalmente porque reduce el costo asociado a la generación de bienes y servicios, incrementa la calidad y volúmenes de producción de una planta industrial entre otros beneficios asociados con su aplicación.

# Clasificación de los sistemas de control

## Lazo abierto

Sistema de control de lazo abierto

Es aquel sistema en que solo actúa el proceso sobre la señal de entrada y da como resultado una señal de salida independiente a la señal de entrada, pero basada en la primera. Esto significa que no hay realimentación hacia el controlador para que éste pueda ajustar la acción de control. Es decir, la señal de salida no se convierte en señal de entrada para el controlador.

* Ejemplo 1: Un tanque con una manguera de jardín. Mientras que la llave siga abierta, el agua fluirá. La altura del agua en el tanque no puede hacer que la llave se cierre y por tanto no nos sirve para un proceso que necesite de un control de contenido o concentración.
* Ejemplo 2: Al hacer una tostada, lo que hacemos es controlar el tiempo de tostado de ella misma entrando una variable (en este caso el grado de tostado que queremos). En definitiva, el que nosotros introducimos como parámetro es el tiempo.

Estos sistemas se caracterizan por:

*  Ser sencillos y de fácil concepto.
*  Nada asegura su estabilidad ante una perturbación.
*  La salida no se compara con la entrada.
*  Ser afectado por las perturbaciones. Estas pueden ser tangibles o intangibles.
*  La precisión depende de la previa calibración del sistema.

## Lazo cerrado

Son los sistemas en los que la acción de control está en función de la señal de salida. Los sistemas de circuito cerrado usan la realimentación desde un resultado final para ajustar la acción de control en consecuencia.

El control en lazo cerrado es imprescindible cuando se da alguna de las siguientes circunstancias:

* Cuando un proceso no es posible de regular por el hombre.
* Una producción a gran escala que exige grandes instalaciones y el hombre no es capaz de manejar.
* Vigilar un proceso es especialmente difícil en algunos casos y requiere una atención que el hombre puede perder fácilmente por cansancio o despiste, con los consiguientes riesgos que ello pueda ocasionar al trabajador y al proceso.

Sus características son:

* Ser complejos, pero amplios en cantidad de parámetros.
* La salida se compara con la entrada y le afecta para el control del sistema.
* Su propiedad de retroalimentación.
* Ser más estable a perturbaciones y variaciones internas.

# Tipos de sistemas de control

1.- Hechos por el hombre. Como los sistemas eléctricos o electrónicos que están permanentemente capturando señales del estado del sistema bajo su control y que al detectar una desviación de los parámetros preestablecidos del funcionamiento normal del sistema, actúan mediante sensores y actuadores, para llevar al sistema de vuelta a sus condiciones operacionales normales de funcionamiento. Un claro ejemplo de este será un termostato, el cual capta consecutivamente señales de temperatura. En el momento en que la temperatura desciende o aumenta y sale del rango, este actúa encendiendo un sistema de refrigeración o de calefacción.


1.1. Por su causalidad pueden ser: causales y no causales. Un sistema es causal si existe una relación de causalidad entre las salidas y las entradas del sistema, más explícitamente, entre la salida y los valores futuros de la entrada.


1.2. Según el número de entradas y salidas del sistema, se denominan:por su comportamiento

1.2.1. De una entrada y una salida o SISO (single input, single output).

1.2.2. De una entrada y múltiples salidas o SIMO (single input, multiple output).

1.2.3. De múltiples entradas y una salida o MISO (multiple input, single output).

1.2.4. De múltiples entradas y múltiples salidas o MIMO (multiple input, multiple output).


1.3. Según la ecuación que define el sistema, se denomina:

1.3.1. Lineal, si la ecuación diferencial que lo define es lineal.

1.3.2. No lineal, si la ecuación diferencial que lo define es no lineal.


1.4.Las señales o variables de los sistema dinámicos son función del tiempo. Y de acuerdo con ello estos sistemas son:

1.4.1. De tiempo continuo, si el modelo del sistema es una ecuación diferencial, y por tanto el tiempo se considera infinitamente divisible. Las variables de tiempo continuo se denominan también analógicas.

1.4.2. De tiempo discreto, si el sistema está definido por una ecuación por diferencias. El tiempo se considera dividido en períodos de valor constante. Los valores de las variables son digitales (sistemas binario, hexadecimal, etc), y su valor solo se conoce en cada período.

1.4.3. De eventos discretos, si el sistema evoluciona de acuerdo con variables cuyo valor se conoce al producirse un determinado evento.


1.5. Según la relación entre las variables de los sistemas, diremos que:

1.5.1. Dos sistemas están acoplados, cuando las variables de uno de ellos están relacionadas con las del otro sistema.

1.5.2. Dos sistemas están desacoplados, si las variables de ambos sistemas no tienen ninguna relación.


1.6. En función de la evolución de las variables de un sistema en el tiempo y el espacio, pueden ser:

1.6.1. Estacionarios, cuando sus variables son constantes en el tiempo y en el espacio.

1.6.2. No estacionarios, cuando sus variables no son constantes en el tiempo o en el espacio.


1.7. Según sea la respuesta del sistema (valor de la salida) respecto a la variación de la entrada del sistema:

1.7.1. El sistema se considera estable cuando ante cualquier señal de entrada acotada, se produce una respuesta acotada de la salida.

1.7.2. El sistema se considera inestable cuando existe por lo menos una entrada acotada que produzca una respuesta no acotada de la salida.


1.8. Si se comparan o no, la entrada y la salida de un sistema, para controlar esta última, el sistema se denomina:

1.8.1. Sistema en lazo abierto, cuando la salida para ser controlada, no se compara con el valor de la señal de entrada o señal de referencia.

1.8.2. Sistema en lazo cerrado, cuando la salida para ser controlada, se compara con la señal de referencia. La señal de salida que es llevada junto a la señal de entrada, para ser comparada, se denomina señal de feedback o de retroalimentación.


1.9. Según la posibilidad de predecir el comportamiento de un sistema, es decir su respuesta, se clasifican en:

1.9.1. Sistema determinista, cuando su comportamiento futuro es predecible dentro de unos límites de tolerancia.

1.9.2. Sistema estocástico, si es imposible predecir el comportamiento futuro. Las variables del sistema se denominan aleatorias.


2.- Naturales, incluyendo sistemas biológicos. Por ejemplo, los movimientos corporales humanos como el acto de indicar un objeto que incluye como componentes del sistema de control biológico los ojos, el brazo, la mano, el dedo y el cerebro del hombre. En la entrada se procesa el movimiento y la salida es la dirección hacia la cual se hace referencia.


3.- Cuyos componentes están unos hechos por el hombre y los otros son naturales. Se encuentra el sistema de control de un hombre que conduce su vehículo. Este sistema está compuesto por los ojos, las manos, el cerebro y el vehículo. La entrada se manifiesta en el rumbo que el conductor debe seguir sobre la vía y la salida es la dirección actual del automóvil. Otro ejemplo puede ser las decisiones que toma un político antes de unas elecciones. Este sistema está compuesto por ojos, cerebro, oídos, boca. La entrada se manifiesta en las promesas que anuncia el político y la salida es el grado de aceptación de la propuesta por parte de la población.


4.- Un sistema de control puede ser neumático, eléctrico, mecánico o de cualquier tipo, su función es recibir entradas y coordinar una o varias respuestas según su lazo de control (para lo que está programado).


5.- Control predictivo, son los sistemas de control que trabajan con un sistema predictivo, y no activo como el tradicional ( ejecutan la solución al problema antes de que empiece a afectar al proceso). De esta manera, mejora la eficiencia del proceso contrarrestando rápidamente los efectos.

# Características

* Señal de Corriente de Entrada: Considerada como estímulo aplicado a un sistema desde una fuente de energía externa con el propósito de que el sistema produzca una respuesta específica.
* Señal de Corriente de Salida: Respuesta obtenida por el sistema que puede o no relacionarse con la respuesta que implicaba la entrada.
* Variable Manipulada: Es el elemento al cual se le modifica su magnitud, para lograr la respuesta deseada. Es decir, se manipula la entrada del proceso.
* Variable Controlada: Es el elemento que se desea controlar. Se puede decir que es la salida del proceso.
* Conversión: Mediante receptores se generan las variaciones o cambios que se producen en la variable.
* Variaciones Externas: Son los factores que influyen en la acción de producir un cambio de orden correctivo.
* Fuente de Energía: Es la que entrega la energía necesaria para generar cualquier tipo de actividad dentro del sistema.
* Retroalimentación: La retroalimentación es una característica importante de los sistemas de control de lazo cerrado. Es una relación secuencial de causas y efectos entre las variables de estado. Dependiendo de la acción correctiva que tome el sistema, este puede apoyar o no una decisión, cuando en el sistema se produce un retorno se dice que hay una retroalimentación negativa; si el sistema apoya la decisión inicial se dice que hay una retroalimentación positiva.
* Variables de fase: Son las variables que resultan de la transformación del sistema original a la forma canónica controlable. De aquí se obtiene también la matriz de controlabilidad cuyo rango debe ser de orden completo para controlar el sistema. 
