# Отчет по лабораторной работе N 15 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Дехтеренко Дмитрий Сергеевич\
Контакты: dekhterenkodmitrii@gmail.com \
Работа выполнена: 20.11.2023\
Преподаватель: Чеснов Илья Игоревич
## 1. Тема

Обработка матриц

## 2. Цель работы

Составить программу на языке C, производящую обработку квадратной матрицы NxN

## 3. Задание

5. Сложение всех строк, содержащих максимальный элемент матрицы, и замена первой из них на результат сложения.

## 4. Оборудование

Процессор: AMD Ryzen 7 5700U @ 8x 1.8GH\
ОП: 15312 Мб\
НМД: 468 Гб\
Монитор: 1920x1080

## 5. Программное обеспечение

Операционная система семейства: **linux (ubuntu)**, версия **23.04**\
Интерпретатор команд: **bash**, версия **5.2.15**.\
Система программирования: **--**, версия **--**\
Редактор текстов: **emacs**, версия **25.2.2**\
Утилиты операционной системы: **--**\
Прикладные системы и программы: **--**\
Местонахождение и имена файлов программ и данных на домашнем компьютере: **--**

## 6. Идея, метод, алгоритм решения задачи

Разделить задачу на подзадачи, для каждой написать цикл и получить резлуьтат, приближающий к ответу.

## 7. Сценарий выполнения работы

План:

1. Написать цикл для заполнения массивов и нахождения максимального элемента матрицы.

2. Написать цикл для определения, в каких строках есть максимальный элемент.

3. Написать цикл для сложения этих строк.

4. Написать цикл для замены первой из этих строк результатом сложения.

## 8. Распечатка протокола

```
Входные данные

1.

5
1 1 1 1 1 
1 9 9 1 1 
1 1 9 1 1 
1 9 1 1 1 
1 1 1 1 1

2.

3
1 2 3 
1 2 3 
1 2 3

3.

2
1 1 
1 1 

Вывод программы

1.

Результат сложения:
3 19 19 3 3 
Получилась матрица:
1 1 1 1 1 
3 19 19 3 3 
1 1 9 1 1 
1 9 1 1 1 
1 1 1 1 1

2.

Результат сложения:
3 6 9 
Получилась матрица:
3 6 9 
1 2 3 
1 2 3

3.

Результат сложения:
2 2 
Получилась матрица:
2 2 
1 1 


```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                  | Действие по исправлению | Примечание  |
|---|---------------|------------|-----------|--------------------------|-------------------------|-------------|
|1  | Лаб           | 20.11.2023 | 10:01    | В описании циклов писал не `;`, а `,`   | Исправил    | Непривык к синтаксису|
|2  | Лаб      | 20.11.2023 | 10:27   | Не определял тип переменных `i` и `j` в описании циклов| Определил |     Глупая ошибка        |

## 10. Замечания автора по существу работы

Линал повсюду.

## 11. Выводы

Научился работать с массивами на языке C.

