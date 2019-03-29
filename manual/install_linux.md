# Установка под Linux
```
Версия операционной системы, библиотеки boost, компилятора могут отличаться
```

## 1. Установка компилятора

* Установите GNU Compiler 

## 2. Установка библиотек

```
cxxopts, picosha2, spdlog - библиотеки, которые зависят от заголовочный файлов. Они уже подключены к проекту. Находятся в lib/
Отредактировав файл CMakeLists.txt Вы можете изменить путь к библиотекам
```

### 2.1 Boost

    $ sudo apt-get install libboost1.67-dev

```
Версия может отличаться
Замените 1.67 на нужную версию
```

### 2.2 SQLite3

    $ sudo apt-get install sqlite3
    $ sudo apt-get install libsqlite3-dev

## 3. Создание Makefile и компиляция проекта

    1. Скачайте и распакуйте репозиторий
    2. Создайте папку build в любом удобном месте
    3. Запустите CMake
    4. Скомпилируйте код используя MinGW

Например:

    $ git clone https://github.com/SavaLione/Battleship-Royale.git
    $ cd Battleship-Royale
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make