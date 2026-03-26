# Proyecto-Simulador-de-Base-de-Datos-de-NBA

# DSA (Data Structures and Algorithms)

### Problema 1 (Algoritmo Ordenamiento)
##### Link video: https://youtu.be/uTtlI4nVlqI
##### Link submission: https://leetcode.com/problems/buy-two-chocolates/submissions/1847867815

### Problema 2 (Estructura lineal)
##### Link video: https://youtu.be/fHiSo1eju5A
##### Link submission: https://leetcode.com/problems/time-needed-to-buy-tickets/submissions/1847876863

### Problema 3 (Estructura no lineal)
##### Link video: https://youtu.be/fTgGN63rrhs
##### Link submission: https://leetcode.com/problems/two-sum/submissions/1847881280


# Proyecto: Simulador de Base de Datos de NBA
> Este proyecto utiliza datos extraídos de la página [basketball-reference](https://www.basketball-reference.com/leagues/NBA_2025.html) siguiendo su formato de organización de listas.  
> El programa ofrece las siguientes funcionalidades:  
1. Mostrar los datos del archivo CSV (tabla de posiciones).  
2. Ordenar los datos mediante el algoritmo merge sort.  
3. Buscar un equipo por nombre utilizando búsqueda lineal.  
4. Acceder a un equipo por su ranking mediante una estructura de árbol de búsqueda binaria (BST).  
5. Insertar un nuevo equipo tanto en el árbol como en el vector.  
6. Al salir del programa, se genera o sobrescribe un archivo de texto llamado 'reporteNBA.txt', que incluye la tabla de posiciones actualizada con los equipos añadidos durante la ejecución.

## Descripción del avance 1
> Este avance implementa el algoritmo de ordenamiento merge sort para clasificar equipos según sus porcentajes de tiros de tres y dos puntos, así como el algoritmo de búsqueda lineal para localizar equipos específicos por nombre.  

## Descripción del avance 2
> Aquí se introduce una estructura de datos de árbol de búsqueda binaria (BST), utilizada para localizar equipos por su ranking. Además, se implementa la funcionalidad de insertar nuevos equipos al árbol y evaluarlos dentro del mismo.  

## Descripción del avance 3
> En este avance, se añade la función de lectura de datos externos, como los equipos añadidos durante la ejecución, para incluirlos en la impresión final. Se emplea la biblioteca `<fstream>` para realizar esta tarea, tambien se implemento un MaxHeap para las funciones relacionadas con la implementacion de la opcion de seleccionar un equipo favorito.  

## Instrucciones para compilar el avance del proyecto  
Ejecutar el siguiente comando en la terminal:  
`g++ bst.h bst.cpp NBAdata.h NBAdata.cpp main.cpp -o nba`  

## Instrucciones para ejecutar el avance del proyecto  
Ejecutar el siguiente comando en la terminal:  
`./nba`  

> Posteriormente, interactúa con el menú a través de las opciones disponibles.  

## Descripción de las entradas del avance del proyecto  
Entrada: Archivo llamado `nba_data.csv`.  
Formato: Valores separados por comas (CSV).  
Por ejemplo si te interesa saber los datos del equipo de Stephen Curry que son GDW:  
`17,Golden State Warriors,0.364,0.528,48,34,40.8,90.4,0.451,15.4,42.4,82,25.3,48.0,240.6,16.9,22.1,0.764,12.5,32.8,45.4,29.1,9.4,4.8,14.0,19.2,113.8`.  
En este proyecto solo se utilizan las 6 variables: ranking, nombre, porcentaje de tiros de tres puntos (%3P) y porcentaje de tiros de dos puntos (%2P) partidos ganados y partidos perdidos.  

## Descripción de las salidas del avance del proyecto  
**Ejemplo:**  
1. Selecciona la opción 5 (Insertar nuevo equipo) en el menú.  
2. Ingresa el nombre del equipo, por ejemplo, "Borregos QRO".  
3. Ingresa el porcentaje de triples, por ejemplo, "0.34".  
4. Ingresa el porcentaje de tiros de dos puntos, por ejemplo, "0.46".
5. Ingresa la cantidad de Victorias, por ejemplo, "12".
6. Ingresa la cantidad de Derrotas, por ejemplo, "70". 
7. Recibirás un mensaje confirmando que el equipo fue agregado.  
8. Regresa al menú principal y selecciona la opción 1 (Mostrar tabla de posiciones).  
9. Verifica que el equipo se agregó correctamente.  
10. Regresa al menú y selecciona la opción 4 (Acceder por número de ranking).  
11. Ingresa el ranking del equipo agregado, por ejemplo, "31".  
12. Verifica que los datos del equipo sean correctos.
13. Seleccione la ocion 6 para seleccionar un Favorito
14. Escoja la opcion 1
15. Ingrese el nombre del que sera su Equipo Favorito, por ejemplo:por ejemplo Golden State Warriors
16. Verifique que esta seleccionado con la opcion 2
17. Refrese al Menu Principal con la opcion 0
18. Ordenelos a su gusto con la opcion 2
19. Seleccione 3pt% con la opcion 2
20. Verifique que su equipo favorito aparece hasta arriba
21. Selecoine 0 para regresar al menu principal
22. Sal del programa seleccionando la opción 0.  
23. Al finalizar, se genera el archivo `reporteNBA.txt` con la tabla de posiciones actualizada, incluyendo el equipo "Borregos QRO con sus respectivos datos".  

---

### Desarrollo de competencias 

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
En este proyecto se utiliza el algoritmo Merge Sort para ordenar los datos obtenidos del archivo nba_data.csv. La elección de este algoritmo se fundamenta en su eficiencia y en su comportamiento consistente sin importar la distribución inicial de los datos.

Complejidad temporal de Merge Sort
Merge Sort divide el vector en mitades de manera recursiva y luego combina (merge) estas mitades ordenadas.
Este proceso genera las siguientes complejidades:

Mejor caso: O(n log n)
Caso promedio: O(n log n)
Peor caso: O(n log n)

La razón por la que los tres casos tienen la misma complejidad es que Merge Sort siempre realiza la misma cantidad de divisiones y fusiones, independientemente del orden en que lleguen los datos (ya estén ordenados, parcialmente ordenados o completamente desordenados).

Esto ocurre porque:
Dividir el vector hasta llegar a porciones de tamaño 1 produce una profundidad de árbol recursivo de log₂(n).
En cada nivel de ese árbol se realiza una fusión lineal de todos los elementos (O(n)).
Entonces, el total del trabajo es:

O(n)×O(logn)=O(nlogn)

El algoritmo **Merge Sort** es la opción más eficiente para este proyecto debido a que su proceso de dividir el vector a la mitad y combinarlo mediante fusiones lineales se mantiene constante independientemente del orden inicial de los datos, garantizando en todos los casos una complejidad de **O(n log n)**. En tu implementación, la función `merge()` copia los elementos en vectores temporales y compara uno por uno para reconstruir el subarreglo ordenado, lo que asegura que cada nivel de la recursión opere en tiempo lineal mientras la división recursiva mantiene el patrón logarítmico. Esto convierte a Merge Sort en una alternativa claramente superior frente a algoritmos básicos como **Bubble Sort, Insertion Sort o Selection Sort**, los cuales presentan tiempos **O(n²)** en el promedio y peor caso, volviéndose poco prácticos para conjuntos de datos reales como los del archivo *nba_data.csv*. Además, Merge Sort es estable y escala mejor: mientras Bubble Sort puede requerir hasta 10,000 operaciones para solo 100 elementos, Merge Sort realiza aproximadamente 664, mostrando una diferencia significativa en rendimiento. Por estas razones, Merge Sort ofrece mayor consistencia, velocidad y fiabilidad al ordenar registros de equipos de NBA, incluso cuando el volumen de información crece.


#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
**Análisis de estructuras de datos (BST):** 
>   Al buscar por ranking:  En el programa se utiliza un árbol binario de búsqueda (BST) para almacenar y acceder a los equipos por su ranking. La búsqueda dentro del árbol compara el valor buscado contra el nodo actual y decide moverse a la izquierda o a la derecha, dividiendo el espacio en cada paso. Por esta razón, cuando el árbol está equilibrado, la búsqueda se realiza en O(log n) como promedio, ya que la altura del árbol es proporcional a log₂(n). Sin embargo, si la inserción de datos ocurre en orden ascendente o descendente, el árbol se desbalancea y adopta la forma de una lista ligada, aumentando la complejidad a O(n) en el peor caso. Lo mismo ocurre para la operación de inserción: normalmente requiere O(log n) al dividir el árbol en mitades a medida que se compara el valor a insertar, pero puede degradarse a O(n) si el árbol está muy desbalanceado. Esto podría evitarse implementando un árbol AVL, donde la complejidad se mantiene siempre en O(log n) al asegurar un equilibrio automático.
>   Al agregar un equipo: Si el árbol esta equilibrado tiene complejidad de O(log n) debido a que cada inserción se realiza dividiendo el árbol en aproximadamente la mitad, ya que se compara el valor a insertar con los valores en los nodos para decidir si irá a la izquierda o derecha. si el árbol esta desequilibrado de igual manera se convierte en una lista ligada por lo tanto la complejidad es de O(n).
> Por lo tanto:
- **Búsqueda:** Al ser un BST su complejidad es de \(O(\log n)\) en promedio, ya que divide el árbol en mitades. En el peor de los casos, un árbol desbalanceado tiene complejidad \(O(n)\).  
- **Inserción:** También \(O(\log n)\) promedio y \(O(n)\) en el peor caso si el árbol está desbalanceado.
  **Nota: se podria implementar un AVL para evitar los casos donde el rbol este desequilibrado**


>   El programa también emplea un Heap para determinar los equipos favoritos mediante un sistema de prioridades. El Heap se implementa como un arreglo, donde la posición de cada nodo se controla mediante las funciones parent(), left() y right(). La inserción en el Heap requiere agregar un elemento al final y luego aplicar un proceso de “heapify up” o ajuste hacia arriba, el cual en el peor caso recorre la altura del Heap. Como la altura es logarítmica, la complejidad de inserción es O(log n).
Por otro lado, la operación más importante del Heap en tu programa —extraer el elemento con mayor prioridad— se realiza moviendo el último elemento a la raíz y aplicando “heapify down”, lo cual también recorre como máximo la altura del Heap, manteniendo una complejidad de O(log n). La construcción del Heap inicial desde un vector de elementos es O(n) gracias al proceso de build-heap, que ajusta los subárboles desde la mitad hacia la raíz. Esto garantiza que la estructura de prioridad funcione de forma eficiente, incluso cuando se manejan múltiples equipos.
> Por lo tanto:
- **Insertar:** Al ser un Heap su complejidad en el mejor de los casos es de O(1), en el promedio es de O(log n), y en el peor de los casos seria O(log n)  
- **Extraer Maximo:** También  su complejidad en el mejor de los casos es de O(1), en el promedio es de O(log n), y en el peor de los casos seria O(log n)  
- **Acceder al Maximo:** Al ser un MaxHeap todo el timepo tenemos el favorito en la parte de arriba por lo que en el mejor caso es O(1) en el caso promedio es O(1) y tambien en el peor caso es O(1).

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
**Ordenamiento:**
>   Merge sort O(n log n): el bucle externo en merge sort se ejecuta O(log n) veces, esto se debe a que en cada iteración, el tamaño del vector se divide aproximadamente a la mitad. También se realizan divisiones y fusiones repetidas, estas se ejecutan en O(n) debido a que dentro de la función auxiliar se copian elementos en vectores temporales y luego se combinan en un solo vector ordenado, Por lo que la combinación de O(log n) y O(n) = O(n log n)


### **Main**
- **Lectura de datos – `O(n · L)`**  
  Donde `n` es el número de líneas del archivo `nba_data.csv` y `L` la longitud promedio de cada línea.  
  Cada llamada a `getline()` cuesta `O(L)` y se ejecuta `n` veces → complejidad total `O(n · L)` en mejor, promedio y peor caso.

- **Escritura de datos – `O(n)`**  
  La generación del archivo `reporteNBA.txt` recorre todos los equipos almacenados en el vector.  
  El costo del ciclo es lineal → mejor caso `O(n)`, promedio `O(n)`, peor caso `O(n)`.


### **Menú**
- **Mostrar menú – `O(1)`**  
  La función `showMenu()` solo imprime texto fijo → complejidad constante en todos los casos.

### **Gestión del menú (`manageMenu`) – depende de la opción seleccionada:**

| Opción | Descripción | Mejor caso | Promedio | Peor caso |
|-------|-------------|------------|----------|-----------|
| 0 | Salir del menú | `O(1)` | `O(1)` | `O(1)` |
| 1 | Mostrar tabla completa | `O(n)` | `O(n)` | `O(n)` |
| 2 | Ordenar datos (Merge Sort) | `O(n log n)` | `O(n log n)` | `O(n log n)` |
| 3 | Buscar por nombre | `O(L)` | `O(n · L)` | `O(n · L)` |
| 4 | Acceder por número de ranking (BST) | `O(1)` | `O(log n)` | `O(n)` |
| 5 | Insertar equipo (BST + vector) | `O(1)` | `O(log n)` | `O(n)` |
| 6 | Seleccionar favorito (Heap) | `O(1)` | `O(log n)` | `O(n)` |

**Nota:** La opción 6 usa un **Heap Máximo** para obtener el “favorito” (el equipo con mayor `favoriteScore`), por lo que:
- insertar un favorito cuesta `O(log n)`
- obtener el máximo cuesta `O(1)`
- si se reordena o reconstruye el heap completo, cuesta `O(n)`.


### **Otros métodos**
- **Buscar por nombre – `O(n · L)`**  
  Se recorren `n` equipos y se compara su nombre con una cadena de longitud `L`.  
  - Mejor caso: el primer nombre coincide → `O(L)`
  - Promedio: recorrer mitad del vector → `O(n · L)`
  - Peor caso: recorrer todo el vector → `O(n · L)`

- **Convertir string a minúsculas – `O(m)`**  
  Donde `m` es el número de caracteres.  
  Un solo recorrido → `O(m)` en todos los casos.


### **Análisis de estructuras de datos**

#### **Árbol Binario de Búsqueda (BST)**
- **Búsqueda:**  
  - Mejor caso: la raíz es el nodo buscado → `O(1)`  
  - Promedio: árbol balanceado → `O(log n)`  
  - Peor caso: árbol desbalanceado (lista ligada) → `O(n)`  

- **Inserción:**  
  - Mejor caso: se inserta en la raíz o cerca → `O(1)`  
  - Promedio: `O(log n)`  
  - Peor caso: árbol desbalanceado → `O(n)`  

El BST es útil cuando se requiere acceso ordenado por claves específicas (ranking) y búsquedas rápidas sin necesidad de reordenar todo el vector. Sin embargo, si los datos llegan muy ordenados o muy desordenados, el árbol puede degenerarse.


#### **Heap Máximo (para seleccionar favorito)**
El heap se usa para obtener rápidamente el equipo favorito basado en `favoriteScore`.

- **Insertar favorito en heap:**  
  - Mejor caso: el elemento ya es el mayor → `O(1)`  
  - Promedio: acomodar con sift-up → `O(log n)`  
  - Peor caso: subir hasta la raíz → `O(log n)`  

- **Obtener favorito (máximo):**  
  - Mejor caso: siempre `O(1)`  
  - Promedio: `O(1)`  
  - Peor caso: `O(1)`  

- **Reconstruir heap completo (heapify):**  
  - Mejor caso: ya está ordenado → `O(n)`  
  - Promedio: `O(n)`  
  - Peor caso: `O(n)`  

El heap es la estructura más eficiente para obtener el elemento con mayor prioridad sin ordenar toda la lista.


### **Complejidad total del programa**
El programa completo está dominado por:
- **ordenamientos (`mergeSort`) → `O(n log n)`**
- **construcción de heap cuando se usa favoritos → `O(n)`**

Por lo tanto, la complejidad final del programa es:
- **Mejor caso:** `O(n)`  
- **Promedio:** `O(n log n)`  
- **Peor caso:** `O(n log n)`  

Ya que el merge sort es la operación más costosa y se mantiene en todos los casos.



### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
> Se eligió **Merge Sort** porque garantiza un rendimiento estable en todos los casos (`O(n log n)`), a diferencia de otros algoritmos:
> - **Bubble Sort:** siempre `O(n²)`, incluso con pocos datos, lo cual es ineficiente y escalable solo para listas pequeñas.
> - **Quick Sort:** aunque es muy rápido en promedio (`O(n log n)`), su peor caso es `O(n²)` si los datos llegan ya ordenados, lo cual puede suceder con datos reales.
> Merge Sort no tiene este problema, mantiene su complejidad incluso con datos adversos, es estable y permite ordenar repetidamente por diferentes criterios (2P%, 3P%, wins, losses).  
> Su implementación se encuentra en `mergeSort()`, `mergeSortBy2Ppercent()` y `mergeSortBy3Ppercent()` entre las líneas **221–317** de **NBAdata.cpp**.


#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Se implementaron dos estructuras principales para resolver diferentes necesidades:
> **1. Árbol Binario de Búsqueda (BST)**  
> Para acceder por número de ranking y permitir inserciones eficientes.  
> Sus operaciones tienen:
> - Mejor caso `O(1)`
> - Promedio `O(log n)`
> - Peor caso `O(n)` si se desbalancea  
> Se usa cuando se requiere acceso por una clave exacta sin ordenar toda la estructura. Funciones ubicadas en **bst.cpp**, líneas **9–49**.

> **2. Heap Máximo**  
> Para seleccionar al equipo favorito de forma eficiente.  
> Obtener el favorito siempre cuesta `O(1)`, y las inserciones solo `O(log n)`.  
> Esto es ideal para una operación frecuente como “Seleccionar Favorito”, ya que evita ordenar todo el vector.

> La combinación de BST y Heap complementa las necesidades del programa:  
> - Búsqueda jerárquica por ranking  
> - Selección óptima basada en prioridad (`favoriteScore`)



### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructuras correctos.
> El programa implementa mecanismos eficientes para consultar datos tanto en el BST como en el Heap.  
>   Con el *BST*, el acceso por ranking evita recorridos lineales y permite imprimir la información en cuanto se encuentra el nodo correspondiente.  
>   Esto se observa entre las líneas *174–186* de *NBAdata.cpp*, donde se accede solo al nodo buscado sin recorrer el árbol completo.  
>   Con el *Heap*, la consulta del equipo favorito se realiza en tiempo constante, ya que el elemento máximo se encuentra siempre en la raíz.  
>   Esto elimina la necesidad de ordenar o recorrer toda la lista para encontrar al favorito.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
> La lectura del archivo CSV está implementada entre las líneas *16–38* en main.cpp.  
> Se utiliza getline() para extraer cada campo y posteriormente almacenar los datos tanto en el vector principal como en el BST. Esto garantiza que las estructuras queden sincronizadas desde el inicio del programa.


#### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.
> La escritura del archivo .txt se lleva a cabo entre las líneas *43–52* de main.cpp.  
> Se recorre linealmente el vector y se imprimen los datos ya ordenados o modificados por el usuario, permitiendo dejar un registro persistente del procesamiento realizado.
