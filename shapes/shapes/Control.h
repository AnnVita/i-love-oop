#pragma once
#include <boost/noncopyable.hpp>
#include "CPoint.h"
#include "CLineSegment.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCanvas.h"

class CShape;

class CAppControl : boost::noncopyable
{
public:
	CAppControl(std::istream & input, std::ostream & output);
	~CAppControl() = default;
	bool HandleCommand();
	void PrintInfo() const;
	void DrawShapes();

private:
	bool CreateLine(std::istream & args, std::shared_ptr<CShape> &shape);
	bool CreateRectangle(std::istream & args, std::shared_ptr<CShape> &shape);
	bool CreateTriangle(std::istream & args, std::shared_ptr<CShape> &shape);
	bool CreateCircle(std::istream & args, std::shared_ptr<CShape> &shape);

	void HandleEventsQueue(CCanvas & canvas);

	const std::map<std::string, std::function<bool(std::istream & args, std::shared_ptr<CShape> & shape)>> m_actionMap;

	std::shared_ptr<CShape> GetMaxAreaShape(std::vector<std::shared_ptr<CShape>> const & shapes) const;
	std::shared_ptr<CShape> GetMinPerimeterShape(std::vector<std::shared_ptr<CShape>> const& shapes) const;

	std::istream & m_input;
	std::ostream & m_output;
	std::vector<std::shared_ptr<CShape>> m_shapes;
};