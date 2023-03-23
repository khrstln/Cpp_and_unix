# Лабораторная работа №1: [C++ & UNIX]: UNIX знакомство: useradd, nano, chmod, docker, GIT, CI, CD #
Хрусталев И. Д., ФФ ИТМО, Z33434

## Цель
Познакомить студента с основами администрирования программных комплексов в ОС
семейства UNIX, продемонстрировать особенности виртуализации и контейнеризации,
продемонстрировать преимущества использования систем контроля версий (на
примере GIT)

## Отчет о выполнении

1. [ОС] Работа в ОС, использование файловой системы, прав доступа, исполение файлов

    1. В папке /USR/LOCAL/ создать 2 директории: folder_max, folder_min
    ```
    khrstln@LinuxUbuntu:~$ cd /usr/local
    khrstln@LinuxUbuntu:/usr/local$ mkdir folder_max
    khrstln@LinuxUbuntu:/usr/local$ mkdir folder_max
    
    khrstln@LinuxUbuntu:/usr/local$ ls
    bin           dockerfile  folder_min  lib         sbin
    Cpp_and_unix  etc         games       man         share
    date.sh       folder_max  include     output.log  src
    ```
    
    
    2. Создать 2-х группы пользователей: group_max, group_min
    ```
    khrstln@LinuxUbuntu:/usr/local sudo groupadd group_max
    khrstln@LinuxUbuntu:/usr/local$ sudo groupadd group_min
    
    khrstln@LinuxUbuntu:/usr/local$ grep 'group_max' /etc/group
    group_max:x:1001:
    
    khrstln@LinuxUbuntu:/usr/local$ grep 'group_min' /etc/group
    group_min:x:1002:
    ```
    3. Создать 2-х пользователей: user_max_1, user_min_1
    ```
    khrstln@LinuxUbuntu:/usr/local$ sudo useradd user_max_1
    khrstln@LinuxUbuntu:/usr/local$ sudo useradd user_min_1
    
    khrstln@LinuxUbuntu:/usr/local$ members group_max
    user_max_1
    
    khrstln@LinuxUbuntu:/usr/local$ members group_min
    user_min_1
    ```
    4. Для пользователей из группы *_max дать полный доступ на директории *_max и *_min. Для пользователей группы *_min дать полный доступ только на директорию *_min
    ```
    khrstln@LinuxUbuntu:/usr/local$ sudo chmod a=rwx folder_min
    khrstln@LinuxUbuntu:/usr/local$ sudo chmod o-w folder_max
    
    khrstln@LinuxUbuntu:/usr/local$ ls -l
    ...
    drwxrwxr-x 2 root    group_max  4096 мар 12 22:17 folder_max
    drwxrwxrwx 2 root    group_min  4096 мар 12 22:19 folder_min
    ...
    ```


    5. Создать и исполнить (пользователем из той же категории) скрипт в директории folder_max, который пишет текущую дату/время в файл output.log в текущей директории
    ```
    khrstln@LinuxUbuntu:/usr/local/folder_max$ su - user_max_1
    $ whoami
    user_max_1
    $ touch date.sh
    ```
    
    После создания файла в директории folder_max открываем его с помощью команды 
    ```
    $ nano date.sh
    ```
    
    Пишем в файл следующий скрипт
    ```
    #!/bin/bash
    date  >> /usr/local/folder_max/output.log
    ```
    
      Чтобы исполнить файл, в терминале пишем следующие команды
    ```
    $ chmod g=rwx date.sh
    $ ./date.sh
    ```

    6. Создать и исполнить (пользователем из той же категории) скрипт в директории folder_max, который пишет текущую дату/время в файл output.log в директории *_min
    ```
    $ touch date_in_min.sh
    ```
    
    После создания файла в директории folder_max открываем его с помощью команды 
    ```
    $ nano date_in_min.sh
    ```
    
    Пишем в файл следующий скрипт
    ```
    #!/bin/bash
    date  >> /usr/local/folder_min/output_from_max.log
    ```
    
    Чтобы исполнить файл, в терминале пишем следующие команды
    ```
    $ chmod a=rwx date_in_min.sh
    $ bash date_in_min.sh
    ```


    7. Исполнить (пользователем *_min) скрипт в директории folder_max, который пишет текущую дату/время в файл output.log в директории *_min
    ```
    $ whoami
    user_min_1
    $ pwd
    /usr/local/folder_max
    $ bash date_in_min.sh
    ```


    8. Создать и исполнить (пользователем из той же категории) скрипт в директории folder_min, который пишет текущую дату/время в файл output.log в директории *_max
    ```
    $ cd ..
    $ cd folder_min
    $ pwd
    /usr/local/folder_min
    $ touch date_in_max.sh
    ```
    
    После создания файла в директории folder_max открываем его с помощью команды 
    ```
    $ nano date_in_max.sh
    ```
    
    Пишем в файл следующий скрипт
    ```
    #!/bin/bash
    date  >> /usr/local/folder_max/output_from_min.log
    ```
    
    Чтобы исполнить файл, в терминале пишем следующие команды
    ```
    $ chmod a=rwx date_in_min.sh
    $ bash date_in_min.sh
    ```
    


    9. Вывести перечень прав доступа у папок *_min/ *_max, а также у всего содержимого внутри
    ```
    khrstln@LinuxUbuntu:/usr/local$ ls -l
    drwxrwxr-x 2 root    group_max  4096 мар 23 17:27 folder_max
    drwxrwxrwx 2 root    group_min  4096 мар 23 18:02 folder_min
    ```

2. [КОНТЕЙНЕР] docker build / run / ps / images
    1. Создать скрипт, который пишет текущую дату/время в файл output.log в текущей директории
    
    Будем работать в директории /usr/local
    ```
    touch
    ````
    
