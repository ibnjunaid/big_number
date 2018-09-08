all:compile run

compile:
	@g++ -std=c++17 ./src/main-draft.cpp -o run.out

run:
	@./src/run.out



