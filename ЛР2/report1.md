# Отчет по лабораторной работе N 2 по курсу

# "Фундаментальная информатика"

Студент группы: M8О-115Б, Дехтеренко Дмитрий Сергеевич\
Контакты: dekhterenkodmitrii@gmail.com\
Работа выполнена: 24.09.2023\
Преподаватель: Чеснов Илья Игоревич

## 1. Тема
Операционная среда ОС UNIX

## 2. Цель работы

Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.

## 3. Задание

Приобретение основных навыков работы в ОС UNIX

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

Скачать файл с гугл диска, вывести его содержимое, провести над ним некоторые манипуляции, в том числе используя python, вывести содержимое изменённого файла. Обернуть всё это сюжетом про голодных студентов.

## 7. Сценарий выполнения работы

План:

1. Создать директорию (`MAI`), и ещё одну внутри неё (`bakery`).
2. Скачать файл с гугл диска, дать ему имя.
3. Вывести содержимое этого файла и количество его строк.
4. Создать директорию (`administration`) и файл в ней с именем - командой для python.
5. Создать ещё одну директорию (`chef`), создать в ней файл `instruction.py` и записать в него имя файла – команду с прошлого шага.
6. В `bakery` создать файлы `2` и `10`
7. Отправить имена этих файлов на ввод `instruction.py`, получить соответствующий вывод
8. С помощью `grep` получаем вывод из старого файла (шаг 2) и записываем его в новый
9. Переименовываем этот новый файл
10. Удаляем его и директорию `bakery`

## 8. Распечатка протокола

```

luckyabatur@university:~$ mkdir -p MAI/bakery; cd MAI
luckyabatur@university:~/MAI$ wget -O hungry_students.txt "https://drive.google.com/uc?export=download&id=1VO3seG5P3EeFFeOIMMq27Lq8o8KKq4v0"
--2023-09-24 16:19:26--  https://drive.google.com/uc?export=download&id=1VO3seG5P3EeFFeOIMMq27Lq8o8KKq4v0
Resolving drive.google.com (drive.google.com)... 173.194.222.194, 2a00:1450:4010:c0f::c2
Connecting to drive.google.com (drive.google.com)|173.194.222.194|:443... connected.
HTTP request sent, awaiting response... 303 See Other
Location: https://doc-0o-2c-docs.googleusercontent.com/docs/securesc/ha0ro937gcuc7l7deffksulhg5h7mbp1/or10u7uvpiou059qorq9c1odrdaf2r5c/1695561525000/01896454975450862930/*/1VO3seG5P3EeFFeOIMMq27Lq8o8KKq4v0?e=download&uuid=8ede91d2-e8a0-440d-83d5-93b6da9ea66b [following]
Warning: wildcards not supported in HTTP.
--2023-09-24 16:19:32--  https://doc-0o-2c-docs.googleusercontent.com/docs/securesc/ha0ro937gcuc7l7deffksulhg5h7mbp1/or10u7uvpiou059qorq9c1odrdaf2r5c/1695561525000/01896454975450862930/*/1VO3seG5P3EeFFeOIMMq27Lq8o8KKq4v0?e=download&uuid=8ede91d2-e8a0-440d-83d5-93b6da9ea66b
Resolving doc-0o-2c-docs.googleusercontent.com (doc-0o-2c-docs.googleusercontent.com)... 216.58.211.225, 2a00:1450:4026:805::2001
Connecting to doc-0o-2c-docs.googleusercontent.com (doc-0o-2c-docs.googleusercontent.com)|216.58.211.225|:443... connected.
HTTP request sent, awaiting response... 200 OK
Length: 133 [text/plain]
Saving to: ‘hungry_students.txt’

hungry_students.txt 100%[===================>]     133  --.-KB/s    in 0s      

2023-09-24 16:19:33 (7.98 MB/s) - ‘hungry_students.txt’ saved [133/133]

luckyabatur@university:~/MAI$ cat hungry_students.txt; wc -l hungry_students.txt
(╥﹏╥)
(╥﹏╥)
(╥﹏╥)
(╥﹏╥)
(╥﹏╥)
(╥﹏╥)
(╥﹏╥)
(╥﹏╥)
(╥﹏╥)
(╥﹏╥)
10 hungry_students.txt
luckyabatur@university:~/MAI$ mkdir administration; cd administration
luckyabatur@university:~/MAI/administration$ touch "print(int(input())*int(input()),'пирожков испечено')"
luckyabatur@university:~/MAI/administration$ mkdir ../chef
luckyabatur@university:~/MAI/administration$ ls >> ../chef/instruction.py
luckyabatur@university:~/MAI/administration$ cd ../bakery
luckyabatur@university:~/MAI/bakery$ touch 2 10
luckyabatur@university:~/MAI/bakery$ ls | python3 ~/MAI/chef/instruction.py
20 пирожков испечено
luckyabatur@university:~/MAI/bakery$ grep -o '﹏' ~/MAI/hungry_students.txt | cat >> ~/MAI/eating_students.txt
luckyabatur@university:~/MAI/bakery$ cd ~/MAI
luckyabatur@university:~/MAI$ mv eating_students.txt sleeping_students.txt
luckyabatur@university:~/MAI$ cat sleeping_students.txt; wc -l sleeping_students.txt
﹏
﹏
﹏
﹏
﹏
﹏
﹏
﹏
﹏
﹏
10 sleeping_students.txt
luckyabatur@university:~/MAI$ rm sleeping_students.txt; rm -r bakery

```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                  | Действие по исправлению | Примечание  |
|---|---------------|------------|-----------|--------------------------|-------------------------|-------------|
|1  | Дом           | 17.09.2023 | 13:25     | Записывал в `instruction.py` помимо команды имя самого файла       | Создал новую директорию и из неё записывал вывод `ls` в `instruction.py` | Узнал, что при использовании `ls >> <файл>`, если файл не существует, то сначала создаётся файл, а потом вывод `ls` записывается в этот файл |
|2  | Дом           | 17.09.2023 | 14:00     | Сделал опечатку в имени файла | Переписал|             
|3  | Дом           | 17.09.2023 | 14: 12    | Неправильно указал путь к файлу | Переписал| Стал внимательнее следить за директорией, в которой нахожусь|

## 10. Замечания автора по существу работы

Первый раз поработал на линукс.

## 11. Выводы

Изучил базовые команды линукса. Научился делать ссылки с гугл диска, которые работают в терминале линукса, попробовал кое-что интересное с python.

