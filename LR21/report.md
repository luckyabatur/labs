# Отчет по лабораторной работе N 21 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Дехтеренко Дмитрий Сергеевич
Контакты: dekhterenkodmitrii@gmail.com
Работа выполнена: 04.11.2023
Преподаватель: Чеснов Илья Игоревич

## 1. Тема

Программирование на интерпретируемых командных языках

## 2. Цель работы

Составить программу выполнения заданных действий над файлами на одном из интерпретируемых командных языков

## 3. Задание

Сравнение указанного файла со всеми другими файлами, имеющими такой же суффикс, с удалением совпадающих файлов.

## 4. Оборудование

Процессор: AMD Ryzen 7 5700U @ 8x 1.8GH
ОП: 15312 Мб
НМД: 468 Гб
Монитор: 1920x1080

## 5. Программное обеспечение

Операционная система семейства: linux (ubuntu), версия 23.04
Интерпретатор команд: bash, версия 5.2.15.
Система программирования: --, версия --
Редактор текстов: emacs, версия 25.2.2
Утилиты операционной системы: --
Прикладные системы и программы: --
Местонахождение и имена файлов программ и данных на домашнем компьютере: --

## 6. Идея, метод, алгоритм решения задачи

Реализовать рекурсивный  (или нерекурсивынй в зависимости от выбора пользователя) обход заданного каталога и сравнить заданный файл с файлами с тем же суффиксом в этом каталоге. Файлы без суффикса будем игнорировать.

## 7. Сценарий выполнения работы

План:

1. Реазлизовать флаг ?, выводящий мануал
2. Реализовать приём значений:
  1. Для ключа -p для ввода директории, файлы из которой будут сравниваться с указанным файлом
  2. Для ключа -f для ввода пути к заданном файлу
  3. Для ключа -r для установки режима работы с вретившимися папками
3. Рассмотреть случаи, когда значения отсутствуют или введены неверно
4. Написать функцию для рекурсивного обхода каталога, сравнения и удаления файлов
5. Написать мануал

## 8. Распечатка протокола

```

1.  Входные данные:

luckyabatur@university:~/UNI/bash$ bash cad -p /home/luckyabatur/UNIbash/ -f /home/luckyabatur/UNI/bash/a.sh

    Вывод программы:
    
Write a mode for working with directories: 1
You wrote a wrong path to directory
Write the path again: 12345
You wrote a wrong path to directory
Write the path again: /home/luckyabatur/UNI/bash/   

the files /home/luckyabatur/UNI/bash/bue.sh and /home/luckyabatur/UNI/bash/a.sh match.
the file /home/luckyabatur/UNI/bash/bue.sh will be deleted.


the files /home/luckyabatur/UNI/bash/tutu.sh and /home/luckyabatur/UNI/bash/a.sh match.
the file /home/luckyabatur/UNI/bash/tutu.sh will be deleted.

2.  Входные данные:

luckyabatur@university:~/UNI/bash$ bash cad -p /home/luckyabatur/UNI/bash/ -f /home/luckyabatur/UNI/bash/cad.sh -r 0
    
    Вывод программы:

You wrote a wrong path to file
Write the path again: /home/luckyabatur/UNI/bash/cad
You wrote a path to file without a suffix
Write the path again: /home/luckyabatur/UNI/bash/script.sh

Matching files with the file suffix were not found.

3.  Входные данные:

luckyabatur@university:~/UNI/bash$ bash cad -r a

    Вывод программы:

Write path to comparision directory: /home/luckyabatur/UNI/bash/
Write path to file: /home/luckyabatur/UNI/bash/log.txt
You wrote a wrong value for key -r
Write value again: 1


Matching files with the file suffix were not found.
```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                  | Действие по исправлению | Примечание  |
|---|---------------|------------|-----------|--------------------------|-------------------------|-------------|
|1  | Дом           | 03.03.2024 | 22:10     | Неправильно строил составные условия  | Разобрался и исправил     | Сложно|
|2  | Дом           | 04.03.2024 | 23:30     | Не учёл случай, когда -r получает некорректное значение | Расмотрел это случай |             |
|3  | Дом           | 05.03.2024 | 01:20    | Неправильно проверял, есть ли суффикс с имени файла| Исправил | Разобрался с операторами # и %          |


## 10. Замечания автора по существу работы

У bash довольно сложный и неочевидный синтаксис.

## 11. Выводы

Теперь знаю больше способов для быстрых манипуляций с файлами.

