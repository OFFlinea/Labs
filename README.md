# Sortings
## Paragraph 1
![Изображение](https://github.com/OFFlinea/Labs/blob/Lab3/lab3/graphics/quadratic_sorts.png) \
Сортировка Шелла оказалась быстрее всего.
## Paragraph 2
![Изображение](https://github.com/OFFlinea/Labs/blob/Lab3/lab3/graphics/pyramid_sort_k.png) \
k = 5 оказалось самым оптимальным.
## Paragraph 3
![Изображение](https://github.com/OFFlinea/Labs/blob/Lab3/lab3/graphics/merge_sort.png) \
Итеративная сортировка выигрывает в скорости рекурсивную (хмм, неожиданно)
## Paragraph 4
big_tests: \
![Изображение](https://github.com/OFFlinea/Labs/blob/Lab3/lab3/graphics/quick_sorts_big_tests.png) \
test_most_dublicates: \
![Изображение](https://github.com/OFFlinea/Labs/blob/Lab3/lab3/graphics/quick_sort_tmd.png) \
Быстрая сортировка с разбиением Ломуто выигрываает у других на big_tests, но оказывается на последнем месте на test_most_dublicates. \
Толстое разбиение вырывается на второе место как ни странно на test_most_dublicates. Но самое лучшее разбиение всё равно у Хоара.
## Paragraph 5
![Изображение](https://github.com/OFFlinea/Labs/blob/Lab3/lab3/graphics/quick_sorts_pivots.png) \
Лучшей быстрой сортировкой оказалась сортировка с pivotom из медианы трёх.
## Paragraph 6
![Изображение](https://github.com/OFFlinea/Labs/blob/Lab3/lab3/graphics/intro_sort_blocks.png) \
Размер блока должен быть примерно <= 16.
## Paragraph 7
![Изображение](https://github.com/OFFlinea/Labs/blob/Lab3/lab3/graphics/intro_sort_recursion_depth.png) \
Самым оптимальным оказалось с = 6. \
![Изображение](https://github.com/OFFlinea/Labs/blob/Lab3/lab3/graphics/intro_sort.png) \
Intro_sort победил best_quick_sort
## Paragraph 8
![Изображение](https://github.com/OFFlinea/Labs/blob/Lab3/lab3/graphics/radix_sorts.png) \
LSD > MSD
## Introduction
Подведём итоги: LSD порвало всех. \
Вот список лучших сортировок:
1) Lsd_sort
2) Msd_sort
3) Intro_sort
4) Quick_sort с pivotom из медианы трёх
