# TinyML Optical Analyzer

A compact ESP32-based optical sensing device that uses TinyML to classify surfaces based on reflected light, scalable to fluorescence and POCT diagnostics.

## Overview

The TinyML Optical Analyzer is an embedded system that measures reflected light intensity from a surface and classifies it into one of three categories:

* **Dark Surface**
* **White Surface**
* **Reflective/Shiny Surface**

This classification runs **entirely on-device** using a machine learning model trained on a custom dataset.

---

## Key Features

* Optical reflectivity sensing using LDR/photodiode
* Exponential Moving Average (EMA) noise filtering
* Custom dataset collection + annotation
* Logistic Regression model 
* **On-board ML inference** running on ESP32
* Real-time surface classification (Future scope)
* Modular design: extendable to forensic fluorescence sensing

---

## System Architecture

```
Surface → Light Reflection → Sensor (AO) → ESP32 ADC
      → Signal Filtering → ML Classifier → Output Label
```

---

## Machine Learning Pipeline

* 60 labeled optical intensity samples collected
* Dataset split into training & testing
* Logistic Regression (One-vs-Rest)
* Accuracy = **100%**
* Confusion Matrix = Perfect separation

---

## Classification Output

| Class | Meaning                  |
| ----- | ------------------------ |
| 0     | Dark Surface             |
| 1     | White Surface            |
| 2     | Reflective/Shiny Surface |

Output example:

```
Intensity: 2855 → Reflective Surface
```

---

## Hardware Setup (Simulation)

| Component     | Pin     |
| ------------- | ------- |
| LDR Sensor AO | GPIO 33 |
| Status LED    | GPIO 2  |

---

## ESP32 Inference Code

*(Full code included in repository)*

---

## Applications

* Industrial surface inspection
* Automated sorting systems
* Robotics surface interaction
* **Extendable to:**

  * UV fluorescence sensing
  * Forensic POCT diagnostics
  * Biomedical lateral flow test reading

---

## Future Scope

* Integrate **UV LED** for fluorescence excitation
* Add optical filter + photodiode for biochemical analyte detection
* Expand ML classes for dye-based intensities
* Compact handheld enclosure (3D printed)
* OLED display + battery operation

---

## Repository Structure

```
📁 tinyml-surface-classifier/
├── src/
│   └── esp32_classifier.ino
├── ml/
│   ├── train_model.py
│   └── surface_dataset.csv
├── docs/
│   ├── results_plot.png
│   ├── architecture.png
│   └── wokwi_output.png
└── README.md
```

