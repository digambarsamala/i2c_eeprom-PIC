# I2C EEPROM Interfacing with PIC16F877A

## 📌 Project Overview

This project demonstrates how to interface an external **I2C EEPROM** with the **PIC16F877A** microcontroller using the MSSP (I2C) module.
The microcontroller writes data to different EEPROM memory locations and then reads it back. The read data is displayed on **PORTD** (typically connected to LEDs) for verification.

This project is useful for learning:

* I2C Master communication
* External EEPROM interfacing
* MSSP module usage in PIC16F877A
* Embedded C with MPLAB XC8

---

## 🧰 Hardware Requirements

* PIC16F877A microcontroller
* External I2C EEPROM (e.g., 24LC256 / 24C04 etc.)
* 16 MHz crystal oscillator
* Pull-up resistors (4.7kΩ recommended) for SDA and SCL
* LEDs on PORTD (for output visualization)
* Breadboard / PCB
* MPLAB X IDE + XC8 Compiler

---

## 🔌 Pin Connections

| PIC16F877A Pin | Function    | EEPROM Pin |
| -------------- | ----------- | ---------- |
| RC3            | SCL (Clock) | SCL        |
| RC4            | SDA (Data)  | SDA        |
| VCC            | +5V         | VCC        |
| GND            | Ground      | GND        |

⚠️ **Important:** Always use pull-up resistors on SDA and SCL lines.

---

## ⚙️ Project Workflow

1. Initialize I2C in master mode (100 kHz)
2. Write three different bytes to EEPROM addresses
3. Wait for EEPROM write cycle completion
4. Read back the stored data
5. Display the read value on PORTD
6. System stays idle

---

## 📂 File Structure

```
📁 I2C_EEPROM_Project
 ├── main.c
 ├── I2C_EEPROM.c
 └── I2C_EEPROM.h
```

### 🔹 main.c

* Initializes I2C
* Writes test data to EEPROM
* Reads data back
* Displays on PORTD

### 🔹 I2C_EEPROM.h

Contains function prototypes for:

* I2C master routines
* EEPROM read/write functions

### 🔹 I2C_EEPROM.c

Implements:

* I2C start, stop, ACK/NACK
* Byte read/write
* EEPROM read/write logic

---

## 🚀 How It Works

### ✍️ Write Operation

```
START → EEPROM_W → Address High → Address Low → Data → STOP
```

### 📖 Read Operation

```
START → EEPROM_W → Address → REPEATED START → EEPROM_R → Read → NACK → STOP
```

---

## 🧪 Test Data Used

| EEPROM Address | Data Written |
| -------------- | ------------ |
| 0x0023         | 0x41 ('A')   |
| 0x0028         | 0x42 ('B')   |
| 0x0036         | 0x43 ('C')   |

PORTD sequentially shows the read values every 2 seconds.

---

## 🛠️ Configuration Details

* Oscillator: **HS, 16 MHz**
* I2C Speed: **100 kHz**
* MSSP Mode: **Master**
* Compiler: **XC8**

---

## 📸 Expected Output

* Data successfully written to EEPROM
* Correct data read back
* PORTD outputs change every 2 seconds

---

## 🔍 Important Notes

* Ensure proper pull-ups on SDA/SCL
* Maintain EEPROM write delay (~10 ms)
* Device address used:

  * Write: `0xA0`
  * Read: `0xA1`
* TRISC3 and TRISC4 must be set as inputs for I2C

---

## 🚧 Future Improvements

* ✅ Page write implementation
* ✅ LCD display instead of LEDs
* ✅ Error handling for NACK
* ✅ EEPROM full memory test
* ✅ Interrupt-based I2C
* ✅ Configurable EEPROM device address
* ✅ Data logging application

---

## 🎯 Learning Outcomes

After completing this project, you will understand:

* I2C protocol basics
* MSSP configuration in PIC16F877A
* External memory interfacing
* Embedded driver modularization

---

## 👨‍💻 Author

**Digambar Samala**
Embedded Systems Enthusiast

---

## 📜 License

This project is open-source and free to use for learning purposes.

---

⭐ If you found this helpful, consider starring the repository!
