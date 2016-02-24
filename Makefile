rtd_prog: main.cpp crc.o gff.o i2c.o
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} crc.o gff.o i2c.o main.cpp -o rtd_prog

crc.o: crc.cpp crc.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -c -o crc.o crc.cpp

gff.o: gff.cpp gff.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -c -o gff.o gff.cpp

i2c.o: i2clinux.cpp i2c.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -c -o i2c.o i2clinux.cpp

clean:
	rm -f *.o rtd_prog
