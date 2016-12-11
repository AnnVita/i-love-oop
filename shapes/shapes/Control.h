#pragma once
#include <boost/noncopyable.hpp>
#include "CPoint.h"
#include "CLineSegment.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"

class IShape;

class CAppControl : boost::noncopyable
{
public:
	CAppControl(std::istream & input, std::ostream & output);
	~CAppControl() = default;
	bool HandleCommand();
	void PrintInfo() const;

private:
	bool CreateLine(std::istream & args, std::shared_ptr<IShape> &shape);
	bool CreateRectangle(std::istream & args, std::shared_ptr<IShape> &shape);
	bool CreateTriangle(std::istream & args, std::shared_ptr<IShape> &shape);
	bool CreateCircle(std::istream & args, std::shared_ptr<IShape> &shape);

	const std::map<std::string, std::function<bool(std::istream & args, std::shared_ptr<IShape> & shape)>> m_actionMap;

	std::shared_ptr<IShape> GetMaxAreaShape(std::vector<std::shared_ptr<IShape>> const & shapes) const;
	std::shared_ptr<IShape> GetMinPerimeterShape(std::vector<std::shared_ptr<IShape>> const& shapes) const;

	std::istream & m_input;
	std::ostream & m_output;
	std::vector<std::shared_ptr<IShape>> m_shapes;
};