#Создаём директории MAI и bakery (МАИ и пекарня открываются)
mkdir -p MAI/bakery; cd MAI

#Скачиваем файл с гугл диска (Голодные студенты входят в вуз)
wget -O hungry_students.txt "https://drive.google.com/uc?export=download&id=1VO3seG5P3EeFFeOIMMq27Lq8o8KKq4v0"

#Выводим содержимое файла и количество строк 
cat hungry_students.txt; wc -l hungry_students.txt

#Создаём новую директорию и переходим в неё (Администрация начинает работу)
mkdir administration; cd administration

#Создаём файл с именем-командой, которое должна отправиться на ввод питону
#(Администрация создаёт инструкцию по выпечку булочек)
touch "print(int(input())*int(input()),'пирожков испечено')"

#Поднимаемся в директорию выше и создаём ещё одну директорию (Кабинет шеф-повара)
mkdir ../chef

#Записываем вывод ls (выводит имя файла - команду для питона) в файл питона
#(нструкция отправляется к шеф-повару)
ls >> ../chef/instruction.py

#Поднимаемся в директорию выше и возвращаемся в bakery (Возвращаемся в пекарню)
cd ../bakery

#Создаём два файла (Каждом студенту нужно 2 пирожка)
touch 2 10

#Выводим имена файлов 2 и 10, отправляем их на ввод питону (Готовим пирожки)
ls | python3 ~/MAI/chef/instruction.py

#Записываем вывод строк с '﹏'(оставляя только '﹏') в новый файл (У студентов обед)
grep -o '﹏' ~/MAI/hungry_students.txt | cat >> ~/MAI/eating_students.txt

# Переходим в директорию MAI, переименовываем файл (Наелись и спят)
cd ~/MAI
mv eating_students.txt sleeping_students.txt

#Выводим содержимое файла и количество строк
cat sleeping_students.txt; wc -l sleeping_students.txt

#Удаляем файл и директорию (Студенты уходят, пекарня закрывается)
rm sleeping_students.txt; rm -r bakery
