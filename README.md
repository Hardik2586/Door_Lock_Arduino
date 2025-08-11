# 🔒 Arduino Door Lock System
> A smart, secure, and beginner-friendly Arduino project with a keypad, LCD, and servo motor.
> ## 📌 Overview
This **Arduino-based Door Lock System** uses a **4x4 keypad**, **servo motor**, and **16x2 LCD display** to create a secure locking mechanism.  
Enter the correct 4-digit password → the servo unlocks the door.  
Enter the wrong password thrice → the system locks you out with a buzzer alert.

## 🛠 Components Used
| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| 4x4 Keypad | 1 |
| Servo Motor (SG90) | 1 |
| 16x2 LCD Display | 1 |
| Buzzer | 1 |
| Jumper Wires | As needed |
| Breadboard | 1 |
| Resistor (10kΩ for LCD contrast) | 1 |

---

## ✨ Features
✅ **5-Digit Password Security** – Changeable in code  
✅ **LCD Feedback** – Shows status messages  
✅ **Buzzer Alerts** – Wrong password warning  
✅ **Lockout System** – 3 wrong attempts = locked  
✅ **Smooth Servo Operation** – Realistic door movement  

## 📜 How It Works
1. **Enter password** via the 4x4 keypad.  
2. LCD shows `"Enter Password"`.  
3. If correct:
   - Servo rotates to **unlock** position.
   - LCD shows `"Door Opened"`.  
4. If incorrect:
   - Buzzer beeps.  
   - LCD shows `"Wrong Password"`.  

