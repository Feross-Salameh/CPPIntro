#pragma once
#include "IBitmapDecoder.h"
#include "WindowsBitmapHeader.h"
#include "Bitmap.h"
#include <iostream>
#include <string>
namespace BitmapGraphics
{
	class WindowsBitmapDecoder :
		public IBitmapIterator
	{
	public:
		WindowsBitmapDecoder();
		~WindowsBitmapDecoder();
			
		virtual HBitmapDecoder clone();
		virtual HBitmapIterator createIterator();
		virtual std::string getMimeType();
		virtual bool isSupported();
	private:
		Bitmap myBitmap;
		Bitmap::ScanLineIterator currentScanLine;
		std::string myMIMEType;

	};
}

