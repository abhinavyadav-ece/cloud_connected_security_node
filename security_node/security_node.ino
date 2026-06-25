/*
 * ============================================================
 *  Project 3: Cloud-Connected Security Node (IoT Telemetry)
 *  Platform  : Wokwi ESP32 Simulator
 *  Sensor    : HC-SR04 Ultrasonic (simulated)
 *  Cloud     : Blynk IoT (simulated via Serial output)
 * ============================================================
 *
 *  HOW TO RUN ON WOKWI:
 *  1. Go to https://wokwi.com
 *  2. Click "New Project" → select "ESP32"
 *  3. Paste this code in the editor
 *  4. Click diagram.json tab → paste diagram.json content
 *  5. Press ▶ Play button
 *  6. Watch Serial Monitor for live telemetry output!
 *  7. Click on HC-SR04 sensor → drag slider to change distance
 * ============================================================
 */

// -------- Pin Definitions --------
#define TRIG_PIN   5
#define ECHO_PIN   18
#define LED_PIN    2    // Built-in + external red LED

// -------- Constants --------
#define INTRUDER_THRESHOLD_CM  50    // Alert if object < 50 cm
#define SEND_INTERVAL_MS       1000  // Send telemetry every 1 second

// -------- Global Variables --------
bool intruderDetected  = false;
bool prevIntruder      = false;
unsigned long lastSend = 0;
int readingCount       = 0;

// ============================================================
//  Measure Distance using HC-SR04
// ============================================================
float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) return -1.0;
  return duration * 0.0343 / 2.0;
}

// ============================================================
//  Simulate Blynk Dashboard in Serial Monitor
// ============================================================
void printDashboard(float distance, bool alert) {
  Serial.println("╔══════════════════════════════════════════╗");
  Serial.println("║    🔐 SECURITY NODE - LIVE TELEMETRY    ║");
  Serial.println("╠══════════════════════════════════════════╣");
  Serial.print  ("║  📏 Distance  : ");
  if (distance < 0) {
    Serial.print("OUT OF RANGE         ");
  } else {
    Serial.printf("%-6.1f cm               ", distance);
  }
  Serial.println("║");
  Serial.print  ("║  📡 Blynk V0  : Gauge → ");
  Serial.printf ("%-6.1f cm           ", distance < 0 ? 0 : distance);
  Serial.println("║");
  Serial.print  ("║  🚨 Alert     : ");
  if (alert) {
    Serial.println("⚠️  INTRUDER DETECTED!          ║");
  } else {
    Serial.println("✅  Area Clear                  ║");
  }
  Serial.print  ("║  💡 LED       : ");
  Serial.println(alert ? "ON  🔴                          ║"
                       : "OFF ⚫                          ║");
  Serial.print  ("║  📊 Reading # : ");
  Serial.printf ("%-5d                            ║\n", readingCount);
  Serial.println("╚══════════════════════════════════════════╝");
  Serial.println();
}

// ============================================================
//  Simulate Blynk Event Notification
// ============================================================
void simulateBlynkEvent(float distance) {
  Serial.println("┌─────────────────────────────────────┐");
  Serial.println("│  📲 BLYNK PUSH NOTIFICATION SENT   │");
  Serial.printf ("│  Event: intruder_alert              │\n");
  Serial.printf ("│  Msg: Object at %.1f cm detected!  │\n", distance);
  Serial.println("│  → Check your Blynk app now! 🔔    │");
  Serial.println("└─────────────────────────────────────┘");
  Serial.println();
}

// ============================================================
//  Setup
// ============================================================
void setup() {
  Serial.begin(115200);
  delay(300);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN,  OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println();
  Serial.println("╔══════════════════════════════════════════╗");
  Serial.println("║   Cloud-Connected Security Node v1.0   ║");
  Serial.println("║   ESP32 + HC-SR04 + Blynk IoT          ║");
  Serial.println("║   [ Running on Wokwi Simulator ]       ║");
  Serial.println("╠══════════════════════════════════════════╣");
  Serial.println("║  Simulating WiFi connection...          ║");
  delay(800);
  Serial.println("║  ✅ Connected to WiFi: MyNetwork        ║");
  delay(400);
  Serial.println("║  Connecting to Blynk Cloud (MQTT)...   ║");
  delay(800);
  Serial.println("║  ✅ Blynk Connected!                    ║");
  Serial.println("║  ✅ Dashboard Live at blynk.cloud       ║");
  Serial.println("╠══════════════════════════════════════════╣");
  Serial.println("║  🎛️  TIP: Click HC-SR04 in Wokwi →     ║");
  Serial.println("║  drag the distance slider to simulate   ║");
  Serial.println("║  an intruder! (set < 50 cm)            ║");
  Serial.println("╚══════════════════════════════════════════╝");
  Serial.println();
  delay(1000);
}

// ============================================================
//  Main Loop
// ============================================================
void loop() {
  unsigned long now = millis();

  if (now - lastSend >= SEND_INTERVAL_MS) {
    lastSend = now;
    readingCount++;

    float distance = measureDistance();

    // Determine alert state
    if (distance > 0 && distance < INTRUDER_THRESHOLD_CM) {
      intruderDetected = true;
      digitalWrite(LED_PIN, HIGH);
    } else {
      intruderDetected = false;
      digitalWrite(LED_PIN, LOW);
    }

    // Print simulated Blynk dashboard
    printDashboard(distance, intruderDetected);

    // Fire event only on first detection (edge trigger)
    if (intruderDetected && !prevIntruder) {
      simulateBlynkEvent(distance);
    }

    prevIntruder = intruderDetected;
  }
}
