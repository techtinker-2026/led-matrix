# 🔥 Arduino Bluetooth LED Matrix Running Text Display

This project demonstrates a **wireless real-time running text display** using an **Arduino UNO**, **MAX7219 8×8 LED matrix**, and an **HC-05 Bluetooth module**. You can send custom messages directly from your smartphone, and they will scroll smoothly across the LED display in real time.

---

## 🚀 Features

* 📡 **Wireless Bluetooth Control** using HC-05
* 🔄 **Smooth Scrolling / Running Text**
* ⚡ **Real-Time Message Updates from Phone**
* 🎛️ Adjustable **speed and brightness**
* 😀 Support for **custom icons/emojis (smile, heart, etc.)**
* 🔁 Continuous scrolling with no delay

---

## 🧰 Components Required

* Arduino UNO / Nano
* MAX7219 8×8 LED Matrix
* HC-05 Bluetooth Module
* Jumper wires

---

## 🔌 Wiring

### LED Matrix (MAX7219)

* VCC → 5V
* GND → GND
* DIN → D12
* CS  → D9
* CLK → D13

### HC-05 Bluetooth

* VCC → 5V
* GND → GND
* TX → D10
* RX → D11 *(use resistor/voltage divider recommended)*

---

## 📱 Mobile App

Use any Bluetooth serial app like:

* Serial Bluetooth Terminal

---

## 🎮 Commands

| Command   | Function                |
| --------- | ----------------------- |
| `T:HELLO` | Change scrolling text   |
| `S:120`   | Set speed               |
| `B:10`    | Set brightness (0–15)   |
| `I:HEART` | Show heart icon         |
| `I:SMILE` | Show smile icon         |
| `+`       | Increase speed (slower) |
| `-`       | Decrease speed (faster) |
| `R`       | Reset to default        |

---

## 💡 How It Works

The Arduino receives text data via Bluetooth from your phone. The message is processed and displayed on the LED matrix using the MAX7219 driver. The **MD_Parola library** is used to create smooth scrolling animations and handle display effects.

---

## 🎯 Applications

* LED name display boards
* Notice boards
* Mini advertising displays
* DIY smart message boards

---

## 📌 Notes

* Ensure common **GND connection** for all components
* Use proper resistor or voltage divider for HC-05 RX pin
* Avoid powering too many modules from Arduino 5V

---

## 🙌 Credits

Built using Arduino and open-source libraries.

---

⭐ If you like this project, consider giving it a star!
