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
		sf::Clock clock;
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
			std::cout << clock.restart().asMicroseconds() << std::endl;
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

	void Application::rect(int x, int y, int a, int b, int c)
	{
		int savedStrokeWeight = m_strokeWeight;
		c = std::min(c, std::min((a - x) / 2, (b - y) / 2));
		switch (m_rectMode)
		{
		case CORNER:
			break;
		case CORNERS:
			rect(x, y + c, a, b - c);
			rect(x + c, y, a - c, b);
			circle(x + c, y + c, c * 2);
			circle(a - c, y + c, c * 2);
			circle(a - c, b - c, c * 2);
			circle(x + c, b - c, c * 2);
			noStroke();
			rect(x, y + c, a, b - c);
			rect(x + c, y, a - c, b);
			circle(x + c, y + c, c * 2);
			circle(a - c, y + c, c * 2);
			circle(a - c, b - c, c * 2);
			circle(x + c, b - c, c * 2);
			stroke(savedStrokeWeight);
			break;
		case CENTER:
			break;
		case RADIUS:
			break;
		}
	}

	void Application::rect(int x, int y, int a, int b, int c, int d, int e, int f)
	{
		int savedStrokeWeight = m_strokeWeight;
		//c = std::min(c, std::min((a - x) / 2, (b - y) / 2));
		sf::ConvexShape convex;
		switch (m_rectMode)
		{
		case CORNER:
			break;
		case CORNERS:
			circle(x + c, y + c, c * 2);
			circle(a - d, y + d, d * 2);
			circle(a - e, b - e, e * 2);
			circle(x + f, b - f, f * 2);
			convex.setFillColor(m_fillColor);
			convex.setOutlineColor(m_strokeColor);
			convex.setOutlineThickness(m_strokeWeight);
			convex.setPointCount(8);
			convex.setPoint(0, sf::Vector2f(x, y + c));
			convex.setPoint(1, sf::Vector2f(x + c, y));
			convex.setPoint(2, sf::Vector2f(a - d, y));
			convex.setPoint(3, sf::Vector2f(a, y + d));
			convex.setPoint(4, sf::Vector2f(a, b - e));
			convex.setPoint(5, sf::Vector2f(a - e, b));
			convex.setPoint(6, sf::Vector2f(x + f, b));
			convex.setPoint(7, sf::Vector2f(x, b - f));
			m_renderWindow->draw(convex);
			noStroke();
			circle(x + c, y + c, c * 2);
			circle(a - d, y + d, d * 2);
			circle(a - e, b - e, e * 2);
			circle(x + f, b - f, f * 2);
			strokeWeight(savedStrokeWeight);
			break;
		case CENTER:
			break;
		case RADIUS:
			break;
		}
	}

	void Application::line(int ax, int ay, int bx, int by)
	{
		sf::ConvexShape convex;
		convex.setFillColor(m_fillColor);
		convex.setOutlineColor(m_strokeColor);
		convex.setOutlineThickness(m_strokeWeight / 2);
		convex.setPointCount(4);
		convex.setPoint(0, sf::Vector2f(ax, ay));
		convex.setPoint(1, sf::Vector2f(bx, by));
		convex.setPoint(2, sf::Vector2f(bx, by));
		convex.setPoint(3, sf::Vector2f(ax, ay));
		m_renderWindow->draw(convex);
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