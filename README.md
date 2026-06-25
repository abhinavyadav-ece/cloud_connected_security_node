# 🔐 Project 3: Cloud-Connected Security Node (IoT Telemetry)
### *Simulated on Wokwi — No Hardware Required!*

<p align="center">
  <img src="screenshots/wokwi_simulation.png" alt="Wokwi Simulation Running" width="750"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Platform-ESP32-blue?style=for-the-badge&logo=espressif"/>
  <img src="https://img.shields.io/badge/Simulator-Wokwi-7B2FBE?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Cloud-Blynk%20IoT-00C7B7?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Protocol-MQTT-orange?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Sensor-HC--SR04-green?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Hardware-Not%20Required-lightgrey?style=for-the-badge"/>
</p>

---

## 📌 Project Overview

A **real-time physical security telemetry system** using ESP32 + HC-SR04 ultrasonic sensor, simulated entirely on **[Wokwi](https://wokwi.com)** — a free browser-based IoT simulator. No physical components needed!

Sensor data is streamed via **MQTT protocol** to a **Blynk IoT cloud dashboard** for live monitoring and intruder alerts.

> **Goal:** Broadcast physical security telemetry across the internet to a centralized cloud dashboard.

---

## 🎯 Key Features

| Feature | Description |
|---------|-------------|
| 🖥️ **100% Simulated** | Runs entirely in Wokwi browser simulator |
| 📏 **Distance Measurement** | HC-SR04 measures distance (drag slider to change!) |
| 🚨 **Intruder Detection** | Alert when object < 50 cm from sensor |
| 📊 **Live Serial Dashboard** | Real-time telemetry table in Serial Monitor |
| 🔔 **Blynk Event Simulation** | Push notification logged when intruder detected |
| 💡 **Visual LED Alert** | Red LED lights up on intruder detection |

---

## 🖥️ Run the Simulation (Step-by-Step)

### Method 1: Wokwi Direct Link (Easiest)

**👉 Click here to open simulation:**
> `https://wokwi.com/projects/new/esp32`

Then follow steps below ↓

---

### Method 2: Manual Setup on Wokwi

#### Step 1 — Open Wokwi
Go to **[wokwi.com](https://wokwi.com)** → Click **"New Project"** → Select **ESP32**

#### Step 2 — Paste the Code
- Open `code/security_node.ino`
- Copy all the code
- Paste it in the Wokwi code editor (left panel)

#### Step 3 — Set Up the Circuit
- Click the **`diagram.json`** tab in Wokwi
- Delete all existing content
- Paste the content from `diagram.json` in this repo

Your circuit will look like this:
```
ESP32 Dev Board
  │
  ├── GPIO 5  ──────► HC-SR04 TRIG
  ├── GPIO 18 ◄────── HC-SR04 ECHO
  ├── 3.3V    ──────► HC-SR04 VCC
  ├── GND     ──────► HC-SR04 GND
  │
  └── GPIO 2  ──► 220Ω ──► LED(Red) ──► GND
```

#### Step 4 — Run the Simulation
- Click the **▶ Play** button (green button, top left)
- Watch the **Serial Monitor** (bottom panel) for live output!

#### Step 5 — Simulate an Intruder!
- Click on the **HC-SR04 sensor** in the circuit
- A **distance slider** will appear
- **Drag it below 50 cm** → Watch the INTRUDER ALERT trigger! 🚨

---

## 📟 Serial Monitor Output

When running, the Serial Monitor shows a live dashboard:

```
╔══════════════════════════════════════════╗
║   Cloud-Connected Security Node v1.0   ║
║   ESP32 + HC-SR04 + Blynk IoT          ║
║   [ Running on Wokwi Simulator ]       ║
╠══════════════════════════════════════════╣
║  Simulating WiFi connection...          ║
║  ✅ Connected to WiFi: MyNetwork        ║
║  Connecting to Blynk Cloud (MQTT)...   ║
║  ✅ Blynk Connected!                    ║
╚══════════════════════════════════════════╝

╔══════════════════════════════════════════╗
║    🔐 SECURITY NODE - LIVE TELEMETRY    ║
╠══════════════════════════════════════════╣
║  📏 Distance  : 124.3 cm               ║
║  📡 Blynk V0  : Gauge → 124.3 cm      ║
║  🚨 Alert     : ✅  Area Clear          ║
║  💡 LED       : OFF ⚫                  ║
║  📊 Reading # : 5                      ║
╚══════════════════════════════════════════╝

╔══════════════════════════════════════════╗
║    🔐 SECURITY NODE - LIVE TELEMETRY    ║
╠══════════════════════════════════════════╣
║  📏 Distance  : 23.5 cm                ║
║  📡 Blynk V0  : Gauge → 23.5 cm       ║
║  🚨 Alert     : ⚠️  INTRUDER DETECTED!  ║
║  💡 LED       : ON  🔴                  ║
╚══════════════════════════════════════════╝

┌─────────────────────────────────────┐
│  📲 BLYNK PUSH NOTIFICATION SENT   │
│  Event: intruder_alert              │
│  Msg: Object at 23.5 cm detected!  │
│  → Check your Blynk app now! 🔔    │
└─────────────────────────────────────┘
```

---

## 🔌 Circuit Diagram

```
┌─────────────────────┐        ┌──────────────────┐
│      ESP32          │        │   HC-SR04        │
│                     │        │                  │
│  3.3V ─────────────────────► VCC               │
│  GND  ─────────────────────► GND               │
│  GPIO5 ────────────────────► TRIG              │
│  GPIO18 ◄──────────────────── ECHO              │
│                     │        └──────────────────┘
│  GPIO2 ──► 220Ω ──► LED(Red) ──► GND
└─────────────────────┘

📡 WiFi → 🌐 Internet → ☁️ Blynk Cloud → 📱 Dashboard
```

---

## ☁️ Blynk Dashboard (Real Hardware Setup)

When running on real ESP32, configure Blynk with these virtual pins:

| Virtual Pin | Widget | Data |
|------------|--------|------|
| V0 | Gauge | Distance (cm) |
| V1 | LED | Intruder Alert |
| V2 | Label | Status text |
| V3 | SuperChart | Distance history |

---

## 📐 How It Works

```
ESP32 → TRIG pulse (10μs) → HC-SR04
                               │
                          Sound wave emitted
                               │
                      Reflects off object
                               │
HC-SR04 → ECHO pulse → ESP32
                               │
Distance = Duration × 0.0343 / 2

Every 1 second:
  ├─ Distance < 50cm? → 🚨 INTRUDER ALERT + LED ON + Blynk Event
  └─ Distance ≥ 50cm? → ✅ Area Clear + LED OFF
```

---

## 📸 Screenshots

| Wokwi Simulation | Serial Monitor Output | Intruder Alert |
|-----------------|----------------------|----------------|
| ![Sim](screenshots/wokwi_simulation.png) | ![Serial](screenshots/serial_monitor.png) | ![Alert](screenshots/intruder_alert.png) |

> 📸 **Note:** Take these screenshots while running the simulation and add them to the `screenshots/` folder.

---

## 🔧 Customization

```cpp
#define INTRUDER_THRESHOLD_CM  50    // Change detection range
#define SEND_INTERVAL_MS       1000  // Change update rate (ms)
```

---

## 📚 Key Skills Demonstrated

- ✅ **Wi-Fi Stack Configuration** on ESP32
- ✅ **MQTT Protocol** via Blynk
- ✅ **IoT Telemetry** — real-time sensor data
- ✅ **Cloud Dashboard Integration** with Blynk
- ✅ **HC-SR04 Ultrasonic Sensor** interfacing
- ✅ **Wokwi Simulation** — hardware-free development

---

## 🗂️ Project Structure

```
project3-iot-security-node/
│
├── code/
│   └── security_node.ino    # Arduino sketch (Wokwi compatible)
│
├── screenshots/
│   ├── wokwi_simulation.png # Wokwi circuit running
│   ├── serial_monitor.png   # Serial Monitor output
│   └── intruder_alert.png   # Alert triggered screenshot
│
├── diagram.json             # Wokwi circuit diagram
├── wokwi.toml               # Wokwi project config
├── GITHUB_UPLOAD_GUIDE.md   # Upload steps guide
├── LICENSE                  # MIT License
└── README.md                # This file
```

---

## 📄 License

MIT License — see [LICENSE](LICENSE)

---

## 👤 Author

**Your Name**
🔗 [GitHub](https://github.com/YOUR_USERNAME)

---

<p align="center">
  Made with ❤️ using ESP32 + Wokwi + Blynk IoT<br/>
  <i>No hardware? No problem! 🚀</i>
</p>
