objects = source/main.o class/client.o class/server.o
cFiles = source/main.cpp class/client.cpp class/server.cpp

ChatServer : $(objects)
	clang++ -o ChatServer -L/usr/local/mysql/lib -lmysqlclient $? && install_name_tool -change @rpath/libmysqlclient.21.dylib /usr/local/mysql/lib/libmysqlclient.21.dylib ChatServer

$(objects) : $(cFiles)
	clang++ -std=c++17 -c -I/usr/local/mysql/include $*.cpp -o $@

.PHONY: clean
clean:
	rm source/*.o class/*.o
