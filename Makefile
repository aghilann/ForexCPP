CC = g++
CFLAGS = -std=c++17 -lcurl -Llibs/rapidjson
DEPS = util.h ExchangeRates.h Graph.h Vertex.h
OBJ = bin/main.o bin/util.o bin/ExchangeRates.o bin/Graph.o bin/Vertex.o
TARGET = bin/main
CXXFLAGS += -Ilibs/rapidjson/include/rapidjson/document.h

bin/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	$(RM) $(TARGET) $(OBJ)
