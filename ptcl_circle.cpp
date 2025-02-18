//circlular motion of a particle graph
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <optional>


using namespace std;

int main() {
  double x0, y0, R, x, y, vx, vy, t, t0, tf, dt;
  double theta, omega;
  double PI = 3.141592653589793;
  string buf , buf1 , buf2 ;
  // User inputs
  cout << "# Enter omega:\n";
  cin >> omega;
  getline(cin, buf);
  cout << "# Enter center of circle (x0, y0, R):\n";
  cin >> x0 >> y0 >> R;
  getline(cin, buf1);
  cout << "# Enter time t0, tf, dt:\n";
  cin >> t >> tf >> dt;
  getline(cin, buf2);
  cout << "omega = " << omega << endl;
  cout << "x = " << x0 << "y = " << y0 << "R = " << R << endl;
  cout << "t0 = " << t0 << "tf = " << tf << "dt = " << dt << endl;

  // Input validation
  if (R <= 0.0) {cerr << "Error: R must be positive." << endl; exit(1);}
  if (omega <= 0.0) {cerr << "Error: omega must be positive." << endl; exit(1);}
  cout << "T= " << 2.0 * PI / omega << endl;
  std::ofstream myfile("circle.dat");
  myfile.precision(17);

  sf::RenderWindow window(sf::VideoMode({800, 600}), "display");

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
      {
        window.close();
      }
      else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
      {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
          window.close();
      }
    }

    sf::CircleShape point(1.f);
    point.setFillColor(sf::Color(255,0,0));
    t = t0;
    while (t < tf) {
      theta = omega * (t-t0);
      x = x0 + R*cos(theta);
      y = y0 + R*sin(theta);
      vx = -omega*R*sin(theta);
      vy = omega*R*cos(theta);
      myfile << x << " " << y << " " << vx << " " << vy << endl;
      point.setPosition({static_cast<float>(x), static_cast<float>(y)});
      t = t + dt;
      window.draw(point);
    }
    t0 = 0.0;
    window.display();
  }


}


