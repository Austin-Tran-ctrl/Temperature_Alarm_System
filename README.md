**# Room Temperature Monitor**



An embedded hardware project built around an ATmega328P microcontroller (Arduino Uno board). The system reads ambient room temperature using an analog sensor, displays the current reading on an LCD screen in Fahrenheit and Celsius, and triggers visual and audible alerts whenever the temperature strays outside a target range.



**## Project Overview**



I built this prototype to get more hands-on experience with embedded electronics, hardware design, and basic signal processing. The main goals were:



**Hardware Prototyping:** Wiring up analog sensors, an I2C LCD, LEDs, and a piezo buzzer, then packaging everything inside an ABS chassis with a custom 3D-printed internal battery holder.

**Embedded Firmware:** Writing C++ code to read analog voltages, convert them into calibrated temperatures, update the display, and run timing loops for out-of-range alert states.

**Circuit \& Power Calculations:** Figuring out current draw across different paths, choosing resistor values to manage LED brightness vs. battery drain, and evaluating power delivery choices.



**## Hardware Setup**



**Microcontroller (ATmega328P / Arduino Uno):** Handles ADC sampling, threshold checks, I2C output, and alerting.

**TMP36 Temperature Sensor:** Connected to pin A0. Outputs an analog voltage that scales linearly with temperature. Operating temperature range is -40 to 257 degrees Fahrenheit. The comfortable range chosen for this prototype is 80 to 90 degrees Fahrenheit.

**16x2 I2C LCD:** Uses an I2C backpack running on pins A4 and A5 to display both Celsius and Fahrenheit values.

**Green Power LED:** Pin D2. Tied to a 1k ohm resistor so it draws around 5 mA. Since it stays on constantly while the system is powered, I chose this high resistor value to keep continuous power drain low and preserve battery life.

**Red Alert LED:** Pin D3. Tied to a 220 ohm resistor, drawing \~22.7 mA to make sure it blinks bright enough during alerts.

**Piezo Buzzer:** Pin D5. Pulsed at 2000 Hz alongside the red LED when room temperature drops below 80 degrees F or goes above 90 degrees F.



**## Power Supply \& Wiring**



**Power Paths:** The board can run directly through the Arduino USB or with an internal 9V battery attached to a switch.

**Battery Life:** A 9V battery was used out of convenience as it is easy to acquire and replace. It has a capacity of 500-600 mAh. For longevity, this is not a good option and after testing, the battery lasted \~5 hours.

**Wiring:** Primary connections made using standard jumper wires for fast prototyping. Twist nut caps were used to keep wires relatively clean. Spade connectors were attached to the toggle switch leads.



**## Diagrams and Photos**


Diagrams of the system are available in the documents folder (both hand-drawn and modeled using Onshape). Fully assembled design pictures also available.



