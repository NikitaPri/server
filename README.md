Приложение реализовано в виде двух исполняемых файлов: socket и threads.
socket отвечает за создание сетевого соединения, принимает один аргумент - порт, который слушать, таким образом запуск выглядит так
./socket 2222
Далее после получения матрицы вызывает threads
threads отвечает за перемножение матриц многопоточно путем вызова в конечном счете системного вызова clone с флагом CLONE_VM(создаваемый процесс работает в общем адресном простравнстве с родительским процессом). Последовательно создается от 1 до NxN(N-размерность матрицы) и вычиляется время, затраченное на перемножение матриц с 1 потоком, 2 потоками и тд, возвращается количество потоков, которое позволило перемножить матрицы с минимальным временем и отправляется по установленному сетевому соединению
Hикитa Пpивaлoв
