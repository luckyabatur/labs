# Отчет по курсовой работе N 2 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Дехтеренко Дмитрий Сергеевич\
Контакты: dekhterenkodmitrii@gmail.com \
Работа выполнена: 08.10.2023\
Преподаватель: Чеснов Илья Игоревич

## 1. Тема

Программирование машин Тьюринга при помощи диаграммера

## 2. Цель работы

Составить программу машины Тьюринга используя диаграммер, выполняющую заданное действие над словами, записанными на ленте.

## 3. Задание

1 Вычисление разности двух десятичных чисел без знака, при условии, что первое число больше второго.

## 4. Оборудование

Процессор: AMD Ryzen 7 5700U @ 8x 1.8GH
ОП: 15312 Мб
НМД: 468 Гб
Монитор: 1920x1080

## 5. Программное обеспечение

Операционная система семейства: linux (ubuntu), версия 23.04
Интерпретатор команд: bash, версия 5.2.15.
Система программирования: visual studio code, версия 1.82.2
Редактор текстов: emacs, версия 25.2.2
Утилиты операционной системы: --
Прикладные системы и программы: --
Местонахождение и имена файлов программ и данных на домашнем компьютере: --

## 6. Идея, метод, алгоритм решения задачи

Скопировать числа, вычитать сначала единицы, потом отбрасывать последнюю цифру, далее десятки и т.д., отдельно учесть случаи с вычитанием однозначного числа, в конце избавиться от ведущих нулей.

## 7. Сценарий выполнения работы

План:
1. Копировать числа.
2. Вычесть из одного числа другое:
3. Запомить и стереть последнюю циффу второго числа.
4. Вычесть её из первого числа, запомнить, что разряд единиц первого числа больше использовать не нужно.
5. Повторять эти действия для остальных цифр, пока не закончатся цифры второго числа.
6. Если нужно, избавиться от ведущих нулей.

## 8. Распечатка протокола
1. tenminus
![alt text](https://github.com/luckyabatur/labs/blob/main/tenminus.png?raw=true)
2. copy
![alt text](https://github.com/luckyabatur/labs/blob/main/copy.png?raw=true)
3. minus
![alt text](https://github.com/luckyabatur/labs/blob/main/minus.png?raw=true)
4. mainsup
![alt text](https://github.com/luckyabatur/labs/blob/main/mainsup.png?raw=true)
5. count1
![alt text](https://github.com/luckyabatur/labs/blob/main/count1.png?raw=true)
6. count2
![alt text](https://github.com/luckyabatur/labs/blob/main/count2.png?raw=true)
7. count3
![alt text](https://github.com/luckyabatur/labs/blob/main/count3.png?raw=true)
8. count4
![alt text](https://github.com/luckyabatur/labs/blob/main/count4.png?raw=true)
9. count5
![alt text](https://github.com/luckyabatur/labs/blob/main/count5.png?raw=true)
10. count6
![alt text](https://github.com/luckyabatur/labs/blob/main/count6.png?raw=true)
11. count7
![alt text](https://github.com/luckyabatur/labs/blob/main/count7.png?raw=true)
12. count8
![alt text](https://github.com/luckyabatur/labs/blob/main/count8.png?raw=true)
13. count9
![alt text](https://github.com/luckyabatur/labs/blob/main/count9.png?raw=true)
14.
![alt text](?raw=true)
15.
![alt text](?raw=true)
16.
![alt text](?raw=true)
17.
![alt text](?raw=true)
18.
![alt text](?raw=true)
19.
![alt text](?raw=true)
20.
![alt text](?raw=true)
21.
 ![alt text](?raw=true)  
22.
![alt text](?raw=true)
23.
![alt text](?raw=true)
24.
![alt text](?raw=true)
25.
![alt text](?raw=true)
26.
![alt text](?raw=true)
27.
![alt text](?raw=true)
```
15 7
!5 7
!5 7 1
15 7 1
1! 7 1
1! 7 15
15 7 15
15 ! 15
15 ! 15 7
15 7 15 7
15 7 15
15 7 1! 
15 7 0!
15 7 08
15 7 !8
15 7 !!
15 7 8!
15 7 8

```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                                                | Действие по исправлению   | Примечание     |
|---|---------------|------------|-----------|--------------------------------------------------------|---------------------------|----------------|
|1  | Дом           | 08.09.2023 | 22:50     | ДТ неправильно вычитала однознанчные числа | Рассмотрел эти случаи отдельно  |   |
|2  | Дом           | 08.09.2023 | 23:14     | При удалении ведущих нулей число заменялось последовательность одинаковых цифр  | Добавил сдвиг влево в соответствующем месте |  Провёл ещё тесты            |

## 10. Замечания автора по существу работы

Крайне занимательная работа.

## 11. Выводы

Научился пользоваться диаграммером Тьюринга.

