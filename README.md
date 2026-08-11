# SmartClimate_Sense_embedded_project




## 📋 Description
An advanced embedded C project for the ATmega32 microcontroller designed to measure, process, and display both positive and negative temperatures. This system bridges the analog physical world with digital processing to provide accurate environmental monitoring.

## ️ Component Usage & Technical Implementation

###  ATmega32 Microcontroller
*   **Usage:** Acts as the central processing unit (CPU) of the system. 
*   **Role:** It executes the Embedded C firmware, manages the ADC conversion process, performs the mathematical calculations to convert raw sensor data into Celsius/Fahrenheit, and drives the output display.

###  Temperature Sensor ( LM35)
*   **Usage:** The primary input transducer.
*   **Role:** Converts physical thermal energy into a continuous analog electrical signal (voltage). The voltage output varies linearly (or predictably) with the ambient temperature, allowing the system to detect both sub-zero and high-temperature environments.

###  Internal ADC (Analog-to-Digital Converter)
*   **Usage:** The critical bridge between the analog sensor and the digital microcontroller.
*   **Role:** The ATmega32 only understands binary (0s and 1s), but the sensor outputs a continuous analog voltage. The 10-bit internal ADC samples this voltage and converts it into a digital integer (0 to 1023). This digital value is then scaled mathematically in the C code to determine the exact temperature.

###  Display Module (LCD) 
*   **Usage:** The human-machine interface (HMI) output.
*   **Role:** Receives the processed digital temperature data from the microcontroller and visually presents the real-time temperature readings to the user, including the negative sign (-) for sub-zero temperatures.

###  Proteus Design Suite
*   **Usage:** Circuit simulation and virtual prototyping.
*   **Role:** Used to design the schematic, simulate the microcontroller's behavior, and test the firmware logic in a virtual environment before deploying to physical hardware.


## 📁 Project Structure
*   `/Src` - Contains all the main C source code files (main logic, ADC driver, Display driver).
*   `/Inc` - Contains all the C header files for modular code organization.
*   `/Proteus` - Contains the Proteus simulation design files and schematics.

## 🔧 How to Run the Simulation
1. Open the `.DBK` or `.PWI` file located in the `Proteus` folder using Proteus Design Suite.
2. Compile the Embedded C code in your IDE (e.g., Atmel Studio / AVR Studio).
3. Load the generated `.hex` file into the ATmega32 microcontroller component in Proteus.
4. Run the simulation and adjust the sensor's temperature variable to observe the system's response to both positive and negative values.
