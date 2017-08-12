Use of DRV2605L Haptic Motor Controller to create the buzz effect on touching the screen

1. Open the project in Visual Studio by opening the sln file.
2. Make sure the arduino board is connected to the above mentioned Motor Controller.
3. Run the arduinoCode.ino in arduino.
4. Build and run the Visual studio project. You may create an exe and run it. If you encounter any missing dll files. Please copy the same to the respective System32 and SysWow64 folders respectively.
6. The 'Start' signal sent from the main.cpp to the arduino serial port is received as input by arduinoCode.ino, and it calls the required function that leads to the buzz effect.
