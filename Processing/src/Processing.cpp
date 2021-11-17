#include "Processing.h"

namespace Processing
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		bool running = true;
		setup();
		if (!g_renderWindow)
		{
			std::cout << "Missing size() function." << std::endl;
			running = false;
		}
		while (running)
		{
			sf::Event event;
			while (g_renderWindow->pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					running = false;
					break;
				}
			}
			update();
			draw();
			display();
		}
		if (g_renderWindow)
		{
			g_renderWindow->close();
		}
		return;
	}

	void Application::display()
	{
		g_renderWindow->display();
	}

	void Application::size(int width, int height)
	{
		g_renderWindow = new sf::RenderWindow(sf::VideoMode(width, height), "");
		g_renderWindow->clear(g_backgroundColor);
		g_renderWindow->display();
		g_renderWindow->clear(g_backgroundColor);
	}

	void Application::rect(int x, int y, int a, int b)
	{
		sf::RectangleShape r;
		r.setFillColor(g_fillColor);
		r.setOutlineColor(g_strokeColor);
		r.setOutlineThickness(g_strokeWeight);
		r.setPosition(sf::Vector2f(x, y));
		switch (g_rectMode)
		{
		case CORNER:
			r.setSize(sf::Vector2f(a, b));
			break;
		case CORNERS:
			r.setSize(sf::Vector2f(a - x, b - y));
			break;
		case CENTER:
			r.setOrigin(sf::Vector2f(a / 2, b / 2));
			r.setSize(sf::Vector2f(a, b));
			break;
		case RADIUS:
			r.setOrigin(sf::Vector2f(a / 2, b / 2));
			r.setSize(sf::Vector2f(a / 2, b / 2));
			break;
		}
		g_renderWindow->draw(r);
	}

	void Application::background(float rgb)
	{
		g_renderWindow->clear(sf::Color(rgb, rgb, rgb));
	}

	void Application::background(float r, float g, float b)
	{
		g_renderWindow->clear(sf::Color(r, g, b));
	}

	void Application::rectMode(RECT_MODE mode)
	{
		g_rectMode = mode;
	}

	void Application::fill(float rgb)
	{
		g_fillColor = sf::Color(rgb, rgb, rgb);
	}

	void Application::fill(float rgb, float a)
	{
		g_fillColor = sf::Color(rgb, rgb, rgb, a);
	}

	void Application::fill(float r, float g, float b)
	{
		g_fillColor = sf::Color(r, g, b);
	}

	void Application::fill(float r, float g, float b, float a)
	{
		g_fillColor = sf::Color(r, g, b, a);
	}

	void Application::stroke(float rgb)
	{
		g_strokeColor = sf::Color(rgb, rgb, rgb);
	}

	void Application::stroke(float rgb, float a)
	{
		g_strokeColor = sf::Color(rgb, rgb, rgb, a);
	}

	void Application::stroke(float r, float g, float b)
	{
		Application::g_strokeColor = sf::Color(r, g, b);
	}

	void Application::stroke(float r, float g, float b, float a)
	{
		Application::g_strokeColor = sf::Color(r, g, b, a);
	}

	void Application::strokeWeight(float weight)
	{
		g_strokeWeight = weight;
	}
	void Application::noStroke()
	{
		g_strokeWeight = 0;
	}
}