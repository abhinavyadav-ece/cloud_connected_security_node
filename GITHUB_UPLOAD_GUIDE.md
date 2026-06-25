# 📤 GitHub Upload Guide — Wokwi Simulation Project

## Pehle Ye Karo — Screenshots Lo! 📸

Simulation run karte waqt ye 3 screenshots lo:

### Screenshot 1: `wokwi_simulation.png`
- Wokwi browser ka full screenshot lo
- Circuit dikh raha ho + Serial Monitor dikh raha ho
- Press `F11` for fullscreen, then `Win + Shift + S` for screenshot

### Screenshot 2: `serial_monitor.png`
- Serial Monitor crop karke lo
- Live telemetry data dikh raha ho (distance readings)

### Screenshot 3: `intruder_alert.png`
- HC-SR04 slider ko < 50 cm par lao
- "⚠️ INTRUDER DETECTED!" wala output screenshot lo

Teeno screenshots ko `screenshots/` folder mein daalo.

---

## GitHub Par Upload Karo

### Step 1: GitHub par naya repository banao
- GitHub.com → "New Repository"
- Name: `project3-iot-security-node`
- Description: `IoT Security Node using ESP32, HC-SR04, simulated on Wokwi`
- Public rakho ✅
- "Create Repository" click karo

### Step 2: Files Upload Karo

**Option A — GitHub Website se (Drag & Drop):**
1. Repository page par jao
2. "uploading an existing file" link click karo
3. Saare files drag & drop karo (README.md, diagram.json, code/ folder, screenshots/ folder)
4. Commit message: `"Add Project 3: Cloud Security Node - Wokwi Simulation"`
5. "Commit changes" click karo ✅

**Option B — Git Command Line:**
```bash
cd project3-iot-security-node
git init
git add .
git commit -m "Project 3: Cloud-Connected Security Node - Wokwi Simulation"
git remote add origin https://github.com/YOUR_USERNAME/project3-iot-security-node.git
git branch -M main
git push -u origin main
```

---

## Repository ko Polish Karo

GitHub repository page → ⚙️ (gear icon near "About"):
- **Description:** `ESP32 IoT Security Node with HC-SR04 ultrasonic sensor, simulated on Wokwi. Streams telemetry via MQTT to Blynk cloud dashboard.`
- **Topics add karo:**
  `esp32` `iot` `wokwi` `blynk` `mqtt` `arduino` `ultrasonic` `security` `simulation`
- **Website:** Wokwi simulation ka link daal sakte ho

---

## Wokwi Project bhi Share Karo (Bonus!)

1. Wokwi mein simulation run karo
2. Top-right mein **Share** button click karo
3. Public link copy karo
4. README.md mein ye line add karo:
   ```markdown
   ## 🎮 Live Simulation
   👉 [Run on Wokwi](https://wokwi.com/projects/YOUR_PROJECT_ID)
   ```

---

✅ Done! Tera Project 3 GitHub par live hai bina ek bhi component ke! 🎉
