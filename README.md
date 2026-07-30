# Industrial Predictive Maintenance: IoT & Machine Learning-Based Vibration Monitoring System

## 📌 Project Overview
This repository contains an end-to-end predictive maintenance system developed during my internship at **HEC Lim** (July 10, 2026 – August 9, 2026). 

The project addresses industrial equipment reliability by monitoring mechanical vibration patterns in real-time. By leveraging an IoT sensor network paired with a Machine Learning classification model within a simulated environment, the system detects, analyzes, and predicts asset anomalies to mitigate unplanned downtime and optimize maintenance schedules.

### Key Objectives
* **Real-time Edge Simulation:** Emulate continuous industrial machinery data streams using virtual microcontrollers.
* **Feature Engineering:** Process raw physical signals into meaningful time-domain statistical metrics.
* **Intelligent Anomaly Detection:** Deploy a Machine Learning model to autonomously classify asset health states.

---

## 🛠️ Technical Stack
* **Simulation Environment:** Wokwi IoT Simulator (Selected for native ESP32 and advanced I2C sensor support)
* **Hardware Architecture:** ESP32 Microcontroller, MPU6050 6-Axis Accelerometer/Gyroscope
* **Firmware Development:** C++ / Arduino Framework
* **Machine Learning Pipeline:** Python 3.x, Scikit-Learn, Pandas, NumPy, Jupyter Notebooks

---

## 🗓️ 4-Week Implementation Roadmap

```text
[Week 1: Architecture] ➔ [Week 2: Data & Circuits] ➔ [Week 3: ML Modeling] ➔ [Week 4: Integration]
```

### Week 1: Architecture Design & Environment Setup (July 10 – July 16)
* **Focus:** Requirement analysis, tool selection, and repository initialization.
* **Deliverables:**
  * Defined hardware architecture schemas (ESP32 + MPU6050 via I2C interface).
  * Outlined the end-to-end data pipeline from physical simulation to ML prediction.
  * Formulated data sampling strategy (frequency rates and window sizing).
  * *Status:* 🟩 **Complete**

### Week 2: Virtual Circuitry & Synthetic Data Acquisition (July 17 – July 23)
* **Focus:** Firmware engineering and dataset compilation.
* **Deliverables:**
  * Construct the virtual schematic wiring within the Wokwi simulator.
  * Develop the firmware script (`.ino`) to read stable 3-axis accelerometer data streams.
  * Program synthetic variance models to simulate "Normal Operational Harmonics" vs. "Mechanical Structural Faults".
  * Stream and export sensor data arrays to localized `.csv` files for baseline dataset creation.
  * *Status:* 🟩 **Complete**

### Week 3: Machine Learning Pipeline & Feature Extraction (July 24 – July 30)
* **Focus:** Statistical processing and model training.
* **Deliverables:**
  * Build a data processing pipeline to convert raw acceleration signals into statistical features (RMS, Peak-to-Peak, Variance).
  * Train and evaluate classification algorithms (e.g., Random Forest, Isolation Forest, or SVM) via Scikit-Learn.
  * Validate performance using confusion matrices, precision-recall curves, and F1-scores.
  * Export the finalized high-accuracy model weights.
  * *Status:* 🟩 **Complete**

### Week 4: System Integration, Edge Alerts & Final Evaluation (July 31 – August 9)
* **Focus:** Hardware-software convergence and validation reporting.
* **Deliverables:**
  * Integrate the trained inference logic or decision boundary parameters back into the simulated stream.
  * Configure automated edge alert responses (Virtual status LEDs/Buzzer signals and telemetry fault flags).
  * Execute validation stress-tests to verify real-time classification accuracy.
  * Compile the final internship technical manuscript and video demonstration for HEC Lim submission.
  * *Status:* ⬜ **Pending**

---

## 🗂️ System Architecture Diagram

```text
+-----------------------+      Raw Data (I2C)     +-------------------+

|  MPU6050 Accelerometer | ---------------------> | ESP32 Board       |
|  (Vibration Sensor)   |                        | (Edge Processing) |
+-----------------------+                        +-------------------+
                                                           |
                                                           | CSV Stream
                                                           v
+-----------------------+      Classification     +-------------------+

| System Status Alert   | <--------------------- | Machine Learning  |
| (Normal vs Anomaly)   |                        | Inference Model   |
+-----------------------+                        +-------------------+
```

---

## 🚀 How to Run the Environment
1. **Clone this repository** to your local machine:
   ```bash
   git clone https://github.com
   ```
   
2. **Launch the Live Simulation:** Open my custom [Wokwi Smart Simulation Link](https://wokwi.com/projects/470178933386555393) directly in your   browser.

3. **Inspect Firmware:** Navigate to the `wokwi_simulation_files/` folder to check `sketch.ino`.

4. *Detailed data processing and ML pipeline commands will be populated next as Week 3 milestones deploy.*


---
*Developed as part of the formal internship evaluation requirements at HEC Lim.*
