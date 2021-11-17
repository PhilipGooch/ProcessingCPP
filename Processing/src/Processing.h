#pragma once

#include "SFML/Graphics.hpp"

#include <iostream>

namespace Processing
{
	class __declspec(dllexport) Application
	{
	public:
		Application();
		~Application();

		void run();

	protected:
		enum RECT_MODE
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
		void background(float rgb);
		void background(float r, float g, float b);
		void rectMode(RECT_MODE mode);
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
		sf::RenderWindow* g_renderWindow;
		bool g_running = true;
		RECT_MODE g_rectMode = CORNER;
		sf::Color g_backgroundColor = sf::Color(200, 200, 200);
		sf::Color g_fillColor = sf::Color::White;
		sf::Color g_strokeColor = sf::Color::Black;
		int g_strokeWeight = 1;
	};
}

#define START class Application : public Processing::Application { public: Application() : Processing::Application() {} protected:
#define END }; int main() { Application application; application.run(); std::cin.get(); return 0; }