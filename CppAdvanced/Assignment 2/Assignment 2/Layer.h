#pragma once
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include "Point.h"
#include "VectorGraphic.h"
#include "PlacedGraphic.h"

namespace VG
{
	using PlacedGraphicList = std::list<PlacedGraphic>;
	class Layer
	{
	public:
		Layer();
		Layer(const char* alias, const PlacedGraphicList& graphicList);

		Layer(const Layer& rhs) = default;
		Layer(Layer&& rhs) = default;

		Layer& operator=(const Layer&) = default;
		Layer& operator=(Layer&&) = default;

		void setAlias(const char* alias);
		void setAlias(const std::string& alias);
		const char* getAlias() const;

		void addPlacedGraphic(const PlacedGraphic& graphic);
		void addPlacedGraphic(PlacedGraphic&& graphic);
		void removeGraphic(const PlacedGraphic& graphic);
		void erasePlacedGraphic(size_t index);

		size_t getPlacedGraphicCount() const;
		const PlacedGraphic& getPlacedGraphic(int index) const;

		bool operator==(const Layer& rhs) const;
		bool operator!=(const Layer& rhs) const;

	private:
		std::string myName;
		PlacedGraphicList myPlacedGraphics;
	};
	std::ostream& operator<<(std::ostream& os, const Layer& p);
}



