#include "SceneReader.h"
#include "Scene.h"
#include "XmlInterfaces.h"
#include "VectorGraphic.h"
#include <sstream>

namespace
{
    int toInt(const std::string& s)
    {
        int value;
        std::stringstream ss(s);
        ss >> value;
        
        return value;
    }
    
    Framework::VectorGraphic readVectorGraphic(const Xml::HElement FrameworkElement)
    {
        Framework::VectorGraphic Framework;
        
        std::string closed = FrameworkElement->getAttribute("closed");
        if (closed == "true")
        {
            Framework.closeShape();
        }
        else if (closed == "false")
        {
            Framework.openShape();
        }
        else
        {
            throw std::runtime_error("Invalid VectorGraphic attribute");
        }
        
        Xml::ElementCollection points = FrameworkElement->getChildElements();
        Xml::ElementCollection::const_iterator p;
        for (p = points.begin(); p != points.end(); ++p)
        {
			if ((*p)->getName() == "Point")
			{
				int x = toInt((*p)->getAttribute("x"));
				int y = toInt((*p)->getAttribute("y"));
				Framework.addPoint(Framework::Point(x, y));
			}
			else if ((*p)->getName() == "Stroke")
			{
				// TODO: finish adding reader for Pen
			}
        }
        
        return Framework;
    }
    
    void readGraphic(Framework::Scene& scene,
                     Framework::Layer& layer,
                     const Xml::HElement graphicElement)
    {
        if (graphicElement->getName() != "PlacedGraphic")
        {
            throw std::runtime_error("Expected PlacedGraphic");
        }
        
        Framework::PlacedGraphic pg;
        int x = toInt(graphicElement->getAttribute("x"));
        int y = toInt(graphicElement->getAttribute("y"));
        
        if (x < 0 || y < 0 ||
            x > scene.getWidth() || y > scene.getHeight())
        {
            throw std::runtime_error("PlacedGraphic out of bounds");
        }
        
        pg.setPlacementPoint(Framework::Point(x, y));
        
        Xml::ElementCollection vectorGraphics = graphicElement->getChildElements();
        Xml::ElementCollection::const_iterator FrameworkElement;
        for (FrameworkElement = vectorGraphics.begin(); FrameworkElement != vectorGraphics.end(); ++FrameworkElement)
        {
            // TODO - assert - there should only be one of these
            pg.setGraphic(readVectorGraphic(*FrameworkElement));
        }
        
        layer.pushBack(pg);
    }
    
    void readLayer(Framework::Scene& scene,
                   const Xml::HElement layerElement)
    {
        if (layerElement->getName() != "Layer")
        {
            throw std::runtime_error("Expected Layer");
        }
        
        Framework::Layer layer(layerElement->getAttribute("alias"));
        
        Xml::ElementCollection graphics = layerElement->getChildElements();
        Xml::ElementCollection::const_iterator graphic;
        for (graphic = graphics.begin(); graphic != graphics.end(); ++graphic)
        {
            readGraphic(scene, layer, *graphic);
        }
        
        scene.pushBack(layer);
    }
}

namespace Framework
{

Scene SceneReader::readScene(const Xml::IElement& rootElement)
{
    if (rootElement.getName() != "Scene")
    {
        throw std::runtime_error("Expected Scene");
    }
    
    int width = toInt(rootElement.getAttribute("width"));
    int height = toInt(rootElement.getAttribute("height"));
    Scene theScene(width, height);
    
    Xml::ElementCollection layers = rootElement.getChildElements();
    Xml::ElementCollection::const_iterator layer;
    for (layer = layers.begin(); layer != layers.end(); ++layer)
    {
		readLayer(theScene, *layer);
    }
    
    return theScene;
}

}