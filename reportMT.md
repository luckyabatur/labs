# Отчет по курсовой работе N 1 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Дехтеренко Дмитрий Сергеевич\
Контакты: dekhterenkodmitrii@gmail.com\
Работа выполнена: 01.10.2023\
Преподаватель: Чеснов Илья Игоревич

## 1. Тема

Программирование машин Тьюринга

## 2. Цель работы

Составить программу машины Тьюринга в четвёрках, выполняющую заданное действие над словами, записанными на ленте.

## 3. Задание

Приобретение основных навыков работы с машиной Тьюринга

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

Представить цифры восьмеричного числа как двоичные триады, получить состоящее из них реверсированное двочиное число, затем реверсировать его и получить ответ.

## 7. Сценарий выполнения работы

План:
1. Для каждой цифры написать переход к реверсированной двоичной триаде.
2. Написать алгоритм перебора цифр восьмерично числа и записи их в виде довичных триад в новое, пока что реверсированное, двоичное число.
3. Написать алгоритм реверса числа.
4. Учесть и убрать в нём незначащие нули реверсированного числа.
5. Отдельно рассмотреть 0.
6. Провести тестирование.

## 8. Распечатка протокола

```
710
71!
71! 0
71! 00
71! 000
710 000
7!0 000
7!0 0001
7!0 000100
710 000100
!10 000100
!10 0001001
!10 00010011
!10 000100111
710 000100111
710 00010011!
710 00010011! 1
710 0001001!! 1
710 0001001!! 11
710 000100!!! 11
710 000100!!! 111
710 00010!!!! 111
710 00010!!!! 1110
710 0001!!!!! 1110
710 0001!!!!! 11100
710 000!!!!!! 11100
710 000!!!!!! 111001
710 00!!!!!!! 111001
710 00!!!!!!! 1110010
710 0!!!!!!!! 1110010
710 0!!!!!!!! 11100100
710 !!!!!!!!! 11100100
710 !!!!!!!!! 111001000

```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                                                | Действие по исправлению   | Примечание     |
|---|---------------|------------|-----------|--------------------------------------------------------|---------------------------|----------------|
|1  | Дом           | 01.10.2023 | 22:04     | МТ выдавала ошибка, если входные данные - нуль или много нулей      | Рассмотрел этот случай отдельно     |   |
|2  | Дом           | 01.10.2023 | 22:20    | 6 переводилась не в ту двоичную триаду | Исправил   | Перепроверил остальные цифры     |

## 10. Замечания автора по существу работы

Крайне занимательная работа.

## 11. Выводы

Научился составлять простые алгоритмы на МТ, вспомнил быстрый способ первода числа из восьмеричной системы счисления в двоичную.
