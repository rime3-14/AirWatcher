# 🌍 AirWatcher

**AirWatcher** is a console-based C++ application developed to help a government environmental agency monitor and analyze air quality across a large territory. It provides statistical analysis, sensor validation, and supports individual participation through data contributions.

---

## 📦 Features

* 📅 Load air quality sensor data from CSV files
* 📊 Compute Air Quality Index (AQI) for a given zone or time
* 🔍 Compare similarity of sensors' AQI profiles
* 🌀 Evaluate the impact of AirTrackers (cleaners) on surrounding air
* 🧪 Filter and exclude unreliable sensor data
* 🔐 Role-based access to features (government vs private users)
* 🚀 Performance tracking of statistical algorithms

---

## ⚙️ How to Run

### 🛠️ Requirements

* A modern C++ compiler (GCC ≥ 9 / Clang ≥ 10)
* Make utility
* Terminal

### ⚡️ Build

From the root directory of the project, run:

```bash
make
```

This compiles the main application.

### ▶️ Execute

```bash
./AirWatcher
```

---

## 👤 How to Use

After launching the application:

1. **Log in** using one of the predefined users.
2. **Main menu** options depend on the role (e.g., private user, provider, government agent).
3. Select an action:

   * Evaluate AQI average in a circular area
   * Compare AQI similarity between sensors
   * Predict air quality at specific points/times
   * Evaluate AirTracker impact and reliability
   * Share or evaluate private data
   * View algorithm performance metrics
4. Follow the prompts to input location, radius, and date/time.

All interactions are text-based and provide helpful guidance and error messages.

---

## 🧪 How to Test

Compile the tests using:

```bash
make test
```

Then run:

```bash
make run-tests
```

All tests are unit-based and focus on models, repositories, and services such as:

* `Measurement`, `Sensor`, `AirCleaner`
* `CSVLoader`, `SensorRepository`, `UserRepository`
* `AirQualityService`, `AlgoPerformance`

Test results will be printed in the console.

---

## 🪧 Project Structure

```
.
├── src/                # Source files (models, data access, console, services)
├── include/            # Header files
├── tests/              # Unit tests
├── build/              # Compiled object files
├── main.cpp            # Application entry point
├── Makefile
└── README.md
```

---

## 💼 Roles & Access

| Role                | Can Evaluate Sensors | Can Share Data | Can View Stats | Can Mark Data |
| ------------------- | -------------------- | -------------- | -------------- | ------------- |
| Government Agent    | ✅                    | ❌              | ✅              | ✅             |
| Private User        | ❌                    | ✅              | ✅              | ❌             |
| AirCleaner Provider | ❌                    | ✅              | ✅              | ❌             |

---

## 📊 Performance & Security

* Calculates air quality averages in under 400ms.
* Interface responds in under 200ms.
* Handles real-time data processing with ≤500ms latency.
* Uses role-based authentication and secure data encapsulation.
* All user input is sanitized to prevent misuse or exploitation.

---

## 🔮 Example Use Case

```
$ ./main
Welcome to AirWatcher
You can use this tool to access different information regarding air quality of the area.

============ Log in: ============
To begin, you need to log in

Are you:
1 - A Private user
2 - A Government employee
3 - An Air Cleaner Provider

Please select a number from above: 2
Successfully logged in

=========== Main menu: ==========
1 - Evaluate AQI Averages:
    Compute the average Air Quality Index in a circular area over a time period

2 - Compare AQI Similarity:
    Compare the AQI evolution between two sensors over time

3 - Calc AirTracker Impact:
    Measure how much an AirTracker has improved local air quality

4 - Eval AirTracker Reliability:
    Identify unreliable sensors based on inconsistencies or missing data

5 - Eval Private Submission:
    Evaluate trustworthiness of private users’ data contributions

6 - Share Private Data:
    Submit air quality data as a private user

7 - View Performance Metrics:
    Show execution times for various algorithm components

Please select a number from above: 1
```

---

## 👥 Team

* Sylvanie YOU
* Rida BINDECH
* Rim CHIHAB-EDDINE
* Ashley DUONG
* Christopher WILSON

---

## 📄 License

This software is developed for educational purposes. Contact the team for reuse permissions.
