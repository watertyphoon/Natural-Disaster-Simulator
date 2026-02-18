a.out: main.o particle_class.o game_class.o world_class.o
	g++ main.o particle_class.o game_class.o world_class.o
main.o: main.cc particle_class.h game_class.h world_class.h
	g++ -c main.cc
particle_class.o: particle_class.cc particle_class.h
	g++ -c particle_class.cc
game_class.o: game_class.cc game_class.h
	g++ -c game_class.cc
world_class.o: world_class.cc world_class.h
	g++ -c world_class.cc
clean:
	rm -f *.o a.out core_
