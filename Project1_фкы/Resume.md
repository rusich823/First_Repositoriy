# Лабораторная работа №1. Задача коммивояжера

## 1. Что сделано
* **Точный алгоритм (полный перебор):** Фиксируем город 0 как стартовый. С помощью перебора всех перестановок остальных городов (используя `std::next_permutation`) находим глобально самый короткий (`Min`) и самый длинный (`Max`) маршруты. Измеряем чистое время работы алгоритма через `std::chrono`.
* **Метрика качества:** Рассчитывается по формуле:
  `Quality = (Max_Exact - Greedy_Cost) / (Max_Exact - Min_Exact) * 100%`
  Где 100% означает, что жадный алгоритм нашел идеальный кратчайший путь, а 0% — худший из возможных.

---

## 2. Результаты тестов

### Тест 1. Ограниченный разброс стоимостей (от 10 до 100)

```text
Dimension: 4x4
  Run #1 | Exact [Min: 145, Time: 0.000s] | WorstRow [Cost: 145, Time: 0.000s] | Quality: 100.0%
  Run #2 | Exact [Min: 119, Time: 0.000s] | WorstRow [Cost: 119, Time: 0.000s] | Quality: 100.0%
  Run #3 | Exact [Min: 129, Time: 0.000s] | WorstRow [Cost: 135, Time: 0.000s] | Quality: 94.2%
  Run #4 | Exact [Min: 129, Time: 0.000s] | WorstRow [Cost: 129, Time: 0.000s] | Quality: 100.0%

Dimension: 6x6
  Run #1 | Exact [Min: 162, Time: 0.000s] | WorstRow [Cost: 182, Time: 0.000s] | Quality: 91.5%
  Run #2 | Exact [Min: 202, Time: 0.000s] | WorstRow [Cost: 202, Time: 0.000s] | Quality: 100.0%
  Run #3 | Exact [Min: 196, Time: 0.000s] | WorstRow [Cost: 215, Time: 0.000s] | Quality: 89.1%
  Run #4 | Exact [Min: 178, Time: 0.000s] | WorstRow [Cost: 190, Time: 0.000s] | Quality: 93.6%

Dimension: 8x8
  Run #1 | Exact [Min: 287, Time: 0.001s] | WorstRow [Cost: 312, Time: 0.000s] | Quality: 92.4%
  Run #2 | Exact [Min: 263, Time: 0.000s] | WorstRow [Cost: 263, Time: 0.000s] | Quality: 100.0%
  Run #3 | Exact [Min: 212, Time: 0.000s] | WorstRow [Cost: 240, Time: 0.000s] | Quality: 88.5%
  Run #4 | Exact [Min: 242, Time: 0.000s] | WorstRow [Cost: 251, Time: 0.000s] | Quality: 96.1%

Dimension: 10x10
  Run #1 | Exact [Min: 223, Time: 0.086s] | WorstRow [Cost: 254, Time: 0.000s] | Quality: 91.2%
  Run #2 | Exact [Min: 211, Time: 0.085s] | WorstRow [Cost: 211, Time: 0.000s] | Quality: 100.0%
  Run #3 | Exact [Min: 219, Time: 0.086s] | WorstRow [Cost: 238, Time: 0.000s] | Quality: 91.8%
  Run #4 | Exact [Min: 218, Time: 0.086s] | WorstRow [Cost: 229, Time: 0.000s] | Quality: 95.4%

Dimension: 12x12
  Run #1 | Exact [Min: 211, Time: 10.657s] | WorstRow [Cost: 243, Time: 0.000s] | Quality: 92.8%
  Run #2 | Exact [Min: 255, Time: 10.673s] | WorstRow [Cost: 280, Time: 0.000s] | Quality: 91.1%
  Run #3 | Exact [Min: 262, Time: 10.859s] | WorstRow [Cost: 262, Time: 0.000s] | Quality: 100.0%
  Run #4 | Exact [Min: 260, Time: 10.913s] | WorstRow [Cost: 291, Time: 0.000s] | Quality: 89.5%
  ```


### Тест 2. Большой разброс стоимостей (от 10 до 1000)

```text
Dimension: 4x4
  Run #1 | Exact [Min: 1478, Time: 0.000s] | WorstRow [Cost: 1478, Time: 0.000s] | Quality: 100.0%
  Run #2 | Exact [Min: 1446, Time: 0.000s] | WorstRow [Cost: 1510, Time: 0.000s] | Quality: 96.3%
  Run #3 | Exact [Min: 1662, Time: 0.000s] | WorstRow [Cost: 1662, Time: 0.000s] | Quality: 100.0%
  Run #4 | Exact [Min: 1247, Time: 0.000s] | WorstRow [Cost: 1312, Time: 0.000s] | Quality: 94.8%

Dimension: 6x6
  Run #1 | Exact [Min: 1613, Time: 0.000s] | WorstRow [Cost: 1720, Time: 0.000s] | Quality: 93.1%
  Run #2 | Exact [Min: 921,  Time: 0.000s] | WorstRow [Cost: 921,  Time: 0.000s] | Quality: 100.0%
  Run #3 | Exact [Min: 1543, Time: 0.000s] | WorstRow [Cost: 1680, Time: 0.000s] | Quality: 90.5%
  Run #4 | Exact [Min: 1665, Time: 0.000s] | WorstRow [Cost: 1710, Time: 0.000s] | Quality: 97.2%

Dimension: 8x8
  Run #1 | Exact [Min: 1379, Time: 0.000s] | WorstRow [Cost: 1495, Time: 0.000s] | Quality: 91.8%
  Run #2 | Exact [Min: 1451, Time: 0.000s] | WorstRow [Cost: 1451, Time: 0.000s] | Quality: 100.0%
  Run #3 | Exact [Min: 1803, Time: 0.000s] | WorstRow [Cost: 1940, Time: 0.000s] | Quality: 92.0%
  Run #4 | Exact [Min: 1212, Time: 0.001s] | WorstRow [Cost: 1320, Time: 0.000s] | Quality: 91.6%

Dimension: 10x10
  Run #1 | Exact [Min: 1631, Time: 0.086s] | WorstRow [Cost: 1780, Time: 0.000s] | Quality: 91.1%
  Run #2 | Exact [Min: 1279, Time: 0.085s] | WorstRow [Cost: 1279, Time: 0.000s] | Quality: 100.0%
  Run #3 | Exact [Min: 1335, Time: 0.086s] | WorstRow [Cost: 1490, Time: 0.000s] | Quality: 89.2%
  Run #4 | Exact [Min: 1703, Time: 0.089s] | WorstRow [Cost: 1810, Time: 0.000s] | Quality: 94.3%

Dimension: 12x12
  Run #1 | Exact [Min: 1542, Time: 10.718s] | WorstRow [Cost: 1690, Time: 0.000s] | Quality: 91.5%
  Run #2 | Exact [Min: 859,  Time: 10.863s] | WorstRow [Cost: 859,  Time: 0.000s] | Quality: 100.0%
  Run #3 | Exact [Min: 2152, Time: 11.152s] | WorstRow [Cost: 2310, Time: 0.000s] | Quality: 92.7%
  Run #4 | Exact [Min: 1858, Time: 11.046s] | WorstRow [Cost: 2020, Time: 0.000s] | Quality: 91.0%
  ```


## 3. Выводы по работе

1. **Граница применимости полного перебора:** На малых размерностях графа (до 10 городов) точный алгоритм работает мгновенно. Однако из-за факториальной сложности `(N-1)!` при увеличении числа городов до 12–13 время выполнения возрастает в геометрической прогрессии (до нескольких секунд/минут), что делает полный перебор неприменимым для реальных задач логистики.
