#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "Point.h"
#include "VectorGraphic.h"
#include "PlacedGraphic.h"
#include "Layer.h"

namespace VG
{
	using LayersList = std::list<Layer>;
	class Scene
	{
	public:

		Scene() = default;
		Scene(unsigned int width, unsigned int height, const LayersList& layers);
		Scene(const Scene&) = default;
		Scene(Scene&&) = default;
		~Scene() = default;
		Scene& operator=(const Scene&) = default;
		Scene& operator=(Scene&&) = default;

		void addLayer(const Layer& lyr);
		void addLayer(Layer&& lyr);
		void removeLayer(const Layer& lyr);
		void eraseLayer(size_t index);

		constexpr unsigned int getWidth() const { return myWidth; }
		constexpr unsigned int getHeight() const { return myHeight; }

		void setWidth(unsigned int width);
		void setHeight(unsigned int height);

		size_t getLayercCount() const;
		const Layer& getLayer(int index) const;

		bool operator==(const Scene& rhs) const;
		bool operator!=(const Scene& rhs) const;

	private:
		unsigned int myWidth{ 0 };
		unsigned int myHeight{ 0 };
		LayersList myLayers;
	};

	std::ostream& operator<<(std::ostream& os, const Scene& p);
}



