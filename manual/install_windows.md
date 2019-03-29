# Установка под Windows
```
Версия операционной системы, библиотеки boost, компилятора могут отличаться
```

## 1. Установка компилятора

* Скачайте [MinGW32](http://www.mingw.org/) или [MinGW-w64](https://mingw-w64.org/doku.php)
```
Мы рекомендуем MinGW-w64
```
* Установите MinGW
* Добавьте исполняемые файлы и динамические библиотеки в системную переменную Path (Необязательно)

## 2. Установка библиотек

```
cxxopts, picosha2, spdlog - библиотеки, которые зависят от заголовочный файлов. Они уже подключены к проекту. Находятся в lib/
Отредактировав файл CMakeLists.txt Вы можете изменить путь к библиотекам
```

### 2.1 Boost

* Скомпилируйте библиотеку как написано в [инструкции](https://www.boost.org/doc/libs/1_69_0/more/getting_started/windows.html)

или
* Скачайте динамические библиотеки(.dll)

### 2.2 SQLite3

* Скомпилируйте библиотеку

или

* Скачайте [.dll](https://www.sqlite.org/download.html)

## 3. Поиск библиотек
### 3.1 Простой способ

    1. Создать папку boost в корне диска C
        C:\boost
    2. Переместить .dll файлы библиотеки boost в папку boost/
        C:\boost\lib
    3. Переместить include файлы библиотеки boost в папку include/
        C:\boost\include
    4. Создать папку sqlite3 в корне диска C
        C:\sqlite3
    5. Переместить .dll файл библиотеки sqlite3 в папку lib/
        C:\sqlite3\lib\sqlite3.dll
    6. Переместить include файлы библиотеки sqlite3 в папку include/
        C:\sqlite3\include

### 3.2 Способ с использованием GUI CMake или cli CMake

    1. Пропишите пути к библиотекам

## 4. Создание Makefile и компиляция проекта

    1. Скачайте и распакуйте репозиторий
    2. Создайте папку build в любом удобном месте
    3. Запустите CMake
    4. Скомпилируйте код используя MinGW

Например:

    $ mkdir Battleship-Royale
    $ mkdir build
    $ cd build
    $ cmake ..\Battleship-Royale -G "MinGW Makefiles"
    $ mingw32-make


## Возможные ошибки

```
CMake Error at C:/Program Files/CMake/share/cmake-3.14/Modules/FindBoost.cmake:2124 (message):
  Unable to find the requested Boost libraries.

  Boost version: 1.69.0

  Boost include path: C:/boost/include/boost-1_69

  Could not find the following Boost libraries:

          boost_system

  Some (but not all) of the required Boost libraries were found.  You may
  need to install these additional Boost libraries.  Alternatively, set
  BOOST_LIBRARYDIR to the directory containing Boost libraries or BOOST_ROOT
  to the location of Boost.
Call Stack (most recent call first):
  CMakeLists.txt:36 (find_package)


-- Configuring incomplete, errors occurred!
```

```
Boost version: 1.69.0  - может отличаться
boost_system - может отличаться
C:/boost/include/boost-1_69 - может отличаться
```
CMake не нашёл библиотеку/модуль boost
Возможно переименование динамических библиотек boost поможет

Например:
```
boost_atomic-mgw81-mt-1_69.dll
boost_date_time-mgw81-mt-1_69.dll
boost_regex-mgw81-mt-1_69.dll
boost_system-mgw81-mt-1_69.dll
```

---
```
CMake Error at C:/Program Files/CMake/share/cmake-3.14/Modules/FindBoost.cmake:2124 (message):
  Unable to find the requested Boost libraries.

  Unable to find the Boost header files.  Please set BOOST_ROOT to the root
  directory containing Boost or BOOST_INCLUDEDIR to the directory containing
  Boost's headers.
Call Stack (most recent call first):
  CMakeLists.txt:36 (find_package)


CMake Error: The following variables are used in this project, but they are set to NOTFOUND.
Please set them or make sure they are set and tested correctly in the CMake files:
Boost_INCLUDE_DIR (ADVANCED)
   used as include directory in directory C:/Git/Battleship-Royale
   used as include directory in directory C:/Git/Battleship-Royale
   used as include directory in directory C:/Git/Battleship-Royale/src/server
   used as include directory in directory C:/Git/Battleship-Royale/src/server
   used as include directory in directory C:/Git/Battleship-Royale/src/server

-- Configuring incomplete, errors occurred!
```

CMake не нашёл include файлы библиотеки boost

---
```
C:\git\Battleship-Royale\build>mingw32-make
"mingw32-make" не является внутренней или внешней
командой, исполняемой программой или пакетным файлом.
```

MinGW не прописан в Path