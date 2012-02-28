all: test	

#preprocess: preprocess.cpp
#	g++ -o preprocess preprocess.cpp
#
#count-char: count-char.cpp
#	g++ -o count-char count-char.cpp
#
#generate-map: generate-map.cpp
#	g++ -o generate-map generate-map.cpp

test: test.cpp File.h File.cc
	g++ -o test test.cpp File.cc Vocab.cc NgramCountLM.cc zio.c Map.cc LHash.cc LM.cc NgramStats.cc FNgramStats.cc
