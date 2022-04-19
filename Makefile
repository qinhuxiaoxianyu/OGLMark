all:
	g++ -Iinclude src/* main.cpp -lGL -lglfw -ldl -lX11 -lpthread -lassimp -o main

#一些命名规范，文件名和函数名小写和下划线，类名大写分割