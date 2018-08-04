#pragma once
#include <string>
#include <cstdlib>
#include <vector>
#include "Point.h"
#include "VectorGraphic.h"
#include "PlacedGraphic.h"

namespace VG
{
	using PlacedGraphicList = std::vector<PlacedGraphic>;
	class Layer
	{
	public:
		Layer() = default;
		Layer(const std::string& alias, const PlacedGraphicList& graphicList);

		Layer(const Layer& rhs) = default;
		Layer(Layer&& rhs) = default;

		Layer& operator=(const Layer&) = default;
		Layer& operator=(Layer&&) = default;

		void setAlias(const std::string& alias);
		std::string const& getAlias() const;

		void setPlacedGraphic(const PlacedGraphic& placedGraphic);
		void setPlacedGraphic(PlacedGraphic&& placedGraphic);
		PlacedGraphic const& getPlacedGraphic() const;

	private:
		std::string& myName;
		PlacedGraphicList& myPlacedGrapics;
	};
}



