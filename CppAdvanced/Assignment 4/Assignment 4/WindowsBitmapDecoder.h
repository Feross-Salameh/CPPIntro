#pragma once
#include "IBitmapDecoder.h"
#include "WindowsBitmapHeader.h"
#include "IBitmapIterator.h"
#include "BitmapIterator.h"
#include "Bitmap.h"
#include <iostream>
#include <string>
namespace BitmapGraphics
{
	class WindowsBitmapDecoder :
		public IBitmapDecoder
	{
	public:
		WindowsBitmapDecoder(std::istream& is, std::string mimeType);
		~WindowsBitmapDecoder() = default;
		virtual IBitmapDecoder& clone() override { return HBitmapDecoder( *this); }
		virtual HBitmapIterator createIterator() override { return myBitmap->createIterator(); }
		virtual std::string getMimeType() override { return myMIMEType; }
		virtual bool isSupported() override { return myMIMEType == "image/x-ms-bmp"; }
		Bitmap* getBitmap() const { return myBitmap; }
	private:
		Bitmap* myBitmap;
		std::string myMIMEType;
		WindowsBitmapDecoder(WindowsBitmapDecoder const& other) = default;
		WindowsBitmapDecoder(WindowsBitmapDecoder && other) = default;
		WindowsBitmapDecoder& operator=(WindowsBitmapDecoder const& other) = default;
		WindowsBitmapDecoder& operator=(WindowsBitmapDecoder && other) = default;
	};
}


