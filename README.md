# Hardware Software Platforms : Altera Quartus EDA, DE1-SoC and Accelerometer_Sensor (driver and application)

This project repository is made in the frame of M. Valderrama (FPMS-UMONS, Belgium) course entitled Hardware Software Platform. The objective of this course is to develop and create a tutorial explaining how to use a development tool (Altera Quartus EDA in my case), platform and peripheral, to develop tests to evaluate the device, its driver and its human interface using simulation or a test bench.

To do so we should create or use an existing driver, create an application (human interaction interface) and test it on the board.

The FPGA board that was used in this project was Altera DE1-SoC. The accelerometer sensor peripheric model is LIS3LV02DL. All the information provided in the tutorial comes from personal knowledge, experiment and from the .PDF documentation that can be found in the "References" folder.

In this project i learn how to drive an accelerometer sensor mentionned above through I2C serial bus interface with an Altera Cyclone V SoC using Quartus and this starting from a simple code C which did the same job on a PIC card (accelorometer.c).

The video demonstrating how my application works can be found on youtube : https://youtu.be/tSfjQ94cZB0

The .qar file is the archived project under Quartus. The .sof file is the binary used to flash the FPGA board with the code of the driver and the application.

The Présentation in .ppt is a powerpoint presenting the project and the Tutorial_Driving_Accelerometer_on_DE1_SoC-FPMs.pdf is a tutorial to reproduce the project made.

In the .qar file you will find .vhd files and a test bench(es) corresponding to their tasks for simulation.

The I2C_Driver.vhd file is the program that manages the communication in I2C with the device. It is inspired to a i2c_master.vhd file found on the internet (https://www.digikey.com/eewiki/pages/viewpage.action?pageId=10125324).

The Appli.vhd is the program that includes the state machine of the sensor.

The Appli_Driver.vhd is grouping the  I2C driver with the Application where you only need to name the pins you want to use to flash it on the SoC. The mapping was done in the DE1SoC.vhd file.

# Project Presented by

Kasongo Kabasele Dieudonné : dieudonne.kasongokabasele@student.umons.ac.be
