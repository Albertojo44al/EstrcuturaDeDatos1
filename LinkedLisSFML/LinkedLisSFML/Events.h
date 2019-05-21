#pragma once
#include "SFML/Graphics.hpp"
#include "mangoTree.h"
using namespace sf;

class Events {
	String playerInput;
	Text playerText;
	Event e;
	mangoTree newTree;
	int background2 = 0;
	mangoTree mango;
	mangoTree newList;
	double mangoWeight = 0;
	int position = 0;
	RenderWindow * window;
	Texture * Background1T;
	Texture * Background2T;
	Texture * TreeT;
	Texture * MangoT;
	Sprite * Background1S;
	Sprite * Background2S;
	Sprite * TreeS;
	Sprite * TreeS2;
	Sprite * MangoS[12];
	Event * movements;
	int selectedItemIndex;
	int joinTrees = 0;

	Font font;
	Text menu[6];
	Text Error[3];
	Text Weigth[3];
	Text textBox[2];
public:

	Events(int resolution_x, int resolution_y, std::string title);
	void Draw1();
	void Draw2();
	void Loop();
	void initializetextures1();
	void initializetextures2();
	void processMovements();
	void moveUp();
	void moveDown();
	void startMenu(int width, int heigth, int numberMenu);
	int getPressedItem();
	void showMessage();
};