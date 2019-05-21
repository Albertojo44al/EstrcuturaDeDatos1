#include "Events.h"
#include <Windows.h>
#include <iostream>
#define FPS 60

using namespace std;
Events::Events(int width, int height, std::string title) {

	movements = new Event;
	window = new RenderWindow(VideoMode(width, height), title);
	window->setFramerateLimit(FPS);
	MangoT = new Texture;
	MangoT->loadFromFile("Imagenes/Mango.png");
	if (!font.loadFromFile("Imagenes/Minecraft.ttf")) {
		printf("error");
	}
	startMenu(width, height, 1);
	showMessage();

	if (joinTrees == 0)
		initializetextures1();

	Loop();
}

void Events::Draw1() {
	window->clear();
	window->draw(playerText);
	window->draw(*Background1S);
	window->draw(*TreeS);
	for (int i = 0; i < 6; i++) {
		window->draw(*MangoS[i]);
	}
	for (int i = 0; i < 6; i++) {
		window->draw(menu[i]);
	}
	window->draw(Weigth[0]);
	window->draw(Weigth[1]);
	window->draw(Error[0]);
	window->draw(Error[2]);
	window->display();

}
void Events::Draw2() {
	window->clear();

	window->draw(*Background2S);
	window->draw(*TreeS);
	window->draw(*TreeS2);
	for (int i = 0; i < 12; i++) {
		window->draw(*MangoS[i]);
	}

	for (int i = 0; i < 6; i++) {
		window->draw(menu[i]);

	}
	window->draw(Weigth[0]);
	window->draw(Weigth[1]);
	window->draw(Weigth[2]);
	window->draw(Error[0]);
	window->draw(Error[1]);
	window->draw(Error[2]);
	window->display();
}

void Events::Loop() {

	while (window->isOpen())
	{
		processMovements();
		mangoTree t;
		if (joinTrees == 0) {
			if (background2 == 1) {
				startMenu(1400, 720, 1);
				background2 = 0;
			}
			Draw1();

		}
		else {
			if (background2 == 0) {
				initializetextures2();
				startMenu(1400, 720, 2);
				background2 = 1;
			}
			Draw2();
		}
	}
}

void Events::initializetextures1() {
	Background1T = new Texture;
	Background1T->loadFromFile("Imagenes/fondo2.jpg");
	Background1S = new Sprite(*Background1T);
	Background1S->setScale((float)window->getSize().x / Background1T->getSize().x, (float)window->getSize().y / Background1T->getSize().y);

	TreeT = new Texture;
	TreeT->loadFromFile("Imagenes/arbol.png");
	TreeS = new Sprite(*TreeT);
	TreeS->setScale(450.f / TreeT->getSize().x, 680.f / TreeT->getSize().y);
	TreeS->setPosition(103, 50);

	for (int i = 0; i < 6; i++) {
		MangoS[i] = new Sprite(*MangoT);
		MangoS[i]->setPosition(200 + rand() % (481 - 200), 110 + rand() % (351 - 110));
		MangoS[i]->setColor(Color(255, 255, 255, 0));
	}


}
void Events::initializetextures2() {
	Background2T = new Texture;
	Background2T->loadFromFile("Imagenes/fondo.jpg");
	Background2S = new Sprite(*Background2T);
	Background2S->setScale((float)window->getSize().x / Background2T->getSize().x, (float)window->getSize().y / Background2T->getSize().y);

	TreeT = new Texture;
	TreeT->loadFromFile("Imagenes/arbol.png");
	TreeS = new Sprite(*TreeT);
	TreeS->setScale(450.f / TreeT->getSize().x, 680.f / TreeT->getSize().y);
	TreeS->setPosition(103, 50);

	TreeS2 = new Sprite(*TreeT);
	TreeS2->setScale(450.f / TreeT->getSize().x, 680.f / TreeT->getSize().y);
	TreeS2->setPosition(870, 50);


	for (int i = 6; i < 12; i++) {
		MangoS[i] = new Sprite(*MangoT);
		MangoS[i]->setPosition(900 + rand() % (1181 - 900), 110 + rand() % (351 - 110));
		MangoS[i]->setColor(Color(255, 255, 255, 0));
	}

}

void Events::processMovements() {
	playerText.setPosition(60, 300);
	playerText.setFillColor(Color::White);
	while (window->pollEvent(*movements)) {
		switch (movements->type)
		{
		case Event::Closed:
			window->close();
			exit(1);
			break;
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Up))
				moveUp();
			else if (Keyboard::isKeyPressed(Keyboard::Down))
				moveDown();
			else if (Keyboard::isKeyPressed(Keyboard::Enter)) {
				switch (getPressedItem()) {
				case 0: //add mangos in Tree 1
					Error[2].setFillColor(Color(255, 255, 255, 0));
					cout << "\ntype a weight:";
					cin >> mangoWeight;
					if (mango.mangoCounter < 6 && (mango.TotalWeight() + mangoWeight) <= 500) {
						mango.addMangoFruit(new mangoFruit(mangoWeight));
						std::cout << "\nadded mango in Tree1 " << mango.mangoCounter;
						Error[0].setFillColor(Color(255, 255, 255, 0));
						MangoS[mango.mangoCounter - 1]->setColor(Color(255, 255, 255, 255));
						MangoS[mango.mangoCounter - 1]->setOrigin(MangoT->getSize().x / 2.f, MangoT->getSize().y / 2.f);
						MangoS[mango.mangoCounter - 1]->setScale((2.f * mangoWeight) / MangoT->getSize().x, (2.f*mangoWeight) / MangoT->getSize().y);
						Weigth[1].setString("Tree1: " + to_string(mango.TotalWeight()) + "kg");
					}
					else {
						Error[0].setFillColor(Color(255, 255, 255, 255));
					}
					break;
				case 1: //Add mangos in tree 2
					Error[2].setFillColor(Color(255, 255, 255, 0));
					cout << "\ntype a weight:";
					cin >> mangoWeight;

					if (newList.mangoCounter < 6 && (newList.TotalWeight() + mangoWeight) <= 500) {
						newList.addMangoFruit(new mangoFruit(mangoWeight));
						std::cout << "\nadded mango in Tree2 " << newList.mangoCounter;
						MangoS[(newList.mangoCounter - 1) + 6]->setScale((2.f * mangoWeight) / MangoT->getSize().x, (2.f*mangoWeight) / MangoT->getSize().y);
						MangoS[(newList.mangoCounter - 1) + 6]->setOrigin(MangoT->getSize().x / 2.f, MangoT->getSize().y / 2.f);
						MangoS[(newList.mangoCounter - 1) + 6]->setColor(Color(255, 255, 255, 255));
						Weigth[2].setString("Tree2: " + to_string(newList.TotalWeight()) + "kg");
					}
					else {
						Error[1].setFillColor(Color(255, 255, 255, 255));
					}
					break;
				case 2: // delete mangos on both Trees
					Error[2].setFillColor(Color(255, 255, 255, 0));
					if (joinTrees == 1) {
						if (newList.mangoCounter > 0) {
							newList.deleteMangoFruit(1);
							Error[1].setFillColor(Color(255, 255, 255, 0));
							MangoS[newList.mangoCounter + 6]->setColor(Color(255, 255, 255, 0));
							Weigth[2].setString("Tree2: " + to_string(newList.TotalWeight()) + "kg");
						}
						else {
							mango.deleteMangoFruit(1);
							Error[0].setFillColor(Color(255, 255, 255, 0));
							MangoS[mango.mangoCounter]->setColor(Color(255, 255, 255, 0));
							Weigth[1].setString("Tree1: " + to_string(mango.TotalWeight()) + "kg");
						}
					}
					else {
						mango.deleteMangoFruit(1);
						Error[0].setFillColor(Color(255, 255, 255, 0));
						MangoS[mango.mangoCounter]->setColor(Color(255, 255, 255, 0));
						Weigth[1].setString("Tree1: " + to_string(mango.TotalWeight()) + "kg");
					}

					std::cout << "\nremoved mango\n";
					break;
				case 3: // join Trees
					Error[2].setFillColor(Color(255, 255, 255, 0));
					if (joinTrees != 0) {
						joinTrees = 0;
						mango = mango.joinTrees(mango, newList);
						newList = newTree;
						Weigth[1].setString("Tree1: " + to_string(mango.TotalWeight()) + "kg");
						for (int i = 0; i < mango.mangoCounter; i++) {
							MangoS[i]->setColor(Color(255, 255, 255, 255));
							MangoS[i]->setScale((2.f * (float)mango.mangoWeight(i)) / MangoT->getSize().x, (2.f* (float)mango.mangoWeight(i)) / MangoT->getSize().y);
							MangoS[i]->setOrigin(MangoT->getSize().x / 2.f, MangoT->getSize().y / 2.f);
						}
					}
					else {

						joinTrees = 1;
						Weigth[2].setString("Tree2: " + to_string(newList.TotalWeight()) + "kg");
					}
					break;
				case 4: //insert mangos
					Error[2].setFillColor(Color(255, 255, 255, 0));
					cout << "\nType a weight:";
					cin >> mangoWeight;
					cout << "type a position:";
					cin >> position;
					if (mango.mangoCounter < 6 && (mango.TotalWeight() + mangoWeight) <= 500) {
						if (mango.insertMangoFruit(new mangoFruit(mangoWeight), position) == -1) {
							Error[2].setFillColor(Color(255, 255, 255, 255));
						}
						else {
							Error[2].setFillColor(Color(255, 255, 255, 0));
							MangoS[mango.mangoCounter - 1]->setColor(Color(255, 255, 255, 255));
							MangoS[mango.mangoCounter - 1]->setOrigin(MangoT->getSize().x / 2.f, MangoT->getSize().y / 2.f);
							MangoS[(mango.mangoCounter - 1)]->setScale((2.f * mangoWeight) / MangoT->getSize().x, (2.f*mangoWeight) / MangoT->getSize().y);
							Weigth[1].setString("Tree1: " + to_string(mango.TotalWeight()) + "kg");
						}
					}
					else {
						Error[0].setFillColor(Color(255, 255, 255, 255));
					}

					break;
				case 5:
					window->close();
					exit(1);
					break;
				}


			}
			break;
		}
	}
}

void Events::startMenu(int width, int height, int numberMenu) {
	if (numberMenu == 1) {
		menu[0].setString("Add a mango");
		menu[1].setString("");
		menu[0].setPosition(Vector2f(width / 1.5, height / 9));
		menu[2].setPosition(Vector2f(width / 1.5, height / (9) * (2)));
		menu[3].setPosition(Vector2f(width / 1.5, height / (9) * (3)));
		menu[4].setPosition(Vector2f(width / 1.5, height / (9) * (4)));
		menu[5].setPosition(Vector2f(width / 1.5, height / (9) * (5)));
		menu[3].setString("Add tree");
	}
	else {
		for (int i = 0; i < 6; i++) {
			menu[i].setPosition(Vector2f(550, height / (9) * (i + 1)));
		}
		menu[0].setString("Add a mango in Tree 1");
		menu[1].setFont(font);
		menu[1].setFillColor(Color::Black);
		menu[1].setString("Add a mango in Tree 2");
		menu[3].setString("Join trees");
	}
	menu[0].setFont(font);
	menu[0].setFillColor(Color::White);

	menu[2].setFont(font);
	menu[2].setFillColor(Color::Black);
	menu[2].setString("Delete mango");

	menu[3].setFont(font);
	menu[3].setFillColor(Color::Black);

	menu[4].setFont(font);
	menu[4].setString("Insert a mango");
	menu[4].setFillColor(Color::Black);

	menu[5].setFont(font);
	menu[5].setString("Exit");
	menu[5].setFillColor(Color::Black);


	selectedItemIndex = 0;
}

void Events::moveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::White);
	}
}
void Events::moveDown() {
	if (selectedItemIndex + 1 < 6) {
		menu[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::White);
	}
}

int Events::getPressedItem() {
	return selectedItemIndex;
}

