```

   ___       __  __  __        __   _          ___                 __   
  / _ )___ _/ /_/ /_/ /__ ___ / /  (_)__  ____/ _ \___  __ _____ _/ /__ 
 / _  / _ `/ __/ __/ / -_|_-</ _ \/ / _ \/___/ , _/ _ \/ // / _ `/ / -_)
/____/\_,_/\__/\__/_/\__/___/_//_/_/ .__/   /_/|_|\___/\_, /\_,_/_/\__/ 
                                  /_/                 /___/             

```

## Dependencies
* **[CMake](http://www.cmake.org/) 2.8.3**+ (compile-time only)
* **[Boost](http://www.boost.org/) 1.48**+
* **[SQLite3](https://www.sqlite.org/) 3.20.0**+

* cxxopts*
* picosha2*
* spdlog*

*Библиотека уже подключена к проекту

1. Boost modules:
```
system
thread
regex
```
2. SQLite3 need headers and lib

## Compile

For Linux run:

    $ mkdir build && cd build
    $ cmake ..
    $ make

For Windows:

	$ mkdir build && cd build
    $ cmake .. -G "MinGW Makefiles"
    $ mingw32-make

## Папки и файлы

|Папка		|Описание		|
|-----------|---------------|
|assets/ 	| Материалы		|
|cmake/ 	| Модули CMake	|
|lib/ 		| Библиотеки	|
|src/ 		| Исходный код	|

|Файл				|Описание			|
|-------------------|-------------------|
|CMakeLists.txt		|CMake				|
|README.md			|Описание проекта	|

## Руководство

|								|Описание				|
|-------------------------------|-----------------------|
|manual\install_windows.md		|Установка под Windows	|
|install_linux.md				|Установка под Linux	|