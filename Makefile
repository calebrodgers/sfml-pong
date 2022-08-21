sfml-pong: main.cpp player.h ball.h scoreboard.h
	g++ main.cpp -o sfml-pong -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-pong