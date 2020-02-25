all: libjablko3d.so driver


libjablko3d.so: vect.o stl.o
	g++ -shared vect.o stl.o -o libjablko3d.so

vect.o: vect.cpp
	g++ -fPIC -c vect.cpp

stl.o: stl.cpp
	g++ -fPIC -c stl.cpp

driver: driver.cpp
	g++ -Wl,-rpath,../Jablko3D driver.cpp -L. -ljablko3d -o driver
	
clean:
	rm *.o
	rm driver
