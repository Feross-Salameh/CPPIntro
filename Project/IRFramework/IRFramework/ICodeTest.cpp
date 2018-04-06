#include "TestHarness.h"
#include "IRCode.h"

using namespace std;
TEST(gets, IRCode)
{

	unsigned char data[4] = { 1, 2, 3, 4 };
	std::string str("TV");
	double time = 1.5;

	IRCode irc(data, 4, str, time);
	
	CHECK_EQUAL("TV", irc.getDevice());
	CHECK_EQUAL(1.5, irc.getWait());
	CHECK_EQUAL(4, irc.getData()[3]);

}


TEST(sets, IRCode)
{
	unsigned char data[4] = { 1, 2, 3, 4 };
	std::string str("TV");
	double time = 1.5;

	IRCode irc(data, 4, str, time);
	
	unsigned char data2[4] = { 5, 6, 7, 9};

	if (!irc.setData(data2, sizeof(data) / sizeof(unsigned char)))
		cout << "set was not successful" << endl;

	CHECK_EQUAL(9, irc.getData()[3]);

	if (!irc.setDevice("Reciever"))
		cout << "set was not successful" << endl;
	CHECK_EQUAL("Reciever", irc.getDevice());

	if(!irc.setWait(1))
		cout << "set was not successful" << endl;

	CHECK_EQUAL(1, irc.getWait());


}
