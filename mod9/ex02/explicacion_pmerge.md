# Explicación del ejercicio PmergeMe

## Qué hace este programa

Este programa implementa una variante del algoritmo de ordenación conocido como Ford-Johnson (también llamado merge-insert sort) sobre dos contenedores diferentes: `std::vector<int>` y `std::deque<int>`. La idea principal es ordenar números usando comparaciones controladas y medir cuántas comparaciones se realizan.

El objetivo de la práctica es comparar dos estructuras de datos y ver cómo se comporta el algoritmo en cada una de ellas.

---

## Estructura de la clase PmergeMe

La clase `PmergeMe` guarda:

- `_v_con`: un `std::vector<int>` que representa la secuencia que se ordena.
- `_de_con`: un `std::deque<int>` con los mismos datos.
- `_vectorComparisons` y `_dequeComparisons`: contadores de comparaciones.
- `hasleftover` y `leftover`: se usan para gestionar el caso en que haya un valor sin pareja al formar grupos de dos.
- `pairlist`, `mainChain` y `pend`: se usan en la lógica de pares del algoritmo, aunque en la implementación actual el flujo principal se apoya más directamente en los contenedores.

La clase también expone métodos para cargar valores, ordenar, imprimir y consultar los contadores.

---

## Qué hace cada función

### 1) `buildJacobsthalOrder(size_t count)`

Esta función genera un orden de inserción para los elementos del grupo `minors` usando una secuencia de Jacobsthal.

#### ¿Qué hace?

1. Crea un `std::vector<size_t>` llamado `order` que almacenará los índices que deben insertarse.
2. Genera la secuencia de Jacobsthal, que empieza con `1, 1, 3, 5, 11, 21, ...`.
3. Usa esos valores para recorrer el rango de índices desde el final hacia atrás, tomando posiciones en un orden especial.
4. Marca los índices ya usados con un `std::vector<bool>` llamado `used` para no repetirlos.
5. Al final, añade los índices que no hayan sido cubiertos.

#### ¿Por qué existe?

Porque el algoritmo de Ford-Johnson no inserta los elementos en orden natural. El orden de inserción afecta directamente a cuántas comparaciones se hacen. La secuencia de Jacobsthal se usa para intentar reducir las comparaciones al insertar los valores del grupo secundario (`minors`).

#### Importancia práctica

Si la secuencia se cambia, el comportamiento del algoritmo puede variar ligeramente en número de comparaciones y en la forma en la que se construye la lista ordenada.

---

### 2) `customLess(int left, int right, std::size_t &comparisons)`

Esta función compara dos valores y además cuenta cuántas comparaciones se han hecho.

#### ¿Qué hace?

- Incrementa el contador `comparisons`.
- Devuelve `left < right`.

#### ¿Por qué existe?

Porque en este ejercicio el objetivo es medir cuántas comparaciones realiza el algoritmo. En vez de usar directamente `operator<`, se sustituye por esta función para centralizar el recuento y evitar perder cuentas.

#### Ejemplo

```cpp
if (customLess(first, second, comparisons))
    std::swap(first, second);
```

Aquí se está comparando si `first` menor que `second`. Si se cumple, se intercambian para dejar el mayor como "major".

---

### 3) `printContainer(Container &con)`

Es una función plantilla que imprime el contenido de cualquier contenedor compatible con iteradores.

#### ¿Qué hace?

- Recibe una referencia al contenedor.
- Recorre todos sus elementos con un iterador.
- Los escribe en la salida estándar, separados por espacios.

#### ¿Por qué existe?

Porque el mismo código de impresión sirve tanto para `std::vector<int>` como para `std::deque<int>`. La plantilla evita duplicar código.

---

### 4) `insertWithCustomSearch(Container &container, typename Container::value_type value, std::size_t &comparisons)`

Esta función inserta un elemento en un contenedor ya ordenado usando una búsqueda lineal y contando comparaciones.

#### ¿Qué hace?

1. Empieza desde el principio del contenedor.
2. Recorre los elementos hasta encontrar el primer elemento que ya no sea menor que `value`.
3. Usa `customLess` para comparar y contar cada comparación.
4. Inserta el valor justo antes de ese punto.

#### ¿Por qué existe?

En el algoritmo de Ford-Johnson, después de formar una cadena base ordenada, se deben insertar los valores del grupo `minors` de uno en uno. Esta función hace exactamente eso: inserta cada elemento en la posición correcta, manteniendo el contenedor ordenado.

#### Importancia práctica

La inserción se hace de forma incremental, y por eso es una parte clave del algoritmo. Aquí es donde se contabilizan muchas de las comparaciones del método.

---

### 5) `fordJohnsonSortImpl(Container &container, std::size_t &comparisons)`

Es la función central del algoritmo. Implementa la parte recursiva del Ford-Johnson.

#### ¿Qué hace?

1. Si el contenedor tiene menos de dos elementos, no hace nada y termina.
2. Divide la secuencia en pares consecutivos.
3. Para cada par:
   - toma `first` y `second`;
   - si `first` es menor que `second`, los intercambia para dejar el mayor en `majors` y el menor en `minors`.
4. Recursivamente ordena `majors`.
5. Borra el contenedor actual y reconstruye la cadena con los `majors` ya ordenados.
6. Usa `buildJacobsthalOrder(minors.size())` para obtener un orden de inserción de los elementos `minors`.
7. Inserta cada uno de esos elementos en la cadena principal con `insertWithCustomSearch`.
8. Si había un elemento sin pareja, lo inserta también al final.

#### ¿Por qué existe?

Porque es la implementación concreta de la ordenación por merge-insert. Divide la entrada en elementos más grandes y más pequeños, usa la recursión para ordenar la mitad principal y, finalmente, inserta los valores menores siguiendo un orden especial para reducir el número de comparaciones.

#### Concepto clave

El algoritmo no ordena “de golpe” como un quicksort o merge sort clásico. En su lugar, construye una cadena ya ordenada poco a poco y va insertando elementos.

---

## Qué hace la ordenación de Jacobsthal

La ordenación de Jacobsthal no es una ordenación independiente; es una forma de definir el orden en que se insertan ciertos elementos durante el algoritmo Ford-Johnson.

### La secuencia de Jacobsthal

La secuencia se define normalmente como:

- `J(0) = 0`
- `J(1) = 1`
- `J(n) = J(n - 1) + 2 * J(n - 2)`

En este código se empieza desde `1, 1` para obtener una secuencia equivalente y útil para el patrón de inserción.

### ¿Por qué es útil?

Porque en el algoritmo Ford-Johnson se desea insertar primero los elementos que producen menos movimiento en la cadena ya ordenada. El orden de Jacobsthal ofrece un patrón que ayuda a equilibrar la carga de inserciones y suele reducir el número de comparaciones respecto a una inserción simple en orden natural.

### En la práctica

`buildJacobsthalOrder` genera una lista de índices que se usan para tomar elementos del vector `minors` y cargarlos en el contenedor ya ordenado. Ese orden no es el resultado final de la ordenación; es la estrategia de inserción.

---

## Qué hace el algoritmo Ford-Johnson

El algoritmo Ford-Johnson, también llamado merge-insert sort, se basa en esta idea:

1. Se forman pares de elementos consecutivos.
2. De cada par, se toma el mayor elemento como parte de una lista principal (`majors`) y el menor como una lista secundaria (`minors`).
3. Se ordena recursivamente la lista principal.
4. Se insertan los elementos de la lista secundaria en el orden adecuado usando una secuencia especial (Jacobsthal).
5. Si hay un elemento sobrante porque el número de elementos era impar, se inserta al final.

### ¿Por qué se usa?

Porque ofrece un rendimiento mejor que la inserción simple en muchos casos, especialmente cuando se trabaja con un número moderado de elementos. El algoritmo está pensado para reducir comparaciones, aunque en una implementación simple como esta, el beneficio puede ser menor que el de otros métodos más modernos.

### Ventaja del enfoque

- Mantiene una estructura parcialmente ordenada.
- Inserta los elementos en posiciones estratégicas.
- Reduce el coste de comparación frente a insertar siempre al final y luego reordenar.

### Limitación de esta implementación

La versión presente es una adaptación didáctica. Está enfocada en que el código sea legible y permita practicar el concepto de Ford-Johnson y de orden de Jacobsthal. No es una implementación completamente óptima o idéntica al algoritmo original en todos los detalles.

---

## Métodos de la clase PmergeMe

### `PmergeMe::PmergeMe()`

Es el constructor por defecto, pero está declarado como privado para impedir que se cree una instancia vacía por accidente.

### `PmergeMe::PmergeMe(const PmergeMe &to_copy)`

Constructor de copia. Copia el estado de otro objeto `PmergeMe`.

### `PmergeMe::operator=(const PmergeMe &original)`

Operador de asignación. Permite copiar todos los campos de un objeto a otro.

### `PmergeMe::PmergeMe(int ar)`

Inicializa el objeto con información sobre si el número de argumentos es par o impar, lo cual influye en si existe un elemento sobrante.

### `void makeFordJonson(int container)`

Llama a la función de ordenación sobre el contenedor adecuado:

- `VECTOR` → ordena `_v_con`
- `DEQUE` → ordena `_de_con`

Además, reinicia el contador correspondiente antes de ordenar.

### `void setVecContainer(int n)` / `void setDeqContainer(int n)`

Añaden un valor al vector o al deque correspondiente.

### `std::vector<int>& getVecContainer()` / `std::deque<int>& getDeqContainer()`

Devuelven una referencia al contenedor interno para poder inspeccionarlo desde fuera.

### `std::size_t getVectorComparisons() const` / `std::size_t getDequeComparisons() const`

Devuelven el número de comparaciones acumuladas durante el proceso de ordenación.

### `void printContainer_vec(std::vector<int> vec)` / `void printContainer_deq(std::deque<int> deq)`

Imprimen los contenidos del vector o del deque.

### `void makePairs(char** argv, int ar)`

Recorre los argumentos y forma un vector de pares de valores. En este ejercicio se usa como parte de la lógica de preparación de datos, aunque el algoritmo principal se apoya más directamente en el contenedor mismo.

### `void buildMain()`

Prepara estructuras de apoyo (`mainChain` y `pend`) a partir de `pairlist`.

### `void insertPend()`

Está declarado pero comentado en el código. Su intención era insertar los elementos del vector `pend` dentro de `mainChain`.

### `void mergeInsertFJ(std::vector<std::pair<int, int> >&pairs)`

Reordena el vector de pares mediante un bucle de comparación. En la implementación actual su utilidad es limitada y no es el punto central del sort.

---

## Resumen final

- `buildJacobsthalOrder` define el orden de inserción usando la secuencia de Jacobsthal.
- `customLess` compara y cuenta comparaciones.
- `insertWithCustomSearch` inserta un valor de forma ordenada en el contenedor.
- `fordJohnsonSortImpl` implementa la lógica recursiva del algoritmo Ford-Johnson.
- El programa usa estas piezas para ordenar un vector y un deque y medir cuántas comparaciones realiza.

La clave de este ejercicio es entender que el algoritmo no solo “ordena”, sino que también decide cómo y en qué orden se insertan los elementos para reducir el coste de comparación.
