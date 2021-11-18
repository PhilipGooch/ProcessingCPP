#pragma once

#include "SFML/Graphics.hpp"

#include <iostream>

#define PI 3.141592653589f
#define HALF_PI PI / 2

namespace Processing
{
	class __declspec(dllexport) Application
	{
	public:
		Application();
		~Application();

		void run();

	protected:
		enum MODE
		{
			CORNER,
			CORNERS,
			CENTER,
			RADIUS
		};

	private:
		void display();

	protected:
		virtual void setup() {}
		virtual void update() {}
		virtual void draw() {}

		void size(int width, int height);
		void rect(int x, int y, int a, int b);
		void circle(int x, int y, int r);
		void ellipse(int x, int y, int a, int b);
		void ellipseMode(MODE mode);
		void background(float rgb);
		void background(float r, float g, float b);
		void rectMode(MODE mode);
		void fill(float rgb);
		void fill(float rgb, float a);
		void fill(float r, float g, float b);
		void fill(float r, float g, float b, float a);
		void stroke(float rgb);
		void stroke(float rgb, float a);
		void stroke(float r, float g, float b);
		void stroke(float r, float g, float b, float a);
		void strokeWeight(float weight);
		void noStroke();

	private:
		sf::RenderWindow* m_renderWindow;
		bool m_running = true;
		MODE m_rectMode = CORNER;
		MODE m_ellipseMode = RADIUS;
		sf::Color m_backgroundColor = sf::Color(200, 200, 200);
		sf::Color m_fillColor = sf::Color::White;
		sf::Color m_strokeColor = sf::Color::Black;
		int m_strokeWeight = 1;
	};
}

#define START class Application : public Processing::Application { public: Application() : Processing::Application() {} protected:
#define END }; int main() { Application application; application.run(); std::cin.get(); return 0; }