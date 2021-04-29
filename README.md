## Вступительное задание Smart Engines

### Задача
Дан массив A из N элементов (N <= 10<sup>6</sup>), все элементы A<sub>i</sub> – неотрицательные целые числа, не превышающие 10^6. Найти любую пару индексов L, R  (L <= R) таких, что сумма элементов на отрезке массива A<sub>L</sub> + … + A<sub>R</sub> делится нацело на N. Доказать, что такая пара индексов всегда существует.

### Решение
Пусть S<sub>i</sub>=(A<sub>0</sub>+...+A<sub>i</sub>) mod N - префиксная сумма по модулю N. Всего непустых префиксных сумм N. Различных возможных значений - N (от 0 до N-1). Тогда возможны два варианта:
1) &exist;i&in;[0, N-1] S<sub>i</sub>=0. Тогда ответ - [0, i]
2) Оставшихся возможных значений N-1, всего сумм N. Тогда по принципу Дирихле 

   &exist;i,j&in;[0, N-1] i < j: S<sub>i</sub>=S<sub>j</sub>
   
   0=S<sub>j</sub>-S<sub>i</sub>=A<sub>i+1</sub>+...+A<sub>j</sub>
   
   Тогда ответ [i+1, j]

### Сборка
Из корневой директории
```bash
mkdir build
cd build
cmake ..
make
```
### Запуск
Для запуска решения из директории build
```bash
./run
```
Для запуска тестов из директории build
```bash
./test
```