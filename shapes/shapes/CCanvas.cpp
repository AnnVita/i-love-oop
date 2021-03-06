#include "stdafx.h"
#include "CCanvas.h"

CCanvas::CCanvas(sf::VideoMode videoMode, sf::String windowTitle)
{
	m_window.create(videoMode, windowTitle);
}

bool CCanvas::IsOpen() const
{
	return m_window.isOpen();
}

void CCanvas::Clear(sf::Color color)
{
	m_window.clear(color);
}

void CCanvas::Display()
{
	m_window.display();
}

bool CCanvas::PollEvent(sf::Event &event)
{
	return m_window.pollEvent(event);
}

void CCanvas::Close()
{
	return m_window.close();
}

void CCanvas::FillShapesList(std::vector<std::shared_ptr<CShape>> const & shapes)
{
	for (auto shape : shapes)
	{
		shape->Draw(*this);
	}
}

void CCanvas::DrawShapes()
{
	sf::RenderStates states;
	draw(m_window, states);
}

void CCanvas::DrawLine(CPoint const & startPoint, CPoint const & endPoint, sf::Color const & outlineColor)
{
	sf::VertexArray line(sf::Lines);
	line.append(sf::Vertex(sf::Vector2f(startPoint.x, startPoint.y), outlineColor));
	line.append(sf::Vertex(sf::Vector2f(endPoint.x, endPoint.y), outlineColor));
	m_shapes.push_back(line);
}

void CCanvas::FillPolygon(std::vector<CPoint> const vertices, sf::Color const & fillColor)
{
	sf::VertexArray polygon;
	polygon.resize(vertices.size());
	SetPrimitiveType(polygon, vertices.size());
	for (size_t i = 0; i < polygon.getVertexCount(); ++i)
	{
		polygon[i].position = sf::Vector2f(vertices[i].x, vertices[i].y);
		polygon[i].color = fillColor;
	}
	m_shapes.push_back(polygon);
}

void CCanvas::SetPrimitiveType(sf::VertexArray & vertexArray, size_t size)
{
	if (size == 3)
	{
		vertexArray.setPrimitiveType(sf::Triangles);
	}
	else if (size == 4)
	{
		vertexArray.setPrimitiveType(sf::Quads);
	}
}

void CCanvas::DrawCircle(CPoint const & center, float radius, sf::Color const & outlineColor)
{
	float angle = 0;
	sf::VertexArray circle;
	for (size_t i = 0; i < 7 * radius; ++i)
	{
		circle.append(sf::Vertex(sf::Vector2f(radius * cos(angle) + center.x, radius * sin(angle) + center.y), outlineColor));
		angle = angle + ((2 * static_cast<float>(M_PI)) / (7 * radius));
	}
	m_shapes.push_back(circle);
}

void CCanvas::FillCircle(CPoint const & center, float radius, sf::Color const & fillColor)
{
	float angle = 0;
	sf::VertexArray circle;
	circle.setPrimitiveType(sf::TriangleFan);
	for (size_t i = 0; i < 7 * radius; ++i)
	{
		circle.append(sf::Vertex(sf::Vector2f((radius - 1) * cos(angle) + center.x, (radius - 1) * sin(angle) + center.y)));
		angle = angle + ((2 * static_cast<float>(M_PI)) / (7 * radius));
	}
	m_shapes.push_back(circle);

	for (size_t i = 0; i < m_shapes[m_shapes.size() - 1].getVertexCount(); ++i)
	{
		m_shapes[m_shapes.size() - 1][i].color = fillColor;
	}
}

void CCanvas::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto & shape : m_shapes)
	{
		target.draw(shape);
	}
}
