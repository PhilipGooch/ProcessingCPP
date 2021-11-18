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
		if (!m_renderWindow)
		{
			std::cout << "Missing size() function." << std::endl;
			running = false;
		}
		while (running)
		{
			sf::Event event;
			while (m_renderWindow->pollEvent(event))
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
		if (m_renderWindow)
		{
			m_renderWindow->close();
		}
		return;
	}

	void Application::display()
	{
		m_renderWindow->display();
	}

	void Application::size(int width, int height)
	{
		m_renderWindow = new sf::RenderWindow(sf::VideoMode(width, height), "");
		m_renderWindow->clear(m_backgroundColor);
		m_renderWindow->display();
		m_renderWindow->clear(m_backgroundColor);
	}

	void Application::rect(int x, int y, int a, int b)
	{
		sf::RectangleShape r;
		r.setFillColor(m_fillColor);
		r.setOutlineColor(m_strokeColor);
		r.setOutlineThickness(m_strokeWeight);
		r.setPosition(sf::Vector2f(x, y));
		switch (m_rectMode)
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
		m_renderWindow->draw(r);
	}

	void Application::circle(int x, int y, int extent)
	{
		sf::CircleShape c;
		c.setFillColor(m_fillColor);
		c.setOutlineColor(m_strokeColor);
		c.setOutlineThickness(m_strokeWeight);
		c.setPosition(sf::Vector2f(x, y));
		c.setRadius(extent / 2);
		c.setOrigin(sf::Vector2f(extent / 2, extent / 2));
		m_renderWindow->draw(c);
	}

	void Application::ellipse(int x, int y, int a, int b)
	{
		sf::CircleShape inside;
		inside.setFillColor(m_fillColor);
		inside.setPosition(sf::Vector2f(x, y));
		inside.setRadius(0.5f);
		inside.scale(sf::Vector2f(a, b));
		
		sf::CircleShape outside;
		outside.setFillColor(m_strokeColor);
		outside.setPosition(sf::Vector2f(x - m_strokeWeight, y - m_strokeWeight));
		outside.setRadius(0.5f);
		outside.scale(sf::Vector2f(a + m_strokeWeight * 2, b + m_strokeWeight * 2));

		m_renderWindow->draw(outside);
		m_renderWindow->draw(inside);
	}

	void Application::ellipseMode(MODE mode)
	{
		m_ellipseMode = mode;
	}

	void Application::background(float rgb)
	{
		m_renderWindow->clear(sf::Color(rgb, rgb, rgb));
	}

	void Application::background(float r, float g, float b)
	{
		m_renderWindow->clear(sf::Color(r, g, b));
	}

	void Application::rectMode(MODE mode)
	{
		m_rectMode = mode;
	}

	void Application::fill(float rgb)
	{
		m_fillColor = sf::Color(rgb, rgb, rgb);
	}

	void Application::fill(float rgb, float a)
	{
		m_fillColor = sf::Color(rgb, rgb, rgb, a);
	}

	void Application::fill(float r, float g, float b)
	{
		m_fillColor = sf::Color(r, g, b);
	}

	void Application::fill(float r, float g, float b, float a)
	{
		m_fillColor = sf::Color(r, g, b, a);
	}

	void Application::stroke(float rgb)
	{
		m_strokeColor = sf::Color(rgb, rgb, rgb);
	}

	void Application::stroke(float rgb, float a)
	{
		m_strokeColor = sf::Color(rgb, rgb, rgb, a);
	}

	void Application::stroke(float r, float g, float b)
	{
		Application::m_strokeColor = sf::Color(r, g, b);
	}

	void Application::stroke(float r, float g, float b, float a)
	{
		Application::m_strokeColor = sf::Color(r, g, b, a);
	}

	void Application::strokeWeight(float weight)
	{
		m_strokeWeight = weight;
	}
	void Application::noStroke()
	{
		m_strokeWeight = 0;
	}
}