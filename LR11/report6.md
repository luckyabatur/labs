# Отчет по лабораторной работе N 11 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Дехтеренко Дмитрий Сергеевич\
Контакты: dekhterenkodmitrii@gmail.com \
Работа выполнена: 19.11.2023\
Преподаватель: Чеснов Илья Игоревич

## 1. Тема

Простейшие приёмы лексического анализа

## 2. Цель работы

Написание конечного автомата, который решает поставленную задачу на языке C

## 3. Задание

Подсчитать количество слов, содержащих не менее 3-х букв.

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

Учитывать количество букв в слове переходами состояний.

## 7. Сценарий выполнения работы

План:
1. Написать состояния `0`, `1`, `2`, `3` и пути переходов.
2. Состояние `0`: начальное, встретив символ, отличный от `' '` и `'\n'`, переходим в состояние `1`.
3. Состояние `1`: если снова встречаем символ, отличный от `' '` и `'\n'`, переходим в состояние `2`, иначе возвращаемся в `0`.
4. Состояние `2`: если снова встречаем символ, отличный от `' '` и `'\n'`, увеличиваем переменную ответа `count` на 1 и переходим в состояние `3`, иначе возвращаемся в `0`.
5. Состояние `3`: если встречаем `' '` или `'\n'`, возвращаемся в `0`.

## 8. Распечатка протокола

```
Количество слов, содержащих не менее 3-х букв: 5

```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                                                | Действие по исправлению   | Примечание     |
|---|---------------|------------|-----------|--------------------------------------------------------|---------------------------|----------------|
|1  | Дом           | 19.11.2023 | 14:02     | Считал каждое подхожящее слово несколько раз               | Написал ещё одно состояние             | |
|2  | Дом           | 19.11.2023 | 14:31     | Некрасиво выводил ответ               | Добавил `\n`| Теперь красиво|

## 10. Замечания автора по существу работы

Подозрительно просто. 

## 11. Выводы

Узнал, что такое конечный автомат, разобрался со switch.
