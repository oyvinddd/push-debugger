build:
	g++ -Wall -Werror *.cpp -o ./out/push

run: build 
	./out/push

clean:
	rm -rf ./out/*

