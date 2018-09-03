#pragma once
#include "IBitmapEncoder.h"
#include "IBitmapIterator.h"
#include "WindowsBitmapHeader.h"
#include <iostream>
namespace BitmapGraphics
{
	class WindowsBitmapEncoder :
		public IBitmapEncoder
	{
	public:
		WindowsBitmapEncoder() = default;
		WindowsBitmapEncoder(HBitmapIterator iterator);

		WindowsBitmapEncoder(WindowsBitmapEncoder const&) = default;
		WindowsBitmapEncoder(WindowsBitmapEncoder &&) = default;

		WindowsBitmapEncoder& operator=(WindowsBitmapEncoder const&) = default;
		WindowsBitmapEncoder& operator=(WindowsBitmapEncoder &&) = default;

		~WindowsBitmapEncoder() = default;

		virtual IBitmapEncoder & clone() override;
		virtual void encodeToStream(std::ostream& os) override;
		virtual std::string getMimeType() override;

		void setIterator(HBitmapIterator iterator) { myBitmapIterator = iterator; }

	private:
		HBitmapIterator myBitmapIterator;
	};
}

