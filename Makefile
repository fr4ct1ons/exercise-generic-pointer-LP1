graal_client: main.o graal.o
	g++ -Wall -std=c++11 -I include/ -o graal_client main.o graal.o 

main.o: driver/main.cpp
	g++ -Wall -std=c++11 -I include/ -c driver/main.cpp

graal.o: source/graal.cpp
	g++ -Wall -std=c++11 -I include/ -c source/graal.cpp
