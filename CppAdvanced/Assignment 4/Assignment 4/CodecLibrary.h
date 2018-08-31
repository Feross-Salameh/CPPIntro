#pragma once
#include "IBitmapDecoder.h"
#include "IBitmapEncoder.h"
#include <list>

namespace BitmapGraphics
{
	using DecoderList = std::list<IBitmapDecoder*>;
	using EncoderList = std::list<IBitmapEncoder*>;

	class CodecLibrary
	{
	public:
		CodecLibrary() = default;
		~CodecLibrary() = default;

		CodecLibrary(const CodecLibrary&) = default;
		CodecLibrary(CodecLibrary&&) = default;

		CodecLibrary& operator=(const CodecLibrary&) = default;
		CodecLibrary& operator=(CodecLibrary&&) = default;


		void registerDecoder(HBitmapDecoder const& decoder) { myDecoders.push_back(&decoder); }
		void registerEncoder(HBitmapEncoder const& encoder) { myEncoders.push_back(&encoder); }

		// provide a mime type version and an
		// auto determination version of createDecoder
		HBitmapDecoder createDecoder(std::istream& sourceStream);
		HBitmapDecoder createDecoder(std::string const& mimeType, std::istream& sourceStream);

		HBitmapEncoder createEncoder(std::string const& mimeType, HBitmapIterator const& bitmapIterator);


	private:
		EncoderList myEncoders;
		DecoderList myDecoders;
	};
	
}
