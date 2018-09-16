#pragma once
#include "ICanvas.h"
#include <vector>
namespace Framework
{
	class BasicCanvas :
		public ICanvas
	{
	public:
		using DrawingBoardLine = std::vector<Color>;
		using DrawingBoard = std::vector<std::vector<Color>>;
	public:
		BasicCanvas(int height, int width);
		~BasicCanvas() = default;

		virtual void setPixelColor(Point const& location, Color const& color) override;
		virtual Color getPixelColor(Point const& location) const override;
		virtual int getWidth() const override;
		virtual int getHeight() const override;
		virtual HBitmapIterator createBitmapIterator() override;

	private:
		int myWidth;
		int myHeight;
		DrawingBoard myBoard;
	};
}

