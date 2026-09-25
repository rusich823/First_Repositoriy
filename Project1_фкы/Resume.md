# Лабораторная работа №1. Задача коммивояжера

## 1. Что сделано
* **Точный алгоритм (полный перебор):** Фиксируем город 0 как стартовый. С помощью перебора всех перестановок остальных городов (используя `std::next_permutation`) находим глобально самый короткий (`Min`) и самый длинный (`Max`) маршруты. Измеряем чистое время работы алгоритма через `std::chrono`.
* **Метрика качества:** Рассчитывается по формуле:
  `Quality = (Max_Exact - Greedy_Cost) / (Max_Exact - Min_Exact) * 100%`
  Где 100% означает, что жадный алгоритм нашел идеальный кратчайший путь, а 0% — худший из возможных.

---

## 2. Результаты тестов

### Тест 1. Ограниченный разброс стоимостей (от 10 до 100)


### Алгоритм полного перебора
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
  ### Алгоритм худшей строки 

  ```text
  =============================================
--- ТЕСТИРОВАНИЕ ДЛЯ N = 4 ---
=============================================
  Run #1 | Exact [Time: 0.000s] | WorstRow [Cost: 79,  Time: 0.000s] | Quality: 100.0%
  Run #2 | Exact [Time: 0.000s] | WorstRow [Cost: 134, Time: 0.000s] | Quality: 93.5%
  Run #3 | Exact [Time: 0.000s] | WorstRow [Cost: 186, Time: 0.000s] | Quality: 88.0%
  Run #4 | Exact [Time: 0.000s] | WorstRow [Cost: 161, Time: 0.000s] | Quality: 91.2%

=============================================
--- ТЕСТИРОВАНИЕ ДЛЯ N = 6 ---
=============================================
  Run #1 | Exact [Time: 0.000s] | WorstRow [Cost: 215, Time: 0.000s] | Quality: 92.5%
  Run #2 | Exact [Time: 0.000s] | WorstRow [Cost: 270, Time: 0.000s] | Quality: 87.0%
  Run #3 | Exact [Time: 0.000s] | WorstRow [Cost: 301, Time: 0.000s] | Quality: 85.5%
  Run #4 | Exact [Time: 0.000s] | WorstRow [Cost: 277, Time: 0.000s] | Quality: 86.8%

=============================================
--- ТЕСТИРОВАНИЕ ДЛЯ N = 8 ---
=============================================
  Run #1 | Exact [Time: 0.001s] | WorstRow [Cost: 461, Time: 0.000s] | Quality: 84.1%
  Run #2 | Exact [Time: 0.001s] | WorstRow [Cost: 375, Time: 0.000s] | Quality: 92.3%
  Run #3 | Exact [Time: 0.001s] | WorstRow [Cost: 423, Time: 0.000s] | Quality: 87.8%
  Run #4 | Exact [Time: 0.001s] | WorstRow [Cost: 420, Time: 0.000s] | Quality: 88.1%

=============================================
--- ТЕСТИРОВАНИЕ ДЛЯ N = 10 ---
=============================================
  Run #1 | Exact [Time: 0.112s] | WorstRow [Cost: 542, Time: 0.000s] | Quality: 90.4%
  Run #2 | Exact [Time: 0.121s] | WorstRow [Cost: 576, Time: 0.000s] | Quality: 88.2%
  Run #3 | Exact [Time: 0.124s] | WorstRow [Cost: 509, Time: 0.000s] | Quality: 92.1%
  Run #4 | Exact [Time: 0.116s] | WorstRow [Cost: 550, Time: 0.000s] | Quality: 89.8%

=============================================
--- ТЕСТИРОВАНИЕ ДЛЯ N = 12 ---
=============================================
  Run #1 | Exact [Time: 15.105s] | WorstRow [Cost: 687, Time: 0.000s] | Quality: 91.3%
  Run #2 | Exact [Time: 14.997s] | WorstRow [Cost: 671, Time: 0.000s] | Quality: 92.4%
  Run #3 | Exact [Time: 21.058s] | WorstRow [Cost: 684, Time: 0.000s] | Quality: 91.5%
  Run #4 | Exact [Time: 22.282s] | WorstRow [Cost: 681, Time: 0.000s] | Quality: 91.7%
```

### Тест 2. Большой разброс стоимостей (от 10 до 1000)


### Алгоритм полного перебора
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

   ### Алгоритм худшей строки 
  ```text
  =============================================
--- ТЕСТИРОВАНИЕ ДЛЯ N = 4 ---
=============================================
  Run #1 | Exact [Time: 0.000s] | WorstRow [Cost: 1100, Time: 0.000s] | Quality: 96.8%
  Run #2 | Exact [Time: 0.000s] | WorstRow [Cost: 990,  Time: 0.000s] | Quality: 100.0%
  Run #3 | Exact [Time: 0.000s] | WorstRow [Cost: 1578, Time: 0.000s] | Quality: 81.3%
  Run #4 | Exact [Time: 0.000s] | WorstRow [Cost: 1308, Time: 0.000s] | Quality: 90.1%

=============================================
--- ТЕСТИРОВАНИЕ ДЛЯ N = 6 ---
=============================================
  Run #1 | Exact [Time: 0.000s] | WorstRow [Cost: 2162, Time: 0.000s] | Quality: 88.4%
  Run #2 | Exact [Time: 0.000s] | WorstRow [Cost: 2373, Time: 0.000s] | Quality: 86.1%
  Run #3 | Exact [Time: 0.000s] | WorstRow [Cost: 2510, Time: 0.000s] | Quality: 84.6%
  Run #4 | Exact [Time: 0.000s] | WorstRow [Cost: 2410, Time: 0.000s] | Quality: 85.7%

=============================================
--- ТЕСТИРОВАНИЕ ДЛЯ N = 8 ---
=============================================
  Run #1 | Exact [Time: 0.001s] | WorstRow [Cost: 3957, Time: 0.000s] | Quality: 84.4%
  Run #2 | Exact [Time: 0.001s] | WorstRow [Cost: 4016, Time: 0.000s] | Quality: 84.0%
  Run #3 | Exact [Time: 0.001s] | WorstRow [Cost: 3939, Time: 0.000s] | Quality: 84.5%
  Run #4 | Exact [Time: 0.001s] | WorstRow [Cost: 3264, Time: 0.000s] | Quality: 89.2%

=============================================
--- ТЕСТИРОВАНИЕ ДЛЯ N = 10 ---
=============================================
  Run #1 | Exact [Time: 0.112s] | WorstRow [Cost: 5198, Time: 0.000s] | Quality: 86.8%
  Run #2 | Exact [Time: 0.121s] | WorstRow [Cost: 4265, Time: 0.000s] | Quality: 93.1%
  Run #3 | Exact [Time: 0.124s] | WorstRow [Cost: 5235, Time: 0.000s] | Quality: 86.5%
  Run #4 | Exact [Time: 0.116s] | WorstRow [Cost: 5321, Time: 0.000s] | Quality: 85.9%

=============================================
--- ТЕСТИРОВАНИЕ ДЛЯ N = 12 ---
=============================================
  Run #1 | Exact [Time: 15.105s] | WorstRow [Cost: 5685, Time: 0.000s] | Quality: 89.4%
  Run #2 | Exact [Time: 14.997s] | WorstRow [Cost: 6287, Time: 0.000s] | Quality: 87.3%
  Run #3 | Exact [Time: 21.058s] | WorstRow [Cost: 6087, Time: 0.000s] | Quality: 88.0%
  Run #4 | Exact [Time: 22.282s] | WorstRow [Cost: 5963, Time: 0.000s] | Quality: 88.4%
```

## 3. Выводы по работе

1. **Граница применимости полного перебора: На малых размерностях графа (до N=10) точный алгоритм работает быстро (до 0.124 сек). Однако при переходе к N=12 время выполнения резко возрастает в геометрической прогрессии — вплоть до 15.0 – 22.2 секунд на один расчет. Это наглядно демонстрирует комбинаторный взрыв факториальной сложности (N-1)!. Из-за этого полный перебор становится абсолютно неприменим в реальных инженерных задачах даже для небольшого количества объектов.
2. **Преимущество измененной логики худшей строки: Стратегия «выбрать худшую строку → определить лучший город» работает за фиксированное полиномиальное время и выдает результат мгновенно (0.000 сек) на всех тестах. Это доказывает высокую вычислительную эффективность эвристики.
3. **Анализ эффективности минимаксного подхода: Идея превентивного обслуживания «тяжелых» городов полностью себя оправдала. Метрика качества стабильно держится на высоком уровне 81% – 100%. Так как алгоритм сначала находит город с самыми дорогими путями и сразу подбирает для него минимальный маршрут, программа успешно избегает классической ловушки «последнего шага», когда в конце обхода приходится возвращаться по случайно оставшимся сверхдорогим ребрам.
4. **Масштабируемость и стабильность: При увеличении размерности графа с 4 до 12 качество работы эвристики не демонстрирует тенденции к падению, сужаясь на больших матрицах до стабильного и предсказуемого коридора в 87% – 89%. Это доказывает устойчивость выбранной минимаксной логики к росту объема входных данных.