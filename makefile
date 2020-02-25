all: libjablko3d.so driver


libjablko3d.so: vect.o stl.o
	g++ -shared objects/vect.o objects/stl.o -o libjablko3d.so

vect.o: source/vect.cpp
	g++ -fPIC -c source/vect.cpp -o objects/vect.o

stl.o: source/stl.cpp
	g++ -fPIC -c source/stl.cpp -o objects/stl.o

driver: tests/driver.cpp
	g++ -Wl,-rpath,../Jablko3D tests/driver.cpp -L. -ljablko3d -o driver
	
clean:
	rm objects/*.o
	rm driver
