CPP = g++
CFLAGS = -I -Wall -g -std=c++17 -lpthread
DEPS =  -L/usr/lib/python3.8/config-3.8-x86_64-linux-gnu -lpython3.8
app :app.cpp 
	$(CPP) $(CFLAGS) app.cpp -o app `pkg-config --cflags --libs opencv dlib-1` \
	 -I/usr/include/python3.8 -lopenblas -lpthread 

.PHONY: app

