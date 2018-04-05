#include "TestHarness.h"
#include "ArduinoInterface.h"

using namespace std;

TEST(setup, ArduinoInterface)
{
	ArduinoInterface ai("COM1");

	CHECK_EQUAL("ARDUINO", ai.HWID());
	CHECK_EQUAL("COM1", ai.Port());
	string error;
	IRCode irc;
	if (!ai.Recieve(irc, error))
		cout << "Recieve unsuccessful: " << error << endl;
}


/*
		code = IRCode();
		unsigned char data[5] = { 'h', 'e', 'l', 'l', 'o' };
		code.setData(data, 5);
		code.setDevice("TEST");
		code.setWait(5);
*/
TEST(recieve, ArduinoInterface)
{
	ArduinoInterface ai("COM1");
	string error;
	IRCode irc;
	if (!ai.Recieve(irc, error))
		cout << "Recieve unsuccessful: " << error << endl;
	CHECK_EQUAL(5, irc.getWait());

}

// Empty test for now. Don't have arduino setup.
TEST(send, ArduinoInterface)
{
	ArduinoInterface ai("COM1");
	unsigned char data[5] = { 'h', 'e', 'l', 'l', 'o' };
	IRCode irc(data, 5, "ARDUINO", 5);
	string error;
	if (!ai.Send(irc, error))
		cout << "Send unsuccessful:" << error << endl;
}