# Proyecto: ARREGLO COSMICO
Mi proyecto consiste en distintos algoritmos de busqueda y ordenamiento los cuales trabajaran con una lsita de planetas para buscar y desplegar en pantalla diversas características de estos como puede ser la distancia en unidades astronómicas, la fuerza gravitacional, la masa del planeta, su díametro, temperatura, humedad, etc. Además de que se le pueden agregar otras variables como puede ser el bioma predominante, la fauna, los materiales y recursos del planeta.

Tambien cuenta con un registro de los viajes espaciales que se han realizado en una lista doblemente ligada, los cuales puedes consultarlos desde el mas antiguo hasta el mas nuevo, asi como un archivo txt el cual funciona como registro de pasajeros, dentro del codigo se puede registrar personas las cuales se guardaran en el txt, se puede mostrar en pantalla y tambien se puede eliminar los datos de un pasajero al buscarlo por su nombre.

## Descripción del avance 1
En el primer avance se definio el objetivo del proyecto a la par se realizo el documento markdown y se realizo una primera version del codigo en la cual solo se utiliza el algoritmo de bubble sort, en la version final, cuando la base de datos sea mas grande se utilizara quick sort y la busqueda binaria.

## Descripción del avance 2
En este segundo avance se implementa la estructura de una lista doblemente ligada para introducir una nueva funcion al código la cual consiste en mostrar las misiones espaciales que se han implementado a lo largo de la historia, estas se desplegaran y tendran la posibilidad de dezplazarse a lo largo de la lista para poder ver cada nodo que contenga.

### Cambios sobre el primer avance
1. Implementacion de la lista doblemente ligada para los viajes espaciales que se han realizado.
2. Elimine la clase orden.h debido a que el sort ya esta dentro del main.

## Descripción del avance 3
En este tercer avance se implementa la modificacion de una base de datos, en este caso un archivo txt con el registro de pasajeros, este archivo se puede editar desde la consola registrando a un nuevo pasajero asi como eliminarlo buscandolo por su nombre. Ademas contiene una funcion que despliega en consola el contenido del archivo txt en ese momento por lo cual se puede comprobar que se añada o elimine al pasajero. 

### Cambios sobre el segundo avance
1. Implementacion de un registro de pasajeros el cual es modificable al agregar y eliminar cualquier registro.
2. Añadi un salto de linea al mostrar la informacion para facilitar la legibilidad.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./a.out` 

## Descripción de las entradas del avance de proyecto
El proyecto requiere de varios txt para la creacion del arreglo de vectores de los planetas, la lista doblemente ligada de las misiones espaciales y el registro de pasajeros. Por otra parte para el registro de pasajeros se reqiuere que el usuario introdusca en la terminal el Nombre, el Planeta destino, la edad del pasajero y el no. de pasajeros que van con esa pasajeros(en caso de ir solo el numero de pasajeros es 1); un ejemplo para el registro de pasajeros seria:

Nombre : Pepe
Planeta destino: Marte
Edad : 19
No. de pasajeros: 1

Nombre : Raymundo
Planeta destino: SqlWorld
Edad : 25
No. de pasajeros: 1

## Descripción de las salidas del avance de proyecto
El programa imprimira en pantalla un menu en el cual el usuario decidira como se despliega la base de datos de los planetas, que caracteristica cuantificable es la que se busca, masa, disncia, diametro, etc; y los imprimira en orden que el usuario decida, de mayor a menor o de menor a mayor, asi como buscara planetas con las caracteristicas especificas que busca el usuario o las mas parecidas. Ademas tiene una opcion para que despliegue la base de datos original.

La segunda funcion del codigo despliega la informacion de la mision espacial en la que se encuentre el nodo de la lista doblementeligada, esta funcion ira desplegando la informacion de una sola mision en lugar de todas a la vez, el usuario podra decidir si pasar a la siguiente o regresar a la anterior.

La tercer funcion del codigo tiene como fin el registro de pasajeros por lo cual  ademas de la modificacion de la base de datos del registro, tiene la opcion de desplegar la informacion que tiene en el momento.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

La complejidad de bubble sort dependera de varios factores como puede ser el estado inicial de  mi base de datos asi como su tamaño, en este caso como no es tan grande considero que el nivel de complejidad del algoritmo de busqueda es un caso promedio en la cual tiene un nivel de complejidad tipo O(n^2), ya que mi base de datos esta un poco desordenada pero no llega al peor de los casos en los que mi base de datos estaria completamente al revez sin embargo la complejidad seria siendo la misma. El unico caso en el que se puede simplificar la complejidad seria donde el orden original de la lista simplifique o ayude al bubble sort, en el caso en el que la lista ya este ordenada el programa solo verificaria la lista por lo que su complejidad seria de O(n).


#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

Debido a que las funciones que utilizo para la base de datos recorren el archivo linea por linea tanto para la lectura como a la hora de desplegar la informacion; estas tienen un nivel de complejidad O(n). De igual manera las funciones de busqueda y eliminacion de pasajeros recorren todo el archivo para encontrar a la victima o encontrar y desplegar al pasajero.


#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

La complejidad de cada funcion del programa se encuentra comentada en el codigo. Debido a que la 
 funcion de mayor complejidad, la cual es el bubble sort,  es O(n^2), la comlejidad final del programa seria esta misma.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Puesto que mi base de datos no es muy grande  y estos algoritmos son de los mas rapidos, los considere como los mejores candidatos dentro del grupo que aprendimos en la clase, es por esta razon que son los que planeo emplear en mi proyecto. Debido a que bubble sort es muy facil de implementar y trabaja bien con arreglos pequeños, y por otra parte quick sort trabaja bien con arreglos mas grandes, por la naturaleza de mi proyecto se le pueden añadir mas variables lo que aumentaria el tamaño de la lista y por lo tanto la complejidad al ordenarla, al utilizar ambos algoritmos procuro cubrir ambos casos en los que se pueda ser mas complejo o no mi arreglo.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Las estructura de datos seleccionada es una lista doblemente ligada ya que mi funcion tiene como objetivo el desplegar una mision a la vez de la base de datos y no todo el archivo. Por lo cual esta estructura resulta conveniente ya que solo despliega la informacion que haya en el nodo actual y debido a los apuntadores que tiene hacia la siguiente y la anterior localidad de memoria, el usuario se puede mover facilmente a travez de la base de datos.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Considero que en las primeras 2 funciones en las que se utiliza un arreglo de vectores y una lista doblemente ligada, de las cuales sus nodos o vectores se crean con la informacion de la base de datos, se logra esta competencia. Esto debido a que hay funciones especificas para ambas funciones para consultar la informacion que tiene cada uno de sus componentes, como son las funciones "disp()" y "muestra()".

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Mis bases de datos de las cuales surgen mi arreglo de vectores y mi lista doblemente ligada estan en archivos .txt, mi codigo lee el archivo y crea los objetos correspondientes simultaneamente utilizando un ciclo while, el cual tiene como funcion que se creen estos objetos hasta que se llegue al final de los .txt, por lo que, puedo aumentar ambas bases de datos y mi codigo deberia seguir funcionando.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Considero que en la nueva funcion "Pasajeros", se logra la competencia debido a que registra la informacion que se le de en la terminal, se puede comprobar que esta se registro en la base de datos guardando la estructura actual en la base de datos y despues buscando con el nombre al pasajero, de igual manera buscandolo por el nombre se puede eliminar especificamente un registro, por lo cual considero que es clara la manipulacion del archivo que tiene la base de datos de los pasajeros