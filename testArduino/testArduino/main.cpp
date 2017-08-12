#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "SerialPort.h"

using namespace std;

//String for getting the output from arduino
char output[MAX_DATA_LENGTH];

/*Portname must contain these backslashes, and remember to
replace the following com port*/
char *port_name = "\\\\.\\COM3";

//String for incoming data
char incomingData[MAX_DATA_LENGTH];

int main()
{
	SerialPort arduino(port_name);
	if (arduino.isConnected()) cout << "Connection Established" << endl;
	else cout << "ERROR, check port name";
	//Sleep(10);

	while (arduino.isConnected()) {

		if ((GetKeyState(VK_LBUTTON) & 0x80) != 0)
				//sending the 'start' message to arduino port
				arduino.writeSerialPort("Start", MAX_DATA_LENGTH);

		//Getting reply from arduino
		arduino.readSerialPort(output, MAX_DATA_LENGTH);
		//printing the output
		puts(output);
	}
}
