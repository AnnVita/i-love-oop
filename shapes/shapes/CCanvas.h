#pragma once
#include "ICanvas.h"
#include "CPoint.h"
#include "CShape.h"
#include "Color.h"

class CCanvas : public ICanvas, public sf::Drawable
{
public:
	CCanvas(sf::VideoMode videoMode, sf::String windowTitle);

	void DrawLine(CPoint const & startPoint, CPoint const & endPoint, sf::Color const & outlineColor) override;
	void FillPolygon(std::vector<CPoint> const vertices, sf::Color const & fillColor) override;
	void DrawCircle(CPoint const & center, float radius, sf::Color const & outlineColor) override;
	void FillCircle(CPoint const & center, float radius, sf::Color const & fillColor) override;

	void FillShapesList(std::vector<std::shared_ptr<CShape>> const& shapes);

	bool IsOpen() const;
	void Clear(sf::Color);
	void Display();
	bool PollEvent(sf::Event & event);
	void Close();
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	void DrawShapes();
private:
	void SetPrimitiveType(sf::VertexArray & vertexArray, size_t size);

	sf::RenderWindow m_window;
	std::vector<sf::VertexArray> m_shapes;
};