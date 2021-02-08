cpp := $(wildcard source/*.cpp)
flags := -DGLEW_STATIC -Wall -std=c++17 #-mwindows
inc := -IC:/Users/Ioannis/Desktop/Coding/include
lib := -LC:/Users/Ioannis/Desktop/Coding/include/GL/lib/Release/x64 -LC:/Users/Ioannis/Desktop/Coding/include/glfw/lib -L"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.18362.0/um/x64" -static -lglfw3 -lglew32s -lglu32 -lopengl32 -lgdi32 -luser32

make:
	g++ -o build/program.exe $(cpp) $(flags) $(inc) $(lib)