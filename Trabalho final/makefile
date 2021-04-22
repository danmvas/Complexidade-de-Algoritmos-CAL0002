all:
	-g++ -c -w ./*/*.h ./*/*.cpp -O2
	-mkdir .compiled
	-mv ./*/*.gch ./.compiled/ 
	-mv *.o .compiled/
	-g++ -w main.cpp -o main -O2
	-g++ -w file_tester.cpp -o file_tester -O2


.PHONY: clean

clean:
	-rm -f -r .compiled
	-rm -f main
	-rm -f file_tester