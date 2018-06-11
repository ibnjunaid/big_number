all:compile run

compile:
	@g++ -std=c++17 main-draft.cpp -o run.out

run:
	@run.out



