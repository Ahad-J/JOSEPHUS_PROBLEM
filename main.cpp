#include <iostream>
#include <queue>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <cmath>

using namespace std;

int josephus(int N, int K, vector<int>& eliminationOrder) {
   srand(time(0));
   queue<int> circle;
   int loc = 0 + rand() % N;
   for (int i = 0; i < N; i++)
       circle.push(i);

   for (int i = 0; i <= loc; i++) {
       circle.push(circle.front());
       circle.pop();
   }
   while (circle.size() > 1) {
       for (int i = 0; i < K - 1; i++) {
           circle.push(circle.front());
           circle.pop();
       }
       eliminationOrder.push_back(circle.front());
       circle.pop();
   }
   return circle.front();
}

int main() {
   int N, K;
   cout << "Enter the number of people (N): ";
   cin >> N;
   cout << "Enter the count step (K): ";
   cin >> K;

   vector<int> eliminationOrder;
   int survivor = josephus(N, K, eliminationOrder);
   cout << "The survivor is person: " << survivor << endl;

   sf::RenderWindow window(sf::VideoMode(1000, 1000), "Josephus Problem Visualization");
   sf::Texture aliveTexture, deadTexture;
   aliveTexture.loadFromFile("1.png");
   deadTexture.loadFromFile("2.png");

   sf::Music backgroundMusic;
   backgroundMusic.openFromFile("1.ogg");
   backgroundMusic.setLoop(true);
   backgroundMusic.play();

   sf::SoundBuffer swordSlashBuffer;
   swordSlashBuffer.loadFromFile("1.wav");
   sf::Sound swordSlashSound;
   swordSlashSound.setBuffer(swordSlashBuffer);

   float maxRadius = 400.0f;
   float baseSpriteSize = 50.0f;
   float scaleFactor = min(2.0f, (maxRadius / N));
   float scaledSpriteSize = baseSpriteSize * scaleFactor;

   vector<sf::Sprite> peopleSprites(N);
   vector<sf::CircleShape> statusCircles(N);
   vector<bool> eliminated(N, false);

   for (int i = 0; i < N; i++) {
       peopleSprites[i].setTexture(aliveTexture);
       peopleSprites[i].setScale(scaledSpriteSize / aliveTexture.getSize().x, scaledSpriteSize / aliveTexture.getSize().y);

       float circleRadius = scaledSpriteSize / 2.5f;
       statusCircles[i].setRadius(circleRadius);
       statusCircles[i].setFillColor(sf::Color::Green);
       statusCircles[i].setOrigin(circleRadius, circleRadius);

       float angle = i * (2.0f * 3.1415 / N);
       float radius = maxRadius * 0.9f;

       float posX = ((window.getSize().x) - 100) / 2 + radius * cos(angle);
       float posY = ((window.getSize().y) - 100) / 2 + radius * sin(angle);

       peopleSprites[i].setPosition(posX, posY);
       statusCircles[i].setPosition(posX + 50, posY + 50);
   }

   int currentIndex = 0;

   while (window.isOpen()) {
       sf::Event event;
       while (window.pollEvent(event)) {
           if (event.type == sf::Event::Closed)
               window.close();
       }

       window.clear();

       for (int i = 0; i < N; i++) {
           window.draw(statusCircles[i]);
           window.draw(peopleSprites[i]);
       }

       window.display();

       if (currentIndex < eliminationOrder.size()) {
           int eliminatedPerson = eliminationOrder[currentIndex];
           eliminated[eliminatedPerson] = true;

           swordSlashSound.play();

           statusCircles[eliminatedPerson].setFillColor(sf::Color::Red);
           peopleSprites[eliminatedPerson].setTexture(deadTexture);

           sf::sleep(sf::seconds(1));
           ++currentIndex;
       }
   }

   return 0;
}
