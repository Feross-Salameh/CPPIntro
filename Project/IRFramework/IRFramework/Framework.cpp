#include "Framework.h"



Framework::Framework() :
	myArdy(),
	myStorage()
{
	interfaces.push_back(& myArdy);
}



void Framework::StoreIRCode(std::string name)
{
	IRCode code;
	std::string error;
	if (myArdy.Recieve(code, error))
		std::cout << "recieved code" << std::endl;
	else
	{
		std::cout << "Unable to recieve code from arduino: " << error << std::endl;
		return;
	}
	code.Name = name;
	if (myStorage.storeCode(code))
		std::cout << "Storage of code " << name << " successful." << std::endl;
	else
		std::cout << "Storage of code " << name << " unsuccessful." << std::endl;

}

void Framework::CreateSequence(std::vector<ICode *>& codes, std::string name)
{
	if (!myStorage.storeSequence(codes, name))
		std::cout << "Storage of Sequence " << name << " was unsuccessful." << std::endl;
}

void Framework::CallCode(std::string name)
{
	// TODO: fully implement when database is setup and multiple interfaces feature implemented.

	ICode code = ICode();
	myStorage.retrieveCode(name, code);

	std::string error; 
	if (myArdy.Send(code, error))
		std::cout << "code " << name << " was sent successfully" << std::endl;
	else
		std::cout << "Code " << name << " was sent unsuccessfully: " << error << std::endl;

}

void Framework::RunSequence(std::string name)
{
	for (auto & c : myStorage.retrieveSequence(name))
		this->CallCode(name);
}

void Framework::GetCode(std::string name, ICode & code)
{
	// TODO: fully implement when database is setup and multiple interfaces feature implemented.
	std::string error;
	if (myArdy.Recieve(code, error))
		std::cout << "Recieved Code!" << std::endl;
}
