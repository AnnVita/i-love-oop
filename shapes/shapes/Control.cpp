#include "stdafx.h"
#include "Control.h"
#include "CShape.h"

using namespace std;
using namespace std::placeholders;

CAppControl::CAppControl(std::istream & input, std::ostream & output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "line", bind(&CAppControl::CreateLine, this, std::placeholders::_1, std::placeholders::_2) },
		{ "rectangle", bind(&CAppControl::CreateRectangle, this, std::placeholders::_1, std::placeholders::_2) },
		{ "triangle", bind(&CAppControl::CreateTriangle, this, std::placeholders::_1, std::placeholders::_2) },
		{ "circle", bind(&CAppControl::CreateCircle, this, std::placeholders::_1, std::placeholders::_2) }
})
{
}

std::shared_ptr<CShape> CAppControl::GetMaxAreaShape(std::vector<std::shared_ptr<CShape>> const & shapes) const
{
	return (shapes.empty()) ? nullptr : *max_element(shapes.begin(), shapes.end(),
		[&](std::shared_ptr<CShape> const & shape1, std::shared_ptr<CShape> const& shape2)
		{
			return shape1->GetArea() < shape2->GetArea();
		});
}

std::shared_ptr<CShape> CAppControl::GetMinPerimeterShape(std::vector<std::shared_ptr<CShape>> const & shapes) const
{
	return (shapes.empty()) ? nullptr : *min_element(shapes.begin(), shapes.end(),
		[&](std::shared_ptr<CShape> const& shape1, std::shared_ptr<CShape> const& shape2)
		{
			return shape1->GetPerimeter() < shape2->GetPerimeter();
		});
}

bool CAppControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);
	string action;
	strm >> action;

	if (commandLine.empty())
	{
		return true;
	}

	std::shared_ptr<CShape> shape;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm, shape);
		m_shapes.push_back(shape);
		return true;
	}
	return false;
}

void CAppControl::PrintInfo() const
{
	if (!m_shapes.empty())
	{
		for (auto shape : m_shapes)
		{
			m_output << shape->ToString() << "\n";
		}
		m_output << std::endl << "Shape with max area: " << std::endl
			<< GetMaxAreaShape(m_shapes)->ToString() << std::endl;
		m_output << "Shape with min perimeter: " << std::endl
			<< GetMinPerimeterShape(m_shapes)->ToString() << std::endl;
	}
	else
	{
		m_output << "File was empty or invalid. Please try again or choose another file" << std::endl;
	}
}

bool CAppControl::CreateLine(std::istream & args, std::shared_ptr<CShape> & shape)
{
	std::shared_ptr<CLineSegment> line;
	if (args >> line)
	{
		shape = line;
		return true;
	}
	return false;
}

bool CAppControl::CreateTriangle(std::istream & args, std::shared_ptr<CShape> & shape)
{
	std::shared_ptr<CTriangle> triangle;
	if (args >> triangle)
	{
		shape = triangle;
		return true;
	}
	return false;
}

bool CAppControl::CreateRectangle(std::istream & args, std::shared_ptr<CShape> & shape)
{
	std::shared_ptr<CRectangle> rectangle;
	if (args >> rectangle)
	{
		shape = rectangle;
		return true;
	}
	return false;
}

bool CAppControl::CreateCircle(std::istream & args, std::shared_ptr<CShape> & shape)
{
	std::shared_ptr<CCircle> circle;
	if (args >> circle)
	{
		shape = circle;
		return true;
	}
	return false;
}

void CAppControl::DrawShapes()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	CCanvas canvas(sf::VideoMode(800, 600), "Shapes");
	canvas.AddShapes(m_shapes);
	canvas.Clear(sf::Color::White);
	canvas.DrawShapes();
	canvas.Display();
	while (canvas.IsOpen())
	{
		HandleEventsQueue(canvas);
	}
}

void CAppControl::HandleEventsQueue(CCanvas & canvas)
{
	sf::Event event;
	while (canvas.PollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			canvas.Close();
	}
}