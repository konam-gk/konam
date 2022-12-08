#ifndef SELEMENTS_H
#define SELEMENTS_H

#include <functional>
#include <map>

#include "spoint.h"
#include "sline.h"

class SElements
{
private:

	SElements() = delete;

	friend class SPoint;
	friend class SLine;


public:

	static std::unique_ptr<SPoint> SPoint()
	{
		struct EnableMaker : public SPoint { using SPoint::SPoint; };
		return std::make_unique<EnableMaker>();
	}


	static std::unique_ptr<SLine> SLine()
	{
		struct EnableMaker : public SLine { using SLine::SLine; };
		return std::make_unique<EnableMaker>();
	}

};

#endif // !SELEMENTS_H
